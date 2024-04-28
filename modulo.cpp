#include<bits/stdc++.h>
using namespace std;

struct Mint {
	int value;
	int p; 
	 
	Mint(int x, int m) : value(x), p(m) {}
	
	int add(int a, int b) {
		return ((a % p) + (b % p)) % p;
	}
	int subtract(int a, int b) {
		return ((a % p) - (b % p) + p) % p;
	}
	int multiply(int a, int b) {
		return ((a % p) * (b % p)) % p;
	}
	int divide(int a, int b){
		return ((a % p) * reverse(b)) % p;
	}
	int power_(int a, int b) {
		if (b == 0) {
			return 1;
		}
		else if ((b % 2) == 0) {
			long long result = power_(a, b / 2);
			return (result * result) % p;
		}
		else {
			return ((a * power_(a, b - 1)) % p);
		}
	}
	int reverse(int b) {
		return power_(b, p - 2) % p; 
	}
}; 

int main() {
    return 0;
}
