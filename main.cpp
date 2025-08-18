#include <iostream>
#include <fstream>
#include <string>
#include <ncurses/ncurses.h>

int main() {
  initscr();
  cbreak();

  std::string line;
  char fileNameBuffer[256];

  printw("Enter the file name: ");
  getstr(fileNameBuffer);

  std::string fileName(fileNameBuffer);

  printw("FileName: ");
  printw(fileName.c_str());
  printw("\n");
  refresh();

  fileName = "TextFiles/" + fileName;

  std::ifstream in(fileName);
  if (in.is_open()) {
    int row = 1;
    while (std::getline(in, line)) {
      printw((std::to_string(row) + ".").c_str());
      printw(" ");
      printw(line.c_str());
      printw("\n");
      refresh();
      row++;
    }
  } else {
    printw("Error opening file.\n");
    refresh();
  }
  in.close();

  printw("\nPress any key to continue...\n");
  refresh();
  getch();
  endwin();
  return 0;
}