#include "Usuario.h"
#include <string>
#include <sstream>
using std::stringstream;
using std::string;

Usuario::Usuario(){

}

Usuario::~Usuario() {

}

Usuario::Usuario(string nombre, string password, string email){
	this->nombre = nombre;
	this->password = password;
	this->email = email;
	
}

void Usuario::setNombre(string nombre2){
  nombre = nombre2;
}

string Usuario::getNombre(){
  return nombre;
}

void Usuario::setEmail(string email2){
  email = email2;
}

string Usuario::getEmail(){
  return email;
}

void Usuario::setPassword(string pass){
  password = pass;
}

int Usuario::getPassword(){
  return password;
}

string Usuario::toString(){
	stringstream ss;
	ss<<"Nombre: "<<nombre<<" Password: "<<numero<<" Correo: "<<email;
	return ss.str();
}