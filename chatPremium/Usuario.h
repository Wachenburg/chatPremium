#pragma once
#include"Libs.h"
using namespace std;
class Usuario {
private:
    string nome;
    string senha;
public:
    //Usuario();
    Usuario(string _nome, string _senha) {
        nome = _nome;
        senha = _senha;
    };
    void setNome(string _nome){
        nome = _nome;
    }
    void setSenha(string _senha){
        senha = _senha;
    }
    string getNome() {
        return nome;
    }
    string getSenha() {
        return senha;
    }

};