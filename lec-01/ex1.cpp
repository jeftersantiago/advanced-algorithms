#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

  string text;
  stack<char> st;
  cin >> text;
  int n = (int)text.size();
  if (text[0] == '(')
    st.push(text[1]);
  else {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (text[i] == ')') {
      if (st.empty()) {
        cout << "NO" << endl;
        return 0;
      }
      st.pop();
    }
    if (text[i] == '(')
      st.push(text[i]);
  }
  if (st.empty())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
