#pragma once
#include "Person.h"
#include <ostream>
class Patient :private Person{
private:
	char* reason;
public:

	//Constructors

	Patient();
	Patient(char*, char*, int,char*);
	Patient(const Patient&);
	~Patient();

	//Setters

	void set_reason(char*);

	//Getters

	char* get_reason();

	//Overwrite operetors '=' , '==' and '<<'

	Patient& operator =(const Patient&);
	bool operator==(const Patient& s);
	friend std::ostream& operator <<(std::ostream&, Patient&);
};