#include <bits/stdc++.h>
using namespace std;
int n;
int W;

vector<int> v;
vector<int> w;
vector<vector<int>> memo;

int main() {

  scanf("%d %d", &n, &W);
  v.assign(n + 1, -1);
  w.assign(n + 1, -1);
  memo.assign(n + 1, vector<int>(n + 1, -1));

  for (int i = 1; i <= n; ++i)
    cin >> w[i] >> w[i];

  return 0;
}
