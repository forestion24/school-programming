#include <iostream>
using namespace std;

int pd[1000010];

void optymalizacjaPD(int n, char x) {
    if (x == 'w') {
        for (int i = 1; i <= n; i++) {
            if (pd[i] > 1 && pd[i-1] == 0) {
                pd[i]--;
                pd[i-1]++;
            } else if (pd[i] > 1 && pd[i+1] == 0) {
                pd[i]--;
                pd[i+1]++;
            }
        }
    }

    if (x == 'm') {
        for (int i = 1; i <= n; i++) {
            if (pd[i] > 1 && pd[i+1] == 0) {
                pd[i]--;
                pd[i+1]++;
            } else if (pd[i] > 1 && pd[i-1] == 0) {
                pd[i]--;
                pd[i-1]++;
            }
        }
    }

    
}

int main() {
    int n;
    int a;
    int wynikM = 0;
    int wynikW = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pd[a+1]++;
    }

    optymalizacjaPD(n, 'm');

    for (int i = 0; i <= n; i++) {
            if (pd[i] > 0) {
                wynikM++;
            }
        }

    optymalizacjaPD(n, 'w');

    for (int i = 0; i <= n; i++) {
            if (pd[i] > 0) {
                wynikW++;
            }
        }

    cout << max(wynikM, wynikM);

    return 0;
}