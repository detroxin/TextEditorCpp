#include <iostream>
#include <fstream>
#include <string>
#include <ncurses/ncurses.h>

int main() {
  initscr();

  if (has_colors()) {
    start_color();

    short color_cream = 10;
    init_color(color_cream,
              255 * 0.95, 255 * 0.9,
              255 * 0.8);

    init_pair(1, color_cream, COLOR_BLACK);

    bkgd(COLOR_PAIR(1));
    attron(COLOR_PAIR(1));
  }
  else {
    printw("Your terminal does not support colors.\n");
  }

  cbreak();
  noecho();

  std::string line;
  std::string fileName("text.txt");

  printw("My terminal supports %d colors.\n", COLORS);

  std::ifstream in(fileName);
  if (in.is_open()) {
    int row = 1;
    while (std::getline(in, line)) {
      printw((std::to_string(row) + ".").c_str());
      printw(" ");
      printw(line.c_str());
      printw("\n");
      row++;
    }
  }
  in.close();

  // std::ofstream out(fileName, std::ios::app);
  // if (out.is_open()) {
  //  out << "Welcome to C++" << std::endl;
  // }
  // out.close();

  printw("\n\nPress any key to continue...\n");
  attroff(COLOR_PAIR(1));
  getch();
  endwin();
  return 0;
}