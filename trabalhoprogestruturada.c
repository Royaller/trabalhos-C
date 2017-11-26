#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define qtd 9

//Opcao 1 = Game of thrones
char gabGOT[11] = {"ADDDBCBCCB"};
//Opcao 2 = The walking dead
char gabTWD[11] = {"DCCAADBBAC"};
//Opcao 3 = Stranger things
char gabST[11] = {"BCBBBDDCDA"};

int tentativas, pontos = 0;
char nome[30];

int validarResposta(char resp, int num, char escolha) {
     int acertou;
     switch(escolha)
     {
     case '1':
	 acertou = (toupper(resp) == gabGOT[num]) ? 1: 0;
	 break;
	 case '2':
	 acertou = (toupper(resp) == gabTWD[num]) ? 1: 0;
     break;
	 case '3':
	 acertou = (toupper(resp) == gabST[num]) ? 1: 0;
     break;	
	 }
       return acertou;
}

void somarPontos(int tentativa){
	 if(tentativa == 1)
	 pontos += 3;
	 else if(tentativa == 2)
	 pontos +=2;
	 else if(tentativa == 3)
	 pontos++;     
}

main(){	

char opcao, escolha = '0';
int i, contTentativa, acertou;
char jogardnv = 's';


while(toupper(jogardnv) == 'S') {

do{
//O usuario digita o questionario desejado
system("cls");
system("color 07");
printf("Seja bem vindo ao jogo! Por favor digite seu nome: ");
gets(nome);
system("cls");
printf("Digite qual tema deseja responder(1 - GOT, 2 - TWD, 3 - ST): ");
scanf("%c", &escolha);

//Caso o usuario digite a opção de tema invalida, o programa retorna com erro
}while(escolha != '1' && escolha != '2' && escolha != '3');

system("cls");

for(i = 0; i <= qtd; i++) {
 	
contTentativa = 1;	

do  {
     switch(escolha)
     {
     case '1':
     system("color 8F");
	 printf("                                      -- Questionario sobre Game of thrones --\n\n");
	 break;
	 case '2':
     system("color 4F");
	 printf("                                      -- Questionario sobre The Walking Dead -- \n\n");
	 break;
	 case '3':
	 system("color 0C");
	 printf("                                      -- Questionario sobre Stranger Things --\n\n");
	 break;
	 }

//Se não for a primeira tentativa
if(contTentativa > 1) 
printf("%d - Infelizmente voce errou, restam mais %d tentativa(s): ", i+1, (4-contTentativa));
else
printf(" Responda a questao %d: ", i+1);
scanf(" %c", &opcao);

//Caso o usuário não digite A,B,C ou D o programa retorna com opção inválida
while(toupper(opcao) != 'A' && toupper(opcao) != 'B' && toupper(opcao) != 'C' && toupper(opcao) != 'D') {

printf("\nResposta invalida, responda(A, B, C OU D) a questao %d: ", i+1);
scanf(" %c", &opcao);
}

    system("cls");
    acertou = validarResposta(opcao, i, escolha);
    if (acertou ==1 )
    somarPontos(contTentativa);
    contTentativa++;
     }       while ((acertou == 0) && (contTentativa <= 3));
  }


if(pontos >= 23) {
printf("\n Parabens %s, mostrou ter grande conhecimento da serie, sua pontuacao final foi de %d!  ",nome,pontos);
system("color 0A");
}else if(pontos >=13 && pontos <= 22) {
printf("\n %s sua pontuacao foi %d pontos, parabens! ",nome,pontos);
system("color 02");
}else {
printf("\n %s infelizmente voce nao foi tao bem, sua pontuacao foi de %d! QUE TAL DAR UMA MARATONADA? :) ",nome,pontos);
system("color 0C");
} 
    
     //Pergunta ao usuario se deseja continuar jogando
     printf("\n\n DESEJA JOGAR NOVAMENTE? (S/N)");
     scanf(" %c", &jogardnv);
     pontos = 0;
}
} 
