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