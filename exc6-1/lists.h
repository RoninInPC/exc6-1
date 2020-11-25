#pragma once
#define MAX_SIZE 20
#define SIZE 1000000
#include <stdio.h>
#include <stdlib.h>


#define OFFSET_OF(TypeName, entryName)  \
    (unsigned char*)&((TypeName*)0)->entryName

#define GET_CONTENT_RECORD(TypeName, entryName, addr)    \
    ((TypeName*)((unsigned char*)addr - OFFSET_OF(TypeName, entryName)))


struct _ListEntry {
	struct _ListEntry* After;
	struct _ListEntry* Before;
};

typedef struct _ListEntry ListEntry;

struct _StringList {
	char* string;
	int size;
	ListEntry pointers;
};
void Output(ListEntry* head);
typedef struct _StringList StringList;