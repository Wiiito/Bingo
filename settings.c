
extern void settings() {
    int input = 0, value;
    while (input < 3) {
        system("cls");
        switch (input) {
            case 1:
                printf("Digite a quantidade de jogadores: ");
                scanf("%i", &value);
                if (value > 0) {
                    changePlayers(value);
                    input = 0;
                }
                break;

            case 2:
                printf("Digite a quantidade de colunas: ");
                scanf("%i", &value);
                if (value > 0) {
                    changeColumns(value);
                    input = 0;
                }
                break;
            default:
                printf("Configuracoes: \n1 - Jogadores\n2 - Colunas\n3 - Voltar\n");
                fflush(stdin);
                input = getch() - 48;
                break;
        }
    }
    returnToMenu();
}