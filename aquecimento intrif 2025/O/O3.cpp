#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Usa o namespace padrão para evitar a necessidade de prefixar com "std::"
using namespace std;

// Estrutura para representar um ponto no plano cartesiano.
struct point {
    long long x, y;
};

// Calcula o produto vetorial entre os vetores (a -> b) e (a -> c).
long long cross_product(point a, point b, point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    point query_p;
    cin >> query_p.x >> query_p.y;

    long long area_sum = 0;
    for (int i = 0; i < n; ++i) {
        area_sum += (p[i].x * p[(i + 1) % n].y - p[(i + 1) % n].x * p[i].y);
    }

    if (area_sum == 0) {
        cout << "FORA" << endl;
        return 0;
    }

    if (area_sum < 0) {
        reverse(p.begin(), p.end());
    }

    bool is_strictly_inside = true;
    for (int i = 0; i < n; ++i) {
        if (cross_product(p[i], p[(i + 1) % n], query_p) <= 0) {
            is_strictly_inside = false;
            break;
        }
    }

    if (is_strictly_inside) {
        cout << "DENTRO" << endl;
    } else {
        cout << "FORA" << endl;
    }

    return 0;
}