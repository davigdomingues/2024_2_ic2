#include <iostream>
#include <ctime>
using namespace std;

void PrefixMedia1(double X[], double A[], int n){
    double a;
    for (int i = 0; i < n; i++){
        a = 0.0;
        for (int j = 0; j <= i; j++)
                a += X[j];
        A[i] = a/(i + 1);
    }
}

void PrefixMedia2(double X[], double A[], int n){
    double s = 0.0; // soma parcial.
    for (int i = 0; i < n; i++){
        s += X[i];
        A[i] = s/(i + 1);
    }
}

int main(){
    int N, numero_Execucoes = 10;
    clock_t tempo1, tempo2, tempo3, tempo4; // variáveis do tipo tempo, em clocks.
    double tempoTotal, soma = 0.0;

    cout<<"Informe o total de elementos de interesse/tamanho do vetor: ";
    cin>>N;

    double *X = new double[N];
    double *A = new double[N];

    for (int i = 0; i < N; i++)
        X[i] = 1;

    cout<<"\n";

    cout<<"Algoritmo Prefix_media_1:"<<endl;
    for (int i = 0; i < numero_Execucoes; i++){ // medição de tempo para o algoritmo 1.
        cout<<"Execucao "<< i + 1 <<endl;
        tempo1 = clock();
        PrefixMedia1(X, A, N);
        tempo2 = clock();

        tempoTotal = difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
        soma += tempoTotal;
        cout<<"Tempo = "<<tempoTotal<<" segundos"<<endl;
        cout<<"\n";
    }
    cout<<"Tempo medio: "<<soma/numero_Execucoes<<endl;

    cout<<"\n";

    soma = 0.0;
    cout<<"Algoritmo Prefix_media_2:"<<endl;
    for (int i = 0; i < numero_Execucoes; i++){ // medição de tempo para o algoritmo 2.
        cout<<"Execucao "<< i + 1 <<endl;
        tempo3 = clock();
        PrefixMedia2(X, A, N);
        tempo4 = clock();

        tempoTotal = difftime(tempo4,tempo3)/CLOCKS_PER_SEC;
        soma += tempoTotal;
        cout<<"Tempo = "<<tempoTotal<<" segundos"<<endl;
        cout<<"\n";
    }
    cout<<"Tempo medio: "<<soma/numero_Execucoes<<endl;

    cout<<"\n";

    delete A;
    delete X;

    return 0;
}
