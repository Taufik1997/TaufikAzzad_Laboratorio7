#include <string>
#include <sstream>
#include "Administrador.h"

using std::stringstream;
using std::string;

Administrador::Administrador() : Contacto(){
    
}

Administrador::Administrador(string nombre,string email, string password, string fecha) : Usuario(nombre,email,password),fecha(fecha){
    
}

void Administrador::setFecha(string fecha2){
  fecha = fecha2;
}

string fecha::getFecha(){
  return fecha;
}

string Administrador::toString(){
	stringstream ss;
	ss<<fecha;
	return ss.str();
}