#include <bits/stdc++.h>
using namespace std;
int counter;

vector<int> kmp_pre_proccess(string ptr) {
  int m = ptr.size();
  vector<int> pi(m);
  int i = 0;
  int j = -1;
  pi[0] = -1;
  while (i < m) {
    while (j >= 0 && ptr[i] != ptr[j])
      j = pi[j];
    i++;
    j++;
    pi[i] = j;
  }
  return pi;
}

int kmp_search(string &text, string ptr) {
  counter = 0;
  int m = text.size();
  int n = ptr.size();
  vector<int> pi = kmp_pre_proccess(ptr);
  int i = 0;
  int j = 0;
  int pos = -1;
  while (i < m) {
    while (j >= 0 && text[i] != ptr[j])
      j = pi[j];
    i++;
    j++;
    if (j == n) {
      j = pi[j];
      pos = i - j;
      counter++;
    }
  }
  return pos;
}

int main() {

  int q;
  cin >> q;
  int t;

  string s;
  string text;

  while (cin >> t >> s) {
    if (t == 1) {
      text.append(s);
      // text.append(" ");
    } else if (t == 2) {

      vector<int> pi = kmp_pre_proccess(s);
      int begin = kmp_search(text, s) - s.size();

      cout << begin << endl;
      //      while(counter > 1){

      //        pos = kmp_search(text, s);
      //      }
    } else if (t == 3) {
      kmp_search(text, s);
      cout << counter << endl;
    }
  }
  return 0;
}
