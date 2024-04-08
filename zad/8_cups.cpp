#include <bits/stdc++.h>
using namespace std;

int errors[1001];

int maxIndex = 0;
int n;

string temp;

int main()
{
	for (int i = 0; i < 1001; i++)
	{
		errors[i] = 0;
	}
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		temp.erase(0,5);
		
		int index = stoi(temp) - 1000000000;
		errors[index]++;
	}
	
	for (int i = 0; i < 1001; i++)
	{
		if (errors[i] > errors[maxIndex])
		{
			maxIndex = i;
		}	
	}
	
	cout << "ERROR" << (maxIndex + 1000000000) << "\n";
	return 0;
}
