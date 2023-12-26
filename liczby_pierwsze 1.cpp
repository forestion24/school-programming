#include <iostream>
using namespace std;

bool czyPierwsza(long long n) {
    for (long long i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        } 
    }
    return true;
}

int main() {

    unsigned long long n;
    cin >> n;
    int j = 1;

    for (unsigned long long i = 0; i < n; i++) {
        if (czyPierwsza(i) == true) {
            cout << i << " " << j << endl;
            j++;
        }
    }

    return 0;
}
