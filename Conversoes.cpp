#include <iostream>
#include <string>


#define INT long long int



using namespace std;

int main()
{
    char teste = '1';
    //Convertendo de char para int
    INT val = atoi(&teste);
    
    
    //Convertendo de int pra string    
    string teste2 = to_string(val);
    
    teste2 += teste;
    
    cout << val << endl;
    cout << teste2 << endl;
    
    //Convertendo de string para int
    INT val2 = stoi(teste2);
    
    
    string teste4 = "";
    
    teste4.append(20, "abcd");
    
    
    val2 += 1000000000000;
    
    cout << teste4 << endl;
    
    cout << val2 << endl;
    
    return 0;
}

