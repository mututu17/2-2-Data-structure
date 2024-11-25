#include<iostream>
#include<sstream>
#include<stack>
#include<cctype>
#include<algorithm>
using namespace std;
const string OPERATORS = "+-*/()";
const int PRECEDENCE[] = { 1,1,2,2,-1,-1 };
stack<char> operator_stack;
stack<double> operand_stack; //피연산자들을 저장할 스택

string::size_type is_operator(char ch) {
	return OPERATORS.find(ch);
}

int precedence(char op) {
	return PRECEDENCE[is_operator(op)];
}

double eval_op(char op) {
	if (operand_stack.empty()) {
		throw runtime_error("Syntax Error: Stack empty in eval_op.");
	}
	double rhs = operand_stack.top();
	operand_stack.pop();
	if (operand_stack.empty()) {
		throw runtime_error("Syntax Error: Stack empty in eval_op.");
	}
	double lhs = operand_stack.top();
	operand_stack.pop();
	double result = 0;
	switch (op) {
	case '+': result = lhs + rhs; break;
	case '-': result = lhs - rhs; break;
	case '*': result = lhs * rhs; break;
	case '/':
		if (rhs == 0) {
			throw runtime_error("Division by zero."); //0으로 나누는 경우 예외처리
		}
		result = lhs / rhs;
		break;
	}
	return result;
}

void process_op(char op) {
	if (operator_stack.empty() || op == '(') { //여는 괄호는 그냥 스택에 push 한다.
		operator_stack.push(op);
	}
	else {
		char top_op = operator_stack.top();
		if (precedence(op) > precedence(top_op)) {
			operator_stack.push(op);
		}
		else {
			while (!operator_stack.empty() && precedence(op) <= precedence(top_op)) //op보다 우선순위가 높은 연산자 연산수행
			{
				operator_stack.pop(); 
				if (top_op == '(') //op의 우선순위가 top_op보다 낮거나 같은데
					//top_op가 여는 괄호이면 op는 닫는 괄호라는 의미
					break;
				double result = eval_op(top_op); //top_op로 연산 수행
				operand_stack.push(result);
				if (!operator_stack.empty())
					top_op = operator_stack.top();
				else
					break;
			}
			if (op != ')') //닫는 괄호는 스택에 push하지 않는다.
				operator_stack.push(op);
		}
	}
}
double convertAndEval(string infix) {
	stringstream postfix, infixstream(infix);
	string token;
	infix.erase(remove(infix.begin(), infix.end(), ' '), infix.end()); //모든 공백을 제거하고 시작

	bool expecting_operand = true; //이전에 연산자가 있는 경우
	int i = 0;
	while (i < infix.length()) { //연산자 단위로 쪼개서 연산자가 아닌 것을 숫자로 처리함
		char ch = infix[i];
		if (is_operator(ch) != string::npos) {
			// 연산자일 경우
			if (ch == '-' && expecting_operand && (i + 1 < infix.length()) && isdigit(infix[i + 1])) { //뒤에 오는게 숫자인지까지 봐야함
				// 음수 처리
				string number = "-";
				i++;
				while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
					number += infix[i++]; //숫자라면 음수로 읽는 중
				}
				operand_stack.push(stod(number));
				expecting_operand = false;
				continue;
			}
			else {
				// 일반 연산자 처리
				process_op(ch);
				expecting_operand = true; //연산자 다음에 -는 음수
			}
		}
		else {
			// 숫자 처리
			string number;
			while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
				number += infix[i++];
			}
			operand_stack.push(stod(number));
			expecting_operand = false;
			continue;
		}
		i++;
	}

	while (!operator_stack.empty()) { //우선 순위가 낮은 연산자들만 모였기 때문에 순서대로 연산하면 된다.
		char op = operator_stack.top();
		if (op == '(') //스택에 여는 괄호가 남아있어서는 안된다.
			throw runtime_error("Unmatched parenthesis.");
		double result = eval_op(op); //연산 수행
		operand_stack.push(result);
		operator_stack.pop();
	}

	double answer = operand_stack.top(); //스택에 남아있는 연산결과 반환
	operand_stack.pop();
	if (operand_stack.empty())
		return answer;
	else {
		throw runtime_error("Syntax Error: Stack should be empty.");
	}
}
int main()
{
	string expr;
	cout << "Enter an infix expression: ";
	getline(cin, expr);
	cout << convertAndEval(expr) << endl;
	return 0;
}