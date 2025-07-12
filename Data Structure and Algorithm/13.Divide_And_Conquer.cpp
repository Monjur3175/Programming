#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <float.h>
#include <iomanip>
using namespace std;

// -------- Closest Pair of Points --------
struct Point {
    double x, y;
};

bool compareX(Point a, Point b) { return a.x < b.x; }
bool compareY(Point a, Point b) { return a.y < b.y; }

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(vector<Point>& points, int left, int right) {
    double minDist = DBL_MAX;
    for (int i = left; i < right; ++i)
        for (int j = i + 1; j < right; ++j)
            minDist = min(minDist, dist(points[i], points[j]));
    return minDist;
}

double stripClosest(vector<Point>& strip, double d) {
    sort(strip.begin(), strip.end(), compareY);
    double minDist = d;
    for (int i = 0; i < strip.size(); ++i)
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j)
            minDist = min(minDist, dist(strip[i], strip[j]));
    return minDist;
}

double closestUtil(vector<Point>& Px, int left, int right) {
    if (right - left <= 3) return bruteForce(Px, left, right);

    int mid = (left + right) / 2;
    Point midPoint = Px[mid];

    double dl = closestUtil(Px, left, mid);
    double dr = closestUtil(Px, mid, right);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i < right; ++i)
        if (abs(Px[i].x - midPoint.x) < d)
            strip.push_back(Px[i]);

    return min(d, stripClosest(strip, d));
}

double closestPair(vector<Point>& points) {
    vector<Point> Px = points;
    sort(Px.begin(), Px.end(), compareX);
    return closestUtil(Px, 0, Px.size());
}

// -------- Strassen's Matrix Multiplication (2x2) --------
vector<vector<int>> strassen2x2(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int a = A[0][0], b = A[0][1], c = A[1][0], d = A[1][1];
    int e = B[0][0], f = B[0][1], g = B[1][0], h = B[1][1];

    int p1 = a * (f - h);
    int p2 = (a + b) * h;
    int p3 = (c + d) * e;
    int p4 = d * (g - e);
    int p5 = (a + d) * (e + h);
    int p6 = (b - d) * (g + h);
    int p7 = (a - c) * (e + f);

    return {
        {p5 + p4 - p2 + p6, p1 + p2},
        {p3 + p4, p1 + p5 - p3 - p7}
    };
}

// -------- MAIN --------
int main() {
    cout << "=== Closest Pair of Points ===\n";
    vector<Point> points = {{2.1, 3.4}, {1.0, 1.0}, {4.0, 5.0}, {3.0, 3.0}};
    double minDist = closestPair(points);
    cout << fixed << setprecision(4);
    cout << "Minimum distance: " << minDist << "\n";

    cout << "\n=== Strassen’s Matrix Multiplication (2x2) ===\n";
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    auto C = strassen2x2(A, B);
    cout << "Result matrix:\n";
    for (auto& row : C) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }

    return 0;
}
