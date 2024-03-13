#include <iostream>
using namespace std;
int n, k;
int tab[1000000], p[1000001], a[1000000], b[1000000];
int main() {
cin>>n>>k;
p[0] = 0;
for(int i=0;i<n; i++) {
    cin>>tab[i];
    p[i+1] = p[i] + tab[i];
}
//printf ("Sumy prefiksowe: %d", p[0]);
//for(int i=1;i<n; i++) {
  //printf (" %d", p[i]);
//}
//printf ("\n");
for(int i=0; i<k; i++) {
    cin>>a[i]>>b[i];
}
for(int i=0; i<k; i++) {
    cout<<p[b[i]] - p[a[i]-1]<<endl;
}
return 0;
}