#include <iostream>

int main() {
    int f = 1;
    for (int i = 1; i <= 10; i++) f *= i;
    std::cout << f << std::endl;

    f = 1;
    int i = 1;
    while (i <= 10) f *= i++;
    std::cout << f << std::endl;

    f = 1;
    i = 1;
    do f *= i++; while (i <= 10);
    std::cout << f << std::endl;

    return 0;
}