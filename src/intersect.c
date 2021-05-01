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

int get_intersects(int n, int* p, int* q, int* r){
    
    return q[0];
}



