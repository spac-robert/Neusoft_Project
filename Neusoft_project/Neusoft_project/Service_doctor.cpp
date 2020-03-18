#include "Service_doctor.h"
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
bool Service_doctor::id_is_unic(int id) {
	for (int i = 0; i < this->service_get_len_doctors(); i++) {
		if (id == this->service_get_all_doctors()[i].get_id())
			return false;
	}
	return true;
}