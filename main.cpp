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

bool grau_vertice(list<dados> &grafo){
    string vertice;
    int acum =0;
    cout << "Digite o nome do vertice desejado: ";
    cin >> vertice;

    for(auto it=grafo.begin(); it!=grafo.end(); it++){
        if(vertice == it->v_inicial || vertice == it->v_final) acum ++;
    }
        cout << "Grau do vertice " << vertice << ":" << acum-1 << endl;
    return 0;
}

bool vertice_final(list<dados> grafo){
    int total_grau;
    dados insere_grau;
    string rot;
    auto j = grafo.begin();

    int p = 0;
    while(p<j->numero_v){
        rot = j->rotulo;
        total_grau = 0;
        for(auto it=grafo.begin(); it!=grafo.end(); it++){
            if(rot == it->v_inicial || rot == it->v_final) total_grau ++;
        }
        p++;
        j++;
        if(total_grau == 1)
            cout << "Vertice(s) final(is): " << rot << endl;

        else{
            cout << "Nao foram encontrados vertices finais\n\n";
            return 0;
        }

    }
}

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
            case 3:
                vertice_final(grafo);
                break;

        }

    }while(op!=7);

    return 0;

}
