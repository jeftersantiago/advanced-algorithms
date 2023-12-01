#include <bits/stdc++.h>
using namespace std;

long long int m = 1e9 + 7;

long long int exp(long int a, long int b) {
  if (b == 0)
    return 1 % m;
  long long int u = exp(a, b / 2);
  u = (u * u) % m;
  if (b % 2 == 1)
    u = (u * a) % m;
  return u;
}

int main() {
  int n;
  long int a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%ld %ld", &a, &b);
    printf("%lld\n", exp(a, b));
  }
  return 0;
}
