#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> wiersze;
  string liczba;

  // Read input numbers until end of input (e.g., EOF or invalid input)
  while (cin >> liczba) {
    wiersze.push_back(liczba);
  }

  int ile_nie_ma = 0;
  int max_ktora_nie_ma = -1;

  // Process each number
  for (const auto &liczba : wiersze) {
    bool czy_moze_miec_skrot = false;

    // Check each digit in the number
    for (char cyfra : liczba) {
      if ((cyfra - '0') % 2 == 1) { // Check if digit is odd
        czy_moze_miec_skrot = true;
        break; // No need to continue checking other digits
      }
    }

    // If the number cannot have a shortcut
    if (!czy_moze_miec_skrot) {
      ile_nie_ma++;
      int liczba_int = stoi(liczba);

      // Update max_ktora_nie_ma if necessary
      if (liczba_int > max_ktora_nie_ma) {
        max_ktora_nie_ma = liczba_int;
      }
    }
  }

  // Output the results
  cout << ile_nie_ma << endl;
  cout << max_ktora_nie_ma << endl;

  return 0;
}
