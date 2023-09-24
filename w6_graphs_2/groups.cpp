#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<vector<int>> & adj){
  for(int i = 0; i < adj.size(); i++){
    for(int j = 0; j < adj[i].size(); j++){
      printf("%d ", adj[i][j]);
    }
  }
  printf("\n");
}

int main(){
  int n, m;
  scanf("%d %d\n", &n, &m);

  vector<vector<int>> adj(n); 

  int u, v;
  for(int i=0; i< n; i++){
    scanf("%d %d\n",&u, &v);
    adj[u].push_back(v);
  }


  print_graph(adj);

  
  return 0;
}
