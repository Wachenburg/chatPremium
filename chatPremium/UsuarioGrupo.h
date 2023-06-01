#pragma once
#include "libs.cpp";

class UsuarioGrupo {
private:
	int idUsuario;
	int idGrupo;
public:
	UsuarioGrupo();
	UsuarioGrupo(int _idUsuario, int _idGrupo);
	void setIdUsuario(int _idUsuario);
	void setIdGrupo(int _idGrupo);
	int getIdUsuario();
	int getIdGrupo();

};