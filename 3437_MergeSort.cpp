#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] >= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = leftArr[i++];
    }

    while (j < n2)
    {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main()
{
    int n;
    cin >> n;

    if (n < 1 || n > 100000)
    {
        return 0;
    }

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
        b[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] < 1 || a[i] > 1000000000)
        {
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
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

    for (int i = 0; i < k; i++)
    {
        vetor[i] = 0;
    }

    /*
    enquanto contK >= 0
        se a[cont] >= a[ultimo]
            somaFrente += a[cont]
            vetorTras[contVetor]
            cont++
        fim se
        senao
            somaFrente += a[ultimo]
            vetorTras[contVetor]
            ultimo--
        fim senao
        contVetor++
        contK--
    fim enquanto
    */

    while (contK > 0)
    {
        if (contK <= 0)
        {
            break;
        }
        if ((a[cont] + b[cont]) >= (a[ultimo] + b[ultimo]))
        {
            somaFrente += a[cont];
            vetor[contTras] = b[cont];
            cont++;
        }
        else
        {
            somaFrente += a[ultimo];
            vetor[contTras] = b[ultimo];
            ultimo--;
        }
        contTras++;
        contK--;
    }

    mergeSort(vetor, 0, k - 1);

    for (int i = 0; i < l; i++)
    {
        somaTras += vetor[i];
    }

    int soma = somaFrente + somaTras;

    cout << soma << endl;
    return 0;
}