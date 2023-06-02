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
    Usuario usuario1("bryan","1234","56");
    Usuario usuario2("Lukas", "7653", "56");
    Usuario usuario3("Felipe", "9032", "56");
    Usuario usuario4("Rhuryan", "1234", "56");
    Grupo grupo1("gangue de retardados", "std", 2);
    Grupo grupo2("Grupo O Grupo", "cvh", 1);
    Grupo grupo3("Só os Confirmados", "hgf", 2);
    Grupo grupo1("Abecedario", "tyr", 1);
    Mensagem tempMensagem1(765, 5, "Oi");
    Mensagem tempMensagem2(135, 6, "caralho");
    Mensagem tempMensagem3(475, 2, "porra");
    Mensagem tempMensagem4(780, 9, "vai se fuder");
    Mensagem tempMensagem5(253, 5, "toma no cu");
    cout << "digite seu nome\n";
    cin >> nome;
    cout << "digite sua senha\n";
    cin >> senha;
    for (int i = 0; i < usuario.size(); i++) {
        if (usuario[i].getNomeUsuario() == nome && usuario[i].getSenha() == senha) {
            usuarioAtual = usuario[i].getId();
            
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
                                usuarioGrupoPush.setIdUsuario(usuario[i].getId());
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
                                usuarioGrupoPush.setIdGrupo(usuario[i].getId());
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
