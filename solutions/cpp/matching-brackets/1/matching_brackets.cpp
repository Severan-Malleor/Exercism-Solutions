#include "matching_brackets.h"
#include <stack>

namespace matching_brackets {

	/*
		When to use std::stackUse it whenever you need strict LIFO access
		Last-In, First-Out (LIFO)
	*/

	bool check(std::string str) {
		std::stack<char> stack;

		for (auto c : str) {
			switch (c) {
			case '[':
			case '{':
			case '(':
				stack.push(c);
				break;
			case ']':
				if (stack.empty() || stack.top() != '[') return false;
				stack.pop();
				break;
			case '}':
				if (stack.empty() || stack.top() != '{') return false;
				stack.pop();
				break;
			case ')':
				if (stack.empty() || stack.top() != '(') return false;
				stack.pop();
				break;
			}
		}

		return stack.empty();
	}

}  // namespace matching_brackets
