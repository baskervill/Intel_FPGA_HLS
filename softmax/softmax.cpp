#include "HLS/hls.h"
#include "softmax.h"
#include "HLS/stdio.h"
#include "HLS/extendedmath.h"
#include "HLS/math.h"

component void softmax(int num, input_score_stream& original_score, output_score_stream& softmax_score){
    int t[i];
    int sum = 0;
    for(int i = 0;i < num;i++){
        t[i] = originnal_score.read();
        sum += t[i];
    }
    float t_magnitude_inv = RSQRT(sum);
    for(int i = 0;i < num;i++){
        softmax_score.write(t[i] * t_magnitude_inv);
    }
}