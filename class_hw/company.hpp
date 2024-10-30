#pragma once
#include <vector>
#include "emp.hpp"
class company
{
public:
	// fields: emp that gets it information from emp.hpp
	std::vector<Emp> emplist;

	// methods; functions for compnay use
	void addEmp();
	void showEmp();
	void highest();
	void avg();
	void findid();
};
