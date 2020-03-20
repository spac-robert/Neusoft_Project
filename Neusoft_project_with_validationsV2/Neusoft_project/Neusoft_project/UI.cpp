#include "UI.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Name validation

void UI::valid_name(char *name, int len_name) { // Input: Char* name and len_name where len_name is the len of name for doctor and patient
    string aux;
    do {
        getline(std::cin,aux);
        if (aux.length() > len_name) 
            cout << "Invalid name! Please try again: ";
    } while (aux.length() > len_name);
    strcpy_s(name, 1 + aux.length(), aux.c_str());
}

//Age validation
void UI::valid_age(int& age,int min,int max) {
    //Read a string and verify if it has 1 or 2 digits. If it's true, bild in age variable the number and ferify if  min<= age <=max.
    //if we have a doctor min is 30 and max is 65
    //if we have a patient min is 0 and max is 85
    string aux_age;
    age = -1;
    bool ok = 0;
    do {
        cin >> aux_age;
        if (aux_age.size() == 1)
            if ('0' <= aux_age[0] and aux_age[0] <= '9')
                age = (aux_age[0] - '0');
            else
                cout << "Invalid age! Try again: ";
        else
            if (aux_age.size() == 2)
                if ('0' <= aux_age[0] and aux_age[0] <= '9' and '0' <= aux_age[1] and aux_age[1] <= '9')
                    age = (aux_age[0]-'0') * 10 + (aux_age[1] - '0');
        if (age != -1)
            if (age<min or age>max)
                cout << "Invalid age! Try again: ";
            else
                ok = 1;
        else
            cout << "Invalid age! Try again: ";
    } while (!ok);
}

//Read a person ( first name , last name and the age ). We use tis function to ceate a doctors and patients
void UI::read_person(char *first_name, char* last_name,int &age,int len_first_name,int len_last_name,int min,int max) {

    cout << "Give a first name (first name must have "<<len_first_name<<" characters): ";
    cin.get();
    valid_name(first_name, len_first_name); //Name validation function
    cout << "Give a last name (last name must have " << len_last_name << " characters): ";
    valid_name(last_name, len_last_name);//Name validation function
    cout << "Give a age ( "<<min<<" - "<<max<<" ): ";
    valid_age(age, min, max);//Age validation function
}

//Reason validation 
void UI::valid_reason(char* reason) {
    int ok = 0;
    do {
        std::cin >> reason; // Read a reason
        if (strcmp(reason, "consultation") == 0 or strcmp(reason, "treatment") == 0 or strcmp(reason, "prescription") == 0) // if reason is consultation or treatment or prescription , the reason is good
            ok = 1;
        else
            std::cout << "Invalid reason! Please give a valid reason: consultation , treatment , prescription  ";
    } while (ok == 0);
}

//Write all Patients
void UI::print_patients(){
    cout << endl;
    for (int i = 0; i < this->service_patient.service_get_len_patients(); i++)
        cout << this->service_patient.service_get_all_patients()[i] << endl;
}

//ID validation
void UI::valid_id(int &id) {
    //Read a sting and verify if len of string is 4.
    string aux_id;  
    bool ok = false;
    do{
        do {
                cin >> aux_id;
                if (aux_id.size() != 4)
                    cout << "Invalid id, try again: ";
                else {
                    //Create the id if we have numbers not letters
                    id = (aux_id[0] - '0') * 1000 + (aux_id[1] - '0') * 100 + (aux_id[2] - '0') * 10 + (aux_id[3] - '0');
                    //Verify if the id has 4 digits
                    if (id / 1000 > 0 and id / 1000 <= 9)
                        ok = true;
                    else
                        cout << "Invalid id, try again: ";
                }
            } while (!ok);
            if (!this->service_doctor.id_is_unique(id))//Verify the id to be unique and we have not this id in Doctors.txt
                cout << "This id exist! Please give another id: ";
    } while (!this->service_doctor.id_is_unique(id));
    
}

//Add a patient
void UI::add_patient() {
    char* first_name = new char[0], * last_name = new char[0], * reason = new char[0];
    int age;
    cout << "Patients: " << endl;
    read_person(first_name, last_name, age, 5, 4, 0, 85);
    cout << "Give a reason (consultation , treatment , prescription):  ";
    valid_reason(reason);
    this->service_patient.service_add_patient(first_name, last_name, age, reason);//Send the row information for encapsulation to Patient class
    
    //Create a .txt file where we save the patients
    fstream file_patients;
    file_patients.open("Patients.txt", ios::out | ios::in | ios::app);
    if (file_patients.is_open())
        file_patients <<first_name << ' ' << last_name << ' ' << age <<' '<< reason << endl;
    else
        cout << "Something is wrong! ";
    file_patients.close();
}

//Add a doctor
void UI::add_doctor() {
    char *first_name=new char[0], *last_name=new char[0];
    int id,age;
    cout << "Doctors: "<<endl;
    cout << "Give an ID (ID must have 4 digits): ";
    valid_id(id);
    read_person(first_name, last_name, age,3,2,30,65);
    this->service_doctor.service_add_doctor(id, first_name, last_name, age);
    
    //Create a .txt file where we save the doctors
    fstream file_doctor;

    file_doctor.open("Doctors.txt", ios::out | ios::in | ios::app);
    if (file_doctor.is_open())
        file_doctor << id << ' ' << first_name << ' ' << last_name << ' ' << age << endl;
    else
        cout << "Something is wrong! ";
    file_doctor.close();
}

//Printing a summary of all patients based on their age group
void UI::print_sumarry_all_patients() {

    int len_patient= this->service_patient.service_get_len_patients(),number_of_childrens = 0, number_of_pupils = 0, number_of_students = 0, number_of_adults = 0;
    Patient* array = this->service_patient.service_get_all_patients();
    
    for (int i = 0; i < len_patient; i++) {
        if (array[i].get_age() <= 1)
            number_of_childrens++;
        if (array[i].get_age() > 1 and array[i].get_age() <= 7)
            number_of_pupils++;
        if (array[i].get_age() > 7 and array[i].get_age() <= 18)
            number_of_students++;
        if (array[i].get_age() > 18)
            number_of_adults++;
    }

    print_sumarry(number_of_childrens, number_of_pupils, number_of_students, number_of_adults);
}

//Printing all doctors
void UI::print_doctors() {
    cout << endl;
    int len_doctors= this->service_doctor.service_get_len_doctors();
    for (int i = 0; i < len_doctors; i++)
        cout << this->service_doctor.service_get_all_doctors()[i] << endl;
}

void UI::run() {
    string opt;
    bool ok = true;
   do {
        cout << endl<< "Chose an option ";
        menu();
        cout << "Your option is: ";
        cin >> opt;
        if (opt.size() == 1)
        {
            if (opt[0] == '1') {
                this->add_doctor();
            }
            else
                if (opt[0] == '2') {
                    this->print_doctors();
                }
                else
                    if (opt[0] == '3') {
                        this->add_patient();
                    }
                    else
                        if (opt[0] == '4') {
                            this->print_patients();
                        }
                        else
                            if (opt[0] == '5') {
                                this->print_sumarry_all_patients();
                            }
                            else
                                if (opt[0] == 'x') {
                                    ok = false;
                                }
                                else
                                    cout <<endl<< "Invalid option!"<<endl;
        }
        else
            cout << endl << "Invalid option!" << endl;
    } while (ok);
}