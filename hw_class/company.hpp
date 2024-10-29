#pragma once
#include <vector>
#include "emp.hpp"
class compnay
{
public:
	std::vector emp;
void addEmp(std::vector<Emp>& emplist);
void showEmp(std::vector<Emp>& emplist);
void highest(std::vector<Emp>& emplist);
void avg(std::vector<Emp>& emplist);
void findid(std::vector<Emp>& emplist);
}
