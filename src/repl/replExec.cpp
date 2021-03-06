//
// Created by giordi on 23/09/17.
//
#include "jit.h"
#include "repl.h"
#include <codegen.h>
#include <iostream>
#include <string>

using babycpp::codegen::Codegenerator;
int main() {
  std::cout << "Babycpp v 0.0.1 ... not my fault if it crash" << std::endl;
  // creating the code generator
  Codegenerator gen;
  babycpp::jit::BabycppJIT jit;

  auto anonymousModule =
      std::make_shared<llvm::Module>("anonymous", gen.context);
  auto staticModule =
      std::make_shared<llvm::Module>("static", gen.context);


  babycpp::repl::loop(&gen, &jit, anonymousModule, staticModule);
  //babycpp::repl::loop(&gen, &jit, nullptr, nullptr);

  return 0;
}
