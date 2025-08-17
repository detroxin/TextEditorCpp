#include <iostream>
#include <fstream>
#include <string>
#include <ncurses/ncurses.h>

int main() {
  initscr(); 
  cbreak();
  noecho();

  std::string line;
  std::string fileName("text.txt");

  printw("My terminal supports %d colors.\n", COLORS);

  std::ifstream in(fileName);
  if (in.is_open()) {
    int row = 1;
    while (std::getline(in, line)) {
      printw((std::to_string(row) + ".").c_str()); // Выводим номер строки с точкой
      printw(" "); // Добавляем пробел после номера строки
      printw(line.c_str()); // Выводим строку
      printw("\n"); // Переходим на новую строку
      row++;
    }
  }
  in.close();

  //std::ofstream out(fileName, std::ios::app);
  //if (out.is_open()) {
  //  out << "Welcome to C++" << std::endl;
  //}
  //out.close();

  printw("\n\nPress any key to continue...\n");
  getch();
  endwin();
  return 0;
}