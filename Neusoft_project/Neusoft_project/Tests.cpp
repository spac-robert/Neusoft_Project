#include "Tests.h"
#include "Repo.h"
#include <cassert>
void test_repo_doctor() {
	char* first_name_doc1 = new char[10], * last_name_doc1 = new char[10];
	char* first_name_doc2 = new char[10], * last_name_doc2 = new char[10];
	char* first_name_doc3 = new char[10], * last_name_doc3 = new char[10];
	char* first_name_doc4 = new char[10], * last_name_doc4 = new char[10];

	strcpy_s(first_name_doc1, sizeof "Ion", "Ion");
	strcpy_s(last_name_doc1, sizeof "Dr", "Dr");
	Doctor doc1(1234, first_name_doc1, last_name_doc1,44);
	strcpy_s(first_name_doc2, sizeof "Ana", "Ana");
	strcpy_s(last_name_doc2, sizeof "Dr", "Dr");
	Doctor doc2(2134, first_name_doc2, last_name_doc2, 65);
	strcpy_s(first_name_doc3, sizeof "Ale", "Ale");
	strcpy_s(last_name_doc3, sizeof "Dr", "Dr");
	Doctor doc3(3124, first_name_doc3, last_name_doc3,50);
	strcpy_s(first_name_doc4, sizeof "Lee", "Lee");
	strcpy_s(last_name_doc4, sizeof "Dr", "Dr");
	Doctor doc4(3412, first_name_doc4, last_name_doc4, 30);

	Repo<Doctor> repo_doc;
	Doctor docs[5];
	docs[0] = doc1;
	docs[1] = doc2;
	docs[2] = doc3;
	docs[3] = doc4;

	repo_doc.add(doc1);
	repo_doc.add(doc2);
	repo_doc.add(doc3);
	repo_doc.add(doc4);

	for (int i = 0; i < repo_doc.get_len(); i++) {
		assert(repo_doc.get_all()[i] == docs[i]);
	}

}