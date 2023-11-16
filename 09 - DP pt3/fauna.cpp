#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vii;
typedef vector<int> vi;
const int INF = INT_MAX;

void print_graph(const vii adj) {
  for (int i = 1; i < adj.size(); ++i) {
    for (int j = 1; j < adj[i].size(); ++j)
      cout << adj[i][j] << " ";
    cout << endl;
  }
}

int tsp(int n, vector<vector<int>> &graph) {
  vector<vector<int>> dp(1 << n, vector<int>(n, INF));

  // Initialize base case: visiting a single city
  for (int i = 1; i < n; ++i) {
    dp[1 << i][i] = 0;
  }

  // Iterate through all subsets and cities
  for (int mask = 1; mask < (1 << n); ++mask) {
    for (int u = 1; u < n; ++u) {
      if (mask & (1 << u)) {
        for (int v = 1; v < n; ++v) {
          if (mask & (1 << v) && u != v) {
            dp[mask][u] =
                min(dp[mask][u], dp[mask ^ (1 << u)][v] + graph[v][u]);
          }
        }
      }
    }
  }

  // Compute the minimum cost of visiting all cities and returning to the
  // starting city
  int minCost = INF;
  int finalMask = (1 << n) - 1;

  for (int u = 0; u < n; ++u) {
    minCost = min(minCost, dp[finalMask][u] + graph[u][0]);
  }

  return minCost;
}

int main() {

  int n, m;
  int u, v, w;
  scanf("%d %d\n", &n, &m);
  vii adj(n + 1, vi(n + 1, 0));

  while (cin >> u >> v >> w)
    adj[u][v] = adj[v][u] = w;

  print_graph(adj);

  int x = tsp(n + 1, adj);
  cout << "Min Cost = " << x << endl;

  return 0;
}
