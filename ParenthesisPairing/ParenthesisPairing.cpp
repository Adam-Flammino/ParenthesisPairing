// ParenthesisPairing.cpp
// Adam Flammino SDEV-345 6/4
// Uses a stack to check whether parentheses in a string a paired correctly

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>

class ParenthesisChecker {
private:
	std::stack<char> parenthesis; // holds opening parentheses
	char next; // holds one char from input for checking
	char np; // holds one parenthesis from stack
	bool flag = true; // true if all parenthesis pair correctly, false if not
public:
	/*Adds character to stack if it is an opening parenthesis. If it is a closing parenthesis, checks top of stack to see if it matches.
	If it does match, it pops the opening parenthesis and continues. Otherwise it stops immediately and returns false*/
	bool checkParenthesis(std::string input) {
		for (int i = 0; i < input.length(); i++) {
			next = input.at(i);
			if (next == '{' || next == '[' || next == '(') {
				parenthesis.push(next);
			}
			else if (next == '}' || next == ']' || next == ')') {
				if (parenthesis.empty()) {
					flag = false;
					break;
				}
				np = parenthesis.top();
				parenthesis.pop();
				if (np == '(') {
					if (next != ')') {
						flag = false;
						break;
					}
				}
				else if (np == '[') {
					if (next != ']') {
						flag = false;
						break;
					}
				}
				else if (np == '{') {
					if (next != '}') {
						flag = false;
						break;
					}
				}
			}
		}
		if (!parenthesis.empty()) {
			flag = false;
		}
		return flag;
	}
};

int main()
{
	std::string input;
	bool flag; // true if all parentheses pair correctly, false if not
	
	std::cout << "Enter the string containing the parenthees you want match. (), [], and {} will all be checked." << std::endl;
	std::cin >> input;

	ParenthesisChecker check;

	flag = check.checkParenthesis(input);
	if (flag) {
		std::cout << "Congratulations! All parentheses are paired properly!" << std::endl;
	}
	else {
		std::cout << "At least one parenthesis is not paired properly" << std::endl;
	}

    return 0;
}

