#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {

	string a;
	string b;
	string sum = "";
	string result = "";

	cout << "First number  >> ";
	cin >> a;

	cout << "Second number >> ";
	cin >> b;

	int length = max(a.length(), b.length()) ;
	a = string(length - a.length(), '0') + a;
	b = string(length - b.length(), '0') + b;



	int number = (a.length() > b.length()) ? a.length() : b.length();

	int c = 0;
	for (int i = number - 1; i >= 0; i--) {

		int digit1 = a[i] - '0';
		int digit2 = b[i] - '0';

		int all = digit1 + digit2 + c;

		c = all / 10;
		sum = to_string(all % 10) + sum;
	}

	if (c) {
		sum = to_string(c) + sum;
	}

	int borrow = 0;
	for (int i = length - 1; i >= 0; i--) {


		int digit_1 = a[i] - '0';
		int digit_2 = b[i] - '0';
		
		int sub = digit_1 - digit_2 - borrow;

		
		if (sub < 0) {
			sub += 10;
			borrow = 1;
		}else {
			borrow = 0;
		}
		
		

		result = to_string(sub) + result;

	}


	result.erase(1, result.find_first_not_of('0'));
	cout << "sum           >>" <<sum << endl;

	if (a.length() >= b.length()) {
		cout << "sub           >>" << result << endl;
	}
	else
		cout << "sub           >>" << result << endl;

	return 0;
}