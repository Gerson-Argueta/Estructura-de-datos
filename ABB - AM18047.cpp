//Gerson Rene Argueta Martinez
//Carnet: AM18047
//Estructura de Datos

#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo //structura para el arbol
{
	int nro;
	struct nodo *izq,*der;
};

typedef struct nodo *ABB;

class Arbolabb{
	public:
	ABB crearNodo(int x){ //reparte las dereccion de donde se almacenara

		ABB nuevoNodo=new (struct nodo); //reserva una parte de la memoria
	
		nuevoNodo->nro=x; //crea la raiz
		nuevoNodo->izq=NULL; //da valor null
		nuevoNodo->der=NULL; //da valor null
		return nuevoNodo; //regresa a hacer un nuevonodo
	
	}

	void insertar(ABB &arbol, int x){ //insertar nodo
	
		if(arbol==NULL) //verifica si esta null
		{
			arbol=crearNodo(x); //si esta null crea un nuevo nodo
		}
		else if(x<arbol->nro) //verifica si el valor ingresado es menor a la raiz
		{
			insertar(arbol->izq, x); //almacena en la posicion izquierda
		}
		else if(x>arbol->nro) //verifica si el valor ingresado es mayor a la raiz
		{
			insertar(arbol->der, x); //almacena en la posicion derecha
		}
	}

	void preOrden(ABB arbol){ //funcion que ordenara los datos en preorden

		if(arbol!=NULL)
		{
			cout<<arbol->nro <<" ";
			preOrden(arbol->izq);
			preOrden(arbol->der);
		}
	}
	void inOrden(ABB arbol){ //funcion que ordenara los datos en inorden
	
		if(arbol!=NULL){
			inOrden(arbol->izq);
			cout << arbol->nro << "\t";
			inOrden(arbol->der);
		}
	}

	void postOrden(ABB arbol){ //funcion que ordenara los datos en postorden
	
		if(arbol!=NULL){
			postOrden(arbol->izq);
			postOrden(arbol->der);
			cout << arbol->nro << "\t";
		}
	}

	void valor(ABB arbol,int &suma){
	
		if(arbol!=NULL)
		{
			valor(arbol->izq,suma);
			suma = suma + arbol->nro;
			valor(arbol->der,suma);
		}
	}
	
	void altura(ABB arbol,int *alt,int aux){
	
		if(arbol!=NULL){
			altura(arbol->izq,alt,aux+1);
			altura(arbol->der,alt,aux+1);
			if(aux > *alt){*alt = aux;}
		}
	}
	void verArbol(ABB arbol, int n){
	
		if(arbol==NULL){
		
			return;
		}
		verArbol(arbol->der,n+1);
		for(int i=0;i<n;i++){
			cout<<"   ";
		}
	
			cout<<arbol->nro<<endl;
			verArbol(arbol->izq,n+1);
	
	}

};

int main(){	//Funcion principal
	
	system("color 9f"); //Cambia el color del fondo y de la fuente
	
	Arbolabb *arbol=new(Arbolabb);
	ABB ar = NULL;
	int n, naux;
	int x,altura;
	char opc;
	int suma = 0, sumaaux = 0;
	
	system ("cls");
	cout <<"\t\t\t===============================================";
	cout <<"\n\t\t\t\tMENU: Arbol Binario de Busqueda\n";
	cout <<"\t\t\t===============================================";
	cout<<"\n\nINGRESE EL NUMERO DE NODOS DEL ARBOL: ";
	cin>>n;
	
	
	
	while(true){
		cout << "El arbol contiene actualente la cantidad de " << naux << " nodos\n";	
		cout << "\n1- Ingresar un nodo";
		cout << "\n2- suma de todas las claves";
		cout << "\n3- Altura del arbol";
		cout << "\n4- Menu de recorridos";
		cout << "\n5- Ver arbol";
		cout << "\n6- Crear un nuevo arbol";
		cout << "\n7-Salir\n...";
		cin >> opc;
	
		switch(opc){
			
			case '1': //llenado de los datos de los nodos
				if(naux < n){		
				cout<<"valor del nodo: "<<endl;
				cin>>x;
				arbol->insertar(ar,x);
				naux++;
				}else{
					cout << "Ha llegado al maximo de nodos permitidos: " << n << "\nDesearia aumentar ese limite?(s/n)";
					cin >> opc;
					if(opc == 's' || opc == 'S'){
						do{
						cout << "\nIngrese la nueva cantidad de nodos que quiere que tenga el ABB: ";cin >> n;
						}while(n < naux);
					}
				}
				break;
			
			case '2': //verifica los datos y los suma
				if(ar == NULL){
					cout << "El arbol esta vacio\n";
					break;
				}
				arbol->valor(ar, suma);
				cout << "La suma de todos los valores en el arbol es: " << suma << endl;
				suma = 0;
				break;
			
			case '3': //da la altura del ABB
				arbol->altura(ar,&altura,1);
				cout << "La altura del arbol es: " << altura << endl;
				altura = 0;
				break;
			
			case '4': //Muestra el ABB en 3 ordenes diferentes
				cout << "\n1-PRE-ORDEN";
				cout << "\n2-IN-ORDEN";
				cout << "\n3-POSTORDEN\n";
				cin >> opc;
			
				if(opc == '1'){
					arbol->preOrden(ar);
				} else if(opc == '2'){
					arbol->inOrden(ar);
				} else if(opc == '3'){
					arbol->postOrden(ar);
				}
				break;
			
			case '5': //muestra  el arbol
				arbol->verArbol(ar,0);
				break;
		
			case '6': //repite el bucle de la creacion del arbol
				return main();
			break;
		
			case '7': //cierra el programa
				return 0;
			}
	
		system("pause");
	
		system("cls");
		
	}

}
