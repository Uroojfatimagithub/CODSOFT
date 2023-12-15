#include <iostream>

int main() {
    char operation;
    double num1, num2;

    std::cout << "Simple Calculator\n";
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "Choose operation (+, -, *, /): ";
    std::cin >> operation;

    switch (operation) {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
            break;
        case '/':
            if (num2 != 0) {
                std::cout << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Error: Invalid operation\n";
    }

    return 0;
}
