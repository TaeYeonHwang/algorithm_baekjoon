#define _CRT_SECURE_NO_WARNINGS

#if 1	//https://www.acmicpc.net/problem/2775
#include <stdio.h>

/*
a��, bȣ�� �����, (a-1)���� 1~bȣ���� ����� ���� �ո�ŭ ������� ������ ��ƾ� �Ѵ�.
k��, nȣ���� ����� ����ִ°�.
(1<=k,n<=14)
0��~, 1ȣ~, 0�� iȣ�� i��.

input : T(Test Case ��), k(��), n(ȣ)
*/

int main(void)
{
	int T, k, n;
	int arr[15][15] = { 0, };

	// �̸� ���س��� �����ؾ߰ڴ�. 
	// arr[a][b]=arr[a-1][1~b]

	// 0��.
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