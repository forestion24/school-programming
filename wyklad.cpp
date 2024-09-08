#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

std::vector<std::pair<double, double>> points;
double best_distance = 1e9;

double dst(std::pair<double, double> a, std::pair<double, double> &b) {
  return std::sqrt((a.first - b.first) * (a.first - b.first) +
                   (a.second - b.second) * (a.second - b.second));
}

double sum_distance(std::pair<double, double> a) {
  double sum = 0.0;
  for (auto &point : points) {
    sum += dst(a, point);
  }
  return sum;
}

void quad_search(int d, double xs, double xe, double ys, double ye) {
  double xm = (xs + xe) / 2.0;
  double ym = (ys + ye) / 2.0;
  best_distance = std::min(best_distance, sum_distance({xm, ym}));

  if (d == 40)
    return;

  double tr = sum_distance({(xm + xe) / 2.0, (ym + ye) / 2.0});
  double tl = sum_distance({(xs + xm) / 2.0, (ym + ye) / 2.0});
  double br = sum_distance({(xm + xe) / 2.0, (ys + ym) / 2.0});
  double bl = sum_distance({(xs + xm) / 2.0, (ys + ym) / 2.0});
  double min = std::min(std::min(tr, tl), std::min(br, bl));

  if (tr == min) {
    quad_search(d + 1, xm, xe, ym, ye);
  } else if (tl == min) {
    quad_search(d + 1, xs, xm, ym, ye);
  } else if (br == min) {
    quad_search(d + 1, xm, xe, ys, ym);
  } else {
    quad_search(d + 1, xs, xm, ys, ym);
  }
}

int main() {
  int n;
  std::cin >> n;
  double xs = 1e5, xe = -1e5, ys = 1e5, ye = -1e5;

  for (int i = 0; i < n; ++i) {
    double x, y;
    std::cin >> x >> y;
    xs = std::min(xs, x);
    xe = std::max(xe, x);
    ys = std::min(ys, y);
    ye = std::max(ye, y);
    points.push_back({x, y});
  }

  quad_search(0, xs, xe, ys, ye);

  std::cout << std::fixed << std::setprecision(10) << best_distance;
}