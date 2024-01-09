#include <iostream>
#include <algorithm>
using namespace std;

pair <int, int> przed[50001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> przed[i].first >> przed[i].second;
  }

  sort(przed, przed+n);

  int p = przed[0].first, k = przed[0].second;
  for (int i = 1; i < n; i++) {
    if (przed[i].first <= k) {
      k = max(przed[i].second, k);
    } else {
      cout << p << " " << k << '\n';
      p = przed[i].first;
      k = przed[i].second;
    }
  }

  cout << p << " " << k;

  return 0;
}
