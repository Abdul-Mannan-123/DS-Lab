#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class InfixToPrefix {
    char stack[100];
    int top;
public:
    InfixToPrefix() { top = -1; }

    int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    void reverse(char s[]) {
        int n = strlen(s);
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n - i - 1]);
    }

    void convert(char infix[], char prefix[]) {
        reverse(infix);
        int k = 0;
        for (int i = 0; infix[i]; i++) {
            char ch = infix[i];
            if (isdigit(ch)) prefix[k++] = ch;
            else if (ch == ')') stack[++top] = ch;
            else if (ch == '(') {
                while (top >= 0 && stack[top] != ')')
                    prefix[k++] = stack[top--];
                top--;
            } else {
                while (top >= 0 && prec(stack[top]) > prec(ch))
                    prefix[k++] = stack[top--];
                stack[++top] = ch;
            }
        }
        while (top >= 0) prefix[k++] = stack[top--];
        prefix[k] = '\0';
        reverse(prefix);
    }

    int evaluate(char prefix[]) {
        int s[100], t = -1;
        for (int i = strlen(prefix) - 1; i >= 0; i--) {
            char ch = prefix[i];
            if (isdigit(ch)) s[++t] = ch - '0';
            else {
                int a = s[t--];
                int b = s[t--];
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
    InfixToPrefix obj;
    char infix[100] = "3+5*2";
    char prefix[100];
    obj.convert(infix, prefix);
    cout << "Prefix: " << prefix << "\n";
    cout << "Result: " << obj.evaluate(prefix) << "\n";
}
