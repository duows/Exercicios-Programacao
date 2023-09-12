#include <iostream>
#include <chrono>

using namespace std;
  
int fib(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibRecursive(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

class GFG {
  
public:
    int fib(int n)
    {
        int f[n + 2];
        int i;
        f[0] = 0;
        f[1] = 1;
  
        for (i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};

void multiply(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);

int fibMethod(int n)
{
    int F[2][2] = { { 1, 1 }, { 1, 0 } };
    if (n == 0)
        return 0;
    power(F, n - 1);
  
    return F[0][0];
}

void power(int F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    int M[2][2] = { { 1, 1 }, { 1, 0 } };
  
    power(F, n / 2);
    multiply(F, F);
  
    if (n % 2 != 0)
        multiply(F, M);
}
  
void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
  
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

int main() {
    GFG g;
    int n = 100000; // Ajuste o valor de n conforme necessário

    // Medição de tempo para o método GFG
    auto start_gfg = chrono::high_resolution_clock::now();
    int result_gfg = g.fib(n);
    auto end_gfg = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time_gfg = end_gfg - start_gfg;

    cout << "Resultado (GFG): " << result_gfg << endl;
    cout << "Tempo de execucao (GFG): " << elapsed_time_gfg.count() << " segundos" << endl;

    // Medição de tempo para o método iterativo
    auto start_iterative = chrono::high_resolution_clock::now();
    int result_iterative = fib(n);
    auto end_iterative = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time_iterative = end_iterative - start_iterative;

    cout << "Resultado (Iterativo): " << result_iterative << endl;
    cout << "Tempo de execucao (Iterativo): " << elapsed_time_iterative.count() << " segundos" << endl;

    // Medição de tempo para o método recursivo
    auto start_recursive = chrono::high_resolution_clock::now();
    int result_recursive = fibRecursive(n);
    auto end_recursive = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time_recursive = end_recursive - start_recursive;

    cout << "Resultado (Recursivo): " << result_recursive << endl;
    cout << "Tempo de execucao (Recursivo): " << elapsed_time_recursive.count() << " segundos" << endl;

    // Medição de tempo para o método de matriz
    auto start_matrix = chrono::high_resolution_clock::now();
    int result_matrix = fibMethod(n);
    auto end_matrix = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time_matrix = end_matrix - start_matrix;

    cout << "Resultado (Matriz): " << result_matrix << endl;
    cout << "Tempo de execucao (Matriz): " << elapsed_time_matrix.count() << " segundos" << endl;

    return 0;
}