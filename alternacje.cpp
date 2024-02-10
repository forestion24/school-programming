#include <iostream>
using namespace std;

struct para{
    int dlu;
    int pWart;
};

const int liscie = 1<<18;
para drzewo[liscie*2];

void aktual(int i) {
    if (drzewo[i*2].dlu == -1) {
        drzewo[i].dlu = drzewo[i*2+1].dlu;
        drzewo[i].pWart = drzewo[i*2+1].pWart;
        return;
    }
    if (drzewo[i*2+1].dlu == -1) {
        drzewo[i].dlu = drzewo[i*2].dlu;
        drzewo[i].pWart = drzewo[i*2].pWart;
        return;
    }
    if ((drzewo[i*2].pWart + 1 + drzewo[i*2].dlu%2)%2 != drzewo[i*2+1].pWart) {
        drzewo[i].dlu = drzewo[i*2].dlu + drzewo[i*2+1].dlu;
        drzewo[i].pWart = drzewo[i*2].pWart;
    } else {
        drzewo[i].dlu = drzewo[i*2].dlu + drzewo[i*2+1].dlu - 1;
        drzewo[i].pWart = drzewo[i*2].pWart;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < liscie*2; i++) {
        drzewo[i].dlu = -1;
        drzewo[i].pWart = -1;
    }

    string a;
    cin >> a;

    for (int i = 0; i < n; i++) {
        drzewo[liscie+i].dlu = 1;
        drzewo[liscie+i].pWart = a[i]-'0';
    }

    for (int i = liscie-1; i > 0; i--) {
        aktual(i);
    }

    cout << drzewo[1].dlu << " ";

    int x;
    for (int j = 0; j < m; j++) {
        cin >> x;
        x--;
        drzewo[liscie+x].pWart = 1-drzewo[liscie+x].pWart;

        for (int i = (liscie+x)/2; i > 0; i/=2) {
            aktual(i);
        }
        cout << drzewo[1].dlu << " ";
    }

    return 0;
}