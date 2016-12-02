#ifndef INTERNO_H
#define  INTERNO_H
#include <string>
#include "Usuario.h"

using std::string;

class Interno : public Usuario {
    private:
    	int dias;
    public:
        Interno();
        Interno(string,string,string,int);
        void setDias(int);
		int getDias();
		string toString();
};

#endif