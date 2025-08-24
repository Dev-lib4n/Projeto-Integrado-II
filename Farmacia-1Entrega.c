#include <stdio.h>
#include <ctype.h>
#include <conio2.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// CONSTANTES 

// STRUCTS

// FUNÇÕES DE TELA

void limpatela(int XI, int XF, int YI, int YF){
	int i, j;
	textcolor(BLACK);
	for(i=YI;i<=YF;i++)
		for(j=XI;j<=XF;j++){
			gotoxy(j,i);
			printf("%c", 219);
		}
	textcolor(WHITE);
}

void moldura(void){
	int i,j,CF=80, CI=1, LI=1, LF=25;
	setlocale(LC_ALL, "C");	
	gotoxy(1,1);
	printf("%c", 201);
	gotoxy(80,1);
	printf("%c", 187);
	gotoxy(1,25);
	printf("%c", 200);
	gotoxy(80,25);
	printf("%c", 188);
	for(i=CI+1;i<CF;i++){
		gotoxy(i,1);
		printf("%c",205);
		gotoxy(i,25);
		printf("%c",205);
	}
	for(i=LI+1;i<LF;i++){
		gotoxy(1,i);
		printf("%c",186);
		gotoxy(80,i);
		printf("%c",186);
	}
	gotoxy(1,23);
	printf("%c", 204);
	gotoxy(80,23);
	printf("%c", 185);
	for(i=CI+1;i<CF;i++){
		gotoxy(i,23);
		printf("%c",205);
	}
	gotoxy(1,5);
	printf("%c", 204);
	gotoxy(80,5);
	printf("%c", 185);
	for(i=CI+1;i<CF;i++){
		gotoxy(i,5);
		printf("%c",205);
	}
	gotoxy(26,5);
	printf("%c", 203);
	gotoxy(26,23);
	printf("%c", 202);
	for(i=LI+5;i<LF-2;i++){
		gotoxy(26,i);
		printf("%c",186);
	}
	gotoxy(1,7);
	printf("%c", 204);
	gotoxy(26,7);
	printf("%c", 185);
	for(i=2;i<26;i++){
		gotoxy(i,7);
		printf("%c",205);
	}
	gotoxy(9,6);
	printf("---MENU---");
	gotoxy(38,3);
	printf("DROGA+");
	
	setlocale(LC_ALL, "Portuguese");
}
void limpamenu(void){
	limpatela(2, 25, 8, 22);
}
void limpamonitor(void){
	limpatela(27, 79, 6, 22);
}
void limpamensagem(void){
	limpatela(2, 79, 24, 24);
}
void limpasubmenu(void){
	limpatela(2, 25, 6, 6);
}

// FUNÇÕES

// MENUS

void menuclientes(){
	char opc;	
	do{
		limpamenu();
		limpasubmenu();
		gotoxy(7,6);
		printf("---CLIENTES---");
		gotoxy(3,9);
		printf("[A] - Cadastrar");
		gotoxy(3,11);
		printf("[B] - Consultar");
		gotoxy(3,13);
		printf("[C] - Excluir");
		gotoxy(3,15);
		printf("[D] - Relatório");
		limpamensagem();
		gotoxy(2,24);
		printf("Selecione uma opção...                              Pressione ESC para VOLTAR");
		gotoxy(24,24);
		opc=toupper(getche());		
		switch(opc){
			case 'A':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'B':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'C':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'D':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
				break;
			default:
				if(opc!=27){
					limpatela(2, 79, 24, 24);
					gotoxy(2,24);
					printf("Opção inválida, selecione outra opção...");
					Sleep(1500);
				}
				break;
		}
	}while(opc!=27);
}
void menulaboratorios(){
	char opc;	
	do{
		limpamenu();
		limpasubmenu();
		gotoxy(5,6);
		printf("---LABORATÓRIOS---");
		gotoxy(3,9);
		printf("[A] - Cadastrar");
		gotoxy(3,11);
		printf("[B] - Consultar");
		gotoxy(3,13);
		printf("[C] - Excluir");
		gotoxy(3,15);
		printf("[D] - Relatório");
		limpamensagem();
		gotoxy(2,24);
		printf("Selecione uma opção...                              Pressione ESC para VOLTAR");
		gotoxy(24,24);
		opc=toupper(getche());		
		switch(opc){
			case 'A':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'B':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'C':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'D':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
				break;
			default:
				if(opc!=27){
					limpatela(2, 79, 24, 24);
					gotoxy(2,24);
					printf("Opção inválida, selecione outra opção...");
					Sleep(1500);
				}
		}
	}while(opc!=27);
}
void menuprodutos(){
	char opc;	
	do{
		limpamenu();
		limpasubmenu();
		gotoxy(7,6);
		printf("---PRODUTOS---");
		gotoxy(3,9);
		printf("[A] - Cadastrar");
		gotoxy(3,11);
		printf("[B] - Consultar");
		gotoxy(3,13);
		printf("[C] - Excluir");
		gotoxy(3,15);
		printf("[D] - Relatório");
		limpamensagem();
		gotoxy(2,24);
		printf("Selecione uma opção...                              Pressione ESC para VOLTAR");
		gotoxy(24,24);
		opc=toupper(getche());		
		switch(opc){
			case 'A':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'B':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'C':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'D':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
				break;
			default:
				if(opc!=27){
					limpatela(2, 79, 24, 24);
					gotoxy(2,24);
					printf("Opção inválida, selecione outra opção...");
					Sleep(1500);
				}
		}
	}while(opc!=27);
}
void menuvendas(){
	char opc;	
	do{
		limpamenu();
		limpasubmenu();
		gotoxy(8,6);
		printf("---VENDAS---");
		gotoxy(3,9);
		printf("[A] - Cadastrar");
		gotoxy(3,11);
		printf("[B] - Consultar");
		gotoxy(3,13);
		printf("[C] - Excluir");
		gotoxy(3,15);
		printf("[D] - Relatório");
		limpamensagem();
		gotoxy(2,24);
		printf("Selecione uma opção...                              Pressione ESC para VOLTAR");
		gotoxy(24,24);
		opc=toupper(getche());
		
		switch(opc){
			case 'A':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'B':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'C':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'D':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
				break;
			default:
				if(opc!=27){
					limpatela(2, 79, 24, 24);
					gotoxy(2,24);
					printf("Opção inválida, selecione outra opção...");
					Sleep(1500);
				}
		}
	}while(opc!=27);
}
void menurelatorios(){
	char opc;	
	do{
		limpamenu();
		limpasubmenu();
		gotoxy(6,6);
		printf("---RELATÓRIOS---");
		gotoxy(3,9);
		printf("[A] - Relatório1");
		gotoxy(3,11);
		printf("[B] - Relatório2");
		gotoxy(3,13);
		printf("[C] - Relatório3");
		gotoxy(3,15);
		printf("[D] - Relatório4");
		limpamensagem();
		gotoxy(2,24);
		printf("Selecione uma opção...                              Pressione ESC para VOLTAR");
		gotoxy(24,24);
		opc=toupper(getche());
		switch(opc){
			case 'A':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'B':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'C':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
			break;
			case 'D':
				limpamensagem();
				textcolor(RED);
				gotoxy(2,24);
				printf("Em Construção...");
				Sleep(1500);
				textcolor(WHITE);
				break;
			default:
				if(opc!=27){
					limpatela(2, 79, 24, 24);
					gotoxy(2,24);
					printf("Opção inválida, selecione outra opção...");
					Sleep(1500);
				}
		}
	}while(opc!=27);
}
void menu(void){
	char opc;
	do{
		limpamenu();
		limpasubmenu();
		gotoxy(9,6);
		printf("---MENU---");
		gotoxy(3,9);
		printf("[A] - Clientes");
		gotoxy(3,11);
		printf("[B] - Laboratórios");
		gotoxy(3,13);
		printf("[C] - Produtos");
		gotoxy(3,15);
		printf("[D] - Vendas");
		gotoxy(3,17);
		printf("[E] - Relatórios");
		limpamensagem();
		gotoxy(2,24);
		printf("Selecione uma opção...                                Pressione ESC para SAIR");
		gotoxy(24,24);
		opc=toupper(getche());	
		switch(opc){
			case 'A':
				menuclientes();
			break;
			case 'B':
				menulaboratorios();
			break;
			case 'C':
				menuprodutos();
			break;
			case 'D':
				menuvendas();
				break;
			case 'E':
				menurelatorios();
				break;
			default:
				if(opc!=27){
					limpatela(2, 79, 24, 24);
					gotoxy(2,24);
					printf("Opção inválida, selecione outra opção...");
					Sleep(1500);
				}
		}
		if(opc==27){
			do{
				limpatela(2, 79, 24, 24);
				gotoxy(2,24);
				printf("Deseja Sair? (S/N)...");
				opc=toupper(getche());
				if(opc!='S' && opc!='N'){
					limpatela(2, 79, 24, 24);
					gotoxy(2,24);
					printf("Opção inválida, selecione outra opção...");
					Sleep(1500);
				}
			}while(opc!='S' && opc!='N');
			if(opc=='S')
				opc=27;
			else
				opc=0;
		}
	}while(opc!=27);
}

// MAIN

int main(void){
	
	moldura();
	menu();
	gotoxy(1,26);
	return 0;
}
