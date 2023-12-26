#include <iostream>
#include <algorithm>
using namespace std;

int poziomy[500010];

int ileZespolow(int n) {
    int wynik = 0;
    for (int i = 0; i < n-2; i++) {
        if (poziomy[i+2]-poziomy[i+1] <= 1 && poziomy[i+2] - poziomy[i] <= 1) {
            wynik++;
            i += 2;
        }
    }
    return wynik;
}

int main () {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> poziomy[i];
    }

    sort(poziomy, poziomy+n);

    cout << ileZespolow(n);

    return 0;
}