#include "intersect.h"
#include "generator.h"



void load_data(void){
    Paths pt;

    int n = 10;
    int p[] = {-5, 15, 15, -8, -11, -5, -13, -14, 15, 10};
    int q[] = {-7, -12, -4, -13, 5, 1, 14, -16, -16, -14};
    int r[] = {2, -13, 1, 9, 9, 1, 1, 12, -15, 6};
    
    pt.len = n;
    pt.p = p;
    pt.l = q;
    pt.r = r;
}
