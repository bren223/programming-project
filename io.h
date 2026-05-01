//
// Created by bj2-goodland on 02/04/2026.
//

#ifndef PROJECT_IO_H
#define PROJECT_IO_H

typedef struct { // set up the struct to store the file data
    double timestamp[1000];
    double phase_A_voltage[1000];
    double phase_B_voltage[1000];
    double phase_C_voltage[1000];
    double line_current[1000];
    double frequency[1000];
    double power_factor[1000];
    double thd_percent[1000];
}data;

data* read(void);

void write();

#endif //PROJECT_IO_H
