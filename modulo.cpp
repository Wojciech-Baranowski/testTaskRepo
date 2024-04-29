#include<bits/stdc++.h>

#define M 1000000007;

using namespace std;

struct Mint {
	int value;
	int p; 
	
	Mint(long long _number) {
		this->p = M;
		this->value = _number % p;
	}
	
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
		return ((a % p) * inverse(b)) % p;
	}
	int pow(int a, int b) {
		if (b == 0) {
			return 1;
		}
		else if ((b % 2) == 0) {
			long long result = pow(a, b / 2);
			return (result * result) % p;
		}
		else {
			return (((long long)a * pow(a, b - 1)) % p);
		}
	}
	int inverse(int b) {
		return pow(b, p - 2) % p;
	}
};

int main() {
    return 0;
}
