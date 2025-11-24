#include <bits/stdc++.h>
using namespace std;


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


string prefixToInfix(string prefix) {
    stack<string> st;
    int n = prefix.size();
    
    
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];
        
        
        if (isalnum(c)) {
            string op(1, c);
            st.push(op);
        }
        
        else if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = "(" + op1 + string(1, c) + op2 + ")";
            st.push(expr);
        }
    }
    return st.top();
}


int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else { // operator
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}


int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

int evaluatePostfix(string postfix) {
    stack<int> st;
    
    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0'); 
        }
        else if (isOperator(c)) {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int res = applyOp(val1, val2, c);
            st.push(res);
        }
    }
    return st.top();
}


int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    
    string infix = prefixToInfix(prefix);
    cout << "Infix Expression: " << infix << endl;

    
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    
    int result = evaluatePostfix(postfix);
    cout << "Postfix Evaluation Result: " << result << endl;

    return 0;
}
