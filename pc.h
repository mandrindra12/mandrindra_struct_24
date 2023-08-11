#ifndef __PC__
#define __PC__

typedef struct{
	char addr_mac[20];
	char label[50];
	char marque[50];
}Pc;
void readFile(FILE *in_file, Pc pc[]);
void sort(Pc *pc, int number);
void writeFile(FILE *file, Pc *pc, int count);
int countLine(FILE *file);

#endif