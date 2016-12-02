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

	vector<Supervisor*> supervisores;
	vector<Interno*> internos;
	vector<Manager*> managers;

	/*
	string line;
	ifstream myfile ("Usuarios.txt");
	if (myfile.is_open())
	{
		while (getline(myfile,line))
		{
			supervisores.push_back(new Supervisor())
		}
		myfile.close();
	}

	else cout << "Unable to open file"; 
	*/



	new Administrador("Admin", "123","Admin@gmail.com", "01/12/16");
	int option = 0;
	do{
		cout<<"     Bienvenido\n1)Log in\n2)Salir\n";
		cin>>option;
		if(option == 1){
			bool usuarioValidado = false;
			string usuario, pass;
			cout<<"Ingrese su nombre de usuario:";
			cin>>usuario;
			cout<<"Contraseña:";
			cin>>pass;
			int opcion = 0;
			bool admin = false, super = false, intern = false, manager = false;

			if(usuario == "Admin" && pass == "123"){
				admin = true;
			}	
			for (int i = 0; i < internos.size(); ++i)
			{
				if(internos.at(i)->getNombre() == usuario && internos.at(i)->getPassword() == pass){
					usuarioValidado = true;
					intern = true;
				}
			}
			for (int i = 0; i < supervisores.size(); ++i)
			{
				if(supervisores.at(i)->getNombre() == usuario && supervisores.at(i)->getPassword() == pass){
					usuarioValidado = true;
					super = true;
				}
			}
			for (int i = 0; i < managers.size(); ++i)
			{
				if(managers.at(i)->getNombre() == usuario && managers.at(i)->getPassword() == pass){
					usuarioValidado = true;
					manager = true;
				}
			}


			if(usuarioValidado){
				do{ 
				cout<<"     Administracion\n1)Internos\n2)Managers\n3)Supervisores\n4)Salir\n";
				cin>>opcion;
				switch(opcion){
					case 1:{

						int opt;
						cout<<"    Internos \n1)Crear\n2)Eliminar\n3)Listar\n4)Salir\n";
						cin>>opt;
						if(opt == 1){
							if(admin || super){
								string nombre, password, mail;
								int dias;
								cout<<"Ingrese el nombre:";
								cin>>nombre;
								cout<<"Ingrese la contraseña:";
								cin>>password;
								cout<<"Ingrese el corre:";
								cin>>mail;
								cout<<"Ingrese los dias trabajados:";
								cin>>dias;
								internos.push_back(new Interno(nombre, password, mail, dias));
							}
						}
						if(opt == 2){
							if(admin || super){

							}
						}
						if(opt == 3){

						}


						break;				
					}
					case 2:{
						int opt;
						cout<<"    Managers \n1)Crear\n2)Eliminar\n3)Listar\n4)Salir\n";
						cin>>opt;
						if(opt == 1){
							if(admin || super){

							}
						}
						if(opt == 2){
							if(admin || super){

							}
						}
						if(opt == 3){

						}


						break;
					}
					case 3:{
						int opt;
						cout<<"    Supervisores \n1)Crear\n2)Eliminar\n3)Listar\n4)Salir\n";
						cin>>opt;
						if(opt == 1){
							if(admin || super){

							}
						}
						if(opt == 2){
							if(admin || super){

							}
						}
						if(opt == 3){

						}

						break;
					}
				}//Fin Switch 
				}while(opcion>=0 && opcion <=3);//Fin do while
			}

		}//if de Administracion
	}while(option != 1);//Fin main do while
	
	return 0;
}

