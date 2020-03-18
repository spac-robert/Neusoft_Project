#include "Person.h"
#include <cstring>

//Constructors

Person::Person() {
	this->age = 0;
	this->first_name = NULL;
	this->last_name = NULL;
}
Person::Person(const char* first_name, const char* last_name, int age) {
	this->first_name = new char[strlen(first_name) + 1];
	strcpy_s(this->first_name, 1 + strlen(first_name), first_name);
	this->last_name = new char[strlen(last_name) + 1];
	strcpy_s(this->last_name, 1 + strlen(last_name), last_name);
	this->age = age;
}
Person::Person(const Person& doctor) {
	this->first_name = new char[strlen(doctor.first_name) + 1];
	strcpy_s(this->first_name, 1 + strlen(doctor.first_name), doctor.first_name);
	this->last_name = new char[strlen(doctor.last_name) + 1];
	strcpy_s(this->last_name, 1 + strlen(doctor.last_name), doctor.last_name);
	this->age = doctor.age;
}
Person::~Person() {

}
//Setters


void Person::set_first_name(char* new_first_name) {
	this->first_name = new char[strlen(new_first_name) + 1];
	strcpy_s(this->first_name, 1 + strlen(new_first_name), new_first_name);
}
void Person::set_last_name(char* new_last_name) {
	this->last_name = new char[strlen(new_last_name) + 1];
	strcpy_s(this->last_name, 1 + strlen(new_last_name), new_last_name);
}
void Person::set_age(int new_age) {
	this->age = new_age;
}

//Getters


const char* Person::get_first_name() {
	return this->first_name;
}
const char* Person::get_last_name() {
	return this->last_name;
}
const int Person::get_age() {
	return this->age;
}

//Overwrite operators '=' , '==' and '<<'

Person& Person:: operator =(const Person& doctor) {
	this->set_first_name(doctor.first_name);
	this->set_last_name(doctor.last_name);
	this->set_age(doctor.age);
	return *this;
}
bool Person:: operator==(const Person& doc) {
	return strcmp(this->first_name, doc.first_name) == 0 && strcmp(this->last_name, doc.last_name) == 0 and this->age == doc.age;
}
std::ostream& operator <<(std::ostream& os, const Person& doctor) {
	os << "  First Name: " << doctor.first_name << " Last Name: " << doctor.last_name << " Age: " << doctor.age;
	return os;
}