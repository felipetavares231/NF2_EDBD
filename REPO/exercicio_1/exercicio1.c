// Online C compiler to run C program online
#include <stdio.h>

typedef struct {
    int matricula;
    char nome[50];
    int idade;
    float nota;
} Aluno;

int main() {
    Aluno studentsList[1000];
    int studentsListCount = 0;

    int running = 1;
    while(running){
        int choice;
        printf("================================\n");
        printf("Escolha uma opção:\n");
        printf("1- CADASTRAR ALUNO:\n");
        printf("2- LISTAR TODOS OS ALUNOS: \n");
        printf("3- BUSCAR ALUNO PELA MATRICULA: \n");
        printf("4- BUSCAR MAIOR NOTA: \n");
        printf("9- FECHAR O PROGRAMA: \n");
        printf("================================\n");
        scanf("%d", &choice);

        if(choice == 9){
            running = 0;
        }

        if(choice == 1){
            Aluno student;
            printf("INFORME o numero da matricula do aluno?\n");
            scanf("%d", &student.matricula);

            printf("INFORME o NOME do aluno?\n");
            scanf("%s", &student.nome);

            printf("INFORME a IDADE do aluno?\n");
            scanf("%d", &student.idade);

            printf("INFORME a NOTA do aluno?\n");
            scanf("%f", &student.nota);

            studentsList[studentsListCount] = student;
            studentsListCount++;
            printf("================================\n");
            printf("ALUNO CADASTRADO: \n");
            printf("NOME: %s\n", student.nome);
            printf("MATRICULA: %d\n", student.matricula);
            printf("IDADE: %d\n", student.idade);
            printf("NOTA: %f\n", student.nota);
            printf("================================\n");
        } else if (choice == 2){
            printf("================================\n");
            printf("MATRICULA, NOME, IDADE, NOTA\n");
            for(int i = 0; i < studentsListCount; i++){
                Aluno student = studentsList[i];
                printf("%d, %s, %d, %f\n", student.matricula, student.nome, student.idade, student.nota);
            }
            printf("================================\n");
        } else if (choice == 3){
            int matricula;
            printf("INFORME a MATRICULA do aluno?\n");
            scanf("%d", &matricula);
            for(int i = 0; i < studentsListCount; i++){
                if(studentsList[i].matricula == matricula){
                    printf("================================\n");
                    printf("ALUNO ENCONTRADO: \n");
                    printf("NOME: %s\n", studentsList[i].nome);
                    printf("MATRICULA: %d\n", studentsList[i].matricula);
                    printf("IDADE: %d\n", studentsList[i].idade);
                    printf("NOTA: %f\n", studentsList[i].nota);
                    printf("================================\n");
                }else if (i == studentsListCount - 1){
                    printf("================================\n");
                    printf("ALUNO NÃO ENCONTRADO\n");
                    printf("================================\n");
                }
            }
        } else if(choice == 4){
            Aluno student;
            for(int i = 0; i < studentsListCount; i++){
                if(studentsList[i].nota > student.nota){
                    student = studentsList[i];
                }
            }
            printf("================================\n");
            printf("ALUNO COM MAIOR NOTA: \n");
            printf("NOME: %s\n", student.nome);
            printf("MATRICULA: %d\n", student.matricula);
            printf("IDADE: %d\n", student.idade);
            printf("NOTA: %f\n", student.nota);
            printf("================================\n");
        }
    }
    return 0;
}
