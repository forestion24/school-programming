#include <iostream>
using namespace std;

int poziomy[100001];
bool odw[100001];

int nieDfs(int w) {
    int suma = 0;
    int i = w;

    if (odw[w]) {
        return ;
    }

    for (int i = w; !odw[i]; i = poziomy[i]) {
        odw[w] == true;
        suma += poziomy[i];
    }
    return suma;
}

int main() {
    int n;
    int wynik = 1000000000;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> poziomy[i];
    }

    for (int i = 1; i <= n; i++) {
        wynik = min(wynik, nieDfs(i));
    }

    cout << wynik;

    return 0;
}