#pragma once

#include <iostream>
#include <memory>
#include <ctime>
#include <algorithm>
#include <string>

class cpf {
public:
  cpf();
  std::string m_numbs;
  void generate_first_digit();
  void generate_second_digit();
  void format_cpf();
  bool check_cpf(std::string * cpf);

};


