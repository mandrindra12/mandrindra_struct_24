#ifndef __STUDENT__
#define __STUDENT__

typedef struct{
    char nom[256];
    char prenoms[256];
    char contact[20];
    char date_de_naissance[50];
    char lieu_de_naissance[100];
    char annee_bacc[20];
    char genre[20];
    char depot_git[256];
}Student;

int countLine(FILE *file);
void readFile(FILE *in_file, Student olona[]);
void inputStudent( Student olona[], int count);
void writeFile(FILE *file, Student *olona, int count);
void sort(Student *olona, int len_student);

#endif