#include <iostream>
using namespace std;
int n;
int t[1000000];

int BiggestSum()
{
	int bsum = 0;
	int a = 0;
	int b = 0;
	int csum = t[0];
	while (a != n - 1)
	{
		if (b == n - 1)
		{
			a++;
			csum -= t[a-1];
		}
		else
		{
			if (csum >= 0)
			{
				b++;
				csum += t[b];
			}
			else
			{
				if (a == b)
				{
					b++;
					a++;
					csum -= t[a - 1];
					csum += t[b];
				}
				else
				{
					a++;
					csum -= t[a - 1];
				}
			}
		}
		bsum = max(bsum, csum);

	}
	return bsum;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}

	cout << BiggestSum() << "\n";
}
