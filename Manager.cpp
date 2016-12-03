#include <string>
#include <sstream>
#include "Manager.h"

using std::stringstream;
using std::string;

Manager::Manager() : Usuario(){
    
}

Manager::Manager(string nombre,string password, string email, string sueldo) : Usuario(nombre,email,password),sueldo(sueldo){
    
}

void Manager::setSueldo(string sueldo2){
  sueldo = sueldo2;
}

string Manager::getSueldo(){
  return sueldo;
}

string Manager::toString(){
	stringstream ss;
	ss<<nombre<<" "<<password<<" "<<email<<" "<<sueldo;
	return ss.str();
}