#include<bits/stdc++.h>
using namespace std;

int M[1000][1000];
int P[1000][1000];
int n,m,k;

void set_P()
{
	for(int i = 0; i < n; i++)
	{
		P[i][0] = M[i][0];
		for(int j = 1; j < m; j++)
		{
			P[i][j] = P[i][j - 1] + M[i][j];
		}
	}
}

int main()
{

   cin >> n >> m >> k;
   for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> M[i][j];
        }
    }
    set_P();
    int ax, ay, bx, by; //trzeba odjac o 1
    for(int i = 0; i < k; i++)
    {
		cin >> ax >> ay >> bx >> by;
		ax--;
		ay--;
		bx--;
		by--;

		int suma = 0;
		for(int y = ay; y <= by; y++)
		{
			suma += (P[y][bx] - P[y][ax-1]);
				//cout << "x: " << P[x][m - 1] << "\n";
				//cout << "sum: " << suma << "\n";
		}
		cout << suma << "\n";

	}
   return 0;
   
}
