#include <bits/stdc++.h>
using namespace std;

bool isNotOptimusPrime[1000001];
int a = 0;
int b = 0;

int maxLength = 0;
int currentLength = 0;
int currentDistance = -1;
int theDistance = 0;

void InitializePrimes()
{
	isNotOptimusPrime[1] = true;
	for  (int i = 2; i <= b; i++)
	{
		if (isNotOptimusPrime[i] == false)
		{
			for (int j = i << 1; j <= b; j += i)
			{
				isNotOptimusPrime[j] = true;
			}
		}
	}
}

int main()
{
	cin >> a;
	cin >> b;
	
	InitializePrimes();
	
	a = max(3, a);
	for (int i = a; i <= b; i++)
	{	
		theDistance++;
		if (!isNotOptimusPrime[i])
		{
			if (theDistance == currentDistance)
			{
				currentLength++;
				maxLength = max(currentLength, maxLength);
			}
			else
			{
				currentDistance = theDistance;
				currentLength = 2;
			}
			theDistance = 0;
		}
	}
	
	cout << maxLength << "\n";
	return 0;
}
