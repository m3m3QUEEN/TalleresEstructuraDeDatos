#include <stdio.h>
#include <math.h>

double desviacion_estandar(int n) {
    // Calcular el promedio (mu) de los primeros n numeros impares
    double promedio = n;
    
    // Calcular la suma de los cuadrados de las diferencias respecto al promedio
    double suma_cuadrados = 0;
    for (int i = 1; i <= n; i++) {
        int impar = 2 * i - 1;
        suma_cuadrados += (impar - promedio) * (impar - promedio);
    }
    
    // Calcular la desviacion estandar
    double desviacion = sqrt(suma_cuadrados / n);
    return desviacion;
}

int main() {
    int n;
    
    while (1) {
        // Leer el numero n
        scanf("%d", &n);
        
        // Si el valor de n es 0, terminamos la entrada
        if (n == 0) {
            break;
        }
        
        // Calcular y mostrar la desviacion estandar
        double resultado = desviacion_estandar(n);
        printf("%.6f\n", resultado);
    }
    
    return 0;
}