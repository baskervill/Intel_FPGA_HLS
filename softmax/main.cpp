// main.cpp
#include "HLS/hls.h"
#include "softmax.h"

#include <string>
#include <stdio.h> //printf
#include <stdlib.h> // malloc, free

int main (void) {


  input_score_stream in_score;
  output_score_stream out_score;
  const size_t t = 4;
  float in[4] = {1.0, 2.0, 3.0, 4.0};
  float out[4] = {0.0};
  for (int i = 0; i < t; ++i) {
    in_score.write(in[i]);
  }
  
  softmax(t, in_score, out_score);

  for (int i = 0; i < t; ++i) {
    out[i] = out_score.read();
    printf("%f ", out[i]);
  }
  printf("\n");
  
  return 0;
}
  