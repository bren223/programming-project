#include <stdio.h>
#include "io.h"

int main() {
    data* data_pt = read(); // reads data and makes a struct with the data then passes the pointer
    printf("%lf",data_pt->timestamp[3]);

    return 0;
}
