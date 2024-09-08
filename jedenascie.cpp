#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  string liczba;
  cin >> liczba;

  char task;
  int a, b;
  for (int i = 0; i < q; i++) {
    cin >> task >> a >> b;
    if (task == '=') {
      liczba[a] = b;
    } else {
    }
  }

  return 0;
}
