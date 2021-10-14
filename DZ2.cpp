#include <iostream>
#include <string>
#include "stack"

char close(char open) {
    if (open == '{') {
        return '}';
    }
    if (open == '(') {
        return ')';
    }
    if (open == '[') {
        return ']';
    }
    return ' ';
}

int main() {
    std::string str;
    std::cin >> str;
    std::stack<char> A; // в стек помещаются закрывающие скобки
    for (uint i = 0; i < str.length(); ++i) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            A.push(close(str[i]));
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
            if (A.empty() || A.top() != str[i]) {
                std::cout << i;
                return 0;
            }
            A.pop();
        }
    }
    std::cout << (A.empty() ? "CORRECT" : std::to_string(str.length()));
    return 0;
}
