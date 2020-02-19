#include<iostream>
#include <conio.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<stdbool.h>
#include <vector>
#include<algorithm>
#include <cctype>
#include<sstream>
#include <bits/stdc++.h>  

using namespace std;

class NodoP{
	public:
        string dato;
        string dato2;
        NodoP *siguiente;
        
    NodoP(string dato, string dato2){
        this->dato=dato;
        this->dato2=dato2;
        siguiente = NULL;
        
    }
};


class Pila{
	private:
		NodoP *top;
	public:
		int tamanio;
		Pila(){
			top=NULL;
			tamanio=0;
		}	
		
		void push(string dato, string dato2){
			NodoP *n = new NodoP(dato, dato2);
			if(top==NULL)
				top = n;
				else{
					n->siguiente=top;
					top=n;
				}
			tamanio++;
		}
		int getTamanio(){
			return tamanio;
		}
		string pop(){
			if(top==NULL){
				cout<<"Pila vacia"<<endl;
				return "ERROR";
				
				
			}else{
				string datoTemp = top->dato;
				NodoP *temp = top;
				top = top->siguiente;
				delete temp;
				return datoTemp;
				tamanio--;
			}
		
		}
		void imprimir(){
        NodoP *temp = top;
        while(temp != NULL){
            cout << temp->dato << " ";
            temp = temp ->siguiente;
        }
        cout << endl;
    	}
    	
    	bool vacio(){
    		if(top==NULL){
    			return true;
			}else{
				return false;
			}
		}
    	
    	void reportePilaLog(){
			
			//cout<<"Si entre"<<endl;
			string cadena="";
	    	string cadenaN="";
	    	string dot = "";
	    	//char sim = '\n';
	    	string fin = "";
	    	string conexion = "";
	    	string conexion2 = "";
	    	string dot2 = "";
	    	int conta = getTamanio();
	    	//stringstream ss, ss1, ss2;
	    	if(vacio()==true){
	    		cout<<"Lista Vacia"<<endl;
			}else{
				ofstream archivo;
		    	archivo.open("reporteLog.dot", ios::out);
		    	if(archivo.fail()){
		    		cout<<"ERROR"<<endl;
		    		
				}
				archivo<<"digraph cancion{\n";
				archivo<<"node [shape=record];\n";
				archivo<<"rankdir=LR;\n";
				NodoP *recorrido = this->top;
				cout<<cadena<<endl;
				while(recorrido != NULL){
					//cout<<cadena<<endl;
					cadena="Dato Original = "+recorrido->dato+"\\n"+"Dato Remplazado = "+recorrido->dato2+"\\n";
					//cadena ="Dato original: " + recorrido->dato+""\n"" +" Dato remplazado: "+ recorrido->dato2;
					
					
					stringstream ss;
					ss << conta;
					string a;
					ss>>a;
					dot += "node"+ a +"[label = "+"\""+cadena+"\""+"];\n";
					//dot += "node"+ a +"[label = "+"\""+cadenaN+"\""+"];\n";
					//conta= getTamanio();
					int auxi = conta-1;
					stringstream ss1;
					ss1<<auxi;
					string recor;
					ss1>>recor;
					
					conexion += "node"+ a +"->"+"node"+recor+"\n";
					//conexion2 += "node"+ recor +"->"+"node"+a+"\n";
					recorrido = recorrido->siguiente;
					
					/*if(recorrido == this->cola){
						//cout<<cadena<<endl;
						fin = recorrido->dato;
						conta++;
						stringstream ss2;
						ss2<<conta;
						string salida;
						ss2>>salida;
						
						dot2 = "node"+salida+"[label= "+"\""+fin+"\""+"];\n";
						break;
					}*/
					conta--;
					
					
				}
				archivo<<dot;
				archivo<<dot2;
				archivo<<"\n";
				archivo<<conexion;
				archivo<<"\n";
				archivo<<conexion2;
				archivo<<"\n";
				archivo<<"label = \"REPORTE DE CAMBIOS\";\n";
				archivo<<"}\n";
				archivo.close();
				system("dot reporteLog.dot -o reporteLog.png -Tpng");
				system("start reporteLog.png");
		    	
			}
			
			
			
		}
			
};

class Nodo{
    public:
        string dato;

        Nodo *siguiente;
        Nodo *anterior;
    	Nodo(string dato){
        	this->dato=dato;
        	siguiente = NULL;
        	anterior=NULL;
    	}
};

class ListaDoble{
    private:
        Nodo *cabecera;
        Nodo *cola;
        int tamanio;
        
    public:
    	string ayuda;
        ListaDoble(){
        	
            cabecera = NULL;
            cola = NULL;
            tamanio = 0;
            ayuda = "";
        }
        ~ListaDoble(){
            Nodo *siguiente;
            while(cabecera != NULL){
                siguiente = cabecera->siguiente;
                delete cabecera;
                cabecera = siguiente;
                //ayuda = "";
            }

        }
        int getTamanio(){
            return tamanio;
        }
        string getDato(){
        	Nodo *temp = cabecera;
        	string valorE;
	        while(temp != NULL){
	            ayuda += temp->dato;
	            temp = temp ->siguiente;
        	}
        	return ayuda;
		}
        void eliminarFinal(){
     	   if (cabecera->siguiente==NULL){
        	    delete cabecera;
            	cabecera= NULL;
            	cola=NULL;
            	tamanio--;

	        }else if (cabecera!=NULL){
	            cola = cola->anterior;
	            delete cola->siguiente;
	            cola ->siguiente = NULL;
	            tamanio--;
        	}
    	}

    	void eliminarInicio(){
	        if (cabecera->siguiente==NULL ){
	            delete cabecera;
	            cabecera=NULL;
	            cola = NULL;
	            tamanio--;
	
	        }else if (cabecera != NULL){
	            cabecera = cabecera -> siguiente;
	            delete cabecera ->anterior;
	            cabecera->anterior = NULL;
	            tamanio--;
	        }
    	}

        void insertarFinal(string dato){
	        Nodo *n = new Nodo(dato);
	        if(cabecera == NULL){
	            cabecera=n;
	            cola=n;
	        }else{
	            cola->siguiente=n;
	            n->anterior=cola;
	            cola = n;
	
	        }
	        tamanio++;
	
	        }
	    void insertarInicio(string dato){
	        Nodo *n = new Nodo(dato);
	        if(cabecera== NULL){
	            cabecera = n;
	            cola = n;
	
	        }else{
	            cabecera->anterior=n;
	            n->siguiente=cabecera;
	            cabecera=n;
	
	        }
	        tamanio++; 
	    }
	    
	    
        void imprimir(){
	        Nodo *temp = cabecera;
	        string ayuda;
	        while(temp != NULL){
	            cout << temp->dato << "\n";
	            ayuda += temp->dato;
	            temp = temp ->siguiente;
               
        	}
        	cout << endl;
   		}
   		
   		bool vacio(){
   			if (cabecera==NULL){
   				return true;
			   }else{
			   	return false;
			   }
   			
		}
		
		void reporteArchivosR(){
			string cadena="";
	    	string cadenaN="";
	    	string dot = "";
	    	//char sim = '\n';
	    	string fin = "";
	    	string conexion = "";
	    	string conexion2 = "";
	    	string dot2 = "";
	    	int conta = 0;
	    	//stringstream ss, ss1, ss2;
	    	if(vacio()==true){
	    		cout<<"Lista Vacia"<<endl;
			}else{
				ofstream archivo;
		    	archivo.open("reporteArchivos.dot", ios::out);
		    	if(archivo.fail()){
		    		cout<<"ERROR"<<endl;
		    		
				}
				archivo<<"digraph cancion{\n";
				archivo<<"node [shape=record];\n";
				archivo<<"rankdir=LR;\n";
				Nodo *recorrido = this->cabecera;
				cout<<cadena<<endl;
				while(recorrido != NULL){
					//cout<<cadena<<endl;
					cadena = recorrido->dato;
					
					
					stringstream ss;
					ss << conta;
					string a;
					ss>>a;
					dot += "node"+ a +"[label = "+"\""+cadena+"\""+"];\n";
					//dot += "node"+ a +"[label = "+"\""+cadenaN+"\""+"];\n";
					int auxi = conta+1;
					stringstream ss1;
					ss1<<auxi;
					string recor;
					ss1>>recor;
					
					conexion += "node"+ a +"->"+"node"+recor+"\n";
					//conexion2 += "node"+ recor +"->"+"node"+a+"\n";
					recorrido = recorrido->siguiente;
					
					if(recorrido == this->cola){
						//cout<<cadena<<endl;
						fin = recorrido->dato;
						conta++;
						stringstream ss2;
						ss2<<conta;
						string salida;
						ss2>>salida;
						string salida1 = "0";
						dot2 = "node"+salida+"[label= "+"\""+fin+"\""+"];\n";
						conexion += "node"+ recor +"->"+"node"+salida1+"\n";
						break;
					}
					conta++;
					
					
				}
				archivo<<dot;
				archivo<<dot2;
				archivo<<"\n";
				archivo<<conexion;
				archivo<<"\n";
				archivo<<conexion2;
				archivo<<"\n";
				archivo<<"label = \"REPORTE DE ARCHIVOS RECIENTES\";\n";
				archivo<<"}\n";
				archivo.close();
				system("dot reporteArchivos.dot -o reporteArchivos.png -Tpng");
				system("start reporteArchivos.png");
		    	
			}
			
		}
		
		void reporteLetras(){
			
			//cout<<"Si entre"<<endl;
			string cadena="";
	    	string cadenaN="";
	    	string dot = "";
	    	//char sim = '\n';
	    	string fin = "";
	    	string conexion = "";
	    	string conexion2 = "";
	    	string dot2 = "";
	    	int conta = 0;
	    	//stringstream ss, ss1, ss2;
	    	if(vacio()==true){
	    		cout<<"Lista Vacia"<<endl;
			}else{
				ofstream archivo;
		    	archivo.open("reporteLetras.dot", ios::out);
		    	if(archivo.fail()){
		    		cout<<"ERROR"<<endl;
		    		
				}
				archivo<<"digraph cancion{\n";
				archivo<<"node [shape=record];\n";
				archivo<<"rankdir=LR;\n";
				Nodo *recorrido = this->cabecera;
				cout<<cadena<<endl;
				while(recorrido != NULL){
					//cout<<cadena<<endl;
					cadena = recorrido->dato;
					
					
					stringstream ss;
					ss << conta;
					string a;
					ss>>a;
					dot += "node"+ a +"[label = "+"\""+cadena+"\""+"];\n";
					//dot += "node"+ a +"[label = "+"\""+cadenaN+"\""+"];\n";
					int auxi = conta+1;
					stringstream ss1;
					ss1<<auxi;
					string recor;
					ss1>>recor;
					
					conexion += "node"+ a +"->"+"node"+recor+"\n";
					conexion2 += "node"+ recor +"->"+"node"+a+"\n";
					recorrido = recorrido->siguiente;
					
					if(recorrido == this->cola){
						//cout<<cadena<<endl;
						fin = recorrido->dato;
						conta++;
						stringstream ss2;
						ss2<<conta;
						string salida;
						ss2>>salida;
						
						dot2 = "node"+salida+"[label= "+"\""+fin+"\""+"];\n";
						break;
					}
					conta++;
					
					
				}
				archivo<<dot;
				archivo<<dot2;
				archivo<<"\n";
				archivo<<conexion;
				archivo<<"\n";
				archivo<<conexion2;
				archivo<<"\n";
				archivo<<"label = \"REPORTE DE CARACTERES\";\n";
				archivo<<"}\n";
				archivo.close();
				system("dot reporteLetras.dot -o reporteLetras.png -Tpng");
				system("start reporteLetras.png");
		    	
			}
			
			
			
		}
		
		
   		
    	void buscar(string valor, string ingreso){
    	//	cout<<valor<<" " << ingreso << "\n";
    	
    	Nodo *aux = cabecera;
    	Nodo *pos = cabecera;
    	Nodo *temp = cabecera;
    	Nodo *n = new Nodo(ingreso);
    	if(cabecera != NULL){
    	//	cout<<"Primer if\n";
    		
    	//	cout<< temp->dato <<" a\n";
    		//temp = temp ->siguiente;
    		
    		if(temp->dato==valor){
    			eliminarInicio();
    			insertarInicio(ingreso);
    	//		cout<<"segundo if\n";
			}else if (cola->dato == valor){
		//		cout<<"Tercero if\n";
				eliminarFinal();
				insertarFinal(ingreso);				
			}else{
	    		while(temp != NULL){
	    //			cout<<"While\n";
	    			if(temp->dato==valor){
	    //				cout<<"Ultimo if \n";
	    //				cout<<"Valor encontrado \n";
						aux = temp;
											
						aux->anterior->siguiente=aux->siguiente;
	                	aux->siguiente->anterior=aux->anterior;
	                	temp = temp ->siguiente;
	                	delete aux;
	                	//pos = temp->anterior;
	                	pos = temp;
	                	pos->anterior->siguiente = n;
		                n->anterior = pos->anterior;
	    	            n->siguiente=pos;
	        	        pos->anterior=n;
	
				
					}else{
						temp = temp ->siguiente;
						
					}	    			
	            
	        	}
	    	}
					
		}
        cout << endl;
    }

   
};

class Practica1{
	public:
		string txt, b;
		char tx[100];
		ListaDoble listaD;
		ListaDoble listaBuscar;
		ListaDoble listaRemplazar;
		ListaDoble listaNuevo;
		ListaDoble listaArchivo;
		
		Pila pilaOriginal;
		Pila pilaNuevo;
		
	
		
		
		
		void buscarR(string prueba){
			string buscar;
			string remplazar;
			string f="",c="",d="",e="";
			int a=0;
			//cin.ignore();	
			string aux;
			
			for(int i=0; i<prueba.size(); i++){
		        aux = aux + prueba[i]; 
		        //listaDoblePalabra.imprimir();
		        if(prueba[i]== ';' || prueba[i]=='.'){
		        	//listaDoblePalabra.insertarFinal(aux);
					size_t tam = aux.length();		        	
					aux.erase(tam-1);
					if(a==0){
						buscar = aux;
						a++;
					}else
						remplazar = aux;     	
		        	aux = "";
				}
				//listaDoblePalabra.imprimir();
	    	}
	    	//cout<<buscar<<endl<<remplazar<<endl;
	    	
	    	
	    	/*listaBuscar.imprimir();
	    	listaRemplazar.imprimir();
	    	//cout<<buscar<<","<<remplazar<<endl;
	    	*/
	    	//listaBuscar.reporteLetras();
	    	listaNuevo.buscar(buscar, remplazar);
	    	//cout<< listaNuevo.getDato()<<endl<<listaNuevo.getTamanio()<<endl;
	    	b = listaNuevo.getDato();
	    	listaNuevo.~ListaDoble();
	    	//cout<<b;
	    	a=0;
			//listaBuscar.~ListaDoble();
			for(int i =0; i<buscar.size();i++){
	    		string aux;
		        aux += buscar[i]; 
		        listaBuscar.insertarFinal(aux);    
		        aux="";
			}
			for(int i =0; i<remplazar.size();i++){
	    		string aux;
		        aux += remplazar[i]; 
		        listaRemplazar.insertarFinal(aux);
		        aux="";
			}
			for(int i=0; i<b.size();i++){
				string aux;
		        aux += b[i]; 
		        listaNuevo.insertarFinal(aux);
		        aux="";
			}
			//b="";
			
			//listaNuevo.imprimir();
			listaNuevo.reporteLetras();
			pilaNuevo.push(buscar, remplazar);
			pilaNuevo.reportePilaLog();
			//listaBuscar.reporteLetras();
			//listaRemplazar.reporteLetras();
			crearArchivo();
			
		}
		
		void separarLetras(string cadena){
			//listaD.~ListaDoble();
			string aux1;
			string help;
			for(int i=0; i<cadena.size(); i++){
				string aux;
			    aux1 = aux1 + cadena[i];  
			    aux += cadena[i];
				if(cadena[i]!= '-' ){
					if(cadena[i]!='.'){
						if(cadena[i]!=' ')
							listaD.insertarFinal(aux);
					}
			       			
			    }//aux="";
		    	
		        aux="";
		        if(cadena[i]== '-' || cadena[i]=='.' || cadena[i]==' '){
		        	//listaDoblePalabra.insertarFinal(aux);
					size_t tam = aux1.length();		        	
					aux1.erase(tam-1);
					listaNuevo.insertarFinal(aux1);
					help += aux1 + " ";
					
		        	aux1 = "";
				}
	    	}
	    	//cout<<help;
	    	//listaD.imprimir();
	    	
	    	listaD.reporteLetras();
			crearArchivo();		
		}
		
		void reporteArchivos(){
			system("cls");
			listaArchivo.imprimir();
			char leer;
			//listaArchivo.insertarFinal(nombreF);
			cout<<"Desea generar la grafica? [s/n]"<<endl;
			cin>>leer;
			if(leer=='s' || leer=='S'){
				listaArchivo.reporteArchivosR();
				system("pause");
				menu();
			}else{
				menu();
			}
			
			
		}
		void lecturaFichero(){
			cout<<"Lista de Archivos Disponibles"<<endl;
			listaArchivo.imprimir();
			char nombreFichero [50];
			cout<<"Ingrese el nombre del archivo a leer:\n";
			cin>>nombreFichero;		
			FILE *archivo;
 	
		 	char caracteres[100];
		 	
		 	archivo = fopen(nombreFichero,"r");
		 	
		 	if (archivo == NULL)
		 		exit(1);
		 	else
		        {
		 	    printf("\nEl contenido del archivo de prueba es \n\n");
		 	    while (feof(archivo) == 0)
		 	    {
		 		fgets(caracteres,100,archivo);
		 		printf("%s",caracteres);
		 		cout<<endl;
		 	    }
		 	    	cout<<endl;
		            system("PAUSE");
		        }
		        fclose(archivo);
		        menu();
		        crearArchivo();
			//return 0;
			
		}
		
		void escrituraFichero(string guardar){
			FILE *fp;
			string auxEscritura;
			char nombreFichero [50];
			cout<<"Ingrese el nombre del archivo a guardar:\n";
			cin>>nombreFichero;
			auxEscritura = nombreFichero;
			fp = fopen ( nombreFichero, "w+" );
			int tam = 0;
			string auxiliar = "";
			char charAux [tam+1];
			auxiliar = guardar;
			tam = auxiliar.size();
			for(int i=0;i<tam;i++){
				printf("%c", fputc(auxiliar[i], fp));		
				//auxEscritura += auxiliar[i];
			}
			
			fclose(fp);
			//reporteArchivos(auxEscritura);
			listaArchivo.insertarFinal(auxEscritura);
			crearArchivo();
			    
		}
		
		void crearArchivo(){
			system("cls");
			
			char tecla;
			string prueba;
			cout<<"^w (Buscar y Remplazar)  	^c(Reportes)	^s(Guardar)"<<endl;
			if(b==""){
				cout<<txt<<endl;
			}else{
				cout<<b<<endl;
				//b="";	
			}
			//b="";
			
			
			cin>>txt;
			cin.ignore();
			/*for(int i=0; i<tx.size();i++){
				txt+=tx;
			}*/
			//cin>>txt;
		//	getline(cin, txt);
			while(tecla!=27){
				
		        tecla=getch();
		        if(tecla==0)
		        {
		            tecla=getch();
		        }
		        else
		        {
		            switch(tecla)
		            {
		        case 23:
		            //cout<<"Presiono ctrl-w"<<endl;
		            
			
					cout<<"Ingrese las palabras: "<<endl;
					cin>>prueba;
		           	buscarR(prueba);
		           	
		            
		            break;
		        case 3:
		            //cout<<"Presiono ctrl-c"<<endl;
		            //cout<<txt<<endl;
		            separarLetras(txt);
		            //crearArchivo();
		            //lista->graphList();
		            break;
		        case 19:
		            //cout<<"Presiono ctrl-s"<<endl;
		            escrituraFichero(txt);
		            //crearArchivo();
		            
		            
		            
		            break;
		        case 8:
		            //cout<<"Presiono retroceso"<<endl;
		            cout<<tecla;
		            break;
		        case 48:
		            //cout<<"Presiono el 0"<<endl;
		            break;
		        case 32:
		            //cout<<"Barra Espaciadora"<<endl;
		            break;
		        case 31:
		            //cout<<"Presiono suprimir"<<endl;
		            break;
		        case 24:
		            //cout<<"Presiono ctrl-x"<<endl;
		            menu();
		            break;
		        default:
		            cout<<"No existe esa opcion"<<endl;
		            }
		        }
   			 }	
			
			
			
		}
	
		void menu(){
		    int opcion;
		    //string bla="blabla :"; 
		    system("cls");
		    cout<<"\n"<<"UNIVERSIDAD DE SAN CARLOS DE GUATEMALA"<<endl 
		    << "FACULTAD DE INGENIERIA \n" << "ESTRUCTURA DE DATOS"<<endl
		    << "PRACTICA 1\n" << "STEVEN MIGUELANGEL CAJCHUM CUJCUJ"<<endl
		    << "201603150"<< endl << "\n" <<endl;     
		    cout<<"MENU:"<< endl <<"1. Crear archivo"<< endl << "2. Abrir Archivo"<<endl
		    << "3. Archivos Recientes"<< endl << "4. Salir"<<endl;
		    cin>>opcion;
		   // if(opcion==1 || opcion==2 || opcion==3 || opcion==4){
		        switch (opcion)
		        {
		        case 1: 
					
		         	crearArchivo();
		
		            break;
		        case 2:
		            lecturaFichero();
		            crearArchivo();
		            break;
		        case 3:
		            reporteArchivos();
		            crearArchivo();
		            break;
		        case 4:
		            system("exit");
		            break;
		        default:
		        	cout<<"No existe esa opcion"<<endl;
		            
		        }
		        
		    /*}else{
		        cout<<"Opcion invalida\n";
		        menu();
		    }*/
		}
	
	
			
};

int main (){
	Practica1 practica;
	practica.menu();
	return 0;
}
