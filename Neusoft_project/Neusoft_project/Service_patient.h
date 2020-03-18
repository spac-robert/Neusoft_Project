#pragma once
#include "Repo.h"
#include "Patient.h"
class Service_patient {
private:
	Repo<Patient> repo;
public:
	Service_patient();
	~Service_patient();
	void service_add_patient(char*, char*, int,char*);
	int service_get_len_patients();
	Patient* service_get_all_patients();
};