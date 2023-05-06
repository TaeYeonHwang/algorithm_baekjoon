#define _CRT_SECURE_NO_WARNINGS

#if 1 //https://www.acmicpc.net/problem/10809
#include <stdio.h>

// C++ String 쓰려면,,///// 
#include <iostream>
#include <string>
//////////////////////////

using namespace std;

/*
알파벳 소문자로만 이루어진 단어 S.
S<=100
a가 처음 등장하는 위치, b가 처음 등장하는 위치, c가....
등장하지 않으면 -1.

ex.
baekjoon
1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/

int main(void)
{
	// Alphaber ASCI Check. ////////////////////////////////////////////////////////////////////////
	int z_num = 'z', a_num = 'a';
	int total_num = z_num - a_num + 1;
	//printf("%d %d %d %d %d\n", 'a','z',a_num,z_num, total_num); // a : 97, z : 122, tatal_num : 25
	////////////////////////////////////////////////////////////////////////////////////////////////

	int answer[30] = { 0, };	//{-1,}은 안됨. 0번 index만 -1되고 나머지는 0임.
	for (int i = 0; i < 30; i++)
	{
		answer[i] = -1;
	}
	// or memset(answer, -1,sizeof(answer));

	char S[101];
	scanf("%s", S);

	int idx = 0;
	while (S[idx] != '\0')	//문자열의 마지막은 '\0'이므로 while loop을 돌릴때 사용한다.
	{
		int alphabet = S[idx] - 97;
		//printf("%d\n", alphabet);

		if ((answer[alphabet] == -1) && (answer[alphabet] < idx))
		{
			answer[alphabet] = idx;
		}
		idx++;
	}

	//printf("\n========= ANSEWER =============\n");

	for (int i = 0; i < total_num; i++)
	{
		printf("%d ", answer[i]);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////

#if 0
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// C에서는 String이 없으므로 아래와 같이 char array를 선언하여 받는다. 이때, 동적으로 받을 수 없는 단점이 있음.
	char S[101];
	scanf("%s", S);

	int idx = 0;
	while (S[idx] != '\0')	//문자열의 마지막은 '\0'이므로 while loop을 돌릴때 사용한다.
	{
		printf("%c ", S[idx++]);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
#endif

#if 0
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// C++ 에서 String 입력은 이렇게 받는다.
	string tmp_string;
	cin >> tmp_string;

	//printf("%s\n", tmp_string);		// printf는 C 함수. string type 출력 지원 X.
	printf("%s\n", tmp_string.c_str());	// 이렇게 c_str 함수를 쓰면 된다.

	int str_len = tmp_string.length();	// length method를 사용하면 length를 쉽게 구할 수 있음. 
	printf("%d\n", str_len);
	/////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
}
#endif

#if 0 //https://www.acmicpc.net/problem/9461
#include <stdio.h>
/*
파도반 수열.
첫삼각형은 1.
P(N)

<inputs>
T : Test case 개수
1<=N<=100
*/

int main(void)
{
	int T, N;
	long long int P[101] = { 0, }; // int Array로 했을때 안되면 long long으로 한번 더 해보자. overflow가 문제일 수 있음. 입출력은 %lld

	//P(100)까지를 미리 구해놓고 시작해야 할 것 같음.
	//P(N+1) = P(N) + P(N-4)
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;

	for (int i = 5; i <= 99; i++)
	{
		P[i + 1] = P[i] + P[i - 4];
	}

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		printf("%lld\n", P[N]);
	}
}
#endif

#if 0	//https://www.acmicpc.net/problem/2775
#include <stdio.h>

/*
a층, b호에 살려면, (a-1)층의 1~b호까지 사람들 수의 합만큼 사람들을 데려와 살아야 한다.
k층, n호에는 몇명이 살고있는가.
(1<=k,n<=14)
0층~, 1호~, 0층 i호는 i명.

input : T(Test Case 수), k(층), n(호)
*/

int main(void)
{
	int T, k, n;
	int arr[15][15] = { 0, };

	// 미리 구해놓고 시작해야겠다. 
	// arr[a][b]=arr[a-1][1~b]

	// 0층.
	for (int i = 1; i <= 14; i++)
	{
		arr[0][i] = i;
	}

	for (int a = 1; a <= 14; a++)
	{
		for (int b = 1; b <= 14; b++)
		{
			for (int c = 1; c <= b; c++)
			{
				arr[a][b] += arr[a - 1][c];
			}
			//printf("%d\n", arr[a][b]);
		}
	}

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", arr[k][n]);
	}
}
#endif