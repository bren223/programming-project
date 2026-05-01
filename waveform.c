//
// Created by bj2-goodland on 02/04/2026.
//

#include "waveform.h"
#include <stdio.h>
#include <math.h>

double* V_RMS(data* data_pt){

    double ASum = 0, BSum = 0, CSum  = 0;
    for (int i = 1; i < 1001; i++) { //sum all the numbers ^2
        ASum = ASum + pow(data_pt->phase_A_voltage[i],2);
        BSum = BSum + pow(data_pt->phase_B_voltage[i],2);
        CSum = CSum + pow(data_pt->phase_C_voltage[i],2);
    }
    double RMS[6] = { sqrt(ASum / 1000), sqrt(BSum / 1000), sqrt(CSum / 1000) }; // calculate RMS and store in an array to pass out
    if (RMS[0] > 207 && RMS[0] < 253) { // 207 is 90% and 253 is 110% so if it is inbetween it will be +-10%
        RMS[3] = 1;
    }
    if (RMS[1] > 207 && RMS[1] < 253) {
        RMS[4] = 1;
    }
    if (RMS[2] > 207 && RMS[1] < 253) {
        RMS[5] = 1;
    }
    double* Pt = RMS; // pointer for array
    return Pt;
}
double* PtoP(data* data_pt) {
    double AMax = 0, AMin = 0, BMax = 0, BMin = 0, CMax = 0, CMin = 0;
    for (int i = 1; i < 1001; i++) { //sort all the max and min of the waves
        if (data_pt->phase_A_voltage[i] > AMax) {
            AMax = data_pt->phase_A_voltage[i];
        }
        else if (data_pt->phase_A_voltage[i] < AMin) {
            AMin = data_pt->phase_A_voltage[i];
        }
        if (data_pt->phase_B_voltage[i] > BMax) {
            BMax = data_pt->phase_B_voltage[i];
        }
        else if (data_pt->phase_B_voltage[i] < BMin) {
            BMin = data_pt->phase_B_voltage[i];
        }
        if (data_pt->phase_C_voltage[i] > CMax) {
            CMax = data_pt->phase_C_voltage[i];
        }
        else if (data_pt->phase_C_voltage[i] < CMin) {
            CMin = data_pt->phase_C_voltage[i];
        }
    }
    double Peak_to_Peak[3] = {AMax-AMin,BMax-BMin,CMax-CMin};
    double* Pt = Peak_to_Peak; // pointer for array
    return Pt;
}
double* DC_off(data* data_pt) {
    double ASum = 0, BSum = 0, CSum  = 0;
    for (int i = 1; i < 1001; i++) { //sum all the numbers
        ASum = ASum + data_pt->phase_A_voltage[i];
        BSum = BSum + data_pt->phase_B_voltage[i];
        CSum = CSum + data_pt->phase_C_voltage[i];
    }
    double DCOff[3] = { ASum/1000, BSum/1000, CSum/1000 };
    double* Pt = DCOff;
    return Pt;
}
double* clip(data* data_pt) {
    double Aclip[1000] = {0}, Bclip[1000] = {0}, Cclip[1000] = {0};
    int AmountA = 0, AmountB = 0, AmountC = 0;
    for (int i = 1; i < 1001; i++) {
        if (data_pt->phase_A_voltage[i] >= 324.9) {
            Aclip[AmountA] = data_pt->timestamp[i];
            AmountA++;
        }
        if (data_pt->phase_B_voltage[i] >= 324.9) {
            Bclip[AmountB] = data_pt->timestamp[i];
            AmountB++;
        }
        if (data_pt->phase_C_voltage[i] >= 324.9) {
            Cclip[AmountC] = data_pt->timestamp[i];
            AmountC++;
        }
    }
    double clip[2][1000];
    for (int i = 0; i < 1001; i++) {
        clip[0][i] = Aclip[i];
        clip[1][i] = Bclip[i];
        clip[2][i] = Cclip[i];
    }

    double* Pt = clip;
    return Pt;
}