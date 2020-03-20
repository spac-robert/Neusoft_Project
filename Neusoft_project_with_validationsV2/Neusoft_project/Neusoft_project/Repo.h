#pragma once
#include "Doctor.h"
#include "Patient.h"

template <typename T>

//Generic Repo for Doctors and Patients

class Repo {
private:
	T array[1001];
	int len;
public:
	Repo();
	~Repo();
	void add(T object);
	T* get_all();
	int get_len();
};

template <typename T>

void Repo<T>::add(T object) {
	this->array[this->len++] = object;
}
template <typename T>

int Repo<T>::get_len() {
	return this->len;
}
template <typename T>

T* Repo<T>::get_all() {
	return this->array;
}
template <typename T>

Repo<T>::Repo() {
	this->len = 0;
}
template <typename T>

Repo<T>::~Repo() {
	this->len = 0;
}