#pragma once
#include "Repo.h"
class Service_doctor {
private:
	Repo<Doctor> repo;
public:
	Service_doctor();
	~Service_doctor();
	void service_add_doctor(int,char*, char*, int);
	int service_get_len_doctors();
	Doctor* service_get_all_doctors();
	bool id_is_unic(int);
};