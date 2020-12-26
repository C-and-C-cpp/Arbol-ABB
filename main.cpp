#include <iostream>
using namespace std;

class Nodo{
public:
    string juego;
    Nodo* sgt;
public:
    Nodo(string juego){
        this->juego=juego;
        sgt=nullptr;
    }
    void setSgt(Nodo* n){
        this->sgt=n;
    }
};
class LinkedList{
public:
    Nodo* first;
public:
    LinkedList(){
        first= nullptr;
    }

    void setFirst(Nodo* n){
        this->first=n;
    }
    void insertar(string juego){
        Nodo* nuevo = new Nodo(juego);
        if(first == nullptr){
            first=nuevo;
        }else{
            nuevo->setSgt(first);
            first=nuevo;
        }

    }
    bool buscar(string juego){
        Nodo* actual=first;
        if(actual!=nullptr){
            while(actual!=nullptr && actual->juego != juego){
                actual=actual->sgt;
            }
        }
        if(actual== nullptr){
            return false;
        }else{
            return true;
        }
    }
    void mostrar(){
        Nodo* actual = first ;
        if(actual!= nullptr){
            while(actual!= nullptr){
                cout<<actual->juego<<endl;
                actual=actual->sgt;
            }
        }

    }
};

class NodoABB{
public :
    int n ;
    LinkedList* lista;
    NodoABB* left;
    NodoABB* right;

public:
    NodoABB(int x){
        this->n=x;
        lista=new LinkedList();
        left = nullptr;
        right= nullptr;
    }
    void mostrar(){
        cout<<n<<endl;
    }
};
class ABB{
public:
    NodoABB* raiz;
public:
    ABB(){
        raiz= nullptr;
    }
    void insert(NodoABB*& raiz,int x , string juego) {
        if(raiz == nullptr){
            raiz = new NodoABB(x);
            raiz->lista->insertar(juego);
            raiz->mostrar();
            raiz->lista->mostrar();
        }else if(raiz->n == x){
            raiz->lista->insertar(juego);
        }
        else{
            if (x > raiz->n) {
                if (raiz->right == nullptr) {
                    raiz->right = new NodoABB(x);
                    raiz->right->lista->insertar(juego);
                } else insert(raiz->right,x,juego);
            } else if (raiz->left == nullptr) {
                raiz->left = new NodoABB(x);
                raiz->left->lista->insertar(juego);
            } else insert(raiz->left,x,juego);
        }

    }

    void ingresar(int gen , string juego){
        insert(raiz,gen,juego);

    };

    bool existe(NodoABB* raiz , int gen){
        if(raiz!=nullptr){
            if(raiz->n == gen){
                return true;
            }else{
                if(raiz->n > gen){
                    return existe(raiz->left, gen);
                }else{
                    return existe(raiz->right,gen);
                }
            }
        }
        return false;
    }

    bool buscarConsola(int gen){
        return existe(raiz,gen);
    }

    void desplegarConsola(){
        desplegar(raiz);
    }
    void desplegar(NodoABB* raiz){

        if (raiz != nullptr) {
            desplegar(raiz->left);
            raiz->mostrar();
            desplegar(raiz->right);
        }
    }

    bool buscarVJ(int gen , string juego){
        if(raiz!=nullptr){
            if(raiz->n == gen){
                return raiz->lista->buscar(juego);
            }else{
                if(raiz->n > gen){
                    return existe(raiz->left, gen);
                }else{
                    return existe(raiz->right,gen);
                }
            }
        }
        return false;
    }

    void desplegarJuegosConsola(NodoABB* raiz,int gen){

        if(raiz!=nullptr){
            if(raiz->n == gen){
                raiz->lista->mostrar();
            }else{
                if(raiz->n > gen){
                    desplegarJuegosConsola(raiz->left, gen);
                }else{
                    desplegarJuegosConsola(raiz->right,gen);
                }
            }
        }
    }
    void desplegarJC(int gen){
        desplegarJuegosConsola(raiz, gen);
    }

};

void Menu(ABB* arbol){

    int opcion;
    cout<<"1- Ingresar juego"<<endl;
    cout<<"2- Buscar Consola"<<endl;
    cout<<"3- Desplegar Consolas"<<endl;
    cout<<"4- Buscar VideoJuego"<<endl;
    cout<<"5- Desplegar Juegos Consola"<<endl;
    cout<<"6- Fin"<<endl;
    cin>>opcion;
    while(opcion!=6){
        if(opcion==1){
            int gen;
            string j;
            cout<<" Ingresar generacion"<<endl;
            cin>>gen;
            cout<<" Ingresar juego"<<endl;
            cin>>j;
            arbol->ingresar(gen,j);

        }
        else{
            if(opcion==2){
                int gen ;
                cout<<" Ingresar generacion"<<endl;
                cin>>gen;

                (arbol->buscarConsola(gen))? cout<<"Existe"<<endl:cout<<"No existe"<<endl;
            }
            else{
                if(opcion==3){
                    arbol->desplegarConsola();
                }
                else{
                    if(opcion==4){
                        int gen;
                        string j;
                        cout<<" Ingresar generacion"<<endl;
                        cin>>gen;
                        cout<<" Ingresar juego"<<endl;
                        cin>>j;

                        (arbol->buscarVJ(gen,j))? cout<<"Existe"<<endl:cout<<"No existe"<<endl;
                    }
                    else{
                        if(opcion==5){
                            int gen;
                            cout<<" Ingresar generacion"<<endl;
                            cin>>gen;
                            arbol->desplegarJC(gen);
                        }
                    }
                }
            }
        }


        cout<<"1- Ingresar juego"<<endl;
        cout<<"2- Buscar Consola"<<endl;
        cout<<"3- Desplegar Consolas"<<endl;
        cout<<"4- Buscar VideoJuego"<<endl;
        cout<<"5- Desplegar Juegos Consola"<<endl;
        cout<<"6- Fin"<<endl;
        cin>>opcion;
    }
}



int main() {

    ABB* arbol= new ABB();
    Menu(arbol);
    delete arbol;
    return 0;


}
