#include <bits/stdc++.h>
using namespace std;

long int m = 1e9 + 7;

long long int exp(long int x, long int n) {
  if (n == 0)
    return 1 % m;
  long long int u = exp(x, n / 2);
  u = (u * u) % m;
  if (n % 2 == 1)
    u = (u * x) % m;
  return u;
}

int main() {
  int n;
  long int a, b, c;
  a = 7;
  b = 8;
  c = 10;
  cout << exp(a, exp(b, c)) << endl;
  //  cin >> n;
  //  while (cin >> a >> b >> c)
  //    cout << exp(a, exp(b, c)) << endl;
  return 0;
}
