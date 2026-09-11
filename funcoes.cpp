#include <iostream>
#include <cstdlib>
#include <ctime>
#define TAM 15
using namespace std;

//variaveis globais:

int vetor_posicoes_jogador[2];
int vetor_posicao_tesouro[2];


void preencher_matriz(char matriz[TAM][TAM]) {
    for (int i = 0; i<TAM; i++){
        for (int j = 0; j<TAM; j++) {
            matriz[i][j] = '.';
        }
    }
}

void exibir_matriz(char matriz[TAM][TAM]) {
    system("cls");
    for (int i = 0; i<TAM; i++){
        for (int j = 0; j<TAM; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

struct Posicoes
{
    char direcao;
    int passos;
    int linha;
    int coluna;
};

void nova_posicao(Posicoes &posicao){

    string pergunta_passos = "quantos passos voce deseja?: ";

    do{
    cout << "Qual direcao voce deseja? (wasd): ";
    cin >> posicao.direcao;
    if (!(isalpha(posicao.direcao))){
        cout << "\nERRO: Voce digitou um numero\n";
    }
    }while(!(isalpha(posicao.direcao)));

    switch(posicao.direcao) {           
        case 'w':

            while(true){
                cout << pergunta_passos;
                // char teste;
                // cin >> teste;
                // if(isalpha(teste)){
                //     cout << "\nERRO: Voce digitou uma letra\n";
                //     continue;
                // } else{
                //     posicao.passos = int(teste);
                // }
                cin >> posicao.passos;
                posicao.linha = vetor_posicoes_jogador[0] - posicao.passos;
                if (posicao.linha<0) {
                    cout << "ERRO: Numero de passos passou do limite! \n";
                    continue;
                }
                break;
            }
            
            vetor_posicoes_jogador[0] = posicao.linha;
            break;

        case 'a':
        
        while(true){
                cout << pergunta_passos;
                cin >> posicao.passos;
                posicao.coluna = vetor_posicoes_jogador[1] - posicao.passos;
                if (posicao.coluna<0) {
                    cout << "ERRO: Numero de passos passou do limite! \n";
                    continue;
                }
                break;
            }
            
            vetor_posicoes_jogador[1] = posicao.coluna;
            break;

        case 's':
        
        while(true){
                cout << pergunta_passos;
                cin >> posicao.passos;
                posicao.linha = vetor_posicoes_jogador[0] + posicao.passos;
                if (posicao.linha>14) {
                    cout << "ERRO: Numero de passos passou do limite! \n";
                    continue;
                }
                break;
            }

            vetor_posicoes_jogador[0] = posicao.linha;
            break;
            
        case 'd':
        
        while(true){
            cout << pergunta_passos;
            cin >> posicao.passos;
                posicao.coluna = vetor_posicoes_jogador[1] + posicao.passos;
                if (posicao.coluna>14) {
                    cout << "ERRO: Numero de passos passou do limite! \n";
                    continue;
                }
                break;
            }
            
            vetor_posicoes_jogador[1] = posicao.coluna;
            break;

        default:
            break;
    }
}

void posicao_jogador(int vetor_posicoes_jogador[2]){
    for (int i = 0; i<TAM; i++) {
        vetor_posicoes_jogador[i] = (rand() % 14);
    }
}

void inserir_jogador(char matriz[TAM][TAM]){ 
    matriz[vetor_posicoes_jogador[0]][vetor_posicoes_jogador[1]] = 'O';
}

void posicao_tesouro(int vetor_posicao_tesouro[2]){
    while(true){
        for (int i = 0; i<TAM; i++) {
            vetor_posicao_tesouro[i] = (rand() % 14);
            if (vetor_posicao_tesouro[i] == vetor_posicoes_jogador[i]){
                continue;
            }
        }
    }
}

void inserir_tesouro(char matriz[TAM][TAM]){ 
    matriz[vetor_posicao_tesouro[0]][vetor_posicao_tesouro[1]] = '1';
}
