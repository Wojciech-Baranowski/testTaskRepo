#include <bits/stdc++.h>
using namespace std;
int w=0, v=0, n, k, mocarz=0, t=0;
int main() {
    string kupa;
    cin>>n>>k;
    //printf("jolo\n");
    cin >> kupa;
    //printf("elo\n");
    while (v != n) {
        if (v - w < k) {
            if (kupa[v] == 'a' || kupa[v] == 'e' || kupa[v] == 'i' || kupa[v] == 'o' || kupa[v] == 'u' || kupa[v] == 'y') {
                //cout<<kupa[v];
                t++;
                w = v;
                v++;

            }
            else {
                v++;
                t++;
                //cout<<"to ja";
            }
        }
        else if ((kupa[v] == 'a' || kupa[v] == 'e' || kupa[v] == 'i' || kupa[v] == 'o' || kupa[v] == 'u' || kupa[v] == 'y') && (kupa[w] == 'a' || kupa[w] == 'e' || kupa[w] == 'i' || kupa[w] == 'o' || kupa[w] == 'u' || kupa[w] == 'y')) {
                //cout<<kupa[v];
                t++;
                w = v;
                v++;
                //cout<<"to ja ";
        }
        else {
            w = v;
            t = 0;
        }
        if (t > mocarz)
            mocarz = t;
        //cout<<t<<" "<<v<<" "<<w<<endl;
    }
    cout<<mocarz<<endl;
    return 0;
}