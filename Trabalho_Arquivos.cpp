#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
# define max 100

struct aluno{
	int matricula;
	char turma[20], nome[30], email[30];
	float nota1 , nota2;
};

int main(){
	
	aluno cadastro[max];
	int opcao, cont , matricula, aux_indice, j;
	char resp;
	FILE *ptr, *aux;
	bool achou;
	float media;
	
	
	ptr = fopen("arquivo.txt","r+");
	
	if(ptr == NULL){
		ptr = fopen("arquivo.txt","w+");
		
		cont = 0;
	}
	else{
		aux_indice = 0;
		
		while(!(feof(ptr))){
			
			fscanf(ptr,"%d\n",&cadastro[aux_indice].matricula);
			fscanf(ptr,"%s\n",cadastro[aux_indice].nome);
			fscanf(ptr,"%s\n",cadastro[aux_indice].email);
			fscanf(ptr,"%s\n",cadastro[aux_indice].turma);
			fscanf(ptr,"%f",&cadastro[aux_indice].nota1);
			fscanf(ptr,"%f",&cadastro[aux_indice].nota2);		
			fscanf(ptr,"%d",&cont);
			
			aux_indice++;
		}
	}
	
	do{
	
	    system("cls");
		
		printf("1 - Incluir Aluno \n");
		printf("2 - Excluir Aluno \n");
		printf("3 - Pesquisar Aluno \n");
		printf("4 - Lancar Notas \n");
		printf("5 - Listar Notas \n");
		printf("6 - Sair \n\n");
		printf("Escolha: ");
		scanf("%d",&opcao);
		
		if(opcao == 1){
		
				system("cls");
				
				if(cont == max){
					printf("Limite de alunos cadastrados alcancado!\n");
				}else{
				   printf("Informe a matricula: ");
				   scanf("%d",&cadastro[cont].matricula);	
				   fflush(stdin);
				   printf("Informe o nome: ");
				   gets(cadastro[cont].nome);
				   printf("Informe o email: ");
				   gets(cadastro[cont].email);
				   printf("Informe a turma: ");
				   gets(cadastro[cont].turma);
				   cadastro[cont].nota1 = -0.5;
				   cadastro[cont].nota2 = -0.5;
					
				   ptr = fopen("arquivo.txt","a");
					
				   fprintf(ptr,"%d\n",cadastro[cont].matricula);
				   fprintf(ptr,"%s\n",cadastro[cont].nome);
				   fprintf(ptr,"%s\n",cadastro[cont].email);
				   fprintf(ptr,"%s\n",cadastro[cont].turma);
				   fprintf(ptr,"%f\n",cadastro[cont].nota1);
				   fprintf(ptr,"%f\n",cadastro[cont].nota2);
					cont++;
					fprintf(ptr,"%d\n",cont);
					
					fclose(ptr);		
			    }
					
				printf("\n");	
				system("pause");
					
	        }else{
				if(opcao == 2){
					
			     
				   system("cls");
			
				   if(cont > 0){
					
					  printf("Informe a matricula: ");
					  scanf("%d",&matricula);
					  printf("\n");
					
					  for(int i=0; i < cont; i++){
					  	
						 if(matricula == cadastro[i].matricula){
							achou = true;
							aux_indice = i;
							
							for(int i = aux_indice; i < cont; i++){	
								cadastro[i].matricula = cadastro[i+1].matricula;
								strcpy(cadastro[i].nome,cadastro[i+1].nome);
								strcpy(cadastro[i].email,cadastro[i+1].email);
								strcpy(cadastro[i].turma,cadastro[i+1].turma);
								cadastro[i].nota1 = cadastro[i+1].nota1;
								cadastro[i].nota2 = cadastro[i+1].nota2;
							}
							cont = cont - 1;							
							remove("arquivo.txt");
							ptr = fopen("arquivo.txt","w+");
							
							for(int i=0 ; i < cont ; i++){
								fprintf(ptr,"%d\n",cadastro[i].matricula);
								fprintf(ptr,"%s\n",cadastro[i].nome);
								fprintf(ptr,"%s\n",cadastro[i].email);
								fprintf(ptr,"%s\n",cadastro[i].turma);
								fprintf(ptr,"%f\n",cadastro[i].nota1);
								fprintf(ptr,"%f\n",cadastro[i].nota2);
								fprintf(ptr,"%d\n",(i+1));
							}
							
							fclose(ptr);
							
						 }	 
					   }
					   if(achou){
					   	  system("cls");
					   	  printf("Aluno Excluido com sucesso!\n");
				       }
				   }else{
					printf("Nenhum aluno cadastrado!");
					printf("\n");
				  }
					
				printf("\n");	
				system("pause");					
					
			}else{
			    if(opcao == 3){
			    	
				   system("cls");
				
				  achou = false;
				
				  if(cont > 0){
					printf("Informe a matricula: ");
					scanf("%d", &matricula);
					printf("\n");
					rewind(ptr);
					
					for(int i = 0; i < cont; i++){
					
						if(matricula == cadastro[i].matricula){
							
							system("cls");
							
							achou = true;
							
							printf("matricula: %d \n",cadastro[i].matricula);
							printf("Nome: %s \n",cadastro[i].nome);
							printf("Email: %s \n",cadastro[i].email);
							printf("Turma: %s \n",cadastro[i].turma);
							
							if(cadastro[i].nota1 > -0.5)
								printf("Nota 1: %.2f\n",cadastro[i].nota1);
								
							if(cadastro[i].nota2 > -0.5)
								printf("Nota 2: %.2f \n",cadastro[i].nota2);
						}
				    }
				   
				     if(!(achou)){
				   	   system("cls");
				   	   printf("Aluno nao encontrado!\n\n");
				     }
				    
			        }else{
			    	  printf("Nenhum aluno cadastrado!");
			    	  printf("\n");
				    }
				
				  printf("\n");		
				  system("pause");
				
				
		       }else{
			         if(opcao == 4){
					 
				        system("cls");
				
				        if(cont > 0){  
					      printf("Informe a matricula: ");
					      scanf("%d", &matricula);
					      for(int i=0 ; i < cont ; i++){
					
						      if(matricula == cadastro[i].matricula){
							
							      system("cls");
							      achou = true;
							      printf("Informe a Nota 1: ");
							      scanf("%f", &cadastro[i].nota1);
							      system("cls");
							      fflush(stdin);
							      printf("Deseja Lancar a nota 2 [s/n]? ");
							      scanf("%c",&resp);
							      printf("\n");
							      system("cls");
							  
							     if(toupper(resp) == 'S'){
								   printf("Informe a nota 2: ");
								   scanf("%f", &cadastro[i].nota2);
								   printf("\n");
							       }
							       remove("arquivo.txt");
							       ptr = fopen("arquivo.txt","w+");
							
							      for(int i=0 ; i < cont ; i++){
								
								    fprintf(ptr,"%d\n",cadastro[i].matricula);
								    fprintf(ptr,"%s\n",cadastro[i].nome);
								    fprintf(ptr,"%s\n",cadastro[i].email);
								    fprintf(ptr,"%s\n",cadastro[i].turma);
								    fprintf(ptr,"%f\n",cadastro[i].nota1);
								    fprintf(ptr,"%f\n",cadastro[i].nota2);
								    fprintf(ptr,"%d\n",(i+1));
							       }
							
							   fclose(ptr);
					         }
					      }
						 
						if(!(achou)){
							printf("Aluno nao encontrado!");
							printf("\n");
						} 									
				    }else{
					  printf("Nenhum aluno cadastrado!");
					  printf("\n");
				    }	
				     printf("\n");	
				    system("pause");
				
		          }else{
				        if(opcao == 5){
				          system("cls");
				          for(int i=0 ; i < cont ; i++){
				          	
					         if(cadastro[i].nota1 > -0.5 || cadastro[i].nota2 > -0.5){
					           printf("=====%d%c Aluno=====",(i+1),(248));
					           printf("\n\n");
					          }
				
					          if(cadastro[i].nota1 > -0.5)
						        printf("Nota 1: %.2f\n",cadastro[i].nota1);
					
					          if(cadastro[i].nota2 > -0.5)
						        printf("Nota 2: %.2f\n",cadastro[i].nota2);
					
					          if(cadastro[i].nota1 > -0.5 && cadastro[i].nota2 > -0.5){
						         media = (cadastro[i].nota1 + cadastro[i].nota2)/2;
						         printf("Media: %.2f\n",media);
						         printf("\n");
						
						         if(media >= 7)
							       printf("Aprovado \n");
						         else
							       printf("Reprovado \n");
					            }
					            
				           }
				           printf("\n"); 	
	                      system("pause");
				   }
			   }	
			 
		      }
			
			 }	
		
	       } 
		   	
	}while(opcao != 6);
	
	system("cls");
	printf("Obrigado!\n\n");
	
	fclose(ptr);
	
	system("pause");
}
