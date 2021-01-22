#include <stdio.h>
#include <stdlib.h>

/* function to fill the magicBox */
void printMagicBox(int box[][10], int n);
/* print the magic box to the console */
void fillmagicBox(int box[][10], int n, int x, int y);

int main()
{
    /* initializing a 2D array its size 10 * 10 */
    int magicBox[10][10] = {0};
    /* n is a variable holding length of one side of the magic box (box size n * n) */
    int n = 0;
    /* x, y are variables for holding start point index */
    int x = 0, y = 0;
    do
    {
        printf("Enter n (n must be between 1 and 10) : ");
        scanf("%d", &n);
    }
    while (n < 1 || n > 10);

    do
    {
       printf("\nEnter start point (x, y) (x and y values must be between 1 and n):\n");
       printf("  x : ");
       scanf("%d", &x);
       printf("\n  y : ");
       scanf("%d", &y);
    }
    while ((x < 1 || x > n) || (y < 1 || y > n));

    fillmagicBox(magicBox, n, x, y);
    printMagicBox(magicBox, n);

    return 0;
}


/* function to fill the magicBox */
void fillmagicBox(int box[][10], int n, int x, int y)
{
    /* number of spaces in the box */
   int box_spaces = n * n;
   /* variable to hold the current value */
   int cur_val = 1;

   /* convert x, y coordinates to 2D array indices */
   x--;
   y--;

   /* iterate over box spaces to fill them */
   for (cur_val = 1; cur_val < box_spaces; cur_val++)
   {
       /* fill the space at (x, y) in the box with the current value */
       box[y][x] = cur_val;
       /* move to next space */
       if ((cur_val % n) != 0)
       {
           /*
            * if current value is not divisible by n move one step to the
            * left and one step up and if you reach the box borders round to
            * other side.
            */
           if (x == 0) {x = n - 1;}
           else {x--;}
           if (y == 0) {y = n - 1;}
           else {y--;}

       }
       else
       {
           /*
            * if current value is divisible by n move one step down and if
            * you reach the box borders round to other side.
            */
           if (y == n - 1) {y = 0;}
           else {y++;}
       }
   }
   /* set last space to current value */
   box[y][x] = cur_val;
}

/* print the magic box to the console */
void printMagicBox(int box[][10], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (box[i][j] < 10)
                printf(" %d ", box[i][j]);
            else
                printf("%d ", box[i][j]);
        }
        printf("\n");
    }
}
