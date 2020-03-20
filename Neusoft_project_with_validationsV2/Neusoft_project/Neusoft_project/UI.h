#pragma once
#include "Service_doctor.h"
#include "Service_patient.h"
class UI {
private:
	Service_doctor service_doctor;
	Service_patient service_patient;
	void add_doctor();
	void read_person(char*, char*,int&,int,int,int,int);
	void print_doctors();
	void add_patient();
	void print_patients();
	void valid_id(int&);
	void valid_name(char*, int);
	void valid_age(int&,int,int);
	void valid_reason(char*);
	void print_sumarry_all_patients();
public:
	void run();
};