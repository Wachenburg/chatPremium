#include "UsuarioGrupo.h"

UsuarioGrupo::UsuarioGrupo()
{
	this->idUsuario = 0;
	this->idGrupo = 0;
}

UsuarioGrupo::UsuarioGrupo(int _idUsuario, int _idGrupo)
{
	this->idUsuario = _idUsuario;
	this->idGrupo = _idGrupo;
}

void UsuarioGrupo::setIdUsuario(int _idUsuario)
{
	this->idUsuario = _idUsuario;
}

void UsuarioGrupo::setIdGrupo(int _idGrupo)
{
	this->idGrupo = _idGrupo;
}

int UsuarioGrupo::getIdUsuario()
{
	return this->idUsuario;
}

int UsuarioGrupo::getIdGrupo()
{
	return this->idGrupo;
}
