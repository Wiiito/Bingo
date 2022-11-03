#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "game.c"
#include "menu.c"
#include "printNumbers.c"
#include "settings.c"

int input = 0;

extern returnToMenu() {
    input = 0;
}

int main() {
    while (input < 3) {  // Pra sair com qualquer outra coisa :)
        system("cls");
        switch (input) {
            case 1:
                game();
                break;
            case 2:
                settings();
                break;
            default:
                menu();
                fflush(stdin);
                input = getch() - 48;  // Getch pega como char
                break;
        }
    }
}
