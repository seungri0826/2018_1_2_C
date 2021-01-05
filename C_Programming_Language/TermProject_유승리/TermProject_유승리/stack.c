#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "structure.h"

// ���ÿ� �����͸� push�ϴ� �Լ� 
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

// ���ÿ� ����� �����͸� pop�ϴ� �Լ�
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