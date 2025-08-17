#include <iostream>
#include <fstream>
#include <string>
#include <ncurses/ncurses.h> // Подключаем заголовочный файл ncurses

int main() {
  initscr();        // Инициализация ncurses
  cbreak();         // Отключаем буферизацию ввода (сразу отправляем символы)
  noecho();         // Отключаем отображение вводимых символов

  std::string line;
  std::string fileName("text.txt");

  std::ifstream in(fileName);
  if (in.is_open()) {
    int row = 0;
    while (std::getline(in, line)) {
      mvprintw(row, 0, line.c_str()); // Выводим строку в координатах (row, 0)
      row++;
    }
  }
  in.close();

  std::ofstream out(fileName, std::ios::app);
  if (out.is_open()) {
    out << "Welcome to C++" << std::endl;
  }
  out.close();

  mvprintw(LINES - 1, 0, "Press any key to continue..."); // Выводим сообщение внизу экрана
  getch();         // Ожидаем нажатия клавиши
  endwin();         // Завершаем работу с ncurses
  return 0;
}