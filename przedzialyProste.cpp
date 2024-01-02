#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

vector<pair<int, int>> przed;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    przed.push_back({b, a});
  }

  sort(przed.begin(), przed.end());

  int najm = 2000000000;
  for (int i = 0; i < n-1; i++) {
    if (przed[i+1].second <= przed[i].first) {
      cout << 0;
      return 0;
    } else {
      najm = min(najm, przed[i+1].second-przed[i].first);
    }
  }

  cout << najm;

  return 0;
}
