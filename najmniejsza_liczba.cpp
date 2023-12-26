#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int tab[3];

int main() {
    int n = 3;

    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }

    sort(tab, tab+n);

/*    

    if (tab[0] == 0) {
        for (int j = 0; tab[j] != 0; j++) {
            tab[0] = tab[j], tab[j] = tab[0];
        }
    }

*/   


    if (tab[0] == 0) {
        tab[0] = tab[1], tab[1] = 0;
    }

    if (tab[0] == 0) {
        tab[0] = tab[2], tab[2] = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << tab[i];
    }

    return 0;
}