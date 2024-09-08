#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::string stack;
  std::vector<std::string> words;
  std::string op;
  int n, s = 0;

  std::cin >> n;

  words.resize(n);
  for (int i = 0; i < n; ++i)
    std::cin >> words[i];
  std::sort(words.begin(), words.end());

  for (int i = 0; i < n; ++i) {
    std::string curr = words[i];

    int first_diff = stack.size();
    for (int j = 0; j < stack.size(); ++j) {
      if (curr[j] != stack[j]) {
        first_diff = j;
        break;
      }
    }
    int to_remove = stack.size() - first_diff;
    for (int j = 0; j < to_remove; ++j) {
      op += "-";
      stack.pop_back();
      s++;
    }
    for (int j = first_diff; j < curr.size(); ++j) {
      op += curr[j];
      stack.push_back(curr[j]);
      s++;
    }
    op += "P";
    s++;
  }

  std::cout << s << "\n";
  for (int i = 0; i < s; ++i)
    std::cout << op[i] << "\n";
}
