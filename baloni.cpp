#include "ballib.h"
#include <unordered_set>
#include <vector>
using namespace std;

int minimalna_liczba_rzutow() {
  int n = liczba_malpek();
  int ileRzutow = 0;

  for (int malpka = 1; malpka <= n; malpka++) {
    vector<int> balony;
    unordered_multiset<int> rzutki;

    while (true) {
      int balon = kolejny_balon(malpka);
      if (balon != -1) {
        balony.push_back(balon);
      } else {
        break;
      }
    }

    for (int i = 0; i < balony.size(); i++) {
      auto rzutka = rzutki.find(balony[i]);
      if (rzutka == rzutki.end()) {
        rzutki.insert(balony[i] - 1);
        ileRzutow++;
      } else {
        int wysRzutki = *rzutka;
        rzutki.erase(rzutka);
        rzutki.insert(wysRzutki - 1);
      }
    }
  }

  return ileRzutow;
}
