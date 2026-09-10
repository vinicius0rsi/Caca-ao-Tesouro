#include "funcoes.cpp"

int main () {

    srand(time(0));
    
    Posicoes posicao;
    char tabuleiro[TAM][TAM];

    posicao_jogador(vetor_posicoes_jogador);
    
    while(true){
        preencher_matriz(tabuleiro);
        inserir_tesouro(tabuleiro);
        inserir_jogador(tabuleiro);
        exibir_matriz(tabuleiro);
        nova_posicao(posicao);
    }

    return 0;
}