#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* display the menu list to the console */
void console_display(void);
/* getting user's keystroke including extended keyboard keys */
char get_key(void);

/* global variable for storing cursor position */
int cur_pos = 0;

int main()
{

    /* variable for holding pressed key input char */
    char ch = 0;

    /* accept input from the user until he press enter or ESC */
    while (ch != 27 && ch != 13)
    {
        console_display();
        ch = get_key();
        switch (ch){
            case 72:  /* up key */
                if (cur_pos == 0)
                    cur_pos = 2;
                else
                    cur_pos--;
                break;
            case 80:  /* down key */
            case 9:   /* tab key */
                if (cur_pos == 2)
                    cur_pos = 0;
                else
                    cur_pos++;
                break;
            case 71:  /* home key */
                cur_pos = 0;
                break;
            case 79:  /* end key */
                cur_pos = 2;
                break;
            case 13:  /* enter key */
                if (cur_pos == 0)
                    printf("\nnew\n");
                else if (cur_pos == 1)
                    printf("\ndisplay\n");
                else
                    return 0;
                printf("Press any key to exit the program.\n");
                getch();
                break;
            }

    }

    return 0;
}

/* display the menu list to the console */
void console_display(void)
{
    /* clear the screen */
    system("cls");
    /* array of strings to hold the menu list */
    char * display_options[3];
    display_options[0] = "New";
    display_options[1] = "Display";
    display_options[2] = "Exit";
    /* print the menu list to the console */
    for (int i = 0; i < 3; i++)
    {
        printf("\n%s", display_options[i]);
        /* check for cursor position (the highlighted menu line)*/
        if (i == cur_pos)
        {
            printf("_");
        }
        printf("\n");
    }
}

/* getting user's keystroke including extended keyboard keys */
char get_key(void)
{
    char c = getch();
    /*
     * if the input keystroke is from keyboard extended keys it
     * sends two chars to the stdin the first char ascii decimal
     * value equals 0 or -32 we ignore it and take second char
     * and return it.
     */
    if (c == 0 || c == -32)
    {
        c = getch();
    }
    return c;
}
