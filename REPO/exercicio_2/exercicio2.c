#include <stdio.h>

typedef struct {
    int code;
    char name[50];
    float price;
    int quantity;
} Product;

int main(){
    int running = 1;

    Product productsList[1000];
    int productsListCount = 0;

    while(running){
        int choice;
        printf("Selecione uma opcao:\n");
        printf("1- Cadastrar produto:\n");
        printf("2- Exibir todos os produtos:\n");
        printf("3- Buscar produto pelo codigo:\n");
        printf("4- Calcular valor total do estoque:\n");
        scanf("%d", &choice);


        if(choice == 1){
            Product product;
            printf("Digite o CODIGO do produto: \n");
            scanf("%d", &product.code);
            printf("Digite o NOME do produto: \n");
            scanf("%s", &product.name);
            printf("Digite o PRECO do produto: \n");
            scanf("%f", &product.price);
            printf("Digite a QUANTIDADE do produto: \n");
            scanf("%d", &product.quantity);

            productsList[productsListCount] = product;
            productsListCount++;
            printf("PRODUTO ADICIONADO\n");

        } else if (choice == 2){
            for (int i = 0; i < productsListCount; i++){
                printf("Codigo | Nome | Preco | Quantidade\n");
                printf("%d | %s | %f | %d\n",
                    productsList[i].code,
                     productsList[i].name,
                      productsList[i].price,
                      productsList[i].quantity);
            }

        } else if (choice == 3){
            int code;
            printf("Digite o codigo do produto\n");
            scanf("%d", &code);
            for (int i = 0; i < productsListCount; i++){
                if(productsList[i].code == code){
                    printf("Produto encontrado: \n");
                    printf("Codigo: %d | Nome: %s | Preco: %f | Quantidade: %d\n",
                        productsList[i].code,
                        productsList[i].name,
                        productsList[i].price,
                        productsList[i].quantity);
                } else if(i == productsListCount - 1){
                    printf("Produto nao encontrado\n");
                }
            }
        } else if (choice == 4){
            float sum = 0;
            for(int i = 0; i < productsListCount; i++){
                sum += productsList[i].price * productsList[i].quantity;
            }
            printf("Valor total do estoque: %f\n", sum);
        }
    }
    return 0;
}