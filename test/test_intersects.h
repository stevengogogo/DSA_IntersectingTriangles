#include "intersect.h"
#include "generator.h"
#include "utils.h"



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

    MERGE_SORT_FIRSTofThree(pt.p, pt.l, pt.r, 0, pt.len-1);
    
    TEST_CHECK(pt.p[0] == -14);
    TEST_CHECK(pt.l[0] == -16);
    TEST_CHECK(pt.r[0] == 12);

    TEST_CHECK(pt.p[9] == 15);
    TEST_CHECK(pt.l[9] == -16);
    TEST_CHECK(pt.r[9] == -15);
    TEST_MSG("Got %d",pt.l[9]);

    //Kill
    kill_path(pt);
}
