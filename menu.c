void printLine(int w) {
    int i;
    for (i = 0; i < w; i++) {
        printf("-");
    }
}

extern void menu() {
    char text[23][88] = {"BBBBBBBBBBBBBBBBB      iiii\0",
                         "B::::::::::::::::B    i::::i\0",
                         "B::::::BBBBBB:::::B    iiii\0",
                         "BB:::::B     B:::::B\0",
                         "  B::::B     B:::::B iiiiiii nnnn  nnnnnnnn        ggggggggg   ggggg    ooooooooooo\0",
                         "  B::::B     B:::::B i:::::i n:::nn::::::::nn     g:::::::::ggg::::g  oo:::::::::::oo\0",
                         "  B::::BBBBBB:::::B   i::::i n::::::::::::::nn   g:::::::::::::::::g o:::::::::::::::o\0",
                         "  B:::::::::::::BB    i::::i nn:::::::::::::::n g::::::ggggg::::::gg o:::::ooooo:::::o\0",
                         "  B::::BBBBBB:::::B   i::::i   n:::::nnnn:::::n g:::::g     g:::::g  o::::o     o::::o\0",
                         "  B::::B     B:::::B  i::::i   n::::n    n::::n g:::::g     g:::::g  o::::o     o::::o\0",
                         "  B::::B     B:::::B  i::::i   n::::n    n::::n g:::::g     g:::::g  o::::o     o::::o\0",
                         "  B::::B     B:::::B  i::::i   n::::n    n::::n g::::::g    g:::::g  o::::o     o::::o\0",
                         "BB:::::BBBBBB::::::B i::::::i  n::::n    n::::n g:::::::ggggg:::::g  o:::::ooooo:::::o\0",
                         "B:::::::::::::::::B  i::::::i  n::::n    n::::n  g::::::::::::::::g  o:::::::::::::::o\0",
                         "B::::::::::::::::B   i::::::i  n::::n    n::::n   gg::::::::::::::g   oo:::::::::::oo\0",
                         "BBBBBBBBBBBBBBBBB    iiiiiiii  nnnnnn    nnnnnn     gggggggg::::::g     ooooooooooo\0",
                         "                                                            g:::::g\0",
                         "                                                gggggg      g:::::g\0",
                         "                                                g:::::gg   gg:::::g\0",
                         "                                                 g::::::ggg:::::::g\0",
                         "                                                  gg:::::::::::::g\0",
                         "                                                    ggg::::::ggg\0",
                         "                                                       gggggg\0"};

    char menu[12][31] = {"           __                 \0",
                         "/|   __   (_ |_ _  _|_        \0",
                         " |        __)|_(_|| |_        \0",
                         "                              \0",
                         "__          __                \0",
                         " _)   __   (_  _|_|_. _  _  _ \0",
                         "/__        __)(-|_|_|| )(_)_) \0",
                         "                        _/    \0",
                         "__          __                \0",
                         " _)   __   /  \\   .|_         \0",
                         "__)        \\_\\/|_|||_         \0",
                         "                              \0"};

    int scWidth = GetSystemMetrics(SM_CXSCREEN);
    int scHeight = GetSystemMetrics(SM_CYSCREEN);
    int i, j;
    // 40px ta taskbar e 24 do menu superior
    // 18 da barra de rolagem
    // As letras são 8px x 16px

    int consoleHeight = scHeight - 40 - 24;
    int letterPerHeight = consoleHeight / 16;

    int consoleWidth = scWidth - 18;
    int letterPerWidth = consoleWidth / 8;

    printLine(letterPerWidth);

    // -2 Remove as barras laterais

    // Tamanho do texto
    int textWidth = 88;
    int textHeight = 23;

    int menuHeight = 12;
    int menuWidth = 30;

    for (i = 0; i < letterPerHeight - 2; i++) {
        printf("|");

        if (i <= (letterPerHeight - 2) / 2 && i > ((letterPerHeight - 2) / 2) - textHeight) {
            for (j = 0; j < ((letterPerWidth - 2) / 2) - textWidth / 2; j++) {
                printf(" ");
            }
            printf("%s", text[i - (((letterPerHeight - 2) / 2) - (textHeight - 1))]);

            // Para voltar a colocar espaços, pega metade de letras que deveriam ter, soma com metade do tamanho do texto
            // e subtrai pelo tamanho da linha impressa (confuso mas funciona)
            // Os 1 na linha de baixo estão "formatando" o /0 (gambiarra xD)
            for (j = 0; j < ((letterPerWidth - 2) / 2) + textWidth / 2 - strlen(text[i - (((letterPerHeight - 2) / 2) - (textHeight - 1))]) + 1; j++) {
                printf(" ");
            }
        } else if (i > ((letterPerHeight - 2) / 2) + 2 && i <= (((letterPerHeight - 2) / 2) + 2) + menuHeight) {
            // O + 2 é só pra pular 2 linhas do BINGO msm
            // NO geral, fazendo a mesma coisa, mas pro menu
            for (j = 0; j < ((letterPerWidth - 2) / 2) - menuWidth / 2; j++) {
                printf(" ");
            }

            printf("%s", menu[i - (((letterPerHeight - 2) / 2) + 2) - 1]);

            for (j = 0; j < ((letterPerWidth - 2) / 2) + menuWidth / 2 - strlen(menu[i - (((letterPerHeight - 2) / 2) + 2) - 1]) + 1; j++) {
                printf(" ");
            }
        } else {
            for (j = 0; j < letterPerWidth - 2; j++) {
                printf(" ");
            }
        }

        printf("|");
    }

    printLine(letterPerWidth);
}