#include <stdio.h>

struct Aluno{
    char nome[50];
    int matricula;
    float nota1, nota2;
    float media;
};

struct Aluno cadastrarAluno(){
    
    struct Aluno aluno;
    
    printf("Digite a matricula: ");
    scanf("%d", &aluno.matricula);
    
    printf("Digite o nome do aluno: ");
    scanf(" %49[^\n]", aluno.nome);
    
    printf("Digite a primeira nota: ");
    scanf("%f", &aluno.nota1);
    
    printf("Digite a segunda nota: ");
    scanf("%f", &aluno.nota2);
    
    aluno.media = (aluno.nota1 + aluno.nota2) / 2;
    
    return aluno;
}

int main(){
    
    int maiorMedia = 0;
    int menorMedia = 0;
    int acimaMedia = 0;
    
    float turmaMedia = 0;
    float mediaGeral;
    
    struct Aluno alunos[10];
    
    for(int i = 0; i < 10; i++){
        
        printf("\n===== ALUNO %d =====\n", i + 1);
        
        alunos[i] = cadastrarAluno();
    }
    
    for(int i = 0; i < 10; i++){
        
        if(alunos[i].media > alunos[maiorMedia].media){
            maiorMedia = i;
        }
        
        if(alunos[i].media < alunos[menorMedia].media){
            menorMedia = i;
        }
        
        turmaMedia += alunos[i].media;
    }
    
    mediaGeral = turmaMedia / 10;
    
    for(int i = 0; i < 10; i++){
        
        if(alunos[i].media > mediaGeral){
            acimaMedia++;
        }
    }
    
    for(int i = 0; i < 10; i++){
        
        printf("\n===== RESULTADO DO ALUNO =====\n");
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Media: %.2f\n", alunos[i].media);
        
        if(alunos[i].media >= 6){
            printf("Situacao: Aprovado\n");
        }else{
            printf("Situacao: Reprovado\n");
        }
    }
    
    printf("\n===== RESULTADO DA TURMA =====\n");
    
    printf("Maior media: %s - %.2f\n", alunos[maiorMedia].nome, alunos[maiorMedia].media);
    printf("Menor media: %s - %.2f\n", alunos[menorMedia].nome, alunos[menorMedia].media);
    printf("Media geral da turma: %.2f\n", mediaGeral);
    printf("Alunos acima da media geral: %d\n", acimaMedia);
    
    return 0;
}
