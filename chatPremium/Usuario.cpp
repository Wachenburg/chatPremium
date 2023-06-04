#include "Usuario.h"

Usuario::Usuario()
{
	this->idUsuario = 0;
	this->nomeUsuario = "";
	this->senha = "";
	this->nomePessoa = "";
	this->hexUsuario = "";
}
Usuario::Usuario(int _idUsuario, string _nomeUsuario, string _senha, string _nomePessoa, string _hexUsuario) {
	this->idUsuario = _idUsuario;
	this->nomeUsuario = _nomeUsuario;
	this->senha = _senha;
	this->nomePessoa = _nomePessoa;
	this->hexUsuario = _hexUsuario;
}
void Usuario::setIdUsuario(int _idUsuario) {
	this->idUsuario = _idUsuario;
}

void Usuario::setNomeUsuario(string _nomeUsuario) {
	this->nomeUsuario = _nomeUsuario;
}
void Usuario::setSenha(string _senha) {
	this->senha = _senha;
}
void Usuario::setNomePessoa(string _nomePessoa) {
	this->nomePessoa = _nomePessoa;
}
void Usuario::setHexUsuario(string _hexUsuario) {
	this->hexUsuario = _hexUsuario;
}
int Usuario::getIdUsuario() {
	return this->idUsuario;
}
string Usuario::getNomeUsuario() {
	return this->nomeUsuario;
}
string Usuario::getSenha() {
	return this->senha;
}
string Usuario::getNomePessoa() {
	return this->nomePessoa;
}
string Usuario::getHexUsuario() {
	return this->hexUsuario;
}

