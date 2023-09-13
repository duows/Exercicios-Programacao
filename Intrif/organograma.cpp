#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Arv {
	
	string data;
	vector<Arv*> filhos;
	
};

void merge(vector<Arv*> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<Arv*> leftArr(n1);
    vector<Arv*> rightArr(n2);

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
        if (leftArr[i]->data.compare(rightArr[j]->data) <= 0)
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

void mergeSort(vector<Arv*> &arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}


void imprimirArv(Arv* raiz) {
	
	if (raiz == NULL) {
		return;
	}
	
	cout << raiz->data << endl;
	
	
	for (Arv* No : raiz->filhos) {
		imprimirArv(No);
	}
}

void ordenarArv(Arv* raiz) {
	
	if (raiz == NULL) {
		return;
	}

    mergeSort(raiz->filhos, 0, raiz->filhos.size()-1);
	
	for (Arv* No : raiz->filhos) {
		imprimirArv(No);
	}
}

Arv* verificaData(Arv* raiz, string data) {
	
	if (raiz == NULL) {
		
		return NULL;
		
	}

    string aux1;
    string aux2;

    for (char c : raiz->data) {
        aux1 += tolower(c);
    }
    
    for (char c : data) {
        aux2 += tolower(c);
    }

	if ( aux1 == aux2) {

		return raiz;

	}

	for ( Arv *No : raiz->filhos ) {
		
		Arv* res = verificaData(No, data);
		
		if (res != NULL) {
			return res;
		}
		
	}
	
	return NULL;
	
		
}


int main() {

	Arv* raiz = new Arv;
	
	string raizData; cin >> raizData;
	
	raiz->data = raizData;
	
	string texto;
	
	while (texto != "fim entrada") {
		
		string filho;
		string pai; 
        
        cin >> filho >> pai;

        if (filho.length() > 40 || pai.length() > 40) {
            return 0;
        }
		
		texto = filho + " " + pai;
		
		if (texto != "fim entrada") {

			Arv* NoArv = verificaData(raiz, pai);
            Arv* NoFilho = verificaData(raiz, filho);

            if (NoFilho != NULL || NoArv == NULL) {
                return 0;
            }


			Arv* NoNovo = new Arv;
			NoNovo->data = filho;
			
			NoArv->filhos.push_back(NoNovo);
            
		}
	}
	
	cin >> texto;
	
	Arv* NoArv = verificaData(raiz, texto);

	if (NoArv == NULL) {
		return 0;
	}   
	
	imprimirArv(NoArv);
	
	
	return 0;
}
