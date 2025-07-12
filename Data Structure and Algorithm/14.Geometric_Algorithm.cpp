// Geometric Algorithms in C++

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <float.h>
using namespace std;

//----------------------------------
// Point Structure
//----------------------------------
struct Point {
    int x, y;
};

//----------------------------------
// 1. Convex Hull - Graham Scan
//----------------------------------
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

Point p0;
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return (p1.x - p0.x)*(p1.x - p0.x) + (p1.y - p0.y)*(p1.y - p0.y) <
               (p2.x - p0.x)*(p2.x - p0.x) + (p2.y - p0.y)*(p2.y - p0.y);
    return o == 2;
}

vector<Point> grahamScan(vector<Point>& points) {
    int n = points.size();
    int ymin = points[0].y, minIdx = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) || (points[i].y == ymin && points[i].x < points[minIdx].x)) {
            ymin = points[i].y;
            minIdx = i;
        }
    }
    swap(points[0], points[minIdx]);
    p0 = points[0];
    sort(points.begin() + 1, points.end(), compare);

    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    for (int i = 3; i < n; i++) {
        while (hull.size() > 1 && orientation(hull[hull.size()-2], hull.back(), points[i]) != 2)
            hull.pop_back();
        hull.push_back(points[i]);
    }
    return hull;
}

//----------------------------------
// 2. Convex Hull - Jarvis March
//----------------------------------
int leftmostPoint(vector<Point>& points) {
    int l = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].x < points[l].x)
            l = i;
    }
    return l;
}

vector<Point> jarvisMarch(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};
    vector<Point> hull;
    int l = leftmostPoint(points);
    int p = l, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;
    } while (p != l);
    return hull;
}

//----------------------------------
// 3. Line Intersection
//----------------------------------
bool onSegment(Point p, Point q, Point r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

//----------------------------------
// Main for Testing
//----------------------------------
int main() {
    vector<Point> pts = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};

    auto hullGraham = grahamScan(pts);
    cout << "Graham Scan Hull:\n";
    for (auto& p : hullGraham)
        cout << "(" << p.x << ", " << p.y << ") ";
    cout << "\n";

    auto hullJarvis = jarvisMarch(pts);
    cout << "Jarvis March Hull:\n";
    for (auto& p : hullJarvis)
        cout << "(" << p.x << ", " << p.y << ") ";
    cout << "\n";

    Point a = {1, 1}, b = {10, 1};
    Point c = {1, 2}, d = {10, 2};
    cout << "Line Intersection: " << (doIntersect(a, b, c, d) ? "Yes" : "No") << endl;

    return 0;
}
