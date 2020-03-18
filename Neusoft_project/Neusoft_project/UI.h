#pragma once
#include "Service_doctor.h"
#include "Service_patient.h"
class UI {
private:
	Service_doctor service_doctor;
	Service_patient service_patient;
	void ui_add_doctor();
	void ui_cin_person(char*, char*,int&,int,int,int,int);
	void ui_print_doctors();
	void ui_add_patient();
	void ui_print_patients();
	void valid_id(int&);
	void valid_name(char*, int);
	void valid_age(int&,int,int);
public:
	void run();
};