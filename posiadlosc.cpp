#include <iostream>
using namespace std;

int main() {
    int a, b;
    int suma;
    int roznica;
    int numer;
    int wynik = 0;

    cin >> a >> b;

    for (int i = a; i < b; i++) {
        numer = i;
        while (numer > 0) {
            suma = numer % 10;
            numer /= 10;
            wynik = max(wynik, suma);
        }
        
    }

    cout << wynik;

}