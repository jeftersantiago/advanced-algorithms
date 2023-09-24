#include <bits/stdc++.h>
using namespace std;

// -> mais desafiador ate agora.

/**
   copypaste do problema das estatuas anterior
   com algumas alteracoes:

   Retorna verdadeiro se para um raio é possivel
   definir uma qtd q menor ou igual k.

 **/
bool is_valid_radious(vector<int64_t> &v, int k, int64_t r) {
  int64_t n = v.size();

  int64_t i = 0;

  /**
     qtd de "bombas"
   **/
  int64_t q = 0;

  while (i < n) {
    q++;
    int64_t next = i;

    /**
       Encontra qual a proxima posicao mais distante
       de i que é alcancada pelo raio R.
    **/
    while (next < n && v[next] - v[i] <= 2 * r)
      next++;

    /* Condicao de parada -> caso que nao da pra explodir mais estatuas com
       o raio dado.
    */
    if (i == next)
      return false;

    i = next;
  }
  /*
    Depois de percorrer todas opções possiveis .
   */
  return q <= k;
}
void find_radious(vector<int64_t> &v, int64_t &R, int64_t k) {
  /**
     Parte do maior raio possivel
     e tenta minimiza-lo se for valido
   **/
  int64_t r = v.back() - v.front();
  int64_t l = 0;
  while (l <= r) {
    /**
       inicialmente center = v.size() / 2
       checa se r = center é valido
       se sim R = center
       diminui o valor de center
       se nao reposiciona o valor l
     **/
    int64_t center = l + (r - l) / 2;

    // passo menos intuitivo de todos
    if (is_valid_radious(v, k, center)) {
      // minimiza o tamanho do raio
      r = center - 1;
      // determina o valor do raio
      R = center;
    } else
      // maximiza o valor de l
      // --> vai diminuir o valor de center
      l = center + 1;
  }
}
int main() {
  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> v;
  int64_t x;
  for (int64_t i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  int64_t r = 0;
  find_radious(v, r, k);
  cout << r << endl;

  return 0;
}
