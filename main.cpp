#include <iostream>
#include <vector>
#include "Usuario.h"
#include "Supervisor.h"
#include "Administrador.h"
#include "Manager.h"
#include "Interno.h"
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){

	vector<Supervisor*> supervisores;
	vector<Interno*> internos;
	vector<Manager*> managers;

	string name,passw, email, other;
	ifstream man;
	man.open("Managers.txt");
	while(!man.eof()){
		getline(man,name,' ');
		getline(man,passw,' ');
		getline(man,email,' ');
		getline(man,other,' ');
		managers.push_back(new Manager(name,passw,email,other));
	} 

	ifstream super;
	super.open("Supervisores.txt");
	while(!super.eof()){
		getline(super,name,' ');
		getline(super,passw,' ');
		getline(super,email,' ');
		getline(super,other,' ');
		supervisores.push_back(new Supervisor(name,passw,email,atoi(other.c_str())));
	} 

	ifstream inter;
	inter.open("Internos.txt");
	while(!inter.eof()){
		getline(inter,name,' ');
		getline(inter,passw,' ');
		getline(inter,email,' ');
		getline(inter,other,' ');
		internos.push_back(new Interno(name,passw,email,atoi(other.c_str())));
	} 
	



	new Administrador("Admin", "123","Admin@gmail.com", "01/12/16");
	int option = 0;
	do{
		option = 0;
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
				usuarioValidado = true;
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
					supervisores.at(i)->setIngresos(supervisores.at(i)->getIngresos() + 1);
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
							if(admin || manager){
								string nombre, password, mail;
								int dias;
								cout<<"Ingrese el nombre:";
								cin>>nombre;
								bool valid = false;
								do{
									cout<<"Ingrese la contraseña:";
									cin>>password;
									if(password.size() > 8){
										valid = true;
									}else{
										cout<<"La contraseña tiene que tener mas dew 8 caracteres."<<endl;
									}
								}while(!valid);
								cout<<"Ingrese el corre:";
								cin>>mail;
								cout<<"Ingrese los dias trabajados:";
								cin>>dias;
								internos.push_back(new Interno(nombre, password, mail, dias));
							}else{
								cout<<"Nesesita ser o administrador o manager para ingresar a esta opcion";
							}
						}
						if(opt == 2){
							if(admin || manager){
								int num;
								cout<<"Ingrese la posicion de el interno que desea borrar:";
								cin>>num;
								internos.erase(internos.begin()+num);
							}else{
								cout<<"Nesesita ser o administrador o manager para ingresar a esta opcion";
							}
						}
						if(opt == 3){
							for (int i = 0; i <internos.size(); ++i)
								{
									cout<< i<<"-"<<internos.at(i)->toString()<<endl;
								}
						}
						break;				
					}
					case 2:{
						int opt;
						cout<<"    Managers \n1)Crear\n2)Eliminar\n3)Listar\n4)Salir\n";
						cin>>opt;
						if(opt == 1){
						if(admin){
								string nombre, password, mail;
								string sueldo;
								cout<<"Ingrese el nombre:";
								cin>>nombre;
								bool valid = false;
								do{
									cout<<"Ingrese la contraseña:";
									cin>>password;
									if(password.size() > 16){
										valid = true;
									}else{
										cout<<"La contraseña tiene que tener mas dew 16 caracteres."<<endl;
									}
								}while(!valid);
								cout<<"Ingrese el corre:";
								cin>>mail;
								cout<<"Ingrese el sueldo:";
								cin>>sueldo;
								managers.push_back(new Manager(nombre, password, mail, sueldo));
							}else{
								cout<<"Nesesita ser o administrador o manager para ingresar a esta opcion";
							}
						}
						if(opt == 2){
							if(admin || manager){
								int num;
								cout<<"Ingrese la posicion de el managers que desea borrar:";
								cin>>num;
								managers.erase(managers.begin()+num);
							}else{
								cout<<"Nesesita ser o administrador o manager para ingresar a esta opcion";
							}
						}
						if(opt == 3){
							if(intern){
								cout<<"Un interno no puedo ingresar a esta opcion";
							}else{
								for (int i = 0; i < managers.size(); ++i)
								{
									cout<< i<<"-"<<managers.at(i)->toString()<<endl;
								}
							}
						}


						break;
					}
					case 3:{
						int opt;
						cout<<"    Supervisores \n1)Crear\n2)Eliminar\n3)Listar\n4)Salir\n";
						cin>>opt;
						if(opt == 1){
							if(admin || manager){
								string nombre, password, mail;
								int dias;
								cout<<"Ingrese el nombre:";
								cin>>nombre;
								bool valid = false;
								do{
									cout<<"Ingrese la contraseña:";
									cin>>password;
									if(password.size() > 8){
										valid = true;
									}else{
										cout<<"La contraseña tiene que tener mas dew 8 caracteres."<<endl;
									}
								}while(!valid);								
								cout<<"Ingrese el corre:";
								cin>>mail;
								supervisores.push_back(new Supervisor(nombre, password, mail, 0));
							}else{
								cout<<"Nesesita ser o administrador o manager para ingresar a esta opcion";
							}
						}
						if(opt == 2){
							if(admin || manager){
								int num;
								cout<<"Ingrese la posicion de el supervisor que desea borrar:";
								cin>>num;
								supervisores.erase(supervisores.begin()+num);
							}else{
								cout<<"Nesesita ser o administrador o manager para ingresar a esta opcion";
							}
						}
						if(opt == 3){
							if(intern){
								cout<<"Un interno no puedo ingresar a esta opcion";
							}else{
								for (int i = 0; i < supervisores.size(); ++i)
								{
									cout<< i<<"-"<<supervisores.at(i)->toString()<<endl;
								}
							}
						}

						break;
					}
				}//Fin Switch 
				}while(opcion>=0 && opcion <=3);//Fin do while
			}

		}//if de Administracion
	}while(option == 1);//Fin main do while
	ofstream file;
	file.open("Supervisores.txt");
	for (int i = 0; i < supervisores.size(); ++i)
		{
			file<<supervisores.at(i)->toString()<<endl;
		}
	file.close();

	ofstream file1;
	file.open("Internos.txt");
	for (int i = 0; i < internos.size(); ++i)
		{
			file1<<internos.at(i)->toString()<<endl;
		}
	file1.close();

	ofstream file2;
	file2.open("Managers.txt");
	for (int i = 0; i < managers.size(); ++i)
		{
			file2<<managers.at(i)->toString()<<endl;
		}
	file2.close();
	return 0;
}
