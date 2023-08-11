#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

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

void writeFile(FILE *file, Student olona[], int count){
    fprintf(file, "NOM;PRENOMS;CONTACT;DATE DE NAISSANCE;LIEU DE NAISSANCE;BACC;GENRE;DEPOT GITHUB\n");
    for (int i = 0; i < count; i++)
    	fprintf(file, "%s;%s;%s;%s;%s;%s;%s\n", (olona+i)->nom, (olona+i)->prenoms, (olona+i)->contact, (olona+i)->date_de_naissance, (olona+i)->lieu_de_naissance, (olona+i)->annee_bacc, (olona+i)->depot_git);
    
}

void readFile(FILE *in_file, Student olona[]){
	int i=0;char tmp[500]="";
	while(fgets(tmp, 500, in_file)){
		sscanf(tmp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t\n]", (olona+i)->nom, (olona+i)->prenoms, (olona+i)->contact, (olona+i)->date_de_naissance, (olona+i)->lieu_de_naissance, (olona+i)->annee_bacc, (olona+i)->depot_git);
		i++;
	}
}

void sort(Student *olona, int len_student){
	for(int i=0; i<len_student; i++){
		for(int j=i+1; j<len_student; j++){
			Student tmp;
			if(strcmp(olona[i].nom, olona[j].nom) > 0){
				tmp	= olona[i];
				olona[i]=olona[j];
				olona[j]=tmp;
			}
			else if(strcmp(olona[i].nom, olona[j].nom)==0){
				if(strcmp(olona[i].prenoms, olona[j].prenoms)>0){
					tmp	= olona[i];
				    olona[i]=olona[j];
				    olona[j]=tmp;		
				}
			}
		}
	}
}

void inputStudent( Student olona[], int count){
	for (int i = 0; i < count; ++i){
		printf("Nom: ");scanf("%s", olona[i].nom);
		printf("Prenoms: ");scanf("%s",olona[i].prenoms);
		printf("Tél: ");scanf("%s",olona[i].contact);
		printf("Date de naissance: ");scanf("%s",olona[i].date_de_naissance);
		printf("Lieu de naissance: ");scanf("%s",olona[i].lieu_de_naissance);
		printf("Annee du bacc: ");scanf("%s",olona[i].annee_bacc);
		printf("Genre: ");scanf("%s",olona[i].genre);
		printf("Depot git:");scanf("%s",olona[i].depot_git);
	}
}