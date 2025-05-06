//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXIX
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{
    int previousFib = 0;  //hier war 1
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 0; i < n; i++) //hier war <=n
    {
        int newFib = previousFib + currentFib;
        previousFib = currentFib; //hier war newFib
        currentFib = newFib; // hier war previousFib
    }
    return currentFib ;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl;
    std::cout << "f(0) = " << 0 << std::endl; //0 & 1 sind am anfang Konstanten
    std::cout << "f(1) = " << 1 << std::endl;
    for (int i = 2; i <= 12 ; i++) //i war 1
    {
        std::cout << "f(" << i << ") = " << fibonacci(i-1) << std::endl;
    }
    return 0;
}
