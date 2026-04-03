//
// Created by bj2-goodland on 02/04/2026.
//
#include <stdio.h>
#include <string.h>
#include "io.h" //link it to header
#include <math.h>
double read(void){
    FILE *fp= fopen("power_quality_log.csv","r"); //open the file
    if (fp == NULL){ //check if the file is empty
        printf("file reading error");
        return 1.0;
    }
    FILE *temp_fp = fopen("power_quality_log.csv","r"); //open the file
    int lines = -1;
    for (char c = getc(temp_fp); c != EOF; c = getc(temp_fp)) { // count how many lines in file
        if (c == '\n') {
            lines ++;
        }
    }

    char line[lines];
    double timestamp[lines],phase_A_voltage[lines],phase_B_voltage[lines],phase_C_voltage[lines],line_current[lines],frequency[lines],power_factor[lines],thd_percent[lines]; //arrays to keep each colum of the data
    fgets(line,lines,fp);
    int i = 0;
    while(fscanf(fp,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&timestamp[i],&phase_A_voltage[i],&phase_B_voltage[i],&phase_C_voltage[i],&line_current[i],&frequency[i],&power_factor[i],&thd_percent[i])==8){
        i++; // set the values in the array to the ones in the csv file
    }
    for (int i = 0; i < lines; i++) {
        printf("%lf ", phase_A_voltage[i]);
    }
    fclose(fp); // close file
    return 0.0;
}