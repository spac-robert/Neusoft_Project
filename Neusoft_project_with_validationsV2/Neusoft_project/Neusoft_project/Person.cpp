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
Person::Person(const Person& person) {
	this->first_name = new char[strlen(person.first_name) + 1];
	strcpy_s(this->first_name, 1 + strlen(person.first_name), person.first_name);
	this->last_name = new char[strlen(person.last_name) + 1];
	strcpy_s(this->last_name, 1 + strlen(person.last_name), person.last_name);
	this->age = person.age;
}
Person::~Person() {
	/*if (this->first_name){
		delete[] first_name;
		first_name = NULL;
		delete[] last_name;
		last_name = NULL;
	}*/
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

Person& Person:: operator =(const Person& person) {
	this->set_first_name(person.first_name);
	this->set_last_name(person.last_name);
	this->set_age(person.age);
	return *this;
}
bool Person:: operator==(const Person& person) {
	return strcmp(this->first_name, person.first_name) == 0 && strcmp(this->last_name, person.last_name) == 0 and this->age == person.age;
}
std::ostream& operator <<(std::ostream& os, const Person& person) {
	os << "  First Name: " << person.first_name << " Last Name: " << person.last_name << " Age: " << person.age;
	return os;
}