#include <stdio.h>
#include <string.h>

// Função para mapear caracteres numéricos romanos para seus valores decimais
int converterRomanoParaDecimal(char simbolo) {
    switch (simbolo) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

// Função para converter um numeral romano para decimal
int calcularValorDecimal(char *numeralRomano) {
    int resultado = 0;
    for (int i = 0; numeralRomano[i]; i++) {
        if (converterRomanoParaDecimal(numeralRomano[i]) < converterRomanoParaDecimal(numeralRomano[i + 1])) {
            resultado -= converterRomanoParaDecimal(numeralRomano[i]);
        } else {
            resultado += converterRomanoParaDecimal(numeralRomano[i]);
        }
    }
    return resultado;
}

// Função para converter decimal para binário
void converterDecimalParaBinario(int decimal, char binario[]) {
    binario[0] = '\0';
    while (decimal > 0) {
        char digito[2];
        sprintf(digito, "%d", decimal % 2);
        strcat(binario, digito);
        decimal /= 2;
    }
    int tamanho = strlen(binario);
    for (int i = 0; i < tamanho / 2; i++) {
        char temp = binario[i];
        binario[i] = binario[tamanho - 1 - i];
        binario[tamanho - 1 - i] = temp;
    }
}

// Função para converter decimal para hexadecimal
void converterDecimalParaHexadecimal(int decimal, char hexadecimal[]) {
    int i = 0, resto;
    hexadecimal[0] = '\0';
    while (decimal > 0) {
        resto = decimal % 16;
        char digito[2];
        if (resto < 10) {
            sprintf(digito, "%d", resto);
        } else {
            sprintf(digito, "%c", resto - 10 + 'a');
        }
        strcat(hexadecimal, digito);
        decimal /= 16;
        i++;
    }
    int comprimento = strlen(hexadecimal);
    for (int i = 0; i < comprimento / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[comprimento - 1 - i];
        hexadecimal[comprimento - 1 - i] = temp;
    }
}

// Função principal
int main() {
    char entradaRomano[15], saidaBinaria[32], saidaHexadecimal[100];
    int valorDecimal;
    
    // Entrada do numeral romano
    scanf("%s", entradaRomano);
    
    // Converte numeral romano para decimal
    valorDecimal = calcularValorDecimal(entradaRomano);
    
    // Converte decimal para binário e hexadecimal
    converterDecimalParaBinario(valorDecimal, saidaBinaria);
    converterDecimalParaHexadecimal(valorDecimal, saidaHexadecimal);
    
    // Exibe os resultados
    printf("%s na base 2: %s\n", entradaRomano, saidaBinaria);
    printf("%s na base 10: %d\n", entradaRomano, valorDecimal);
    printf("%s na base 16: %s\n", entradaRomano, saidaHexadecimal);
    
    return 0;
}
