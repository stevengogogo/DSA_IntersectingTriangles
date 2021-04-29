#include "intersect.h"


Paths init_path(int len, int p[], int q[], int r[]){
    Paths pt;
    pt.len = len;
    pt.p = p;
    pt.l = q;
    pt.r = r;

    int am;
    int Plr[2];

    for(int i=0;i<len;i++){
        if (pt.l[i] > pt.r[i])
            swap(&pt.l[i], &pt.r[i]);
    }

    return pt;
}


int get_intersects(int n, int* p, int* q, int* r){
    
    return q[0];
}



