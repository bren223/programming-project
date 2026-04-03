//
// Created by bj2-goodland on 02/04/2026.
//
#include <stdio.h>
#include "io.h" //link it to header

double read(void){
    FILE *fp= fopen("power_quality_log.csv","r"); //open the file
    if (fp == NULL){ //check if the file is empty
        printf("file reading error");
        return 1;
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
    double data[lines][8];

    for (int i = 0; i < lines; i++) {
        data[i][0] = timestamp[i];
        data[i][1] = phase_A_voltage[i];
        data[i][2] = phase_B_voltage[i];
        data[i][3] = phase_C_voltage[i];
        data[i][4] = line_current[i];
        data[i][5] = frequency[i];
        data[i][6] = power_factor[i];
        data[i][7] = thd_percent[i];
    }
    printf("%lf",data[0][4]);
    return 0;
}
