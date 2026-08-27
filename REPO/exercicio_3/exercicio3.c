#include <stdio.h>
#include <stdlib.h>
/*
Implemente uma lista de compras utilizando uma lista encadeada.


Cada item possui:

- Nome do produto;
- Quantidade.


---

## Operações obrigatórias

Implementar funções:

```
inserir()
remover()
buscar()
listar()
```
*/

typedef struct Node {
    char *name;
    int quantity;
    struct Node *next;
} Node;

void inserir(Node **listHead, char *name, int quantity){
    Node *newHead = (Node *)malloc(sizeof(Node));
    newHead->name = name;
    newHead->quantity = quantity;
    newHead->next = *listHead;

    *listHead = newHead;
}

void listar(Node *listHead){
    if(listHead == NULL){
        printf("\n");
        return;
    }

    printf("%s -> ", listHead->name);
    listar(listHead->next);
}

void removeHead(Node **listHead){
    if (*listHead == NULL) return;

    Node *temp = *listHead;
    *listHead = (*listHead)->next;

    //free(temp->name);
    free(temp);
}

void removeValue(Node **listHead, char *name, Node **previousHead){
    if (*listHead == NULL) return;

    //if(*previousHead == NULL) removeHead(listHead); //se for o primeiro item, só remove ele

    //*listHead = atual
    if((*listHead)->name == name){
        Node *temp = *listHead;
        (*previousHead)->next = (*listHead)->next;

        free(temp);
        return;
    }

    removeValue(&((*listHead)->next), name, listHead);
}

void buscar(Node *listHead, char *name){
    if (listHead == NULL) return;

    if(listHead->name == name){
        printf("Encontrado! %s, %d", listHead->name, listHead->quantity);
        return;
    }

    buscar(listHead->next, name);
}

int main(){
    Node *listHead = NULL;

    inserir(&listHead, (char*)"maca", 10);
    inserir(&listHead, (char*)"banana", 10);
    inserir(&listHead, (char*)"macaco", 10);

    listar(listHead);
    //removeHead(&listHead);
    //buscar(listHead, "maca");
    removeValue(&listHead, "banana", NULL);

    listar(listHead);

    return 0;
}