#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

#define N 5

struct Chemical_element {
    char name[N];
    int number;
    int group;
    float weight;
};

int main() {
    struct Chemical_element* mas;
    int n;
    printf("Введите количество химических элементов: ");
    scanf("%d", &n);
    mas = (struct Chemical_element*)malloc(n * sizeof(struct Chemical_element));
    for (int i = 0; i < n; i++) {
        printf("Введите название %d химического элемента: ", i + 1);
        scanf("%s", mas[i].name);
        printf("Введите номер %d химического элемента: ", i + 1);
        scanf("%d", &(mas[i].number));
        printf("Введите группу %d химического элемента: ", i + 1);
        scanf("%d", &(mas[i].group));
        printf("Введите атомную массу %d химического элемента: ", i + 1);
        scanf("%f", &(mas[i].weight));
    }
    
    printf("Массив перед сортировкой:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %.3f\n", mas[i].name, mas[i].number, mas[i].group, mas[i].weight);
    }
    
    char l[5];
    int d;
    int c;
    float b;
    bool f;
    do {
        f=false;
        for (int i=0;i<n-1;i++) {
            if(strcmp(mas[i].name,mas[i+1].name) > 0) {
                f=true;
                strcpy(l, mas[i].name);
                strcpy(mas[i].name, mas[i+1].name);
                strcpy(mas[i+1].name, l);
                
                d = mas[i].number;
                mas[i].number = mas[i+1].number;
                mas[i+1].number = d;
                
                c = mas[i].group;
                mas[i].group = mas[i+1].group;
                mas[i+1].group = c;
                
                b = mas[i].weight;
                mas[i].weight = mas[i+1].weight;
                mas[i+1].weight = b;
                } 
        }
        }
        while(f);

    printf("Итоговый массив:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %.3f\n", mas[i].name, mas[i].number, mas[i].group, mas[i].weight);
    }
    free(mas);
    return 0;
}