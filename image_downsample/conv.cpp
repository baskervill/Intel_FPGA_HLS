#include "HLS/hls.h"
#include "conv.h"
#include "HLS/stdio.h"

component void matrix_conv(int rows, int cols, input_image_stream& original_image, output_image_stream& conv_image, float k[][3]){
    /*
    unsigned int** a = new unsigned int* [rows];
    for(int i = 0;i < cols;i++) a[i] = new unsigned int [cols];
    */
    unsigned int a[rows][cols];
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < cols;j++){
            unsigned int tmp = original_image.read();
            a[i][j] = tmp;
        }
    }
    int count = 0;
    #pragma unroll
    for(int xix = 0;xix < rows - 4;xix++){
        for(int yix = 0;yix < cols - 4;yix++){
            float sum = 0.0f;
            for(int kxix = 0;kxix < 3;kxix++){
                for(int kyix = 0;kyix < 3;kyix++){
                    sum += a[xix + kxix][yix + kyix] * k[kxix][kyix];
                }
            }
            conv_image.write(sum);
        }
    }
    /*
    for(int i = 0;i < rows;i++)
           delete[] a[i];
    delete[] a;
    */
}