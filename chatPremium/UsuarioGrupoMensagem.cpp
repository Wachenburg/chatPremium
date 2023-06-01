#include "UsuarioGrupoMensagem.h"

UsuarioGrupoMensagem::UsuarioGrupoMensagem()
{
	this->idUsuario = 0;
	this->idGrupo = 0;
	this->idMensagem = 0;
}

UsuarioGrupoMensagem::UsuarioGrupoMensagem(int _idUsuario, int _idGrupo, int _idMensagem)
{
	this->idUsuario = _idUsuario;
	this->idGrupo = _idGrupo;
	this->idMensagem = _idMensagem;
}

void UsuarioGrupoMensagem::setIdUsuario(int _idUsuario)
{
	this->idUsuario = _idUsuario;
}

void UsuarioGrupoMensagem::setIdGrupo(int _idGrupo)
{
	this->idGrupo = _idGrupo;
}

void UsuarioGrupoMensagem::setIdMensagem(int _idMensagem)
{
	this->idMensagem = _idMensagem;
}

int UsuarioGrupoMensagem::getIdUsuario()
{
	return this->idUsuario;
}

int UsuarioGrupoMensagem::getIdGrupo()
{
	return this->idGrupo;
}

int UsuarioGrupoMensagem::getIdMensagem()
{
	return this->idMensagem;
}
