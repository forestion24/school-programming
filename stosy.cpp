#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair <int, int> stosy[10001];

int main() {
    int n;
    pair <int, int> stos;

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> stos.first >> stos.second;
    }

    sort(stosy, stosy+n);
    int wynik = 0;
    int wynik2 = 0;

    for (int i = 1; i < n; i++) {
        if (stosy[i].first >= stosy[i-1].first && stosy[i].second >= stosy[i-1].second) {
            wynik++;
        }
        wynik2 = max(wynik, wynik2);
        wynik = 0;
    }

    cout << wynik2;

    return 0;
}