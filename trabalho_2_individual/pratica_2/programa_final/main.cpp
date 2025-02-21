/*
//letra a)
#include <iostream>
using namespace std;

int count = 0;

int buscaVetor(int x, int v[], int n){
    for (int i = 0; i < n; i++){
        if (x == v[i])
            count++;

        if (count == 2)
            return i;
    }
        return -1;
}

int main(){
    int n, encontrado;
    float x;

    cout<<"Informe o tamanho do vetor de interesse: ";
    cin>>n;

    int *v = new int[n];

    for (int i = 0; i < n; i++){
        cout<<"Valor "<<i + 1<<": ";
        cin>>v[i];
    }

    cout<<"Informe a chave de busca numerica para o vetor: ";
    cin>>x;

    encontrado = buscaVetor(x, v, n);

    if (encontrado > 0)
        cout<<"O numero foi encontrado pela segunda vez no vetor na posicao "<<encontrado;

    else{
        if (count == 1)
            cout<<"O numero foi encontrado apenas uma vez na estrutura do vetor";
        else
            cout<<"O numero foi encontrado nenhuma vez na estrutura do vetor";
    }

    return 0;
}
*/

//letra c)
#include <iostream>
using namespace std;

int operacoes = 0;

int buscaVetor(int x, int v[], int n){
    int count = 0;
    operacoes += 2; // count = 0 e i = 0.
    for (int i = 0; i < n; i++){
        operacoes++; //durante os casos em que i < n.
        operacoes += 2; // == e v[i], ambos de x == v[i].
        if (x == v[i]){
            count++;
            operacoes ++; //relacionado ao count.
        }

        operacoes++; //relacionado ao == de count == 2
        if (count == 2){
            operacoes++; //relacionado ao return i.
            return i;
        }

        if (i < n) //relacionado ao i++.
            operacoes++;
    }
    operacoes += 2; //relacionado ao return -1 e ao caso em que i == n.
    return -1;
}

int main(){
    int n;
    float x;

    cout<<"Informe o tamanho do vetor de interesse: ";
    cin>>n;

    int *v = new int[n];

    for (int i = 0; i < n; i++){
        cout<<"Valor "<<i + 1<<": ";
        cin>>v[i];
    }

    cout<<"Informe a chave de busca numerica para o vetor: ";
    cin>>x;

    buscaVetor(x, v, n);
    cout<<"Total de operacoes realizadas para a busca tradicional: "<<operacoes;

    return 0;
}

