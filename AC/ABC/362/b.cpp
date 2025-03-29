
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1, x2, x3, y1, y2, y3;

  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  int a, b, c;

  a = pow(x1 - x2, 2) + pow(y1 - y2, 2);
  b = pow(x1 - x3, 2) + pow(y1 - y3, 2);
  c = pow(x2 - x3, 2) + pow(y2 - y3, 2);

  if (a == b + c || b == a + c || c == a + b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
