#include "utils.h"


long*  init_arr(long len){
    long*  array = (int*)malloc(len*sizeof(int));
    return array;
}

void kill_arr(long*  array){
    free(array);
}

void copy_arr(long*  dst, long*  src, long left, long right){
    long j = 0;
    for(long i=left; i<right;i++){
        dst[j] = src[i];
        ++j;
    }
}

long argmax(long n0, long n1){
    if (n1>n0)
        return n1;
    else 
        return n0;
}

void swap(long*  a, long *b){
    long tmp = *a;
    *a = *b;
    *b = tmp;
}

long ChooseMax(long a, long b){
    if (a>b)
        return a;
    else 
        return b;
}

TriProb ParseData(char* filePath){
    FILE *fp;
    TriProb tp;

    fp = fopen(filePath, "r");
    assert(fp!=NULL);

    //Get length
    fscanf(fp, "%d", &tp.n); 

    tp.ps = (int*)malloc(tp.n*sizeof(int));
    tp.qs = (int*)malloc(tp.n*sizeof(int));
    tp.rs = (int*)malloc(tp.n*sizeof(int));

    for(long i=0;i<tp.n;i++){
        fscanf(fp, "%d", &tp.ps[i]); 
    }

    for(long i=0;i<tp.n;i++){
        fscanf(fp, "%d", &tp.qs[i]); 
    }

    for(long i=0;i<tp.n;i++){
        fscanf(fp, "%d", &tp.rs[i]); 
    }

    //Get Solution
    fscanf(fp, "%d", &tp.sol); 


    fclose(fp);

    return tp;
}

void int2str(long i, char *s) {
  sprintf(s,"%d",i);
}