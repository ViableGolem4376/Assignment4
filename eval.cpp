#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <locale>
#include <cmath>

int main(int argc, char *argv[]) {

  std::locale loc;

  std::string eq = argv[1];
  std::istringstream myss(eq);

  std::string op;
  std::stack<std::string> stack;
  float a, b, c;

  char operands[] = {'^', '*', '/', '+', '-'};

  while( myss >> op) {

    //if (!stack.empty()){
   //     std::cout << stack.top() << std::endl;
   // }

    if (isdigit(op[0], loc) || isdigit(op[1], loc)) {
      stack.push(op);
    }
    else if (op[0]== operands[0]){
      b = std::stoi(stack.top());
      stack.pop();
      a = std::stoi(stack.top());
      stack.pop();
      c = pow(a,b);
      stack.push(std::to_string(c));

    } else if (op[0]== operands[1]){
      b = std::stoi(stack.top());
      stack.pop();
      a = std::stoi(stack.top());
      stack.pop();
      c = a * b;
      stack.push(std::to_string(c));

    } else if (op[0]== operands[2]){
      b = std::stoi(stack.top());
      stack.pop();
      a = std::stoi(stack.top());
      stack.pop();
      c = a / b;
      stack.push(std::to_string(c));

    } else if (op[0]== operands[3]){
      b = std::stoi(stack.top());
      stack.pop();
      a = std::stoi(stack.top());
      stack.pop();
      c = a + b;
      stack.push(std::to_string(c));

    } else if (op[0]== operands[4]){
      b = std::stoi(stack.top());
      stack.pop();
      a = std::stoi(stack.top());
      stack.pop();
      c = a - b;
      stack.push(std::to_string(c));
    }
  }
  std::cout << ceil(std::stof(stack.top())) << std::endl;
  stack.pop();

}
