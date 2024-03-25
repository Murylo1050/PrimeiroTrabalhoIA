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

// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 1 ***
//	Implementacao da primeira estrategia de jogo.
void init_Player1() {
	
}
const char *run_Player1() {
	const char *movimento;	
	
	// Trecho de codigo de Exemplo.
	int move = rand()%4;
	movimento = id_Caminhos[move];
	// Fim de trecho de codigo de Exemplo.
	
	return movimento;
}

// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 2 ***
//	Implementacao da segunda estrategia de jogo.
void init_Player2() {
	
}
const char *run_Player2() {
	const char *movimento;
	
	// Trecho de codigo de Exemplo.
	if (maze_VerCaminho("leste") == CAMINHO) {
		movimento = "leste";
	}
	else if (maze_VerCaminho("sul") == CAMINHO) {
		movimento = "sul";
	}
	else if (maze_VerCaminho("oeste") == CAMINHO) {
		movimento = "oeste";
	}
	else if (maze_VerCaminho("norte") == CAMINHO) {	
		movimento = "norte";
	}
	else {
		int move = rand()%4;
		movimento = id_Caminhos[move];
	}
	// Fim de trecho de codigo de Exemplo.
	
	return movimento;
}


