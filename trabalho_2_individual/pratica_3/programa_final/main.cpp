/*letra a e b:
Procedimento recHanoi( discos , inicio , fim , temporario ):
Entrada: número do disco, torres inicial, final e temporária
se discos > 0
recHanoi ( discos-1 , inicio , temporario , fim )
escreva (“Mova disco ” , discos , ” da torre “ , inicio , “ para a torre “, fim )
recHanoi ( discos-1 , temporario , fim , inicio )
fim se
retorne

#include <iostream>
using namespace std;

void recHanoi(int discos, int inicio, int fim, int temporario){
    if (discos > 0){
        recHanoi(discos - 1, inicio, temporario, fim);
        cout<<"Mova disco "<<discos<<" da torre "<<inicio<<" para a torre "<<fim<<endl;
        recHanoi(discos - 1, temporario, fim, inicio);
    }
}

int main(){
    int totalDiscos, torreInicial, torreFinal, torreTemporaria;

    cout<<"Informe o total de discos a serem utilizados: ";
    cin>>totalDiscos;

    cout<<"Informe a torre inicial que deseja colocar todos os discos: ";
    cin>>torreInicial;

    cout<<"Informe a torre final que deseja colocar todos os discos: ";
    cin>>torreFinal;

    cout<<"Informe a torre intermediaria que deseja colocar todos os discos: ";
    cin>>torreTemporaria;
    recHanoi(totalDiscos, torreInicial, torreFinal, torreTemporaria);

return 0;
}
*/

/*letra c:
#include <iostream>
#include <ctime>
using namespace std;

void recHanoi(int discos, int inicio, int fim, int temporario){
    if (discos > 0){
        recHanoi(discos - 1, inicio, temporario, fim);
        recHanoi(discos - 1, temporario, fim, inicio);
    }
}

int main(){ //Obs: a quantia de torres é sempre 3!
    clock_t time1, time2;
    int totalDiscos;
    double tempoFinal = 0.0;

    cout<<"Informe o total de discos a serem utilizados (ha somente 3 torres): ";
    cin>>totalDiscos;

    time1 = clock();
    recHanoi(totalDiscos, 0, 1, 2);
    time2 = clock();

    tempoFinal = difftime(time2, time1)/CLOCKS_PER_SEC;
    cout<<"\n\n"<<tempoFinal;

return 0;
}
*/

//letra d:
#include <iostream>
#include <ctime>
using namespace std;
int totalVariaveisPrograma = 0;

void recHanoi(int discos, int inicio, int fim, int temporario){
    totalVariaveisPrograma += 4;
    if (discos > 0){
        recHanoi(discos - 1, inicio, temporario, fim);
        recHanoi(discos - 1, temporario, fim, inicio);
    }
}

int main(){ //Obs: a quantia de torres é sempre 3!
    int totalDiscos, torreInicial, torreFinal, torreTemporaria;
    totalVariaveisPrograma += 4;

    cout<<"Informe o total de discos a serem utilizados: ";
    cin>>totalDiscos;

    cout<<"Informe a torre inicial que deseja colocar todos os discos: ";
    cin>>torreInicial;

    cout<<"Informe a torre final que deseja colocar todos os discos: ";
    cin>>torreFinal;

    cout<<"Informe a torre intermediaria que deseja colocar todos os discos: ";
    cin>>torreTemporaria;

    recHanoi(totalDiscos, torreInicial, torreFinal, torreTemporaria);
    cout<<totalVariaveisPrograma;

return 0;
}
