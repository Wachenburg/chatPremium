#pragma once
#include "Libs.cpp";

class Grupo {
private:
	int idGrupo;
	string nomeGrupo;
	string grupoSecret;
	int tipoGrupo;

public:
	Grupo();
	Grupo(string _nomeGrupo, string _grupoSecret, int tipoGrupo);
	void setNomeGrupo(string _nomeGrupo);
	void setGrupoSecret(string _grupoSecret);
	void setTipoGrupo(int _tipoGrupo);
	int getIdGrupo();
	string getNomeGrupo();
	string getGrupoSecret();
	int getTipoGrupo();

};
