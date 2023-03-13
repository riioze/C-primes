#include <stdio.h>
#include <stdlib.h>


typedef struct cList{
    int value;
    struct cList* next;
    struct cList* last;
} cList;



int size(cList *list){
    cList * current = list;
    int i;
    for(i=1; current->next != NULL; i++){
        current = current->next;
    }
    return i;
}


void freee(cList *list){
    if (list != NULL){
        freee(list->next);
        free(list);
    }
}


void setvalue(cList *list,int index,int value){
    cList *current = list;
    for (int i = 0; i<index;i++){
        current = current->next;
    }
    current->value = value;
    
}

void freeall(cList *list, int **r){
    int s = size(list);
    int *l = malloc(sizeof(int)*s);
    cList * current = list;
    for (int i = 0; current != NULL; i++){
        l[i] = current->value;
        current = current->next;
    }
    *r = l;

}

cList * add(cList *list,int value){
    cList *new = (cList*)malloc(sizeof(cList));
    new->value = value;
    list->last->next = new;
    list->last = new;
    return new;
}

int isprime(cList *list,int value){
    
    for (cList *current = list; current->value*current->value<=value;current=current->next){
        if (value%current->value == 0){
            return 0;
        }
    }
    return 1;
}

cList * primes(cList *pList,int max){
    pList->value = 2;
    for (int i=3; i<=max;i++){
        if (isprime(pList,i)){
            add(pList,i);
        }
    }
    return pList;
}

void show(int list[], int len){
    for (int i=0; i<len;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}

int main() {

    cList *pList = (cList*)malloc(sizeof(cList));
    pList->last = pList;

    int *ptab = NULL;
    int s;

    int max;


    scanf("%d",&max);



    pList = primes(pList,max);

    s = size(pList);
    freeall(pList,&ptab);
    show(ptab,s);
    free(ptab);
    return 0;
}