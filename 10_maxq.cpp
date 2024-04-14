#include<bits/stdc++.h>
using namespace std;

const int N = 1000000; 

pair<int, string> tab[N]; 

struct queValues{
    int count; 
    int value; 
    string name;
}; 
deque<queValues> maxq; 

void add(int k, string s) {
    int c = 0; 
    while(!maxq.empty() && maxq.back().value <= k) {
        c += maxq.back().count + 1;
        maxq.pop_back();  
    }
    queValues q; 
    q.count = c; 
    q.value = k; 
    q.name = s; 
    maxq.push_back(q); 
}

int main() {
    int n, R_count = 0; 
    cin >> n; 
    
    for(int i = 0; i < n; i++) {
        char l; 
        cin >> l; 
            
        if (l == 'A') {
            int k; 
            string s; 
            cin >> k >> s; 
            add(k, s); 
        }
        if(l == 'D') {
            if(maxq.front().count == 0) {
				maxq.pop_front(); 
			}
			else {
				maxq.front().count--; 
			}
        }
        if(l == 'R') { 
            tab[R_count].first = maxq.front().value; 
            tab[R_count].second = maxq.front().name; 
            R_count++; 
        }    
    }
    for (int i = 0; i < R_count; i++) {
       cout << tab[i].first << " " << tab[i].second << "\n"; 
    }
    return 0;     
}
