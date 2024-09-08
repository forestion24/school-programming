#include <algorithm>
#include <complex>
#include <cstdint>
#include <iostream>

struct Cost {
  int a, b, c;

  friend bool operator<(const Cost &x, const Cost &y) {
    return std::min(x.a, std::min(x.b, x.c)) <
           std::min(y.a, std::min(y.b, y.c));
  }
};

Cost cost[16];
int64_t best_cost = 0;

void calculate_best(int64_t i, int64_t c) {
  if (c <= 300) {
    best_cost = std::max(best_cost, i);
  }
  if (i == 16)
    return;
  calculate_best(i + 1, c + cost[i].a);
  calculate_best(i + 1, c + cost[i].b);
  calculate_best(i + 1, c + cost[i].c);
}

int main() {
  for (int i = 0; i < 16; ++i) {
    std::cin >> cost[i].a >> cost[i].b >> cost[i].c;
  }

  std::sort(cost, cost + 16);

  calculate_best(0, 0);
  std::cout << best_cost;
}
