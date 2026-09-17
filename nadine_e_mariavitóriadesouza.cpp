#include <stdio.h>

int main(){
	int caixa=0; // 1- aberto 0- fechado
	int matricula, ultimoop=0, matriculaaberta=0; //matriculas e ultimo operador
	int quantidadevendas=0;
	int opcao, formapagamento;
	int dinheiro=0, pix=0, credito=0, debito=0; // quantidade de vendas separado em forma de pagamento
	float totaldinheiro=0, totalpix=0, totalcredito=0, totaldebito=0; // subtotal separado em formas de pagamento
	float totalvendido=0, dinheirocaixa=0; //totalvendido e a quantidade de dinheiro total da compra atual / / dinheirocaixa e a quantidade de dinheiro total armazenado no caixa incluindo todas as formas de pagamento
	float extracao, venda, montante=0; // montante e a quantidade de dinheiro apenas fisico do caixa
	
	while(1){
	    printf("SISTEMA DE CAIXA\n");
	    printf("========================================================\n");
	    
	    
	if(caixa == 0){ //caixa fechado
	    printf("1- Abertura de caixa\n");
	    printf("2- Resumo\n");
	    printf("6- Sair\n");   
	}
	
	else { // caixa aberto
		printf("2- Resumo\n");
	    printf("4- Extracao\n");
	    printf("5- Venda\n"); 
	    printf("3- Fechamento do caixa\n");
	}
	    printf("========================================================\n");
	    printf("Escolha uma opcao: ");
	    scanf("%d", &opcao); //opcoes do menu
	
	switch(opcao){
		
		case 1:{
			
			printf("Insira a sua matricula: ");
			scanf("%d", &matricula); 
			
		    if (matricula <= 0) {
             printf("Matricula invalida!\n"); //caso seja inserido um numero negativo
            }
            
            else {
            	matriculaaberta=matricula; // atualiza a matricula aberta
			    ultimoop=matricula; // atualiza o ultimo operador
			
            	quantidadevendas=0; //reinicia o valor das variaveis
                dinheiro=0;
			    pix=0; 
			    credito=0; 
			    debito=0;
                totaldinheiro=0;
			    totalpix=0;
			    totalcredito=0;
			    totaldebito=0;
			    totalvendido=0;
			    caixa=1;
			
			    printf("Caixa aberto com sucesso!\n");
			    printf("Operador: %d \n", matriculaaberta); // mostra a matricula aberta
			
			}
			
			break;
		}
		
		case 2:{
			
			
			if(matriculaaberta==0 && ultimoop==0){
				printf("ERRO: Nao houve operacao neste caixa\n"); // se nao tiver operador atual ou ultimo operador
			}
			
			else{
				if(caixa == 1){
					printf("RESUMO\n");
					printf("Operador: %d\n", matriculaaberta); //pede a matricula aberta
					printf("========================================================\n");
				}
				
				else{
					printf("========================================================\n");
					printf("RESUMO\n");
					printf("Ultimo operador: %d\n", ultimoop); //pede a matricula do ultimo operador
					printf("========================================================\n");
				}
			}

			//Total de cada forma de pagamento
			printf("Quantidades de vendas em dinheiro: %d\n", dinheiro);
			printf("Quantidades de vendas em pix: %d\n", pix);
			printf("Quantidades de vendas em credito: %d\n", credito);
			printf("Quantidades de vendas em debito: %d\n", debito);
			
			//Subtotal de cada forma de pagamento
			printf("Subtotal vendido por dinheiro: %.2f\n", totaldinheiro);
			printf("Subtotal vendido por pix: %.2f\n", totalpix);
			printf("Subtotal vendido por credito: %.2f\n", totalcredito);
			printf("Subtotal vendido por debito: %.2f\n", totaldebito);
			
			//Total vendido + Qtd de dinheiro (geral)
			
			printf("Total vendido: %.2f\n", totalvendido);
			printf("Quantidade de dinheiro no caixa: %.2f\n", dinheirocaixa);
			printf("========================================================\n");
			break;
		}
		
		case 3:{
		   
		   if(caixa==0){
                 printf("ERRO: Caixa fechado!\n"); //caso o caixa esteja fechado
            break;
            }
    
			printf("========================================================\n");
			printf("Insira sua matricula: \n");
			scanf("%d", &matricula); //pede a matricula
			
			if(matricula != matriculaaberta){
				printf("ERRO: Matricula diferente da usada na abertura do caixa\n"); //caso a matricula seja diferente da inserida
			}
			else{
				printf("========================================================\n");
				printf("FECHAMENTO DE CAIXA\n"); // imprime as informacoes
				printf("Quantidade de vendas: %d\n", quantidadevendas);
				printf("Total vendido: %.2f\n", totalvendido);
				printf("Quantidade de dinheiro no caixa: %.2f\n", dinheirocaixa);
				
				ultimoop = matriculaaberta; //atualiza a matricula do ultimo operador
				matriculaaberta = 0; //fecha a matricula aberta
				caixa = 0; //fecha o caixa
				printf("Caixa fechado!\n");
				
			}
			break;
		}
		
		case 4:{
			
			if(caixa==0){
                 printf("ERRO: Caixa fechado!\n"); // caso o caixa estiver fechado
            break;
              }
			
			printf("========================================================\n");
			printf("Insira sua matricula: \n");
			scanf("%d", &matricula); //pede a matricula
			
			if(matricula != matriculaaberta){
				printf("ERRO: Matricula diferente da usada na abertura do caixa\n"); //caso a matricula seja diferente
			}
			
			else{
				printf("Insira o valor a ser extraido: \n");
				scanf("%f", &extracao); //pede o valor para ser extraido
				
				if(extracao<=0){
					printf("ERRO: Valor nao positivo\n"); // quando o valor for negativo
				}
				
				else if(extracao>montante){
					printf("ERRO: Saldo insuficiente!\n"); //quando o saldo inserido for maior que o saldo
				}
				else{
					montante=montante-extracao; //realiza a extracao
					dinheirocaixa=dinheirocaixa-extracao;
					printf("Extracao realizada com sucesso!\n");
				}
			}
			break;
		}
		
		case 5:{
			
			if(caixa==0){ //caso o caixa esteja fechado
                 printf("ERRO: Caixa fechado!\n");
            break;
              }
              
			printf("========================================================\n");
			printf("Insira o valor da venda: \n");
			scanf("%f", &venda);
			
			
			
			if(venda<=0){ //caso o valor for negativo
				printf("ERRO: Valor nao positivo\n");
			}
			
			else{
				printf("========================================================\n");
				printf("Forma de pagamento:\n");
			
                printf("1- dinheiro\n");
                printf("2- pix\n");
                printf("3- credito\n");
                printf("4- debito\n");
                scanf("%d", &formapagamento); //opcoes
    
                if(formapagamento<1 || formapagamento>4){ //caso for inserida uma forma de pagamento invalida
                     printf("ERRO: Forma de pagamento invalida! Tente novamente.\n");
                 }
               
				
				switch(formapagamento){
					
					case 1:{ //calcula a venda em dinheiro, armazena os dados e alerta quando o valor do montante for superior a 1000
						dinheiro++;
						quantidadevendas++;
						totaldinheiro=totaldinheiro+venda;
						dinheirocaixa=dinheirocaixa+venda;
						montante=montante+venda;
						totalvendido=totalvendido+venda;
						if(montante>1000){
							printf("Montante maior que 1000, faca uma extracao!\n");
						}
						break;
					}
					
					case 2:{ //calcula a venda no pix e armazena os dados
						quantidadevendas++;
						pix++;
						totalpix=totalpix+venda;
						dinheirocaixa=dinheirocaixa+venda;
						totalvendido=totalvendido+venda;
						break;
					}
					
					case 3:{ //calcula a venda no credito e armazena os dados
						quantidadevendas++;
						credito++;
						totalcredito=totalcredito+venda;
						dinheirocaixa=dinheirocaixa+venda;
						totalvendido=totalvendido+venda;
						break;
					}
					
					case 4:{ //calcula a venda no debito e armazena os dados
						quantidadevendas++;
						debito++;
						totaldebito=totaldebito+venda;
						dinheirocaixa=dinheirocaixa+venda;
						totalvendido=totalvendido+venda;
						break;
					}
				}
			}
			
			break;
		}
		
		case 6:{
			
			if(caixa==1){ // caso o caixa esteja aberto
               printf("ERRO: Nao e possivel sair com o caixa aberto!\n");
               break;
        }
			else{ //encerra o programa
				printf("Programa encerrado!");
			return 0;
			}
			
			break;
		}
	
	    default:{ //caso o usuario insira um numero que nao faz parte do menu
        printf("ERRO: Opcao invalida!\n");
        
        break;
		}
		
	}
	
	}
	
	return 0;
}
