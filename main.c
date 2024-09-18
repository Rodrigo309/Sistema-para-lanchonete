#include <stdio.h>  // printf, scanf, fscanf, fprintf, fopen, etc.
#include <unistd.h> // sleep
#include <stdlib.h> // system

//Controle de Vendas
//o programa só vai sair das opcões selecionadas depois de eu clicar em alguma tecla

typedef struct{
    char nome[50];
    int quantidade;
    double receitaTotal;
} lancheVendido;


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
    FILE *arquivoVendas;

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

        arquivoVendas = fopen("Vendas.txt","a");
        if(arquivoVendas == NULL){
            printf("Erro ao abrir arquivo de vendas!\n");
            return;
        }

        fprintf(arquivoVendas,"Lanche: %s | Quantidade: %d | Preço Unitário: %.2lf | Total: %.2f\n",
        lanche[com_lanc], com_quant, preco[com_lanc], total);

        fclose(arquivoVendas);

    } else {
        printf("Lanche inválido!\n");
    }

    sleep(2);
}

void analisarVendas(){
    FILE *arquivoVendas = fopen("Vendas.txt","r");
    if(arquivoVendas == NULL){
        printf("Erro ao abrir arquivo de vendas!\n");
        return;
    }

    lancheVendido lanches[50];
    int totalLanches = 0;

    char nome[50];
    int quantidade;
    double preco_unitario, receita;

    while(fscanf(arquivoVendas, "Lanche: %49[^|] | Quantidade: %d | Preço Unitário: %lf | Total: %lf\n", 
    nome, &quantidade, &preco_unitario, &receita) == 4){
        int encontrado = 0;
        for(int i = 0; i < totalLanches; i++){
            if(strcmp(lanches[i].nome, nome) == 0){
                lanches[i].quantidade += quantidade;
                lanches[i].receitaTotal += receita;
                encontrado = 1;
                break;
            }
        }

        if(!encontrado && totalLanches < 50){
            strcpy(lanches[totalLanches].nome, nome);
            lanches[totalLanches].quantidade = quantidade;
            lanches[totalLanches].receitaTotal = receita;
            totalLanches++;
        }
    }

    fclose(arquivoVendas);


    printf("====Análise de Vendas ====\n");
    for(int i= 0; i <totalLanches; i++){
        printf("Produto: %s - Total Vendido: %d - Receita Total: %.2lf Reais\n",
        lanches[i].nome, lanches[i].quantidade, lanches[i].receitaTotal);
    }
}

int mostrarMenu(){
    int opc;
    printf("====Lanchonete====\n");
    printf("1 - Cadastrar Lanche\n");
    printf("2 - Lançar venda\n");
    printf("3 - Cardápio\n");
    printf("4 - Análise de Vendas\n");
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

            case 4:
                analisarVendas();
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