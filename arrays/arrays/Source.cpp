#include<iostream>
using namespace std;
int main() {
	int phone[10];
	cout << "Enter your phone number girl..." << endl;
	cin >> phone[0];
	cin >> phone[1];
	cin >> phone[2];
	cin >> phone[3];
	cin >> phone[4];
	cin >> phone[5];
	cin >> phone[6];
	cin >> phone[7];
	cin >> phone[8];
	cin >> phone[9];

	for (int i = 0; i < 10; i++)
		cout << phone[i];
	cout << "Is this correct" << endl;
	system("pause");
}