#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#define ARRAY_LENGTH 30	// 문자 배열의 크기 30으로 설정


// 동적 메모리를 할당하는 함수 init 선언
void init()
{
	head = (Schedule*)malloc(sizeof(Schedule));
	end = (Schedule*)malloc(sizeof(Schedule));
	head->next = end;
	end->next = end;
}

// 스택 관련 함수 선언 (stack.c)
void push(int a, int b, char str[], char str2[]);
Schedule pop();

int size;	// 배열의 크기를 기록하는 변수


int main(void)
{
	FILE *ifp, *ofp;
	Schedule sorting[100];

	ifp = fopen("input.txt", "r");
	if (ifp == NULL)
	{
		printf("입력 파일이 열리지 않았습니다. \n");
		return 1;
	}

	ofp = fopen("output.txt", "wt");
	if (ofp == NULL)
	{
		printf("파일이 열리지 않았습니다. \n");
		return 1;
	}

	init();

	char str[ARRAY_LENGTH], str2[ARRAY_LENGTH], str3[ARRAY_LENGTH], str4[ARRAY_LENGTH];

	// 'input.txt' 파일에서 날짜, 시간, 설명, 장소를 입력 받아 배열에 저장함
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

	// 버블 정렬을 이용한 날짜 순 정렬
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

	// 'output.txt' 파일 출력
	fprintf(ofp, "     [날짜]        [시간]                 [설명]                      [장소]\n");
	int k;
	for (k = 0; k < size; k++)
	{
		fprintf(ofp, "%10d%10d시\t%s\t\t%s\n", sorting[k].date, sorting[k].time, sorting[k].name, sorting[k].place);
	}
}