#include "intersect.h"
#include "generator.h"
#include "util.h"



void load_data(void){
    int n = 10;
    int p[] = {-5, 15, 15, -8, -11, -5, -13, -14, 15, 10};
    int q[] = {-7, -12, -4, -13, 5, 1, 14, -16, -16, -14};
    int r[] = {2, -13, 1, 9, 9, 1, 1, 12, -15, 6};
    
    //Initiate
    Paths pt = init_path(n,p,q,r);
    
    for(int i=0; i<n;i++){
        TEST_CHECK(pt.p[i] == p[i]);
        
        if (q[i] > r[i]){
            TEST_CHECK(pt.r[i] == q[i]);
            TEST_CHECK(pt.l[i] == r[i]);
        }
        else{
            TEST_CHECK(pt.r[i] == r[i]);
            TEST_CHECK(pt.l[i] == q[i]);
        }
    }

    //Kill
    kill_path(pt);
}
