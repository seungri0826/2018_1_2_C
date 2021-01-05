#pragma once
#include <stdio.h>
#define ARRAY_LENGTH 30

// 자기 참조 구조체 Schedule의 선언
struct schedule
{
	int date;   // 날짜
	int time;   // 시간
	char name[ARRAY_LENGTH];   // 설명
	char place[ARRAY_LENGTH];   // 장소
	struct schedule *next;
};
typedef struct schedule Schedule;

Schedule *head, *end;
Schedule *ptr;