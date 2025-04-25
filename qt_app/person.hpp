#ifndef PERSON_H
#define PERSON_H

#include <cstddef>

class Person_t
{
public:
	enum SEX{ MAN, WOMAN };
private:
	char* name;
	char* surname;
	char* middlename;
	size_t age;
	SEX sex;
public:
	Person_t(const char* _name = "", const char* _surname = "", const char* _middlename = "", size_t _age = 18, SEX _sex = MAN);
	virtual ~Person_t();

	void SetName(const char* _name);
	void SetSurname(const char* _name);
	void SetMiddlename(const char* _name);
	const char* GetName() const { return name; }
	const char* GetSername() const { return surname; }
	const char* GetMiddlename() const { return middlename; }
	void SetAge(int _age);
	size_t GetAge() const { return age; }
	void SetSex(int _sex);
	SEX GetSex() const { return sex; }
};

#endif // PERSON_H