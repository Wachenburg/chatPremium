#include "Criptografador.h"
/*
    Esta classe e a responsavel atual por criptografar mensagens. Ela altera valores de string pelo metodo zenit polar (troca de caracteres).
    No futuro, a intencao e trocar este metodo por um jwt
*/
string Criptografador::criptografa(string _texto)
{
    //zenit
    //polar
    string criptografa = _texto;
    bool troca;
    for (int i = 0; i < criptografa.size(); i++) {
        troca = false;
        if (criptografa[i] == 'p' && troca != true) {
            criptografa[i] = 'z';
            troca = true;
        }
        if (criptografa[i] == 'o' && troca != true) {
            criptografa[i] = 'e';
            troca = true;
        }
        if (criptografa[i] == 'l' && troca != true) {
            criptografa[i] = 'n';
            troca = true;
        }
        if (criptografa[i] == 'a' && troca != true) {
            criptografa[i] = 'i';
            troca = true;
        }
        if (criptografa[i] == 'r' && troca != true) {
            criptografa[i] = 't';
            troca = true;
        }
        ////
        if (criptografa[i] == 'z' && troca != true) {
            criptografa[i] = 'p';
            troca = true;
        }
        if (criptografa[i] == 'e' && troca != true) {
            criptografa[i] = 'o';
            troca = true;
        }
        if (criptografa[i] == 'n' && troca != true) {
            criptografa[i] = 'l';
            troca = true;
        }
        if (criptografa[i] == 'i' && troca != true) {
            criptografa[i] = 'a';
            troca = true;
        }
        if (criptografa[i] == 't' && troca != true) {
            criptografa[i] = 'r';
            troca = true;
        }
    }
    return criptografa;
}

string Criptografador::decriptografa(string _texto)
{
    //polar
    //zenit
    string descriptografa = _texto;
    bool troca;
    for (int i = 0; i < descriptografa.size(); i++) {
        troca = false;
        if (descriptografa[i] == 'p' && troca != true) {
            descriptografa[i] = 'z';
            troca = true;
        }
        if (descriptografa[i] == 'o' && troca != true) {
            descriptografa[i] = 'e';
            troca = true;
        }
        if (descriptografa[i] == 'l' && troca != true) {
            descriptografa[i] = 'n';
            troca = true;
        }
        if (descriptografa[i] == 'a' && troca != true) {
            descriptografa[i] = 'i';
            troca = true;
        }
        if (descriptografa[i] == 'r' && troca != true) {
            descriptografa[i] = 't';
            troca = true;
        }
        ////
        if (descriptografa[i] == 'z' && troca != true) {
            descriptografa[i] = 'p';
            troca = true;
        }
        if (descriptografa[i] == 'e' && troca != true) {
            descriptografa[i] = 'o';
            troca = true;
        }
        if (descriptografa[i] == 'n' && troca != true) {
            descriptografa[i] = 'l';
            troca = true;
        }
        if (descriptografa[i] == 'i' && troca != true) {
            descriptografa[i] = 'a';
            troca = true;
        }
        if (descriptografa[i] == 't' && troca != true) {
            descriptografa[i] = 'r';
            troca = true;
        }
    }
    return descriptografa;
}
