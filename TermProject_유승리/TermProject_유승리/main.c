#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#define ARRAY_LENGTH 30	// ���� �迭�� ũ�� 30���� ����


// ���� �޸𸮸� �Ҵ��ϴ� �Լ� init ����
void init()
{
	head = (Schedule*)malloc(sizeof(Schedule));
	end = (Schedule*)malloc(sizeof(Schedule));
	head->next = end;
	end->next = end;
}

// ���� ���� �Լ� ���� (stack.c)
void push(int a, int b, char str[], char str2[]);
Schedule pop();

int size;	// �迭�� ũ�⸦ ����ϴ� ����


int main(void)
{
	FILE *ifp, *ofp;
	Schedule sorting[100];

	ifp = fopen("input.txt", "r");
	if (ifp == NULL)
	{
		printf("�Է� ������ ������ �ʾҽ��ϴ�. \n");
		return 1;
	}

	ofp = fopen("output.txt", "wt");
	if (ofp == NULL)
	{
		printf("������ ������ �ʾҽ��ϴ�. \n");
		return 1;
	}

	init();

	char str[ARRAY_LENGTH], str2[ARRAY_LENGTH], str3[ARRAY_LENGTH], str4[ARRAY_LENGTH];

	// 'input.txt' ���Ͽ��� ��¥, �ð�, ����, ��Ҹ� �Է� �޾� �迭�� ������
	while (0 < fscanf(ifp, "%s%s%s%s", str, str2, str3, str4))
	{
		push(atoi(str), atoi(str2), str3, str4);
		sorting[size].date = atoi(str);
		sorting[size].time = atoi(str2);
		strcpy(sorting[size].name, str3);
		strcpy(sorting[size].place, str4);
		size++;
	}

	int i, j;
	Schedule temp;

	// ���� ������ �̿��� ��¥ �� ����
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (sorting[j].date > sorting[j + 1].date)
			{
				temp = sorting[j];
				sorting[j] = sorting[j + 1];
				sorting[j + 1] = temp;
			}
		}
	}

	// 'output.txt' ���� ���
	fprintf(ofp, "     [��¥]        [�ð�]                 [����]                      [���]\n");
	int k;
	for (k = 0; k < size; k++)
	{
		fprintf(ofp, "%10d%10d��\t%s\t\t%s\n", sorting[k].date, sorting[k].time, sorting[k].name, sorting[k].place);
	}
}