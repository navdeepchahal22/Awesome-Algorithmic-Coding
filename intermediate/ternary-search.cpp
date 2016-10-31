# include <bits/stdc++.h>

using namespace std;

double f(double x) {
  return -0.4 * x*x + 7*x + 47;
}

double ternary_search(double l, double r) {
  const double EPS = 1e-5;
  while (r - l > EPS) {
     double m1 = l + (r - l) / 3,
        m2 = r - (r - l) / 3;
     if (f (m1) < f (m2))
        l = m1;
     else
        r = m2;
  }
  return l;
}


int main() {
  double l, r;
  cin >> l >> r;

  double max_x = ternary_search(l,r);
  double max_v = f(max_x);

  cout << "Max " << max_v << " at " << max_x << " ";

  return 0;
}
