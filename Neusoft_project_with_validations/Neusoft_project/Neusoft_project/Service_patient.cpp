#include "Service_patient.h"
Service_patient::Service_patient() {

}
Service_patient::~Service_patient() {

}
void Service_patient::service_add_patient(char* first_name, char* last_name, int age,char * reason) {
	Patient patient(first_name, last_name, age,reason);
	repo.add(patient);
}
Patient* Service_patient::service_get_all_patients() {
	return this->repo.get_all();
}
int Service_patient::service_get_len_patients() {
	return this->repo.get_len();
}