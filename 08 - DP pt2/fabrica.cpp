#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

void print(vii v) {
  for (int i = 1; i < v.size(); ++i) {
    cout << "\t";
    for (int j = 1; j < v[i].size(); ++j)
      cout << v[i][j] << " ";
    cout << endl;
  }
}

int main() {

  int n, k;
  cin >> n >> k;

  vii v(n + 1, vi(k + 1, -1));

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= k; ++j)
      cin >> v[i][j];

  cout << "Input: " << endl;
  print(v);

  return 0;
}
