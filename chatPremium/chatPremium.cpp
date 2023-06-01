// chatPremium.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include"Libs.cpp"
#include "Usuario.h";

int main() {
    string nomegrupo, mensagem, nomecontato;
    int op, tipo, qntdcontato;
    string nome, senha;
    Usuario teste("teste", "teste", "teste", "teste");
    vector <Usuario> usuario;
    cout << "digite seu nome\n";
    cin >> nome;
    cout << "digite sua senha\n";
    cin >> senha;
    if (teste.getNomeUsuario() == nome && teste.getSenha() == senha) {
        do {
            cin >> op;
            switch (op) {
            case 1: {
                cout << "Qual o contato/grupo que você vai enviar a mensagem\n";
                cin >> nomegrupo;
                cout << "digite a mensagem a ser enviada\n";
                getline(cin, mensagem);
                cin.clear();
                cin.ignore();
                break;
            }
            case 2: {
                //fazer um "do while" para listar todos os grupos que o usuario logado
                break;
            }
            case 3: {
                do {
                    cout << "Selecione o tipo de grupo, 1 para grupo simples e 2 para grupo com varias pessoas\n";
                    cin >> tipo;
                } while (tipo != 1 && tipo != 2);
                if (tipo == 1) {
                    cout << "digite o nome do contato\n";
                    cin >> nomecontato;
                }if (tipo == 2) {
                    cout << "digite o nome do grupo\n";
                    cin >> nomegrupo;
                    cout << "digite quantos contatos deseja adicionar\n";
                    cin >> qntdcontato;
                    for (int i = 0; i < qntdcontato; i++) {
                        cout << "digite o contato\n";
                        cin >> nomecontato;
                        //chamado para o banco
                    }
                }
                break;
            }
            case 4: {
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

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
