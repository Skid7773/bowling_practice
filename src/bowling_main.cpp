#include "bowling_game.h"

int main(void)
{
    Game game;

    game.roll(3);   
    game.roll(7);   /*1F: 20*/
    game.roll(10);  /*2F: 20*/
    game.roll(1);
    game.roll(9);   /*3F: 16*/
    game.roll(6);
    game.roll(0);   /*4F: 6*/
    game.roll(0);
    game.roll(0);   /*5F: 0*/
    game.roll(4);
    game.roll(5);   /*6F: 9*/
    game.roll(8);
    game.roll(2);   /*7F: 20*/
    game.roll(10);  /*8F: 30*/
    game.roll(10);  /*9F: 30*/
    game.roll(10);  /*10F: 10*/
    game.roll(10);  /*10F: 10*/
    game.roll(5);   /*10F: 5*/
    /* garbage */
    game.roll(0);
    game.roll(15);
    game.roll(10);
    game.roll(0);
    game.roll(0);
    game.roll(0);
    game.roll(0);
    game.roll(1);

    game.showScore();   /* expect: 176 */
    game.NextGame();

    game.roll(10);
    game.roll(10);
    game.roll(10);
    game.roll(10);
    game.roll(10);
    game.roll(10);
    game.roll(10);
    game.roll(10);
    game.roll(10);  /*9F*/
    game.roll(10);
    game.roll(10);
    game.roll(10);
    /* garbage */
    game.roll(10);
    game.roll(10);

    game.showScore();   /* expect: 300 */

    return 0;
}