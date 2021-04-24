#include <stdio.h>
#include <stdlib.h>

#include "intersect.h"
#include "generator.h"
int main()
{
    
    generator.init();
    int t = generator.getT();


    for(int i=0;i<t;i++){
        int n, *p, *q, *r;
        generator.getData(&n, &p, &q, &r);

        int ans = get_intersects(n, p, q, r);
        printf("%d", ans);
    }

    

    return 0;
}