#include <bits/stdc++.h>
using namespace std;
typedef long long int li;
const li mod = 1e9 + 7;

li exp(li a, li b, li mod) {
  li ans = 1;
  while (b) {
    if (b % 2 == 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  long long a, b, c;
  while (cin >> a >> b >> c)
    // fermats lil theorem -> x^n % m = x^(n % (m - 1)) % m
    cout << exp(a, exp(b, c, mod - 1), mod) << endl;
  return 0;
}
