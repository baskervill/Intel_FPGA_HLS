#ifndef CONV_H
#define CONV_H
/*
struct mat{
    int m;
    int n;
};
struct ker{
    int km;
    int kn;
}
struct kernel{
    const int* kernel_shape;
    const int* stride;
    const int* pad;
    const int* dilation;
};
*/
typedef ihc::stream_in<unsigned int> input_image_stream;
typedef ihc::stream_out<unsigned int> output_image_stream;

component void matrix_conv(int rows, int cols, input_image_stream& original_image, output_image_stream& resized_image, float k[][3]);

#endif //CONV_H