#include "HLS/hls.h"
#include "pool.h"
#include <algorithm>
#include "HLS/stdio.h"
component void matrix_pool(int rows, int cols, input_image_stream& original_image, output_image_stream& pool_image){
    /*
    unsigned int** b = new unsigned int* [rows];
    for(int i = 0;i < cols ;i++) b[i] = new unsigned int [cols];
    */
    unsigned int b[1000][1000];
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < cols;j++){
            unsigned int tmp = original_image.read();
            b[i][j] = tmp;
        }
    }
    int step = 2;
    int count = 0;
    #pragma unroll
    for(int x = 0;x < rows;x += step){
        for(int y = 0;y < cols;y += step){
            unsigned int max1 = 0;
            for(int i = 0 ;i < step;i++){
                for(int j = 0;j < step;j++){
                    max1 = std::max(max1, b[x + i][y + j]);
                }
            }
            pool_image.write(max1);
            count++;
        }
    }
    printf("count:%d\n", count);
    /*
    for(int i = 0;i < rows;i++)
        delete[] b[i];
    delete[] b;
    */
}