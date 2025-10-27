#include <stdio.h>
#include <ctype.h>
#include <conio2.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// CONSTANTES 

#define TF 100

// STRUCTS

typedef struct{
	int dia, mes, ano;
}tpdata;

typedef struct{
	int num;
	char cidade[50], estado[3], pais[20], rua[50];
}tpendereco;

typedef struct{
	tpendereco end;
	int cod, ddd, tel;
	char nome[50], cnpj[20];
}tplab;

typedef struct{
	tpdata validade;
	tpdata fab;
	tplab lab;
	int quant, cod, lote;
	float valorC, valorV;
	char desc[50];
}tpproduto;

typedef struct{
	tpendereco end;
	tpdata nasc;
	int	ddd, tel;
	char cpf[15], nome[50];
}tpcliente;

typedef struct{
	tpdata datanota;
	tpproduto prod[TF];
	int nf, TLNota;
}tpvendas;

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
void mensagemerro(void){
	limpamensagem();
	textcolor(RED);
	gotoxy(2,24);
	printf("Erro na abertura do arquivo...");
	Sleep(1500);
	textcolor(WHITE);
}

// BUSCAS

int buscacliente(FILE *ptrcli, char cpfaux[15]){
	tpcliente reg;
	fseek(ptrcli,0,0);
	if(!feof(ptrcli)){
		fread(&reg, sizeof(tpcliente), 1, ptrcli);
		while(!feof(ptrcli) && strcmp(cpfaux, reg.cpf)!=0){
			fread(&reg, sizeof(tpcliente), 1, ptrcli);
		}
		if(!feof(ptrcli) && strcmp(cpfaux, reg.cpf)==0){
			fseek(ptrcli,-sizeof(tpcliente),1);
			return ftell(ptrcli);
		}
		else
			return -1;  
	}else
		return -1;
}

int buscalab(FILE *ptrlab, int codaux){
	tplab reg;
	fseek(ptrlab,0,0);
	if(!feof(ptrlab)){
		fread(&reg, sizeof(tplab), 1, ptrlab);
		while(!feof(ptrlab) && codaux!=reg.cod){
			fread(&reg, sizeof(tplab), 1, ptrlab);
		}
		if(!feof(ptrlab) && codaux==reg.cod){
			fseek(ptrlab,-sizeof(tplab),1);
			return ftell(ptrlab);
		}
		else
			return -1; 
	}else
		return -1;
}

int buscaprod(FILE *ptrprod, int codaux){
	tpproduto reg;
	fseek(ptrprod,0,0);
	if(!feof(ptrprod)){
		fread(&reg, sizeof(tpproduto), 1, ptrprod);
		while(!feof(ptrprod) && codaux!=reg.cod){
			fread(&reg, sizeof(tpproduto), 1, ptrprod);
		}
		if(!feof(ptrprod) && codaux==reg.cod){
			fseek(ptrprod,-sizeof(tpproduto),1);
			return ftell(ptrprod);
		}
		else
			return -1; 
	}else
		return -1;
}

int buscavendas(FILE *ptrvenda, int nfaux){
	tpvendas reg;
	fseek(ptrvenda,0,0);
	if(!feof(ptrvenda)){
		fread(&reg, sizeof(tpvendas), 1, ptrvenda);
		while(!feof(ptrvenda) && nfaux!=reg.nf){
			fread(&reg, sizeof(tpvendas), 1, ptrvenda);
		}
		if(!feof(ptrvenda) && nfaux==reg.nf){
			fseek(ptrvenda,-sizeof(tpvendas),1);
			return ftell(ptrvenda);
		}
		else
			return -1; 
	}else
		return -1;
}

// FUNÇÕES DO CPF E CNPJ

void convertecpf(char cpf[15]){
	cpf[14]='\0';
	cpf[13]=cpf[10];
	cpf[12]=cpf[9];
	cpf[11]='-';
	cpf[10]=cpf[8];
	cpf[9]=cpf[7];
	cpf[8]=cpf[6];
	cpf[7]='.';
	cpf[6]=cpf[5];
	cpf[5]=cpf[4];
	cpf[4]=cpf[3];
	cpf[3]='.';
}

void revertecpf(char cpf[15]){
	cpf[3]=cpf[4];
	cpf[4]=cpf[5];
	cpf[5]=cpf[6];
	cpf[6]=cpf[8];
	cpf[7]=cpf[9];
	cpf[8]=cpf[10];
	cpf[9]=cpf[12];
	cpf[10]=cpf[13];
	cpf[11]='\0';
}

void convertecnpj(char cnpj[20]){
	cnpj[18]='\0';
	cnpj[17]=cnpj[13];
	cnpj[16]=cnpj[12];
	cnpj[15]='-';
	cnpj[14]=cnpj[11];
	cnpj[13]=cnpj[10];
	cnpj[12]=cnpj[9];
	cnpj[11]=cnpj[8];
	cnpj[10]='/';
	cnpj[9]=cnpj[7];
	cnpj[8]=cnpj[6];
	cnpj[7]=cnpj[5];
	cnpj[6]='.';
	cnpj[5]=cnpj[4];
	cnpj[4]=cnpj[3];
	cnpj[3]=cnpj[2];
	cnpj[2]='.';
}

void revertecnpj(char cnpj[20]){
	cnpj[2]=cnpj[3];
	cnpj[3]=cnpj[4];
	cnpj[4]=cnpj[5];
	cnpj[5]=cnpj[7];
	cnpj[6]=cnpj[8];
	cnpj[7]=cnpj[9];
	cnpj[8]=cnpj[11];
	cnpj[9]=cnpj[12];
	cnpj[10]=cnpj[13];
	cnpj[11]=cnpj[14];
	cnpj[12]=cnpj[16];
	cnpj[13]=cnpj[17];
	cnpj[14]='\0';
}

int validcpf(char cpf[15]){
	int soma=0, i, j=10, num;
	char resto[3], codv[3], n;
	revertecpf(cpf);
	codv[0]=cpf[9];
	codv[1]=cpf[10];
	codv[2]='\0';
	resto[2]='\0';
	for(i=0;i<9;i++, j--){
		n=cpf[i];
		num=n-'0';
		soma+=num*j;
	}
	num=soma%11;
	if(num<2)
		num=0;
	else
		num=11-num;
	resto[0]='0'+num;
	soma=0;
	j=11;
	for(i=0;i<9;i++, j--){
		n=cpf[i];
		num=n-'0';
		soma+=num*j;
	}
	n=resto[0];
	num=n-'0';
	soma+=num*2;
	num=soma%11;
	if(num<2)
		num=0;
	else
		num=11-num;
	resto[1]='0'+num;
	convertecpf(cpf);
	if(strcmp(resto, codv)==0)
		return 1;
	else
		return 0;
}

//FUNÇÕES

//CADASTROS

void cadcliente(){
	tpcliente cliente;
	FILE *cli;
	cli=fopen("clientes.dat","ab+");
	if(cli==NULL){
		mensagemerro();
	}else{
		do{
			do{
				limpamensagem();
				gotoxy(2,24);
				printf("Escreva as informações do cliente...              Pressione ENTER para VOLTAR");
				limpamonitor();
				gotoxy(28,6);
				printf("Cpf: ");
				fflush(stdin);
				gets(cliente.cpf);
				if(strcmp(cliente.cpf, "\0")!=0)
					convertecpf(cliente.cpf);
				if(buscacliente(cli, cliente.cpf)!=-1 && strcmp(cliente.cpf, "\0")!=0){
					limpamensagem();
					textcolor(RED);
					gotoxy(2,24);
					printf("Usuário já cadastrado, digite um cpf diferente...");
					Sleep(1500);
					textcolor(WHITE);
				}
				if(validcpf(cliente.cpf)!=1 && strcmp(cliente.cpf, "\0")!=0){
					limpamensagem();
					textcolor(RED);
					gotoxy(2,24);
					printf("Cpf inválido, digite somente números...");
					Sleep(1500);
					textcolor(WHITE);
				}
			}while((buscacliente(cli, cliente.cpf)!=-1 || validcpf(cliente.cpf)!=1) && strcmp(cliente.cpf, "\0")!=0);
			if(strcmp(cliente.cpf, "\0")!=0){
				limpamensagem();
				gotoxy(2,24);
				printf("Escreva as informações do cliente...");
				gotoxy(28,7);
				printf("Nome: ");
				fflush(stdin);
				gets(cliente.nome);
				gotoxy(28,8);
				printf("DDD e Telefone: ");
				scanf("%d %d", &cliente.ddd, &cliente.tel);
				gotoxy(28,9);
				printf("Data de nascimento: ");
				scanf("%d %d %d", &cliente.nasc.dia, &cliente.nasc.mes, &cliente.nasc.ano);
				gotoxy(28,10);
				printf("Endereço da residência: ");
				fflush(stdin);
				gets(cliente.end.rua);
				gotoxy(28,11);
				printf("Número da residência: ");
				scanf("%d", &cliente.end.num);
				gotoxy(28,12);
				printf("Cidade: ");
				fflush(stdin);
				gets(cliente.end.cidade);
				gotoxy(28,13);
				printf("Estado: ");
				fflush(stdin);
				gets(cliente.end.estado);
				gotoxy(28,14);
				printf("País: ");
				fflush(stdin);
				gets(cliente.end.pais);
				fseek(cli,0,2);
				fwrite(&cliente, sizeof(tpcliente), 1, cli);
			}
		}while(strcmp(cliente.cpf, "\0")!=0);
	}
	fclose(cli);
	limpamonitor();
}

void cadlab(){
	int codaux;
	tplab laboratorio;
	FILE *lab;
	lab=fopen("laboratorios.dat","ab+");
	if(lab==NULL){
		mensagemerro();
	}else{
		do{
			do{
				do{
					limpamensagem();
					gotoxy(2,24);
					printf("Escreva as informações do laboratório...                 digite 0 para VOLTAR");
					limpamonitor();
					gotoxy(28,6);
					printf("Código: ");
					scanf("%d", &codaux);
					if(codaux>9999 || codaux<1000 && codaux!=0){
						limpamensagem();
						textcolor(RED);
						gotoxy(2,24);
						printf("O código deve ter 4 dígitos...");
						Sleep(1500);
						textcolor(WHITE);
					}else
						if(buscalab(lab,codaux)!=-1 && codaux!=0){
							limpamensagem();
							textcolor(RED);
							gotoxy(2,24);
							printf("Laboratório já cadastrado, digite um código diferente...");
							Sleep(1500);
							textcolor(WHITE);
						}
				}while(codaux>9999 || codaux<1000 && codaux!=0);
			}while(buscalab(lab,codaux)!=-1 && codaux!=0);
			if(codaux!=0){
				laboratorio.cod=codaux;
				limpamensagem();
				gotoxy(2,24);
				printf("Escreva as informações do laboratório...");
				gotoxy(28,7);
				printf("Cnpj: ");
				fflush(stdin);
				gets(laboratorio.cnpj);
				convertecnpj(laboratorio.cnpj);
				gotoxy(28,8);
				printf("Razão Social: ");
				fflush(stdin);
				gets(laboratorio.nome);
				gotoxy(28,9);
				printf("DDD e Telefone: ");
				scanf("%d %d", &laboratorio.ddd, &laboratorio.tel);
				gotoxy(28,10);
				printf("Endereço do laboratório: ");
				fflush(stdin);
				gets(laboratorio.end.rua);
				gotoxy(28,11);
				printf("Número do laboratório: ");
				scanf("%d", &laboratorio.end.num);
				gotoxy(28,12);
				printf("Cidade: ");
				fflush(stdin);
				gets(laboratorio.end.cidade);
				gotoxy(28,13);
				printf("Estado: ");
				fflush(stdin);
				gets(laboratorio.end.estado);
				gotoxy(28,14);
				printf("País: ");
				fflush(stdin);
				gets(laboratorio.end.pais);
				fseek(lab,0,2);
				fwrite(&laboratorio, sizeof(tplab), 1, lab);
			}
		}while(codaux!=0);
	}
	fclose(lab);
	limpamonitor();
}

//CONSULTAS

void consultacliente(){
	tpcliente cliente;
	FILE *cli;
	cli=fopen("clientes.dat","rb+");
	if(cli==NULL){
		mensagemerro();
	}else{
		do{
			do{
				limpamensagem();
				gotoxy(2,24);
				printf("Digite o CPF para consultar..                     Pressione ENTER para VOLTAR");
				limpamonitor();
				gotoxy(28,6);
				printf("Cpf: ");
				fflush(stdin);
				gets(cliente.cpf);
				if(strcmp(cliente.cpf, "\0")!=0)
					convertecpf(cliente.cpf);
				if(buscacliente(cli, cliente.cpf)==-1 && strcmp(cliente.cpf, "\0")!=0){
					limpamensagem();
					textcolor(RED);
					gotoxy(2,24);
					printf("Usuário não encontrado, digite um cpf diferente...");
					Sleep(1500);
					textcolor(WHITE);
					limpamensagem();
					gotoxy(2,24);
					printf("Escreva as informações do cliente...");
				}
				if(validcpf(cliente.cpf)!=1 && strcmp(cliente.cpf, "\0")!=0){
					limpamensagem();
					textcolor(RED);
					gotoxy(2,24);
					printf("Cpf inválido, digite somente números...");
					Sleep(1500);
					textcolor(WHITE);
					limpamensagem();
					gotoxy(2,24);
					printf("Escreva as informações do cliente...");
				}
			}while((buscacliente(cli, cliente.cpf)==-1 || validcpf(cliente.cpf)!=1) && strcmp(cliente.cpf, "\0")!=0);
			if(strcmp(cliente.cpf, "\0")!=0){
				limpamonitor();
				fread(&cliente, sizeof(cliente), 1, cli);
				gotoxy(28,6);
				printf("CPF: %s", cliente.cpf);
				gotoxy(28,7);
				printf("Nome: %s", cliente.nome);
				gotoxy(28,8);
				printf("Telefone: (%d) %d", cliente.ddd, cliente.tel);
				gotoxy(28,9);
				printf("Nascimento: %d/%d/%d", cliente.nasc.dia, cliente.nasc.mes, cliente.nasc.ano);
				gotoxy(28,10);
				printf("Rua: %s, %d", cliente.end.rua, cliente.end.num);
				gotoxy(28,11);
				printf("Cidade: %s", cliente.end.cidade);
				gotoxy(28,12);
				printf("Estado: %s", cliente.end.estado);
				gotoxy(28,13);
				printf("País: %s", cliente.end.pais);
				limpamensagem();
				gotoxy(2,24);
				printf("Pressione qualquer tecla para continuar...");
				getch();
			}
		}while(strcmp(cliente.cpf, "\0")!=0);
	}
	fclose(cli);
	limpamonitor();
}

void consultalab(){
	int codaux;
	tplab laboratorio;
	FILE *lab;
	lab=fopen("laboratorios.dat","rb+");
	if(lab==NULL){
		mensagemerro();
	}else{
		do{
			do{
				do{
					limpamensagem();
					gotoxy(2,24);
					printf("Digite o código do laboratório...                        digite 0 para VOLTAR");
					limpamonitor();
					gotoxy(28,6);
					printf("Código: ");
					scanf("%d", &codaux);
					if(codaux>9999 || codaux<1000 && codaux!=0){
						limpamensagem();
						textcolor(RED);
						gotoxy(2,24);
						printf("O código deve ter 4 dígitos...");
						Sleep(1500);
						textcolor(WHITE);
					}else
						if(buscalab(lab,codaux)==-1 && codaux!=0){
							limpamensagem();
							textcolor(RED);
							gotoxy(2,24);
							printf("Laboratório não encontrado, digite um código diferente...");
							Sleep(1500);
							textcolor(WHITE);
						}
				}while(codaux>9999 || codaux<1000 && codaux!=0);
			}while(codaux!=0 && buscalab(lab,codaux)==-1);
			if(codaux!=0){
				limpamonitor();
				fread(&laboratorio, sizeof(tplab), 1, lab);
				gotoxy(28,6);
				printf("Código: %d", laboratorio.cod);
				gotoxy(28,7);
				printf("CNPJ: %s", laboratorio.cnpj);
				gotoxy(28,8);
				printf("Razão Social: %s", laboratorio.nome);
				gotoxy(28,9);
				printf("Telefone: (%d) %d", laboratorio.ddd, laboratorio.tel);
				gotoxy(28,10);
				printf("Rua: %s, %d", laboratorio.end.rua, laboratorio.end.num);
				gotoxy(28,11);
				printf("Cidade: %s", laboratorio.end.cidade);
				gotoxy(28,12);
				printf("Estado: %s", laboratorio.end.estado);
				gotoxy(28,13);
				printf("País: %s", laboratorio.end.pais);
				limpamensagem();
				gotoxy(2,24);
				printf("Pressione qualquer tecla para continuar...");
				getch();
			}
		}while(codaux!=0);
	}
	fclose(lab);
	limpamonitor();
}

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
				cadcliente();
			break;
			case 'B':
				consultacliente();
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
				cadlab();
			break;
			case 'B':
				consultalab();
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
		gotoxy(3,17);
		printf("[E] - Promoção");
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
			case 'E':
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
		printf("[A] - Prod. para vencer");
		gotoxy(3,11);
		printf("[B] - Baixo estoque");
		gotoxy(3,13);
		printf("[C] - Vendas no mês");
		gotoxy(3,15);
		printf("[D] - Média de compra");
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
