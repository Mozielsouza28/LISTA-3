#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int ultimoDigitoPlaca(char placaCarro[10]){
    return placaCarro[strlen(placaCarro) - 1] - '0';
}

void qtdLetrasNumeros(char placaCarro[10], int* qtdLetras, int* qtdNumeros){
    for (int i = 0; i < strlen(placaCarro); ++i) {
        if(isalpha(placaCarro[i])){
            *qtdLetras = *qtdLetras + 1;
        } if(isdigit(placaCarro[i])){
            *qtdNumeros = *qtdNumeros + 1;
        }
    }
}

void validaPlaca(char placaCarro[10], int qtdLetras, int qtdNumeros, int* placaEhValida){
    char *contemHifem = strchr(placaCarro, '-');
    //printf("%llu\n", strlen(contemHifem));
    if(contemHifem != NULL){ //placa antiga
        if(qtdLetras == 3 && qtdNumeros == 4 && strlen(contemHifem) == 5){
            *placaEhValida = 1;
        }
    } else{ // placa nova
        if(qtdLetras == 4 && qtdNumeros == 3){
            *placaEhValida = 1;
        }
    }
}

void validaSemana(char diasDaSemana[][14], char *diaSemana, int *diaEhValido){
    for (int i = 0; i < 7; i++) {
        if (strstr(diaSemana, diasDaSemana[i]) != NULL) {
            *diaEhValido = 1;
        }
    }
}

void verificaPlacaEDia(int diaEhValido, int placaEhValida){
    if(diaEhValido == 0 || placaEhValida == 0){
        if(placaEhValida == 0){
            printf("Placa invalida\n");
        }
        if(diaEhValido == 0){
            printf("Dia da semana invalido\n");
        }
        exit(0);
    }
}


int main(){
    char placaCarro[10], diaSemana[14], diaSemanaNaoPermitido[14];
    char diasDaSemana[][14] = {
            "DOMINGO", "SEGUNDA-FEIRA", "TERCA-FEIRA",
            "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO"
    };
    int placaEhValida = 0, diaEhValido = 0, qtdLetras = 0, qtdNumeros = 0;

    fgets(placaCarro, sizeof(placaCarro), stdin);
    placaCarro[strcspn(placaCarro, "\n")] = '\0';
    scanf("%s", diaSemana);


    qtdLetrasNumeros(placaCarro, &qtdLetras, &qtdNumeros);

    validaPlaca(placaCarro, qtdLetras, qtdNumeros, &placaEhValida);


    validaSemana(diasDaSemana, diaSemana, &diaEhValido);

    verificaPlacaEDia(diaEhValido, placaEhValida);

    switch (ultimoDigitoPlaca(placaCarro)) {
        case 0:
        case 1:
            strcpy(diaSemanaNaoPermitido, diasDaSemana[1]);
            break;
        case 2:
        case 3:
            strcpy(diaSemanaNaoPermitido, diasDaSemana[2]);
            break;
        case 4:
        case 5:
            strcpy(diaSemanaNaoPermitido, diasDaSemana[3]);
            break;
        case 6:
        case 7:
            strcpy(diaSemanaNaoPermitido, diasDaSemana[4]);
            break;
        case 8:
        case 9:
            strcpy(diaSemanaNaoPermitido, diasDaSemana[5]);
            break;
    }

    if (strcmp(diaSemana, diasDaSemana[0]) == 0 || strcmp(diaSemana, diasDaSemana[6]) == 0){
        printf("Nao ha proibicao no fim de semana\n");
    } else if(strcmp(diaSemana, diaSemanaNaoPermitido) != 0){
        toLowerCase(diaSemana);
        printf("%s pode circular %s\n", placaCarro, diaSemana);
    } else{
        toLowerCase(diaSemana);
        printf("%s nao pode circular %s\n", placaCarro, diaSemana);

    }
    return 0;
}