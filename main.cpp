#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class RSA {
private:
	int ciphertext;

public:
	int encrypt() {}
	string decrypt() {}
};

int main() {
	int p = 0;
	int q = 0;
	string values;
	string plaintext;
	cout << "Enter your p value and q values\n";
	getline(cin, values);
	istringstream iss(values);
	iss >> p >> q;

	cout << "Enter the string you would like to encrypt (alphabetic characters only)\n";
	getline(cin, plaintext);
	for (int i = 0; i < plaintext.size(); i++) {
		if (plaintext[i] == ' ') {
			continue;
		}
		if (!isalpha(plaintext[i])) {
			cout << "Please enter alphabetical characters only\n";
			break;
		}
	}

}