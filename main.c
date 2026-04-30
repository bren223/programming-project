#include <stdio.h>
#include "io.h"
#include "waveform.h"

int main() {
    data* data_pt = read(); // reads data and makes a struct with the data then passes the pointer
    printf("\n %lf",data_pt->timestamp[3]);

    V_RMS(data_pt);

    return 0;
}
