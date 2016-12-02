#include <iostream>
#include <vector>
#include "Usuario.h"
#include "Supervisor.h"
#include "Administrador.h"
#include "Manager.h"
#include "Interno.h"
#include <fstream>
#include <string>

using namespace std;

int main(){
	vector<Usuario*> usuarios;
	contactos.push_back(new Administrador("Admin", "123","Admin@gmail.com", "01/12/16"));
	
	int opcion = 0;
	do{
		cout<<"     Administracion\n1)Agrergar\n2)Eliminar\n3)Listar con Categoria\n4)Salir\n";
		cin>>opcion;
		switch(opcion){
			case 1:{

				break;				
			}
			case 2:{
				
				break;
			}
			case 3:{
				

				break;
			}
		}//Fin Switch 
	}while(opcion>=0 && opcion <=3);//Fin do while
	return 0;
}