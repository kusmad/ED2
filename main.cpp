#include<iostream>
#include<list>
#include<fstream>

//ajuste: calcular o grau do vertice logo após a leitura para facilitar nas outras duas fuções;

using namespace std;

struct dados{
    int numero_v; // número do vértice
    string rotulo;
    int numero_aresta;
    string rotulo_aresta;
    string v_inicial; // vértice inicial
    string v_final; // vértice final
    int custo;
    int grau;
};

void menu(){
    cout << "Digite a opcao desejada:\n\n";
    cout << "1- Arvore Geradora Minima\n";
    cout << "2- Grau vertice\n";
    cout << "3- Vertices finais\n";
    cout << "4- incidencia\n";
    cout << "5- Circuito\n";
    cout << "6- Sequencia de graus\n";
    cout << "7- Fim\n";
}

bool leitura_arq(list<dados> &grafo){
    ifstream arq;
    dados leitura, p;
    int cont;

    arq.open("grafo.txt");

    if(!arq){
        cout << "Erro ao abrir o arquivo!\n";
        return 0;
    }

    while(arq >> leitura.numero_v){
        cont = leitura.numero_v;
        for(int i=0; i<cont; i++){
            arq >> leitura.rotulo;
            grafo.push_back(leitura);
    }
        arq >> leitura.numero_aresta;
        cont = leitura.numero_aresta;
        for(int j=0; j<cont; j++){
            arq >> leitura.rotulo_aresta >> leitura.v_inicial >> leitura.v_final >> leitura.custo;
            grafo.push_back(leitura);
        }
    }
    grafo.push_back(leitura);

    return 0;

}

void grau_vertice(list<dados> &grafo){
    string rot;
    int t_grau;
    dados aux;

    rot = aux.rotulo;

    for(auto it=grafo.begin(); it!=grafo.end(); it++){
        if(rot == it->v_inicial || rot == it->v_final)
            cout << "yes" << endl;
    }
}

/*void vertice_final(list<dados> grafo){
    for(auto it=grafo.begin(); it!=grafo.end(); it++){
        if(it->vinici)
    }
}*/

int main(){

    int op;
    list<dados> grafo;

    leitura_arq(grafo);

    menu();

    cin >> op;

    do{
        switch(op){
            case 2:
                grau_vertice(grafo);
                break;

        }

    }while(op!=7);

    return 0;

}
