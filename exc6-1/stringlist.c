#include "lists.h"
void MakeStr(char* str, int size) {
    char* Alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < size; i++)
    {
        int letter = rand() % 51;
        str[i] = Alphabet[letter];
    }
    str[size] = 0;
}

StringList* Init(void) {
    StringList* tmp = (StringList*)malloc(sizeof(StringList));
    tmp->size = rand() % (MAX_SIZE - 4) + 4;
    tmp->string = (char*)malloc(tmp->size * sizeof(char));
    MakeStr(tmp->string, tmp->size);

    return tmp;
}

void AddNewElement(ListEntry* head) {
    StringList* tmp = Init();
    tmp->pointers.After = head->After;
    head->After->Before = &tmp->pointers;
    head->After = &tmp->pointers;
    tmp->pointers.Before = head;
}
void Output(ListEntry* head) {
    StringList* tmp = NULL;
    if (head == NULL || head->Before == NULL) {
        head = head->After;
    }
    while (head->After != NULL)
    {
        tmp = GET_CONTENT_RECORD(StringList, pointers, head);
        printf("%s\n", tmp->string);
        head = head->After;
    }
}