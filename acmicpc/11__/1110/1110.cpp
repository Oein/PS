
#include <iostream>
using namespace std;
int main()
{
	int number = 0;		//바뀐수
	int cycle = 0;	//리사이클한 횄수
	int N = 0;			//입력받을 수
	
	cin >> N;
	number = N;
	for (; cycle==0 || number != N ; cycle++) {
		int number_ten = number / 10;
		int number_one = number % 10;
		int sum = number_ten + number_one;
		int sum_ten = sum / 10;
		int sum_one = sum % 10;
		number = sum_one + (number_one * 10);
		// cout << number_ten << " + " << number_one << " = " << sum_ten << "," << sum_one << " -> " << number << endl;
	}
	cout << cycle << endl;
}









