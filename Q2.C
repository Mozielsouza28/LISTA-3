#include <stdio.h>

int main(){
    int qtdMeses;
    double aporteMensal, Juros, montante = 0.0;

    scanf("%d", &qtdMeses);
    scanf("%lf", &aporteMensal);
    scanf("%lf", &Juros);

    for (int i = 1; i <= qtdMeses; ++i) {
        montante += aporteMensal;
        montante *= (1 + Juros);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, montante);
    }


    return 0;
}