#include<bits/stdc++.h>
using namespace std;

pair<int, int> przedzialy[200002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int wyn = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> przedzialy[i].second >> przedzialy[i].first;
    }

    sort(przedzialy, przedzialy+n);

    int pom = 0;

    for (int i = 0; i < n; i++) {
        if (przedzialy[i].second >= pom) {
            pom = przedzialy[i].first;
            wyn++;
        }
    }

    cout << wyn;

    return 0;
}