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
      for (long long int j = i * i; j < n; j += i) {
        sieve[j] = false;
      }
      primes.push_back(i);
    }
  }
}
int count_divisors(int x) {
  int count = 1;
  map<int, int> fats;
  for (int i = 0, fp = primes[i]; fp * fp <= x; ++i, fp = primes[i]) {
    while (x % primes[i] == 0) {
      x /= fp;
      fats[fp]++;
    }
  }
  if (x != 1) {
    fats[x] = 1;
  }
  for (auto k : fats) {
    count *= k.second + 1;
  }
  return count;
}
int main() {
  int n;
  int x;
  cin >> n;
  load_sieve(100000);

  while (n--) {
    cin >> x;
    cout << count_divisors(x) << endl;
  }

  return 0;
}
