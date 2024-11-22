#include <stdio.h> //bliblioteca de comunicação com o usuário
#include <stdlib.h> //bliblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de locações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

    
int registro()//Função responsavel por cadastra usuários no sistema
{
	//Inicio de criaçaõ de variáveis/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
	//Final de criaçaõ de variáveis/string

    printf("Digite o CPF a ser cadastrado: ");//coleta de infimações de usuário
    scanf("%s", cpf);//"%s" refere-se a string
    
    strcpy(arquivo, cpf);//Responsavel por copiar os valores das string
    
    FILE *file;//cria o arquivo
    file = fopen(arquivo, "w");//cria o arquivo e "w" siginifica "escrever"
    fprintf(file,cpf);//salva o valor da variavel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//abrindo o arquivo e "a" siginifica "atualizar"
    fprintf(file,",");//comando pra adicionar ","
    fclose(file);//Fenchando aquivo
    
    printf("Digite o nome a ser cadastrado: ");//informando sobre a coleta de infimações de usuário
    scanf("%s",nome);//"%s" refere-se a string
    
    file = fopen(arquivo, "a");//abrindo o aquivo, comando "a" para atualiza
    fprintf(file,nome);//salva o valor da variavel
    fclose(file);//Fechando arquivo
    
    file = fopen(arquivo, "a");//abrindo o aquivo, comando "a" para atualiza
    fprintf(file,",");//comando pra adicionar ","
    fclose(file);//Fechando arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");//informando sobre a coleta de infimações de usuário
    scanf("%s", sobrenome);//"%s" refere-se a string
    
    file = fopen(arquivo, "a");//abrindo o aquivo, comando "a" para atualiza
    fprintf(file,sobrenome);//salva o valor da variavel
    fclose(file);//Fechando arquivo
    
    file = fopen(arquivo, "a");//abrindo o aquivo, comando "a" para atualiza
    fprintf(file,",");//comando pra adicionar ","
    fclose(file);//Fechando arquivo
    
    printf("Digite o cargo a ser cadastrado: ");//informando sobre a coleta de infimações de usuário
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
	//Definindo variáveis
	int opcao=0;
	int laco=1;
	//Fim das definições de variávis
	
	for(laco=1;laco=1;)//Função de repetição
	{
		system("cls");//responsavel por limpar a tela
		
		printf("Deseja continuar o Registro?\n\n");//Opções de escolhas
		printf("\t1 - sim\n");
        printf("\t2 - não\n\n");
        printf("Opção: ");//Fim da opção
        
        scanf("%d", &opcao);//Armazenando a escolha do usuário
        system("cls");//Limpando opções
        switch(opcao)//Inicio de seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			return 0;//Retorna ao inico do progama
			break;
			
			default:
			printf("Essa escolha não está disponivel!\n");//informando o usuário
			system("pause");//Comando para pausa o sistama
			break;//Fim de seleção	
	    }
    }
}

int consulta()//Função responsavel por consilta os dados do usuários no sistema
{
	setlocale (LC_ALL, "Portuguese");//Definindo a linguagem
	
	//Inicio de criaçaõ de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Final de criaçaõ de variáveis/string
	
	printf("Digite o CPF a ser consultado: ");//informando sobre a coleta de infimações de usuário
	scanf("%s",cpf);//"%s" refere-se a string
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//abrindo o aquivo, comando "r" siginifica ler
	
	if(file == NULL)//comando pra se casos o arqivo não seja encontrado ("NULL" siginifica nenhum/nada) ("==" siginifica igual)
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado!.\n");//informações para o usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)//comando para uma ação repetitiva
	{
		printf("\nEssas são as informações do usuário;\n          ");//informações para o usuário
		printf("%s", conteudo);//"%s" refere-se a string
		printf("\n\n");//comando de quebra de linha
	}
	
	fclose(file);//Fechando arquivo
	system("pause");//Comando para pausa o sistama
}
int escolhaconsulta()
{
	//Definindo variáveis
	int opcao=0;
	int laco=1;
	//Fim das definições de variávis
	
	for(laco=1;laco=1;)//Função de repetição
	{
		system("cls");//responsavel por limpar a tela
		
		printf("Deseja continuar a Consulta?\n\n");//Opções de escolhas
		printf("\t1 - sim\n");
        printf("\t2 - não\n\n");
        printf("Opção: ");//Fim da opção
        
        scanf("%d", &opcao);//Armazenando a escolha do usuário
        system("cls");//Limpando opções
        switch(opcao)//Inicio de seleção do menu
		{
			case 1:
			consulta();//chamada de funções
			break;
			
			case 2:
			return 0;//Retorna ao inico do progama
			break;
			
			default:
			printf("Essa escolha não está disponivel!\n");//informando o usuário
			system("pause");//Comando para pausa o sistama
			break;//Fim de seleção	
	    }
    }
}

int deletar()//Função responsavel por deleta os dados do usuários do sistema
{
	char cpf[40];//Criando variável/sting
	
	printf("Digite o CPF a ser deletado: ");//informando sobre a coleta de infimações de usuário
	scanf("%s",cpf);//"%s" refere-se a string
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//abrindo o aquivo, comando "r" siginifica ler
	fclose(file);//Fechando arquivo
	
	if(file == NULL)//comando pra se casos o arqivo não exista ou não seja encontrado ("NULL" siginifica nenhum/nada) ("==" siginifica igual)
	{
		printf("\nO usuário não encontrado!.\n");//informações para o usuário
		system("pause");//Comando para pausa o sistama
	}
	else//caso ele encontre um arquivo com as definições do usuaria ele vai execulta esse comando
	{
		remove(cpf);//comando para deleta a informação do usuário
		printf("\nUsuário deletado com sucesso!.\n");//comando para informa que os dados foram deletados
    	system("pause");//Comando para pausa o sistama
	}
}
int escolhadeletar() //Opção de escolha para retorna ao menu
{
	//Definindo variáveis
	int opcao=0;
	int laco=1;
	//Fim das definições de variávis
	
	for(laco=1;laco=1;)//Função de repetição
	{
		system("cls");//responsavel por limpar a tela
		
		printf("Deseja continuar a Exclusão?\n\n");//Opções de escolhas
		printf("\t1 - sim\n");
        printf("\t2 - não\n\n");
        printf("Opção: ");//Fim da opção
        
        scanf("%d", &opcao);//Armazenando a escolha do usuário
        system("cls");//Limpando opções
        switch(opcao)//Inicio de seleção do menu
		{
			case 1:
			deletar();//chamada de funções
			break;
			
			case 2:
			return 0;//Retorna ao inico do progama
			break;
			
			default:
			printf("Essa escolha não está disponivel!\n");//informando o usuário
			system("pause");//Comando para pausa o sistama
			break;//Fim de seleção	
	    }
    }
}

int main ()
{
	//Definindo variáveis
	int opcao=0;
	int laco=1;
	//Fim das definições de variávis
	
	for(laco=1;laco=1;)//Função de repetição
	{
		system("cls");//responsavel por limpar a tela
		
		setlocale (LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");//Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Cadastrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("Opção: ");//Fim do menu
	
	
		scanf("%d", &opcao);//Armazenando a escolha do usuário
	
		system("cls");//Limpando opções
		
		switch(opcao)//Inicio de seleção do menu
		{
			case 1:
			escolharegistro();//chamada de funções
			break;
			
			case 2:
			escolhaconsulta();//chamada de funções
			break;
			
			case 3:
			escolhadeletar();//chamada de funções
			break;
			
			default:
			printf("Essa escolha não está disponivel!\n");//informando o usuário
			system("pause");//Comando para pausa o sistama
			break;//Fim de seleção		
		}
	
	}
}
