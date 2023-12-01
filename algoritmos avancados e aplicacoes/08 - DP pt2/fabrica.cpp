#include <bits/stdc++.h>
using namespace std;
int n, k;

int main() {
  cin >> n >> k;

  vector<vector<int>> cost(n + 1, vector<int>(k + 1, 0));
  vector<vector<int>> memo(n + 1, vector<int>(k + 1, 0));

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= k; ++j)
      cin >> cost[i][j];

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= k; ++j) {
      for (int m = 1; m <= k; ++m)
        // n soma as consecutivas
        if (m != j)
          //                                          tinha iniciado memo com -1
          //                                          -> troquei pra 0
          memo[i][j] = max(memo[i][j], cost[i][m] + memo[i - 1][m]);
      // preenchendo a memo
    }
  int x = 0;
  for (int j = 1; j <= k; ++j)
    // ultima linha tem os valores preenchidos
    // encontra o maximo
    x = max(x, memo[n][j]);
  cout << x << endl;
  // cout << memo[n][k-1] << endl;
  return 0;
}
// removendo versoes recursivas
