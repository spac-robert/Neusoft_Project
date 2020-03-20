#pragma once
#include <ostream>
class Person {
protected:
	char* first_name;
	char* last_name;
	int age;
public:

	//Constructors
	Person();
	Person(const char*, const char*, int);
	Person(const Person&);
	~Person();

	//Setters

	void set_first_name(char*);
	void set_last_name(char*);
	void set_age(int);

	//Getters

	const char* get_first_name();
	const char* get_last_name();
	const int get_age();

	//Overwrite operators '=' , '==' and '<<'

	Person& operator =(const Person&);
	bool operator==(const Person& s);
	friend std::ostream& operator <<(std::ostream&, const Person&);
};