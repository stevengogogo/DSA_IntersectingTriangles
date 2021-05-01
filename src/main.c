#include <stdio.h>
#include <stdlib.h>

#include "intersect.h"
#include "generator.h"


int main()
{
    
    int n = 10;
    int p[] = {-5, 15, 15, -8, -11, -5, -13, -14, 15, 10};
    int q[] = {-7, -12, -4, -13, 5, 1, 14, -16, -16, -14};
    int r[] = {2, -13, 1, 9, 9, 1, 1, 12, -15, 6};
    
    //Initiate
    Paths pt = init_path(n,p,q,r);
    


    MERGE_SORT_FIRSTofThree(pt.p, pt.l, pt.r, 0, pt.len-1);


    /*
    generator.init();
    int t = generator.getT();
    Paths pt;

    for(int i=0;i<t;i++){
        int n, *p, *q, *r;
        generator.getData(&n, &p, &q, &r);

        pt.len = n;
        pt.p = p;
        pt.l = q;
        pt.r = r;


        int ans = get_intersects(n, p, q, r);
        printf("%d", ans);
    }
    */
    

    return 0;
}