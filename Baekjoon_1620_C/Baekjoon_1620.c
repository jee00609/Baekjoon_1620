// Baekjoon_1620.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

typedef struct pokemon {
	int num;
	char name[21];
}pokemon;

int isInteger(char *str);
int pokemon_Search(pokemon *pokemon, char *search, int left, int right);
void quick_Sort(pokemon *pokemon, int left, int right);
int inPlacePartition(pokemon *pokemon, int left, int right, int k);

int main()
{
	int N;
	int M;

	char search[21];

	scanf("%d", &N);
	scanf("%d", &M);

	if ((N<1) || (N>100000))return 1;
	if ((M<1) || (M>100000))return 1;


	pokemon *arr_name = (pokemon*)malloc(sizeof(pokemon)*N);
	pokemon *arr_num = (pokemon*)malloc(sizeof(pokemon)*N);

	for (int i = 0; i < N; i++) {
		scanf("%s", arr_name[i].name);
		arr_name[i].num = (i + 1);

		strcpy(arr_num[i].name, arr_name[i].name);
		arr_num[i].num = (i + 1);
	}


	// 퀵 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝)
	quick_Sort(arr_name, 0, N - 1);
	printf("-------------------------------\n");
	for (int i = 0; i < N; i++) {
		printf("%d--%s(%d)\n", i, arr_name[i].name, arr_name[i].num);
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", search);

		if (isInteger(search))printf("%s\n", arr_num[atoi(search) - 1].name);//숫자일 경우 알려주는 arr_num
		else {
			printf("문자 입력\n");
			printf("%d\n", pokemon_Search(arr_name, search, 0, N - 1));
		}//문자일 경우 알려주는 arr_name

	}


	return 0;
}

int isInteger(char *str) {
	int i;

	for (i = 0; str[i]; i++) {
		if (!('0' <= str[i] && str[i] <= '9'))return 0;
		else return 1;
	}
}

int pokemon_Search(pokemon *pokemon, char *search, int left, int right) {

	//printf("%s",search);
	printf("left=%d\tright=%d\n", left, right);
	int m = (left + right) / 2;
	printf("배열의 중간 m =%d\n", m);
	printf("pokemon[%d].name=%s\n", m, pokemon[m].name);

	if (strcmp(pokemon[m].name, search) == 0) {
		printf("찾았습니다!\n");
		return pokemon[m].num;
	}
	else if (strcmp(pokemon[m].name, search) < 0) {
		printf("search가 더 클때\n");
		return pokemon_Search(pokemon, search, m + 1, right);
	}
	else if (strcmp(pokemon[m].name, search) > 0) {
		printf("pokemon[m].name이 더 클때\n");
		return pokemon_Search(pokemon, search, left, m - 1);
	}
	else {
		return 1;
	}
	return 0;
}



// 퀵 정렬
void quick_Sort(pokemon *pokemon, int left, int right) {

	printf("\n\nThis is quidk_Sort\n\n");
	int a, b;

	if (left >= right) return;

	a = b = inPlacePartition(pokemon, left, right, right);
	quick_Sort(pokemon, left, a - 1);
	quick_Sort(pokemon, b + 1, right);

}

int inPlacePartition(pokemon *po, int left, int right, int k) {
	printf("\n\nThis is inPlacePartition\n\n");
	pokemon p;
	pokemon tmp; //사용자가 입력했던 순서대로 저장할 구조체

	int i, j;

	p = po[k];
	tmp = po[k];

	//퀵정렬의 기본원소는 오른쪽
	po[k] = po[right];
	po[right] = tmp;

	i = left;
	j = right - 1;
	printf("i=%d\tj=%d\n",i,j);

	while (i <= j) {
		printf("po[%d].name=%s\tp.name=%s\n",i,po[i].name,p.name);
		while (i <= j&&(strcmp(po[i].name, p.name) <= 0)) {
			printf("<=----i=%d\tj=%d\n", i, j);
			printf("po[%d].name=%s\tp.name=%s\n", i, po[i].name, p.name);
			i++;
		}
		while (j >= i&&(strcmp(po[i].name, p.name) >= 0)) {
			printf(">=----i=%d\tj=%d\n", i, j);
			printf("po[%d].name=%s\tp.name=%s\n", i, po[i].name, p.name);
			j--;
		}
		if (i < j) {
			tmp = po[i];
			po[i] = po[j];
			po[j] = tmp;
		}
	}

	tmp = po[i];
	po[i] = po[right];
	po[right] = tmp;

	return i;
}


