#include <bits/stdc++.h>
using namespace std;

deque<pair<pair<string, int>, int>> p;


void push(int value, string name)
{
	int cnt = 0;
	while(!p.empty() && p.back().first.second < value)
	{
		cnt += p.back().second + 1;
		p.pop_back();
	}
	p.push_back(make_pair(make_pair(name, value), cnt));
}

void pop()
{
	if (p.front().second == 0) p.pop_front();
	else p.front().second--;
}

pair<string, int> front()
{
	return p.front().first;
}

void drukuj()
{
	for(auto el: p) cout << el.first.first << " " << el.first.second << " " << el.second << "\n";
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		//cout << "przejscie " << i << endl;
		char t;
		cin >> t;
		if (t == 'A')
		{
			int value;
			string name;
			cin >> value >> name;
			push(value, name);
			//drukuj();
		}
		else if (t == 'R')
		{
			cout << front().first << " " << front().second << "\n";
		}
		else
		{
			pop();
		}
	}
	return 0;

}
