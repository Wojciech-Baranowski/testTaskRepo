#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int m;
int k;

int tasksDone(int number)
{
	return number * m + (t - number) * n;
}

int binarySearch(int l, int u)
{
	if (u - l <= 1)
	{
		if (tasksDone(l) >= k)
		{
			return l;
		}
		else if (tasksDone(u) >= k)
		{
			return u;
		}
		else
		{
			return -1; //POMOC
		}
	}
	
	int p = ((l - u) >> 1) + u; //(l + u) / 2
	
	if (tasksDone(p) >= k)
	{
		return binarySearch(l,p);
	}
	if (tasksDone(p) < k)
	{
		return binarySearch(p,u);
	}
	
	return -1;
}


int main()
{
	cin >> t >> n >> m >> k;
	
	if (t * m < k)
	{
		cout << "POMOC" << "\n";
		return 0;
	}
	
	cout << binarySearch(0, t) << "\n";
	return 0;
}
