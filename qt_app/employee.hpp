#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.hpp"

class Employee_t : public Person_t
{
private:
	int experience;
	char* phoneNum;
public:
	Employee_t(const char* _name = "", const char* _surname= "", const char* _middlename = "", size_t _age = 18, SEX _sex = MAN, int _experience = 0, const char* _phoneNum = "8(800)222-35-35");
	virtual ~Employee_t();

	void SetPhoneNumber(const char* num);
	const char* GetPhoneNumber(const char* num) const { return phoneNum; }
	void SetExperience(int exper) { if(exper >= 0){ experience = exper; } }
	int GetExperience() const { return experience; }
};

#endif // EMPLOYEE_H