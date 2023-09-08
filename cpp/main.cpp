#include <iostream>
#include <ctime> 
#include "cpf.hpp" 
#include <memory>
#include <string>


int main(int argc, char** argv) {


    std::srand(std::time(0)); 
    auto c = std::make_unique<cpf>(); 
    
  if (argc > 1)
  {
    std::string args = argv[1];
    if (args == "--format")
    {
      c->format_cpf();
      std::cout << c->m_numbs << std::endl; 
     
    }else if (args == "--check")
    {
      std::string cpf = argv[2];
      if (c->check_cpf(&cpf))
      {
        std::cout << "Valid CPF" << std::endl; 
      }else{
        std::cout << "Invalid CPF" << std::endl; 
      }

    }else{
      std::cout << "Invalid argument" << std::endl; 
      return EXIT_FAILURE;
    }
    
  }else{
     std::cout << c->m_numbs << std::endl; 
  }
  
   
    
    return 0;
}
