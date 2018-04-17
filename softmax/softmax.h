#ifndef POOL_H
#define POOL_H

typedef ihc::stream_in<int> input_score_stream;
typedef ihc::stream_out<int> output_score_stream;

component void softmax(input_score_stream& original_score, output_score_stream& softmax_score);
#endif