#include <stdio.h> //biblicoteca de comuni��o com o usu�rio
#include <stdlib.h> // aloca��o de espa�o de mem�ria 
#include <locale.h> // aloca��o de texto pare regi�o
#include <string.h> //biblicoteca para cuidar da string
//Observa��es:\t=espa�o,\n=enter,"=texto,;=confirma��o de comando,%d=variavel int,tab=identar


int registro() //fun��o responsav�l por cadastrar o usu�rio
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio de cria��o de string
	
	char arquivo [200];
	char cpf [40];
	char nome [100];
	char data [40];
	char sobrenome [100];
	char cargo [40];
	
	//final de cria��o de string
		
	printf("\t-RESGISTRAR USU�RIO-\n\n");
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
	printf("\t-CONSULTAR USU�RIO-\n\n\n");
	printf("DIGITE O CPF: ");
	scanf("%s",cpf);
	
	system("cls");
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\t-USU�RIO N�O LOCALIZADO-\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL )
	{
	printf("\t-INFORMA��ES DO USU�RIO-\n\n");
	
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
	
	printf("\t-DELETAR USU�RIO-\n\n");
	printf("CPF: ");
	scanf("%s", cpf);
	
	system("cls");
	
	FILE*file;
	file= fopen(cpf,"r");
	
	if(file != NULL)
	
	{
		printf("\t-DELETAR USU�RIO-\n\n");
  			
	}
		while(fgets(conteudo, 200, file) != NULL )
	{
	printf("\t-INFORMA��ES DO USU�RIO-\n\n");
	
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
	
	printf("\n\n\t*USU�RIO DELETADO COM SUCESSO*");
	printf("\n\n");
	}
	
	if(file == NULL)
	{
		printf("\t-USU�RIO N�O EXISTE NO SISTEMA-\n\n");
	}
	
	system("pause");
	fclose(file);
		
	remove(cpf);  //excluir dados


}

int main () //fun��o do menu
{ 
	int opcao=0; //varialvel
	int x=1;
	
	for(x=1;x=1;) //repeti��o
    {
	    
	    system("cls"); //limpar a tela
	
  	 	setlocale(LC_ALL, "Portuguese"); //inclus�o de idioma,LC_ALL=refer�ncia a todos os aspectos da localiza��o
	 
	  	printf("###Cart�rio da EBAC###\n\n"); //printf=comunica��o com o usu�rio 
 	  	printf("-Escolha a op��o desejada-\n\n");
	  	printf("\t1. Registrar usu�rio\n");
	  	printf("\t2. Consultar usu�rio\n");
	 	printf("\t3. Deletar usu�rio\n\n");
	 	printf("Op��o:");
	 
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
    	    printf("\t*OP��O INDISPON�VEL*\n");
      		system("pause");
    	    break;

		} //fim de sele��o			
    }
}
