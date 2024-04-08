#include <bits/stdc++.h>
using namespace std;

int errors[1000];

int maxIndex = 0;
int n;

string temp;

int main()
{
	for (int i = 0; i < 1000; i++)
	{
		errors[i] = 0;
	}
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		
		int index = stoi(temp.substr(12, 14));
		errors[index]++;
	}
	
	for (int i = 0; i < 1000; i++)
	{
		if (errors[i] > errors[maxIndex])
		{
			maxIndex = i;
		}	
	}
	
	cout << "ERROR" << (maxIndex + 1000000000) << "\n";
	return 0;
}
