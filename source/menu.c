#include "../include/snake.h"

void            *menu()
{
    int         row;
    int         col;
    int         map;
    char        t;
    char        *path;
    char        buf[400];
    ssize_t     file;
    t_list      list;
    t_snake     snake;

    t = '\0';
    path = NULL;

    init(&list);
    my_putstr("\033c\n"); // Clear terminal
    my_putstr("       /******* SNAKE *******\\\n");
    my_putstr("       |                     |\n");
    my_putstr("       |  1)  MAP LEVEL 1    |\n");
    my_putstr("       |  2)  MAP LEVEL 2    |\n");
    my_putstr("       |  3)  MAP LEVEL 3    |\n");
    my_putstr("       |  4)  CHOISE SIZE    |\n");
    my_putstr("       |                     |\n");
    my_putstr("       |  5)     QUIT        |\n");
    my_putstr("       \\*********************/\n\n");

    path = malloc(sizeof(char *) * 20);

    t = readline();

    if (t == '1')
        path = "maps/level1.txt";
    else if (t == '2')
        path = "maps/level2.txt";
    else if (t == '3')
        path = "maps/level3.txt";
    else if (t == '4')
        my_putstr("Coming soon\n");
    else if (t == '5')
    {
        my_putstr("\033c\n"); // Clear terminal
        my_putstr("Goodbye !\n");
        list_free(&list);
        return (0);
    }
    else
        menu();

    if (path != NULL)
    {
        map = open(path, O_RDONLY);
        file = read(map, buf, sizeof(buf));
        col = count_x(buf);
        row = count_y(buf);

        char    arr[row][col];

        get_map(path, col, arr);

        // PUT SNAKE IN ARR
        snake_in_map(&list, col, arr);

        // PUT BONUS AND MALUS ON MAP
        put_rand_bonus(col, row, arr);
        put_rand_malus(col, row, arr);

        // GAME
        move(&list, col, row, arr);

        menu();
    }
    else
        my_putstr("Cette map n'existe pas.\n");
}