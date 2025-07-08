#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define lli long long int

const double TOLERANCE = 1e-7;
const int MAX_ITERATIONS = 10000;

double evaluatePolynomial(const vector<double>& coeffs, double x) {
    double result = 0;
    double power = 1;
    for (int i = coeffs.size() - 1; i >= 0; --i) {
        result += coeffs[i] * power;
        power *= x;
    }
    return result;
}

vector<double> differentiatePolynomial(const vector<double>& coeffs) {
    vector<double> derivative;
    int n = coeffs.size() - 1;
    for (int i = 0; i < n; ++i) {
        derivative.push_back((n - i) * coeffs[i]);
    }
    return derivative;
}

// Método de Newton-Raphson para encontrar uma raiz
double newtonRaphson(const std::vector<double>& coeffs, const std::vector<double>& derivativeCoeffs, double initialGuess) {
    double x = initialGuess;
    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        double fx = evaluatePolynomial(coeffs, x);
        double fpx = evaluatePolynomial(derivativeCoeffs, x);
        
        // Evitar divisão por zero
        if (fabs(fpx) < TOLERANCE) {
            return NAN; // Retorna NaN se a derivada for zero
        }
        
        double x_next = x - fx / fpx;
        
        if (fabs(x_next - x) < TOLERANCE) {
            return x_next;
        }
        
        x = x_next;
    }
    
    return NAN; 
}

vector<double> findRealRootsNewtonRaphson(const vector<double>& coeffs, double a, double b, double step = 0.1) {
    vector<double> roots;
    vector<double> derivativeCoeffs = differentiatePolynomial(coeffs);
    
    for (double x = a; x <= b; x += step) {
        double root = newtonRaphson(coeffs, derivativeCoeffs, x);
        if (!isnan(root)) {
            
            bool isDuplicate = false;
            for (double r : roots) {
                if (fabs(r - root) < TOLERANCE) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                roots.push_back(root);
            }
        }
    }
    
    return roots; 
}

int main() { _
    // Coeficientes do polinômio de quarto grau
    vector<double> coeffs(5);
    for (int i = 0; i < 5; i++) {
        cin >> coeffs[i];
    }

    long long int vi, vf; 
    cin >> vi >> vf;

    // Derivada e segunda derivada do polinômio
    vector<double> derivateCoeffs = differentiatePolynomial(coeffs);
    vector<double> secondDer = differentiatePolynomial(derivateCoeffs);
    
    vector<double> roots = findRealRootsNewtonRaphson(derivateCoeffs, vi, vf); 


    double minimum = numeric_limits<double>::lowest(), maximum = numeric_limits<double>::max();

    for (double root : roots) {
        double tendence = evaluatePolynomial(secondDer, root);

        if (tendence < 0 && minimum == numeric_limits<double>::lowest()) {
            minimum = root;
        } else if (tendence > 0 && maximum == numeric_limits<double>::max()) {
            maximum = root;
        }

        if (minimum != numeric_limits<double>::lowest() && maximum != numeric_limits<double>::max()) {
            break; 
        }
    }

    cout << fixed << setprecision(7);

    // Caso não tenha raízes ou extremos válidos
    if (roots.empty() || minimum == numeric_limits<double>::lowest() || maximum == numeric_limits<double>::max()) {
        cout << "PARAMETROS FALHOS" << endl;
    } else {
        cout << minimum << endl;
        cout << maximum << endl;
    }

    return 0;
}
