#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

// Estruturas para as entidades do modelo
typedef struct {
    int id;
    char nome[50];
    char endereco[100];
    int cervejaFavoritaId;
} Frequentador;

typedef struct {
    int id;
    char nome[50];
    char endereco[100];
} Bar;

typedef struct {
    int id;
    char nome[50];
    int fabricanteId;
} Cerveja;

typedef struct {
    int id;
    char nome[50];
    char endereco[100];
} Fabricante;

typedef struct {
    int id;
    char numero[20];
    int frequentadorId;
} Telefone;

typedef struct {
    int id;
    int barId;
    int cervejaId;
    float valor;
} Preco;

typedef struct {
    int id;
    int frequentadorId;
    int barId;
} Frequenta;

typedef struct {
    int id;
    int fornecedorId;
    int cervejaId;
} Fornece;

// Arrays para armazenar as entidades
Frequentador frequentadores[MAX];
Bar bares[MAX];
Cerveja cervejas[MAX];
Fabricante fabricantes[MAX];
Telefone telefones[MAX];
Preco precos[MAX];
Frequenta frequenta[MAX];
Fornece fornece[MAX];

// Contadores de entidades
int totalFrequentadores = 0, totalBares = 0, totalCervejas = 0;
int totalFabricantes = 0, totalTelefones = 0, totalPrecos = 0;
int totalFrequenta = 0, totalFornece = 0;

// Funções utilitárias
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void obterString(char* buffer, int tamanho, const char* mensagem) {
    printf("%s", mensagem);
    fgets(buffer, tamanho, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int obterInteiro(const char* mensagem) {
    int valor;
    printf("%s", mensagem);
    scanf("%d", &valor);
    limparBufferEntrada();
    return valor;
}

float obterFloat(const char* mensagem) {
    float valor;
    printf("%s", mensagem);
    scanf("%f", &valor);
    limparBufferEntrada();
    return valor;
}

// Funções para adicionar entidades
void adicionarFrequentador() {
    Frequentador f = { totalFrequentadores + 1 };
    obterString(f.nome, 50, "Nome do frequentador: ");
    obterString(f.endereco, 100, "Endereco do frequentador: ");
    f.cervejaFavoritaId = obterInteiro("ID da cerveja favorita: ");
    frequentadores[totalFrequentadores++] = f;
}

void adicionarBar() {
    Bar b = { totalBares + 1 };
    obterString(b.nome, 50, "Nome do bar: ");
    obterString(b.endereco, 100, "Endereco do bar: ");
    bares[totalBares++] = b;
}

void adicionarCerveja() {
    if (totalFabricantes == 0) {
        printf("Erro: Cadastre pelo menos um fabricante antes de adicionar uma cerveja.\n");
        return;
    }

    Cerveja c = { totalCervejas + 1 };
    obterString(c.nome, 50, "Nome da cerveja: ");
    c.fabricanteId = obterInteiro("ID do fabricante: ");
    cervejas[totalCervejas++] = c;
}

void adicionarFabricante() {
    Fabricante f = { totalFabricantes + 1 };
    obterString(f.nome, 50, "Nome do fabricante: ");
    obterString(f.endereco, 100, "Endereco do fabricante: ");
    fabricantes[totalFabricantes++] = f;
}

void adicionarTelefone() {
    Telefone t = { totalTelefones + 1 };
    obterString(t.numero, 20, "Numero do telefone: ");
    t.frequentadorId = obterInteiro("ID do frequentador: ");
    telefones[totalTelefones++] = t;
}

void adicionarPreco() {
    if (totalBares == 0 || totalCervejas == 0) {
        printf("Erro: Cadastre pelo menos um bar e uma cerveja antes de adicionar um preço.\n");
        return;
    }

    Preco p = { totalPrecos + 1 };
    p.barId = obterInteiro("ID do bar: ");
    p.cervejaId = obterInteiro("ID da cerveja: ");
    p.valor = obterFloat("Valor: ");
    precos[totalPrecos++] = p;
}

void adicionarFrequenta() {
    Frequenta f = { totalFrequenta + 1 };
    f.frequentadorId = obterInteiro("ID do frequentador: ");
    f.barId = obterInteiro("ID do bar: ");
    frequenta[totalFrequenta++] = f;
}

void adicionarFornece() {
    Fornece f = { totalFornece + 1 };
    f.fornecedorId = obterInteiro("ID do fornecedor: ");
    f.cervejaId = obterInteiro("ID da cerveja: ");
    fornece[totalFornece++] = f;
}

// Função para exibir todas as entidades
void exibirEntidades() {
    printf("\nFREQUENTADORES:\n");
    for (int i = 0; i < totalFrequentadores; i++) {
        printf("ID: %d, Nome: %s, Endereco: %s, Cerveja Favorita ID: %d\n",
               frequentadores[i].id, frequentadores[i].nome, frequentadores[i].endereco, frequentadores[i].cervejaFavoritaId);
    }

    printf("\nBARES:\n");
    for (int i = 0; i < totalBares; i++) {
        printf("ID: %d, Nome: %s, Endereco: %s\n",
               bares[i].id, bares[i].nome, bares[i].endereco);
    }

    printf("\nCERVEJAS:\n");
    for (int i = 0; i < totalCervejas; i++) {
        printf("ID: %d, Nome: %s, Fabricante ID: %d\n",
               cervejas[i].id, cervejas[i].nome, cervejas[i].fabricanteId);
    }

    printf("\nFABRICANTES:\n");
    for (int i = 0; i < totalFabricantes; i++) {
        printf("ID: %d, Nome: %s, Endereco: %s\n",
               fabricantes[i].id, fabricantes[i].nome, fabricantes[i].endereco);
    }

    printf("\nTELEFONES:\n");
    for (int i = 0; i < totalTelefones; i++) {
        printf("ID: %d, Numero: %s, Frequentador ID: %d\n",
               telefones[i].id, telefones[i].numero, telefones[i].frequentadorId);
    }

    printf("\nPRECOS:\n");
    for (int i = 0; i < totalPrecos; i++) {
        printf("ID: %d, Bar ID: %d, Cerveja ID: %d, Valor: %.2f\n",
               precos[i].id, precos[i].barId, precos[i].cervejaId, precos[i].valor);
    }

    printf("\nFREQUENTA:\n");
    for (int i = 0; i < totalFrequenta; i++) {
        printf("ID: %d, Frequentador ID: %d, Bar ID: %d\n",
               frequenta[i].id, frequenta[i].frequentadorId, frequenta[i].barId);
    }

    printf("\nFORNECE:\n");
    for (int i = 0; i < totalFornece; i++) {
        printf("ID: %d, Fornecedor ID: %d, Cerveja ID: %d\n",
               fornece[i].id, fornece[i].fornecedorId, fornece[i].cervejaId);
    }
}

// Função para exibir o menu
void mostrarMenu() {
    printf("\nMENU\n");
    printf("1. Adicionar Frequentador\n");
    printf("2. Adicionar Bar\n");
    printf("3. Adicionar Cerveja\n");
    printf("4. Adicionar Fabricante\n");
    printf("5. Adicionar Telefone\n");
    printf("6. Adicionar Preco\n");
    printf("7. Adicionar Frequenta\n");
    printf("8. Adicionar Fornece\n");
    printf("9. Exibir Entidades\n");
    printf("10. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int opcao;
    do {
        mostrarMenu();
        opcao = obterInteiro("");
        switch (opcao) {
            case 1:
                adicionarFrequentador();
                break;
            case 2:
                adicionarBar();
                break;
            case 3:
                adicionarCerveja();
                break;
            case 4:
                adicionarFabricante();
                break;
            case 5:
                adicionarTelefone();
                break;
            case 
                6:
                adicionarPreco();
                break;
            case 7:
                adicionarFrequenta();
                break;
            case 8:
                adicionarFornece();
                break;
            case 9:
                exibirEntidades();
                break;
            case 10:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 10);

    return 0;
}
