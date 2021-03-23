#include <iostream>
#include <vector>
#include <string>
#include <stack>  // to use STL stack
//  #include "stack.cpp" // to use honemade stack

using namespace std;

//*************************
// Task 1: Matching bracket
//*************************
bool match_bracket(string expression) 
{   
    stack<char> s; 
    char x; 
  
    // Traversing the Expression 
    for (int i = 0; i < expression.length(); i++)  
    { 
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')  
        { 
            // Push the element in the stack 
            cout << "Pushed " << expression[i] << " to stack." << endl;
            s.push(expression[i]); 
            cout << "Stack contains " << s.size() << endl;
            continue; 
        } 
  
        // IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point. 
        // if (s.empty()) return false; 
  
        switch (expression[i]) { 
        case ')': 
            cout << "')' detected." << endl;

            // Store the top element in a 
            x = s.top(); 
            s.pop(); 
            if (x == '{' || x == '[') 
            {
                cout << x << " mismatched ')'" << endl;
                return false; 
            }
            cout << "'(' matched." << endl;
            break; 
  
        case '}': 
            cout << "'}' detected." << endl;

            // Store the top element in b 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '[') 
            {
                cout << x << " mismatched '}'" << endl;
                return false; 
            }
            cout << "'{' matched." << endl;
            break; 
  
        case ']': 
            cout << "']' detected." << endl;

            // Store the top element in c 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '{') 
            {
                cout << x << " mismatched ']'" << endl;
                return false; 
            }
                cout << "'[' matched." << endl;
            break; 
        } 
    } 
  
    // Check Empty Stack 
    cout << "Stack is " << s.size()<< endl;
    return s.empty(); 
}


//******************
// Task 2: Token ADT
//******************
struct Token {
    // your code here

};

Token make_token(int i) {
    Token t;
    // your code here

    return t;
}

Token make_token(char op) {
    Token t;
    // your code here

    return t;
}

char get_optr(Token t) {
    // your code here

}

int get_opnd(Token t) {
    // your code here

}

bool is_opnd(Token t) {
    // your code here

}

//***************************************
// START OF Helper functions. Do not edit

// Function to tokenize a expression into vector of tokens
vector<Token> tokenize(string expression) {
    vector<Token> output;
    string i;
    for (char c : expression) {
        // if c is a digit
        if (isdigit(c)) {
            i += c;
        } else {
            if (!i.empty()) {
                output.push_back(make_token(stoi(i)));
                i.clear();
            }
            // convert brackets to round
            switch (c) {
                case '[':
                case '{':
                    c = '(';
                    break;
                case ']':
                case '}':
                    c = ')';
                    break;
            }
            output.push_back(make_token(c));
        }
    }
    if (!i.empty())
        output.push_back(make_token(stoi(i)));
    return output;
}


// This function maps the operator to an int
// so we can use the native comparison of int
// to compare the priority.
// You may use this function if you find it useful
int priority(Token t) {
    switch (get_optr(t)) {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        case '^':
            return 2;
    }
    return -1;
}

// Function to teach cout how to display vector of Token
ostream & operator << (ostream &out, const Token &t) {
    if (is_opnd(t))
        out << get_opnd(t);
    else
        out << get_optr(t);
    return out;
}

ostream & operator << (ostream &out, const vector<Token> &v)
{
    for (Token t : v)
        out << t << " ";
    return out;
}
// END OF helper functions
//*************************

//*************************
// Task 3: Infix to Postfix
//*************************
vector<Token> in_to_post(vector<Token> infix) {
    vector<Token> output;
    // your code here

    return output;
}


//*********************************
// Task 4: Calculate the expression
//*********************************
#include <math.h>
int calculate(vector<Token> postfix) {
    // replace with your code
    return 0;
}





// Main function for local testing
int main(void) {
    cout << boolalpha;  // tell cout to display bool as true/false

    // Task 1
    // cout << match_bracket("1+2*[3**(1-2)]-{1/4}") << endl;
    // cout << match_bracket("1 + 2 * [ 3 ** { 1 - 2) ] - { 1 / 4 }") << endl;
    // cout << match_bracket("1+(2*3)**4") << endl;
    // cout << match_bracket("(1+[2-3]*{9/2})") << endl;
    cout << match_bracket("(1+[2-3]*9/2})") << endl;

    // You may edit the expression for testing
    // Remember only non-negative integers are supported
    // string expression = "1+((2+3*4)/5)^6%7";

    // // Task 2
    // vector<Token> infix = tokenize(expression);
    // cout << "   Expr: " << expression << endl;
    // cout << "  Infix: " << infix << endl;

    // // Task 3
    // vector<Token> postfix = in_to_post(infix);
    // cout << "Postfix: " << postfix << endl;

    // // Task 4
    // cout << " Result: ";
    // cout << calculate(postfix) << endl;
} 