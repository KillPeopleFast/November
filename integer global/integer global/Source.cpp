#include<iostream>
#include<ctime>
using namespace std;
int gold = 0;
void GoldDrop();
int main() {
	srand(time(NULL));
	while(1){

	cout << "you gained" << gold << endl;
	GoldDrop();
	system("PAUSE");
	}
}
void GoldDrop() {
	int x(rand() % 100);

	if (x >= 0 && x <= 30) {
		cout << "You gained 1 gold" << endl;
		gold = gold + 1;
	}

	if (x >= 31 && x <= 50) {
		cout << "You gained 5 gold" << endl;
		gold = gold + 5;
	}

	if (x >= 51 && x <= 90) {
		cout << "You gained nothing" << endl;
	}

	if (x >= 91 && x <= 100) {
		cout << "A theif appears and gains your 10 gold" << endl;
		gold = gold - 10;
	}
}