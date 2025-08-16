#include <iostream>
#include <cstdlib> // Для getenv

int main() {
    const char* path = std::getenv("PATH");
    if (path != nullptr) {
        std::cout << "PATH: " << path << std::endl;
    } else {
        std::cout << "PATH environment variable not found." << std::endl;
    }
    std::cout << "Hello, world!" << std::endl;

    // Добавляем паузу, чтобы консоль не закрывалась сразу
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get(); // Ждем ввода символа

    return 0;
}