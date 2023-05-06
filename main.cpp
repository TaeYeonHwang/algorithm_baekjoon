#define _CRT_SECURE_NO_WARNINGS

#if 1 //https://www.acmicpc.net/problem/10809
#include <stdio.h>

// C++ String ������,,///// 
#include <iostream>
#include <string>
//////////////////////////

using namespace std;

/*
���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S.
S<=100
a�� ó�� �����ϴ� ��ġ, b�� ó�� �����ϴ� ��ġ, c��....
�������� ������ -1.

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

	int answer[30] = { 0, };	//{-1,}�� �ȵ�. 0�� index�� -1�ǰ� �������� 0��.
	for (int i = 0; i < 30; i++)
	{
		answer[i] = -1;
	}
	// or memset(answer, -1,sizeof(answer));

	char S[101];
	scanf("%s", S);

	int idx = 0;
	while (S[idx] != '\0')	//���ڿ��� �������� '\0'�̹Ƿ� while loop�� ������ ����Ѵ�.
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
	// C������ String�� �����Ƿ� �Ʒ��� ���� char array�� �����Ͽ� �޴´�. �̶�, �������� ���� �� ���� ������ ����.
	char S[101];
	scanf("%s", S);

	int idx = 0;
	while (S[idx] != '\0')	//���ڿ��� �������� '\0'�̹Ƿ� while loop�� ������ ����Ѵ�.
	{
		printf("%c ", S[idx++]);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
#endif

#if 0
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// C++ ���� String �Է��� �̷��� �޴´�.
	string tmp_string;
	cin >> tmp_string;

	//printf("%s\n", tmp_string);		// printf�� C �Լ�. string type ��� ���� X.
	printf("%s\n", tmp_string.c_str());	// �̷��� c_str �Լ��� ���� �ȴ�.

	int str_len = tmp_string.length();	// length method�� ����ϸ� length�� ���� ���� �� ����. 
	printf("%d\n", str_len);
	/////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
}
#endif

#if 0 //https://www.acmicpc.net/problem/9461
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