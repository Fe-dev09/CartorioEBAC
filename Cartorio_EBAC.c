#include <stdio.h> //bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bliblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de loca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

    
int registro()//Fun��o responsavel por cadastra usu�rios no sistema
{
	//Inicio de cria�a� de vari�veis/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
	//Final de cria�a� de vari�veis/string

    printf("Digite o CPF a ser cadastrado: ");//coleta de infima��es de usu�rio
    scanf("%s", cpf);//"%s" refere-se a string
    
    strcpy(arquivo, cpf);//Responsavel por copiar os valores das string
    
    FILE *file;//cria o arquivo
    file = fopen(arquivo, "w");//cria o arquivo e "w" siginifica "escrever"
    fprintf(file,cpf);//salva o valor da variavel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//abrindo o arquivo e "a" siginifica "atualizar"
    fprintf(file,",");//comando pra adicionar ","
    fclose(file);//Fenchando aquivo
    
    printf("Digite o nome a ser cadastrado: ");//informando sobre a coleta de infima��es de usu�rio
    scanf("%s",nome);//"%s" refere-se a string
    
    file = fopen(arquivo, "a");//abrindo o aquivo, comando "a" para atualiza
    fprintf(file,nome);//salva o valor da variavel
    fclose(file);//Fechando arquivo
    
    file = fopen(arquivo, "a");//abrindo o aquivo, comando "a" para atualiza
    fprintf(file,",");//comando pra adicionar ","
    fclose(file);//Fechando arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");//informando sobre a coleta de infima��es de usu�rio
    scanf("%s", sobrenome);//"%s" refere-se a string
    
    file = fopen(arquivo, "a");//abrindo o aquivo, comando "a" para atualiza
    fprintf(file,sobrenome);//salva o valor da variavel
    fclose(file);//Fechando arquivo
    
    file = fopen(arquivo, "a");//abrindo o aquivo, comando "a" para atualiza
    fprintf(file,",");//comando pra adicionar ","
    fclose(file);//Fechando arquivo
    
    printf("Digite o cargo a ser cadastrado: ");//informando sobre a coleta de infima��es de usu�rio
    scanf("%s", cargo);//"%s" refere-se a string
    
    file = fopen(arquivo, "a");//abrindo o aquivo, comando "a" para atualiza
    fprintf(file,cargo);//salva o valor da variavel
    fclose(file);//Fechando arquivo
    
    file = fopen(arquivo, "a");//abrindo o aquivo, comando "a" para atualiza
    fprintf(file,",");//comando pra adicionar ","
    fclose(file);//Fechando arquivo
    
    system("pause");//Comando para pausa o sistama
}
int escolharegistro()
{
	//Definindo vari�veis
	int opcao=0;
	int laco=1;
	//Fim das defini��es de vari�vis
	
	for(laco=1;laco=1;)//Fun��o de repeti��o
	{
		system("cls");//responsavel por limpar a tela
		
		printf("Deseja continuar o Registro?\n\n");//Op��es de escolhas
		printf("\t1 - sim\n");
        printf("\t2 - n�o\n\n");
        printf("Op��o: ");//Fim da op��o
        
        scanf("%d", &opcao);//Armazenando a escolha do usu�rio
        system("cls");//Limpando op��es
        switch(opcao)//Inicio de sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			return 0;//Retorna ao inico do progama
			break;
			
			default:
			printf("Essa escolha n�o est� disponivel!\n");//informando o usu�rio
			system("pause");//Comando para pausa o sistama
			break;//Fim de sele��o	
	    }
    }
}

int consulta()//Fun��o responsavel por consilta os dados do usu�rios no sistema
{
	setlocale (LC_ALL, "Portuguese");//Definindo a linguagem
	
	//Inicio de cria�a� de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Final de cria�a� de vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");//informando sobre a coleta de infima��es de usu�rio
	scanf("%s",cpf);//"%s" refere-se a string
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//abrindo o aquivo, comando "r" siginifica ler
	
	if(file == NULL)//comando pra se casos o arqivo n�o seja encontrado ("NULL" siginifica nenhum/nada) ("==" siginifica igual)
	{
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado!.\n");//informa��es para o usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL)//comando para uma a��o repetitiva
	{
		printf("\nEssas s�o as informa��es do usu�rio;\n          ");//informa��es para o usu�rio
		printf("%s", conteudo);//"%s" refere-se a string
		printf("\n\n");//comando de quebra de linha
	}
	
	fclose(file);//Fechando arquivo
	system("pause");//Comando para pausa o sistama
}
int escolhaconsulta()
{
	//Definindo vari�veis
	int opcao=0;
	int laco=1;
	//Fim das defini��es de vari�vis
	
	for(laco=1;laco=1;)//Fun��o de repeti��o
	{
		system("cls");//responsavel por limpar a tela
		
		printf("Deseja continuar a Consulta?\n\n");//Op��es de escolhas
		printf("\t1 - sim\n");
        printf("\t2 - n�o\n\n");
        printf("Op��o: ");//Fim da op��o
        
        scanf("%d", &opcao);//Armazenando a escolha do usu�rio
        system("cls");//Limpando op��es
        switch(opcao)//Inicio de sele��o do menu
		{
			case 1:
			consulta();//chamada de fun��es
			break;
			
			case 2:
			return 0;//Retorna ao inico do progama
			break;
			
			default:
			printf("Essa escolha n�o est� disponivel!\n");//informando o usu�rio
			system("pause");//Comando para pausa o sistama
			break;//Fim de sele��o	
	    }
    }
}

int deletar()//Fun��o responsavel por deleta os dados do usu�rios do sistema
{
	char cpf[40];//Criando vari�vel/sting
	
	printf("Digite o CPF a ser deletado: ");//informando sobre a coleta de infima��es de usu�rio
	scanf("%s",cpf);//"%s" refere-se a string
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//abrindo o aquivo, comando "r" siginifica ler
	fclose(file);//Fechando arquivo
	
	if(file == NULL)//comando pra se casos o arqivo n�o exista ou n�o seja encontrado ("NULL" siginifica nenhum/nada) ("==" siginifica igual)
	{
		printf("\nO usu�rio n�o encontrado!.\n");//informa��es para o usu�rio
		system("pause");//Comando para pausa o sistama
	}
	else//caso ele encontre um arquivo com as defini��es do usuaria ele vai execulta esse comando
	{
		remove(cpf);//comando para deleta a informa��o do usu�rio
		printf("\nUsu�rio deletado com sucesso!.\n");//comando para informa que os dados foram deletados
    	system("pause");//Comando para pausa o sistama
	}
}
int escolhadeletar() //Op��o de escolha para retorna ao menu
{
	//Definindo vari�veis
	int opcao=0;
	int laco=1;
	//Fim das defini��es de vari�vis
	
	for(laco=1;laco=1;)//Fun��o de repeti��o
	{
		system("cls");//responsavel por limpar a tela
		
		printf("Deseja continuar a Exclus�o?\n\n");//Op��es de escolhas
		printf("\t1 - sim\n");
        printf("\t2 - n�o\n\n");
        printf("Op��o: ");//Fim da op��o
        
        scanf("%d", &opcao);//Armazenando a escolha do usu�rio
        system("cls");//Limpando op��es
        switch(opcao)//Inicio de sele��o do menu
		{
			case 1:
			deletar();//chamada de fun��es
			break;
			
			case 2:
			return 0;//Retorna ao inico do progama
			break;
			
			default:
			printf("Essa escolha n�o est� disponivel!\n");//informando o usu�rio
			system("pause");//Comando para pausa o sistama
			break;//Fim de sele��o	
	    }
    }
}

int main ()
{
	//Definindo vari�veis
	int opcao=0;
	int laco=1;
	//Fim das defini��es de vari�vis
	
	for(laco=1;laco=1;)//Fun��o de repeti��o
	{
		system("cls");//responsavel por limpar a tela
		
		setlocale (LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");//Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Cadastrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("Op��o: ");//Fim do menu
	
	
		scanf("%d", &opcao);//Armazenando a escolha do usu�rio
	
		system("cls");//Limpando op��es
		
		switch(opcao)//Inicio de sele��o do menu
		{
			case 1:
			escolharegistro();//chamada de fun��es
			break;
			
			case 2:
			escolhaconsulta();//chamada de fun��es
			break;
			
			case 3:
			escolhadeletar();//chamada de fun��es
			break;
			
			default:
			printf("Essa escolha n�o est� disponivel!\n");//informando o usu�rio
			system("pause");//Comando para pausa o sistama
			break;//Fim de sele��o		
		}
	
	}
}
