#pragma once

/* 
1021. Remove Outermost Parentheses
https://leetcode.com/problems/remove-outermost-parentheses/

A valid parentheses string is either empty (""), "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.  For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string S is primitive if it is nonempty, and there does not exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.

Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.



Example 1:

Input: "(()())(())"
Output: "()()()"
Explanation:
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: "(()())(())(()(()))"
Output: "()()()()(())"
Explanation:
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: "()()"
Output: ""
Explanation:
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".


Note:

S.length <= 10000
S[i] is "(" or ")"
S is a valid parentheses string
*/

#include <string>
#include <stack>

class Solution {
public:
	std::string removeOuterParentheses(std::string S) {
		std::string res;
		
		// 1.Use stack and std::string::substr
		// Time complexity:		O(N)
		// Space complexity:	O(1)
		std::stack<char> stk;
		bool primitive = false;
		int pos = 0;
		for (size_t i = 0; i < S.length(); ++i) {
			if (S[i] == '(') {
				primitive = !stk.empty();
				stk.push(S[i]);
			}
			else {
				stk.pop();
				if (stk.empty()) {
					if (primitive) {
						res += S.substr(pos + 1, i - pos - 1);
					}
					pos = i + 1;
				}
			}
		}

		// 2.Count open parentheses (primitive parenthes contain at least one '(')
		// Time complexity:		O(N)
		// Space complexity:	O(1)
		/*int opened = 0;
		for (char c : S) {
			if (c == '(' && opened++ > 0) res += c;
			if (c == ')' && opened-- > 1) res += c;
		}*/

		return res;
	}
};

/*
Tips:
*/