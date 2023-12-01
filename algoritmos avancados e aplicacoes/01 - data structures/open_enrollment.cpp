#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {

  // "curso", id do estudante
  unordered_map<int, int> map;
  // mantem aqui os elementos a serem removidos
  unordered_map<int, int> removed;

  int n;
  cin >> n;
  int k;
  int id;

  int j = 1;
  while (j < n + 1) {
    cin >> k;
    for (int i = 0; i < k; i++) {
      cin >> id;
      /**
         ignora re-matricula em mesmo curso
         entra se é feita matricula em outro curso. 
      **/
      if (map[id] != 0 && map[id] != j) {
        removed[id];
        map.erase(id);
      } else
        map[id] = j;
    }
    j++;
  }

  // remove de fato os elementos repetidos e/ou matriculados em 2 cursos
  for (auto const &x : removed)
    map.erase(x.first);

  // conta qtd de elementos em cada curso
  vector<int> vec(n + 1, 0);
  for (auto const &x : map) {
    vec[x.second]++;
  }

  for (int i = 1; i < n + 1; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
  return 0;
}
