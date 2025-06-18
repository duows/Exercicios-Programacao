#include <iostream>
#include <vector>
#include <algorithm>

// Usando o namespace std para simplificar.
using namespace std;

// Estrutura para representar um ponto no plano.
struct Point {
    long long x, y;
};

// Função que retorna:
// 0 se os pontos p, q, r são colineares
// 1 se a ordem é horária (clockwise)
// 2 se a ordem é anti-horária (counter-clockwise)
int orientation(Point p, Point q, Point r) {
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Colineares
    return (val > 0) ? 1 : 2; // Horária ou Anti-horária
}

// Função que verifica se o ponto 'q' está no segmento de reta 'pr'.
// Pré-condição: os três pontos já são colineares.
bool on_segment(Point p, Point q, Point r) {
    return (q.x >= min(p.x, r.x) && q.x <= max(p.x, r.x) &&
            q.y >= min(p.y, r.y) && q.y <= max(p.y, r.y));
}

int main() {
    // Otimiza a entrada e saída de dados.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    Point p;
    cin >> p.x >> p.y;

    // Um ponto no infinito para servir como o fim do nosso "raio".
    // Usamos um valor grande, mas seguro, para as coordenadas.
    Point extreme = {20000, p.y};

    int intersections = 0;
    for (int i = 0; i < n; i++) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];

        // Checa se o ponto 'p' está exatamente na borda do polígono.
        if (orientation(p1, p, p2) == 0 && on_segment(p1, p, p2)) {
             cout << "DENTRO" << endl;
             return 0;
        }

        // Checa se o segmento de reta do polígono (p1, p2) intersecta
        // o segmento do nosso raio (p, extreme).
        int o1 = orientation(p1, p2, p);
        int o2 = orientation(p1, p2, extreme);
        int o3 = orientation(p, extreme, p1);
        int o4 = orientation(p, extreme, p2);

        // A intersecção geral acontece se as orientações dos pares trocarem.
        if (o1 != o2 && o3 != o4) {
            intersections++;
        }
    }

    // Se o número de intersecções for ímpar, o ponto está dentro.
    if (intersections % 2 == 1) {
        cout << "DENTRO" << endl;
    } else {
        cout << "FORA" << endl;
    }

    return 0;
}