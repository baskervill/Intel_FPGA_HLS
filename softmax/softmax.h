#ifndef SOFTMAX_H
#define SOFTMAX_H

typedef ihc::stream_in<float> input_score_stream;
typedef ihc::stream_out<float> output_score_stream;

component void softmax(int num, input_score_stream& original_score, output_score_stream& softmax_score);
#endif