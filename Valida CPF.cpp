#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validcpf(char cpf[15]){
	int soma=0, i, j=10, num;
	char resto[3], codv[3], n;
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
	if(strcmp(resto, codv)==0)
		return 1;
	else
		return 0;
}
int main(void){
	char cpf[14];
	printf("CPF: ");
	fflush(stdin);
	gets(cpf);
	if(validcpf(cpf)==1)
		printf("Valido");
	else
		printf("Invalio");
	return 0;
}
