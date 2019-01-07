/*Atividade desenvolvida por Vinicius Ribeiro de Oliveira, FADERGS, curso Análise e Desenvolvimento de Sistemas,
para a disciplina de lógica de progrmação*/


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

char menu;
//VARIÁVEIS CLIENTE
char cod_cliente[3], nome_cliente[50], end_cliente[100];
float salario_cliente=0;
//VARIÁVEIS VEÍCULO
char placa_carro[6]="nulo",marca_carro[10];
int ano_carro=0,combustivel=0;
//VARIÁVEIS CÁLCULO DE VENDA
char confere_placa[6],confere_cliente[3],opcao;
float valor_veiculo=0,valor_final=0,entrada=0,valor_parcelas=0;
int parcelas=0;

main(void)
{
system("COLOR 80");
setlocale(LC_ALL, "portuguese");
//SetConsoleOutputCP(1252);
//SetConsoleCP(1252);
inicio:;
	system("CLS");	
		printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf(" *-------------        BEM VINDO         --------------*\n");
		printf(" *-------------  NAVEGUE NO MENU ABAIXO  --------------*\n");
		printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		opcoes:;
		printf("\n\n\n 1: Cadastro do cliente:\n 2: Cadastro do veículo:\n 3: Calcular o valor da venda do veículo:\n 9: Finalizar:\n\n->");
		scanf("%c",&menu);
	switch (menu)
	{
				//CADASTRO DO CLIENTE
						
		case '1':{
			system("CLS");
			printf("\nCADASTRO DO CLIENTE");
			printf("\n\n\nDigite um código para o cliente.\nO código deve conter no mínimo 4 digitos. (São aceitos letras e números): ");
			scanf("%s",cod_cliente);
			fflush(stdin);
			printf("\nNome do cliente: ");
			gets(nome_cliente);
			fflush(stdin);
			printf("\nEndereço do cliente: ");
			gets(end_cliente);
			fflush(stdin);
			printf("\nInsira o valor de renda mensal do cliente: R$");
			scanf("%f",&salario_cliente);
			//printf("\n%s\n\n%s",nome_cliente,end_cliente);
			printf("\n\nCadastro do cliente realizado com sucesso!\nSelecione a próxima opção no MENU.");
			fflush(stdin);
			getch();				
			goto inicio;
			break;}
					
				//CADASTRO DO VEÍCULO
				
		case '2':{
			system("CLS");
			printf("\nCADASTRO DO VEÍCULO");
			fflush(stdin);
			printf("\n\n\nInsira a placa do veículo (Digite letras e números sem espaço e sem hífen): ");
			scanf("%s",placa_carro);
			fflush(stdin);
			printf("\nQual a marca do veículo? (Fabricante): ");
			scanf("%s",marca_carro);
			fflush(stdin);
			printf("\nDigite o ano do veículo: (4 digitos): ");
			scanf("%i",&ano_carro);
			fflush(stdin);
			do{
				printf("\nSelecione o combustível (1: Gasolina / 2: Flex): ");
				scanf("%i",&combustivel);
				if(combustivel!=1&&combustivel!=2)
				printf("\nOpção Inválida\n");
			}while(combustivel!=1&&combustivel!=2);
			printf("\n\nCadastro do veículo realizado com sucesso!\nSelecione a próxima opção no MENU.");
			fflush(stdin);
			getch();
			goto inicio;
			break;}
			
				//CÁLCULO DE VENDA
		case '3':{
			system("CLS");
			printf("\nCALCULAR O VALOR DE VENDA DO VEÍCULO");
			printf("\n\nConfirme a placa do veículo: ");
			scanf("%s",confere_placa);
			if(strcmp(placa_carro,confere_placa)!=0) {
				printf("\nVEÍCULO NÃO CADASTRADO\nPressione enter para retornar ao MENU e selecione a opção 2:CADASTRO DO VEÍCULO\n");
				fflush(stdin);
				getch();
				goto inicio;
				}
			printf("\nComfirme código do cliente: ");
			scanf("%s",confere_cliente);
			if(strcmp(cod_cliente,confere_cliente)!=0) {
				printf("\nCLIENTE NÃO CADASTRADO\nPressione enter para retornar ao MENU e selecione a opção 1:CADASTRO DO CLIENTE\n");
				fflush(stdin);
				getch();
				goto inicio;
				}
			printf("\nDigite o valor do veículo: ");
			scanf("%f",&valor_veiculo);
				pagamento:;
				fflush(stdin);
				printf("\nSelecione o método de pagamento:(1:À vista / 2:A prazo): ");
				scanf("%c",&opcao);
				switch(opcao)
					{
					// PAGAMENTO À VISTA
					case '1':{
						if (combustivel==1)
						{
							system("CLS");
							valor_final=(valor_veiculo*1.13)*1.105;
							printf("\nCLIENTE: %s\nPLACA: %s\nCOMBUSTÍVEL: GASOLINA \nVALOR DE FÁBRICA: R$%2.2f",nome_cliente,placa_carro,valor_veiculo);
							printf("\nVALOR FINAL: R$%2.2f \nVALOR DE IPI: R$%2.2f \nLUCRO DA CONCESSIONÁRIA: R$%2.2f",valor_final,valor_veiculo*0.13,((valor_veiculo*1.13)*0.105));
							goto fim;
						}
						else if(combustivel==2)
						{
							system("CLS");
							valor_final=(valor_veiculo*1.11)*1.105;
							printf("\nCLIENTE: %s\nPLACA: %s\nCOMBUSTÍVEL: FLEX \nVALOR DE FÁBRICA: R$%2.2f",nome_cliente,placa_carro,valor_veiculo);
							printf("\nVALOR FINAL: R$%2.2f \nVALOR DE IPI: R$%2.2f \nLUCRO DA CONCESSIONÁRIA: R$%2.2f",valor_final,valor_veiculo*0.11,((valor_veiculo*1.11)*0.105));
							goto fim;
						}
						break;}
							
					// PAGAMENTO A PRAZO
					case '2':{
						printf("\nQual o valor da entrada? ");
						scanf("%f",&entrada);
						printf("\nSaldo em quantas parcelas? ");
						scanf("%i",&parcelas);
						if (combustivel==1)
						{
							valor_final=((valor_veiculo*1.13)*1.105)-entrada;
							valor_parcelas=(valor_final/parcelas)*1.02;
							if(valor_parcelas>(salario_cliente*0.3)){
								system("CLS");
								printf("\nCliente não tem renda suficiente para o financiamento.\nPressione ENTER novamente para retrnar ao MENU.\n");
								fflush(stdin);
								getch();
								goto inicio;
								}
							else{
								system("CLS");
								printf("\nCLIENTE: %s\nPLACA: %s\nCOMBUSTÍVEL: GASOLINA \nVALOR DE FÁBRICA: R$%2.2f",nome_cliente,placa_carro,valor_veiculo);
								printf("\nVALOR DE IPI: R$%2.2f \nLUCRO DA CONCESSIONÁRIA: R$%2.2f",valor_veiculo*0.13,((valor_veiculo*1.13)*0.105));
								printf("\nVALOR TOTAL: R$%2.2f \nENTRADA: R$%2.2f",valor_final+entrada,entrada);
								printf("\nSALDO: %2.2f \nNº DE PARCELAS: %i \nVALOR DA PARCELA (JUROS DE 2%% AO MÊS): %2.2f",valor_final,parcelas,valor_parcelas);
								printf("\nVALOR TOTAL A PRAZO: R$%2.2f",(valor_final+entrada*1.02));
								goto fim;
							}
						}
						else if(combustivel==2)
						{
							valor_final=((valor_veiculo*1.11)*1.105)-entrada;
							valor_parcelas=(valor_final/parcelas)*1.02;
							if(valor_parcelas>(salario_cliente*0.3)){
								system("CLS");
								fflush(stdin);
								printf("\nCliente não tem renda suficiente para o financiamento.\nPressione ENTER novamente para retrnar ao MENU.\n");
								getch();
								goto inicio;
								}
							else{
								system("CLS");
							printf("\nCLIENTE: %s\nPLACA: %s\nCOMBUSTÍVEL: FLEX \nVALOR DE FÁBRICA: R$%2.2f",nome_cliente,placa_carro,valor_veiculo);
								printf("\nVALOR DE IPI: R$%2.2f \nLUCRO DA CONCESSIONÁRIA: R$%2.2f",valor_veiculo*0.11,((valor_veiculo*1.11)*0.105));
								printf("\nVALOR TOTAL: R$%2.2f \nENTRADA: R$%2.2f",valor_final+entrada,entrada);
								printf("\nSALDO: %2.2f \nNº DE PARCELAS: %i \nVALOR DA PARCELA (JUROS DE 2%% AO MÊS): %2.2f",valor_final,parcelas,valor_parcelas);
								printf("\nVALOR TOTAL A PRAZO: R$%2.2f",(valor_final+entrada*1.02));
								goto fim;
								}
						}
						
							break;}
					
					default:
						fflush(stdin);
						printf("\nOpção Inválida\n");
						goto pagamento;
					}
				}
				
				//FINALIZAR
		case '9':{
			fim:;
			printf("\n\n(_   _)( )                  ( )      ( )   ( )              \n");
			printf("  | |  | |__     _ _   ___  | |/ )    \\ \\_/ / _    _   _   	\n");
			printf("  | |  |  _  \\ / _  )/  _  \\| , <       \\ / / _ \\ ( ) ( )	\n");
			printf("  | |  | | | |( (_| || ( ) || |\\ \\      | |( (_) )| (_) |	 	\n");
			printf("  (_)  (_) (_) \\__ _)(_) (_)(_) (_)     (_) \\___/  \\___/  	\n");
			break;}
		
		default:{
			system("CLS");
			fflush(stdin);
			printf("Opção Inválida\n\nPressione ENTER novamente e retorne ao MENU.");
			fflush(stdin);
			getch();
			goto inicio;}
			
	}
}
