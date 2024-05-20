#include <bits/stdc++.h>
using namespace std;

int files[1000000];

int a;
int b;

int n;
int m;
string op;

int find(int a)
{
	if (files[a] != a)
	{
		return find(files[a]);
	}
	return files[a];
}

void join_onion(int a, int b)
{
	int f = find(a);
	int s = find(b);
	
	if (a > b)
	{
		files[b] = a;
	}
	else
	{
		files[a] = b;
	}
}

bool check(int a, int b)
{
	return find(a) == find(b);
}

int main()
{
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		files[i] = i;
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> op;
		cin >> a >> b;
		if (op == "CHECK")
		{
			if (check(a, b))
			{
				cout << "TAK" << "\n";
			}
			else
			{
				cout << "NIE" << "\n";
			}
		}
		if (op == "JOIN")
		{
			join_onion(a, b);
		}
	}
	
	return 0;
}
