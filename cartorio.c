#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria, quando se trabalha com vari�veis etc
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro () //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); // scanf scaneia e salva - %s refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa write
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);	
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);	
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);	
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! .\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //serve para deletar
	
	FILE *file; //acessar o arquivo
	file = fopen(cpf, "r"); //abre o arquivo para procurar
	
	if(file == NULL) //valida��o
	{
		printf("O usu�rio n�o se encontra no sistema! .\n");
	}	system("pause");
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		system("cls"); //Clear screen
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem para portugu�s
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes: \n");
        printf("\t2 - Consultar nomes: \n");
        printf("\t3 - Deletar nomes: \n\n");
        printf("Op��o: "); //Fim do menu
        
        scanf("%d", &opcao); //Armazenando a escolha do usu�rio

        system("cls");
        
        switch(opcao) //in�cio da sele��o do menu
        {
            case 1:
            printf("Voc� escolheu o registro de nomes! \n");
            system("pause");
            break;

            case 2:
            printf("Voc� escolheu consultar os nomes! \n");
            system("pause");
            break;

            case 3:
            printf("Voc� escolheu deletar nomes! \n");
            system("pause");
            break;

            default:
            printf("Essa op��o n�o est� dispon�vel! \n");
            system("pause");
            break;
        } //fim da sele��o
	}
}
