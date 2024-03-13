#include <iostream>
using namespace std;
int main() {
int n, m, k, pp;
int cn, cm, ck;
int tab[1000][1000], p[1001][1000], ax[1000], bx[1000], ay[1000], by[1000];
cin>>n>>m>>k;
for(cn=0;cn<n; cn++) {
    p[0][cn] = 0;
    for (cm=0; cm<m; cm++) {
        cin>>tab[cm][cn];
        p[cm+1][cn] = p[cm][cn] + tab[cm][cn];
    }
}
//printf ("Sumy prefiksowe:\n");
//for(cn=0;cn<n; cn++) {
//    printf ("\t%d", p[0][cn]);
//    for(int cm=1;cm<=m; cm++) {
//        printf ("\t%d", p[cm][cn]);
//    }
//    printf ("\n");
//}
for(ck=0; ck<k; ck++) {
    cin>>ax[ck]>>ay[ck]>>bx[ck]>>by[ck];
}
for(ck=0; ck<k; ck++) {
    pp = 0;
    for(int j=(ay[ck]-1); j<by[ck]; j++) {
        pp = pp + p[bx[ck]][j] - p[ax[ck]-1][j];
    }   
    cout<<pp<<endl;
}
return 0;
}