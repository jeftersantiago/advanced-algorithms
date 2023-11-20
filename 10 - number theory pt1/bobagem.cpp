#include <bits/stdc++.h>
using namespace std;

bitset<10000010> sieve;
vector<long long int> primes;

void load_sieve(int n) {
  n = n + 1;
  sieve.set();
  sieve[0] = sieve[1] = false;
  for (long long int i = 2; i < n; ++i) {
    if (sieve[i]) {
      for (long long int j = i * i; j < n; j += i)
        sieve[j] = false;
      primes.push_back(i);
    }
  }
}

long long int has_3_divisors(long long int x) {
  // odeio que 4 = 2 * 2
  if (x == 4)
    return 1;
  // se par ret 0
  if (x % 2 != 0)
    for (long long int i = 0; i < primes.size(); ++i) {
      long long int fp = primes[i];
      long long int prod = fp * fp;
      if (prod == x)
        return 1;
      // caso fp > sqrt(x)
      if (prod > x)
        break;
    }
  return 0;
}

int main() {
  // sqrt(10^12) ~ 10^6
  load_sieve(1000000);
  long long int n, x;
  cin >> n;
  while (cin >> x)
    cout << has_3_divisors(x) << "";
  return 0;
}
