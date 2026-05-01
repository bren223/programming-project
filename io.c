//
// Created by bj2-goodland on 02/04/2026.
//
#include <stdio.h>
#include "io.h" //link it to header

data* read(void){
    FILE *fp= fopen("power_quality_log.csv","r"); //open the file
    if (fp == NULL){ //check if the file is empty
        printf("file reading error");
        //return 1;
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

    fclose(fp); // close file

    data file_data; // inisalize the struct

    for (int i = 0; i < 1001; i++) { // set the arrays in the stuct to the file data
        file_data.timestamp[i] = timestamp[i];
        file_data.phase_A_voltage[i] = phase_A_voltage[i];
        file_data.phase_B_voltage[i] = phase_B_voltage[i];
        file_data.phase_C_voltage[i] = phase_C_voltage[i];
        file_data.line_current[i] = line_current[i];
        file_data.frequency[i] = frequency[i];
        file_data.power_factor[i] = power_factor[i];
        file_data.thd_percent[i] = thd_percent[i];
    }

    data* pt = &file_data; // variable to pass the pointer

    return pt;
}

void write(double Wave_RMS[3], double RMS_10[3], double Peak_to_Peak[3],double Wave_DCOff[3], int Clipamount[3], double ClipA[],double ClipB[], double ClipC[]){
    FILE *Output = fopen("Output.txt","w");
    fprintf(Output,"Wave Data \n"
                   "Wave             /  WaveA /   WaveB /   WaveC \n ");
    fprintf(Output,"RMS              / %lf / %lf / %lf \n ",Wave_RMS[0],Wave_RMS[1],Wave_RMS[2]);
    fprintf(Output,"RMS+-10(1 = true)/ %lf / %lf / %lf \n",RMS_10[0],RMS_10[1],RMS_10[2]);
    fprintf(Output,"Peak to Peak     / %lf / %lf / %lf \n",Peak_to_Peak[0],Peak_to_Peak[1],Peak_to_Peak[2]);
    fprintf(Output,"DC offset        / %lf / %lf / %lf \n",Wave_DCOff[0],Wave_DCOff[1],Wave_DCOff[2]);

    fprintf(Output,"Wave A cliped %d the times are: \n",Clipamount[0]);
    for (int i = 0; i < Clipamount[0]; i++) {
        fprintf(Output,"/ %lf ",ClipA[i]);
    }

    fprintf(Output,"\n Wave B cliped %d the times are: \n",Clipamount[1]);
    for (int i = 0; i < Clipamount[1]; i++) {
        fprintf(Output,"/ %lf ",ClipB[i]);
    }

    fprintf(Output,"\n Wave C cliped %d the times are: \n",Clipamount[2]);
    for (int i = 0; i < Clipamount[2]; i++) {
        fprintf(Output,"/ %lf ",ClipC[i]);
    }

    fclose(Output);
}
