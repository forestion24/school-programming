#include <iostream>
using namespace std;

int wysokosci[400010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int maxPlus = 0;

  for (int i = 0; i < n; i++) {
    cin >> wysokosci[i];
  }

  for (int i = 0; i < n; i++) {
    cout << wysokosci[i] / 2 + wysokosci[i] % 2 << " ";
  }

  for (int i = 0; i < n; i++) {
  }

  return 0;
}
