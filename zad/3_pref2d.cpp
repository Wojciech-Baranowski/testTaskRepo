#include<bits/stdc++.h>
using namespace std;

int tab[1000][1000];
int p[1000][1000];

int n;
int m;
int k;

int ax;
int ay;
int bx;
int by;

int prefixSum(int ax, int ay, int bx, int by)
{
	int sum = 0;
	for(int i = ay; i <= by; i++)
	{
		int temp = 0;
		if(ax-1 >= 0)
		{
			temp = p[i][ax-1];
		}
		sum += (p[i][bx] - temp);
	}
	return sum;
}

int main()
{
	cin >> n;
	cin >> m;
	cin >> k;
	
	for(int i = 0; i < n; i++) 
	{ 
		for(int j = 0; j < m;j++)
		{
			cin >> tab[i][j]; 
		}
	}
	
	for(int i = 0; i < n; i++) 
	{ 
		p[i][0] = tab[i][0]; 
		for(int j = 1; j < m;j++)
		{
			p[i][j] = p[i][j-1] + tab[i][j];
		}
	}
	
	for(int i = 0; i < k; i++)
	{
		cin >> ax;
		cin >> ay;
		cin >> bx;
		cin >> by;

		cout << prefixSum(ax-1,ay-1,bx-1,by-1) << "\n";
	}
	
	return 0;
}

