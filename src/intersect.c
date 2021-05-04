#include "intersect.h"


Paths init_path(long len, long p[], long q[], long r[]){
    

    Paths pt;
    long arrSize = len*sizeof(int);
    long arrSizeN = len*sizeof(node);
    pt.len = len;
    pt.p = (int*)malloc(arrSize);
    pt.l = (node*)malloc(arrSizeN);
    pt.r = (node*)malloc(arrSizeN);

    assert(pt.p!=NULL);
    assert(pt.l!=NULL);
    assert(pt.r!=NULL);

    // Copy P
    copy_arr(pt.p, p, 0, len);

    // Copy l , r (l<=r)
    node L, R;  
    for(long i=0;i<len;i++){
        L.val = q[i]; R.val = r[i];
        L.p = p[i]; R.p = p[i];
        if (L.val>R.val){
            swapNode(&L, &R);
        }
        pt.l[i] = L;
        pt.r[i] = R;
    }
   
    return pt;
}

void kill_path(Paths pt){
    free(pt.l);
    free(pt.p);
    free(pt.r);
}

MemMerge3 allocMemMerge3(long len){
    //Sort Array
    MemMerge3 temp;
    temp.L = (int*)malloc((len+1)*sizeof(int));
    temp.R = (int*)malloc((len+1)*sizeof(int));
    //Paired Array 1
    temp.a2_L = (node*)malloc(len*sizeof(node));
    temp.a2_R = (node*)malloc(len*sizeof(node));
    //Paired Array 2
    temp.a3_L = (node*)malloc(len*sizeof(node));
    temp.a3_R = (node*)malloc(len*sizeof(node));

    assert(temp.L != NULL);
    assert(temp.R != NULL);
    assert(temp.a2_L != NULL);
    assert(temp.a2_R != NULL);
    assert(temp.a3_L != NULL);
    assert(temp.a3_R != NULL);

    return temp;
}
void kill_MemMerge3(MemMerge3 temp){
    free(temp.L);
    free(temp.R);
    free(temp.a2_L);
    free(temp.a2_R);
    free(temp.a3_L);
    free(temp.a3_R);
}

MemMergeT allocMemMergeT(long len){
    MemMergeT temp;
    temp.Ls_L = (node*)malloc((len+1)*sizeof(node));
    temp.Ls_R = (node*)malloc((len+1)*sizeof(node));
    temp.Rs_L = (node*)malloc((len+1)*sizeof(node));
    temp.Rs_R = (node*)malloc((len+1)*sizeof(node));
    assert(temp.Ls_L != NULL);
    assert(temp.Ls_R != NULL);
    assert(temp.Rs_L != NULL);
    assert(temp.Rs_R != NULL);

    return temp;
}

void kill_MemMergeT(MemMergeT temp){
    free(temp.Ls_L);
    free(temp.Ls_R);
    free(temp.Rs_L);
    free(temp.Rs_R);
}

void MERGE_SORT_FIRSTofThree(Paths pt, long p, long r, MemMerge3 temp){
    if (p<r){
        long q = (p+r) / 2;
        MERGE_SORT_FIRSTofThree(pt, p, q, temp);
        MERGE_SORT_FIRSTofThree(pt, q+1, r, temp);
        MERGE_FIRSTofThree(pt, p, q, r, temp);
    }
}

void MERGE_FIRSTofThree(Paths pt, long p, long q, long r, MemMerge3 temp){
    long n1 = q - p + 1; // Length of sub-array Left [p,q]
    long n2 = r - (q+1) + 1; // Length of sub-array right (q,r]

    //Sort Array
    long* L = temp.L;
    long* R = temp.R;
    //Paired Array 1
    node* a2_L = temp.a2_L;
    node* a2_R = temp.a2_R;
    //Paired Array 2
    node* a3_L = temp.a3_L;
    node* a3_R = temp.a3_R;


    //Copy left part
    copy_arr(L, pt.p, p, q+1);
    copyNode(a2_L, pt.l, p, q+1);
    copyNode(a3_L, pt.r, p, q+1);
    //Copy right part
    copy_arr(R, pt.p, q+1, r+1);
    copyNode(a2_R, pt.l, q+1, r+1);
    copyNode(a3_R, pt.r, q+1, r+1);

    //Sentinel
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    //Dispatch
    long i = 0;
    long j = 0;
    for(long k=p; k<=r;k++){ //from [p,r]
        if(L[i] <= R[j]){
            pt.p[k] = L[i];
            pt.l[k] = a2_L[i];
            pt.r[k] = a3_L[i];
            ++i;
        }
        else{
            pt.p[k] = R[j];
            pt.l[k] = a2_R[j];
            pt.r[k] = a3_R[j];
            ++j;
        }
    }
}

void sortPaths_P(Paths pt){
    MemMerge3 temp = allocMemMerge3(pt.len);
    MERGE_SORT_FIRSTofThree(pt, 0, pt.len-1, temp);
    kill_MemMerge3(temp);
}

long MERGE_SORT_COUNT_INVERSION(Paths pt, long l, long r, MemMergeT temp){
    long inv=0;
    if (l<r){
        long m = (l+r)/2;
        inv += MERGE_SORT_COUNT_INVERSION(pt, l, m, temp);
        inv += MERGE_SORT_COUNT_INVERSION(pt, m+1, r, temp);
        inv += MERGE_COUNT_INVERSION(pt, l, m, r, temp);
    }
    return inv;
}

long MERGE_COUNT_INVERSION(Paths pt, long l, long m, long r, MemMergeT temp){

    //Count inversion
    long count = m+1;
    long inv = 0;

    //Same Item
    node isSame = {
        .p=INT_MAX,
        .val=0
    };

    long Iden = 0; //Identical Ps on the right
    long IdenSite = m+1;
    if(pt.p[m]==pt.p[m+1]){
        isSame.val=1;//Same item true
        isSame.p = pt.p[m]; // value of identical p
        //Number of Same Ps
        while(IdenSite <= r && isSame.p == pt.p[IdenSite] ){
            ++Iden;
            ++IdenSite;
            
            if (IdenSite > r)//avoid segmenetation fault
                break;
        }
    }

    //Count inversions and Overlapped pairs
    for (long k=l;k<=m;k++){
        //Find Max{left} > Min{right}
        while(count <= r && pt.r[k].val >= pt.l[count].val){
            //Rule out counted identical P
            if(isSame.val && isSame.p == pt.l[count].p){ //included p
                --Iden;
            }

            ++count;
        }

        //Sum up
        inv +=  (count - (m + 1));

        if(pt.r[k].p == isSame.p && isSame.val==1){
             inv += Iden;
        }
    }



    //Finish sorting
    long n1 = m - l + 1;
    long n2 = r - (m+1) + 1;

    // Sort Array
    node* Ls_L = temp.Ls_L;
    node* Ls_R = temp.Ls_R;
    node* Rs_L = temp.Rs_L;
    node* Rs_R = temp.Rs_R;   


    //Copy left part
    copyNode(Ls_L, pt.l, l, m+1);
    copyNode(Rs_L, pt.r, l, m+1);
    //Copy right part
    copyNode(Ls_R, pt.l, m+1, r+1);
    copyNode(Rs_R, pt.r, m+1, r+1);

    //Sentinel 
    Ls_L[n1].val = INT_MAX;
    Rs_L[n1].val = INT_MAX;
    Ls_R[n2].val = INT_MAX;
    Rs_R[n2].val = INT_MAX;

    long Li = 0;
    long Lj = 0;
    long Ri = 0;
    long Rj = 0;

    for (long k=l;k<=r;k++){
        //Dispatch Ls
        if(Ls_L[Li].val <= Ls_R[Lj].val){
            pt.l[k] = Ls_L[Li];
            ++Li;
        }
        else{
            pt.l[k] = Ls_R[Lj];
            ++Lj;
        }

        //Dispatch Rs
        if(Rs_L[Ri].val <= Rs_R[Rj].val){
            pt.r[k] = Rs_L[Ri];
            ++Ri;
        }
        else{
            pt.r[k] = Rs_R[Rj];
            ++Rj;
        }
    }

    return inv;
}


long get_intersects(long n, long* p, long* q, long* r){
    Paths pt = init_path(n,p,q,r);
    sortPaths_P(pt);

    MemMergeT temp = allocMemMergeT(pt.len);
    long inv = MERGE_SORT_COUNT_INVERSION(pt, 0, pt.len-1, temp);
    
    kill_MemMergeT(temp);
    kill_path(pt);
    return inv;
}



void swapNode(node* a, node* b){
    node tmp = *a;
    *a = *b;
    *b = tmp;
}

void copyNode(node* dst, node* src, long left, long right){
    long j = 0;
    assert(left<=right);
    for(long i=left; i<right;i++){
        dst[j] = src[i];
        ++j;
    }
}