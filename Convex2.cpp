#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool compare(Point p1, Point p2) {
    int o = orientation({0, 0}, p1, p2);
    if (o == 0)
        return (p1.x*p1.x + p1.y*p1.y) < (p2.x*p2.x + p2.y*p2.y);
    return (o == 2);
}

void convexHullGraham(Point points[], int n) {
    int minY = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < minY) || (y == minY && points[i].x < points[minIndex].x)) {
            minY = points[i].y;
            minIndex = i;
        }
    }

    swap(points[0], points[minIndex]);
    sort(points + 1, points + n, compare);

    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    for (int i = 3; i < n; i++) {
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    cout << "Convex Hull Points (Graham's Scan): ";
    for (auto p : hull) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
}

int main() {
    ifstream inputFile("points.txt");
    int n;
    inputFile >> n;

    Point points[n];
    for (int i = 0; i < n; i++) {
        inputFile >> points[i].x >> points[i].y;
    }

    convexHullGraham(points, n);

    inputFile.close();
    return 0;
}
