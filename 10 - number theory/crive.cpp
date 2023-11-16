#include <bits/stdc++.h>
using namespace std;
typedef long long int long_int;

bitset<100000100> sieve;
vector<long_int> primes;

void erastothenes_sieve(int n) {
  sieve[0] = sieve[1] = false;
  for (long_int i = 2; i < n; ++i) {
    if (sieve[i]) {
      for (long_int j = i * i; j < n; j += i)
        sieve[j] = false;
      primes.push_back(i);
    }
  }
}

int main() {
  long_int n = 1000000;
  for (int i = 0; i < n; ++i)
    sieve.set(i);
  erastothenes_sieve(n);

  /**
  for (long_int i = 0; i < primes.size(); ++i)
    cout << primes[i] << " ";
  cout << endl;
  **/

  while (true) {
    long_int x;
    cin >> x;

    int y = 1;
    for (long_int i = 2; i <= x; ++i)
      if (x % i == 0)
        y++;

    if (y == 3)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
