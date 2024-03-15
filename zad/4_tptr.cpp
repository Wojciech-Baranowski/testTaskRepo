#include <bits/stdc++.h>
using namespace std;

int n;
int tab[1000000];

int a,b;

int sum;
int maxSum;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tab[i];
	}
	
	a = 0;
	b = 0;
	sum = tab[0];
	
	while (a < n - 1)
	{
		if (b == n)
		{
			sum -= tab[a];
			a++;
			if (maxSum < sum)
			{
				maxSum = sum;
			}
			continue;
		}
		if (sum < 0)
		{
			if (a == b)
			{
				b++;
				sum += tab[b];
			}
			sum -= tab[a];
			a++;
			if (maxSum < sum)
			{
				maxSum = sum;
			}
			continue;
		}
		if (sum >= 0)
		{
			if (b < n)
			{
				b++;
				sum += tab[b];
			}
			if (maxSum < sum)
			{
				maxSum = sum;
			}
			continue;
		}
	}
	cout << maxSum << "\n";
}
