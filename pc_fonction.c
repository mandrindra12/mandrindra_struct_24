#include <stdio.h>
#include <string.h>
#include "pc.h"

void readFile(FILE *in_file, Pc *pc){
	int i=0;
	char nom[256]="";
	//each value is separated by '\t'
	while(fgets(nom, 256, in_file)){
		sscanf(nom, "%[^\t]\t%[^\t]\t%[^\t\n]", (pc+i)->addr_mac, (pc+i)->label, (pc+i)->marque);
		i++;
	}

}

void writeFile(FILE *file, Pc *pc, int count){
    fprintf(file, "LABEL;ADRESSE MAC;MARQUE\n");
    for (int i = 0; i < count; i++) fprintf(file, "%s;%s;%s\n",  (pc+i)->label, (pc+i)->addr_mac, (pc+i)->marque);
}


void sort(Pc *pc, int number){
	for(int i=0; i<number; i++){
		for(int j=i+1; j<number; j++){
			Pc tmp;
			if(strcmp(pc[i].label, pc[j].label) > 0){
				tmp	= pc[i];
				pc[i]=pc[j];
				pc[j]=tmp;
			}
		}
	}
}

int countLine(FILE *file){
	int count=0;
	char actuel='0';
	while(!feof(file)){
		actuel=fgetc(file);
		if(actuel=='\n') count++;
	}
	rewind(file);
	return count;
}
