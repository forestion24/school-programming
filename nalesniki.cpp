#include <bits/stdc++.h>
using namespace std;

int nalesniki[2002];
int pankejki[2002];
int DobrePankejki[2002][2002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int suma = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> nalesniki[i];
        suma += nalesniki[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> pankejki[i];
        suma += pankejki[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                DobrePankejki[i][j] = pankejki[j] - DobrePankejki[i][j-1];
            } else if (j == 0) {
                DobrePankejki[i][j] = nalesniki[i] - DobrePankejki[i-1][j];
            } else {
                DobrePankejki[i][j] = max(nalesniki[i] - DobrePankejki[i-1][j], pankejki[j] - DobrePankejki[i][j-1]);
            }
        }
    }

    cout << suma - (suma-DobrePankejki[n][m])/2;

    return 0;
}