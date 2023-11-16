#include <bits/stdc++.h>
using namespace std;

/**
   aprendendo bitmask

 **/
int main() {

  string str; // "ABC";
  cin >> str;
  int N = (1 << size(str));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < size(str); ++j) {
      int mask = 1 << j;
      if ((i & mask) != 0) {
        printf("%c", str[j]);
      }
    }
    cout << endl;
  }
  return 0;
}
