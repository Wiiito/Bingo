// Ver isso aqui no game.c tava dando nos nervos

extern int printColllerNumbers(int num) {
    char num1[11][14] = {"       oe    \0",
                         "     .@88    \0",
                         " ==*88888    \0",
                         "    88888    \0",
                         "    88888    \0",
                         "    88888    \0",
                         "    88888    \0",
                         "    88888    \0",
                         "    88888    \0",
                         "    88888    \0",
                         " '**%%%%%%** \0"};
    char num2[11][16] = {"  .--~*teu.    \0",
                         " dF     988Nx  \0",
                         "d888b   `8888> \0",
                         "?8888>  98888F \0",
                         " \"**\"  x88888~ \0",
                         "      d8888*`  \0",
                         "    z8**\"`   : \0",
                         "  :?.....  ..F \0",
                         " <\"\"888888888~ \0",
                         " 8:  \"888888*  \0",
                         " \"\"    \"**\"`   \0"};
    char num3[11][16] = {"  .x~~\"*Weu.   \0",
                         " d8Nu.  9888c  \0",
                         " 88888  98888  \0",
                         " \"***\"  9888\%  \0",
                         "      ..@8*\"   \0",
                         "   ````\"8Weu   \0",
                         "  ..    ?8888L \0",
                         ":@88N   '8888N \0",
                         "*8888~  '8888F \0",
                         "'*8\"`   9888\%  \0",
                         "  `~===*\%\"`    \0"};
    char num4[11][18] = {"        xeee    \0",
                         "       d888R    \0",
                         "      d8888R    \0",
                         "     @ 8888R    \0",
                         "   .P  8888R    \0",
                         "  :F   8888R    \0",
                         " x\"    8888R    \0",
                         "d8eeeee88888eer \0",
                         "       8888R    \0",
                         "       8888R    \0",
                         "    \"*\%\%\%\%\%\%**~ \0"};
    char num5[11][18] = {"  cuuu....uK    \0",
                         "  888888888     \0",
                         "  8*888**\"      \0",
                         "  >  .....      \0",
                         "  Lz\"  ^888Nu   \0",
                         "  F     '8888k  \0",
                         "  ..     88888> \0",
                         " @888L   88888  \0",
                         "'8888F   8888F  \0",
                         " %8F\"   d888\"   \0",
                         "  ^\"===*%\"`     \0"};
    char num6[11][16] = {"    .ue~~%u.   \0",
                         "  .d88   z88i  \0",
                         " x888E  *8888  \0",
                         ":8888E   ^\"\"   \0",
                         "98888E.=tWc.   \0",
                         "98888N  '888N  \0",
                         "98888E   8888E \0",
                         "'8888E   8888E \0",
                         " ?888E   8888\" \0",
                         "  \"88&   888\"  \0",
                         "    \"\"==*\"\"    \0"};
    char num7[11][16] = {"dL ud8Nu  :8c \0",
                         "8Fd888888L \%8 \0",
                         "4N88888888cuR \0",
                         "4F   ^\"\"\%\"\"d  \0",
                         "d       .z8   \0",
                         "^     z888    \0",
                         "    d8888'    \0",
                         "   888888     \0",
                         "  :888888     \0",
                         "   888888     \0",
                         "   '\%**\%      \0"};
    char num8[11][18] = {"   u+=~~~+u.    \0",
                         " z8F      `8N.  \0",
                         "d88L       98E  \0",
                         "98888bu.. .@*   \0",
                         "\"88888888NNu.   \0",
                         " \"*8888888888i  \0",
                         " .zf\"\"*8888888L \0",
                         "d8F      ^\%888E \0",
                         "88>        `88~ \0",
                         "'\%N.       d*\"  \0",
                         "   ^\"=====\"`    \0"};

    char num9[11][17] = {"  .xn!~\%x.     \0",
                         " x888   888.   \0",
                         "X8888   8888:  \0",
                         "88888   X8888  \0",
                         "88888   88888> \0",
                         "`8888  :88888X \0",
                         "  `\"**~ 88888> \0",
                         " .xx.   88888  \0",
                         "'8888>  8888~  \0",
                         " 888\"  :88\%    \0",
                         "  ^\"===\"\"      \0"};

    char num0[11][18] = {"    .n~~\%x.     \0",
                         "  x88X   888.   \0",
                         " X888X   8888L  \0",
                         "X8888X   88888  \0",
                         "88888X   88888X \0",
                         "88888X   88888X \0",
                         "88888X   88888f \0",
                         "48888X   88888  \0",
                         " ?888X   8888\"  \0",
                         "  \"88X   88*`   \0",
                         "    ^\"===\"`     \0"};

    int line, print[2], i;
    print[0] = num / 10;
    print[1] = num % 10;

    printf("\n");
    for (line = 0; line < 11; line++) {
        for (i = 0; i < 2; i++) {
            switch (print[i]) {
                case 1:
                    printf("%s", num1[line]);
                    break;
                case 2:
                    printf("%s", num2[line]);
                    break;
                case 3:
                    printf("%s", num3[line]);
                    break;
                case 4:
                    printf("%s", num4[line]);
                    break;
                case 5:
                    printf("%s", num5[line]);
                    break;
                case 6:
                    printf("%s", num6[line]);
                    break;
                case 7:
                    printf("%s", num7[line]);
                    break;
                case 8:
                    printf("%s", num8[line]);
                    break;
                case 9:
                    printf("%s", num9[line]);
                    break;
                case 0:
                    printf("%s", num0[line]);
                    break;
            }
        }
        printf("\n");
    }
}