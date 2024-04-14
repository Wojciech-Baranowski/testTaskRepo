#include <bits/stdc++.h>
using namespace std;
int n, k, mocarz = 0, tab[1000000];
string s, siu[1000000];
char tomasz;
struct maestro {
    int cnt;
    int z;
    string proc;
};
deque <maestro> mq;
void push(int x, string y) {
    int c = 0;
    while (!mq.empty() && mq.back().z <= x) {
        c += mq.back().cnt + 1;
        mq.pop_back();
    }
    maestro elm;
    elm.cnt = c;
    elm.z = x;
    elm.proc = y;
    mq.push_back(elm);
}
void pop() {
    if (mq.front().cnt == 0)
        mq.pop_front();
    else
        mq.front().cnt--;
}
int readz() {
    return mq.front().z;
}
string readp() {
    return mq.front().proc;
}
int main() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>tomasz;
        if (tomasz == 'A') {
            cin>>k;
            cin>>s;
            push(k, s);
        }
        if (tomasz == 'D') {
            pop();
        }
        if (tomasz == 'R') {
            tab[mocarz] = readz();
            siu[mocarz] = readp();
            mocarz++;
        }
    }
    for (int i = 0; i < mocarz; i++) {
        cout<<siu[i]<<' '<<tab[i]<<'\n';
    }
    return 0;
}