#include <iostream>

using namespace std;

// Function to compute the GCD using the Euclidean algorithm
int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Function to compute the odd shortcut
int nieparzysty_skrot(int n) {
  int m = 0;
  int mnoznik = 1;

  while (n > 0) {
    int cyfra = n % 10;   // Get the last digit
    if (cyfra % 2 == 1) { // Check if the digit is odd
      m = m + cyfra * mnoznik;
      mnoznik *= 10;
    }
    n /= 10; // Remove the last digit
  }

  return m;
}

int main() {
  int liczba;

  // Read numbers from standard input
  while (cin >> liczba) {
    int liczba_skrot = nieparzysty_skrot(liczba);

    // Check if gcd of liczba and liczba_skrot is 7
    if (gcd(liczba, liczba_skrot) == 7) {
      cout << liczba << endl;
    }
  }

  return 0;
}
