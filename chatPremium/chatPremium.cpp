// chatPremium.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "Libs.cpp";
#include "Usuario.h";
#include "Grupo.h";
#include "Mensagem.h";
#include "UsuarioGrupo.h";
int main() {
    string nomegrupo, msg, nomecontato;
    int op, tipo, qntdcontato, usuarioAtual, idGrupoEnvia;
    string nome, senha;
    
    vector <Usuario> usuario;
    vector <Grupo> grupo;
    vector <Mensagem> mensagem; 
    vector <UsuarioGrupo> usuarioGrupo;
    Mensagem tempMensagem;
    ////
    Usuario usuario1(1,"user1", "1234", "bryan", "56");
    usuario.push_back(usuario1);
    Usuario usuario2(2,"user2", "7653", "Lukas", "56");
    usuario.push_back(usuario2);
    Usuario usuario3(3,"user3",  "9032", "Felipe", "56");
    usuario.push_back(usuario3);
    Usuario usuario4(4,"user4",  "1234", "Rhuryan", "56");
    usuario.push_back(usuario4);
    ////
    Grupo grupo1(1,"gangue de retardados", "std", 2);
    grupo.push_back(grupo1);
    Grupo grupo2(2,"Grupo O Grupo", "cvh", 1);
    grupo.push_back(grupo2);
    Grupo grupo3(3,"So os Confirmados", "hgf", 2);
    grupo.push_back(grupo3);
    Grupo grupo4(4,"Abecedario", "tyr", 1);
    grupo.push_back(grupo4);
    ////
    UsuarioGrupo usergroup1(1,1);
    usuarioGrupo.push_back(usergroup1);
    UsuarioGrupo usergroup2(2, 1);
    usuarioGrupo.push_back(usergroup2);
    UsuarioGrupo usergroup3(3, 1);
    usuarioGrupo.push_back(usergroup3);
    UsuarioGrupo usergroup4(1, 2);
    usuarioGrupo.push_back(usergroup4);
    UsuarioGrupo usergroup5(4, 2);
    usuarioGrupo.push_back(usergroup5);
    ////
    Mensagem tempMensagem1(1,1, 1, "Oi");
    mensagem.push_back(tempMensagem1);
    Mensagem tempMensagem2(2,3, 1, "caralho");
    mensagem.push_back(tempMensagem2);
    Mensagem tempMensagem3(3,4, 2, "porra");
    mensagem.push_back(tempMensagem3);
    Mensagem tempMensagem4(4,2, 1, "vai se fuder");
    mensagem.push_back(tempMensagem4);
    Mensagem tempMensagem5(5,1, 2, "toma no cu");
    mensagem.push_back(tempMensagem5);

    for (Usuario iterador : usuario){
        cout << iterador.getIdUsuario()<<" /// " << iterador.getNomeUsuario() << " /// " << iterador.getSenha() << " /// " << iterador.getNomePessoa() << " /// " << iterador.getHexUsuario() <<endl;
    }
    for (Grupo iterador : grupo) {
        cout << iterador.getIdGrupo() << " /// " << iterador.getNomeGrupo() << " /// " << iterador.getGrupoSecret() << " /// " << iterador.getTipoGrupo() << endl;
    }
    for (UsuarioGrupo iterador : usuarioGrupo) {
        cout << iterador.getIdUsuario() << " /// " << iterador.getIdGrupo() << endl;
    }
    for (Mensagem iterador : mensagem) {
        cout << iterador.getIdMensagem() << " /// " << iterador.getIdPosta() << " /// " << iterador.getIdGrupo() << " /// " << iterador.getMensagem()<<endl;
    }



    cout << "digite seu nome de usuario\n";
    cin >> nome;
    cout << "digite sua senha\n";
    cin >> senha;
    for (int i = 0; i < usuario.size(); i++) {
        if (usuario[i].getNomeUsuario() == nome && usuario[i].getSenha() == senha) {
            usuarioAtual = usuario[i].getIdUsuario();
            
            do {
                cout << "digita uma opcao mano";
                cin >> op;
                switch (op) {
                case 1: {
                    cout << "Qual o contato/grupo que voce vai enviar a mensagem\n";
                    cin >> nomegrupo;
                    for (int i = 0; i < grupo.size(); i++) {
                        if (grupo[i].getNomeGrupo() == nomegrupo) {
                            idGrupoEnvia = grupo[i].getIdGrupo();
                            for (int y = 0; y < usuarioGrupo.size(); y++) {
                                if (idGrupoEnvia == usuarioGrupo[y].getIdGrupo() && usuarioAtual == usuarioGrupo[y].getIdUsuario()) {
                                    tempMensagem.setIdPosta(usuarioAtual);
                                    tempMensagem.setIdGrupo(grupo[i].getIdGrupo());
                                    cout << "digite a mensagem a ser enviada\n";
                                    getline(cin, msg);
                                    cin.clear();
                                    cin.ignore();
                                    tempMensagem.setMensagem(msg);
                                    mensagem.push_back(tempMensagem);
                                    break;
                                }
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    //fazer um "do while" para listar todos os grupos que o usuario logado
                    for (int i = 0; i < usuarioGrupo.size(); i++) {
                        if (usuarioAtual == usuarioGrupo[i].getIdUsuario()) {
                            for (int y = 0; y < grupo.size(); y++) {
                                if (grupo[y].getIdGrupo() == usuarioGrupo[i].getIdGrupo()) {
                                    cout << grupo[y].getNomeGrupo()<<endl;
                                }
                            }
                        }
                       
                    }
                    break;
                }
                case 3: {
                    Grupo grupoPush;
                    UsuarioGrupo usuarioGrupoPush;
                    do {
                        cout << "Selecione o tipo de grupo, 1 para grupo simples e 2 para grupo com varias pessoas\n";
                        cin >> tipo;
                    } while (tipo != 1 && tipo != 2);
                    if (tipo == 1) {
                        cout << "digite o nome do contato\n";
                        cin >> nomecontato; // adicionar concatenacao com o nome da pessoa que esta criando o contato
                        for (int i = 0; i < usuario.size(); i++) {
                            if (usuario[i].getNomeUsuario() == nomecontato) {
                                grupoPush.setNomeGrupo(nomecontato);
                                grupoPush.setTipoGrupo(tipo);
                                grupoPush.setGrupoSecret("asokaoksoakoaksoskaoksaosk");
                                grupo.push_back(grupoPush);
                                usuarioGrupoPush.setIdUsuario(usuario[i].getIdUsuario());
                                usuarioGrupo.push_back(usuarioGrupoPush);
                                usuarioGrupoPush.setIdUsuario(usuarioAtual);
                                usuarioGrupo.push_back(usuarioGrupoPush);

                            }
                        }
                    }if (tipo == 2) {
                        grupoPush.setTipoGrupo(tipo);
                        cout << "digite o nome do grupo\n";
                        cin >> nomegrupo;
                        grupoPush.setNomeGrupo(nomegrupo);
                        cout << "digite quantos contatos deseja adicionar\n";
                        cin >> qntdcontato;
                        grupoPush.setGrupoSecret("asokaoksoakoaksoskaoksaosk");
                        grupo.push_back(grupoPush);
                        usuarioGrupoPush.setIdUsuario(usuarioAtual);
                        usuarioGrupo.push_back(usuarioGrupoPush);
                        for (int i = 0; i < qntdcontato; i++) {
                            cout << "digite o contato\n";
                            cin >> nomecontato;
                            if (usuario[i].getNomeUsuario() == nomecontato) {
                                usuarioGrupoPush.setIdGrupo(usuario[i].getIdUsuario());
                                usuarioGrupo.push_back(usuarioGrupoPush);
                            }
                            
                            //chamado para o banco
                        }
                    }
                    break;
                }
                case 4: {
                    UsuarioGrupo usuarioGrupoPush;
                    cout << "Digite o grupo para entrar: ";
                    cin >> nomegrupo;
                    for (int i = 0; i < grupo.size(); i++) {
                        if (grupo[i].getNomeGrupo() == nomegrupo && grupo[i].getTipoGrupo() == 2) {
                            usuarioGrupoPush.setIdGrupo(grupo[i].getIdGrupo());
                            usuarioGrupoPush.setIdUsuario(usuarioAtual);
                            usuarioGrupo.push_back(usuarioGrupoPush);
                            break;
                        }
                    }
                    break;
                }
                case 5: {
                    break;
                }
                case 6: {
                    break;
                }
                case 7: {
                    break;
                }
                default: {
                    break;
                }
                }
            } while (op != 7);
            
        }
    }
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
