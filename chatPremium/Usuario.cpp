#include "Usuario.h"

Usuario::Usuario()
{
	this->nomeUsuario = "";
	this->senha = "";
	this->nomePessoa = "";
	this->hexUsuario = "";
}
Usuario::Usuario(string _nomeUsuario, string _senha, string _nomePessoa, string _hexUsuario) {
	this->nomeUsuario = _nomeUsuario;
	this->senha = _senha;
	this->nomePessoa = _nomePessoa;
	this->hexUsuario = _hexUsuario;
}

void Usuario::setNomeUsuario(string _nomeUsuario) {
	this->nomeUsuario = _nomeUsuario;
}
void Usuario::setSenha(string _senha) {
	this->senha = _senha;
}
string Usuario::getNomeUsuario() {
	return this->nomeUsuario;
}
string Usuario::getSenha() {
	return this->senha;
}
