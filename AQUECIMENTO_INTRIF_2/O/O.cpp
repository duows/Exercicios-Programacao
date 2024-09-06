#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

// Fun��o para avaliar o polin�mio de quarto grau
double evaluatePolynomial(double x, const vector<double>& coeffs) {
    return coeffs[0] * pow(x, 4) + coeffs[1] * pow(x, 3) + coeffs[2] * pow(x, 2) + coeffs[3] * x + coeffs[4];
}

// Fun��o para calcular a derivada do polin�mio de quarto grau
vector<double> derivative(const vector<double>& coeffs) {
    vector<double> deriv(4);
    deriv[0] = 4 * coeffs[0];
    deriv[1] = 3 * coeffs[1];
    deriv[2] = 2 * coeffs[2];
    deriv[3] = coeffs[3];
    return deriv;
}

// Fun��o para encontrar as ra�zes de um polin�mio c�bico usando o m�todo de Newton-Raphson
vector<double> findRoots(const vector<double>& coeffs) {
    vector<double> roots;
    const double epsilon = 1e-7;
    for (double guess = -1000; guess <= 1000; guess += 1.0) {
        double x = guess;
        while (true) {
            double fx = evaluatePolynomial(x, coeffs);
            double dfx = evaluatePolynomial(x, derivative(coeffs));
            if (fabs(dfx) < epsilon) break; // evite divis�o por zero
            double new_x = x - fx / dfx;
            if (fabs(new_x - x) < epsilon) break;
            x = new_x;
        }
        if (fabs(evaluatePolynomial(x, coeffs)) < epsilon) {
            roots.push_back(x);
        }
    }
    return roots;
}

int main() {
    // Leitura dos coeficientes do polin�mio de quarto grau
    vector<double> coeffs(5);
    for (int i = 0; i < 5; ++i) {
        cin >> coeffs[i];
    }
    
    // Leitura dos intervalos de rota��o
    int P_i, P_f;
    cin >> P_i >> P_f;
    
    // Calcula a derivada do polin�mio de quarto grau
    vector<double> derivCoeffs = derivative(coeffs);
    
    // Encontra as ra�zes da derivada (pontos cr�ticos)
    vector<double> criticalPoints = findRoots(derivCoeffs);
    
    // Filtra os pontos cr�ticos que est�o dentro do intervalo [P_i, P_f]
    vector<double> validPoints;
    for (double pt : criticalPoints) {
        if (pt >= P_i && pt <= P_f) {
            validPoints.push_back(pt);
        }
    }
    
    // Ordena os pontos cr�ticos v�lidos pelo valor da fun��o original
    if (validPoints.size() < 2) {
        cout << "FALHOS" << endl;
    } else {
        sort(validPoints.begin(), validPoints.end(), [&](double a, double b) {
            return evaluatePolynomial(a, coeffs) > evaluatePolynomial(b, coeffs);
        });
        cout << fixed << setprecision(7) << validPoints[0] << endl;
        cout << fixed << setprecision(7) << validPoints[1] << endl;
    }
    
    return 0;
}

