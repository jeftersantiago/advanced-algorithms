#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int64_t>> vvi;
typedef vector<int64_t> vi;
typedef vector<bool> vb;

int64_t t = 0;
vi d;
vi low;
/**
   passei horas debugando sei perceber que onstack nao estava sendo passada por
   referencia kkkkkkkkkk
 **/
void tarjan(const vvi &adj, const int64_t u, vvi &scc, stack<int64_t> &st, vb &onstack) {

  d[u] = low[u] = t++;
  st.push(u);
  onstack[u] = true;

  for (const int64_t v : adj[u]) {
    if (d[v] == -1) {
      tarjan(adj, v, scc, st, onstack);
      low[u] = min(low[u], low[v]);
    } else if (onstack[v])
      low[u] = min(low[u], d[v]);
  }

  if (d[u] == low[u]) {
    vi scc_aux;
    int64_t v;
    do {
      v = st.top();
      st.pop();
      onstack[v] = false;
      scc_aux.push_back(v);
    } while (v != u);
    sort(scc_aux.begin(), scc_aux.end());
    scc.push_back(scc_aux);
  }
}
vvi findSCCs(vvi &adj) {
  int n = adj.size();
  vvi sccs;

  vb onstack(n, false);
  d.assign(n, -1);
  low.assign(n, -1);

  stack<int64_t> st;
  for (int64_t u = 1; u <= n; u++) {
    if (d[u] == -1)
      tarjan(adj, u, sccs, st, onstack);
  }
  t = 0;
  sort(sccs.begin(), sccs.end());
  return sccs;
}

int main() {
  int n, m;
  cin >> n >> m;
  n++;
  vvi adj(n, vector<int64_t>());

  int64_t u, v;
  while (cin >> u >> v)
    adj[u].push_back(v);

  vvi sccs = findSCCs(adj);
  vi cmps(n, -1);
  int64_t p = 1;

  for (int64_t i = 0; i < sccs.size(); i++) {
    for (int64_t j = 0; j < sccs[i].size(); j++)
      cmps[sccs[i][j]] = p;
    p++;
  }
  cout << sccs.size() << endl;
  for (int64_t i = 1; i < cmps.size(); i++)
    cout << cmps[i] << " ";
  cout << endl;
  return 0;
}
/**
void print_graph(vvi &adj) {
  for (int64_t x = 1; x < adj.size(); x++) {
    cout << x << ": ";
    for (const auto y : adj[x])
      cout << y << " ";
    cout << endl;
  }
}
**/
