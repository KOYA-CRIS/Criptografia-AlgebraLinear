/* ************************************************************************************
 *	CENTRO UNIVERSITÁRIO UNICARIOCA					ENSINO SUPERIOR					  *
 * 	DISCIPLINA 										ÁLGEBRA LINEAR					  *			Desenvolvido por Cristhian Anthony.
 * 	TURMA:											926								  * 	
 * 	PROFESSOR:										MANUEL							  *
 * 	ALUNO:											CRISTHIAN ANTHONY FREITAS GOMES   *
 * 	MÁTRICULA:										2023100901						  *
 * ************************************************************************************ 
 
 
Atividade Prática Supervisionada_ APS

Objetivo da Atividade : Desenvolver uma aplicação com um algoritimo em dois módulos.
1: Criptografia
2: Descriptografia                                                                     												

Considerações do Desenvolvedor:
	
	Primeiro de tudo, espero que o usuário se divirta tanto com a ánalise do código quanto ao executável.
	Algumas opções de estrutura de código foram definidas pelos seugintes motivos especificios:
	
		1: Os contadores foram definidos como váriaveis globais por problemas do compilador do meu Dev C++. Infelizmente essa IDE apresenta muitos Bugs e quase perdi o programa por erros dela.
		
		2: Toda estrutura foi pensada visando o máximo de organização para melhor leitura do Desenvolvedor quanto a do usuário utilizando técnicas de boas práticas.
		
		3: A opção de efetuar os cálculos mátemáticos em funções de forma modular, foi visando a adaptabilidade do programa para outros objetivos, como por exemplo, efetuar a multiplicação de qualquer matriz
		   utilizando qualquer chave selecionada pelo usuário ( Obviamente obedecendo os axiomas mátematicos  )
		
		4: O Código está dividido em algumas partes para melhor visualização:
		   A) Bibliotecas / Constantes / Procedimentos 
		   B) Função Main e Cabeçalho (Função a parte das funções Matemáticas)
		   			b2) IPU_ Interação Programa Usuário :  Todo o "Front Ending" foi desenvolvido nessa parte que está dividido da seguinte maneira:
					   b2a) Menu Principal
					   b2b) Menu de Criptografia
					   b2c) Menu de Descriptografia
			
			C) Funções de Criptografia ( A função "multiplica_matriz" também foi utilizada em Descriptografia graças o tópico 3 citado acima para uso em diversas partes do programa )
			D) Funções de Descriptografia 
			 
		5: O programa foi comentado e documentado visando a instrução do próprio desenvolvedor e do usuário.
		   
		   Váriaveis, bibliotecas, e funções foram comentadas com seus respectivos objetivos.
		   If's e Else's não foram comentados para uso do raciocínio do Dev e do Usuário para interpretar qual lógica foi utilizada para resolução de matrizes e lógicas de programação ;) (Parte da Diversão)
		
		6: A matriz_clone_chave foi criada pois entre os critérios do trabalho, há a exigência de que a matriz de Criptografia fosse uma constante. Porém, a função de matriz inversa fornecida manipula
		   os valores da matriz de criptografia ( coisa impossível de ocorrer com uma constante ) logo foi necessário ter uma matriz que pudesse ser manipulada sem que alterasse a matriz original.
		
		
	Observações sobre a segurança:
	
		Acredito que muitas melhorias possam ser implementadas para a maior segurança dos dados fornecidos pelo úsuario e até quanto a integridade do código.
		Entre os principais, acredito que a inserção de uma senha para que seja possível descriptografar a palavra inserida já seria um belo mecanismo de defesa contra possíveis bisbilhoteiros.
		
		Autorizações para respectivos níveis de usuários como : Dev / Usuário Final  (Controle de Acesso)
		Funcionalidades restringidas dado o usúario que acessa a aplicação.
		
		Segurança de rede e verificação de vírus.
		
		Verificação de integridade da informação.
		
		Essas seriam algumas sugestões para aumentar a segurança do código.
		Imagino que haja uma infinidade de métodos mas esses em meu pequeno conhecimento quanto o assunto de segurança, seriam os fundamentais.
		
	
	Considerações finais:
		
		Digo novamente que prezo o desfruto do usuário quanto ao código e a aplicação final.
		Aceito recomendações para melhorias em organização e boas práticas para a leitura do código.
		...... .....          ....  ....    em como otimizar e diminuir o código tendo as mesmas funcionalidades.
		
		Bom proveito!!
		
	
	
	
	
		
		"Conheçe-te a ti mesmo e conhecerás o universo e os deuses."
		   Sócrates
		
	    "Educação não transforma o mundo.
		Educação muda as pessoas.
		Pessoas transformam o mundo."
			Paulo Freire
			
		"O que não te desafia
		Não te transforma."
			
		
		   


/*_____________________________________________________________________________________BIBLIOTECAS / CONSTANTES / PROCEDIMENTOS_______________________________________________________________________________*/




//Inserção de Bibliotecas.

		#include<stdio.h>
		#include<stdlib.h>
		#include <unistd.h> 																			//Manipulação de tempo no C.  																				
		#include<string.h>    																			//Biblioteca para manipulação de String.
		#include<locale.h>    																			//Biblioteca para manipular funcionalidades do programa de acordo com a localidade escolhida.


//Definição de constantes.

		#define LINHAS_MUSER   3																		//Uso na Matriz Bidimensional gerada pelo usuário.
		#define COLUNAS_MUSER  2

		#define LINHAS_MCHAVE  3																		//Uso na Matriz Bidimensional chave fornecida pelo exercício.
		#define COLUNAS_MCHAVE 3 
		#define ORDEM  LINHAS_MCHAVE

		const char alfabeto_min[] = "*abcdefghijklmnopqrstuvwxyz";										//Alfabetos.
		const char alfabeto_maiusculo[] = "*ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		const float matriz_chave[LINHAS_MCHAVE][COLUNAS_MCHAVE] = 										//Matriz Chave.
		{
    		{ 1, 0, 1 },
    		{ 1, 1, 1 },
    		{ 0, 2, -1}
		};


//Váriavel Global

		int i;																						//Contadores - Acumuladores - Váriaveis de auxílio
		int j;																							//Definidas como váriaveis globais para evitar erros por versão de compilador.
		int k;												
		float l;
		

//Lista de Procedimentos

		void cabecalho();
		void verifica_quantCaracter ( char user_word[7] );
		int *converte_psecreta_para_lista_numerica ( char user_word[7] , int user_list[6] );
		void converte_listaNumerica_para_matrizUsuario ( int user_list[6] , float user_matrix [LINHAS_MUSER][COLUNAS_MUSER] );
		void multiplica_matriz ( float result_matrix[LINHAS_MCHAVE][COLUNAS_MUSER] , float key_matrix[LINHAS_MCHAVE][COLUNAS_MCHAVE] , float user_matrix[LINHAS_MUSER][COLUNAS_MUSER] );
		void calcula_inversa (  float key_matrix[ORDEM][ORDEM] , int id_matrix[ORDEM][ORDEM] , float reverse_matrix[ORDEM][ORDEM] );
		void calcula_identidade ( int id_matrix[ORDEM][ORDEM] );
		void revela_palavra ( float descripto_matrix[LINHAS_MCHAVE][COLUNAS_MUSER] );
	



/*________________________________________________________________________________MAIN_FUNC E CABEÇALHO__________________________________________________________________________________________________*/




int main()
{
	setlocale(LC_ALL, "Portuguese");													    			//Define a localidade do programa para a região desejada (Português Brasil)
	
	
	//Set de Variaveis locais para execução
		
		int    op_menu = -1;																			//Abriga opções da seleção do menu principal.
		int    op_cripto = -1;																			//Abriga opções da seleção do menu de criptografia.
		int    op_descripto = -1;																		//Abriga opções da seleção do menu de descriptografia.																			.
		char   palavra_secreta[7]; 																		//Abriga palavra secreta do usuário									
		int    lista_numerica[6]; 																    	//Vetor númerico que abrigará a conversão da palavra secreta do usuário em número.
		float  matriz_usuario [LINHAS_MUSER][COLUNAS_MUSER];											//Abriga matriz com os dados em número da palavra secreta do usuário.
		float  matriz_cripto [LINHAS_MCHAVE][COLUNAS_MUSER];											//Abriga matriz criptografada
		int    matriz_identidade[ORDEM][ORDEM];															//Abriga matriz identidade da matriz chave.
		float  matriz_inversa[ORDEM][ORDEM];															//Abriga Matriz inversa da matriz chave.
		float  matriz_descripto[LINHAS_MCHAVE][COLUNAS_MUSER];											//Abriga Matriz_cripto descriptografada por métodos matemáticos.
	
		
		
	
	
	
	

	
	/*_____________________________________________________________________________IPU - INTERAÇÃO PROGRAMA USUÁRIO__________________________________________________________________________________________*/
		
		
		cabecalho();
		
		/*_________________________________________________________________________________MENU PRINCIPAL___________________________________________________________________________________________________*/		
			
			
		while ( op_menu != 0 )
		{	
		
			float  matriz_clone_chave[ORDEM][ORDEM] = 													    //Abriga Matriz clone da matriz de criptografia para manipulação em funções.
			{
	    		{ 1, 0, 1 },
	    		{ 1, 1, 1 },
	    		{ 0, 2, -1}
			};
			
			op_cripto = -1;
			op_descripto = -1;
			
			system("cls");
			
			printf("UNICARIOCA - ENIGMA / TURING MACHINE");
				printf("\n");
			
			printf("Digite [0] para sair do programa");
				printf("\n\n\n\n");
			
			printf("Criptografia [ 1 ]          Digite [1] para criptografar sua mensagem secreta...       ");
				printf("\n\n");
				
			printf("Descriptografia [ 2 ]       Digite [2] para revelarmos a mensagem secreta (CONFIDENCIAL)...       ");
				printf("\n\n\n\n\n\n\n\n\n");
					
			printf("Digite a opção desejada: ");
			scanf("%d",&op_menu);
			fflush(stdin);	
			
			
			switch(op_menu)
			{
				case 0:
					break;
			
			
				/*___________________________________________________________________MENU DE CRIPTOGRAFIA___________________________________________________________________________________________________*/		
			
				case 1:  //Inicio do Menu de Criptografia
					
					while (op_cripto != 0 )
						{
							
							system("cls");
							
							printf("UNICARIOCA - ENIGMA / TURING MACHINE");
								printf("\n");
								
							printf("Digite [0] para voltar ao menu principal");
								printf("\n\n\n\n");
							
							printf("Inserir Palavra Secreta [ 1 ]");
								printf("\n\n");
								
							printf("Imprimir Palavra Secreta [ 2 ]");
								printf("\n\n");
							
							printf("Imprimir Matriz Codificada [ 3 ]");
								printf("\n\n");
							
							printf("Imprimir Matriz Criptografada [ 4 ]");
								printf("\n\n\n\n\n\n\n\n\n\n");
								
							printf("Digite a opção desejada: ");
							scanf("%d",&op_cripto);
							fflush(stdin);
							
							switch ( op_cripto )
							{	
								
								case 0:
									break;
									
								case 1:
									verifica_quantCaracter(palavra_secreta);
									*converte_psecreta_para_lista_numerica( palavra_secreta , lista_numerica );
									converte_listaNumerica_para_matrizUsuario( lista_numerica , matriz_usuario );
									multiplica_matriz( matriz_cripto , matriz_clone_chave , matriz_usuario);
									calcula_identidade( matriz_identidade );
									calcula_inversa ( matriz_clone_chave , matriz_identidade , matriz_inversa );
									multiplica_matriz ( matriz_descripto , matriz_inversa , matriz_cripto );
									break;
								
								case 2:
									if ( strlen(palavra_secreta) != 0 ) 
									{
										system("cls");
										
										printf("UNICARIOCA - ENIGMA / TURING MACHINE");
											printf("\n\n");
						
										printf("A palavra digitada foi : %s" , palavra_secreta);
											printf("\n\n\n\n\n\n\n\n\n\n");
											
										system("pause");
										break;	
									}
									else
									{
										system("cls");
										
										printf("UNICARIOCA - ENIGMA / TURING MACHINE");
											printf("\n\n");
										
										printf("Não existe nada para ser exibido..");
											printf("\n");
											
										printf("Digite a Palavra Secreta antes de acessar esse menu.");
											printf("\n\n\n\n\n\n\n\n\n\n");
											
										system("pause");
										break;
									}
						
								case 3:	
									if ( strlen(palavra_secreta) != 0 )
									{
									
										system("cls");
										
										printf("UNICARIOCA - ENIGMA / TURING MACHINE");
											printf("\n\n");
										
										printf("Lista numérica gerada usando a tabela de conversão para modificar a palavra secreta: ");
											printf("\n");
										
										printf("[ ");
										
										for (i = 0; i < 6; i++) 
											printf("%d ", *(lista_numerica + i));
										
										printf("]");
											printf("\n\n");
										
										printf("Matriz gerada a partir da Lista numérica: ");
											printf("\n\n");
										
										for( j = 0 ; j < LINHAS_MUSER ; j++)
										{
	
											for( k = 0 ; k < COLUNAS_MUSER ; k++)
												printf("%2.f  ", matriz_usuario[j][k]);
		
		
											printf("\n");			
										}
										
										printf("\n\n\n\n\n\n\n\n\n\n");
										system("pause");
										break;
									}
									else
									{
										system("cls");
										
										printf("UNICARIOCA - ENIGMA / TURING MACHINE");
											printf("\n\n");
										
										printf("Não existe nada para ser exibido..");
											printf("\n");
											
										printf("Digite a Palavra Secreta antes de acessar esse menu.");
											printf("\n\n\n\n\n\n\n\n\n\n");
											
										system("pause");
										break;	
									}
									
								case 4:
									if ( strlen(palavra_secreta) != 0 )
									{
										system("cls");
										
										printf("UNICARIOCA - ENIGMA / TURING MACHINE");
											printf("\n\n");
										
										printf("Impressão da Matriz Criptografada:");
											printf("\n\n");
	
										for( i = 0 ; i < LINHAS_MCHAVE  ; i++)
										{
	
											for( j = 0 ; j < COLUNAS_MUSER ; j++)
												printf("%2.f  ", matriz_cripto[i][j]);
		
		
											printf("\n");			
										}
										
										printf("\n\n\n");
										system("pause");
										break;
									}
									else
									{
										system("cls");
										
										printf("UNICARIOCA - ENIGMA / TURING MACHINE");
											printf("\n\n");
										
										printf("Não existe nada para ser exibido..");
											printf("\n");
											
										printf("Digite a Palavra Secreta antes de acessar esse menu.");
											printf("\n\n\n\n\n\n\n\n\n\n");
											
										system("pause");
										break;	
									}
											
								default:
									system("cls");
											
									printf("UNICARIOCA - ENIGMA / TURING MACHINE");
										printf("\n\n");
									
									printf("Opção Inválida");
										printf("\n\n");
										
									printf("Tente novamente...");	
										printf("\n\n\n\n\n\n");
										
									system("pause");
									break;	
								
								} // Fim dos cases do menu de Criptografia		
						} 				// Fim do While do menu de Criptografia
					break;					 // Break do Case 1 do Menu Principal
						
				
				
				
				/*________________________________________________________________________MENU DE DESCRIPTOGRAFIA_____________________________________________________________________________________________*/					
				
				
				
				case 2: //Menu de Descriptografia
					
					if ( strlen(palavra_secreta) != 0 )
					{
						while( op_descripto != 0)
						{
							
							system("cls");
								
							printf("UNICARIOCA - ENIGMA / TURING MACHINE");
								printf("\n");
								
							printf("Digite [0] para voltar ao menu principal");
								printf("\n\n\n\n");
							
							printf("Imprimir Matriz Criptograda [ 1 ]");
								printf("\n\n");
								
							printf("Imprimir a inversa da Matriz Chave [ 2 ]");
								printf("\n\n");
							
							printf("Imprimir Matriz Descriptografada [ 3 ]");
								printf("\n\n");
							
							printf("Revelar Palavra Secreta [ 4 ]");
								printf("\n\n\n\n\n\n\n\n\n\n");
								
							printf("Digite a opção desejada: ");
							scanf("%d",&op_descripto);
							fflush(stdin);
							
							switch (op_descripto)
								{
									case 0: 																						//Para que a opção de sair não gere conflito com Default.
									break;
									
									case 1:
										system("cls");
								
										printf("UNICARIOCA - ENIGMA / TURING MACHINE");
											printf("\n");
												
										printf("\n\nImpressão da Matriz Criptografada:");
											printf("\n\n");
		
										for( i = 0 ; i < LINHAS_MCHAVE  ; i++)
										{
		
											for( j = 0 ; j < COLUNAS_MUSER ; j++)
												printf("%2.f  ", matriz_cripto[i][j]);
		
		
											printf("\n");			
										}
										
										printf("\n\n\n");
										system("pause");
										break;
									
									case 2:
										system("cls");
								
										printf("UNICARIOCA - ENIGMA / TURING MACHINE");
											printf("\n\n");
											
										printf("Impressão da Matriz Inversa: ");
											printf("\n\n");
										
										for(i = 0; i < ORDEM; i++)
										{
											for(j = 0; j < ORDEM; j++)
											{
												printf("%2.f ", matriz_inversa[i][j]);
											}
									
											printf("\n");
										}
										
										printf("\n\n\n\n\n\n");
										
										system("pause");
										break;	
									
									case 3: 
										
										system("cls");
										printf("UNICARIOCA - ENIGMA / TURING MACHINE"); 
											printf("\n\n");	
										
										printf("Impressão da Matriz Descriptografada: ");
											printf("\n\n");
											
										for( i = 0 ; i < LINHAS_MCHAVE  ; i++)
										{
										
												for( j = 0 ; j < COLUNAS_MUSER ; j++)
													printf("%2.f  ", matriz_descripto[i][j]);
											
											
											printf("\n");			
										}
										
										printf("\n\n\n\n\n\n");
										
										system("pause");
										break;
										
									case 4:
										
										system("cls");
								
										printf("UNICARIOCA - ENIGMA / TURING MACHINE"); 
											printf("\n");
											
										printf("CONFIDENCIAL");
											printf("\n");
									
										revela_palavra( matriz_descripto );
									
										printf("\n\n\n\n\n\n");
										
										system("pause");
										break;
										
									default:
										system("cls");
											
										printf("UNICARIOCA - ENIGMA / TURING MACHINE");
											printf("\n\n");
										
										printf("Opção Inválida");
											printf("\n\n");
											
										printf("Tente novamente...");	
											printf("\n\n\n\n\n\n");
											
										system("pause");
										break;
							
								} // Fim dos cases do Menu de Descriptografia
						} 				//Fim do While do Menu Descripto
					} 						//Fim do If de verificação do Strlen do menu de Descriptografia
					
					else
					{
						system("cls");
													
						printf("UNICARIOCA - ENIGMA / TURING MACHINE");
							printf("\n\n");
						
						printf("Ops... Parece que não há nada para ser descriptografado.");
							printf("\n\n");
						
						printf("Acesse primeiro o Menu de Criptografia para que exista uma palavra a ser descriptografada.");
							printf("\n\n\n\n\n\n\n");
							
						system("pause");
					}
					break; 																												//Fim do case 2 do menu Principal
					
					default:
						system("cls");
											
						printf("UNICARIOCA - ENIGMA / TURING MACHINE");
							printf("\n\n");
									
						printf("Opção Inválida");
							printf("\n\n");
										
						printf("Tente novamente...");	
							printf("\n\n\n\n\n\n");
										
						system("pause");
						break;	
						
					
			}// Fim dos cases do Menu Principal
		} 		// Fim do While do menu principal
				
					
						
							
		//Finalização do EXE.
		
			
		
		system("cls");
		printf("Obrigado por usar o programa!\n\n");
		printf("Volte Sempre!!\n\n\n\n");
				
		system("pause");	
				
			
		
	

	return 0;
}

							

void cabecalho()																				//Informa dados de Cabeçalho
{
	
	puts("Centro Universitário Unicarioca	");
	puts("Ensino Superior");
	
	printf("\n");
	
	puts("Disciplina        Álgebra Linear");
	puts("Turma:            926");
	puts("Professor:        Manuel");
	puts("Aluno:            Cristhian Anthony F. Gomes");
	puts("Matrícula:        2023100901");
	
	printf("\n");
	
	system("pause");
	system("cls");
	
	
}




/*_____________________________________________________________________________________ FUNÇÕES DE CRIPTOGRAFIA__________________________________________________________________________________________________*/




 void verifica_quantCaracter(char user_word[7])	//Parâmetro String 								//Usuário insere palavra de 6 caracteres e é realizada verificação
{
	
	//IPU
	
		system("cls");
		
		printf("UNICARIOCA - ENIGMA / TURING MACHINE");
			printf("\n");
		
		printf("Digite a palavra secreta de 6 caracteres.");
			printf("\n\n\n\n");
	   	
		   printf("OBS_1: A Palavra Secreta não deve conter números ou caracteres especiais  ");
	   		printf("\n\n");
	   	
		   printf("OBS_2: Utilize * para colocar espaços em branco na palavra digitada.");
	   		printf("\n\n");
	   	
		   printf("OBS_3: A letra \"ç\" também é considerada um caracter especial.");
	   		printf("\n\n\n\n\n\n\n\n\n\n");
		
		printf("Digite aqui: ");
			scanf("%s",user_word);
			fflush(stdin);
		
		if(strlen(user_word) != 6)																	//Se Palavra digitada for diferente de 6 caracteres:
		{	
			
			system("cls");
			printf("UNICARIOCA - ENIGMA / TURING MACHINE");
			printf("\n\n");
			puts("Palavra secreta não atende os requisitos de 6 caracteres...");					//Mensagem de aviso
			printf("Digite novamente.. \n\n");
			system("pause");
			system("cls");
			
			
			verifica_quantCaracter(user_word);														//Chamada recursiva da função " verifica_quantCaracter "
		}
			
}


int *converte_psecreta_para_lista_numerica(char user_word[7] , int user_list[6])				//Transforma letras da palavra secreta em números correspondentes as letras do alfabeto.
{
	
	char *endereco_letra_minuscula;																//Set de ponteiro
	char *endereco_letra_maiuscula;																
	
	int posicao_letra_minuscula;																//Abriga index do caracter.
	int posicao_letra_maiuscula;
	
	
	for ( i = 0 ; i < 6 ; i++ )																	//Loop para ler caracter por caracter da palavra secreta do usuário
	{
		endereco_letra_minuscula = strchr( alfabeto_min , user_word[i] );						//ponteiros recebem os endereços dos caracteres correspondentes 
		endereco_letra_maiuscula = strchr( alfabeto_maiusculo , user_word[i] );					//da palavra secreta dentro do alfabeto_minusculo e maiusculo.
		
		posicao_letra_minuscula  = (int)( endereco_letra_minuscula - alfabeto_min );			//Realiza o calculo para achar o index do caracter no alfabeto_min
		posicao_letra_maiuscula  = (int)( endereco_letra_maiuscula - alfabeto_maiusculo  );   //Realiza o calculo para achar o index do caracter no alfabeto_mai.
		
		
		if ( endereco_letra_minuscula != NULL )
			user_list[i] = posicao_letra_minuscula;										        //Lista recebe posição numérica ( posição minuscula )
				
		
		else if ( endereco_letra_maiuscula != NULL )
			user_list[i] = posicao_letra_maiuscula;												//Lista recebe posição númerica (posição maiuscula)
		
		else
		{
			
			system("cls");
			
			printf("UNICARIOCA - ENIGMA / TURING MACHINE");
				printf("\n\n");
			
			printf("Palavra secreta não comporta números ou caracteres especiais.");
			
			printf("\nDigite novamente... ");
				printf("\n\n");
			
			system("pause");
			
			
			verifica_quantCaracter(user_word);													//Chamada de função de caracter para colocar novamente os dados da palavra secreta.
		}
		
	}
	
	return user_list;
}


void converte_listaNumerica_para_matrizUsuario( int user_list[6] , float user_matrix[LINHAS_MUSER][COLUNAS_MUSER])  //Converete lista em matriz bidimensional 3x2.
{

		//Direciona cada caracter da lista a seu respectivo index na matriz
		int i = 0;																				//index da lista
	
		
		for( j = 0 ; j < COLUNAS_MUSER ; j++)
			for( k = 0 ; k < LINHAS_MUSER ; k++)
			{
				
				user_matrix[k][j] = user_list[i];
				i++;
								
			}
						
}


void multiplica_matriz( float result_matrix[LINHAS_MCHAVE][COLUNAS_MUSER] , float key_matrix[LINHAS_MCHAVE][COLUNAS_MCHAVE] , float user_matrix[LINHAS_MUSER][COLUNAS_MUSER]) //usado na desriptografia tbm.
{
	
	//Associa cada produto escalar da matriz chave pela matriz do usuário a matriz criptografada (resultado)
	//Pode ser usada para multiplicar quaisquer matrizes (obdecendo o axioma matemático) adaptando a função.
	
	
	for( i = 0 ; i < LINHAS_MCHAVE ; i++ )														
		for( j = 0 ; j < COLUNAS_MUSER ; j++ )
		{
			
			result_matrix[i][j] = 0;
			for( k = 0 ; k < COLUNAS_MCHAVE ; k++ )
				result_matrix[i][j] += key_matrix[i][k] * user_matrix[k][j];
				
		}


}




/*___________________________________________________________________________________FUNÇÕES DE DESCRIPTOGRAFIA__________________________________________________________________________________________________*/




void calcula_identidade(int id_matrix[ORDEM][ORDEM])  //Set de Matriz identidade
{
	
		for(i=0; i < ORDEM ; i++)
		{
			for(j=0; j < ORDEM ; j++)
			{
				if(i == j)
					id_matrix[i][j] = 1;
				else
					id_matrix[i][j] = 0;
			}
		}

}


void calcula_inversa ( float key_matrix[ORDEM][ORDEM] , int id_matrix[ORDEM][ORDEM] , float reverse_matrix[ORDEM][ORDEM] )  //Realiza Cálculo de Inversa na Matriz Cripto.
{
	
	
	for ( i = 0 ; i < ORDEM ; i++)
	{
	
		for( j = 0 ; j < ORDEM ; j++)
			reverse_matrix[i][j] = id_matrix[i][j];
	}
	
	float pivo = 0;
	l = 0;
	 
	
	for(j=0; j < ORDEM ; j++)
	{
		pivo = key_matrix[j][j];
		//p = pivo/pivo;
		
		for(k=0; k < ORDEM; k++)
		{
			key_matrix[j][k] /= pivo;
			reverse_matrix[j][k] /= pivo;
		}
		
		for( i = 0 ; i < ORDEM ; i++)
		{
			if( i != j )
				l= key_matrix[i][j];
				
			
			for( k = 0 ; k < ORDEM ; k++)
			{
				key_matrix[i][k] -= (l * key_matrix[j][k]);
				reverse_matrix[i][k] -= ( l * reverse_matrix[j][k]);
			}
		
		}
	}

		
}


void revela_palavra ( float descripto_matrix[LINHAS_MCHAVE][COLUNAS_MUSER])	//Revela palavra criptografada inserida pelo usuário
{
	int armazenador;
	
	printf("\n");
	printf("A Palavra Secreta é: ");
	for ( i = 0 ; i < COLUNAS_MUSER ; i++)
		for( j = 0 ; j < LINHAS_MCHAVE ;  j++)
		{
			armazenador = descripto_matrix[j][i];
			printf("%c", alfabeto_maiusculo[ armazenador ]  );
		}
		
}



		
//The end :)			
												
