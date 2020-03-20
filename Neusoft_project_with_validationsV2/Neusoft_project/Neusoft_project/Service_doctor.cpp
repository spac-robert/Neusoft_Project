#include "Service_doctor.h"
#include <fstream>
using namespace std;
Service_doctor::Service_doctor() {

}

Service_doctor::~Service_doctor() {

}

void Service_doctor::service_add_doctor(int id, char* first_name, char* last_name, int age) {

	Doctor doc(id, first_name, last_name, age);
	repo.add(doc);
}

Doctor* Service_doctor::service_get_all_doctors() {

	return this->repo.get_all();
}

int Service_doctor::service_get_len_doctors() {

	return this->repo.get_len();
}

bool Service_doctor::id_is_unique(int id) {

	int len_doctors = this->service_get_len_doctors();
	bool number =true;
	for (int i = 0; i < len_doctors; i++) {
		if (id == this->service_get_all_doctors()[i].get_id())
			number=false;
	}

	char x;
	int numb = 0;
	bool ok = false;
	fstream file_doctor;
	file_doctor.open("Doctors.txt", ios::out | ios::in | ios::app);
	if (file_doctor.is_open()==true) {
		while (!ok) {
			file_doctor >> x;
			if (x <= '9' and x >= '0') {
				numb = numb * 10 + (x - '0');
			}
			if (numb >= 1000 and numb <= 9999) {
				ok = true;
			}
		}
	}
	file_doctor.close();
	if (id == numb)
		numb = false;
	return numb;

}