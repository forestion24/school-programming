#include <iostream>
using namespace std;

pair <int, int> zCzegoJestZlozona(int iloraz, int a, int b) {
    for (int i = 1; max(a, b); i++) {
        for (int j = 1; j < min(a, b); j++) {
            if (i*j == iloraz) {
                return make_pair(max(i, j), min(i, j));
            }
        }
    }
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a*b < c*d) {
        cout << "NIE";
        return 0;
    }

    pair <int, int> wymiary = zCzegoJestZlozona(c*d, a, b);

    if (wymiary.first < max(a, b) && wymiary.second < min(a, b)) {
        cout << "TAK";
        return 0;
    } else {
        cout << "NIE";
    }
}