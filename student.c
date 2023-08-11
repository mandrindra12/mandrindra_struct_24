#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

int main(){
    int ligne=0;
    FILE *outp_file=NULL,*inp_file=NULL;
    inp_file=fopen("mpianatra_0.txt","r");
    outp_file=fopen("mpianatra_1.csv","w");
    if(inp_file==NULL) {fprintf(stderr, "%s\n", "ERROR: FILE CANNOT BE OPEN!! input file");exit(100);}
    if(outp_file==NULL) {fprintf(stderr, "%s\n", "ERROR: FILE CANNOT BE OPEN!! output file");exit(100);}
    ligne=countLine(inp_file);
    //printf("Nombre d'eleve: ");scanf("%d",&ligne);
    Student *olona;
    olona = (Student*)malloc(sizeof(Student)*ligne);
    //input_student(olona, n);//the input here is from stdin
    //input here is from file named mpianatra_0.txt where each value is separated by \t (tab)
    readFile(inp_file, olona);
    sort(olona, ligne);
    writeFile(outp_file, olona, ligne);
    fclose(inp_file);
    fclose(outp_file);
    return 0;
}