#include "Tests.h"
#include "Repo.h"
#include <cassert>

void test_repo_doctors() {

	char* first_name_doc1 = new char[10], * last_name_doc1 = new char[10];
	char* first_name_doc2 = new char[10], * last_name_doc2 = new char[10];
	char* first_name_doc3 = new char[10], * last_name_doc3 = new char[10];
	char* first_name_doc4 = new char[10], * last_name_doc4 = new char[10];

	strcpy_s(first_name_doc1, sizeof "Ion", "Ion");
	strcpy_s(last_name_doc1, sizeof "Dr", "Dr");
	Doctor doc1(1234, first_name_doc1, last_name_doc1, 44);

	strcpy_s(first_name_doc2, sizeof "Ana", "Ana");
	strcpy_s(last_name_doc2, sizeof "Dr", "Dr");
	Doctor doc2(2134, first_name_doc2, last_name_doc2, 65);

	strcpy_s(first_name_doc3, sizeof "Ale", "Ale");
	strcpy_s(last_name_doc3, sizeof "Dr", "Dr");
	Doctor doc3(3124, first_name_doc3, last_name_doc3, 50);

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

void test_repo_patients() {

	char* first_name_pat1 = new char[10], * last_name_pat1 = new char[10], * reason1 = new char[14];
	char* first_name_pat2 = new char[10], * last_name_pat2 = new char[10], * reason2 = new char[14];
	char* first_name_pat3 = new char[10], * last_name_pat3 = new char[10], * reason3 = new char[14];
	char* first_name_pat4 = new char[10], * last_name_pat4 = new char[10], * reason4 = new char[14];
	
	strcpy_s(reason1, sizeof "prescription", "prescription");
	strcpy_s(reason2, sizeof "treatment", "treatment");
	strcpy_s(reason3, sizeof "consultation", "consultation");
	strcpy_s(reason4, sizeof "treatment", "treatment");
	
	strcpy_s(first_name_pat1, sizeof "Ion", "Ion");
	strcpy_s(last_name_pat1, sizeof "Dr", "Dr");
	Patient pat1(first_name_pat1, last_name_pat1, 44,reason1);

	strcpy_s(first_name_pat2, sizeof "Ana", "Ana");
	strcpy_s(last_name_pat2, sizeof "Dr", "Dr");
	Patient pat2(first_name_pat2, last_name_pat2, 65,reason2);

	strcpy_s(first_name_pat3, sizeof "Ale", "Ale");
	strcpy_s(last_name_pat3, sizeof "Dr", "Dr");
	Patient pat3(first_name_pat3, last_name_pat3, 50,reason3);

	strcpy_s(first_name_pat4, sizeof "Lee", "Lee");
	strcpy_s(last_name_pat4, sizeof "Dr", "Dr");
	Patient pat4(first_name_pat4, last_name_pat4, 30,reason4);

	Repo<Patient> repo_pat;
	Patient patients[5];
	patients[0] = pat1;
	patients[1] = pat2;
	patients[2] = pat3;
	patients[3] = pat4;

	repo_pat.add(pat1);
	repo_pat.add(pat2);
	repo_pat.add(pat3);
	repo_pat.add(pat4);

	for (int i = 0; i < repo_pat.get_len(); i++) {
		assert(repo_pat.get_all()[i] == patients[i]);
	}
}

void tests() {
	
	test_repo_doctors();
	test_repo_patients();

}