#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> graf[1000001];

long long od[1000001];
long long Do[1000001];
priority_queue<pair<long long, long long>> q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long n, m, a, b, c;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    graf[a].push_back({b, c});
  }

  q.push({-1, 1});

  while (q.size()) {
    long long w = q.top().second;
    long long dl = q.top().first;
    q.pop();

    if (od[w] != 0 && Do[w] != 0) {
      continue;
    }

    if (od[w] > -dl || od[w] == 0) {
      od[w] = Do[w];
      od[w] = -dl;
      for (auto t : graf[w]) {
        q.push({(od[w] + t.second) * -1, t.first});
      }
    } else if (Do[w] > -dl or Do[w] == 0) {
      Do[w] = -dl;
      for (auto t : graf[w]) {
        q.push({(Do[w] + t.second) * -1, t.first});
      }
    }
  }

  cout << Do[n] - 1;
  return 0;
}