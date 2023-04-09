#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int karatsuba(int x, int y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    int n = fmax(log10(x) + 1, log10(y) + 1);
    int m = (n + 1) / 2;

    int a = x / (int)pow(10, m);
    int b = x % (int)pow(10, m);
    int c = y / (int)pow(10, m);
    int d = y % (int)pow(10, m);

    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int abcd = karatsuba(a + b, c + d);

    return ac * (int)pow(10, 2 * m) + (abcd - ac - bd) * (int)pow(10, m) + bd;
}

int main() {
    int x, y;
    printf("Enter two integers to multiply: ");
    scanf("%d %d", &x, &y);
    printf("The result of Karatsuba multiplication is: %d\n", karatsuba(x, y));
    return 0;
}
