#include <stdio.h>
#include "io.h"
#include "waveform.h"
#include <stdlib.h>

int main() {
    data* data_pt = read(); // reads data and makes a struct with the data then passes the pointer

    double* RMS = V_RMS(data_pt); // run RMS function
    double Wave_RMS[3] = {*RMS, *(RMS+1),*(RMS+2)}, RMS_10[3] = {*(RMS+3),*(RMS+4),*(RMS+5)}; // RMS values

    double* Peak_to_Peak = PtoP(data_pt); // run peak to peak function
    double Wave_PtoP[3] = {*Peak_to_Peak,*(Peak_to_Peak+1),*(Peak_to_Peak+2)}; // peak to peak values

    double* DCOff = DC_off(data_pt); // run DC offset function
    double Wave_DCOff[3] = {*DCOff,*(DCOff+1),*(DCOff+2)}; // DC offset values

    double* Clip = clip(data_pt); // run clip function
    int Clipamount[3] = {0}; // 1 is A / 2 is B / 3 is C

    for (int i = 0; i < 1000; i++) // find amount of times cliped
        if (*(Clip+i) > 0.0000 || *(Clip+i) < 0.0000 ){
            Clipamount[0]++;
        }
    for (int i = 1001; i < 2000; i++)
        if (*(Clip+i) > 0.0000 || *(Clip+i) < 0.0000 ){
            Clipamount[1]++;
        }
    for (int i = 2001; i < 3000; i++)
        if (*(Clip+i) > 0.0000 || *(Clip+i) < 0.0000 ){
            Clipamount[2]++;
        }
    double ClipA[Clipamount[0]],ClipB[Clipamount[1]],ClipC[Clipamount[2]];
    int a=0,b=0,c=0;
    for (int i = 0; i < 1000; i++) { // restric arrays to non 0 values
        if (*(Clip+i) > 0.0000 || *(Clip+i) < 0.0000 ) {
            ClipA[a] = *(Clip+i);
            a++;
        }
        if (*(Clip+i+1000) > 0.0000 || *(Clip+i+1000) < 0.0000 ) {
            ClipB[b] = *(Clip+i+1000);
            b++;
        }
        if (*(Clip+i+2000) > 0.0000 || *(Clip+i+2000) < 0.0000 ) {
            ClipC[c] = *(Clip+i+2000);
            c++;
        }
    }

    printf("\n Wave Data \n"); // print all values needed
    printf("Wave             /  WaveA /   WaveB /   WaveC \n ");
    printf("RMS              / %lf / %lf / %lf \n ",Wave_RMS[0],Wave_RMS[1],Wave_RMS[2]);
    printf("RMS+-10(1 = true)/ %lf / %lf / %lf \n",RMS_10[0],RMS_10[1],RMS_10[2]);
    printf("Peak to Peak     / %lf / %lf / %lf \n",Wave_PtoP[0],Wave_PtoP[1],Wave_PtoP[2]);
    printf("DC offset        / %lf / %lf / %lf \n",Wave_DCOff[0],Wave_DCOff[1],Wave_DCOff[2]);

    printf("Wave A clipped %d the times are: \n",Clipamount[0]);
    for (int i = 0; i < Clipamount[0]; i++) {
        printf("/ %lf ",ClipA[i]);
    }

    printf("\n Wave B clipped %d the times are: \n",Clipamount[1]);
    for (int i = 0; i < Clipamount[1]; i++) {
        printf("/ %lf ",ClipB[i]);
    }

    printf("\n Wave C clipped %d the times are: \n",Clipamount[2]);
    for (int i = 0; i < Clipamount[2]; i++) {
        printf("/ %lf ",ClipC[i]);
    }

    char output[] = "hellow ";
    write(Wave_RMS,RMS_10, Peak_to_Peak,Wave_DCOff,Clipamount,ClipA,ClipB,ClipC);

    free(data_pt);

    return 0;
}