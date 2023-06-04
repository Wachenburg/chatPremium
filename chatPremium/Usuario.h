#pragma once
#include"Libs.cpp"

class Usuario {
private:
    int idUsuario;
    string nomeUsuario;
    string senha;
    string nomePessoa;
    string hexUsuario;
public:
    Usuario();
    Usuario(int _idUsuario, string _nomeUsuario, string _senha, string _nomePessoa, string _hexUsuario);
    void setIdUsuario(int _idUsuario);
    void setNomeUsuario(string _nomeUsuario);
    void setSenha(string _senha);
    void setNomePessoa(string _nomePessoa);
    void setHexUsuario(string _hex);
    int getIdUsuario();
    string getNomeUsuario();
    string getSenha();
    string getNomePessoa();
    string getHexUsuario();
};
