#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lab.h"


char* input() {
    char buff[128];
    char* k;
    fgets(buff, 128, stdin);
    k = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
    strcpy(k, buff);
    return k;
}


med* newmed(med* head) {
    char* h1;
    med* nmed = (med*)malloc(sizeof(med));
    for (int i = 0; i < 1;) {
        printf("Ведите название лекарства: \n");
        h1 = input();
        if (h1 != NULL) {
            i++;
            nmed->name = h1;
        }
    }
    for (int i = 0; i < 1;) {
        printf("Введите назначение: \n");
        h1 = input();
        if (h1 != NULL) {
            i++;
            nmed->purpose = h1;
        }
    }
    for (int i = 0; i < 1;) {
        printf("Введите цену: \n");
        h1 = input();
        if (h1 != NULL) {
            i++;
            nmed->price = h1;
        }
    }

    return nmed;
}


char* newread(FILE* file, char* k) {
    char* t;
    t = (char*)malloc(sizeof(char) * strlen(k) + 1);
    strcpy(t, k);
    return t;
}
med* read(char* fname) {
    FILE* file;
    char* e;
    char k[150];
    med* head = NULL;
    file = fopen(fname, "r");
    if (file == NULL) {
        return head;
    }
    while (1) {
        int p3;
        med* temp;
        e = fgets(k, 150, file);
        if (e == 0)break;
        temp = (med*)malloc(sizeof(med));
        temp->name = newread(file, k);
        fgets(k, 150, file);
        temp->purpose = newread(file, k);
        fgets(k, 150, file);
        temp->price = newread(file, k);
        temp->apt = head;
        head = temp;
    }
    fclose(file);
    return head;
}


void edit(med* head) {
    int y;
    do {
        printf("Что хотите редактировать? \n");
        printf("(1) Название \n");
        printf("(2) Назначение \n");
        printf("(3) Цену \n");
        printf("(4) Выход \n");
        scanf("%d", &y);
        char h1[2];
        int i;
        switch (y) {
        case 1:
            getchar();
            printf("Введите название лекарства: \n");
            free(head->name);
            printf("\n");
            head->name = input();
            break;
        case 2:
            getchar();
            printf("Введите назначение: \n");
            free(head->purpose);
            printf("\n");
            head->purpose = input();
            break;
        case 3:
            getchar();
            printf("Введите цену: \n");
            free(head->price);
            printf("\n");
            head->price = input();
            break;
        }
    } while (y != 4);
}


med* find1(char* str, med* head) {
    while (head != NULL) {
        if (!strcmp(head->name, str))
            break;
        else head = head->apt;
    }
    return head;
}


int* find2(char* str, med* head) {
    int i = 0;
    while (head != NULL) {
        if (!strcmp(head->purpose, str)) {
            i++;
            printf("Название:%s \n Назначение:%s \n Цена:%s \n", head->name, head->purpose, head->price);
            head = head->apt;
        }
        else head = head->apt;
    }
    if (i == 0)
        printf("Нет данных \n");
    return 0;
}


med* del(med* head) {
    med* d2;
    d2 = head->apt;
    free(head->name);
    free(head->purpose);
    free(head->price);
    free(head);
    return d2;
}


void write(med* head, char* fname) {
    FILE* file;
    file = fopen(fname, "w");
    while (head != NULL) {
        fprintf(file, "%s%s%s \n", head->name, head->purpose, head->price);
        head = del(head);
    }
    fclose(file);
}
