 #include <iostream>
#include <stack>
#include <string>
//for int to string conversion
#include <sstream> 
using namespace std;
//to check if the character is operator or not
bool isOp(char x) { 
switch (x) {
case '+':
case '-':
case '/':
case '*':
   return true;
}
return false;
}
// to evaluate the expression: perform operation based on exp
int eval(signed int operand1,signed int operand2,char exp) 
{
   int val;
   if(exp=='+')
       val=operand1+operand2;
   else if(exp=='-')
       val=operand1-operand2;
   else if(exp=='/')
       val=operand1/operand2;
   else if(exp=='*')
       val=operand1*operand2;
      
return val;
}

//prefix to infix function
string prefixToInfix(string prefix_str) {
    // stack used for infix expression generation
stack<string> infix_string; 
// stack used for prefix evaluation side by side
stack<int> prefix_integer; 

int len = prefix_str.size();

// read prefix expression from right to left
for (int i = len - 1; i >= 0; i--) {

   // check if the character is an operator
   if (isOp(prefix_str[i])) {
string op1,op2;
signed int operand1,operand2;
   // pop two operands from stack
   if(!infix_string.empty())
   {
  
       op1 = infix_string.top(); infix_string.pop(); // a character
       operand1=prefix_integer.top();prefix_integer.pop(); //a signed int
       if(!infix_string.empty())
       {
         
               op2 = infix_string.top(); infix_string.pop();  // a character
               operand2=prefix_integer.top();prefix_integer.pop(); //a signed int
       }  
       else
       {
      
           cout<<"Error"<<endl; // if stack is empty after popping op1/operand1, then it is not a valid prefix expression
           break;
       }
   }
   else
   {
   cout<<"Error"<<endl; // if stack is empty before popping op1/operand1, then it is not a valid prefix expression
   break;
   }  


   // group the operands and operator within brackets
   string temp_str = "(" + op1 + prefix_str[i] + op2 + ")";

  // evaluate the operands using the operator specified by prefix_str[i]
   signed int val=eval(operand1,operand2,prefix_str[i]); 

   // Push string temp_str back to stack
   infix_string.push(temp_str);
   prefix_integer.push(val);
   }

   // if character is an operand
   else {

   // push the operand to the stack
   infix_string.push(string(1, prefix_str[i])); // push operator into stack of type string
   prefix_integer.push(prefix_str[i]-'0'); // push operator into integer stack after converting
   }
}

// final Stack contains the Infix expression
if(infix_string.size()>1)
{
cout<<"Error"; // if the stack contains more than 1 element then it is invalid prefix expression
exit(0); // use exit and not break as it is not within a loop
}
else
{
ostringstream o;
o <<prefix_integer.top(); // prefix_integer.top contains the evaluated result
string res=infix_string.top()+"="+o.str(); // converting integer value to string
return res;
}
}


int main() {
string prefix_str;
cout<<"enter a prefix expression:"<<endl;
cin>>prefix_str;
cout << prefixToInfix(prefix_str);
return 0;
}