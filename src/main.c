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
    
   
    //Initiate
    /*
    TriProb tp = ParseData("test/dataGen/2.txt");
    int ans = get_intersects(tp.n, tp.ps, tp.qs, tp.rs);
    printf("%d\n",ans);
    */

   // Interface
    generator.init();
    int t = generator.getT();

    for(int i=0;i<t;i++){
        int n, *p, *q, *r;
        generator.getData(&n, &p, &q, &r);

        int ans = get_intersects(n, p, q, r);
        printf("%d", ans);
        if(i!= t-1){
            printf("\n");
        }
    }


    return 0;
}