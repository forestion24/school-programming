#include <iostream>
using namespace std;


/*
6 12
12 6
6 6
0 6
6 0
*/


int NWD(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    
    while (b > 0) {
        a %= b; 
        swap(a, b);
    }
    return a;
}


int NWW(int a, int b) {
    return a*b/NWD(a, b);
}


int main(){
    int a, b;
    string operacja;

    cout << "Napisz nww lub nwd a pozniej liczby." << endl;

    cin >> operacja >> a >> b;

    if (operacja == "nwd" || operacja == "NWD"){
        cout << NWD(a, b);
    } else if (operacja == "nww" || operacja == "NWW") {
        cout << NWW(a, b);
    }
    

    return 0;
}