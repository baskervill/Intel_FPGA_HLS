// main.cpp
#include "HLS/hls.h"
#include "relu.h"
#include "bmp_tools.h"

#include <string>
#include <stdio.h> //printf
#include <stdlib.h> // malloc, free

int main (void) {
  // image files
  std::string input_bmp_filename    = "test.bmp";
  std::string output_bmp_filename   = "relu.bmp";

  // load image
  unsigned int* in_img = 0;;
  int rows, cols;
  read_bmp(input_bmp_filename.c_str(), &in_img, rows, cols);

  input_image_stream in_img_s;
  output_image_stream out_img_s;
  
  for (int i = 0; i < (rows*cols); ++i) {
    in_img_s.write(in_img[i]);
  }
  
  
  matrix_relu(rows, cols, in_img_s, out_img_s);
  
  // save output image
  int out_rows = rows;
  int out_cols = cols;
  unsigned int* out_img = (unsigned int*) malloc(out_rows * out_cols * sizeof(unsigned int));
  for (int i = 0; i < (out_rows*out_cols); ++i) {
    out_img[i] = out_img_s.read();
  }
  write_bmp(output_bmp_filename.c_str(), out_img, out_rows, out_cols);

  return 0;
}
  