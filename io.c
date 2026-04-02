//
// Created by bj2-goodland on 02/04/2026.
//
#include <stdio.h>
#include "io.h"
int read(void){
    FILE *fp;
    fp = fopen("power_quality_log.csv","r");
    if (fp == NULL){
        printf("file reading error");
        return 1;
    }
    char line[1024];
    double timestamp,phase_A_voltage,phase_B_voltage,phase_C_voltage,line_current,frequency,power_factor,thd_percent;

    while(fscanf(fp,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&timestamp,&phase_A_voltage,&phase_B_voltage,&phase_C_voltage,&line_current,&frequency,&power_factor,&thd_percent)==8){
        printf("timestamp: %lf phase_A_voltage: %lf phase_B_voltage: %lf phase_C_voltage: %lf line_current: %lf frequency: %lf power_factor: %lf thd_percent: %lf \n",timestamp,phase_A_voltage,phase_B_voltage,phase_C_voltage,line_current,frequency,power_factor,thd_percent);
    }
    fclose(fp);
    return 0;
}