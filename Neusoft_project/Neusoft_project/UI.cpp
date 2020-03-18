#include "UI.h"
#include "Functions.h"
#include <iostream>
#include <string>
using namespace std;
void UI::valid_name(char *name, int len_name) {
    string aux;
    do {
        getline(std::cin,aux);
        if (aux.length() > len_name)
            cout << "Invalid name! Please try again: ";
    } while (aux.length() > len_name);
    strcpy_s(name, 1 + aux.length(), aux.c_str());
}
void UI::valid_age(int& age,int min,int max) {
    do {
        cin >> age;
        if (age<min or age>max)
            cout << "Invalid age! Try again: ";
    } while (age<min or age>max);
}
void UI::ui_cin_person(char *first_name, char* last_name,int &age,int len_first_name,int len_second_name,int min,int max) {

    cout << "Give a first name: ";
    cin.get();
    valid_name(first_name, len_first_name);
    cout << "Give a last name: ";
    valid_name(last_name, len_second_name);
    cout << "Give a age: ";
    valid_age(age, min, max);
}
void UI::ui_add_patient() {
    char *first_name=new char[0], *last_name=new char[0],reason[12];
    int age;
    cout << "Patients: " << endl;
    ui_cin_person(first_name, last_name, age,5,4,0,85);
    cout << "Give a reason: ";
    cin >> reason;
    this->service_patient.service_add_patient(first_name, last_name, age, reason);
}
void UI::ui_print_patients(){
    cout << endl;
    for (int i = 0; i < this->service_patient.service_get_len_patients(); i++)
        cout << this->service_patient.service_get_all_patients()[i] << endl;
}
void UI::valid_id(int &id) {
    do{
        do {
                cin >> id;
                if(id / 1000 == 0 or id / 1000 >= 10)
                    cout << "Invalid id, try again: ";
            } while (id / 1000 == 0 or id / 1000 >= 10);
            if (!this->service_doctor.id_is_unic(id))
                cout << "This id exist! Please give another id: ";
    } while (!this->service_doctor.id_is_unic(id));
    
}
void UI::ui_add_doctor() {
    char *first_name=new char[0], *last_name=new char[0];
    int id,age;
    cout << "Doctors: "<<endl;
    cout << "Give an ID: ";
    valid_id(id);
    ui_cin_person(first_name, last_name, age,3,2,30,65);
    this->service_doctor.service_add_doctor(id, first_name, last_name, age);
}
void UI::ui_print_doctors() {
    cout << endl;
    for (int i = 0; i < this->service_doctor.service_get_len_doctors(); i++)
        cout << this->service_doctor.service_get_all_doctors()[i] << endl;
}
void UI::run() {
    int opt = 1;
    while (opt) {
        cout << endl<< "Chose an option ";
        menu();
        cout << "Your option is: ";
        cin >> opt;
        if (opt == 1) {
            this->ui_add_doctor();
        }
        if (opt == 2) {
            this->ui_print_doctors();
        }
        if (opt == 3) {
            this->ui_add_patient();
        }
        if (opt == 4) {
            this->ui_print_patients();
        }
    }
}