#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lab.h"

void menu(char *fname){
    int a;
    int a1;
    med *head=NULL;
    med *d;
    med *d1;
    int get_variant;
    head=read(fname);
    printf("Меню: \n");
    do{
        printf("(1) Ассортимент \n");
        printf("(2) Ввод данных \n");
        printf("(3) Редактирование данных \n");
        printf("(4) Поиск по названию \n");
        printf("(5) Поиск по назначению \n");
        printf("(6) Удаление данные \n");
        printf("(7) Выход \n");

        scanf("%d", &get_variant);
        getchar();
        switch(get_variant){
		case 1:
                d=head;
                       if(d==NULL){
                                printf("Нет данных\n");
                                break;
                       }
                while(d!=NULL){
                    printf("Название: \n Назначение: \n Цена: \n",
                    d->name, d->purpose, d->price);
                    d=d->apt;
                }
            break;

		case 2:
                head=newmed(head);
            break;

		case 3:
                d=head;
                if(d==NULL){
                    printf("Нет данных\n");
                    break;
                }
                printf("введите название лекарства: \n");
                d=find1(input(), d);
                if(d==NULL){
                    printf("Нет данных\n");
                    break;
                }
                edit(d);
            break;

		case 4:
                d=head;
                       if(d==NULL){
                                printf("Нет данных\n");
                                break;
                       }
                       printf("введите название лекарства: \n");
                       d=find1(input(), d);
                       if(d==NULL){
                                printf("Нет данных\n");
                                break;
                       }
                printf("Название: %s\n Назначение: %s\n Цена: %s\n",
                                d->name, d->purpose, d->price);
            break;

		case 5:
                d=head;
                       if(d==NULL){
                                printf("Нет данных\n");
                                break;
                       }
                       printf("Введите назначение: ");
                       find2(input(), d);
            break;

		case 6:
                d=head;
                d1=head;
                if(d==NULL){
                    printf("Нет данных\n");
                    break;
                }
                printf("Введите название лекарства: \n");
                d=find1(input(), d);
                if(d==NULL){
                    printf("Нет данных\n");
                    break;
                }
                if(d==head)
                    head=del(d);
                else{
                    while(1){
                        if(d1->apt==d)
                            break;
                        else d1=d1->apt;
                    }
                    d1->apt=del(d);
                }
            break;


		case 7:
                write(head, fname);
                printf("Завершение работы \n");
            break;
            default:
                printf("Такого пункта в меню нет \n");
            break;
        }
    }
	while(get_variant!=7);
}

