// main.cpp
#include "HLS/hls.h"
#include "conv.h"
#include "bmp_tools.h"
#include "pool.h"

#include <string>
#include <stdio.h> //printf
#include <stdlib.h> // malloc, free

int main (void) {
  // image files
  std::string input_bmp_filename    = "test.bmp";
  std::string output_bmp_filename   = "conv.bmp";

  // load image
  unsigned int* in_img = 0;;
  int rows, cols;
  read_bmp(input_bmp_filename.c_str(), &in_img, rows, cols);

  input_image_stream in_img_s;
  input_image_stream in_img_s2;
  output_image_stream out_img_s1;
  output_image_stream out_img_s2;
  
  for (int i = 0; i < (rows*cols); ++i) {
    in_img_s.write(in_img[i]);
  }
  
  float k[3][3] = {-1.0,-1.0,-1.0,-1.0,8.0,-1.0,-1.0,-1.0,-1.0};
  matrix_conv(rows, cols, in_img_s, out_img_s1, k);

  for (int i = 0; i < (rows-4)*(cols-4); ++i) {
    unsigned int tmp;
    tmp = out_img_s1.read();
    in_img_s2.write(tmp);
  }
  
  matrix_pool(rows-4, cols-4, in_img_s2, out_img_s2);

  
  // save output image
  int out_rows = (rows - 4) / 2;
  int out_cols = (cols - 4) / 2;
  unsigned int* out_img = (unsigned int*) malloc(out_rows * out_cols * sizeof(unsigned int));
  for (int i = 0; i < (out_rows*out_cols); ++i) {
    out_img[i] = out_img_s2.read();
  }
  write_bmp(output_bmp_filename.c_str(), out_img, out_rows, out_cols);

  return 0;
}
  