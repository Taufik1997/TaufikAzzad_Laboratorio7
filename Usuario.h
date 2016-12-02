#ifndef USUARIO_H
#define USUARIO_H 
#include <string>

using std::string;

class Usuario{
private:
	string nombre;
	string password;
	string email;
public:
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