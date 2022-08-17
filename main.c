#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nomeArquivo[40];
FILE *registro;
FILE *operacao;

struct Item{
  float semana1[18];
  float semana2[18];
  float semana3[18];
  float semana4[18];
  float total[18];
};


char string[18][60]= {
"(=) Saldo Anterior",
"(+) Recebimento De Vendas",
"(-) Salarios",
"(-) Fornecedores",
"(-) Impostos",
"(=) Saldo FCO",
"(+) Venda de ativos",
"(-) Aquisicao de Novos Ativos",
"(+) Recebimento de Dividendos",
"(=) Saldo FCI",
"(+) Aquisição de novos Emp./Fin.",
"(+) Integralização de Capital",
"(-) Amortização de Fin./Emp.",
"(-) Pagamento de Dividendos",
"(=) Saldo FCF",
"Saldo Inicial do Período",
"Saldo do Período",
"Resultado Final do Período"};



  int l = 0;
  int s = 0;

struct Item item;

int criarArquivo(FILE *leituraPtr);
int salvarArquivo(FILE *leituraPtr);
void menu();
int print();
int periodo();
void inserir();
void menuOpcao();
void itens();
void remover(FILE *leituraPtr);


int main(void) { 
  // menuOpcao();
  int op = 0;
  
  do{
    printf("*--------------------------------*\n"
           "  1 - Criar Arquivo               \n"
           "  2 - Excluir Arquivo             \n"
           "  3 - Sair                        \n"
           "*--------------------------------*\n\n");

    printf("Opção: ");
    scanf("%d", &op);
  switch(op){
    case 1:
      criarArquivo(operacao);
    break;
    
    case 2:
      remover(operacao);
    break;
    
    default:
      printf(">> Opção Inválida.\n");
      system("pause");
    break;
  }
    
  }while(op != 3);
}

int criarArquivo(FILE *leituraPtr){
 
  getchar();
  system("cls || clear");
  printf("---------------------------------------------\n"
         "Digite o nome do arquivo do fluxo de caixa: ");
  scanf("%[^\n]s.txt", nomeArquivo);

  strcat(nomeArquivo, ".txt");

 if ((registro = fopen(nomeArquivo, "w")) == NULL) {
      printf("O arquivo não existe! Tente novamente.");
      system("cls || clear");         
    }else{
 
  fclose(registro);
  system("cls || clear");
  salvarArquivo(operacao);
  menuOpcao();
  }
  return 0;
}
void remover(FILE *leituraPtr){
  FILE *registro;
  FILE *ptrBalancoTXT;
 char nomeArquivo[30] = "";
  char caminhoArquivo[60] = "";
  char caminhoArquivoTXT[50] = "";
  getchar();
  printf("---------------------------------------------\n"
        "\tDigite o nome do balanco: ");
  scanf("%[^\n]s", nomeArquivo);
  getchar();

  strcat(nomeArquivo, ".txt");
  
  if ((registro = fopen(nomeArquivo, "r")) == NULL) {

    printf("\n\n\t*********************************\n"
               "\t*  >>> Arquivo nao encontrado.  *\n"
               "\t*********************************\n");
    return;
  }

  fclose(registro);
  
  if (remove(nomeArquivo) == 0) {
    system("cls || clear");
    printf("\n\n\t***************************************\n"
               "\t*  >>> Arquivo removido com sucesso.  *\n"
               "\t***************************************\n");
  } else {
    system("cls || clear");
    printf("\n\n\t*********************************************\n"
               "\t*  >>> Nao foi possivel remover o arquivo.  *\n"
               "\t*********************************************\n");
     
  }
   
}

void menuOpcao(){
  int opcao = 0;
    do{
        opcao = 0;
       
        printf("\n\n*-------------- MENU PRINCIPAL ------------------*\n");
        printf(" 1 - Inserir/Alterar\n");
        printf(" 2 - Visualizar Fluxo\n");
        printf(" 3 - Salvar Fluxo\n");
        printf("*------------------------------------------------*\n");
        printf(" 0 - Sair\n");
        printf("*------------------------------------------------*\n\n");
        printf("Opção: ");
        scanf("%d", &opcao);
       
        if (opcao == 1){
            system("cls || clear");
            inserir();
          }
          else if (opcao == 2){
            system("cls || clear");
            print();
        }
          else if (opcao == 3){
            salvarArquivo(operacao);
        }
            else if (opcao == 0){
            printf("\n >> Saindo...\n");
        }
          else {
            printf("\n >> Inválido.\n");
            main();
        }
    }while (opcao != 0);

}

void inserir(){
  int opcao = 0;
  int linha = 0;
    
        printf("\n\n*-------- SEMANA -------------*\n\n");
        printf("\t\t1° SEMANA\n");
        printf("\t\t2° SEMANA\n");
        printf("\t\t3° SEMANA\n");
        printf("\t\t4° SEMANA\n");
        printf("*-------------------------------*\n\n");
        printf("\t\t0 - Voltar               \n");
        printf("*-------------------------------*\n\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if(opcao >= 2 &&  opcao <= 4 && (item.semana1[0] == 0)){
          printf("\n\n>> Informe a 1° semana primeiro!\n\n");
        }
        else if( opcao > 4){
          printf("\n\n>> Quantidade de semanas inválida!\n\n");
        }
        else{
          if(opcao == 1){
            do{
            if(item.semana1[0] == 0){
              printf("\n(=) Saldo Anterior: ");
              scanf("%f", &item.semana1[0]);
              
              }
              system("cls || clear");
              printf("\n---------------------------------------------------------\n");
              printf("\n1 - (=) Saldo Anterior \n");
              itens(linha);
              printf("\nOpção: ");
              scanf("%d", &linha);
              if(linha == 6 || linha == 10 || linha == 15){
                  printf("\n\n >> O saldo é calculado automaticamente!\n");
                }
              else if(linha != 0){
                  printf("Informe o valor: ");
                  scanf("%f", &item.semana1[linha-1]);
                  printf(">> Cadrastrado com sucesso!\n");
                  item.total[linha-1] = item.semana1[linha-1]+item.semana2[linha-1]+item.semana3[linha-1]+item.semana4[linha-1];
                  
                }
              }while(linha != 0);
          }

          if(opcao == 2){
            do{
            if(item.semana1[0] == 0){
              printf("\n(=) Saldo Anterior: ");
              scanf("%f", &item.semana1[0]);
              
              }
              system("cls || clear");
              printf("\n---------------------------------------------------------\n");
              printf("\n1 - (=) Saldo Anterior \n");
              itens(linha);
              printf("\nOpção: ");
              scanf("%d", &linha);
              if(linha == 1 ){
                printf("\n\n >> Saldo anterior já cadrastrado\n\n");
              }
              else if(linha == 6 || linha == 10 || linha == 15){
                  printf("\n\n >> O saldo é calculado automaticamente!\n");
                }   
                else if(linha != 0){
                  printf("Informe o valor: ");
                  scanf("%f", &item.semana2[linha-1]);
                  printf(">> Cadrastrado com sucesso!\n");
                  item.total[linha-1] = item.semana1[linha-1]+item.semana2[linha-1]+item.semana3[linha+2]+item.semana4[linha+2];
                }
              }while(linha != 0);
          }

          if(opcao == 3){
            do{
            if(item.semana1[0] == 0){
              printf("\n(=) Saldo Anterior: ");
              scanf("%f", &item.semana1[0]);
              
              }
              system("cls || clear");
              printf("\n---------------------------------------------------------\n");
              printf("\n1 - (=) Saldo Anterior \n");
              itens(linha);
              printf("\nOpção: ");
              scanf("%d", &linha);
              if(linha == 1 ){
                printf("\n\n >> Saldo anterior já cadrastrado\n\n");
              }
              else if(linha == 6 || linha == 10 || linha == 15){
                  printf("\n\n >> O saldo é calculado automaticamente!\n");
                }   
                else if(linha != 0){
                  printf("Informe o valor: ");
                  scanf("%f", &item.semana3[linha-1]);
                  printf(">> Cadrastrado com sucesso!\n");
                  item.total[linha-1] = item.semana1[linha-1]+item.semana2[linha-1]+item.semana3[linha-1]+item.semana4[linha-1];
                }
              }while(linha != 0);
          }

          if(opcao == 4){
            do{
            if(item.semana1[0] == 0){
              printf("\n1 - (=) Saldo Anterior: ");
              scanf("%f", &item.semana1[0]);
              
              }
              system("cls || clear");
              printf("\n---------------------------------------------------------\n");
              printf("\n1 - (=) Saldo Anterior \n");
              itens(linha);
              printf("\nOpção: ");
              scanf("%d", &linha);
              if(linha == 1 ){
                printf("\n\n >> Saldo anterior já cadrastrado\n\n");
              }
              else if(linha == 6 || linha == 10 || linha == 15){
                  printf("\n\n >> O saldo é calculado automaticamente!\n");
                }   
                else if(linha != 0){
                  printf("Informe o valor: ");
                  scanf("%f", &item.semana4[linha-1]);
                  printf(">> Cadrastrado com sucesso!\n");
                  item.total[linha-1] = item.semana1[linha-1]+item.semana2[linha-1]+item.semana3[linha-1]+item.semana4[linha-1];
                }
              }while(linha != 0);
          } 
  }
}        

void itens(){
 
  for(l = 1; l<5; l++){
    printf("%d - %-33s\n", l+1, string[l]); 
  }
  printf("\n6 - (=) Saldo FCO\n");
   for(l = 6; l<9; l++){
    printf("%d - %-33s\n", l+1, string[l]);
  }
  printf("\n10 - (=) Saldo FCI\n");
  for(l = 10; l<14; l++){
    printf("%d - %-33s\n", l+1, string[l]); 
  }
  printf("15 - (=) Saldo FCF\n");
  printf("---------------------------------------------------------\n");
  printf("0 - Sair\n\n"); 
}


int print(){

  
  printf("%-30s %17s %17s %17s %17s %14s\n", "FLUXO DE CAIXA", "SEMANA 1", "SEMANA 2", "SEMANA 3", "SEMANA 4","TOTAL");

  //SEMANA 1  
  float semana1_fco = item.semana1[1]+item.semana1[2]+item.semana1[3]+item.semana1[4];
  float semana1_fci = item.semana1[6]+item.semana1[7]+item.semana1[8];
  float semana1_fcf = item.semana1[10]+item.semana1[11]+item.semana1[12]+item.semana1[13];
 
  //SEMANA 2 
  float semana2_fco = item.semana2[1]+item.semana2[2]+item.semana2[3]+item.semana2[4];
  float semana2_fci = item.semana2[6]+item.semana2[7]+item.semana2[8];
  float semana2_fcf = item.semana2[10]+item.semana2[11]+item.semana2[12]+item.semana2[13];
  
  //SEMANA 3 
  float semana3_fco = item.semana3[1]+item.semana3[2]+item.semana3[3]+item.semana3[4];
  float semana3_fci = item.semana3[6]+item.semana3[7]+item.semana3[8];
  float semana3_fcf = item.semana3[10]+item.semana3[11]+item.semana3[12]+item.semana3[13];
  
  //SEMANA 4
  float semana4_fco = item.semana4[1]+item.semana4[2]+item.semana4[3]+item.semana4[4];
  float semana4_fci = item.semana4[6]+item.semana4[7]+item.semana4[8];
  float semana4_fcf = item.semana4[10]+item.semana4[11]+item.semana4[12]+item.semana4[13];
  
  //TOTAL DAS SEMANAS
  float fcoTotal=0;
  float fciTotal = 0;
  float fcfTotal = 0;

  float saldoP1 = 0;
  float saldoP2 = 0;
  float saldoP3 = 0;
  float saldoP4 = 0;
  float saldoPTotal = 0;

  saldoP1 = semana1_fco + semana1_fci +semana1_fcf;
  saldoP2 = semana2_fco + semana2_fci +semana2_fcf;
  saldoP3 = semana3_fco + semana3_fci +semana3_fcf;
  saldoP4 = semana4_fco + semana4_fci +semana4_fcf;
  saldoPTotal = saldoP1 + saldoP2 + saldoP3 + saldoP4;
    
    item.semana2[0] =  item.semana1[0] + saldoP1;
    item.semana3[0] =  item.semana2[0] + saldoP2;
    item.semana4[0] =  item.semana3[0] + saldoP3;
  
    item.total[0] = item.semana1[0];
    printf("%-30s\t%16.2f %17.2f %17.2f %17.2f %17.2f\n", string[0], item.semana1[0], item.semana2[0], item.semana3[0], item.semana4[0], item.total[0]);
    
     
 
  printf("Fluxo de Caixa Operacional\n");
  for(l = 1; l<5; l++){
      printf("%-30s\t%16.2f %17.2f %17.2f %17.2f %17.2f\n", string[l], item.semana1[l], item.semana2[l], item.semana3[l], item.semana4[l], item.total[l]);
    }
    
    fcoTotal = semana1_fco + semana2_fco + semana3_fco + semana4_fco;
    for(l=5; l<6; l++){
      printf("(=) Saldo FCO =\t%32.2f %17.2f %17.2f %17.2f %17.2f\n", semana1_fco, semana2_fco, semana3_fco, semana4_fco, fcoTotal);
      
    }
    
    
    printf("\nFluxo de Caixa de Investimento\n");
    for(l = 6; l<9; l++){
      printf("%-30s\t%16.2f %17.2f %17.2f %17.2f %17.2f\n", string[l], item.semana1[l], item.semana2[l], item.semana3[l], item.semana4[l], item.total[l]);
    }
    
    fciTotal = semana1_fci + semana2_fci + semana3_fci + semana4_fci;
    for(l = 9; l<10; l++){
      printf("(=) Saldo FCI =\t%32.2f %17.2f %17.2f %17.2f %17.2f\n",  semana1_fci, semana2_fci, semana3_fci, semana4_fci, fciTotal);
    }
    
    
   printf("\nFluxo de Caixa de Financiamento\n");
    for(l = 10; l<14; l++){
      printf("%-35s\t%12.2f %17.2f %17.2f %17.2f %17.2f\n", string[l], item.semana1[l], item.semana2[l], item.semana3[l], item.semana4[l], item.total[l]);
    } 

    fcfTotal = semana1_fcf + semana2_fcf + semana3_fcf + semana4_fcf;
    for(l = 14; l<15; l++){
      printf("(=) Saldo FCF =\t%32.2f %17.2f %17.2f %17.2f %17.2f\n", semana1_fcf, semana2_fcf, semana3_fcf, semana4_fcf, fcfTotal);
    }
    printf("\n");

  float totalSIC = 0;
  totalSIC = item.semana1[0]; 
    for(l = 15; l< 16; l++){
      printf("SALDO INICIAL =\t%32.2f %17.2f %17.2f %17.2f %17.2f\n", item.semana1[0], item.semana2[0], item.semana3[0], item.semana4[0], totalSIC);
    }

  printf("SALDO PERIODO =\t%32.2f %17.2f %17.2f %17.2f %17.2f\n", saldoP1, saldoP2, saldoP3, saldoP4, saldoPTotal);

    float resultadoFP1 = item.semana1[0] + saldoP1;
    float resultadoFP2 = item.semana2[0] + saldoP2;
    float resultadoFP3 = item.semana3[0] + saldoP3;
    float resultadoFP4 = item.semana4[0] + saldoP4;
    float resultadoFPT = item.total[0] + fcoTotal + fciTotal + fcfTotal;
  
  printf("RESULTADO FINAL DO PERIODO =\t%16.2f %17.2f %17.2f %17.2f %17.2f\n", resultadoFP1, resultadoFP2, resultadoFP3, resultadoFP4, resultadoFPT);
  
  
  return 0;
}

int salvarArquivo(FILE *leituraPtr){

  registro = fopen(nomeArquivo, "w");
  fprintf(registro, "%-30s %17s %17s %17s %17s %17s\n", "FLUXO DE CAIXA", "SEMANA 1", "SEMANA 2", "SEMANA 3", "SEMANA 4","TOTAL");

  //SEMANA 1  

  float semana1_fco = item.semana1[1]+item.semana1[2]+item.semana1[3]+item.semana1[4];
  float semana1_fci = item.semana1[6]+item.semana1[7]+item.semana1[8];
  float semana1_fcf = item.semana1[10]+item.semana1[11]+item.semana1[12]+item.semana1[13];
 
  //SEMANA 2 
  float semana2_fco = item.semana2[1]+item.semana2[2]+item.semana2[3]+item.semana2[4];
  float semana2_fci = item.semana2[6]+item.semana2[7]+item.semana2[8];
  float semana2_fcf = item.semana2[10]+item.semana2[11]+item.semana2[12]+item.semana2[13];
  
  //SEMANA 3 
  float semana3_fco = item.semana3[1]+item.semana3[2]+item.semana3[3]+item.semana3[4];
  float semana3_fci = item.semana3[6]+item.semana3[7]+item.semana3[8];
  float semana3_fcf = item.semana3[10]+item.semana3[11]+item.semana3[12]+item.semana3[13];
  
  //SEMANA 4
  float semana4_fco = item.semana4[1]+item.semana4[2]+item.semana4[3]+item.semana4[4];
  float semana4_fci = item.semana4[6]+item.semana4[7]+item.semana4[8];
  float semana4_fcf = item.semana4[10]+item.semana4[11]+item.semana4[12]+item.semana4[13];
  
  //TOTAL DAS SEMANAS
  float fcoTotal=0;
  float fciTotal = 0;
  float fcfTotal = 0;

  float saldoP1 = 0;
  float saldoP2 = 0;
  float saldoP3 = 0;
  float saldoP4 = 0;
  float saldoPTotal = 0;

  saldoP1 = semana1_fco + semana1_fci +semana1_fcf;
  saldoP2 = semana2_fco + semana2_fci +semana2_fcf;
  saldoP3 = semana3_fco + semana3_fci +semana3_fcf;
  saldoP4 = semana4_fco + semana4_fci +semana4_fcf;
  saldoPTotal = saldoP1 + saldoP2 + saldoP3 + saldoP4;
  
      item.semana2[0] =  item.semana1[0] + saldoP1;
      item.semana3[0] =  item.semana2[0] + saldoP2;
      item.semana4[0] =  item.semana3[0] + saldoP3;
      item.total[0] = item.semana1[0];

      fprintf(registro, "%-30s\t%16.2f %17.2f %17.2f %17.2f %17.2f\n", string[0], item.semana1[0], item.semana2[0], item.semana3[0], item.semana4[0], item.total[0]);
    
     
 
  fprintf(registro, "Fluxo de Caixa Operacional\n");
  for(l = 1; l<5; l++){
      fprintf(registro, "%-30s\t%16.2f %17.2f %17.2f %17.2f %17.2f\n", string[l], item.semana1[l], item.semana2[l], item.semana3[l], item.semana4[l], item.total[l]);
    }
    
    fcoTotal = semana1_fco + semana2_fco + semana3_fco + semana4_fco;
    for(l=5; l<6; l++){
      fprintf(registro, "(=) Saldo FCO =\t%32.2f %17.2f %17.2f %17.2f %17.2f\n", semana1_fco, semana2_fco, semana3_fco, semana4_fco, fcoTotal);
      
    }
    
    
    fprintf(registro, "\nFluxo de Caixa de Investimento\n");
    for(l = 6; l<9; l++){
      fprintf(registro, "%-31s\t%16.2f %17.2f %17.2f %17.2f %17.2f\n", string[l], item.semana1[l], item.semana2[l], item.semana3[l], item.semana4[l], item.total[l]);
    }
    
    fciTotal = semana1_fci + semana2_fci + semana3_fci + semana4_fci;
    for(l = 9; l<10; l++){
      fprintf(registro, "(=) Saldo FCI =\t%32.2f %17.2f %17.2f %17.2f %17.2f\n",  semana1_fci, semana2_fci, semana3_fci, semana4_fci, fciTotal);
    }
    
    
   fprintf(registro, "\nFluxo de Caixa de Financiamento\n");
    for(l = 10; l<14; l++){
      fprintf(registro, "%-35s\t%16.2f %16.2f %17.2f %17.2f %17.2f\n", string[l], item.semana1[l], item.semana2[l], item.semana3[l], item.semana4[l], item.total[l]);
    } 

    fcfTotal = semana1_fcf + semana2_fcf + semana3_fcf + semana4_fcf;
    for(l = 14; l<15; l++){
      fprintf(registro, "(=) Saldo FCF =\t%33.2f %16.2f %17.2f %17.2f %17.2f\n", semana1_fcf, semana2_fcf, semana3_fcf, semana4_fcf, fcfTotal);
    }
    fprintf(registro, "\n");


  float totalSIC = 0;
  totalSIC = item.semana1[0]; 
    for(l = 15; l< 16; l++){
      fprintf(registro, "SALDO INICIAL =\t%33.2f %16.2f %17.2f %17.2f %17.2f\n", item.semana1[0], item.semana2[0], item.semana3[0], item.semana4[0], totalSIC);
    }

    fprintf(registro, "SALDO PERIODO =\t%33.2f %16.2f %17.2f %17.2f %17.2f\n", saldoP1, saldoP2, saldoP3, saldoP4, saldoPTotal);

    float resultadoFP1 = item.semana1[0] + saldoP1;
    float resultadoFP2 = item.semana2[0] + saldoP2;
    float resultadoFP3 = item.semana3[0] + saldoP3;
    float resultadoFP4 = item.semana4[0] + saldoP4;
    float resultadoFPT = item.total[0] + fcoTotal + fciTotal + fcfTotal;

  fprintf(registro, "RESULTADO FINAL DO PERIODO =\t%19.2f %16.2f %17.2f %17.2f %17.2f\n", resultadoFP1, resultadoFP2, resultadoFP3, resultadoFP4, resultadoFPT);
  

  fclose(registro);
  return 0;
}




// void inserir(){
//   int opcao = 0;
//   int linha = 0;
//     do{
//         opcao = 0;
       
//         printf("\n\n*-------- SEMANA -------------*\n\n");
//         printf("\t\t1° SEMANA\n");
//         printf("\t\t2° SEMANA\n");
//         printf("\t\t3° SEMANA\n");
//         printf("\t\t4° SEMANA\n");
//         printf("*-------------------------------*\n\n");
//         printf("\t\t0 - Voltar               \n");
//         printf("*-------------------------------*\n\n");
//         printf("Opção: ");
//         scanf("%d", &opcao);

//         if(opcao >= 2 &&  opcao <= 4 && (item.semana1[0] == 0)){
//           printf("\n\n>> Informe a 1° semana primeiro!\n\n");
//         }
//           else if( opcao > 4){
//             printf("\n\n>> Quantidade de semanas inválida!\n\n");
//           }
//         else{
//           switch(opcao){
//             case 1:
//               if(item.semana1[0] == 0){
//                printf("\n(=) Saldo Anterior: ");
//               scanf("%f", &item.semana1[0]);
//               }else{     
//               printf("\n(=) Saldo Anterior \n");
//               itens(linha);
//               printf("\nOpção: ");
//               scanf("%d", &linha);
//                 if(linha == 6 || linha == 10 || linha == 15){
//                   printf("\n\n >> O saldo é calculado automaticamente!\n");
//                 }
//                 else{
//                   printf("Informe o valor: ");
//                   scanf("%f", &item.semana1[linha-1]);
//                   item.total[linha-1] = item.semana1[linha-1]+item.semana2[linha-1]+item.semana3[linha-1]+item.semana4[linha-1];
//                 }
              
//               }
//             break;
            
//             case 2:
//               itens(linha);
//               printf("Opção: ");
//               scanf("%d", &linha);
//               if(linha == 1 ){
//                 printf("\n\n >> Saldo anterior já cadrastrado\n\n");
//               }
//                 else if(linha == 6 || linha == 10 || linha == 15){
//                   printf("\n\n >> O saldo é calculado automaticamente!\n");
//                 }
//                 else{
//                   printf("Informe o valor: ");
//                   scanf("%f", &item.semana2[linha-1]);
//                   item.total[linha-1] = item.semana1[linha-1]+item.semana2[linha-1]+item.semana3[linha+2]+item.semana4[linha+2];
//                 }
              
//             break;
            
//             case 3:
//               itens(linha);
//               printf("Opção: ");
//               scanf("%d", &linha);
//               if(linha == 1 ){
//                 printf("\n\n >> Saldo anterior já cadrastrado\n\n");
//               }
//                 else if(linha == 6 || linha == 10 || linha == 15){
//                   printf("\n\n >> O saldo é calculado automaticamente!\n");
//                 }
//                 else{
//                   printf("Informe o valor: ");
//                   scanf("%f", &item.semana3[linha-1]);
//                   item.total[linha-1] = item.semana1[linha-1]+item.semana2[linha-1]+item.semana3[linha-1]+item.semana4[linha-1];
//                 }
              
//             break;
            
//             case 4:
//               itens(linha);
//               printf("Opção: ");
//               scanf("%d", &linha);
//               if(linha == 1 ){
//                 printf("\n\n >> Saldo anterior já cadrastrado\n\n");
//               }
//                 else if(linha == 6 || linha == 10 || linha == 15){
//                   printf("\n\n >> O saldo é calculado automaticamente!\n");
//                 }
//                 else{
//                   printf("Informe o valor: ");
//                   scanf("%f", &item.semana4[linha-1]);
//                   item.total[linha-1] = item.semana1[linha-1]+item.semana2[linha-1]+item.semana3[linha-1]+item.semana4[linha-1];
//                 }
//             break;
//           }
//       }
        
//     }while (opcao != 0);
// }