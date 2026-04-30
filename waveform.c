//
// Created by bj2-goodland on 02/04/2026.
//

#include "waveform.h"
#include <stdio.h>
#include <math.h>

double V_RMS(data* data_pt){

    printf("\n----------");
    double ASum = 0, BSum = 0, CSum  = 0;
    for (int i = 1; i < 1001; i++) {
        ASum = ASum + data_pt->phase_A_voltage[i];
        printf("\n %lf",data_pt->phase_A_voltage[i]);
        BSum = BSum + data_pt->phase_B_voltage[i];
        CSum = CSum + data_pt->phase_C_voltage[i];
    }
    printf("\n %lf",ASum);
}