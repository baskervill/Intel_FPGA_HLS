#ifndef POOL_H
#define POOL_H

typedef ihc::stream_in<unsigned int> input_image_stream;
typedef ihc::stream_out<unsigned int> output_image_stream;

component void matrix_relu(int rows, int cols, input_image_stream& original_image, output_image_stream& relu_image);
#endif