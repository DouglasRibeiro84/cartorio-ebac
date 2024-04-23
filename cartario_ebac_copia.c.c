#include <stdio.h> //biblicoteca de comunição com o usuário
#include <stdlib.h> // alocação de espaço de memória 
#include <locale.h> // alocação de texto pare região
#include <string.h> //biblicoteca para cuidar da string
//Observações:\t=espaço,\n=enter,"=texto,;=confirmação de comando,%d=variavel int,tab=identar


int registro() //função responsavél por cadastrar o usuário
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio de criação de string
	
	char arquivo [200];
	char cpf [40];
	char nome [100];
	char data [40];
	char sobrenome [100];
	char cargo [40];
	
	//final de criação de string
		
	printf("\t-RESGISTRAR USUÁRIO-\n\n");
	printf("CPF: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf);// copiar strings
	
	FILE * file;  //cria o arquivo
	file = fopen(arquivo,"w"); //criando o arquivo
	fprintf(file,cpf);  //salvar a variavel
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("NOME:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("SOBRENOME: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("DATA DE NASCIMENTO:");
	scanf("%s", data);
	
	file = fopen(arquivo, "a");
	fprintf(file,data);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("CARGO: ");
	scanf("%s", cargo);
	
    file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
}

int consulta()
{
 	setlocale(LC_ALL, "Portuguese");
 	
	char cpf[40];
	char conteudo[200];
	printf("\t-CONSULTAR USUÁRIO-\n\n\n");
	printf("DIGITE O CPF: ");
	scanf("%s",cpf);
	
	system("cls");
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\t-USUÁRIO NÃO LOCALIZADO-\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL )
	{
	printf("\t-INFORMAÇÕES DO USUÁRIO-\n\n");
	
	char* token = strtok(conteudo,",");  // dividindo o arquivo em token ate a virgula
	printf("CPF: %s\n", token);
	
	token = strtok(NULL,",");
	printf("NOME: %s\n", token);
	
	token = strtok(NULL,",");
	printf("SOBRENOME: %s\n", token);
	
	token = strtok(NULL,",");
	printf("DATA DE NASCIMENTO: %s\n", token);
	
	token = strtok(NULL,",");
	printf("CARGO: %s\n", token);
	
	
	printf("\n\n");
	}
	
	system("pause");
	fclose(file);			
}

int deletar()
{
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("\t-DELETAR USUÁRIO-\n\n");
	printf("CPF: ");
	scanf("%s", cpf);
	
	system("cls");
	
	FILE*file;
	file= fopen(cpf,"r");
	
	if(file != NULL)
	
	{
		printf("\t-DELETAR USUÁRIO-\n\n");
  			
	}
		while(fgets(conteudo, 200, file) != NULL )
	{
	printf("\t-INFORMAÇÕES DO USUÁRIO-\n\n");
	
	char* token = strtok(conteudo,",");  // dividindo o arquivo em token ate a virgula
	printf("CPF: %s\n", token);
	
	token = strtok(NULL,",");
	printf("NOME: %s\n", token);
	
	token = strtok(NULL,",");
	printf("SOBRENOME: %s\n", token);
	
	token = strtok(NULL,",");
	printf("DATA DE NASCIMENTO: %s\n", token);
	
	token = strtok(NULL,",");
	printf("CARGO: %s\n", token);
	
	printf("\n\n\t*USUÁRIO DELETADO COM SUCESSO*");
	printf("\n\n");
	}
	
	if(file == NULL)
	{
		printf("\t-USUÁRIO NÃO EXISTE NO SISTEMA-\n\n");
	}
	
	system("pause");
	fclose(file);
		
	remove(cpf);  //excluir dados


}

int main () //função do menu
{ 
	int opcao=0; //varialvel
	int x=1;
	
	for(x=1;x=1;) //repetição
    {
	    
	    system("cls"); //limpar a tela
	
  	 	setlocale(LC_ALL, "Portuguese"); //inclusão de idioma,LC_ALL=referência a todos os aspectos da localização
	 
	  	printf("###Cartório da EBAC###\n\n"); //printf=comunicação com o usuário 
 	  	printf("-Escolha a opção desejada-\n\n");
	  	printf("\t1. Registrar usuário\n");
	  	printf("\t2. Consultar usuário\n");
	 	printf("\t3. Deletar usuário\n\n");
	 	printf("Opção:");
	 
	  	scanf("%d", &opcao);  //scanf=armazendo comando do usuario
	 
	  	system("cls");
		
		switch(opcao) //encadeamento de if
		{
			case 1:
			registro();	
			break;
			
			case 2:
			consulta();
    	    break;
    	    
			case 3:
    	    deletar();
    	    break;
    	 
	    	default: //fim do encadeamento 
    	    printf("\t*OPÇÃO INDISPONÍVEL*\n");
      		system("pause");
    	    break;

		} //fim de seleção			
    }
}
