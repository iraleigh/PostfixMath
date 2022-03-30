#include <iostream>
#include <string>
#include <stack>

using namespace std;

  // *********************************
  // help with iterating over a string
  // *********************************
  // string word = "hello";

  // for (char c : word) {
  //   cout << c;
  // }

  // cout << endl;

  // for (int i = 0; i < word.size(); i++) {
  //   cout << word[i];
  // }
  // *********************************

  // ********************************
  // help with converting char to int
  // ********************************
  // char a = '4';
  // int four = a - '0'; // ascii
  // ********************************

bool isOperator(char c) {
  return (c == '+') || (c == '-');
}

int operate(int a, int b, char op) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
  }
  return 0;
}

// prints the output of the 
// postfix expression. The expression
// will only have + and - some digits
// in the form of 22+ 
void compute(string s) {
  stack<int> digits; // 1

  // 22-1+
  for (char c : s) {
    if (isOperator(c)) {
      int b = digits.top(); // 1
      digits.pop();

      int a = digits.top(); // 0
      digits.pop();

      digits.push(operate(a, b, c));
    } else {
      digits.push(c - '0'); 
    }
  }

  cout << digits.top() << endl;
}



int main() {
  // 2 + 2 -> infix
  // operand operator operand
  // 22+ -> postfix
  // operand operand operator 
  compute("22-1+");
  // 22-
  // 0
  // 01+
  // 1
  
  // Rather than computing
  // we could covert this into assembly
  // following the same algorithm, with some
  // extra steps
  
  // load 2, r1 # load 2 into register 1
  // sub  2, r1 # subtract 2 and r1 load result r1
  // str  c, r1 # store register into c
  // load c, r1 
  // add  1, r1
  // str  c, r1
}