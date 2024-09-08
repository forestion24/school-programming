#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int maxN = 500010;

vector<int> graf[maxN];
vector<int> farg[maxN];
vector<int> silniespojneskladowe[maxN];
int rozmiarysilnychspojnychskladowych[maxN];
stack<int> stak;
bool odw[maxN];
int kolor[maxN];
int tablicaGorszych[maxN];
int odwCount[maxN];

void dfs(int x) {
  odw[x] = true;
  for (int y : graf[x]) {
    if (!odw[y]) {
      dfs(y);
    }
  }
  stak.push(x);
}

void dfsKolor(int x, int k) {
  kolor[x] = k;
  rozmiarysilnychspojnychskladowych[k]++;
  for (int y : farg[x]) {
    if (kolor[y] == 0) {
      dfsKolor(y, k);
    } else if (kolor[y] != k) {
      silniespojneskladowe[kolor[y]].push_back(k);
    }
  }
}

void dfsCount(int x) {
  odwCount[x] = true;
  tablicaGorszych[x] = rozmiarysilnychspojnychskladowych[x] - 1;
  for (int y : silniespojneskladowe[x]) {
    if (!odwCount[y]) {
      dfsCount(y);
      tablicaGorszych[x] += tablicaGorszych[y] + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int prev;
    cin >> prev;

    for (int j = 1; j < n; j++) {
      int x;
      cin >> x;
      graf[prev].push_back(x);
      farg[x].push_back(prev);
      prev = x;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!odw[i]) {
      dfs(i);
    }
  }

  int color_counter = 1;
  while (!stak.empty()) {
    int x = stak.top();
    stak.pop();
    if (kolor[x] == 0) {
      dfsKolor(x, color_counter);
      color_counter++;
    }
  }

  for (int i = 1; i < color_counter; i++) {
    if (!odwCount[i]) {
      dfsCount(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << tablicaGorszych[kolor[i]] << " ";
  }

  return 0;
}
