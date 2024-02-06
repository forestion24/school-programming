#include <iostream>
using namespace std;

int liczby[100];

bool czy_k_rosnaca(int k) {
  for (int i = 1; i <= 99-k; i++) {
    if (liczby[i] >= liczby[i+k]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 100; i++) {
    cin >> liczby[i];
  }

  for (int i = 1; i <= 99; i++) {
    if (czy_k_rosnaca(i)) {
      cout << i << '\n';
    }
  }

  return 0;
}
