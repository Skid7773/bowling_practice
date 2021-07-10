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
    game.NextGame();

    game.roll(10);  /*1F: 30*/
    game.roll(10);  /*2F: 30*/
    game.roll(10);  /*3F: 30*/
    game.roll(10);  /*4F: 30*/
    game.roll(10);  /*5F: 30*/
    game.roll(10);  /*6F: 30*/
    game.roll(10);  /*7F: 27*/
    game.roll(10);  /*8F: 20*/
    game.roll(7);   
    game.roll(3);   /*9F: 14*/
    game.roll(4);
    game.roll(5);   /*10F: 9*/
    /* garbage */
    game.roll(1);
    game.roll(2);
    game.roll(3);

    game.showScore();   /* expect: 250 */
    game.NextGame();

    game.roll(1);
    game.roll(2);   /*1F: 3*/
    game.roll(3);
    game.roll(4);   /*2F: 7*/
    game.roll(5);
    game.roll(5);   /*3F: 16*/
    game.roll(6);   /*4F(1/2): 6*/
    game.showScore();   /* expect: 32 */
    game.roll(4);   /*4F: 10+10*/
    game.roll(10);  /*5F: 20+2*/
    game.roll(10);  /*6F: 10+2+3*/
    game.showScore();   /* expect: 76 */
    game.roll(2);   /*7F(1/2): 2*/
    game.showScore();   /* expect: 82 */
    game.roll(3);   /*7F: 5*/
    game.showScore();   /* expect: 88 */

    return 0;
}