#include <stdio.h>
#include <malloc.h>

struct element
{
    struct element *next;
    int info;
};

struct List
{
    struct element *start;
    struct element *end;
    int size;
};

struct List *createList()
{
    struct List *aList;
    aList = malloc(sizeof(struct List));
    if (aList != NULL)
    {
        aList->size = 0;
        aList->start = NULL;
    }
    return aList;
}

int add(struct List *aList, int info)
{
    struct element *new, *previous;
        new = (struct element *) malloc(sizeof(struct element));

        if (aList->start == NULL)
        {
            aList->size = aList->size + 1;
            new->info = info;
            new->next = NULL;
            aList->start = new;
            aList->end = new;
            return (aList->size);
        }
        else
        {
            if (new == NULL)
            {
                return (printf("Error(Full)"));
            }
            else
            {
                previous = aList->end;
                new->info = info;
                new->next = NULL;
                previous->next = new;
                aList->end = new;
                aList->size = aList->size +1;
                return (aList->size);
            }
        }
}

int withdraw(struct List *aList, int valor)
{
    struct element *previous = NULL, *aux;
    int *back;
    aux = aList->start;
    while (aux != NULL)
    {
        if (aux->info == valor)
        {
            if (previous == NULL)
            {
                aList->start = aux->next;
            }
            else
            {
                previous->next = aux->next;
            }
            aList->size = aList->size - 1;
            return 1;
        }
        previous = aux;
        aux = aux->next;
    }
}

int show(struct List *aList){
    struct element *aux;
    aux = aList->start;
    while(aux != NULL)
    {
        printf("%d ",aux->info);
        aux = aux->next;
    }
    return 0;
}
