#include "HLS/hls.h"
#include "pool.h"
#include <algorithm>
#include "HLS/stdio.h"
component void matrix_relu(int rows, int cols, input_image_stream& original_image, output_image_stream& relu_image){
    unsigned int b[1000][1000];
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < cols;j++){
            unsigned int tmp = original_image.read();
            b[i][j] = tmp;
        }
    }
    #pragma unroll
    for(int x = 0;x < rows;x++){
        for(int y = 0;y < cols;y++){ 
            unsigned int max1 = 0;
            max1 = std::max(max1, b[x][y]);
            relu_image.write(max1);
        }
    }
}