#include <iostream>
#include <stack>
#include <string>

void generateBracketSequences(int n, int open, int close, std::string sequence) {
    if (sequence.length() == 2 * n) {
        std::cout << sequence << std::endl;
        return;
    }
    if (open < n) {
        generateBracketSequences(n, open + 1, close, sequence + "(");
    }
    if (close < open) {
        generateBracketSequences(n, open, close + 1, sequence + ")");
    }
    if (open > close) {
        generateBracketSequences(n, open, close + 1, sequence + "]");
    }
}

int main() {
    int n;
    std::cin >> n;

    if (n > 0 && n % 2 == 0) {
        generateBracketSequences(n / 2, 0, 0, "");
    }

    return 0;
}
