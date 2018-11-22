#include<iostream>
#include<list>
#include<fstream>

//ajuste: calcular o grau do vertice logo após a leitura para facilitar nas outras duas fuções;
//ajuste2: na função do grau um dos for's era desnecessário e tava bugando o V05;

using namespace std;

int menu(){
    cout << "Digite a opcao desejada:\n\n";
    cout << "1- Arvore Geradora Minima\n";
    cout << "2- Grau vertice\n";
    cout << "3- Vertices finais\n";
    cout << "4- incidencia\n";
    cout << "5- Circuito\n";
    cout << "6- Sequencia de graus\n";
    cout << "7- Sair\n";
    int op;
    cin >> op;
    return op;

}

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

bool leitura_arq(list<dados> &grafo){
    ifstream arq;
    dados aux;
    int qtd;

    arq.open("grafo.txt");

    if(!arq){
        cout << "Erro ao abrir o arquivo!\n";
        return 0;
    }

    if(arq >> aux.numero_v){
        qtd = aux.numero_v;
        for(int i=0; i<qtd; i++){
            arq >> aux.rotulo;
            grafo.push_back(aux);
        }
    }

    if(arq >> aux.numero_aresta){
        qtd = aux.numero_aresta;
            for(int j=0; j<qtd; j++){
                arq >> aux.rotulo_aresta >> aux.v_inicial >> aux.v_final >> aux.custo;
                grafo.push_back(aux);
            }
    }

    return 0;
}

bool grau(list<dados> grafo){
    string vertice;
    cout << "Digite o nome do vertice desejado: ";
    cin >> vertice;
    int acum =0;

    for(auto it=grafo.begin(); it!=grafo.end(); it++){
        if(vertice == it->v_inicial || vertice == it->v_final){
            acum++;
        }
    }
    if(acum!=0)
        cout << "grau de " << vertice << ": " << acum << endl;
    else
        cout << "grau de " << vertice << ": " << "Nao existe." << endl;

    cout << endl;
    return 0;
}

bool incidente(list<dados> grafo){
    dados aux;
    cout << "Digite o nome da aresta desejada: ";
    cin >> aux.rotulo_aresta;

    for(auto it=grafo.begin(); it!=grafo.end(); it++){
        if(aux.rotulo_aresta == it->rotulo_aresta){

        }
    }

    return 0;
}

bool vertice_final(list<dados> &grafo){
    int cont, vf;
    list<dados>::iterator p=grafo.begin();
    string v;
    cont = p->numero_v;
   // cout << p->numero_v << endl;
    //cout << cont << endl;
    while(cont--){
        v = p->rotulo;
      //  cout << v << endl;
        vf = 0;
        for(auto it=grafo.begin(); it!=grafo.end(); it++){
            if(v == it->v_inicial || v == it->v_final){
                vf ++;
               // cout << vf << endl;
            }
        }
        if(vf==1){
            cout << "Vertice final: " << v << endl;

        }
        else{
            cout << "Nao ha vertices finais no grafo\n\n";
        }
        p++;
    }
}



int main(){

    int op;
    list<dados> grafo;

    leitura_arq(grafo);

    do{
        op = menu();
        switch(op){
            case 2:
                grau(grafo);
                break;
            case 3:
                vertice_final(grafo);
                break;
            case 4:
                incidente(grafo);
                break;

            default:
        cout<<"Opcao invalida";
        break;
    }
    }while(op!=7);

    return 0;
}
