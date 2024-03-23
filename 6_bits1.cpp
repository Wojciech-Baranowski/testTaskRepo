#include <bits/stdc++.h>
using namespace std;
float t, n, m, k;
int main() {
    cin>>t>>n>>m>>k;
    if (k/m > t)
        cout<<"POMOC"<<endl;
    else if (k/n < t)
        cout<<'0'<<endl;
    else
        cout<<ceil((k - t*n)/(m - n))<<endl;
    return 0;
}