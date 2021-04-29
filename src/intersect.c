#include "intersect.h"

Paths init_paths(int len){
    int np = 3; // number of points
    int* arr[np];

    for(int i=0;i<np;i++)
        arr[i] = (int*)malloc(len*sizeof(int));

    Paths pt = {
        .p = arr[0],
        .l = arr[1],
        .r = arr[2],
        .len = len
    };
    return pt;
}

void kill_paths(Paths pt){
    free(pt.p);
    free(pt.l);
    free(pt.r);
}


int get_intersects(int n, int* p, int* q, int* r){
    
    return q[0];
}



