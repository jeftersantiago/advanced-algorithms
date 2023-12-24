#include <bits/stdc++.h>
using namespace std;

/* sorts by the ending time */
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {

  int n;
  vector<pair<int, int>> l;

  int st = -1;
  int end = -1;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> st >> end;
    l.push_back(make_pair(st, end));
  }
  // O(nlnn)
  sort(l.begin(), l.end(), compare);

  int lecs = 0;
  int aux = 0;
  for (int j = 0; j < n; j++)
    if (l[j].first >= aux) {
      aux = l[j].second;
      lecs++;
    }

  cout << lecs << endl;

  return 0;
}
