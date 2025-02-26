#include <stdio.h>
#include <stdlib.h>


int main() {
    long long n;
    printf("Ingrese el n-esimo termino para conocer su coordenada: ");
    scanf("%lld", &n);
    
    if (n == 1) {
        printf("0 0\n");
        return 0;
    }
    
    long long k = 1;
    while (4 * k * k < n) {
        k++;
    }
    
    long long prev_points = 4 * (k - 1) * (k - 1);
    long long x = 2 * k - 2, y = -k + 1;
    long long pos = prev_points + 1;
    
    // Parte inferior
    if (n <= prev_points + (4 * k - 2)) {
        printf("%lld %lld\n", x - (n - pos), y);
        return 0;
    }
    
    pos += (4 * k - 2);
    x -= (4 * k - 3);
    
    // Diagonal izquierda
    if (n <= pos + (2 * k - 2)) {
        printf("%lld %lld\n", x + (n - pos), y + (n - pos));
        return;
    }
    
    pos += (2 * k - 2);
    x += (2 * k - 1);
    y += (2 * k - 1);
    
    // Diagonal derecha
    printf("%lld %lld\n", x + (n - pos), y - (n - pos));
    return 0;
}