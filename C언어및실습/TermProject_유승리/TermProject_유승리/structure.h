#pragma once
#include <stdio.h>
#define ARRAY_LENGTH 30

// �ڱ� ���� ����ü Schedule�� ����
struct schedule
{
	int date;   // ��¥
	int time;   // �ð�
	char name[ARRAY_LENGTH];   // ����
	char place[ARRAY_LENGTH];   // ���
	struct schedule *next;
};
typedef struct schedule Schedule;

Schedule *head, *end;
Schedule *ptr;