
#include <stdio.h> // puts()
#include <stdlib.h> // exit()
#include <curses.h> // getch()
#include <stdbool.h> // bool

int main(int argc, char *argv[])
{
    bool valid;

    initscr();
    cbreak(); // Don't expect a return after choosing an option
    noecho(); // Don't show user input

    if (has_colors() == FALSE) {

        printw("No colors in your terminal. Would you mind noticing that we live in 21st century?");
        exit(1);
    }

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    printw("Welcome to Stan's Diner!\n"
           "1. Coffee\n"
           "2. Tea\n"
           "3. Fried Eggs\n\n");


    do {
        attron(A_BOLD); // Show the choice in bold font

        switch (getch()) {

        case '1':
            attron(COLOR_PAIR(1));
            printw("You chose Coffee\n");
            attroff(COLOR_PAIR(1));

            valid = true;
            break;
        case '2':
            attron(COLOR_PAIR(1));
            printw("You chose Tea\n");
            attroff(COLOR_PAIR(1));

            valid = true;
            break;
        case '3':
            attron(COLOR_PAIR(1));
            printw("You chose Fried Eggs\n");
            attroff(COLOR_PAIR(1));

            valid = true;
            break;

        default:
            clear();

            attroff(A_BOLD);
            printw("Welcome to Stan's Diner!\n"
                   "1. Coffee\n"
                   "2. Tea\n"
                   "3. Fried Eggs\n\n");
            attron(A_BOLD);

            attron(COLOR_PAIR(2));
            printw("Wrong choice!");
            attroff(COLOR_PAIR(2));

            valid = false;
        }

        attroff(A_BOLD);

    } while (!valid);


    printw("Press any key to exit\n");
    getch();

    endwin();
    return 0;
}
