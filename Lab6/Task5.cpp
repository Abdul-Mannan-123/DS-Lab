#include <iostream>
#include <cctype>
using namespace std;

class InfixToPostfix {
    char stack[100];
    int top;
public:
    InfixToPostfix() { top = -1; }

    int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    void convert(char infix[], char postfix[]) {
        int k = 0;
        for (int i = 0; infix[i]; i++) {
            char ch = infix[i];
            if (isdigit(ch)) postfix[k++] = ch;
            else if (ch == '(') stack[++top] = ch;
            else if (ch == ')') {
                while (top >= 0 && stack[top] != '(')
                    postfix[k++] = stack[top--];
                top--;
            } else {
                while (top >= 0 && prec(stack[top]) >= prec(ch))
                    postfix[k++] = stack[top--];
                stack[++top] = ch;
            }
        }
        while (top >= 0) postfix[k++] = stack[top--];
        postfix[k] = '\0';
    }

    int evaluate(char postfix[]) {
        int s[100], t = -1;
        for (int i = 0; postfix[i]; i++) {
            char ch = postfix[i];
            if (isdigit(ch)) s[++t] = ch - '0';
            else {
                int b = s[t--];
                int a = s[t--];
                switch (ch) {
                    case '+': s[++t] = a + b; break;
                    case '-': s[++t] = a - b; break;
                    case '*': s[++t] = a * b; break;
                    case '/': s[++t] = a / b; break;
                }
            }
        }
        return s[t];
    }
};

int main() {
    InfixToPostfix obj;
    char infix[100] = "3+5*2";
    char postfix[100];
    obj.convert(infix, postfix);
    cout << "Postfix: " << postfix << "\n";
    cout << "Result: " << obj.evaluate(postfix) << "\n";
}
