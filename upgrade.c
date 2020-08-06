#include <stdio.h>
#include <stdlib.h>
char p1, p2, game[3][3];
int verifica[3][3], condi = 0; 
static int p = 0,q = 0;

struct crd{
	int lin, col;
}retorna;

int main()
{
	
int i, c, again;
char se;

void menu ();
void GAME ();
int ganhador ();

do{
    do{
        p1 = 00; p2 = 00;
        fflush(stdin);
        menu();
        printf("PLAYER 1 (X ou O): ");
        p1 = getche();
        fflush(stdin);
            if (p1 == 'X' || p1 == 'x'){
                p1 = 'X';
                p2 = 'O';
                menu ();
                printf("\t\t\t  Pressione - \t1 para iniciar\n");
                printf("\t\t\t  Pressione - \t0 para trocar Simbolo\n");
                se = getch();
            }
            else if (p1 == 'o' || p1 == 'O'){
                p1 = 'O';
                p2 = 'X';
                menu ();
                printf("\t\t\t  Pressione - \t1 para iniciar\n");
                printf("\t\t\t  Pressione - \t0 para trocar Simbolo\n");
                se = getch();
            }
            else{
                printf("\n\t\t\t\tSimbolo Invalido!\n\t\t    ");
                system("pause");
                se = '0';
            }
            for (i = 0; i < 3; i++){
                for (c  = 0; c < 3; c++){
                    verifica[i][c] = 0;
                    game[i][c] = 00;
                }
            }
    }while (se != '1');
    GAME ();
    do{
        printf("\n\n\t\t\t  Pressione - \t1 para NOVO JOGO\n");
        printf("\t\t\t  Pressione - \t0 para SAIR\n");
        scanf("%d", &again);
        se++;
        if (again != 0 && again != 1){
            printf("\n\t\t\t\tOpcao Invalida!\n\t\t");
            system("pause");
            se = 0;
        }
    }while (se == 0);
}while (again == 1);
}
void menu (){

int i, c, j, d;

system("cls");
printf("\t\t\tJOGO DA VELHA - By Duarte.jSistem\n\n\n");
printf("\t\t\t");
    for (j = 0; j < 15; j++){
        printf("-");
     }
        printf ("COORDENADAS");
    for (j = 0; j < 15; j++){
        printf("-");
     }
     for (j = 0; j < 5; j++){
        if (j < 4){
            if (j < 3){
                printf("\n\t\t\t|\t");
                printf(" %d |", j+1);
            }
        for (c = 0; c < 3; c++){
                if (j < 3)
                printf("__ __|");
                if (j == 3 && c == 2){
                    printf("\n\t\t\t|\t");
                    for (i = 0; i < 3; i++){
                        printf("     %d", i+1);
                    }
                }
                if (c == 2){
                    printf("\t\t|");
                }
            }
        }
        else{
            printf("\n\t\t\t|\t\t\t\t\t|");
        }
     }
     printf("\n\t\t\t");
     for (j = 0; j < 41; j++){
        printf("-");
     }
    printf("\n\n\n");
    printf("PLAYER 1: %c\nPLAYER 2: %c", p1, p2);
    printf("\n\n\n");
}
crd tabuleiro (int seta){

int i = 0, c = 0, a , b;
char copia[3][3];
system("cls");
printf("\t\t\tJOGO DA VELHA - By Duarte.jSistem\n\n\n");

strcpy(copia, game);
a = p; b = q;
if(seta == 4){ // seta para cima
	p--;
	if (p <= 0){
		p = a; q = b;
		retorna.lin = p;
		retorna.col = q;
	}
	else{
		retorna.lin = a;
		retorna.col = q;
	}
}
else if(seta == 12){ // verificando seta para baixo
	p++;
	if (p > 3){
		p = a; q = b;
		retorna.lin = p;
		retorna.col = q;
	}
	else{
		retorna.lin = p;
		retorna.col = q;
	}	
}
else if (seta == 9){ // seta para direita
	q++;
	if (q <= 0){
		p = ; q = b;
		retorna.lin = p;
		retorna.col = q;
	}
	else{
		retorna.lin = p;
		retorna.col = q;
	}
}
else{// seta para a esquerda
	q--;
	if (q > 3){
		p = ; q = b;
		retorna.lin = p;
		retorna.col = q;
	}
	else{
		retorna.lin = p;
		retorna.col = q;
	}
}
    while (i < 3){
        printf("\t\t\t\t |");
        for (c = 0; c < 3; c++){
            printf("__%c__|", copia[i][c]);
        }
        i++;
        printf("\n");
    }
    
return retorna;
}
int ganhador (){

int i, j, d, c, vencedor[8], cont = 0, retorna;

            /* VERIFICAR PRIMEIRAS 3 LINHAS */
        for (i = 0; i < 3; i++){
            for (c = 0; c < 3; c++){
                    if (verifica[i][0] == verifica[i][c]){
                        condi++;
                    }
                    if (condi == 3){
                        vencedor[cont] = verifica[i][0];
                    }
                    else if (c == 2){
                        vencedor[cont] = 0;
                    }
            }
            cont++;
            condi = 0;
        }
            /* VERIFICAR PRIMEIRAS 3 COLUNAS */
        for (i = 0; i < 3; i++){
            for (c = 0; c < 3; c++){
                if (verifica[0][i] == verifica[c][i]){
                    condi++;
                }
                if (condi == 3){
                        vencedor[cont] = verifica[0][i];
                }
                else if (c == 2){
                        vencedor[cont] = 0;
                }
            }
            condi = 0;
            cont++;
        }
        condi = 0;
            /* VERIFICAR DIAGONAL PRINCIPAL*/
        for (i = 0; i < 3; i++){
            for (c = 0; c < 3; c++){
                if (i == c && verifica[1][1] == verifica[i][c]){
                    condi++;
                }
                if (condi == 3){
                    vencedor[cont] = verifica[1][1];
                }
                else if (c == 2){
                    vencedor[cont] = 0;
                }
            }
        }
        cont++;
        condi = 0;
            /* VERIFICAR DIAGONAL SECUNDARIA*/
        for (i = 0; i < 3; i++){
            for (c = 0; c < 3; c++){
                if (i + c == 2 && verifica[1][1] == verifica[i][c]){
                    condi++;
                }
                if (condi == 3){
                    vencedor[cont] = verifica[1][1];
                }
                else if (c == 2){
                    vencedor[cont] = 0;
                }
            }
        }
        cont++;
        condi = 0;
    for (i = 0; i < 8; i++){
        if (vencedor[i] != 0){
            retorna = vencedor[i];
            return retorna;
        }
        else if (i >= 7){
            return 0;
        }
    }
}
void GAME (){

int i, c, j, d, player = 1, jogadas = 0, se = 0;
tabuleiro();
    while (jogadas < 9){
        if (player == 1 && jogadas < 9){
            while (se == 0){
                printf("\n\n\t\t\tPLAYER %d, E A SUA VEZ DE MARCAR! (%c)\n\n", player, p1);
                se++;
                printf("Informe, respectivamente, a linha e coluna de marcacao: ");
                scanf("%d %d", &d, &j);
                if ((d <= 0 || d > 3)|| (j <= 0 || j > 3)){
                    printf("\n\n\t\t\tValor invalido! Tente Novamente...\n\t\t");
                    system("pause");
                    menu();
                    system("pause");
                    tabuleiro();
                    se = 0;
                }
            }
            se = 0;
            d = d-1; j = j-1;
            if (verifica[d][j] != 0){
                player--;
                jogadas--;
                printf("\n\t\tPOSICAO JA MARCADA!! TENTE NOVAMENTE...\n\n");
                system("pause");
                menu();
                system("pause");
                tabuleiro();
            }
            else{
                game[d][j] = p1;
                verifica[d][j] = player;
                ganhador();
                tabuleiro();
                if (jogadas >= 4 && ganhador() != 0){
                    tabuleiro();
                    printf("\n\n\t\t\tPARABENS! O JOGADOR %d E O VENCEDOR!\n\n", ganhador());
                    system("pause");
                    jogadas = 8;
                }
                else if (jogadas >= 8){
                    tabuleiro();
                    printf("\n\n\t\tNAO HOUVE GANHADOR! O JOGO DEU VELHA!\n\n");
                    system("pause");
                }
            }
            player++;
            jogadas++;
        }
        if (player == 2 && jogadas < 9){
            while (se == 0){
                se++;
                printf("\n\n\t\t\tPLAYER %d, E A SUA VEZ DE MARCAR! (%c)\n\n", player, p2);
                printf("Informe, respectivamente, a linha e coluna de marcacao: ");
                scanf("%d %d", &d, &j);
                if ((d <= 0 || d > 3)|| (j <= 0 || j > 3)){
                    printf("\n\n\t\t\tValor invalido! Tente Novamente...\n\t\t");
                    system("pause");
                    menu();
                    system("pause");
                    tabuleiro();
                    se = 0;
                }
            }
            se = 0;
            d = d-1; j = j-1;
            if (verifica[d][j] != 0){
                player = 3;
                jogadas--;
                printf("\n\t\tPOSICAO JA MARCADA!! TENTE NOVAMENTE...\n\n");
                system("pause");
                menu();
                system("pause");
                tabuleiro();
            }
            else{
                game[d][j] = p2;
                verifica[d][j] = player;
                ganhador();
                if (jogadas >= 4 && ganhador() != 0){
                    tabuleiro();
                    printf("\n\n\t\t\tPARABENS! O JOGADOR %d E O VENCEDOR!\n\n", ganhador());
                    system("pause");
                    jogadas = 8;
                }
                else if (jogadas >= 8){
                    tabuleiro();
                    printf("\n\n\t\tNAO HOUVE GANHADOR! O JOGO DEU VELHA!\n\n");
                    system("pause");
                }
                tabuleiro();
            }
            player--;
            jogadas++;
        }
    }
}

