#include "intersect.h"


Paths init_path(int len, int p[], int q[], int r[]){
    

    Paths pt;
    pt.len = len;
    pt.p = (int*)malloc(len*sizeof(int));
    pt.l = (int*)malloc(len*sizeof(int));
    pt.r = (int*)malloc(len*sizeof(int));

    // Copy P
    copy_arr(pt.p, p, 0, len);

    // Copy l , r (l<=r)
    int L, R;  
    for(int i=0;i<len;i++){
        L = q[i]; R = r[i];
        if (L>R){
            swap(&L, &R);
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

void MERGE_SORT_FIRSTofThree(int* A, int* a2, int* a3, int p, int r){
    if (p<r){
        int q = (p+r) / 2;
        MERGE_SORT_FIRSTofThree(A, a2, a3, p, q);
        MERGE_SORT_FIRSTofThree(A, a2, a3, q+1, r);
        MERGE_FIRSTofThree(A, a2, a3, p, q, r);
    }
}

void MERGE_FIRSTofThree(int* A, int* a2, int* a3, int p, int q, int r){
    int n1 = q - p + 1; // Length of sub-array Left [p,q]
    int n2 = r - q; // Length of sub-array right (q,r]

    //Sort Array
    int* L = (int*)malloc(n1*sizeof(int) + 1);
    int* R = (int*)malloc(n2*sizeof(int) + 1);
    //Paired Array 1
    int* a2_L = (int*)malloc(n1*sizeof(int));
    int* a2_R = (int*)malloc(n2*sizeof(int));
    //Paired Array 2
    int* a3_L = (int*)malloc(n1*sizeof(int));
    int* a3_R = (int*)malloc(n2*sizeof(int));

    //Copy left part
    copy_arr(L, A, p, q+1);
    copy_arr(a2_L, a2, p, q+1);
    copy_arr(a3_L, a3, p, q+1);
    //Copy right part
    copy_arr(R, A, q+1, r+1);
    copy_arr(a2_R, a2, q+1, r+1);
    copy_arr(a3_R, a3, q+1, r+1);

    //Sentinel
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    //Dispatch
    int i = 0;
    int j = 0;
    for(int k=p; k<r;k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            a2[k] = a2_L[i];
            a3[k] = a3_L[i];
            ++i;
        }
        else{
            A[k] = R[j];
            a2[k] = a2_R[j];
            a3[k] = a3_L[j];
            ++j;
        }
    }


    //Free
    free(L);
    free(R);
    free(a2_R);
    free(a3_R);
    free(a2_L);
    free(a3_L);
}

int get_intersects(int n, int* p, int* q, int* r){
    
    return q[0];
}



