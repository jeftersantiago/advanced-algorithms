#include <iostream>
#include <vector>

using namespace std;

int nim(vector<int> &piles) {
    int xorResult = 0;

    // Calculate the XOR of all piles
    for (int pile : piles) {
        xorResult ^= pile;
    }

    // Check if the XOR result is non-zero
    if (xorResult != 0) {
        int minAddition = 0;

        // Find the minimum addition required for each pile
        for (int pile : piles) {
            if ((pile ^ xorResult) < pile) {
                int addition = pile - (pile ^ xorResult);
                minAddition = (minAddition == 0) ? addition : min(minAddition, addition);
            }
        }

        return minAddition;
    } else {
        return 0; // Return 0 if XOR result is zero
    }
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; ++i)
      cin >> piles[i];
    cout << nim(piles) << endl;
  }

  return 0;
}
