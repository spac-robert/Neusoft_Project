#include "Doctor.h"
#include <cstring>

//Constructors
Doctor::Doctor() {
	this->id = 0;
}
Doctor::Doctor(int id,char* first_name,  char* last_name, int age):Person(first_name,last_name,age) {
	this->id = id;
}
Doctor::Doctor(const Doctor& doctor):Person(doctor) {
	this->id = doctor.id;
}
Doctor::~Doctor() {

}
//Setters

void Doctor::set_id(int new_id) {
	this->id = new_id;
}


//Getters

int Doctor::get_id() {
	return this->id;
}

//Overwrite operators '=' , '==' and '<<'

Doctor& Doctor:: operator =(const Doctor& doctor) {
	this->set_id(doctor.id);
	Person::operator = (doctor);
	return *this;
}

bool Doctor:: operator==(const Doctor& doc) {
	Person::operator == (doc);
	return strcmp(this->first_name, doc.first_name) == 0 && strcmp(this->last_name, doc.last_name) == 0  and this->id == doc.id and this->age == doc.age;
}

std::ostream& operator <<(std::ostream& os, Doctor& doctor) {
	os << "Identificator: " << doctor.id << "  First Name: " << doctor.get_first_name() << " Last Name: " << doctor.get_last_name() << " Age: " << doctor.get_age()<<std::endl;
	return os;
}