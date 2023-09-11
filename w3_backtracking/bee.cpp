#include <bits/stdc++.h>
#include <ostream>

using namespace std;

void find_subsets(vector<int> v, vector<vector<int>> &subsets, vector<int> &s,
                  int k) {
  subsets.push_back(s);

  for (int i = k; i < v.size(); i++) {
    s.push_back(v[i]);
    find_subsets(v, subsets, s, i + 1);
    s.pop_back();
  }
  return;
}

int main() {
  int n;

  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int elem;
    cin >> elem;
    v.push_back(elem);
  }

  vector<vector<int>> subsets;
  vector<int> s;
  find_subsets(v, subsets, s, 0);

  unordered_set<int> sets;

  for (auto const x : subsets) {
    int sum = 0;
    for (int i = 0; i < x.size(); i++)
      sum += x[i];
    sets.insert(sum);
  }

  cout << sets.size() - 1 << endl;
  return 0;
}
