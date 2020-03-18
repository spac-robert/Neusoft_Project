#include "Patient.h"
#include <cstring>

//Constructors

Patient::Patient() {

	this->reason = NULL;
}
Patient::Patient(char* first_name, char* last_name, int age,char* reason):Person(first_name,last_name,age) {
	this->reason = new char[strlen(reason)+1];
	strcpy_s(this->reason, 1 + strlen(reason), reason);
}
Patient::Patient(const Patient& doctor):Person(doctor) {
	this->reason = new char[strlen(doctor.reason) + 1];
	strcpy_s(this->reason, 1 + strlen(doctor.reason), doctor.reason);
}
Patient::~Patient() {
	if (this->reason)
	{
		delete[] reason;
		this->reason = NULL;
	}
}
//Setters

void Patient::set_reason(char* new_reason) {

	this->reason = new char[strlen(new_reason)+1];
	strcpy_s(this->reason, 1 + strlen(new_reason), new_reason);
}

//Getters


char* Patient::get_reason() {
	return this->reason;
}


//Overwrite operators '=' , '==' and '<<'

Patient& Patient:: operator =(const Patient& patient) {
	this->set_reason(patient.reason);
	Person::operator=(patient);
	return *this;
}

bool Patient:: operator==(const Patient& patient) {
	return strcmp(this->first_name, patient.first_name) == 0 && strcmp(this->last_name, patient.last_name) == 0 and this->age == patient.age and strcmp(this->reason, patient.reason);
}

std::ostream& operator <<(std::ostream& os,Patient& patient) {
	os << "First Name: " << patient.get_first_name() << " Last Name: " << patient.get_last_name() << " Age: " << patient.get_age() << " Reason: " << patient.reason <<std::endl;
	return os;
}