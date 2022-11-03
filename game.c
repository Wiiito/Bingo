int num = 2;
int columns = 2;

int rng() {
    int rng = rand() % 60;
    if (rng <= 0) {
        rng = 60;
    }
    return rng;
}

int valueinarray(int val, int arr[]) {
    int i;
    for (i = 0; i < 60; i++) {
        if (arr[i] == val) {
            return 1;
        }
    }
    return 0;
}

extern void changePlayers(int players) {
    num = players;
}

extern void changeColumns(int colunas) {
    columns = colunas;
}

extern void game() {
    srand(time(NULL));  // Mudando a seed do rand() (passando o tempo desde 1970 (pq? só deus sabe))

    int i, j, k, numbers[60], aux, winner = 0, input = 0;

    for (i = 0; i < 60; i++) {  // Tirando todos os números do numbers
        numbers[i] = 0;
    }

    int **players = malloc(sizeof(int *) * num);

    for (i = 0; i < num; i++) {
        players[i] = malloc(sizeof(int) * 16);
    }

    for (i = 0; i < num; i++) {
        for (j = 0; j < 16; j++) {
            players[i][j] = rng();
            for (k = 0; k < j; k++) {  // Vendo se ja esta em uso
                if (players[i][j] == players[i][k]) {
                    j--;
                }
            }
        }
        for (j = 0; j < 16; j++) {  // Deixando em ordem crescente
            for (k = j + 1; k < 16; k++) {
                if (players[i][j] > players[i][k]) {
                    aux = players[i][j];
                    players[i][j] = players[i][k];
                    players[i][k] = aux;
                }
            }
        }
    }

    // O jogo começa aqui
    // Gerando números

    while (winner == 0 && input != 3) {  // Roda o codigo até que um ganhador seja encontrado
        int out = 60, max, temp = 0;
        while (out) {  // Vale a pena ressaltar, isso aqui ta criando um número aleatorio xD
            // Out é só um valor pro loop rodar enquanto não encontra uma posição vazia (0)
            // Dai pra aproveitar, ele é usado pra encontrar a casa mais alta do loop
            max = 60 - out;
            out--;
            if (numbers[max] == 0) {
                while (temp == 0) {
                    temp = rng();
                    if (valueinarray(temp, numbers) == 1) {
                        temp = 0;
                    } else {
                        numbers[max] = temp;
                    }
                }
                out = 0;
            }
        }

        system("cls");  // Limpando o terminal pra ficar bonitinho :3

        // Deixando o número sorteado maior
        printf("Numero da sorte: \n");
        printColllerNumbers(numbers[max]);

        printf("\n");
        // Mostrando todos os números sorteados até então
        for (i = 0; i <= max; i++) {
            if (i > 0) {  // Imprimindo todos os numeros menos o da sorte, pra isso n posso imprimir o arr[-1]
                printf("%02i ", numbers[i - 1]);
            }
        }

        printf("\n");

        // Gerando uma linha em cima para separar tudo
        for (j = 0; j < 50 * columns + 1; j++) {
            printf("-");
        }
        printf("\n");

        // Gerando o nome dos jogadores
        for (i = 0; i < num; i++) {
            printf("|");
            for (j = 0; j < 20; j++) {
                printf(" ");
            }
            printf("Jogador %02i", i + 1);
            for (j = 0; j < 19; j++) {
                printf(" ");
            }

            if (i % columns == columns - 1) {  // 3 é a quantidade de jogadores por linha (2 é um a menos q a quantidade de linhas)
                printf("|\n");

                // Imprimindo a tabela dos jogadores
                for (j = columns - 1; j >= 0; j--) {
                    printf("| ");
                    for (k = 0; k < 16; k++) {
                        printf("%02i ", players[i - j][k]);
                    }
                }
                printf("|\n");

                // Imprimindo os números marcados
                for (j = columns - 1; j >= 0; j--) {
                    printf("| ");
                    for (k = 0; k < 16; k++) {
                        if (valueinarray(players[i - j][k], numbers)) {
                            printf(">< ");
                        } else {
                            printf("() ");
                        }
                    }
                }
                printf("|\n");

                for (j = 0; j < 50 * columns + 1; j++) {
                    printf("-");
                }
                printf("\n");
            }
        }

        if (num % columns != 0) {  // Quebra de linha com base no número de colunas
            printf("|\n");
            for (i = num - num % columns; i < num; i++) {
                // Imprimindo a tabela dos jogadores
                printf("| ");
                for (j = 0; j < 16; j++) {
                    printf("%02i ", players[i][j]);
                }
            }
            printf("|\n");

            for (i = num - num % columns; i < num; i++) {
                // Imprimindo os números marcados
                printf("| ");
                for (j = 0; j < 16; j++) {
                    if (valueinarray(players[i][j], numbers)) {
                        printf(">< ");
                    } else {
                        printf("() ");
                    }
                }
            }
            printf("|\n");

            for (j = 0; j < 50 * (num % columns) + 1; j++) {
                printf("-");
            }
            printf("\n");
        }

        // Procurando ganhadores
        for (i = 0; i < num; i++) {
            for (j = 0; j < 16; j++) {
                if (valueinarray(players[i][j], numbers)) {
                    winner = i + 1;
                } else {
                    winner = 0;
                    break;
                }
            }
            if (winner) {
                break;
            }
        }
        if (!winner) {  // Só pra n ter q ficar apertando enter quando alguém ganhar
            printf("Para sortear o proximo numero, pressione qualquer tecla");
            printf("\nPara voltar digite - 3\n");
            input = getch() - 48;
        }
    }
    free(players);

    if (winner) {
        printf("\n\nGanhador: ");
        printColllerNumbers(winner);
        printf("\n");
        system("PAUSE");
    }

    returnToMenu();
}
