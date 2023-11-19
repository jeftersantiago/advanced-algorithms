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


  


  return 0;
}
