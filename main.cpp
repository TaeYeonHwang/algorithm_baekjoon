#define _CRT_SECURE_NO_WARNINGS

#if 1	//https://www.acmicpc.net/problem/2775
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