#include"lab.h"
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Файл не создан \n");
        exit(1);
    }
    FILE *file;
    file=fopen(argv[1], "r");
    if(file == NULL){
        printf("Неправильное имя файла \n");
                exit(1);
    }
    char* fname = argv[1];
    menu(fname);
    return 0;
}
