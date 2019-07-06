#include "stdafx.h"
using namespace std;
string pokemon_arr[100001];

map<string, int> pokemon;

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		char name[30];
		scanf("%s", name);
		pokemon_arr[i] = name;
		pokemon.insert(map<string, int>::value_type(pokemon_arr[i], i));
	}



	for (int i = 0; i < M; i++)
	{
		int num = 0;
		char first_Character;
		string s;
		char name[30];
		scanf("%s", name);
		s = name;


		first_Character = s[0];
		if (first_Character >= '0' && first_Character <= '9')
		{
			for (int i = 0; s[i] != 0; i++)
			{
				num *= 10;
				num += s[i] - '0';
			}
			printf("%s\n", pokemon_arr[num - 1].c_str());
		}
		else
		{
			int left = 0, right = N - 1;
			int result;
			result = pokemon[s];

			printf("%d\n", result + 1);
		}

	}
}
