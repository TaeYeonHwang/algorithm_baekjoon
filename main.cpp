#define _CRT_SECURE_NO_WARNINGS

#if 1 //https://www.acmicpc.net/problem/9461
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