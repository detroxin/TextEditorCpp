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

  std::ifstream in(fileName);
  if (in.is_open()) {
    int row = 1;
    while (std::getline(in, line)) {
      mvprintw(row - 1, 0, (std::to_string(row) + ".").c_str());
      mvprintw(row - 1, 4, line.c_str());
      row++;
    }
  }
  in.close();

  //std::ofstream out(fileName, std::ios::app);
  //if (out.is_open()) {
  //  out << "Welcome to C++" << std::endl;
  //}
  //out.close();

  mvprintw(LINES - 1, 0, "Press any key to continue...");
  getch();
  endwin();
  return 0;
}