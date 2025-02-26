#include <stdio.h>
#include <stdlib.h>

int main() {
    long long num_cases = 1;
    scanf("%lld", &num_cases);  
    
    while (num_cases--) {
        long long coord_x, coord_y;
        scanf("%lld %lld", &coord_x, &coord_y);
        
        long long level;
        if (coord_y > 0) {
            level = coord_y + llabs(coord_x);
        } else {
            level = -coord_y + 1;
            long long offset = (-4 * coord_y + 3) / 2;
            if (llabs(coord_x) > offset) {
                level += llabs(coord_x) - offset;
            }
        }
        
        long long result = 4 * (level - 1) * (level - 1);  
        long long y_start = -level + 1, x_start = 2 * level - 2;  
        
        if (y_start == coord_y) {
            if (coord_x == 2 * level - 1) result = 4 * level * level;
            result += x_start - coord_x + 1;
            printf("%lld\n", result);
            continue;
        }
        
        result += 4 * level - 2;
        x_start -= 4 * level - 3;
        if (coord_x - x_start == coord_y - y_start) {
            result += coord_x - x_start;
            printf("%lld\n", result);
            continue;
        }
        

        x_start += 2 * level - 1;
        y_start += 2 * level - 1;
        result += 2 * level - 1;
        result += coord_x - x_start;
        printf("%lld\n", result);
    }

    return 0;
}