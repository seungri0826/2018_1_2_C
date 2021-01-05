#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "structure.h"

// 스택에 데이터를 push하는 함수 
void push(int a, int b, char str[], char str2[])
{
	ptr = (Schedule*)malloc(sizeof(Schedule));
	ptr->date = a;
	ptr->time = b;
	strcpy(ptr->place, str);
	strcpy(ptr->name, str2);
	ptr->next = head->next;
	head->next = ptr;
}

// 스택에 저장된 데이터를 pop하는 함수
Schedule pop()
{
	Schedule ret;
	ptr = head->next;
	head->next = head->next->next;
	ret.date = ptr->date;
	ret.time = ptr->time;
	strcpy(ret.place, ptr->place);
	strcpy(ret.name, ptr->name);
	free(ptr);
	return ret;
}