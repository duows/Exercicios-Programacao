#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct point {
    long long x, y;
};

long long cross_product(point a, point b, point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

long long squared_distance(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 1;

    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int p0_idx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[p0_idx].y || (points[i].y == points[p0_idx].y && points[i].x < points[p0_idx].x)) {
            p0_idx = i;
        }
    }
    rotate(points.begin(), points.begin() + p0_idx, points.end());

    if (n > 2 && cross_product(points[0], points[1], points[2]) < 0) {
        reverse(points.begin() + 1, points.end());
    }

    long long x, y;
    cin >> x >> y;
    point p = {x, y};

    if (p.x == points[0].x && p.y == points[0].y) {
        cout << "DENTRO\n";
        return 0;
    }

    auto cp1 = cross_product(points[0], points[1], p);
    auto cpn = cross_product(points[0], points[n - 1], p);

    if (cp1 < 0 || cpn > 0) {
        cout << "FORA\n";
        return 0;
    }

    if (cp1 == 0) {
        if (squared_distance(points[0], p) <= squared_distance(points[0], points[1])) {
            cout << "DENTRO\n";
        } else {
            cout << "FORA\n";
        }
        return 0;
    }
    if (cpn == 0) {
        if (squared_distance(points[0], p) <= squared_distance(points[0], points[n - 1])) {
            cout << "DENTRO\n";
        } else {
            cout << "FORA\n";
        }
        return 0;
    }

    int l = 1, r = n - 1;
    int idx = 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (cross_product(points[0], points[mid], p) >= 0) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    idx = l;

    if (cross_product(points[idx - 1], points[idx], p) >= 0) {
        cout << "DENTRO\n";
    } else {
        cout << "FORA\n";
    }

    return 0;
}