#include <cmath>
#include <iostream>

class Point2d {
  double m_x{0}, m_y{0};

  public:
  Point2d() = default;
  Point2d(double x, double y) : m_x{x}, m_y{y} {}

  void print() {
    std::cout << "Point2d(" << (*this).m_x << ", " << this->m_y << ")"
              << std::endl;
  }
  Point2d getPoint() const { return Point2d(m_x, m_y); }

  // double distanceTo(const Point2d& o){
  //   return std::sqrt((this->m_x - o.m_x)* (m_x - o.m_x)+(m_y - o.m_y)*(m_y -
  //   o.m_y));
  // }
  friend double distanceFrom(const Point2d&, const Point2d&);
};

double distanceFrom(const Point2d& f, const Point2d& o) {
  // Point2d a = f.getPoint();
  // Point2d b = o.getPoint();

  return std::sqrt((f.m_x - o.m_x) * (f.m_x - o.m_x) +
                   (f.m_y - o.m_y) * (f.m_y - o.m_y));

  // return 0;
}
int main() {
  Point2d first{};
  Point2d second{3.0, 4.0};
  first.print();
  second.print();
  // std::cout << "Distance between two points: " << first.distanceTo(second)
  //           << std::endl;

  std::cout << "Distance between two points: " << distanceFrom(first, second)
            << '\n';
  return 0;
}
