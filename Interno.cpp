#include <string>
#include <sstream>
#include "Interno.h"

using std::stringstream;
using std::string;

Interno::Interno() : Usuario(){
    
}

Interno::Interno(string nombre,string password, string email, int dias) : Usuario(nombre,email,password),dias(dias){
    
}

void Interno::setDias(int dias2){
  dias = dias2;
}

int Interno::getDias(){
  return dias;
}

string Interno::toString(){
	stringstream ss;
	ss<<dias;
	return ss.str();
}