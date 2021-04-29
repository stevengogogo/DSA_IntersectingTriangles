#include "intersect.h"
#include "generator.h"
#include "util.h"



void load_data(void){
    int n = 10;
    int p[] = {-5, 15, 15, -8, -11, -5, -13, -14, 15, 10};
    int q[] = {-7, -12, -4, -13, 5, 1, 14, -16, -16, -14};
    int r[] = {2, -13, 1, 9, 9, 1, 1, 12, -15, 6};
    
    Paths pt = init_path(n,p,q,r);
    int qr[2];
    for(int i=0; i<n;i++){
        qr[0] = q[i];
        qr[1] = r[i];
        int am = argmax(q[i], r[i]);

        TEST_CHECK(pt.p[i] == p[i]);
        TEST_CHECK(pt.r[i] == qr[am]);
        TEST_CHECK(pt.l[i] == qr[1^am]);
    }
}
