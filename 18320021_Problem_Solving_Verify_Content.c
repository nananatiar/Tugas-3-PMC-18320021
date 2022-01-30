//PROGRAM MENENTUKAN TIPE FILE BERDASARKAN CONTENT FILE
#include <stdio.h>
#define maxchar_fn 50 // Max nama file 50 character
#define sig_byte 5

int main () {
    //KAMUS
    char namafile [maxchar_fn];
    unsigned char val[sig_byte]; 
    FILE *filep;
    //ALGORITMA
    printf("Masukkan Nama File : "); 
    scanf("%s", namafile); // Mendefine nama file sebagai variabel namafile
    
    filep = fopen(namafile,"r");
    if (filep != NULL){
        fread(val, sig_byte, 1, filep);
        printf("%x %x %x %x %x\n", val[0],val[1],val[2],val[3],val[4]); // Menampilkan content file

        if ((val[0] == 0x25) && (val[1] == 0x50) && (val[2] == 0x44) 
            && (val[3] == 0x46) && (val[4] == 0x2d)){
            printf("File %s merupakan PDF\n", namafile);
        } // File memiliki content pdf
        else if ((val[0] == 0xFF) && (val[1] == 0xd8) && (val[2] == 0xFF)) {
            printf("File %s merupakan JPG\n", namafile);
        } // File memiliki content jpg
        else {
            printf("File tidak terdefinisi\n");
        } // File tidak memiliki konten baik pdf maupun jpg 
    }
    fclose(filep);
    return 0;
}