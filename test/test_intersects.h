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
            TEST_CHECK(pt.r[i].val == q[i]);
            TEST_CHECK(pt.l[i].val == r[i]);
        }
        else{
            TEST_CHECK(pt.r[i].val == r[i]);
            TEST_CHECK(pt.l[i].val == q[i]);
        }
    }



    sortPaths_P(pt);    


    TEST_CHECK(pt.p[0] == -14);
    TEST_CHECK(pt.l[0].val == -16);
    TEST_CHECK(pt.r[0].val == 12);

    TEST_CHECK(pt.p[9] == 15);
    TEST_CHECK(pt.l[9].val == -16);
    TEST_CHECK(pt.r[9].val == -15);
    TEST_MSG("Got %d",pt.l[9].val);

    TEST_CHECK(pt.p[4] == -5);
    TEST_CHECK(pt.l[4].val == -7);
    TEST_CHECK(pt.r[4].val == 2);

    /*
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d\t", pt.p[i]);
    }
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d\t", pt.l[i].val);
    }
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d\t", pt.r[i].val);
    }
    printf("\n");
    */

    MERGE_SORT_COUNT_INVERSION(pt, 0, pt.len-1);
    TEST_CHECK(pt.p[0] == -14);
    TEST_CHECK(pt.l[0].val == -16);
    TEST_CHECK(pt.r[0].val == -15);

    TEST_CHECK(pt.p[9] == 15);
    TEST_CHECK(pt.l[9].val == 5);
    TEST_MSG("Got %d",pt.l[9].val);

    /*
    for(int i=0;i<10;i++){
        printf("%d ", pt.l[i].val);
    }
    */

    TEST_CHECK(pt.r[9].val == 14);
    TEST_MSG("Got %d",pt.r[9].val);

    //Kill
    kill_path(pt);
}
