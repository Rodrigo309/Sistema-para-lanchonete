#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//Controle de Vendas
//o programa só vai sair das opcões selecionadas depois de eu clicar em alguma tecla

void gravarLanche(char lanche[][50], double preco[], int totalLanches){
    FILE *arquivo = fopen("Cardapio.txt","w");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    for(int i = 0; i < totalLanches; i++){
        fprintf(arquivo, "%s;%.2lf\n", lanche[i], preco[i]);
    }
    fclose(arquivo);
}

void lerLanches(char lanche[][50], double preco[], int *totalLanches){
    FILE *arquivo = fopen("Cardapio.txt","r");
        if(arquivo == NULL){
            printf("Erro ao abrir o arquivo!\n");
            *totalLanches = 0;
            return;
        }


        *totalLanches = 0;
        while(fscanf(arquivo, "%49[^;];%lf\n", lanche[*totalLanches], &preco[*totalLanches]) == 2){
            (*totalLanches)++;
        }
        fclose(arquivo);
}

void listarCardapio(char lanche[][50], double preco[], int totalLanches){
    printf("====Cardápio====\n");
    for(int i = 0; i < totalLanches; i++){
        printf("%d - %s || %.2lf Reais\n", i+1 , lanche[i], preco[i]);
    }

    //o Cardapio só pode desaparecer depois de eu clicar em alguma tecla
    //Fazer com qualquer na hora de imprimir eles fiquem alinhados
}

void cadastrarLanche(char lanche[][50], double preco[], int *totalLanches){
    if(*totalLanches >= 50){
        printf("Limite de lanches atingido!");
        return;
    }

    printf("Descrição: ");
    scanf(" %49[^\n]", lanche[*totalLanches]);
    printf("Preço: ");
    scanf("%lf", &preco[*totalLanches]);
    (*totalLanches)++;
    gravarLanche(lanche, preco, *totalLanches);
    sleep(2);
}

void lancarVenda(char lanche[][50], double preco[], int totalLanches){
    int com_lanc, com_quant;
    double total = 0.0;
    listarCardapio(lanche, preco, totalLanches);

    printf("Informe o número do lanche: ");
    scanf("%d", &com_lanc);

    com_lanc--;

      if (com_lanc >= 0 && com_lanc < totalLanches) {
        printf("%s - %.2lf Reais\n", lanche[com_lanc], preco[com_lanc]);
        printf("Informe a quantidade: ");
        scanf("%d", &com_quant);
        total = com_quant * preco[com_lanc];
        printf("Total a pagar = %.2lf Reais\n", total);
    } else {
        printf("Lanche inválido!\n");
    }

    sleep(2);
}

int mostrarMenu(){
    int opc;
    printf("====Lanchonete====\n");
    printf("1 - Cadastrar Lanche\n");
    printf("2 - Lançar venda\n");
    printf("3 - Cardápio\n");
    printf("0 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opc);
    return opc;
}

int main(){
    char lanche[50][50];
    double preco[50], total = 0.0;
    int l = 0;
    int opc;

    lerLanches(lanche, preco, &l);
    


    do
    {
        system("clear");
        opc = mostrarMenu();

        switch (opc){
            case 1:
                cadastrarLanche(lanche, preco, &l);
                break;

            case 2:
                lancarVenda(lanche, preco, l);
                sleep(2);
                break;

            case 3:
                listarCardapio(lanche, preco, l);
                sleep(5);
                break;

            case 0:
                printf("Saindo!");
                break;

            default:
                  printf("Opção inválida!\n");
                  break;


        }

    } while (opc != 0);
    

    return 0;
}