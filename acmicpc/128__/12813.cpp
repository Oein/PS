#include<bitset>
#include<iostream>
using namespace std;

int main() {
	const int len = 100000;
	bitset<len>b;
	bitset<len>  a;
	cin >> a >> b;
	cout <<(a & b) << '\n' << (a | b) << '\n' << (a ^ b) << '\n' << (~a) << '\n' << (~b);

}