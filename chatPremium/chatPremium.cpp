// chatPremium.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "Libs.cpp";
#include "Usuario.h";
#include "Grupo.h";
#include "Mensagem.h";
#include "UsuarioGrupo.h";
#include "Criptografador.h";

int main() {
    string nomegrupo, msg, nomecontato, senhaSuperSecretaAdm = "SENHaSUPErSECRETa";
    int opLogin, opConta, tipo, qntdcontato, usuarioAtual, idGrupoEnvia;
    string nome, senha;
    Criptografador criptografador;

    vector <Usuario> usuario;
    vector <Grupo> grupo;
    vector <Mensagem> mensagem;
    vector <UsuarioGrupo> usuarioGrupo;
    Mensagem tempMensagem;

    /*
    Nas linhas abaixo, estamos preenchendo nossos vetores com algumas informaoes de exemplo. Esta parte será mantida no código até que um banco de dados ou
    arquivo para mantermos os dados. 
    */

    ////
    Usuario deleted(0, "DELETED", "2@40*1!", "DELETED", "FFFFFF");
    usuario.push_back(deleted);
    Usuario usuario1(1, "user1", "1234", "bryan", "56");
    usuario.push_back(usuario1);
    Usuario usuario2(2, "user2", "7653", "Lukas", "56");
    usuario.push_back(usuario2);
    Usuario usuario3(3, "user3", "9032", "Felipe", "56");
    usuario.push_back(usuario3);
    Usuario usuario4(4, "user4", "1234", "Rhuryan", "56");
    usuario.push_back(usuario4);
    ////
    Grupo grupo1(1, "testandooow owo", "std", 2);
    grupo.push_back(grupo1);
    Grupo grupo2(2, "Grupo O Grupo", "cvh", 1);
    grupo.push_back(grupo2);
    Grupo grupo3(3, "So os Confirmados", "hgf", 2);
    grupo.push_back(grupo3);
    Grupo grupo4(4, "Abecedario", "tyr", 1);
    grupo.push_back(grupo4);
    ////
    UsuarioGrupo usergroup1(1, 1);
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
    Mensagem tempMensagem1(1, 1, 1, criptografador.criptografa("Oi"));
    mensagem.push_back(tempMensagem1);
    Mensagem tempMensagem2(2, 3, 1, criptografador.criptografa("Caramba"));
    mensagem.push_back(tempMensagem2);
    Mensagem tempMensagem3(3, 4, 2, criptografador.criptografa("que loucura"));
    mensagem.push_back(tempMensagem3);
    Mensagem tempMensagem4(4, 2, 1, criptografador.criptografa("oi?"));
    mensagem.push_back(tempMensagem4);
    Mensagem tempMensagem5(5, 1, 2, criptografador.criptografa("que isso cara"));
    mensagem.push_back(tempMensagem5);

    

    do {
        /*
            Este do-while seria a tela inicial do app. aqui seria onde o usuario teria a opcao de entrar na sua conta, recuperar sua senha ou criar seu usuario.
            Tambem existe uma opcao ****extremamente secreta**** para fazer debugging
        */
        cout << "1 login, 2 cadastrar, 3 esqueci a senha, 4 encerrar"<<endl;
        cin >> opLogin;
        cin.ignore();
        switch (opLogin) {

        case 1: {
            /*
            Aqui ocorre o fluxo principal do programa, onde o usuario tem acesso a todas as opcoes disponiveis para ele.
            */
            cout << "digite seu nome de usuario\n";
            cin >> nome;
            cin.ignore();
            cout << "digite sua senha\n";
            cin >> senha;
            cin.ignore();
            for (int i = 0; i < usuario.size(); i++) {
                if (usuario[i].getNomeUsuario() == nome && usuario[i].getSenha() == senha) {
                    usuarioAtual = usuario[i].getIdUsuario();

                    do {
                        cout << "Selecione uma opcao: "<<endl;
                        cout << "1 - Enviar Mensagem" << endl;
                        cout << "2 - Listar Grupos"<<endl;
                        cout << "3 - Criar Contato/Grupo"<<endl;
                        cout << "4 - Entrar em Grupo" << endl;
                        cout << "5 - Listar Mensagens" << endl;
                        cout << "6 - Excluir Conta" << endl;
                        cout << "7 - Editar Dados da Conta" << endl;
                        cout << "8 - Fazer Logoff" << endl;
                        cin >> opConta;
                        cin.ignore();
                        switch (opConta) {
                        case 1: {
                            /*
                            Aqui faremos os envios de mensagens. O usuario precisa definir para quem ela sera enviada e a mensagem em si. A mensagem sera
                            criptografada antes de ser salva no vetor.
                            */
                            cout << "Qual o contato/grupo que voce vai enviar a mensagem\n";
                            getline(cin, nomegrupo);
                            cin.clear();
                            //cin >> nomegrupo;
                            for (int i = 0; i < grupo.size(); i++) {
                                if (strcmp(grupo[i].getNomeGrupo().c_str(),nomegrupo.c_str())==0) {
                                    idGrupoEnvia = grupo[i].getIdGrupo();
                                    for (int y = 0; y < usuarioGrupo.size(); y++) {
                                        if (idGrupoEnvia == usuarioGrupo[y].getIdGrupo() && usuarioAtual == usuarioGrupo[y].getIdUsuario()) {
                                            tempMensagem.setIdPosta(usuarioAtual);
                                            tempMensagem.setIdGrupo(grupo[i].getIdGrupo());
                                            cout << "digite a mensagem a ser enviada\n";
                                            getline(cin, msg);
                                            cin.clear();
                                            string enviaCriptografia = criptografador.criptografa(msg);
                                            tempMensagem.setMensagem(enviaCriptografia);
                                            mensagem.push_back(tempMensagem);
                                            break;
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        case 2: {
                            /*
                            Aqui listaremos todos os grupos que o usuario atual faz parte. Por grupo, definimos que podera ser considerado como um contato
                            ou como um grupo. Mais sobre isso a frente.
                            */
                            for (int i = 0; i < usuarioGrupo.size(); i++) {
                                if (usuarioAtual == usuarioGrupo[i].getIdUsuario()) {
                                            for (int y = 0; y < grupo.size(); y++) {
                                                if (grupo[y].getIdGrupo() == usuarioGrupo[i].getIdGrupo()) {
                                                    cout << grupo[y].getNomeGrupo() << endl;
                                                }
                                            }   
                                }

                            }
                            break;
                        }
                        case 3: {
                            /*
                            Nesta parte criamos os grupos, para onde serao enviadas as mensagens. Os grupos sao contatos ou grupos. Um contato sera classificado
                            como tipo 1. Isto define que apenas 2 pessoas participam deste grupo, nao podendo adicionar novas pessoas. Um grupo, classificado
                            como tipo 2, podera conter N contatos.
                            */
                            Grupo grupoPush;
                            UsuarioGrupo usuarioGrupoPush;
                            int idGrupo;
                            bool idViavel;
                            do {
                                cout << "Selecione o tipo de grupo, 1 para grupo simples e 2 para grupo com varias pessoas\n";
                                cin >> tipo;
                                cin.ignore();
                            } while (tipo != 1 && tipo != 2);
                            if (tipo == 1) {
                                cout << "digite o nome do contato\n";
                                cin >> nomecontato; 
                                cin.ignore();
                                for (int i = 0; i < usuario.size(); i++) {
                                    if (usuario[i].getNomeUsuario() == nomecontato) {
                                        do {
                                            srand(time(NULL));
                                            idViavel = true;
                                            idGrupo = rand() % 10000;
                                            for (int k = 0; k < grupo.size(); k++) {
                                                if (grupo[k].getIdGrupo() == idGrupo) {
                                                    idViavel = false;
                                                }
                                            }
                                        } while (idViavel != true);
                                        grupoPush.setIdGrupo(idGrupo);
                                        grupoPush.setNomeGrupo(nomecontato);
                                        grupoPush.setTipoGrupo(tipo);
                                        grupoPush.setGrupoSecret("asokaoksoakoaksoskaoksaosk");
                                        grupo.push_back(grupoPush);
                                        usuarioGrupoPush.setIdUsuario(usuario[i].getIdUsuario());
                                        usuarioGrupoPush.setIdGrupo(idGrupo);
                                        usuarioGrupo.push_back(usuarioGrupoPush);
                                        usuarioGrupoPush.setIdUsuario(usuarioAtual);
                                        usuarioGrupoPush.setIdGrupo(idGrupo);
                                        usuarioGrupo.push_back(usuarioGrupoPush);

                                    }
                                }
                            }if (tipo == 2) {
                                do {
                                    srand(time(NULL));
                                    idViavel = true;
                                    idGrupo = rand() % 10000;
                                    for (int k = 0; k < grupo.size(); k++) {
                                        if (grupo[k].getIdGrupo() == idGrupo) {
                                            idViavel = false;
                                        }
                                    }
                                } while (idViavel != true);
                                grupoPush.setIdGrupo(idGrupo);
                                grupoPush.setTipoGrupo(tipo);
                                cout << "digite o nome do grupo\n";
                                getline(cin, nomegrupo);
                                cin.clear();
                                //cin >> nomegrupo;
                                grupoPush.setNomeGrupo(nomegrupo);
                                cout << "digite quantos contatos deseja adicionar\n";
                                cin >> qntdcontato;
                                grupoPush.setGrupoSecret("asokaoksoakoaksoskaoksaosk");
                                grupo.push_back(grupoPush);
                                usuarioGrupoPush.setIdGrupo(idGrupo);
                                usuarioGrupoPush.setIdUsuario(usuarioAtual);
                                usuarioGrupo.push_back(usuarioGrupoPush);
                                for (int p = 0; p < qntdcontato; p++) {
                                    cout << "digite o contato\n";
                                    cin >> nomecontato;
                                    for (int t = 0; t < usuario.size(); t++) {
                                        if (strcmp(usuario[t].getNomeUsuario().c_str(), nomecontato.c_str()) == 0) {
                                            usuarioGrupoPush.setIdGrupo(idGrupo);
                                            usuarioGrupoPush.setIdUsuario(usuario[t].getIdUsuario());
                                            usuarioGrupo.push_back(usuarioGrupoPush);
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        case 4: {
                            /*
                            Aqui o usuario pode entrar em algum grupo ja existente. O programa ira validar se este grupo e do tipo 2, permitindo sua entrada
                            */
                            UsuarioGrupo usuarioGrupoPush;
                            cout << "Digite o grupo para entrar: ";
                            getline(cin, nomegrupo);
                            cin.clear();
                            //cin >> nomegrupo;
                            for (int i = 0; i < grupo.size(); i++) {
                                if (strcmp(grupo[i].getNomeGrupo().c_str(),nomegrupo.c_str())==0 && grupo[i].getTipoGrupo() == 2) {
                                    usuarioGrupoPush.setIdGrupo(grupo[i].getIdGrupo());
                                    usuarioGrupoPush.setIdUsuario(usuarioAtual);
                                    usuarioGrupo.push_back(usuarioGrupoPush);
                                    break;
                                }
                            }
                            break;
                        }
                        case 5: {
                            /*
                            Esta parte lista as mensagens do grupo especificado pelo usuario, na ordem em que foram enviadas.
                            */
                            string grupoLista, usuarioPosta;
                            int grupoIdTemp, usuarioPostaId;
                            cout << "Digite o grupo para listar as mensagens: ";
                            getline(cin, grupoLista);
                            cin.clear();
                            //cin >> grupoLista;

                            for (int i = 0; i < grupo.size(); i++) {
                                if (strcmp(grupo[i].getNomeGrupo().c_str(), grupoLista.c_str()) == 0) {
                                    grupoIdTemp = grupo[i].getIdGrupo();
                                    for (int z = 0; z < usuarioGrupo.size(); z++) {
                                        if (grupoIdTemp == usuarioGrupo[z].getIdGrupo() && usuarioAtual == usuarioGrupo[z].getIdUsuario()) {
                                            for (int j = 0; j < mensagem.size(); j++) {
                                                if (mensagem[j].getIdGrupo() == grupoIdTemp) {
                                                    usuarioPostaId = mensagem[j].getIdPosta();
                                                    for (int p = 0; p < usuario.size(); p++) {
                                                        if (usuario[p].getIdUsuario() == usuarioPostaId) {
                                                            usuarioPosta = usuario[p].getNomeUsuario();
                                                            break;
                                                        }

                                                    }
                                                    cout << usuarioPosta << ": " << criptografador.decriptografa(mensagem[j].getMensagem()) << "." << endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        case 6: {
                            /*
                            Esta parte permite o usuario excluir a sua conta. Apos a exclusao, o programa sera levado para fora da area do usuario e devolta 
                            para a tela de login.
                            */
                            string escolheApagar;
                            cout << "Voce deseja mesmo apagar sua conta? sim ou nao?";
                            cin >> escolheApagar;
                            if (strcmp(escolheApagar.c_str(), "sim") == 0) {
                                for (int i = 0; i < usuarioGrupo.size(); i++) {
                                    if (usuarioGrupo[i].getIdUsuario() == usuarioAtual) {
                                        usuarioGrupo[i].setIdUsuario(0);
                                    }
                                }
                                for (UsuarioGrupo teste : usuarioGrupo) {
                                    cout << teste.getIdGrupo() << " /// " << teste.getIdUsuario() << endl;
                                }
                                for (int i = 0; i < mensagem.size(); i++) {
                                    if (mensagem[i].getIdPosta() == usuarioAtual) {
                                        mensagem[i].setIdPosta(0); 
                                    }
                                }
                                for (Mensagem teste : mensagem) {
                                    cout << teste.getIdPosta() << endl;
                                }
                                for (int i = 0; i < usuario.size(); i++) {
                                    if (usuario[i].getIdUsuario() == usuarioAtual) {
                                        usuario.erase(usuario.begin() + i);
                                        break;
                                    }
                                    
                                }
                            }
                            opConta = 8;
                            /*for (Usuario iterador : usuario) {
                            cout << iterador.getIdUsuario() << " /// " << iterador.getNomeUsuario() << " /// " << iterador.getSenha() << " /// " << iterador.getNomePessoa() << " /// " << iterador.getHexUsuario() << endl;
                            }*/
                            break;
                        }
                        case 7: {
                            /*
                            Aqui o usuario pode editar algumas informacoes da sua conta. Nao e fornecida uma opcao para editar o seu ID, pois o plano e 
                            futuramente integrar com o banco de dados e utilizar uma chave primaria auto-incrementavel para definir os ID's.
                            */
                            Usuario edita;
                            int opEdita = 0, continuarEditando;
                            for (int i = 0; i < usuario.size(); i++) {
                                if (usuario[i].getIdUsuario() == usuarioAtual) {
                                    edita.setNomeUsuario(usuario[i].getNomeUsuario());
                                    edita.setSenha(usuario[i].getSenha());
                                    edita.setNomePessoa(usuario[i].getNomePessoa());
                                    edita.setHexUsuario(usuario[i].getHexUsuario());
                                    do {
                                        /*
                                        Dentro deste loop, o usuario pode escolher alterar varios dados, um dado ou o mesmo dado varias vezes.
                                        */
                                        cout << "Digite qual a informacao a alterar: " << endl;
                                        cout << "1 - Nome de Usuario" << endl;
                                        cout << "2 - Senha" << endl;
                                        cout << "3 - Nome" << endl;
                                        cout << "4 - Hexadecimal" << endl;
                                        cout << "5 - Cancelar" << endl;
                                        cin >> opEdita;
                                        switch (opEdita) {
                                        case 1: {
                                            string novoNomeUsuario;
                                            cout << "Digite seu novo nome de usuario: ";
                                            cin >> novoNomeUsuario;
                                            edita.setNomeUsuario(novoNomeUsuario);
                                            cout << "Editar mais itens? 1 - nao\nOutros inputs - sim" << endl;
                                            cin >> continuarEditando;
                                            if (continuarEditando != 1) {
                                                opEdita = 0;
                                            }
                                            else {
                                                opEdita = 5;
                                            }
                                            break;
                                        }
                                        case 2: {
                                            string comparaSenha, senhaNova;
                                            do {
                                                cout << "Digite sua nova senha: ";
                                                cin >> senhaNova;
                                                cout << "Repita a nova senha: ";
                                                cin >> comparaSenha;
                                                if (strcmp(comparaSenha.c_str(), senhaNova.c_str()) != 0) {
                                                    cout << "Senhas nao coincidem."<<endl;
                                                }
                                            } while (strcmp(comparaSenha.c_str(), senhaNova.c_str()) != 0);
                                            edita.setSenha(senhaNova);
                                            cout << "Editar mais itens? 1 - nao\nOutros inputs - sim" << endl;
                                            cin >> continuarEditando;
                                            if (continuarEditando != 1) {
                                                opEdita = 0;
                                            }
                                            else {
                                                opEdita = 5;
                                            }
                                            break;
                                        }
                                        case 3: {
                                            string novoNome;
                                            cout << "Digite o novo nome: ";
                                            cin >> novoNome;
                                            edita.setNomePessoa(novoNome);
                                            cout << "Editar mais itens? 1 - nao\nOutros inputs - sim" << endl;
                                            cin >> continuarEditando;
                                            if (continuarEditando != 1) {
                                                opEdita = 0;
                                            }
                                            else {
                                                opEdita = 5;
                                            }
                                            break;
                                        }
                                        case 4: {
                                            string novoHex;
                                            cout << "Digite o novo hexadeciml: ";
                                            cin >> novoHex;
                                            edita.setHexUsuario(novoHex);
                                            cout << "Editar mais itens? 1 - nao\nOutros inputs - sim" << endl;
                                            cin >> continuarEditando;
                                            if (continuarEditando != 1) {
                                                opEdita = 0;
                                            }
                                            else {
                                                opEdita = 5;
                                            }
                                            break;
                                        }
                                        case 5: {
                                            usuario[i].setNomeUsuario(edita.getNomeUsuario());
                                            usuario[i].setSenha(edita.getSenha());
                                            usuario[i].setNomePessoa(edita.getNomePessoa());
                                            usuario[i].setHexUsuario(edita.getHexUsuario());
                                            break;
                                        }
                                        default: {
                                            cout << "Opcao invalida." << endl;
                                            break;
                                        }
                                        }
                                    } while (opEdita != 5);
                                }
                            }
                            break;
                        }
                        case 8: {
                            /*
                            Aqui voltamos para nossa tela inicial, permitindo um novo login ser realizado.
                            */
                            cout << "Saindo..." << endl;
                            break;
                        }
                        default: {
                            //Default para casos de input incorreto
                            cout << "Opcao invalida." << endl;
                            break;
                        }
                        }
                    } while (opConta != 8);
                }
            }
            break;
        }
        case 2: {
            /*
                Nesta aba podemos cadastrar um novo usuario. Como ainda nao temos uma ligacao com um banco, possuimos um input do ID, mas validamos se ele ja
                existe para outro usuario antes de permitir sua insercao, assim nao tendo uma conta duplicata.
            */
            Usuario cadastro;
            int verificaId, idTemp;
            string nomeUsuarioTemp, senhaTemp, nomeRealTemp, hexTemp;
            do {
                cout << "ID para a conta";
                cin >> idTemp;
                verificaId = 1;
                for (Usuario verificador : usuario) {
                    if (verificador.getIdUsuario() == idTemp) {
                        verificaId = 0;
                        cout << "ID ja em uso, escolha outro.";
                        break;
                    }
                }
            } while (verificaId != 1);
            cadastro.setIdUsuario(idTemp);
            cout << "Nome do usuario: ";
            cin >> nomeUsuarioTemp;
            cadastro.setNomeUsuario(nomeUsuarioTemp);
            cout << "Senha da conta: ";
            cin >> senhaTemp;
            cadastro.setSenha(senhaTemp);
            cout << "Nome real: ";
            cin >> nomeRealTemp;
            cadastro.setNomePessoa(nomeRealTemp);
            cout << "Hexadecimal: ";
            cin >> hexTemp;
            cadastro.setHexUsuario(hexTemp);
            usuario.push_back(cadastro);
            /*for (Usuario iterador : usuario) {
                cout << iterador.getIdUsuario() << " /// " << iterador.getNomeUsuario() << " /// " << iterador.getSenha() << " /// " << iterador.getNomePessoa() << " /// " << iterador.getHexUsuario() << endl;
            }*/
            break;
        }
        case 3: {
            /*
                Funcao de recuperacao de senha. O usuario devera lembrar alguns parametros de seguranca para poder recuperar sua conta, como o ID dele, que apenas
                ele tem acesso.
            */
            int idRecupera;
            string nomeUsuarioRecupera;
            cout << "Nome da conta: ";
            cin >> nomeUsuarioRecupera;
            cout << "id da conta: ";
            cin >> idRecupera;
            for (Usuario senhaRecupera : usuario) {
                if ((strcmp(senhaRecupera.getNomeUsuario().c_str(), nomeUsuarioRecupera.c_str()) == 0)&& (senhaRecupera.getIdUsuario() == idRecupera)) {
                    cout << "A sua senha e "<<senhaRecupera.getSenha();
                    break;
                }
            }
            break;
        }
        case 4: {
            /*
            Fechamos o app
            */
            cout << "Encerrando app...";
            break;
        }
        default: {
            //Caso default, para o caso de um input incorreto
            cout << "Opcao invalida." << endl;
        }
        case 12022000: {
            /*
            Ferramenta de debugging. Aqui listamos tudo que temos cadastrado nos nossos vetores (ja que atualmente nao temos um banco).
            */
            string senhaComparaAdm;
            cout << "..." << endl;
            cin >> senhaComparaAdm;
            if (strcmp(senhaComparaAdm.c_str(),senhaSuperSecretaAdm.c_str())==0) {
                cout << "\n" << endl;
                for (Usuario iterador : usuario) {
                    cout << iterador.getIdUsuario() << " /// " << iterador.getNomeUsuario() << " /// " << iterador.getSenha() << " /// " << iterador.getNomePessoa() << " /// " << iterador.getHexUsuario() << endl;
                }
                cout << "\n" << endl;
                for (Grupo iterador : grupo) {
                    cout << iterador.getIdGrupo() << " /// " << iterador.getNomeGrupo() << " /// " << iterador.getGrupoSecret() << " /// " << iterador.getTipoGrupo() << endl;
                }
                cout << "\n" << endl;
                for (UsuarioGrupo iterador : usuarioGrupo) {
                    cout << iterador.getIdUsuario() << " /// " << iterador.getIdGrupo() << endl;
                }
                cout << "\n" << endl;
                for (Mensagem iterador : mensagem) {
                    cout << iterador.getIdMensagem() << " /// " << iterador.getIdPosta() << " /// " << iterador.getIdGrupo() << " /// " << iterador.getMensagem() << endl;
                }
                cout << "\n" << endl;
                break;
            }
            break;
        }
        }
    } while (opLogin != 4);
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
