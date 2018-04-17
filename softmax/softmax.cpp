#include "HLS/hls.h"
#include "softmax.h"
#include "HLS/stdio.h"
#include "HLS/extendedmath.h"
#include "HLS/math.h"

component void softmax(int num, input_score_stream& original_score, output_score_stream& softmax_score){
    float t[10];
    float sum = 0.0;
    for(int i = 0;i < num;i++){
        t[i] = original_score.read();
        float tmp = exp(t[i]);
        sum += tmp;
    }

    float t_magnitude_inv = 1.0 / sum;

    for(int i = 0;i < num;i++){
        softmax_score.write(exp(t[i]) * t_magnitude_inv);
    }
}