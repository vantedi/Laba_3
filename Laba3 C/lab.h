#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct med {
char *name;
char *purpose;
char *price;
struct med *apt;
}med;

char *input();
med *newmed(med *head);
med *del(med *head);
void write(med *head, char *fname);
void edit(med *head);
med *find1(char *str, med *head);
int *find2(char *str, med *head);
char *newread(FILE *file, char *k);
med *read(char *fname);
char*fanc(int n);
void menu(char *fname);

