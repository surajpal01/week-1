#include <stdio.h>

int factorial(int n) {
    if(n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int sumDigits(int n) {
    if(n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int n, a, b;

    printf("Enter number for factorial: ");
    scanf("%d", &n);
    printf("Factorial = %d\n", factorial(n));

    printf("Enter number of Fibonacci terms: ");
    scanf("%d", &n);

    printf("Fibonacci = ");
    for(int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));

    printf("\n");

    printf("Enter two numbers for GCD: ");
    scanf("%d %d", &a, &b);
    printf("GCD = %d\n", gcd(a, b));

    printf("Enter number for sum of digits: ");
    scanf("%d", &n);
    printf("Sum of digits = %d", sumDigits(n));

    return 0;
}