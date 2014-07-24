// Obliczanie liczb Fibonacciego za pomocą potęgowania macierzy
// Data: 19.02.2012
// (C)2012 mgr Jerzy Wałaszek
//-------------------------------------------------------------
    
#include <iostream>

using namespace std;

// Oblicza n-tą liczbę Fibonacciego
//---------------------------------
unsigned long long fibo(int n)
{
    unsigned long long q11,q12,q21,q22, // macierz Q
    p11,p12,p21,p22, // macierz P
    w11,w12,w21,w22; // macierz W

    if(n < 2) return n;

    // ustawiamy macierz Q

    q11 = q12 = q21 = 1;
    q22 = 0;

    // w macierzy W tworzymy macierz jednostkową

    w11 = w22 = 1;
    w12 = w21 = 0;

    n--;      // będzie nam potrzebna n-1 potęga Q

    while(n)
    {
        if(n & 1)
        {
        // wykonujemy mnożenie P = W x Q

        p11 = w11*q11 + w12 * q21; p12 = w11*q12 + w12 * q22;
        p21 = w21*q11 + w22 * q21; p22 = w21*q12 + w22 * q22;

        // wynik przenosimy: W = P

        w11 = p11; w12 = p12;
        w21 = p21; w22 = p22;

        }

        n >>= 1;    // usuwamy z n sprawdzony bit

        if(!n) break;

        // podnosimy Q do kwadratu:  P = Q x Q

        p11 = q11*q11 + q12 * q21; p12 = q11*q12 + q12 * q22;
        p21 = q21*q11 + q22 * q21; p22 = q21*q12 + q22 * q22;

        // wynik przenosimy: Q = p

        q11 = p11; q12 = p12;
        q21 = p21; q22 = p22;

    }

    return w11;
}

// Program główny
//---------------

int main()
{
    for(int i = 0; i < 94; i++) cout << "F(" << i << ") = " << fibo(i) << endl;
    return 0;
} 
