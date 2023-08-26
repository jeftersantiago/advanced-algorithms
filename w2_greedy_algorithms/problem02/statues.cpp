#include <bits/stdc++.h>
using namespace std;

int main() {

  int n = 0;
  int k = 0;

  cin >> n >> k;
  vector<int> v;

  int m;
  for (int i = 0; i < n; i++) {
    cin >> m;
    v.push_back(m);
  }

  int i = 0;
  int g = 0;
  int aux = 0;

  while (i < n) {
    g++;
    // posicao de partida : mais à esquerda possivel
    aux = v[i];
    // anda ate 2*k -> distancia maxima : proximo
    // ponto à esquerda
    while (i < n && v[i] <= aux + 2 * k)
      i++;
  }
  cout << g << endl;
  return 0;
}
