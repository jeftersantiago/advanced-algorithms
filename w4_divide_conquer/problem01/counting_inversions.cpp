#include <bits/stdc++.h>
using namespace std;

/* mergesort adaptado para contar as inversoes em um vetor */
void count_inversions(vector<int64_t> &v, int64_t *inversions) {

  if (v.size() == 1)
    return;

  vector<int64_t> l;
  vector<int64_t> r;

  /** Divide **/
  int64_t center = (int64_t)v.size() / 2;

  for (int64_t i = 0; i < center; i++)
    l.push_back(v[i]);

  for (int64_t j = center; j < v.size(); j++)
    r.push_back(v[j]);

  count_inversions(l, inversions);
  count_inversions(r, inversions);

  // Conquer
  int64_t i = 0;
  int64_t j = 0;

  for (int64_t k = 0; k < v.size(); k++) {
    /*
      Topo esquerdo atingiu maximo -> so adiciona no lado direito
     */
    if (i >= l.size()) {
      v[k] = r[j];
      j++;
    }
    /* Topo direito atingiu maximo -> adiciona no lado esquerdo */
    else if (j >= r.size()) {
      v[k] = l[i];
      i++;
    }
    /* Caso inicial em que nenhum atingiu maximo*/
    else if (l[i] < r[j]) {
      v[k] = l[i];
      i++;
    } else {
      /* incrementa o contador pelo numero
         de elementos restantes em l
       */
      *inversions += l.size() - i;
      v[k] = r[j];
      j++;
    }
  }
}

int main() {

  int n;
  cin >> n;
  int x;
  vector<int64_t> v;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }

  int64_t inversions = 0;
  count_inversions(v, &inversions);
  cout << inversions << endl;

  return 0;
}
