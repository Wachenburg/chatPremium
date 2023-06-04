#pragma once
#include "Libs.cpp";

class Mensagem {
private:
	int idMensagem;
	int idPosta;
	int idGrupo;
	string mensagem;
public:
	Mensagem();
	Mensagem(int _idMensagem,int _idPosta, int _idGrupo, string _mensagem);
	void setIdMensagem(int _idMensagem);
	void setIdPosta(int _idPosta);
	void setIdGrupo(int _idGrupo);
	void setMensagem(string mensagem);
	int getIdMensagem();
	int getIdPosta();
	int getIdGrupo();
	string getMensagem();
};
