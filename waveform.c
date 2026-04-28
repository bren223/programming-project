//
// Created by bj2-goodland on 02/04/2026.
//

#include "waveform.h"
#include <stdio.h>
#include <math.h>

double V_RMS(data* data_pt){

    printf("\n----------");
    double Asum, Bsum, Csum;
    int amount;
    for (int i = 0; i < 1001; i++) {
        Asum = Asum + data_pt->phase_A_voltage[i];
        Bsum = Bsum + data_pt->phase_B_voltage[i];
        Csum = Csum + data_pt->phase_C_voltage[i];
        if (data_pt->phase_A_voltage[i] != 0){
            amount ++;
        }
        printf("%lf",Asum/amount);
    }
}