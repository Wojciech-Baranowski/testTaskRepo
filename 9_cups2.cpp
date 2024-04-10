#include<bits/stdc++.h>
using namespace std;

const int T = 1001; 
set<string> cup[T]; 

bool check(string &s1, string &s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
	}
    return s1 < s2;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; 
	cin >> n; 
	
	for(int i = 0; i < n; i++) {
		int number; 
		string name;
		
		cin >> number >> name; 
		cup[number].insert(name); 
	}
	cout << "\n";
	for(int i = T - 1; i > 0; i--) {
		
		if(!cup[i].empty()) {
			string unsorted[cup[i].size()];
			int it = 0;
			
            for (auto element : cup[i]) {
                unsorted[it++] = element;
            }	
			sort(unsorted, unsorted + cup[i].size(), check); 
			
			for(int j = 0; j < cup[i].size(); j++) {
				cout << i << " " << unsorted[j] << "\n";  
			}
		}
	}
	return 0; 
}
