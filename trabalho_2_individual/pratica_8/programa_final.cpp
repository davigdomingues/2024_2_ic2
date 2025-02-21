/*Obs:a palavra-chave const � usada para declarar vari�veis ou par�metros que n�o podem
ser modificados ap�s a sua inicializa��o. Isso ajuda a garantir que certos valores permane�am
constantes durante a execu��o do programa, aumentando a seguran�a e a clareza do c�digo
*/

#include <iostream>
#include <string>

#define PRIMO 17 // Tamanho da tabela hash (tamanho fixo)
#define BASE 256 // Base para convers�o de string para inteiro (ASCII estendido)

using namespace std;

struct Registro {
    string key; // Chave
    int idade; // Valor associado � chave (por exemplo, idade)
    bool removido; // Indicador de remo��o
};

Registro T[PRIMO]; // Tabela hash com P posi��es

// Fun��o de mapeamento/transforma��o
int transform(const string& s, int primo) {
    int somaValoresStringASCII = 0;

    for (int i = 0; i < s.length(); i++)
        somaValoresStringASCII = somaValoresStringASCII * BASE + s[i];

    int x = somaValoresStringASCII % primo;
    return x;
}

// Fun��o de inser��o
int Hash_insercao(Registro T[], const string& key, int idade) {
    int i = 0, h;

    // Sondagem linear
    do {
        h = (transform(key, PRIMO) + i) % PRIMO;  // Calcula o �ndice com a sondagem

        if (T[h].key.empty() || T[h].removido) {
            T[h].key = key;
            T[h].idade = idade;
            T[h].removido = false;
            return h;
        }

        else
            i++;  // Sondagem linear, incrementa o contador

    } while (i != PRIMO);  // Caso a tabela esteja cheia

    cout << "Erro: Overflow na tabela hash!" << endl;
    return -1;  // Retorna valor inv�lido caso a tabela esteja cheia
}

// Fun��o de busca
int Hash_busca(Registro T[], const string& key) {
    int i = 0, h;

    // Sondagem linear
    do {
        h = (transform(key, PRIMO) + i) % PRIMO;  // Calcula o �ndice com a sondagem

        if (T[h].key == key && !T[h].removido)
            return h;

        else if (T[h].key.empty())
            return -1;

        i++;

    } while (i != PRIMO);

    return -1;
}

// Fun��o de remo��o
int Hash_remover(Registro T[], const string& key) {
    int pos = Hash_busca(T, key);

    if (pos != -1) { // Uso de flag booleana (indica que a posi��o n�o pode mais ser usada)
        T[pos].removido = true;
        return pos;
        /* Caso se deseje remover todo o conte�do, sem aplicar a l�gica das flags booleanas
        T[pos].key = ""; // Remove a chave
        T[pos].idade = 0; // Reseta o valor associado
        */
    }

    return -1;
}

void exibirMenu() {
    cout << "\nMenu de Opera��es:\n";
    cout << "1. Inserir novo registro\n";
    cout << "2. Buscar registro\n";
    cout << "3. Remover registro\n";
    cout << "4. Sair\n";
    cout << "Escolha uma op��o: ";
}

int main() {
    for (int i = 0; i < PRIMO; i++) { // Inicializando a tabela hash com chaves vazias
        T[i].key = "";
        T[i].removido = false;
    }

    int opcao, idade;
    string nome;

    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: { // delimita a mudan�a das vari�veis exclusivamente para o caso tratado dentro do switch
                cout << "\nDigite o nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite a idade: ";
                cin >> idade;

                int pos = Hash_insercao(T, nome, idade);

                if (pos != -1)
                    cout << "Registro inserido na posi��o " << pos << endl;

                break;
            }

            case 2: {
                cout << "\nDigite o nome a ser buscado: ";
                cin.ignore();
                getline(cin, nome);

                int pos = Hash_busca(T, nome);

                if (pos != -1)
                    cout << "Chave " << nome << " encontrada na posi��o " << pos << ", Idade: " << T[pos].idade << endl;

                else
                    cout << "Chave " << nome << " n�o encontrada." << endl;

                break;
            }

            case 3: {
                cout << "\nDigite o nome a ser removido: ";
                cin.ignore();
                getline(cin, nome);

                int pos = Hash_remover(T, nome);

                if (pos != -1)
                    cout << "Chave " << nome << " removida da posi��o " << pos << endl;

                else
                    cout << "Chave " << nome << " n�o encontrada." << endl;

                break;
            }

            case 4:
                cout << "Saindo do programa..." << endl;
                break;

            default:
                cout << "Op��o inv�lida, tente novamente." << endl;
                break;
        }

    } while (opcao != 4);

    return 0;
}
