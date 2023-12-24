// esse era easy
#include <bits/stdc++.h>
using namespace std;
long long int solve(long long int n, long long int k) {
  long long int m = 0;
  long long int p;
  while (n != 0) {
    p = n % k;
    if (p == 0) {
      n = n / k;
      m++;
    } else {
      m += p;
      n -= p;
    }
  }
  return m;
}
int main() {
  int T;
  long long int n, k;
  cin >> T;
  while (cin >> n >> k)
    cout << solve(n, k) << endl;

  return 0;
}
