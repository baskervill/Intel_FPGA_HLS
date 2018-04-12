#include "HLS/hls.h"
#include <stdlib.h>

int bin_count(int *bins, int a){
    return ++bins[a];
}

int main(){
    int *bins = (int *) malloc(16 * sizeof(int));
    srand(NULL);
    for(int i = 0;i < 256;i++){
        int x = rand() % 16;
        int res = bin_count(bins, x);
        printf("Count val: %d\n", res);
    }
    return 0;
}