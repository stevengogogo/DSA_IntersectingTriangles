/**
 * @file main.c
 * @author Shao-Ting Chiu (r07945001@ntu.edu.tw)
 * @brief Get Triangle Intersections with Merge sort
 * @version 0.1
 * @date 2021-05-01
 * @note See Documentation: https://stevengogogo.github.io/DSA_IntersectingTriangles/globals.html for details.
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "intersect.h"
#include "generator.h"

int main()
{
    

    //TEST
    /*
    TriProb tp = ParseData("test/dataGen/4_3e5.txt");
    ulong ans = get_intersects(tp.n, tp.ps, tp.qs, tp.rs);
    free(tp.ps); free(tp.qs); free(tp.rs);
    printf("%ld\n",ans);
    */
  
   // Interface
    generator.init();
    int t = generator.getT();

    for(int i=0;i<t;i++){
        int n, *p, *q, *r;
        generator.getData(&n, &p, &q, &r);

        ulong ans = get_intersects(n, p, q, r);
        printf("%ld\n", ans);
    }


    return 0;
}