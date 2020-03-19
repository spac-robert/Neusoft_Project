#pragma once
#include "Person.h"
#include <ostream>
class Doctor :public Person{
private:
	int id;
public:

	//Constructors
	Doctor();
	Doctor(int, char*, char*, int);
	Doctor(const Doctor&);
	~Doctor();

	//Setters

	void set_id(int);
	

	//Getters

	int get_id();
	

	//Overwrite operetors '=' , '==' and '<<'

	Doctor& operator =(const Doctor&);
	bool operator==(const Doctor& );
	friend std::ostream& operator <<(std::ostream&, Doctor&);
};