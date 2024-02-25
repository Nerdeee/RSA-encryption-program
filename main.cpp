#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int modPow(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Function to generate a random prime number
int generatePrime() {
    int n, i, flag;

    while (true) {
        n = rand() % 100 + 2; // Generate a random number between 2 and 100
        flag = 0;

        for (i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            return n; // Return the prime number
        }
    }
}

// Function to calculate the greatest common divisor (gcd) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    srand(time(NULL));

    // Generate two random prime numbers
    int p = generatePrime();
    int q = generatePrime();

    // Calculate n and z
    int n = p * q;
    int z = (p - 1) * (q - 1);

    // Choose the smallest e such that it has no common factor (except 1) with z
    int e;
    for (e = 2; e < z; ++e) {
        if (gcd(e, z) == 1) {
            break;
        }
    }

    // Find the smallest d such that ed-1 is divisible by z
    int d;
    for (d = 2; d < z; ++d) {
        if ((e * d - 1) % z == 0) {
            break;
        }
    }

    // Prompt the user for a phrase
    string phrase;
    cout << "Enter an alphabetic only phrase: ";
    getline(cin, phrase);

    // Encrypt the phrase
    string encrypted;
    for (char c : phrase) {
        int m = c; // Convert character to ASCII value
        int cipher = modPow(m, e, n); // Encrypt using the public key (e, n)
        encrypted += to_string(cipher) + " ";
    }

    cout << "Encrypted cipher: " << encrypted << endl;

    // Decrypt the phrase
    string decrypted;
    istringstream iss(encrypted);
    string cipherText;
    while (iss >> cipherText) {
        int cipher = stoi(cipherText);
        int m = modPow(cipher, d, n); // Decrypt using the private key (d, n)
        char decryptedChar = m; // Convert ASCII value back to character
        decrypted += decryptedChar;
    }

    cout << "Decrypted phrase: " << decrypted << endl;


    return 0;
}
