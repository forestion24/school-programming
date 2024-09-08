#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<string> input;
  vector<char> to_add;
  string curr;
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    input.push_back(temp);
  }
  sort(input.begin(), input.end());
  for (int i = 0; i < n; i++) {
    long long curr_len = input[i].size();
    long long to_remove = curr_len;
    while (to_remove != 0 && curr_len - to_remove < curr.size() &&
           curr_len - to_remove < input[i].size() &&
           curr[curr_len - to_remove] == input[i][curr_len - to_remove]) {
      to_remove--;
    }
    cout << 1 << endl;
    while (curr.size() > curr_len - to_remove) {
      curr.pop_back();
      to_add.push_back('-');
    }
    cout << 2 << endl;
    while (curr.size() < input[i].size()) {
      curr.push_back(input[i][curr.size() - 1]);
      to_add.push_back(input[i][curr.size() - 1]);
    }
    cout << 3 << endl;
    to_add.push_back('P');
  }
  cout << to_add.size();
  for (int i = 0; i < to_add.size(); i++) {
    cout << to_add[i] << "\n";
  }
}