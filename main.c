#include <stdio.h>
#include "io.h"
#include "waveform.h"

int main() {
    data* data_pt = read(); // reads data and makes a struct with the data then passes the pointer
    printf("\n %lf",data_pt->timestamp[3]);

    double* RMS = V_RMS(data_pt);
    double A_RMS = *RMS,B_RMS = *(RMS+1),C_RMS = *(RMS+2), RMS_10[3] = {*(RMS+3),*(RMS+4),*(RMS+5)};
    printf("\n %lf",A_RMS);

    double* Peak_to_Peak = PtoP(data_pt);
    double A_PtoP = *Peak_to_Peak,B_PtoP = *(Peak_to_Peak+1),C_PtoP = *(Peak_to_Peak+2);
    printf("\n %lf",B_PtoP);

    double* DCOff = DC_off(data_pt);
    double A_DCOff = *DCOff,B_DCOff = *(DCOff+1),C_DCOff = *(DCOff+2);
    printf("\n %lf",C_DCOff);

    double* Clip = clip(data_pt);
    int ClipAamount = 0,ClipBamount = 0,ClipCamount = 0;

    for (int i = 0; i < 1000; i++)
        if (*(Clip+i) > 0.0000 || *(Clip+i) < 0.0000 ){
            ClipAamount++;
        }
    for (int i = 1001; i < 2000; i++)
        if (*(Clip+i) > 0.0000 || *(Clip+i) < 0.0000 ){
            ClipBamount++;
        }
    for (int i = 2001; i < 3000; i++)
        if (*(Clip+i) > 0.0000 || *(Clip+i) < 0.0000 ){
            ClipCamount++;
        }
    double Aclip[ClipAamount], Bclip[ClipBamount],Cclip[ClipCamount];
    int a=0, b=0, c=0;
    for (int i = 0; i < 1000; i++) {
        if (*(Clip+i) > 0.0000 || *(Clip+i) < 0.0000 ) {
            Aclip[a] = *(Clip+i);
            a++;
        }
        if (*(Clip+i+1000) > 0.0000 || *(Clip+i+1000) < 0.0000 ) {
            Bclip[b] = *(Clip+i+1000);
            b++;
        }if (*(Clip+i+2000) > 0.0000 || *(Clip+i+2000) < 0.0000 ) {
            Cclip[c] = *(Clip+i+2000);
            c++;
        }
    }
    printf("---%lf----",Aclip[]);

    printf("\n Wave Data \n");
    printf("Wave             /  WaveA /   WaveB /   WaveC \n ");
    printf("RMS              / %lf / %lf / %lf \n ",A_RMS,B_RMS,C_RMS);
    printf("RMS+-10(1 = true)/ %lf / %lf / %lf \n",RMS_10[0],RMS_10[1],RMS_10[2]);
    printf("Peak to Peak     / %lf / %lf / %lf \n",A_PtoP,B_PtoP,C_PtoP);
    printf("DC offset        / %lf / %lf / %lf \n",A_DCOff,B_DCOff,C_DCOff);



    return 0;
}
