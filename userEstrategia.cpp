/*
	Autor: Luis Otavio Rigo Junior
	Objetivo: 
		Este arquivo destina-se a implementacao das estrategias de jogo dos agentes.
	
	Devem ser implementados os 4 prototipos:
		init_Player1 - executada uma unica vez e contem as funcoes de inicializacao da estrategia do jogador 1;
		run_Player1 - executado a cada passo do jogo e retorna uma string com a direcao de movimento do jogador 1;
		init_Player2 - executada uma unica vez e contem as funcoes de inicializacao da estrategia do jogador 2;
		run_Player2 - executado a cada passo do jogo e retorna uma string com a direcao de movimento do jogador 2.
	
	Funcoes que podem ser chamadas pelo jogador (agente):
		char *maze_VerAmbiente(char tipo[MAXLINE]);
			- Utilizada para verificar alguma informacao da celula. Ex.: id;
		bool maze_VerCaminho(const char *direcao);
			- Retorna se existe um caminho naquela direcao (verdadeiro ou falso).
		bool maze_VerMinotauro(const char *direcao);
			- Retorna se o minotauro estah naquela direcao (verdadeiro ou falso).
		float maze_CustoDoCaminho(const char *direcao);
			- Retorna o custo de executar um passo naquela direcao.
		float maze_HeuristicaDistEuclidiana(const char *direcao);
			- Retorna o a distancia heuclidiana da celula que estah naquela direcao ateh a saida.
	
	Constantes que podem ser usadas pelo jogador (agente):
		#define NUMCAMINHOS 4
		const char *id_Caminhos[NUMCAMINHOS] = {"norte", "sul", "oeste", "leste"};
		const char *id_Retornos[NUMCAMINHOS] = {"sul", "norte", "leste", "oeste"};
		typedef struct str_PosicaoPlano {
			int x,y;
		} tipo_PosicaoPlano;
*/




/*
Atividade de busca cega feito pela dupla: Isadora Fernandes Santos, Murylo Dias de Oliveira Rubim
*/
#include "globais.h"
#include <vector>
#include <iostream> 
#include "maze.h"
#include <stdlib.h>


using namespace std; 
int P1_Reticulado[MAXCEL][MAXCEL];
int P2_Reticulado[MAXCEL][MAXCEL];
int flagRetornoLimite;
std::vector<const char *> P1_PilhaHistorico;
std::vector<const char*> P2_PilhaHistorico;



// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 1 ***

/*
A estrategia adotada para o player 1 foi uma busca em profundidade limitada, na qual as direções são
escolhidas de forma aleatoria.
*/
void init_Player1() {
	for(int y=0; y<MAXCEL; y++) {
		for(int x=0; x<MAXCEL; x++) {
			P1_Reticulado[y][x]= -1;
		}
	}
	
	// Desmonta a pilha.
	while (P1_PilhaHistorico.size() > 0) {
		P1_PilhaHistorico.pop_back();
	}
	
    flagRetornoLimite = 0;
	
}

const char *run_Player1() {
	
	const char *movimento = "null";
    int flag = 0;
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};

   P1_Reticulado[posAtualP1.x][posAtualP1.y] = 0;
    
    if(P1_PilhaHistorico.size() >= 1000){
        flagRetornoLimite = 1;
    }
    
    if(flagRetornoLimite == 1){

        P1_Reticulado[posAtualP1.x][posAtualP1.y] = -1;
        movimento = P1_PilhaHistorico[P1_PilhaHistorico.size()-1];
        P1_PilhaHistorico.pop_back();

        if(P1_PilhaHistorico.size() == 750){
            flagRetornoLimite = 0;
        }

    }else{
        int vet_Caminhos[NUMCAMINHOS];
		int count_Aux = 0;
        for(int i = 0; i<NUMCAMINHOS;i++){
            int xnovo = posAtualP1.x + dx[i];
            int ynovo = posAtualP1.y + dy[i];

            if((maze_VerCaminho(id_Caminhos[i]) == CAMINHO) && (P1_Reticulado[xnovo][ynovo] == -1)){
                vet_Caminhos[count_Aux] = i;
				count_Aux++;
                flag = 1;
                 
            }
        }
                
        if(flag == 1){
            int escolha = rand()%count_Aux;
            movimento = id_Caminhos[vet_Caminhos[escolha]];
            P1_PilhaHistorico.push_back(id_Retornos[vet_Caminhos[escolha]]);

        }else{
            movimento = P1_PilhaHistorico[P1_PilhaHistorico.size()-1];
            P1_PilhaHistorico.pop_back();
        }
    }
    
	return movimento;
}

// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 2 ***


/*
A estrategia adotada para o player 2 foi uma busca em profundidade, na qual as direções são
escolhidas de forma aleatoria.
*/
void init_Player2() {
	

    for(int y=0; y<MAXCEL; y++) {
		for(int x=0; x<MAXCEL; x++) {
			P2_Reticulado[y][x]= -1;
		}
	}

	while (P2_PilhaHistorico.size() > 0) {
		P2_PilhaHistorico.pop_back();
	}
}

const char *run_Player2() {

    const char* movimento = "null";
    int flag = 0;
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};

    int vet_Caminhos[NUMCAMINHOS];
	int count_Aux = 0;
  
    P2_Reticulado[posAtualP2.x][posAtualP2.y] = 0;
    
     for(int i = 0; i<NUMCAMINHOS;i++){
            int xnovo = posAtualP2.x + dx[i];
            int ynovo = posAtualP2.y + dy[i];

            if((maze_VerCaminho(id_Caminhos[i]) == CAMINHO) && (P2_Reticulado[xnovo][ynovo] == -1)){
                vet_Caminhos[count_Aux] = i;
				count_Aux++;
                flag = 1;
            }
        }

    if(flag == 1){
        int escolha = rand()%count_Aux;
        movimento = id_Caminhos[vet_Caminhos[escolha]];
        P2_PilhaHistorico.push_back(id_Retornos[vet_Caminhos[escolha]]);

    }else{
        movimento = P2_PilhaHistorico[P2_PilhaHistorico.size()-1];
        P2_PilhaHistorico.pop_back();
    }
   
return movimento;
   
}


