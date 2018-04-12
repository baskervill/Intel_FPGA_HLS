#include "HLS/stdio.h"
#include "HLS/hls.h"

component void say_hello() {
    printf("Hello from the componet \n");
}

int main(){
    printf("Hello from the testbench \n");
    say_hello();
    return 0;
}