#include <string>
#include <sstream>
#include "Administrador.h"

using std::stringstream;
using std::string;

Administrador::Administrador() : Usuario(){
    
}

Administrador::Administrador(string nombre,string email, string password, string fecha) : Usuario(nombre,email,password),fecha(fecha){
    
}

void Administrador::setFecha(string fecha2){
  fecha = fecha2;
}

string Administrador::getFecha(){
  return fecha;
}

string Administrador::toString(){
	stringstream ss;
	ss<<fecha;
	return ss.str();
}