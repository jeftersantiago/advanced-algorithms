#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// classical solution
// F_n > 1.6^n -> exp time
int recFib(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return recFib(n - 1) + recFib(n - 2);
}

// memo table
int pdFib(vi &f, int n) {
  if (f[n] == -1)
    f[n] = pdFib(f, n - 1) + pdFib(f, n - 2);
  return f[n];
}

// no recursion
// O(n)
int solvePD(int n) {
  vi f(n, -1);
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i <= n; i++)
    f[i] = f[i - 1] + f[i - 2];
  return f[n];
}

int solvePD_constant_space(int n) {
  int a = 0;
  int b = 1;
  int sum = 0;

  if (n == 0)
    return 0;

  for (int i = 2; i <= n; i++) {
    sum = a + b;
    a = b;
    b = sum;
  }
  return sum;
}

void calculate_fib(vi &f_pd, int n) {

  cout << "classical solve = " << recFib(n) << endl;
  cout << "PD 1 -> recursive = " << pdFib(f_pd, n) << endl;
  cout << "PD 2 -> iterative  = " << solvePD(n) << endl;
  cout << "PD 3 -> constant time = " << solvePD_constant_space(n) << endl;
}

int main() {

  int n = 8;

  vi f(n, -1);
  f[0] = 0;
  f[1] = 1;
  calculate_fib(f, n - 2);

  return 0;
}
