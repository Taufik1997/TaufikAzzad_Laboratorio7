#ifndef SUPERVISOR_H
#define  SUPERVISOR_H
#include <string>
#include "Usuario.h"

using std::string;

class Supervisor : public Usuario {
    private:
    	int ingresos;
    public:
        Supervisor();
        Supervisor(string,string,string,int);
        void setIngresos(int);
		int getIngresos();
		string toString();
};

#endif