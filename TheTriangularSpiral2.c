#include <stdio.h>
#include <stdlib.h>

long long valor_absoluto(long long numero) {
    return (numero < 0) ? -numero : numero;
}

int main() {
    long long coord_x, coord_y;
    printf("Ingrese la coordenada (x y): ");
    scanf("%lld %lld", &coord_x, &coord_y);

    if (coord_x == 0 && coord_y == 0) {
        printf("1\n");
        return 0;
    }

    long long nivel_espiral = valor_absoluto(coord_y) + valor_absoluto(coord_x);
    if (coord_y > 0) {
        nivel_espiral = coord_y + valor_absoluto(coord_x);
    } else {
        nivel_espiral = -coord_y + 1;
        long long auxiliar = (-4 * coord_y + 3) / 2;
        if (valor_absoluto(coord_x) > auxiliar) {
            nivel_espiral += valor_absoluto(coord_x) - auxiliar;
        }
    }

    long long puntos_previos = 4 * (nivel_espiral - 1) * (nivel_espiral - 1);

    long long primer_x = 2 * nivel_espiral - 2, primer_y = -nivel_espiral + 1;

    if (primer_y == coord_y) {
        long long termino_n = puntos_previos + (primer_x - coord_x) + 1;
        printf("%lld\n", termino_n);
        return 0;
    }

    puntos_previos += (4 * nivel_espiral - 2);
    primer_x -= (4 * nivel_espiral - 3);
    if (coord_x - primer_x == coord_y - primer_y) {
        long long termino_n = puntos_previos + (coord_x - primer_x);
        printf("%lld\n", termino_n);
        return 0;
    }

    puntos_previos += (2 * nivel_espiral - 2);
    primer_x += (2 * nivel_espiral - 1);
    primer_y += (2 * nivel_espiral - 1);
    long long termino_n = puntos_previos + (coord_x - primer_x);
    printf("%lld\n", termino_n);

    return 0;
}