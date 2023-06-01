#include "Grupo.h"

Grupo::Grupo()
{
	this->nomeGrupo = " ";
	this->grupoSecret = " ";
	this->tipoGrupo = 0;

}
Grupo::Grupo(string _nomeGrupo, string _grupoSecret, int _tipoGrupo) {
	this->nomeGrupo = _nomeGrupo;
	this->grupoSecret = _grupoSecret;
	this->tipoGrupo = _tipoGrupo;
}
void Grupo::setNomeGrupo(string _nomeGrupo) {
	this->nomeGrupo = _nomeGrupo;
}
void Grupo::setGrupoSecret(string _grupoSecret) {
	this->grupoSecret = _grupoSecret;
}
void Grupo::setTipoGrupo(int _tipoGrupo) {
	this->tipoGrupo = _tipoGrupo;
}
int Grupo::getIdGrupo() {
	return this->idGrupo;
}
string Grupo::getNomeGrupo() {
	return this->nomeGrupo;
}
string Grupo::getGrupoSecret() {
	return this->grupoSecret;
}
int Grupo::getTipoGrupo() {
	return this->tipoGrupo;
}
