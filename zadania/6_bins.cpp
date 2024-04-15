#include <iostream>
using namespace std;

int t, n, m, k;
int a = 0; 
int b;

int nh(int aorb)
{
	return aorb * n + (t - aorb) * m;
}

int bin()
{
	if(b - a <= 1)
	{
		if(nh(a) >= k) return a;
		if(nh(b) >= k) return b;
		else return -1;
	}
	
	int p = (a + b) / 2;
	if(nh(p) == k) return p;
	else
	{
		if(nh(p) > k)
		{
			b = p;
			bin();
		}
		else
		{
			a = p;
			bin();
		}
	}
	return -1;
}

int main()
{
	cin >> t >> n >> m >> k;
	b = t - 1;
	if(t * m < k)
	{
		cout << "POMOC\n";
	}
	else if(t * m == k)
	{
		cout << "0\n";
	}
	else
	{
		//if(bin() == -1) cout << "POMOC\n";
		//else
		 cout << bin() << "\n";
	}
}
