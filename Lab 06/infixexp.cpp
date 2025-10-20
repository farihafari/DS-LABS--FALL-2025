#include <iostream>
#include <stack>
#include <string>
using namespace std;
int Precedence(char c){
	if(c == '^'){
		return 3;
	}else if (c == '*' || c=='/'){
		return 2;
	}else if (c== '+' || c=='-'){
		return 1;
	}else{
		return -1;
	}
}
string InfixToPostFix(string infix){ //input string
	string postfix =""; //output string
	stack<char> s;  //stack
	for(int i=0;i<infix.length();i++){
		char c = infix[i]; 
		if(isalnum(c)){ // If the scanned character or num is an operand, add it to  output string.
        		postfix +=c;
			
		}else if( c== '('){
			s.push(c);
		}else if(c == ')'){
			while(!s.empty() && s.top() != '('){
				char op = s.top();
				postfix +=op;
				s.pop();
			}
			 if (!s.empty() &&s.top()=='('){
				s.pop();
			}
		}else{
			while(!s.empty() && Precedence(c) <= Precedence(s.top())){
				char op = s.top();
				postfix = op;
				s.pop();
			}
			s.push(c);
		}
	}
	while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

//infix to prefix
bool isOperator(char c){ //check if a character is an operator
	return (c== '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
string InfixToPreFix(string infix) {
    string prefix = "";
    stack<char> s;

    // Scan from right to left
    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];

        if (isalnum(c)) {
            // Operand directly added to result (in front)
            prefix = c + prefix;
        } 
        else if (c == ')') {
            s.push(c);
        } 
        else if (c == '(') {
            while (!s.empty() && s.top() != ')') {
                char op = s.top();
                s.pop();
                prefix = op + prefix;
            }
            if (!s.empty()) s.pop(); // pop ')'
        } 
        else if (isOperator(c)) {
            while (!s.empty() && isOperator(s.top()) &&
                   (Precedence(s.top()) > Precedence(c) ||
                   (Precedence(s.top()) == Precedence(c) && c != '^'))) {
                char op = s.top();
                s.pop();
                prefix = op + prefix;
            }
            s.push(c);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        char op = s.top();
        s.pop();
        prefix = op + prefix;
    }

    return prefix;
}
int main()
{
    string infix = "A+B*C";
  cout << "Infix Expression: " << infix << endl;
      cout << "Postfix Expression: " << InfixToPostFix(infix)
         << endl;
         
          string preinfix = "A+B*C";
    cout << "Infix Expression: " << preinfix << endl;
    cout << "Prefix Expression: " << InfixToPreFix(preinfix) << endl;
    return 0;
}
