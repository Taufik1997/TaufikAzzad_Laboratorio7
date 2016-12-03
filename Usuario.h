#ifndef USUARIO_H
#define USUARIO_H 
#include <string>

using std::string;

class Usuario{
private:
	
public:
	string nombre;
	string password;
	string email;
	Usuario(string,string,string);
	Usuario();
	virtual ~Usuario();
	void setNombre(string);
	string getNombre();
	void setPassword(string);
	string getPassword();
	void setEmail(string);
	string getEmail();
	string toString();
};

#endif