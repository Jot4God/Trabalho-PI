#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include<math.h>

#define ROWS 33
#define COLS 53


#define BASE_HEALTH 100
#define MINE_HEALTH 50
#define BARRACKS_HEALTH 70
#define STABLES_HEALTH 70
#define ARMOURY_HEALTH 70
#define INFANTRY_HEALTH 30
#define CAVALRY_HEALTH 40
#define ARTILLERY_HEALTH 20

#define INFANTRY_ATTACK_POWER 5
#define CAVALRY_ATTACK_POWER 7
#define ARTILLERY_ATTACK_POWER 10

int player1_health = BASE_HEALTH;
int player2_health = BASE_HEALTH;
int mine_health = MINE_HEALTH;
int barracks_health = BARRACKS_HEALTH;
int stables_health = STABLES_HEALTH;
int armoury_health = ARMOURY_HEALTH;
int infantary_health = INFANTRY_HEALTH;
int cavalry_health = CAVALRY_HEALTH;
int artillery_health = ARTILLERY_HEALTH;

void MainMenu();
void startNewGame();
void SideSelection();
void settings();
void LoadGame();
char tabuleiro[33][53];
int Tabuleiro();
void printtabuleiro();
void Turno_Gondor();
void Turno_Mordor();
void saveGame();
char tabuleiro[ROWS][COLS];
int CastarCoins1 = 100;
int CastarCoins2 = 100;


int main() {
	int choice;
	do {
		MainMenu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			startNewGame();
			break;
		case 2:
			LoadGame();
			printf("Load Game option selected.\n");
			break;
		case 3:
			settings();
			break;
		case 4:
			printf("Exiting the game\n");
			break;
		default:
			printf("Invalid choice.\n");
		}
	} while (choice != 4);
	return 0;
}
void MainMenu() {
	printf("================================");
	printf("\nWelcome to Middle-earth Battle\n");
	printf("================================\n");
	printf("1. Start New Game\n");
	printf("2. Load Game\n");
	printf("3. Settings\n");
	printf("4. Exit\n");
}
void startNewGame() {
	SideSelection();
	Tabuleiro();
	printtabuleiro();
	Turno_Gondor();
}


void SideSelection() {
	int sideChoice;
	printf("\nChoose your side:\n");
	printf("1 - Gondor\n");
	printf("2 - Mordor\n");
	printf("Enter your choice: ");
	scanf("%d", &sideChoice);
	if (sideChoice == 1) {

		printf("\nYou chose Gondor\n");
	}
	else if (sideChoice == 2) {

		printf("\nYou chose Mordor\n");
	}
	else {
		printf("Invalid choice.\n");
		SideSelection();
	}
}

void criar_unidadeGondor(char tipoUnidade, int custo) {
	int l = 33;
	int c = 53;
	char letra;
	int letra_tabuleiro;
	int numero;
	int numero_tabuleiro;
	int i = 0;
	int j = 0;


	if (CastarCoins1 >= custo) {

		CastarCoins1 -= custo;


		int i, j;

		for (i = 0; i < 33; i++) {
			for (j = 0; j < 53; j++) {
				if (tabuleiro[i][j] == ' ') {

					tabuleiro[i][j] = tipoUnidade;

					printf("   Choose where you want to place the building (A1):");
					scanf(" %c%d", &letra, &numero);
					numero_tabuleiro = (numero * 2) - 1;
					letra_tabuleiro = ((letra - 'A') * 2) + 1;
					i = numero_tabuleiro;
					j = letra_tabuleiro;

					printtabuleiro();

					Turno_Gondor();
					return 0;

				}
			}
		}


		printf("There is no space available to create the new unit.\n");
	}
	else {
		printf("Castar Coins insufficient to create the unit.\n");
	}
}

void LoadGame() {
	FILE* file = fopen("saved_game.txt", "r");
	if (file == NULL) {
		printf("No saved game found.\n");
		return;
	}


	Tabuleiro();


	CastarCoins1 = 0;
	CastarCoins2 = 0;

	fscanf(file, "%d %d\n", &CastarCoins1, &CastarCoins2);

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			fscanf(file, " %c", &tabuleiro[i][j]);
		}
		fscanf(file, "\n");
	}

	fclose(file);


	printf("Game loaded successfully.\n");
	printtabuleiro();
	printf("CastarCoins from Gondor= %d\n", CastarCoins1);
	printf("CasterCoins from Mordor= %d\n", CastarCoins2);
}

void saveGame() {
	FILE* file = fopen("saved_game.txt", "w");
	if (file == NULL) {
		printf("Error saving the game.\n");
		return;
	}

	fprintf(file, "%d %d\n", CastarCoins1, CastarCoins2);

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			fprintf(file, "%c", tabuleiro[i][j]);
		}
		fprintf(file, "\n");
	}

	fclose(file);

	printf("Game saved successfully.\n");
}

void settings() {
	int dificuldade;
	int Volume;
	printf("Current game settings:\n");
	printf("Chose youre dificulty: (1,2,3)\n");
	scanf("\n%d", &dificuldade);
	printf("Difficulty changed to: %d", dificuldade);
	printf("\nVolume level:(1,2,3,4,5)\n");
	scanf("\n%d", &Volume);
	printf("Volume level changed to: %d", Volume);

}

int Tabuleiro() {
	int x = 1;
	int l = 33;
	int c = 53;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			if (i == 0 && j == 0) {
				tabuleiro[i][j] = 218;
			}
			else if (i == 15 && j == 1) {
				tabuleiro[i][j] = 64;
			}
			else if (i == 15 && j == 51) {
				tabuleiro[i][j] = 184;
			}
			else if (i == 0 && j == 52) {
				tabuleiro[i][j] = 191;
			}
			else if (i == 32 && j == 0) {
				tabuleiro[i][j] = 192;
			}
			else if (i == 32 && j == 52) {
				tabuleiro[i][j] = 217;
			}
			else if (i == 0 && j == 26) {
				tabuleiro[i][j] = 203;
			}
			else if (i == 32 && j == 26) {
				tabuleiro[i][j] = 202;
			}
			else if (i % 2 == 0 && j == 26) {
				tabuleiro[i][j] = 206;
			}
			else if (i % 2 != 0 && j == 26) {
				tabuleiro[i][j] = 186;
			}
			else if (i == 32 && j % 2 == 0) {
				tabuleiro[i][j] = 193;
			}
			else if (i == 0 && j % 2 == 0) {
				tabuleiro[i][j] = 194;
			}
			else if (i % 2 == 0 && j == 52) {
				tabuleiro[i][j] = 180;
			}
			else if (i % 2 != 0 && j % 2 == 0) {
				tabuleiro[i][j] = 124;
			}
			else if (i % 2 == 0 && j == 0) {
				tabuleiro[i][j] = 195;
			}
			else if (i % 2 == 0 && j % 2 == 0) {
				tabuleiro[i][j] = 197;
			}
			else if (i % 2 == 0 || j % 2 == 0) {
				tabuleiro[i][j] = 196;
			}
			else { tabuleiro[i][j] = ' '; }
		}
	}return 0;
}

void printtabuleiro() {

	int x = 1;
	int l = 33;
	int c = 53;
	printf("    A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
	printf("   ");
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", tabuleiro[i][j]);
		}
		if (i % 2 == 0 && x < 10) {
			printf("\n 0%d", x);
			x++;
		}
		else if (i % 2 == 0 && x < 17) {
			printf("\n %d", x);
			x++;
		}
		else {
			printf("\n   ");
		}
	}x = 1;
}


void colocar_pecasGondor(char peca) {
	int i = 0;
	int j = 0;
	int l = 33;
	int c = 53;


	if (peca == 71) {
		if (CastarCoins1 > 10) {
			for (int i = 0; i < l; i++) {
				for (int j = 0; j < c; j++) {
					if (tabuleiro[i][j] == 'R') {
						tabuleiro[i][j + 2] = 71;
						CastarCoins1 = CastarCoins1 - 10;
					}
				}
			}
		}
		else {
			printf("No money found\n\n");
			Turno_Gondor();
		}

	}
	else if (peca == 67) {
		if (CastarCoins1 > 15) {
			for (int i = 0; i < l; i++) {
				for (int j = 0; j < c; j++) {
					if (tabuleiro[i][j] == 'L') {
						tabuleiro[i][j + 2] = 67;
						CastarCoins1 = CastarCoins1 - 15;
					}
				}
			}
		}
		else {
			printf("No money found\n\n");
			Turno_Gondor();
		}


	}
	else {
		if (CastarCoins1 > 20) {
			for (int i = 0; i < l; i++) {
				for (int j = 0; j < c; j++) {
					if (tabuleiro[i][j] == 'B') {
						tabuleiro[i][j + 2] = 84;
						CastarCoins1 = CastarCoins1 - 20;
					}
				}
			}
		}
		else {
			printf("No money found\n\n");
			Turno_Gondor();
		}

	}
	printtabuleiro();
	printf("CastarCoins from Gondor= %d\n", CastarCoins1);
	printf("   CasterCoins from Mordor= %d\n", CastarCoins2);

	Turno_Gondor();
}


void colocar_pecasMordor(char peca) {
	int l = 33;
	int c = 53;
	int i = 0;
	int j = 0;

	if (peca == 79) {
		if (CastarCoins2 > 10) {
			for (int i = 0; i < l; i++) {
				for (int j = 0; j < c; j++) {
					if (tabuleiro[i][j] == 'I') {
						tabuleiro[i][j - 2] = 79;
						CastarCoins2 = CastarCoins2 - 10;
					}
				}
			}
		}
		else {
			printf("No money found\n\n");
			Turno_Mordor();
		}

	}
	else if (peca == 87) {
		if (CastarCoins2 > 15) {
			for (int i = 0; i < l; i++) {
				for (int j = 0; j < c; j++) {
					if (tabuleiro[i][j] == 'M') {
						tabuleiro[i][j - 2] = 87;
						CastarCoins2 = CastarCoins2 - 15;
					}
				}
			}
		}
		else {
			printf("No money found\n\n");
			Turno_Mordor();
		}

	}
	else {
		if (CastarCoins2 > 20) {
			for (int i = 0; i < l; i++) {
				for (int j = 0; j < c; j++) {
					if (tabuleiro[i][j] == 'D') {
						tabuleiro[i][j - 2] = 83;
						CastarCoins2 = CastarCoins2 - 20;
					}
				}
			}
		}
		else {
			printf("No money found\n\n");
			Turno_Mordor();
		}

	}
	printtabuleiro();
	printf("CastarCoins from Gondor= %d\n", CastarCoins1);
	printf("   CasterCoins from Mordor= %d\n", CastarCoins2);

	Turno_Mordor();


}


void colocar_construcaoGondor(char construcao) {
	int l = 33;
	int c = 53;
	char letra;
	int letra_tabuleiro;
	int numero;
	int numero_tabuleiro;
	int i = 0;
	int j = 0;

	printf("    Choose where you want to place the building  (A1):");
	scanf(" %c%d", &letra, &numero);
	numero_tabuleiro = (numero * 2) - 1;
	letra_tabuleiro = ((letra - 'A') * 2) + 1;
	i = numero_tabuleiro;
	j = letra_tabuleiro;
	if (tabuleiro[i][j] == ' ') {
		if (construcao == 'H') {
			if (CastarCoins1 > 20) {
				tabuleiro[i][j] = construcao;
				CastarCoins1 = CastarCoins1 - 20;
			}
			else {
				printf("No money found\n\n");
				Turno_Gondor();
			}

		}
		else if (construcao == 'R') {
			if (CastarCoins1 > 25) {
				tabuleiro[i][j] = construcao;
				CastarCoins1 = CastarCoins1 - 25;
			}
			else {
				printf("No money found\n\n");
				Turno_Gondor();
			}
		}
		else if (construcao == 'L') {
			if (CastarCoins1 > 25) {
				tabuleiro[i][j] = construcao;
				CastarCoins1 = CastarCoins1 - 25;
			}
			else {
				printf("No money found\n\n");
				Turno_Gondor();
			}
		}
		else {
			if (CastarCoins1 > 30) {
				tabuleiro[i][j] = construcao;
				CastarCoins1 = CastarCoins1 - 30;
			}
			else {
				printf("No money found\n\n");
				Turno_Gondor();
			}
		}

		printtabuleiro();
		printf("CastarCoins from Gondor= %d\n", CastarCoins1);
		printf("   CasterCoins from Mordor= %d\n", CastarCoins2);
		Turno_Gondor();
	}
	else {
		printf("Already in use, try again:\n");
		colocar_construcaoGondor(construcao);
	}
}


void colocar_construcaoMordor(char construcao) {
	int l = 33;
	int c = 53;
	char letra;
	int letra_tabuleiro;
	int numero;
	int numero_tabuleiro;
	int i = 0;
	int j = 0;

	printf("   Choose where you want to place the building  (A1):");
	scanf(" %c%d", &letra, &numero);
	numero_tabuleiro = (numero * 2) - 1;
	letra_tabuleiro = ((letra - 'A') * 2) + 1;
	i = numero_tabuleiro;
	j = letra_tabuleiro;
	if (tabuleiro[i][j] == ' ') {
		if (construcao == 'E') {
			if (CastarCoins2 > 20) {
				tabuleiro[i][j] = construcao;
				CastarCoins2 = CastarCoins2 - 20;
			}
			else {
				printf("No money found\n\n");
				Turno_Mordor();
			}
		}
		else if (construcao == 'I') {
			if (CastarCoins2 > 25) {
				tabuleiro[i][j] = construcao;
				CastarCoins2 = CastarCoins2 - 25;
			}
			else {
				printf("No money found\n\n");
				Turno_Mordor();
			}
		}
		else if (construcao == 'M') {
			if (CastarCoins2 > 25) {
				tabuleiro[i][j] = construcao;
				CastarCoins2 = CastarCoins2 - 25;
			}
			else {
				printf("No money found\n\n");
				Turno_Mordor();
			}
		}
		else {
			if (CastarCoins2 > 30) {
				tabuleiro[i][j] = construcao;
				CastarCoins2 = CastarCoins2 - 30;
			}
			else {
				printf("No money found\n\n");
				Turno_Mordor();
			}
		}

		printtabuleiro();
		printf("CastarCoins from Gondor= %d\n", CastarCoins1);
		printf("   CasterCoins from Mordor= %d\n", CastarCoins2);
		Turno_Mordor();
	}
	else {
		printf("Already in use, try again:\n");
		colocar_construcaoMordor(construcao);
	}
}


void MoverpecaGondor() {
	int l = 33;
	int c = 53;
	char letra;
	int letra_tabuleiro;
	int numero;
	int numero_tabuleiro;
	int i = 0;
	int j = 0;
	printf("Enter the board house of the piece you want to move (A1(A1):\n");
	scanf(" %c%d", &letra, &numero);
	numero_tabuleiro = (numero * 2) - 1;
	letra_tabuleiro = ((letra - 'A') * 2) + 1;
	i = numero_tabuleiro;
	j = letra_tabuleiro;
	char peca = tabuleiro[i][j];
	if (tabuleiro[i][j] == ' ') {
		printf("There are no pieces in this board house, try again:\n");
		MoverpecaGondor();
	}
	else if (tabuleiro[i][j] == 'H' || tabuleiro[i][j] == 'R' || tabuleiro[i][j] == 'L' || tabuleiro[i][j] == 'B' || tabuleiro[i][j] == 'O' || tabuleiro[i][j] == 'W' || tabuleiro[i][j] == 'S' || tabuleiro[i][j] == 'E' || tabuleiro[i][j] == 'I' || tabuleiro[i][j] == 'M' || tabuleiro[i][j] == 'D' || tabuleiro[i][j] == 64 || tabuleiro[i][j] == 184) {
		printf("This piece does not belong to you or is a construction, try again:\n ");
		MoverpecaGondor();
	}
	else {
		char movimento;
		printf("\n\nUse the WASD keys to move the piece('Q' to move).\n");

		while (1) {
			if (CastarCoins1 > 0) {
				scanf(" %c", &movimento);
				if (movimento == 'W' && i > 1) {
					if (tabuleiro[i - 2][j] == ' ') {
						tabuleiro[i][j] = ' '; // Limpa a posição anterior
						i = i - 2;

						tabuleiro[i][j] = peca; // Coloca a peça na nova posição
					}
					else {
						printf("Posicao Ocupada, tente de novo:\n");
						Turno_Gondor();
					}

				}
				else if (movimento == 'S' && i < l - 2) {
					if (tabuleiro[i + 2][j] == ' ') {
						tabuleiro[i][j] = ' ';
						i = i + 2;
						tabuleiro[i][j] = peca;
					}
					else {
						printf("Posicao Ocupada, tente de novo:\n");
						Turno_Gondor();
					}

				}
				else if (movimento == 'D' && j < c - 2) {
					if (tabuleiro[i][j + 2] == ' ') {
						tabuleiro[i][j] = ' ';
						j = j + 2;
						tabuleiro[i][j] = peca;
					}
					else {
						printf("Posicao Ocupada, tente de novo:\n");
						Turno_Gondor();
					}
				}
				else if (movimento == 'A' && j > 1) {
					if (tabuleiro[i][j - 2] == ' ') {
						tabuleiro[i][j] = ' ';
						j = j - 2;
						tabuleiro[i][j] = peca;
					}
					else {
						printf("Posicao Ocupada, tente de novo:\n");
						Turno_Gondor();
					}
				}
				else if (movimento == 'Q') {
					Turno_Gondor();
				}

				printtabuleiro();
				if (peca == 71) {
					CastarCoins1 = CastarCoins1 - 2;
				}
				else if (peca == 67) {
					CastarCoins1 = CastarCoins1 - 1;
				}
				else if (peca == 84) {
					CastarCoins1 = CastarCoins1 - 3;
				}
				printf("CastarCoins from Gondor= %d\n", CastarCoins1);
				printf("   CasterCoins from Mordor= %d\n", CastarCoins2);
			}
			else {
				printf("FIcou sem Dinheiro, fim de turno\n\n");
				Turno_Mordor();
			}
		}
	}
}


void MoverpecaMordor() {
	int l = 33;
	int c = 53;
	char letra;
	int letra_tabuleiro;
	int numero;
	int numero_tabuleiro;
	int i = 0;
	int j = 0;
	printf("Introduza a casa da peca que deseja movimentar(A1):\n");
	scanf(" %c%d", &letra, &numero);
	numero_tabuleiro = (numero * 2) - 1;
	letra_tabuleiro = ((letra - 'A') * 2) + 1;
	i = numero_tabuleiro;
	j = letra_tabuleiro;
	char peca = tabuleiro[i][j];
	if (tabuleiro[i][j] == ' ') {
		printf("Nao existe nenhuma peca nesta casa, tente de novo:\n");
		MoverpecaMordor();
	}
	else if (tabuleiro[i][j] == 'H' || tabuleiro[i][j] == 'R' || tabuleiro[i][j] == 'L' || tabuleiro[i][j] == 'B' || tabuleiro[i][j] == 'G' || tabuleiro[i][j] == 'C' || tabuleiro[i][j] == 'T' || tabuleiro[i][j] == 'E' || tabuleiro[i][j] == 'I' || tabuleiro[i][j] == 'M' || tabuleiro[i][j] == 'D' || tabuleiro[i][j] == 64 || tabuleiro[i][j] == 184) {
		printf("Esta peca nao lhe pertence ou e uma construcao, tente outra vez:\n ");
		MoverpecaMordor();
	}
	else {
		char movimento;
		printf("\n\nUse as teclas WASD para mover a peca ('Q' para sair).\n");

		while (1) {
			if (CastarCoins2 > 0) {
				scanf(" %c", &movimento);
				if (movimento == 'W' && i > 1) {
					if (tabuleiro[i - 2][j] == ' ') {
						tabuleiro[i][j] = ' ';
						i = i - 2;

						tabuleiro[i][j] = peca;
					}
					else {
						printf("Already in use, try again:\n");
						Turno_Mordor();
					}

				}
				else if (movimento == 'S' && i < l - 2) {
					if (tabuleiro[i + 2][j] == ' ') {
						tabuleiro[i][j] = ' ';
						i = i + 2;
						tabuleiro[i][j] = peca;
					}
					else {
						printf("Already in use, try again:\n");
						Turno_Mordor();
					}

				}
				else if (movimento == 'D' && j < c - 2) {
					if (tabuleiro[i][j + 2] == ' ') {
						tabuleiro[i][j] = ' ';
						j = j + 2;
						tabuleiro[i][j] = peca;
					}
					else {
						printf("Already in use, try again:\n");
						Turno_Mordor();
					}
				}
				else if (movimento == 'A' && j > 1) {
					if (tabuleiro[i][j - 2] == ' ') {
						tabuleiro[i][j] = ' ';
						j = j - 2;
						tabuleiro[i][j] = peca;
					}
					else {
						printf("Already in use, try again:\n");
						Turno_Mordor();
					}
				}
				else if (movimento == 'Q') {
					Turno_Mordor();
				}

				printtabuleiro();
				if (peca == 79) {
					CastarCoins2 = CastarCoins2 - 2;
				}
				else if (peca == 87) {
					CastarCoins2 = CastarCoins2 - 1;
				}
				else if (peca == 83) {
					CastarCoins2 = CastarCoins2 - 3;
				}
				printf("CastarCoins from Gondor= %d\n", CastarCoins1);
				printf("   CasterCoins from Mordor= %d\n", CastarCoins2);
			}
			else {
				printf("No money found, shift ended.\n\n");
				Turno_Gondor();
			}

		}

	}
}

void attackGondor() {
	int attack_power = 0;
	int* defender_health = NULL;
	char letra1;
	char letra2;
	int letra_tabuleiro1;
	int letra_tabuleiro2;
	int numero1;
	int numero2;
	int numero_tabuleiro1;
	int numero_tabuleiro2;
	int i = 0;
	int j = 0;
	int p = 0;
	int q = 0;
	printf("Escolha com que peca deseja atacar(A1):\n");
	scanf(" %c%d", &letra1, &numero1);
	numero_tabuleiro1 = (numero1 * 2) - 1;
	letra_tabuleiro1 = ((letra1 - 'A') * 2) + 1;
	i = numero_tabuleiro1;
	j = letra_tabuleiro1;
	char attacker = tabuleiro[i][j];
	printf("Escolha que peca deseja atacar(A1):\n");
	scanf(" %c%d", &letra2, &numero2);
	numero_tabuleiro2 = (numero2 * 2) - 1;
	letra_tabuleiro2 = ((letra2 - 'A') * 2) + 1;
	p = numero_tabuleiro2;
	q = letra_tabuleiro2;
	char defender = tabuleiro[p][q];

	// Ataque determinado pelo tipo do personagem
	switch (attacker) {
	case 'G':
		attack_power = INFANTRY_ATTACK_POWER;
		break;
	case 'C':
		attack_power = CAVALRY_ATTACK_POWER;
		break;
	case 'T':
		attack_power = ARTILLERY_ATTACK_POWER;
		break;
	default:
		printf("Invalid attacker type.\n");
		Turno_Gondor();
	}

	// Defesa determinada pelo tipo do personagem
	switch (defender) {
	case 184:
		defender_health = &player2_health;
		break;
	case 'O':
		defender_health = &infantary_health;
		break;
	case 'W':
		defender_health = &cavalry_health;
		break;
	case 'S':
		defender_health = &artillery_health;
		break;
	case 'E':
		defender_health = &mine_health;
		break;
	case 'I':
		defender_health = &barracks_health;
		break;
	case 'M':
		defender_health = &stables_health;
		break;
	case 'D':
		defender_health = &armoury_health;
		break;
	default:
		printf("Invalid defender type.\n");
		Turno_Gondor();
	}

	*defender_health -= attack_power;


	if (*defender_health > 0) {
		printf("Attack: %c -> %c\n", attacker, defender);
		printf("Defender's health after the attack: %d\n", *defender_health);
		printtabuleiro();
		Turno_Gondor();
	}
	else {
		printf("\nA peca foi derrotada\n\n");
		tabuleiro[p][q] = ' ';
		printtabuleiro();
		Turno_Gondor();
	}
}


void attackMordor() {
	int attack_power = 0;
	int* defender_health = NULL;
	char letra1;
	char letra2;
	int letra_tabuleiro1;
	int letra_tabuleiro2;
	int numero1;
	int numero2;
	int numero_tabuleiro1;
	int numero_tabuleiro2;
	int i = 0;
	int j = 0;
	int p = 0;
	int q = 0;
	printf("Escolha com que peca deseja atacar(A1):\n");
	scanf(" %c%d", &letra1, &numero1);
	numero_tabuleiro1 = (numero1 * 2) - 1;
	letra_tabuleiro1 = ((letra1 - 'A') * 2) + 1;
	i = numero_tabuleiro1;
	j = letra_tabuleiro1;
	char attacker = tabuleiro[i][j];
	printf("Escolha que peca deseja atacar(A1):\n");
	scanf(" %c%d", &letra2, &numero2);
	numero_tabuleiro2 = (numero2 * 2) - 1;
	letra_tabuleiro2 = ((letra2 - 'A') * 2) + 1;
	p = numero_tabuleiro2;
	q = letra_tabuleiro2;
	char defender = tabuleiro[p][q];


	switch (attacker) {
	case 'O':
		attack_power = INFANTRY_ATTACK_POWER;
		break;
	case 'W':
		attack_power = CAVALRY_ATTACK_POWER;
		break;
	case 'S':
		attack_power = ARTILLERY_ATTACK_POWER;
		break;
	default:
		printf("Invalid attacker type.\n");
		Turno_Mordor();
	}


	switch (defender) {
	case 64:
		defender_health = &player1_health;
		break;
	case 'G':
		defender_health = &infantary_health;
		break;
	case 'C':
		defender_health = &cavalry_health;
		break;
	case 'T':
		defender_health = &artillery_health;
		break;
	case 'H':
		defender_health = &mine_health;
		break;
	case 'R':
		defender_health = &barracks_health;
		break;
	case 'L':
		defender_health = &stables_health;
		break;
	case 'B':
		defender_health = &armoury_health;
		break;
	default:
		printf("Invalid defender type.\n");
		Turno_Mordor();
	}

	*defender_health -= attack_power;

	if (*defender_health > 0) {
		printf("Attack: %c -> %c\n", attacker, defender);
		printf("Defender's health after the attack: %d\n", *defender_health);
		printtabuleiro();
		Turno_Mordor();
	}
	else {
		printf("\nA peca foi derrotada\n\n");
		tabuleiro[p][q] = ' ';
		printtabuleiro();
		Turno_Mordor();
	}
}


void Turno_Gondor() {
	int escolha;
	int escolhapeca;
	int escolhaconstrucao;
	char peca;
	char construcao;
	printf("====Gondor Round====\n");
	printf("CastarCoins=%d\n", CastarCoins1);
	printf("Choose what do you want to do:\n1 - Place pieces:\n2 - Place contructions:\n3 - Move pieces:\n4 - Shift ended:\n5 - Creating New Units:\n6 - Attack:\n7 - Save Game:\n");
	printf("Enter your choice: ");
	scanf("%d", &escolha);

	if (escolha == 1) {
		printf("Indicate which piece you want to position:\n1 - Gondoryan Guards'Infantry'\n2 - Swan-Knights'Cavalry'\n3 - Trabuchets'Artillery'\n");
		scanf(" %d", &escolhapeca);

		if (escolhapeca == 1) {
			colocar_pecasGondor(peca = 71);
		}
		else if (escolhapeca == 2) {
			colocar_pecasGondor(peca = 67);
		}
		else if (escolhapeca == 3) {
			colocar_pecasGondor(peca = 84);
		}
		else {
			printf("Invalid action, try again");
			Turno_Gondor();
		}
	}
	else if (escolha == 2) {
		printf("Indicate which building you want to position:\n1 - Mines\n2 - Barracks\n3 - Stables\n4 - Armoury\n");
		scanf(" %d", &escolhaconstrucao);

		if (escolhaconstrucao == 1) {
			colocar_construcaoGondor(construcao = 72);
		}
		else if (escolhaconstrucao == 2) {
			colocar_construcaoGondor(construcao = 82);
		}
		else if (escolhaconstrucao == 3) {
			colocar_construcaoGondor(construcao = 76);
		}
		else if (escolhaconstrucao == 4) {
			colocar_construcaoGondor(construcao = 66);
		}
		else {
			printf("Invalid Choice, Try Again");
			Turno_Gondor();
		}
	}
	else if (escolha == 3) {
		MoverpecaGondor();
	}
	else if (escolha == 4) {
		printf("\nShift Ended:\n\n");

		int l = 33;
		int c = 53;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < c; j++) {
				if (tabuleiro[i][j] == 'E') {
					CastarCoins2 = CastarCoins2 + 5;
				}
			}
		}
		Turno_Mordor();
	}
	else if (escolha == 6) {

		attackGondor();
	}
	else if (escolha == 7) {
		saveGame();
	}
	else if (escolha == 5) {
		printf("Indicate which building you want to position:\n1 - Gondoryan Guards'Infantry'\n2 - Swan-Knights'Cavalry'\n3 - Trabuchets'Artillery'\n");
		scanf(" %d", &escolhapeca);

		if (escolhapeca == 1) {
			criar_unidadeGondor('G', 10);
		}
	}
	else {
		printf("Invalid Choice, Try Again:\n");
		Turno_Gondor();
	}
	}



	void Turno_Mordor() {
		int escolha;
		int escolhapeca;
		int escolhaconstrucao;
		char peca;
		char construcao;

		printf("====Turno de Mordor====\n");
		printf("CastarCoins=%d\n", CastarCoins2);
		printf("Choose what do you want to do:\n1 - Place pieces:\n2 - Place contructions:\n3 - Move pieces:\n4 - Shift ended:\n5 - Creating New Units:\n6 - Attack:\n7 - Save Game:\n");
		printf("Enter your choice: ");
		scanf(" %d", &escolha);
		if (escolha == 1) {
			printf("Indicate which building you want to position:\n1 - Orcs'Infantry'\n2 - Wargs'Cavalry'\n3 - Sieges-Towers'Artillery'\n");
			scanf(" %d", &escolhapeca);
			if (escolhapeca == 1) {
				colocar_pecasMordor(peca = 79);
			}
			else if (escolhapeca == 2) {
				colocar_pecasMordor(peca = 87);
			}
			else if (escolhapeca == 3) {
				colocar_pecasMordor(peca = 83);
			}
			else {
				printf("Invalid Choice, Try Again\n");
				Turno_Mordor();
			}
		}
		else if (escolha == 2) {
			printf("Indicate which building you want to position:\n1 - Mines\n2 - Barracks\n3 - Stables\n4 - Armoury\n");
			scanf(" %d", &escolhaconstrucao);

			if (escolhaconstrucao == 1) {
				colocar_construcaoMordor(construcao = 69);
			}
			else if (escolhaconstrucao == 2) {
				colocar_construcaoMordor(construcao = 73);
			}
			else if (escolhaconstrucao == 3) {
				colocar_construcaoMordor(construcao = 77);
			}
			else if (escolhaconstrucao == 4) {
				colocar_construcaoMordor(construcao = 68);
			}
			else {
				printf("Invalid Choice, Try Again:");
				Turno_Mordor();
			}
		}
		else if (escolha == 3) {
			MoverpecaMordor();
		}
		else if (escolha == 4) {
			printf("\nShift Ended:\n\n");

			int l = 33;
			int c = 53;
			for (int i = 0; i < l; i++) {
				for (int j = 0; j < c; j++) {
					if (tabuleiro[i][j] == 'H') {
						CastarCoins1 = CastarCoins1 + 5;
					}
				}
			}
		}
		else if (escolha == 7) {
			saveGame();
		}

		else if (escolha == 6) {
			attackMordor();
		}
		else if (escolha == 5) {
			printf("Indicate which building you want to position:\n1 - Orcs'Infantry'\n2 - Wargs'Cavalry'\n3 - Sieges-Towers'Artillery'\n");
			scanf(" %d", &escolhapeca);

			if (escolhapeca == 1) {
				criar_unidadeGondor('G', 10); // Assuming it costs 10 Castar coins
			}
			
		}

		else {
			printf("Invalid Choice, Try Again:\n");
			Turno_Mordor();
		}
		}
	
