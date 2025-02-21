#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

// --------------------------------------------------------------------------------------
// prototipagem das fun��es n�o relacionadas diretamente � main():

void ordenacaoInsercaoDireta(int vetor1[], int tamanho);
void ordenacaoInsercaoBinaria(int vetor1[], int tamanho);
void ordenacaoSelecao(int vetor1[], int tamanho);
void ordenacaoBubbleSort(int vetor1[], int tamanho);
void ordenacaoHeapsort(int vetor1[], int tamanho);
void ordenacaoFusao(int vetor1[], int tamanho);
void ordenacaoQuickSort(int vetor1[], int tamanho);
// --------------------------------------------------------------------------------------

// fun��o auxiliar de cada m�todo relacionado diretamente � main():
void impressaoVetor(int vetor1[], int tamanho);

// --------------------------------------------------------------------------------------
// prototipagem das fun��es auxiliares de alguns dos processos de ordena��o supracitados:

// Heapsort:
void ordenacaoHeapsortHeapify(int vetor1[], int L, int R);

// Fus�o direta/Mergesort:
void mergePass(int A[], int tamanho, int particao, int C[]);
void processoFusao(int A[], int esquerda, int meio, int direita, int C[]);
// --------------------------------------------------------------------------------------

// QuickSort:
void aplicacaoOrdenacaoQuickSort(int A[], int esquerda, int direita);
// --------------------------------------------------------------------------------------

// vari�vel global de ordena��o (auxiliar universal):
int x;

/*vari�veis globais de contagem de total de compara��es e de movimenta��es para cada algoritmo de ordena��o:
Observa��o: essas vari�veis est�o relacionadas apenas �s chaves do vetor1*/
int totalComparacoes1 = 0, totalMovimentacoes1 = 0;
int totalComparacoes2 = 0, totalMovimentacoes2 = 0;
int totalComparacoes3 = 0, totalMovimentacoes3 = 0;
int totalComparacoes4 = 0, totalMovimentacoes4 = 0;
int totalComparacoes5 = 0, totalMovimentacoes5 = 0;
int totalComparacoes6 = 0, totalMovimentacoes6 = 0;
int totalComparacoes7 = 0, totalMovimentacoes7 = 0;

void preencherVetor(int vetor1[], int vetor2[], int tamanho) {
  for (int i = 1; i <= tamanho; i++) {
    //cout << "Valor " << i << ": ";
    //cin >> vetor1[i];
    vetor2[i] = vetor1[i];
  }
}

void impressaoVetor(int vetor1[], int tamanho) {
  cout << "[ ";
  for (int i = 1; i <= tamanho; i++)
    cout << vetor1[i] << " ";
  cout << "]" << endl;
}

void desordenarVetor(int vetor1[], int vetor2[], int tamanho) {
  for (int i = 1; i <= tamanho; i++)
    vetor1[i] = vetor2[i];
}

void insercaoDireta(int vetor1[], int tamanho) {
  clock_t t1, t2;

  t1 = clock();
  ordenacaoInsercaoDireta(vetor1, tamanho);
  t2 = clock();

  cout << endl<< "Tempo final de execucao da ordenacao por insercao direta: "<< difftime(t2, t1) / CLOCKS_PER_SEC << endl;
  cout<<"Total de comparacoes realizadas entre as chaves do vetor declarado: "<<totalComparacoes1<<endl;
  cout<<"Total de movimentacoes realizadas entre as chaves do vetor declarado: "<<totalMovimentacoes1<<endl<<endl;

  //impressaoVetor(vetor1, tamanho);
}

void insercaoBinaria(int vetor1[], int tamanho) {
  clock_t t3, t4;

  t3 = clock();
  ordenacaoInsercaoBinaria(vetor1, tamanho);
  t4 = clock();

  cout << endl<< "Tempo final de execucao da ordenacao por insercao binaria: "<< difftime(t4, t3) / CLOCKS_PER_SEC << endl;
  cout<<"Total de comparacoes realizadas entre as chaves do vetor declarado: "<<totalComparacoes2<<endl;
  cout<<"Total de movimentacoes realizadas entre as chaves do vetor declarado: "<<totalMovimentacoes2<<endl<<endl;

  //impressaoVetor(vetor1, tamanho);
}

void selecao(int vetor1[], int tamanho) {
  clock_t t5, t6;

  t5 = clock();
  ordenacaoSelecao(vetor1, tamanho);
  t6 = clock();

  cout << endl<< "Tempo final de execucao da ordenacao por selecao: "<< difftime(t6, t5) / CLOCKS_PER_SEC << endl;
  cout<<"Total de comparacoes realizadas entre as chaves do vetor declarado: "<<totalComparacoes3<<endl;
  cout<<"Total de movimentacoes realizadas entre as chaves do vetor declarado: "<<totalMovimentacoes3<<endl<<endl;

  //impressaoVetor(vetor1, tamanho);
}

void bubbleSort(int vetor1[], int tamanho) {
  clock_t t7, t8;

  t7 = clock();
  ordenacaoBubbleSort(vetor1, tamanho);
  t8 = clock();

  cout << endl<< "Tempo final de execucao da ordenacao por Bubblesort: "<< difftime(t8, t7) / CLOCKS_PER_SEC << endl;
  cout<<"Total de comparacoes realizadas entre as chaves do vetor declarado: "<<totalComparacoes4<<endl;
  cout<<"Total de movimentacoes realizadas entre as chaves do vetor declarado: "<<totalMovimentacoes4<<endl<<endl;

  //impressaoVetor(vetor1, tamanho);
}

void heapsort(int vetor1[], int tamanho){
    clock_t t9, t10;

    t9 = clock();
    ordenacaoHeapsort(vetor1, tamanho);
    t10 = clock();

    cout<<endl<<"Tempo final de execucao da ordenacao por Heapsort: "<<difftime(t10,t9)/CLOCKS_PER_SEC<<endl;
    cout<<"Total de comparacoes realizadas entre as chaves do vetor declarado: "<<totalComparacoes5<<endl;
    cout<<"Total de movimentacoes realizadas entre as chaves do vetor declarado: "<<totalMovimentacoes5<<endl<<endl;

    //impressaoVetor(vetor1, tamanho);
}

void fusao(int vetor1[], int tamanho){
    clock_t t11, t12;

    t11 = clock();
    ordenacaoFusao(vetor1, tamanho);
    t12 = clock();

    cout<<endl<<"Tempo final de execucao da ordenacao por Fusao: "<<difftime(t12,t11)/CLOCKS_PER_SEC<<endl;
    cout<<"Total de comparacoes realizadas entre as chaves do vetor declarado: "<<totalComparacoes6<<endl;
    cout<<"Total de movimentacoes realizadas entre as chaves do vetor declarado: "<<totalMovimentacoes6<<endl<<endl;

    //impressaoVetor(vetor1, tamanho);
}

void quickSort(int vetor1[], int tamanho){
    clock_t t13, t14;

    t13 = clock();
    aplicacaoOrdenacaoQuickSort(vetor1, 1, tamanho);
    t14 = clock();

    cout<<endl<<"Tempo final de execucao da ordenacao por QuickSort:"<<difftime(t14,t13)/CLOCKS_PER_SEC<<endl;
    cout<<"Total de comparacoes realizadas entre as chaves do vetor declarado: "<<totalComparacoes7<<endl;
    cout<<"Total de movimentacoes realizadas entre as chaves do vetor declarado: "<<totalMovimentacoes7<<endl<<endl;

    //impressaoVetor(vetor1, tamanho);
}

void ordenacaoInsercaoDireta(int vetor1[], int tamanho) { // ordena��o por inser��o direta
  int j; // auxiliar para a busca linear com sentinela.

  for (int i = 2; i <= tamanho; i++) {
    x = vetor1[i]; // sentinela da busca.
    vetor1[0] = x;
    totalMovimentacoes2 += 2;

    totalComparacoes1++; //j� se releva o caso em que x < vetor1[j - 1] � falso.
    for (j = i; j >= 0 && x < vetor1[j - 1]; j--){ // busca linear com sentinela.
        vetor1[j] = vetor1[j - 1];
        totalMovimentacoes1++;
    }

    vetor1[j] = x; // troca de valores do sentinela.
    totalMovimentacoes1++;
  }
}

void ordenacaoInsercaoBinaria(int vetor1[], int tamanho) { // ordena��o por inser��o bin�ria.
  int j; // representa os �ndices do vetor final ordenado.
  int R; // representa a parte direita do vetor.
  int L; // representa a parte direita do vetor.
  int m; // representa a parte direita do vetor.

  for (int i = 2; i <= tamanho; i++) {
    x = vetor1[i]; //atribui��o de um "sentinela".
    totalMovimentacoes2++;

    for (L = 1, R = i; L < R; ) { // busca bin�ria r�pida
        m = (L + R) / 2;

        totalComparacoes2++;
        if (vetor1[m] > x)
            R = m;

        else
            L = m + 1;
    }

    for (j = i; j > R; j--){
        vetor1[j] = vetor1[j - 1];
        totalMovimentacoes2++;
    }

    vetor1[R] = x; // troca de valores do "sentinela".
    totalMovimentacoes2++;
  }
}

void ordenacaoSelecao(int vetor1[], int tamanho) { // ordena��o por sele��o.
  int aux; // indica o �ndice do menor n�mero encontrado em cada itera��o.
  totalComparacoes3++;

  // busca do �ndice do menor valor de cada itera��o.
  for (int i = 1; i <= tamanho - 1; i++) {
    aux = i;

    for (int j = i + 1; j <= tamanho; j++) {
      totalComparacoes3++;
      if (vetor1[j] < vetor1[aux])
        aux = j;
    }

    // troca efetiva do valor selecionado com o menor valor encontrado.
    x = vetor1[i];
    vetor1[i] = vetor1[aux];
    vetor1[aux] = x;
    totalMovimentacoes3 += 3;
  }
}

void ordenacaoBubbleSort(int vetor1[], int tamanho) { // ordena��o por Bubblesort.
    // princ�pio da "bolha": menor valor, menor densidade, primeiros endere�os.
    int aux;
    bool deuCerto = false;
    totalComparacoes4++;

    for (int i = 2; i <= tamanho; i++) {
        for (int j = tamanho; j >= i; j--) {
            //totalComparacoes4++;
            totalMovimentacoes4 += 3;

            if (vetor1[j - 1] > vetor1[j]) { // troca efetiva dos valores de menores "densidades" no vetor.
                aux = vetor1[j - 1];
                vetor1[j - 1] = vetor1[j];
                vetor1[j] = aux;
                totalComparacoes4++;
                deuCerto = true; // uso necess�rio por conta de comportamento aleat�rio inesperado durante a execu��o.
            }
        }

        if (!deuCerto)
            totalMovimentacoes4 -= 3;
    }
}

void ordenacaoHeapsort(int vetor1[], int tamanho){ //ordena��o por Heapsort.
    int aux; // valor auxiliar para a ordena��o.
    int L; // representa a parte esquerda do vetor.
    int R; // representa a parte direita do vetor.

    for (L = tamanho/2; L >= 1; L--) //forma��o do heap, estrutura de �rvore bin�ria.
        ordenacaoHeapsortHeapify(vetor1, L, tamanho);

    for (R = tamanho; R >= 2; R--){ //aplica��o da ordena��o, a partir do princ�pio de forma��o do heap.
        //troca de posi��o do maior valor, para se "atualizar" a nova estrutura heap, desconsiderando o valor reposicionado.
        aux = vetor1[1];
        vetor1[1] = vetor1[R];
        vetor1[R] = aux;

        totalMovimentacoes5 += 3;
        ordenacaoHeapsortHeapify(vetor1, 1, R - 1); // chamada do algoritmo de ordena��o do heap, pelo processo de amontoa��o (tombamento � esquerda)
    }
}

void ordenacaoHeapsortHeapify(int vetor1[], int L, int R){
    int aux1 = L; // representa o endere�o do n� pai de cada chamada dessa fun��o.
    int aux2 = 2*L; // representa o endere�o da folha esquerda de cada chamada dessa fun��o, em rela��o ao n� pai associado.
    x = vetor1[L]; // representa o valor do n� pai de cada itera��o subsequente durante a execu��o da fun��o.
    totalMovimentacoes5++;

    totalComparacoes5++;
    if ((aux2 < R) && (vetor1[aux2] < vetor1[aux2 + 1])) //aplica��o do princ�pio de heap m�ximo.
        aux2++;

    totalComparacoes5++; // j� se releva o caso em que uma das compara��es � falsa (an�lise pregui�osa)
    while ((aux2 <= R) && (x < vetor1[aux2])){
        vetor1[aux1] = vetor1[aux2];
        totalMovimentacoes5++;
        aux1 = aux2;
        aux2 *= 2;

        totalComparacoes5 ++;
        if ((aux2 < R) && (vetor1[aux2] < vetor1[aux2 + 1])) //aplica��o do princ�pio de heap m�ximo (processo repetido para cada n� filho associado).
            aux2++;
    }

    vetor1[aux1] = x; // maior valor agora est� no endere�o do n� pai, obedecendo o princ�pio do heap m�ximo.
    totalMovimentacoes5++;
}

void ordenacaoFusao(int vetor1[], int tamanho){ // ordena��o por Fus�o direta.
    int particao = 1; // vari�vel auxiliar que delimita o escopo de combina��es do vetor a ser ordenado.

    int *A = new int[tamanho + 1];
    int *C = (int*) calloc(tamanho + 1, sizeof(int)); // vetor auxiliar da fus�o inicializado com zero em todos os endere�os.

    if (C == nullptr) // tratamento de erro, caso ocorra algum problema na execu��o do calloc.
        exit(1);

    for (int i = 1; i <= tamanho; i++)
        A[i] = vetor1[i];

    while (particao < tamanho){ // loop de chamada iterativa do processo de fus�o.
        mergePass(A, tamanho, particao, C);
        particao *= 2;
        mergePass(C, tamanho, particao, A);
        particao *= 2;
    }

    /* c�pia do vetor ordenado de volta para vetor1 --> A � o vetor ordenado final, pois na �ltima execu��o de mergePass no while,
     o vetor C � argumento para o uso do vetor A.*/
    for (int i = 1; i <= tamanho; i++)
        vetor1[i] = A[i];

    delete[] A;
    delete[] C;
}

void processoFusao(int A[], int esquerda, int meio, int direita, int C[]){ /*fus�o
de vetores "partidos":
A vai da esquerda at� meio - 1, entretanto C vai de meio at� direita.
*/
    int a = esquerda; // �ndice inicial do vetor particionado A.
    int b = meio + 1; // �ndice inicial do vetor particionado C.
    int k = esquerda - 1; //�ndice de aux�lio para preenchimento do vetor resultante da fus�o.
    totalComparacoes6++;

    while (a <= meio && b <= direita){ //comparador intra-vetores.
        k++;


        if (A[a] < A[b]){
            C[k] = A[a];
            totalComparacoes6++;
            totalMovimentacoes6++;
            a++;
        }

        else{
            C[k] = A[b];
            totalComparacoes6++;
            totalMovimentacoes6++;
            b++;
        }
    }

    while (a <= meio){ /*preenchimento do restante do vetor final,
        caso A.length > C.length.*/
        k++;
        C[k] = A[a];
        totalMovimentacoes6++;
        a++;
    }

    while (b <= direita){ /*preenchimento do restante do vetor final,
    caso A.length < C.length.*/
        k++;
        C[k] = A[b];
        totalMovimentacoes6++;
        b++;
    }
}

void mergePass(int A[], int tamanho, int particao, int C[]){ /* garante a passage de refer�ncia para o processo de fus�o, ou seja,
delimita o intervalo a ser fundido e ordenado, considerando os devidos valores de parti��o a cada chamada do m�todo na ordena��o*/
    int aux = 1; // �ndice para o endere�o auxiliar a ser modificado durante a ordena��o.

    while (aux < tamanho - 2*particao + 1){ // garantia de que o comprimento considerado � m�ltiplo de pot�ncia de 2.
        processoFusao(A, aux, aux + particao - 1, aux + 2*particao - 1, C);
        aux += 2*particao;
    }

    if (aux + particao - 1 < tamanho) /* eventual processo de fus�o, caso o valor do meio ap�s o while ainda ser menor do que o tamanho do vetor A
    (ou C, dependendo do caso).*/
        processoFusao(A, aux, aux + particao - 1, tamanho, C);

    else{
        for (int j = aux; j <= tamanho; j++){ /* passagem efetiva dos valores ordenados de cada chamada de mergePass, considerando o valor de parti��o
         de cada chamada da fun��o mergePass em ordena��oFusao*/
            C[j] = A[j];
            totalMovimentacoes6++;
        }
    }
}

void aplicacaoOrdenacaoQuickSort(int vetor1[], int esquerda, int direita){ //ordena��o por QuickSort.
    int i = esquerda; // delimita��o do endere�o � esquerda de cada chamada da fun��o.
    int j = direita; // delimita��o do endere�o � direita de cada chamada da fun��o.
    int aux; // vari�vel auxiliar para a troca dos valores dos devidos endere�os de troca.
    x = vetor1[(esquerda + direita)/2]; // vari�vel auxiliar para compara��o das chaves do vetor

    do{
        totalComparacoes7++; // considera-se previamente o caso em que ser� falso o valor booleano associado.
        while (vetor1[i] < x){ // varredura da esquerda para a diretia
            totalComparacoes7++;
            i++;
        }

        totalComparacoes7++; // considera-se previamente o caso em que ser� falso o valor booleano associado.
        while (vetor1[j] > x){ // varredura da direita para a esquerda
            totalComparacoes7++;
            j--;
        }

        if (i <= j){ // condicional para a troca dos valores encontrados nos endere�os indicados ap�s a execu��o das itera��es "while".
            aux = vetor1[i];
            vetor1[i] = vetor1[j];
            vetor1[j] = aux;
            totalMovimentacoes7 += 3;
            i++;
            j--;
        }

    } while (i <= j); // estrutura a qual evita o caso de loop infinito.

    if (i < direita) // acomoda��o do vetor para a esquerda.
        aplicacaoOrdenacaoQuickSort(vetor1, i, direita);

    if (esquerda < j) // acomoda��o do vetor para a direita.
        aplicacaoOrdenacaoQuickSort(vetor1, esquerda, j);
}

int main() {
  int n;

  cout<<"Informe o tamanho do vetor: ";
  cin>>n;
  cout<<endl;

  /*(Trecho usado para item "b)":
    cout << "Informe o tamanho do vetor: "; //Por conven��o de teste, a entrada ser�:
    //{45, 56, 12, 43, 95, 19, 8, 67}, ou seja, n = 8.

    cin>>n;
    cout<<endl;
  */

  /*(Trecho usado para item "c)" (1):
    //Aplica��o de valores aleat�rios:
    int *vetor1 = new int[n + 1];
    srand(time(NULL)); // "Source random"

    vetor1[1] = rand()%100;
    for (int i = 2; i <= n; i++)
        vetor1[i] = vetor1[i - 1] + rand()%3;

*/
  /*
  (Trecho usado para item "c)" (2):
    //Aplica��o de valores aleat�rios:
    int *vetor1 = new int[n + 1];
    srand(time(NULL)); // "Source random"

    vetor1[1] = rand()%10000;
    for (int i = 2; i <= n; i++)
        vetor1[i] = vetor1[i - 1] - rand()%3;
  */

  //(Trecho usado para item "c)" (3):
    //Aplica��o de valores aleat�rios:
    int *vetor1 = new int[n + 1];
    srand(NULL); // "Source random" -->  Uso da biblioteca ctime, para "burlar" a pseudoaleatoriedade dos n�meros da classe Random tradicional.

    for (int i = 1; i <= n; i++)
        vetor1[i] = rand()%100; //Aplica��o da Random, adaptada para o uso da biblioteca ctime.
  //*/

  int *vetor2 = new int[n + 1];
  preencherVetor(vetor1, vetor2, n);

  insercaoDireta(vetor1, n);
  desordenarVetor(vetor1, vetor2, n);

  insercaoBinaria(vetor1, n);
  desordenarVetor(vetor1, vetor2, n);

  selecao(vetor1, n);
  desordenarVetor(vetor1, vetor2, n);

  bubbleSort(vetor1, n);
  desordenarVetor(vetor1, vetor2, n);

  heapsort(vetor1, n);
  desordenarVetor(vetor1, vetor2, n);

  fusao(vetor1, n);
  desordenarVetor(vetor1, vetor2, n);

  quickSort(vetor1, n);

  delete[] vetor1;
  delete[] vetor2;

  return 0;
}
