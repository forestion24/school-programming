#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string ip;
  cin >> ip;

  char b1 = ip[0];
  char b2 = ip[1];
  char b3 = ip[2];

  //int o1 = (b1-'0')*100 + (b2-'0')*10 + (b3-'0');
  int o1;
  int o2;

  if (ip[2] == '.') {
    o1 = (ip[0]-'0')*10 + (ip[1]-'0');
  } else {
    o1 = (ip[0]-'0')*100 + (ip[1]-'0')*10 + (ip[2]-'0');
  }

  if (ip[6] == '.') {
    o2 = (ip[4]-'0')*10 + (ip[5]-'0');
  } else {
    o2 = (ip[4]-'0')*100 + (ip[5]-'0')*10 + (ip[6]-'0');
  }

  if (o1 < 128) {
    cout << "A" << '\n';
    if (o1 == 10) {
      cout << "PRYWATNA";
    } else {
      cout << "PUBLICZNA";
    }
 //   cout << "A" << '\n' << "PUBLICZNA";
  } else if (o1 < 192) {
    cout << "B" << '\n'; 
    if (o1 == 172 && o2 >= 16 && o2 <= 31) {
      cout << "PRYWATNA";
    } else {
      cout << "PUBLICZNA";
    }
  } else if (o1 < 224) {
    cout << "C" << '\n';
    if (o1 == 192 && o2 == 168) {
      cout << "PRYWATNA";
    } else {
      cout << "PUBLICZNA";
    }
  } else if (o1 < 240) {
    cout << "D" << '\n' << "PUBLICZNA";
  } else {
    cout << "E" << '\n' << "PUBLICZNA";
  }

  return 0;
}
