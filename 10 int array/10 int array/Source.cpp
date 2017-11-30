#include<iostream>
using namespace std;
int main() {
	int array[10];
	int whatever;
	int large;
	cout << "lemme get uhhh,ten bonelessss numberss plzzzz?" << endl;
	cin >> array[0];
	cin >> array[1];
	cin >> array[2];
	cin >> array[3];
	cin >> array[4];
	cin >> array[5];
	cin >> array[6];
	cin >> array[7];
	cin >> array[8];
	cin >> array[9];
		for (int i = 0; i < 10; i++) {
			if (array[i] > 10){
				whatever = i;
			large = array[i];
	}
		}
	cout << large << "is your lasrgest num" << endl;
	cout << whatever<<"is whatver" << endl;
	system("pause");
}