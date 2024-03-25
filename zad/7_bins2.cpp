#include <bits/stdc++.h>
using namespace std;

int tab[200000];
int p[200000];

int s[200000];

int n;
int k;

double sqr;

int binarySearch(int l, int u)
{
	if (u - l <= 1)
	{
		if (tab[u] <= sqr)
		{
			return u;
		}
		else if (tab[l] <= sqr)
		{
			return l;
		}
		else
		{
			return -1;
		}
	}
	
	int p = ((l - u) >> 1) + u; //(l + u) / 2
	
	if (tab[p] > sqr)
	{
		return binarySearch(l,p);
	}
	if (tab[p] <= sqr)
	{
		return binarySearch(p,u);
	}
	
	return -1;
}

int main()
{
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		cin >> tab[i];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> s[i];
	}
	
	sort(tab, tab + n);
	
	p[0] = tab[0];
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i-1] + tab[i];
	}
	
	cout << "\n";
	for (int i = 0; i < k; i++)
	{
		sqr = sqrt(s[i]);
		cout << p[binarySearch(0, n)] << " ";
	}
	
	return 0;
}
