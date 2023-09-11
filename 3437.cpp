#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    if (n < 1 || n > 100000)
    {
        return 0;
    }

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        a[i] = 0;
        b[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] < 1 || a[i] > 1000000000)
        {
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];

        if (b[i] < 1 || b[i] > 1000000000)
        {
            return 0;
        }
    }

    int k, l;

    cin >> k >> l;

    if (l < 1 || l > k || k > n)
    {
        return 0;
    }

    int somaFrente = 0;
    int somaTras = 0;

    int ultimo = n - 1;
    int cont = 0;
    int contK = k;
    int contTras = 0;

    vector<int> vetor(k);

    for (int i = 0; i < k; i++) {
        vetor[i] = 0;
    }

    while (ultimo - cont >= 0) {
        if (contK <= 0) {
            break;
        }
        if (a[cont] > a[ultimo]) {
            somaFrente += a[cont];
            vetor[contTras] = b[cont];
            cont++;
        }
        else {
            somaFrente += a[ultimo];
            vetor[contTras] = b[ultimo];
            ultimo--;
        }
        contTras++;
        contK--;
    }

    quickSort(&vetor[0], 0, k - 1);

    for (int i = 0; i < l; i++) {
        somaTras += vetor[i];
    }

    int soma = somaFrente + somaTras;

    cout << soma << endl;
    return 0;
}