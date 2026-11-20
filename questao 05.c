
#include <stdio.h>

struct Data{
    int dia, mes, ano;
};

struct Paciente{
    int codigo;
    char nome[50];
    int idade;
};

struct Consulta{
    int codigoPaciente;
    struct Data data;
    char descricao[100];
};

void cadastrarPaciente(struct Paciente *paciente){
    printf("Digite o codigo do paciente: ");
    scanf("%d", &paciente->codigo);

    printf("Digite o nome do paciente: ");
    scanf(" %49[^\n]", paciente->nome);

    printf("Digite a idade do paciente: ");
    scanf("%d", &paciente->idade);
}

void listarPacientes(struct Paciente pacientes[], int quantidade){
    if(quantidade == 0){
        printf("\nNenhum paciente cadastrado.\n");
        return;
    }

    for(int i = 0; i < quantidade; i++){
        printf("\n===== PACIENTE %d =====\n", i + 1);
        printf("Codigo: %d\n", pacientes[i].codigo);
        printf("Nome: %s\n", pacientes[i].nome);
        printf("Idade: %d\n", pacientes[i].idade);
    }
}

int encontrarPaciente(struct Paciente pacientes[], int quantidade, int codigo){
    for(int i = 0; i < quantidade; i++){
        if(pacientes[i].codigo == codigo){
            return i;
        }
    }

    return -1;
}

int cadastrarConsulta(struct Paciente pacientes[], int quantidadePacientes, struct Consulta *consulta){
    int codigo;
    int posicao;

    printf("Digite o codigo do paciente: ");
    scanf("%d", &codigo);

    posicao = encontrarPaciente(pacientes, quantidadePacientes, codigo);

    if(posicao == -1){
        printf("Paciente nao encontrado!\n");
        return 0;
    }

    consulta->codigoPaciente = codigo;

    printf("Digite o dia da consulta: ");
    scanf("%d", &consulta->data.dia);

    printf("Digite o mes da consulta: ");
    scanf("%d", &consulta->data.mes);

    printf("Digite o ano da consulta: ");
    scanf("%d", &consulta->data.ano);

    printf("Digite a descricao do atendimento: ");
    scanf(" %99[^\n]", consulta->descricao);

    printf("Consulta cadastrada com sucesso!\n");

    return 1;
}

void listarConsultas(struct Consulta consultas[], int quantidade){
    if(quantidade == 0){
        printf("\nNenhuma consulta cadastrada.\n");
        return;
    }

    for(int i = 0; i < quantidade; i++){
        printf("\n===== CONSULTA %d =====\n", i + 1);
        printf("Codigo do paciente: %d\n", consultas[i].codigoPaciente);
        printf("Data: %02d/%02d/%d\n", consultas[i].data.dia, consultas[i].data.mes, consultas[i].data.ano);
        printf("Descricao: %s\n", consultas[i].descricao);
    }
}

void consultarPaciente(struct Paciente pacientes[], int quantidadePacientes, struct Consulta consultas[], int quantidadeConsultas){
    int codigo;
    int encontrou = 0;

    printf("Digite o codigo do paciente: ");
    scanf("%d", &codigo);

    int posicao = encontrarPaciente(pacientes, quantidadePacientes, codigo);

    if(posicao == -1){
        printf("Paciente nao encontrado!\n");
        return;
    }

    printf("\n===== CONSULTAS DO PACIENTE =====\n");
    printf("Nome: %s\n", pacientes[posicao].nome);

    for(int i = 0; i < quantidadeConsultas; i++){
        if(consultas[i].codigoPaciente == codigo){
            printf("\nData: %02d/%02d/%d\n", consultas[i].data.dia, consultas[i].data.mes, consultas[i].data.ano);
            printf("Descricao: %s\n", consultas[i].descricao);
            encontrou = 1;
        }
    }

    if(encontrou == 0){
        printf("Nenhuma consulta encontrada para esse paciente.\n");
    }
}

void listarConsultasPorData(struct Consulta consultas[], int quantidade){
    int dia, mes, ano;
    int encontrou = 0;

    printf("Digite o dia: ");
    scanf("%d", &dia);

    printf("Digite o mes: ");
    scanf("%d", &mes);

    printf("Digite o ano: ");
    scanf("%d", &ano);

    for(int i = 0; i < quantidade; i++){
        if(consultas[i].data.dia == dia && consultas[i].data.mes == mes && consultas[i].data.ano == ano){
            printf("\nCodigo do paciente: %d\n", consultas[i].codigoPaciente);
            printf("Data: %02d/%02d/%d\n", consultas[i].data.dia, consultas[i].data.mes, consultas[i].data.ano);
            printf("Descricao: %s\n", consultas[i].descricao);
            encontrou = 1;
        }
    }

    if(encontrou == 0){
        printf("Nenhuma consulta encontrada nessa data.\n");
    }
}

int contarConsultas(struct Consulta consultas[], int quantidade, int codigo){
    int total = 0;

    for(int i = 0; i < quantidade; i++){
        if(consultas[i].codigoPaciente == codigo){
            total++;
        }
    }

    return total;
}

int pacienteMaisConsultas(struct Paciente pacientes[], int quantidadePacientes, struct Consulta consultas[], int quantidadeConsultas){
    int posicaoMaior = -1;
    int maior = 0;

    for(int i = 0; i < quantidadePacientes; i++){
        int total = contarConsultas(consultas, quantidadeConsultas, pacientes[i].codigo);

        if(total > maior){
            maior = total;
            posicaoMaior = i;
        }
    }

    return posicaoMaior;
}

int main(){
    struct Paciente pacientes[15];
    struct Consulta consultas[30];

    int quantidadePacientes = 0;
    int quantidadeConsultas = 0;
    int opcao;

    do{
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Listar pacientes\n");
        printf("3 - Cadastrar consulta\n");
        printf("4 - Listar consultas\n");
        printf("5 - Consultar paciente\n");
        printf("6 - Consultas por data\n");
        printf("7 - Paciente com mais consultas\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            if(quantidadePacientes < 15){
                cadastrarPaciente(&pacientes[quantidadePacientes]);
                quantidadePacientes++;
            }else{
                printf("Limite de pacientes atingido!\n");
            }
        }

        if(opcao == 2){
            listarPacientes(pacientes, quantidadePacientes);
        }

        if(opcao == 3){
            if(quantidadeConsultas < 30){
                if(cadastrarConsulta(pacientes, quantidadePacientes, &consultas[quantidadeConsultas])){
                    quantidadeConsultas++;
                }
            }else{
                printf("Limite de consultas atingido!\n");
            }
        }

        if(opcao == 4){
            listarConsultas(consultas, quantidadeConsultas);
        }

        if(opcao == 5){
            consultarPaciente(pacientes, quantidadePacientes, consultas, quantidadeConsultas);
        }

        if(opcao == 6){
            listarConsultasPorData(consultas, quantidadeConsultas);
        }

        if(opcao == 7){
            int posicao = pacienteMaisConsultas(pacientes, quantidadePacientes, consultas, quantidadeConsultas);

            if(posicao == -1){
                printf("Nenhum paciente possui consultas.\n");
            }else{
                printf("\n===== PACIENTE COM MAIS CONSULTAS =====\n");
                printf("Nome: %s\n", pacientes[posicao].nome);
                printf("Codigo: %d\n", pacientes[posicao].codigo);
                printf("Total de consultas: %d\n", contarConsultas(consultas, quantidadeConsultas, pacientes[posicao].codigo));
            }
        }

    }while(opcao != 0);

    return 0;
}

