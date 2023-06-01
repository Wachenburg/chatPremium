#pragma once
class UsuarioGrupoMensagem {
private:
	int idUsuario;
	int idGrupo;
	int idMensagem;
public:
	UsuarioGrupoMensagem();
	UsuarioGrupoMensagem(int _idUsuario, int _idGrupo, int _idMensagem);
	void setIdUsuario(int _idUsuario);
	void setIdGrupo(int _idGrupo);
	void setIdMensagem(int _idMensagem);
	int getIdUsuario();
	int getIdGrupo();
	int getIdMensagem();
};