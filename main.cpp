#define _CRT_SECURE_NO_WARNINGS

#if 1 //https://www.acmicpc.net/problem/9461
#include <stdio.h>
/*
�ĵ��� ����.
ù�ﰢ���� 1.
P(N)

<inputs>
T : Test case ����
1<=N<=100
*/

int main(void)
{
	int T, N;
	long long int P[101] = { 0, }; // int Array�� ������ �ȵǸ� long long���� �ѹ� �� �غ���. overflow�� ������ �� ����. ������� %lld

	//P(100)������ �̸� ���س��� �����ؾ� �� �� ����.
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