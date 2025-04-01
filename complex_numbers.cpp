#include <iostream>
#include "complex_numbers.hpp"

/*
prova per verificare la corretta implementazione del file complex_numbers.hpp
PER ESEGUIRE: g++ -std=c++20 -o complex complex_numbers.cpp
*/


int main(void) {
    using cpx = complex_number<double>;

    complex_number<float> c1(3.0f, 2.95f);
    cpx c2(1.35, 4.78);
    cpx c2_p(1.35, 4.78);
    cpx c3(0.35);
    cpx c4(0.35, false);
    cpx c5;
    cpx c6(3.35, -6.66);

    //complex c1(3.0,2.0);
    
    std::cout << "CASO 1 (float): " << c1 << std::endl;
    std::cout << "CASO 2 (double): " << c2 << std::endl;
    std::cout << "CASO 3 (immaginario 0): " << c3 << std::endl;
    std::cout << "CASO 4 (reale 0): " << c4 << std::endl;
    std::cout << "CASO 5 (tutto 0): " << c5 << std::endl;
    std::cout << "CASO 6 (immaginario negativo): " << c6 << std::endl << std::endl << std::endl;


    std::cout << "Numero originale: " << c6 << std::endl;
    std::cout << "Parte reale: " << c6.get_real_p() << std::endl;
    std::cout << "Parte immaginaria: " << c6.get_img_p() << std::endl;
    std::cout << "Complesso coniugato: " << c6.get_complex_conjugate() << std::endl << std::endl << std::endl;;

    //prova overload +=
    c2 += c6;
    std:: cout << "--- PROVA SOMMA (stesso tipo)    " << c2_p << " + " << c6 << " ------------" << std::endl;
    std::cout << "Prova overload + : " << c2_p + c6 << std::endl;
    std::cout << "Prova overload += : " << c2 << std::endl << std::endl;
    std:: cout << "--- PROVA SOMMA (tipo diverso)   " << "3.0 + " << c6 << " + 6.0 ------------" << std::endl;
    std::cout << "Prova overload + : " <<3.0 + c6 + 6.0 << std::endl << std::endl << std::endl;;

    //prova overload *=
    std:: cout << "--- PROVA PRODOTTO (stesso tipo)     " << c2_p << " * " << c6 << " ------------" << std::endl;
    std::cout << "Prova overload * : " << c2_p * c6 << std::endl;
    c2_p *= c6;
    std::cout << "Prova overload *= : " << c2_p << std::endl;
    
    std:: cout << "--- PROVA PRODOTTO (tipo diverso)    " << "3.0 * " << c6 << " * 6.0 ------------" << std::endl;
    std::cout << "Prova overload * : " << 3.0 * c6 * 6.0<< std::endl << std::endl << std::endl;;
    

    return 0;
}