#include "Mensagem.h"

Mensagem::Mensagem()
{
	this->idMensagem = 0;
	this->idPosta = 0;
	this->idGrupo = 0;
	this->mensagem = "";
}
Mensagem::Mensagem(int _idMensagem,int _idPosta, int _idGrupo, string _mensagem) {
	this->idMensagem = _idMensagem;
	this->idPosta = _idPosta;
	this->idGrupo = _idGrupo;
	this->mensagem = _mensagem;
}

void Mensagem::setIdMensagem(int _idMensagem) {
	this->idMensagem = _idMensagem;
}

void Mensagem::setIdPosta(int _idPosta)
{
	this->idPosta = _idPosta;
}

void Mensagem::setIdGrupo(int _idGrupo)
{
	this->idGrupo = _idGrupo;
}

void Mensagem::setMensagem(string mensagem)
{
	this->mensagem = mensagem;
}

int Mensagem::getIdMensagem()
{
	return this->idMensagem;
}

int Mensagem::getIdPosta()
{
	return this->idPosta;
}

int Mensagem::getIdGrupo()
{
	return this->idGrupo;
}

string Mensagem::getMensagem()
{
	return this->mensagem;
}

