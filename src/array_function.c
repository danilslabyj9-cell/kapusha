#include <stdio.h>
#include "../include/array_function.h"

void join_int_arrays(int* src1, size_t size_src1, int* src2, size_t size_src2, int* dest) {
    int i, j;
    for(i = 0; i < size_src1; i++) {
        dest[i] = src1[i];
    }

    for(j = 0; j < size_src2; j++) {
        dest[size_src1 + j] = src2[j];
    }
}

void join_and_sort_int_arrays(int* src1, size_t size_src1, int* src2, size_t size_src2, int* dest) {
    int i, j;
    int temp;

    join_int_arrays(src1, size_src1, src2, size_src2, dest);

    for(i = 0; i < size_src1 + size_src2 - 1; i++) {
        for(j = 0; j < size_src1 + size_src2 - 1 - i; j++) {
            if(dest[j] > dest[j+1]) {
                temp = dest[j];
                dest[j] = dest[j+1];
                dest[j+1] = temp;
            }
        }
    }
}

void get_min_and_max_from_int_array(int* src, size_t size, int* min, int* max) {
    int i;

    if(size == 0) {
        return;
    }

    *min = src[0];
    *max = src[0];

    for(i = 1; i < size; i++) {
        if(src[i] < *min) {
            *min = src[i];
        }
        if(src[i] > *max) {
            *max = src[i];
        }
    }
}
