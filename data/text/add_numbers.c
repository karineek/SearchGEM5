// Modification Timestamp: 2023-08-03 18:00:30
// Original Source: https://www.programiz.com/c-programming/examples/add-numbers

#include <stdio.h>

int main() {    
    int number1, number2, sum;
    
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);

    // calculate the sum
    sum = number1 + number2;      
    
    printf("%d + %d = %d", number1, number2, sum);
    return 0;
}
