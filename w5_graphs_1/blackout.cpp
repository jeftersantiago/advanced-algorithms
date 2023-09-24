#include <bits/stdc++.h>
using namespace std;

typedef pair<int64_t, int64_t> PairInt;
typedef vector<vector<pair<int64_t, int64_t>>> ADJList;

void print_graph(const ADJList adjList) {
  int64_t i = 1;
  for (int64_t j = 1; j < adjList.size(); ++j) {
    cout << i << " : ";
    for (auto const y : adjList[j])
      cout << "(" << y.first << ", w = " << y.second << ") ";
    // cout << y.first << " ";
    cout << endl;
    ++i;
  }
}

struct compare_weights {
  bool operator()(const PairInt &a, const PairInt &b) const {
    return a.second > b.second;
  }
};

int64_t mst(ADJList &adj) {
  // começo da arvore é fixo msm ...
  int start = 1;

  vector<bool> visited(adj.size(), false);

  vector<PairInt> mst_builded;

  int64_t total_weight = 0;

  priority_queue<PairInt, vector<PairInt>, compare_weights> pq;

  pq.push(make_pair(start, 0));

  // Posiciona primeiro nó da mst
  mst_builded.push_back(pq.top());

  while (!pq.empty()) {

    PairInt current = pq.top();
    pq.pop();

    int64_t u = current.first;

    // pouquinho de otimizacao
    if (visited[u])
      continue;

    visited[u] = true;

    // condição fraca -> ta errada.
    if (u != start) {
      // adicionando vertices à mst
      mst_builded.push_back(current);
      total_weight += current.second;
    }

    for (const pair<int, int> &V : adj[u]) {
      int64_t v = V.first;
      int64_t w = V.second;
      if (!visited[v])
        pq.push(make_pair(v, w));
    }
  }

  // isso é o bastante para assegurar que a árvore é o grafo completo.
  if (mst_builded.size() == adj.size() - 1)
    return total_weight;
  return -1;
}
int main() {
  int64_t n, m;
  int64_t u, v, w;

  ADJList adj;

  cin >> n >> m;

  adj.assign(n + 1, vector<pair<int64_t, int64_t>>());

  while (cin >> u >> v >> w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  // print_graph(adj);

  cout << mst(adj) << endl;
  return 0;
}

// Codigo desnecessario -> quando estava fazendo por algum motivo
// pensei que precisaria checar se o grafo era conexo.

/**
typedef vector<vector<pair<int64_t, int64_t>>> ConnectedComponents;
typedef vector<pair<int64_t, int64_t>> Component;



void dfs(int64_t u, ADJList &adj, vector<bool> &visited, Component &component) {
  visited[u] = true;
  component.push_back(make_pair(u, 0));
  for (const auto &v : adj[u]) {
    int vertex = v.first;
    if (!visited[vertex])
      dfs(vertex, adj, visited, component);
  }
}
ConnectedComponents connected_components(ADJList &adj) {

  vector<bool> visited(adj.size(), false);
  ConnectedComponents components;

  for (int64_t i = 1; i < adj.size(); i++) {
    if (!visited[i]) {
      Component aux;
      dfs(i, adj, visited, aux);
      components.push_back(aux);
    }
  }
  return components;
}

**/
