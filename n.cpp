#include <iostream>

bool is_prime(int64_t num) {
  for (int64_t i = 2; i * i <= num; ++i) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int main() {
  int64_t n;
  std::cin >> n;

  if (n == 4) {
    std::cout << "2\n";
    return 0;
  }

  if (is_prime(n)) {
    std::cout << n - 1 << "\n";
  } else {
    std::cout << "0\n";
  }
}
