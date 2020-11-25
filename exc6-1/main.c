#include <stdio.h>
#include "lists.h"
#include "sortswap.h"
#include "stringlist.h"
int main() {
    StringList* head = (StringList*)malloc(sizeof(StringList));
    StringList* tail = (StringList*)malloc(sizeof(StringList));
    (head)->pointers.After = &tail->pointers;
    head->pointers.Before = NULL;
    tail->pointers.Before = &head->pointers;
    tail->pointers.After = NULL;
    srand(time(NULL));
    for (int i = 0; i < SIZE; ++i)
    {
        AddNewElement(&head->pointers);
    }
    Output(&head->pointers);
    QSort(&head->pointers, &tail->pointers);
    printf("\n");
    Output(&head->pointers);
    return 0;
}