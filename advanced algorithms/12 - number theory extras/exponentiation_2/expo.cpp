#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
const li mod = 1000000007; // m = 10^9 + 7

long long exp(li a, li b) {
  long long result = 1;
  a = a % mod;

  while (b > 0) {
    if (b % 2 == 1)
      result = (result * a) % mod;

    b = b >> 1;
    a = (a * a) % mod;
  }
  return result;
}

int main() {

  int n;
  cin >> n;
  long long a, b, c;

  while (cin >> a >> b >> c)
    cout << exp(a, exp(b, c)) << endl;

  return 0;
}
