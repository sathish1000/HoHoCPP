#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
			opening_brackets_stack.push(Bracket(next,position));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
			if (!opening_brackets_stack.empty())
			{
				Bracket popValue = opening_brackets_stack.top();
				if (!popValue.Matchc(next))
				{
					std::cout << position+1 << std::endl;
					return 0;
				}
				else
				{
					opening_brackets_stack.pop();
				}
			}
			else
			{
				std::cout << position+1 << std::endl;
				return 0;				
			}
        }
    }

    // Printing answer, write your code here
	if (opening_brackets_stack.empty()) 
	{
		std::cout << "Success" << std::endl;
	}
	else
	{
		Bracket popValue = opening_brackets_stack.top();
		std::cout << popValue.position+1 << std::endl;		
	}	

    return 0;
}
