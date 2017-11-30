#include <iostream>
using namespace std;

int calculate(int num);

int input;
int main() {
	cout << "Give me a number" << endl;

	while (1) {
		cin >> input;

		cout << calculate(input);

	}
}

int calculate(int num) {
	if (num == 4)
		return num;
	else
		return 2 * calculate(num + 1);
}