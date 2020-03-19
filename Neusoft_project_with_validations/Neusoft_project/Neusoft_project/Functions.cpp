#include "Functions.h"
#include <iostream>
void menu() {
    std::cout << std::endl;
    std::cout << "x.Exit" << std::endl;
    std::cout << "1.Add a doctor" << std::endl;
    std::cout << "2.Print all doctors" << std::endl;
    std::cout << "3.Add a patient" << std::endl;
    std::cout << "4.Print all patients" << std::endl;
}
void print_sumarry(int number_of_childrens, int number_of_pupils, int number_of_students, int number_of_adults) {
    std::cout << std::endl;
    std::cout << "Children (0-1): " << number_of_childrens << " patients"<<std::endl;
    std::cout << "Children (1-7): " << number_of_pupils << " patients" << std::endl;
    std::cout << "Children (7-18): " << number_of_students << " patients" << std::endl;
    std::cout << "Children (>18): " << number_of_adults << " patients" << std::endl;
}