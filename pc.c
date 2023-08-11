#include <stdio.h>
#include <stdlib.h>
#include "pc.h"


int main(){
	FILE *input_file=fopen("fichier_struct_PC_get.txt","r");
	FILE *output_file=fopen("pc_sorted_by_label.csv","w");
	if(input_file==NULL) {fprintf(stderr, "%s\n", "ERROR: FILE CANNOT BE OPEN!! input file");exit(100);}
    if(output_file==NULL) {fprintf(stderr, "%s\n", "ERROR: FILE CANNOT BE OPEN!! output file");exit(100);}
	Pc *computer=NULL;
	int count=0;
	count=countLine(input_file);
	computer=(Pc*)malloc(sizeof(Pc)*count);
	readFile(input_file, computer);
	sort(computer, count);
	writeFile(output_file, computer, count);
	fclose(input_file);
	fclose(output_file);
	return 0;
}