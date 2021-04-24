#include "intersect.h"











int interface(void){

    generator.init();
    int t = generator.getT();
    int n;
    int *p = init_arr(t);
    int *q = init_arr(t);
    int *r = init_arr(t);

    for(int i=0;i<t;i++){
        //generator.getData(&n, &p[i], &q[i], &r[i]);
    }

    return 0;
}

int sample_interface(void){
    generator.init();
    int t = generator.getT();
    while (t--) {
        int n, *p, *q, *r;
        generator.getData(&n, &p, &q, &r);
        int ans = 0;
        for (int i = 0; i < n; i++) 
            ans += p[i] * q[i] * r[i];
        printf("%d\n", ans);
    }
    return 0;
}