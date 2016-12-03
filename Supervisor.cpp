#include <string>
#include <sstream>
#include "Supervisor.h"

using std::stringstream;
using std::string;

Supervisor::Supervisor() : Usuario(){
    
}

Supervisor::Supervisor(string nombre,string password, string email, int ingresos) : Usuario(nombre,email,password),ingresos(ingresos){
    
}

void Supervisor::setIngresos(int ingresos2){
  ingresos = ingresos2;
}

int Supervisor::getIngresos(){
  return ingresos;
}

string Supervisor::toString(){
	stringstream ss;
	ss<<nombre<<" "<<password<<" "<<email<<" "<<ingresos;
	return ss.str();
}