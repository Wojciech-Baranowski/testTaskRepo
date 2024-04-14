#include <bits/stdc++.h>
using namespace std;

deque<pair<pair<int, string>, int>> maximums_queue;

char op;
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> op;
		if (op == 'A')
		{
			int tempI;
			string tempS;
			cin >> tempI >> tempS;
			
			int tempC = 1;
			
			if (!maximums_queue.empty())
			{
				if (tempI > maximums_queue.back().second)
				{
					for (auto it : maximums_queue)
					{
						tempC += it.second;
					}		
					maximums_queue.clear();
				}
			}	
			
			maximums_queue.push_back(make_pair(make_pair(tempI, tempS), tempC));
		}
		
		if (maximums_queue.empty())
		{
			continue;
		}
		
		if (op == 'D')
		{
			if(maximums_queue.front().second > 1)
			{
				maximums_queue.front().second -= 1;
			}
			else
			{
				maximums_queue.pop_front();
			}
		}
		if (op == 'R')
		{
			pair<pair<int, string>, int> cMax = maximums_queue.front();
			cout << cMax.first.second << " " << cMax.first.first << "\n";
		}
	}
	
	return 0;
}
