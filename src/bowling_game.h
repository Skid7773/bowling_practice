#define TBLSIZE_KNOCKEDDOWN (3)
#define MAX_KNOCKEDDOWN_PINS (10)
#define MAX_ROLL_CNT (21)
#define MAX_FLAMENUM (10)
#define MAX_THROWNUM (3)

class Game
{
public:
    enum FLAME_RESULT_TYPE {
        RESULT_LAME,    /* ぱっとしない(0-9) */
        RESULT_SPARE,
        RESULT_STRIKE,
        RESULT_INVALID, /* ありえないスコア(合計11以上) */
    };
private:
    unsigned int   m_nRollCnt;
    /* 単純化 */
    unsigned int   m_tblKnockedDown[MAX_ROLL_CNT];

    Game::FLAME_RESULT_TYPE CheckFlameResultType(unsigned int nFirst, unsigned int nSecond);
    unsigned int CalcOneFlameScore(unsigned int pstCurrentSet[3], unsigned int *pScoreResult);
    unsigned int CalcLastFlameScore(unsigned int pstCurrentSet[3], unsigned int *pScoreResult);

public:
    Game(void);

    void roll(unsigned int nKnockedDown);
    unsigned int score(void);
    void showScore(void);
    void NextGame(void);
    unsigned int GetRollCnt(void) const { return m_nRollCnt; };
};