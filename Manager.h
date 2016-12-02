#ifndef MANAGER_H
#define  MANAGER_H
#include <string>
#include "Usuario.h"

using std::string;

class Manager : public Usuario {
    private:
    	int sueldo;
    public:
        Manager();
        Manager(string,string,string,int);
        void setSueldo(int);
		int getSueldo();
		string toString();
};

#endif