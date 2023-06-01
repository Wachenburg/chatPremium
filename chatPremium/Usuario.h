#pragma once
#include"Libs.cpp"

class Usuario {
private:
    int id;
    string nomeUsuario;
    string senha;
    string nomePessoa;
    string hexUsuario;
public:
    Usuario();
    Usuario(string _nomeUsuario, string _senha, string _nomePessoa, string _hexUsuario);
    void setNomeUsuario(string _nomeUsuario);
    void setSenha(string _senha);
    void setNomePessoa(string _nomePessoa);
    void setHexUsuario(string _hex);
    string getId();
    string getNomeUsuario();
    string getSenha();
    string getNomePessoa();
    string getHexUsuario();
};
