#include <bits/stdc++.h>
using namespace std;
/** pd é do caralho **/

int main() {
  int64_t n;
  cin >> n;

  vector<int64_t> v(n + 1, -1);
  for (int64_t i = 1; i <= n; i++)
    cin >> v[i];

  vector<int64_t> MEMO(n + 1, -1);

  MEMO[1] = 0;
  MEMO[2] = abs(v[2] - v[1]);
  for (int64_t i = 3; i <= n; i++)
    MEMO[i] = min(MEMO[i - 1] + abs(v[i] - v[i - 1]),
                  MEMO[i - 2] + abs(v[i] - v[i - 2]));

  cout << MEMO[n] << endl;
  return 0;
}

/**
// solucao totalmente recursiva
int solveRec(vector<int> v, int i) {

  if (i == 1)
    return 0;
  if (i == 2)
    return abs(v[2] - v[1]);

  // costs
  int c1 = solveRec(v, i - 1) + abs(v[i] - v[i - 1]);
  int c2 = solveRec(v, i - 2) + abs(v[i] - v[i - 2]);

  return min(c1, c2);
}

// pd recursiva
int solveRecPD(vector<int> v, int i) {
  if (MEMO[i] == -1)
    MEMO[i] = min(solveRecPD(v, i - 1) + abs(v[i] - v[i - 1]), solveRecPD(v, i - 2) + abs(v[i] - v[i - 2]));
  return MEMO[i];
}

// PD  iterativa
// QUE LINDO
int solvePD(vector<int> v, int n) {
  vector<int> memo(v.size(), -1);
  memo[1] = 0;
  memo[2] = abs(v[2] - v[1]);

  for (int i = 3; i < n; i++)
    memo[i] = min(memo[i - 1] + abs(v[i] - v[i - 1]),
                  memo[i - 2] + abs(v[i] - v[i - 2]));
  return memo[n - 1];
}
**/
