#include "utils.h"


int* init_arr(int len){
    int* array = (int*)malloc(len*sizeof(int));
    return array;
}

void kill_arr(int* array){
    free(array);
}

void copy_arr(int* dst, int* src, int left, int right){
    for(int i=left; i<right;i++){
        dst[i] = src[i];
    }
}

int argmax(int n0, int n1){
    if (n1>n0)
        return n1;
    else 
        return n0;
}

void swap(int* a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}