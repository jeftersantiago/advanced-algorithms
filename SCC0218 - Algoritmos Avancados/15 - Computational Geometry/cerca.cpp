#include "geometria.h"
int main() {

  int n;
  vector<Point<long long int>> points;
  int x, y;

  double perimeter;

  cin >> n;
  while (cin >> x >> y)
    points.push_back(Point<long long int>(x, y));

  sort(points.begin(), points.end());
  int k = 0;
  vector<Point<long long int>> hull(2 * n);

  // lower hull
  for (size_t i = 0; i < n; ++i) {
    while (k >= 2 && points[i].cross(hull[k - 2], hull[k - 1]) <= 0)
      k--;
    hull[k++] = points[i];
  }
  // upper hull
  for (size_t i = n - 1, t = k + 1; i > 0; --i) {
    while (k >= t && points[i - 1].cross(hull[k - 2], hull[k - 1]) <= 0)
      k--;
    hull[k++] = points[i - 1];
  }
  hull.resize(k - 1);

  // cout << "Convex Hull: " << endl;
  // for(auto const p : hull)
  // cout << "(" << p.x << ", " << p.y << ")" << endl;
  Point<long long int> p = hull[0];
  for (int i = 1; i <= hull.size(); ++i) {
    // cout << "dist = " << p.dist(hull[i]) << endl;
    perimeter += p.dist(hull[i]);
    p = hull[i];
  }

  // cout << "perimeter = " << perimeter << endl;
  cout << fixed << setprecision(6) << perimeter;
  return 0;
}
