#define _CRT_SECURE_NO_WARNINGS
#include "employee.hpp"
#include <string.h>

Employee_t::Employee_t(const char* _name, const char* _surname, const char* _middlename, size_t _age, SEX _sex, int _experience, const char* _phoneNum) 
	: Person_t(_name, _surname, _middlename, _age, _sex), experience(_experience)
{
	phoneNum = new char[strlen(_phoneNum) + 1];
	strcpy(phoneNum, _phoneNum);
}

Employee_t::~Employee_t()
{
	delete[] phoneNum;
}