#include <stdio.h>

#define QTDNC 2

typedef struct {
    float real, imaginaria;
} numcomplex;

void leNumComplex(numcomplex *nc) {
    printf("\nParte Real: ");
    scanf("%f", &nc->real);

    printf("Parte Imaginaria: ");
    scanf("%f", &nc->imaginaria);
}

void escreveNumComplex(numcomplex nc) {
    printf("\nNumero Complexo: ");
    if ((nc.real != 0) || (nc.imaginaria == 0)) {
        printf("%.2f", nc.real);
    }
    if (nc.imaginaria != 0) {
        if ((nc.imaginaria > 0) && (nc.real != 0)) {
            printf("+%.2f", nc.imaginaria);
        } else {
            printf("%.2f", nc.imaginaria);
        }
        printf("i");
    }
    printf("\n");
}

numcomplex somaNumComplex(numcomplex a, numcomplex b) {
    numcomplex resultado;
    resultado.real = a.real + b.real;
    resultado.imaginaria = a.imaginaria + b.imaginaria;
    return resultado;
}

numcomplex produtoNumComplex(numcomplex a, numcomplex b) {
    numcomplex resultado;
    resultado.real = (a.real * b.real) - (a.imaginaria * b.imaginaria);
    resultado.imaginaria = (a.real * b.imaginaria) + (a.imaginaria * b.real);
    return resultado;
}

// Retorna 1 se iguais, 0 se diferentes
int iguaisNumComplex(numcomplex a, numcomplex b) {
    return (a.real == b.real) && (a.imaginaria == b.imaginaria);
}

// Retorna o oposto do número complexo
numcomplex opostoNumComplex(numcomplex nc) {
    numcomplex resultado;
    resultado.real = -nc.real;
    resultado.imaginaria = -nc.imaginaria;
    return resultado;
}

// Retorna o conjugado do número complexo
numcomplex conjugadoNumComplex(numcomplex nc) {
    numcomplex resultado;
    resultado.real = nc.real;
    resultado.imaginaria = -nc.imaginaria;
    return resultado;
}

int main() {
    int i;
    numcomplex vetorNC[QTDNC];
    numcomplex sNC, pNC;

    for (i = 0; i < QTDNC; i++) {
        printf("\n====================");
        printf("\n%dº Numero Complexo", i + 1);
        printf("\n====================\n");
        leNumComplex(&vetorNC[i]);
        escreveNumComplex(vetorNC[i]);
    }

    printf("\n====================");
    printf("\nSoma");
    printf("\n====================\n");
    sNC = somaNumComplex(vetorNC[0], vetorNC[1]);
    escreveNumComplex(sNC);

    printf("\n====================");
    printf("\nProduto");
    printf("\n====================\n");
    pNC = produtoNumComplex(vetorNC[0], vetorNC[1]);
    escreveNumComplex(pNC);

    // Exemplos de uso das novas rotinas:
    printf("\n====================");
    printf("\nIgualdade");
    printf("\n====================\n");
    if (iguaisNumComplex(vetorNC[0], vetorNC[1])) {
        printf("Os números complexos são iguais.\n");
    } else {
        printf("Os números complexos são diferentes.\n");
    }

    printf("\n====================");
    printf("\nOposto do 1º Numero Complexo");
    printf("\n====================\n");
    escreveNumComplex(opostoNumComplex(vetorNC[0]));

    printf("\n====================");
    printf("\nConjugado do 1º Numero Complexo");
    printf("\n====================\n");
    escreveNumComplex(conjugadoNumComplex(vetorNC[0]));

    printf("\n====================\n");

    return 0;
}