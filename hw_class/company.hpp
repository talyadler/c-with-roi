#pragma once
#include <vector>
#include "emp.hpp"
class compnay
{
public:
	// fields: emp that gets it information from emp.hpp
	std::vector<Emp> emplist;

	// methods
	void addEmp();
	void showEmp();
	void highest();
	void avg();
	void findid();
};
