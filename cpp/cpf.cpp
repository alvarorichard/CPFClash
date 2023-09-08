#include "cpf.hpp"


cpf::cpf(){
  for (size_t i {}; i < 9; i++) {
    this -> m_numbs += std::to_string(std::rand() % 9 );
  }
  generate_first_digit();
  generate_second_digit();
}

void cpf::generate_first_digit(){
  int d1 {};
  for (size_t i {}, k {10}; i < m_numbs.size(); ++i, --k){
    d1 += std::stoi(m_numbs.substr(i, 1)) * k; 
  }

  (d1 % 11 < 2) ?
    this->m_numbs += "0" :
    this->m_numbs += std::to_string(11 - (d1 % 11));
}

void cpf::generate_second_digit(){
  int d2 {};
  for (size_t i {}, k {10}; i < m_numbs.size() - 1; ++i, --k){
    d2 += std::stoi(m_numbs.substr(i + 1, 1)) * k; 
  }

  (d2 % 11 < 2) ?
    this->m_numbs += "0" :
    this->m_numbs += std::to_string(11 - (d2 % 11));
}
void cpf::format_cpf(){
  m_numbs.insert(m_numbs.size() - 8, 1,'.');
    m_numbs.insert(m_numbs.size() - 5, 1,'.');
      m_numbs.insert(m_numbs.size() - 2, 1,'-');

}


bool cpf::check_cpf(std::string * cpf){
  // Limpa o CPF
  (*cpf).erase(std::remove((*cpf).begin(), (*cpf).end(), '.'), (*cpf).end());
  (*cpf).erase(std::remove((*cpf).begin(), (*cpf).end(), '-'), (*cpf).end());

  // Verificar se o CPF é somente números
  if(!std::all_of(cpf->begin(), cpf->end(), ::isdigit)){
    return false;
  }

  this->m_numbs = cpf->substr(0, 9);
  generate_first_digit();
  generate_second_digit();
  return this->m_numbs == *cpf;
}
