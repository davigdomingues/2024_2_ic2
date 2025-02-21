#include <iostream>
#include <limits>
using namespace std;

struct Domicilio{
    float rendaMensal;
    int totalOcupantes;
    string endereco;
    int ocupantesIdadeEscolar;
};

bool preencherInformacaoDomicilio(Domicilio& domicilio) {
    cout << "Renda mensal do domicilio: ";
    cin >> domicilio.rendaMensal;
    if (domicilio.rendaMensal <= 0) {
        cout << "Dado invalido! Insercao interrompida..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora a linha
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Total de ocupantes do domicilio: ";
    cin >> domicilio.totalOcupantes;
    if (domicilio.totalOcupantes <= 0) {
        cout << "Dado invalido! Insercao interrompida..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Endereco do domicilio: ";
    getline(cin, domicilio.endereco);
    if (domicilio.endereco.empty()) {
        cout << "Dado invalido! Insercao interrompida..." << endl;
        return false;
    }

    cout << "Ocupantes em idade escolar do domicilio: ";
    cin >> domicilio.ocupantesIdadeEscolar;
    if (domicilio.ocupantesIdadeEscolar <= 0 || domicilio.ocupantesIdadeEscolar >= domicilio.totalOcupantes) {
        cout << "Dado invalido! Insercao interrompida..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return true;
}

void encontrarDadosDomicilio(Domicilio domicilio[], int i, string& endereco_desejado){
    domicilio[i].endereco = endereco_desejado; // atribuicao ao sentinela da busca linear.
    for (int j = 0; j < i; j++){
        if(domicilio[j].endereco == domicilio[i].endereco){
            cout<<"Endereco localizado, dados encontrados!"<<endl;
            cout<<"Renda mensal: "<<domicilio[j].rendaMensal<<endl;
            cout<<"Total de ocupantes: "<<domicilio[j].totalOcupantes<<endl;
            cout<<"Ocupantes em idade escolar: "<<domicilio[j].ocupantesIdadeEscolar<<endl;
            return;
        }
    }
    cout<<"Endereco nao localizado, dados inexistentes!";
}

int main(){
    int opcao = 0, i = 0, total_domicilios;
    string endereco_desejado;

    cout<<"Informe o total de domicilios: ";
    cin>>total_domicilios;
    cout<<endl;

    Domicilio* domicilio = new Domicilio[total_domicilios + 1]; //vetor que comporta o sentinela

    do{
        cout<<"Informe o que deseja fazer:"<<endl;
        cout<<"(1) Digitar os dados de um domicilio"<<endl;
        cout<<"(2) Buscar os dados de um domicilio, a partir de um endereco"<<endl;
        cout<<"(3) Sair"<<endl;
        cin>>opcao;

        switch(opcao){
            case 1:
                if (i < total_domicilios){
                    if (preencherInformacaoDomicilio(domicilio[i])) i++;
                }

                else cout<<"Numero maximo de domicilios alcancado, impossivel adicionar informacoes!"<<endl;
                break;

            case 2:
                cout<<"Informe o endereco desejado para saber os dados associados: ";
                getline(cin, endereco_desejado);

                encontrarDadosDomicilio(domicilio, i, endereco_desejado);
                break;

            case 3:
                cout<<endl<<"Saindo..."<<endl;
                break;

            default:
                cout<<"Opcao invalida, tente novamente..."<<endl;
         }

         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer antes de um novo loop
    } while(opcao != 3);

    delete[] domicilio;

return 0;
}
