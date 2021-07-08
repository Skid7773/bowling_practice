#include "stdio.h"
#include "bowling_game.h"

Game::Game(void)
: m_nRollCnt(0)
{
    for(int i = 0; i < MAX_ROLL_CNT; i++){
        m_tblKnockedDown[i] = 0;
    }
}
/**
 * 投球：
 *  引数は倒したピンの数
 *  ファールはただの0ピンとして扱う
 *  不正な入力も0として扱う
 **/
void
Game::roll(unsigned int nKnockedDown)
{
    if(MAX_KNOCKEDDOWN_PINS < nKnockedDown){
        /* 10を超える異常値は0とする */
        nKnockedDown = 0;
    }
    if(m_nRollCnt < MAX_ROLL_CNT){
        m_tblKnockedDown[m_nRollCnt] = nKnockedDown;
        m_nRollCnt++;
    }
}
Game::FLAME_RESULT_TYPE
Game::CheckFlameResultType(unsigned int nFirst, unsigned int nSecond)
{
    Game::FLAME_RESULT_TYPE eType = Game::RESULT_LAME;

    if(MAX_KNOCKEDDOWN_PINS == nFirst){
        eType = Game::RESULT_STRIKE;
    }
    else{
        if(MAX_KNOCKEDDOWN_PINS == (nFirst + nSecond)){
           eType = Game::RESULT_SPARE;
        }
        else if(MAX_KNOCKEDDOWN_PINS > (nFirst + nSecond)){
           eType = Game::RESULT_LAME;
        }
        else{
          eType = Game::RESULT_INVALID;
        }
    }

    return eType;
}
unsigned int
Game::CalcOneFlameScore(unsigned int pstCurrentSet[4], unsigned int *pScoreResult)
{
    unsigned int nScore = 0;
    unsigned int nMove = 0;

    Game::FLAME_RESULT_TYPE eType = CheckFlameResultType(pstCurrentSet[0], pstCurrentSet[1]);
    switch(eType){
    case Game::RESULT_INVALID:
        /* 入力漏れの0が[0]と[1]の間にあったものとして計算しておく */
        nScore = pstCurrentSet[0];
        nMove = 1;
        break;
    case Game::RESULT_STRIKE:
        {
            Game::FLAME_RESULT_TYPE eType2 = CheckFlameResultType(pstCurrentSet[1], pstCurrentSet[2]);
            if(Game::RESULT_INVALID == eType2){
                /* 入力漏れの0が[1]と[2]の間にあったものとして計算しておく */
                nScore = MAX_KNOCKEDDOWN_PINS + pstCurrentSet[1];
            }
            else{
                nScore = MAX_KNOCKEDDOWN_PINS + pstCurrentSet[1] + pstCurrentSet[2];
            }
            nMove = 1;
        }
        break;
    case Game::RESULT_SPARE:
        /* 配列の箱1つに11以上の値が入っていることはないので、異常値を気にせず単純に足し算 */
        nScore = MAX_KNOCKEDDOWN_PINS + pstCurrentSet[2];
        nMove = 2;
        break;
    case Game::RESULT_LAME:
    default:
        nScore = pstCurrentSet[0] + pstCurrentSet[1];
        nMove = 2;
        break;
    }

    *pScoreResult = nScore;
    return nMove;
}
unsigned int
Game::CalcLastFlameScore(unsigned int pstCurrentSet[3], unsigned int *pScoreResult)
{
    unsigned int nScore = 0;
    unsigned int nMove = 0;

    Game::FLAME_RESULT_TYPE eType = CheckFlameResultType(pstCurrentSet[0], pstCurrentSet[1]);
    /* ストライク以外ならスコア確定できる */
    switch(eType){
    case Game::RESULT_INVALID:
        /* 入力漏れの0が[0]と[1]の間にあったものとして計算しておく */
        nScore = pstCurrentSet[0] + pstCurrentSet[1];
        nMove = 2;
        break;
    case Game::RESULT_LAME:
    case Game::RESULT_SPARE:
        nScore = pstCurrentSet[0] + pstCurrentSet[1] + pstCurrentSet[2];
        nMove = 3;
        break;
    case Game::RESULT_STRIKE:
    default:
        {
            Game::FLAME_RESULT_TYPE eType2 = CheckFlameResultType(pstCurrentSet[1], pstCurrentSet[2]);
            if(Game::RESULT_INVALID == eType2){
                /* 入力漏れの0が[1]と[2]の間にあったものとして計算しておく */
                nScore = pstCurrentSet[0] + pstCurrentSet[1];
                nMove = 2;
            }
            else{
                nScore = pstCurrentSet[0] + pstCurrentSet[1] + pstCurrentSet[2];
                nMove = 3;
            }
        }
        break;
    }

    *pScoreResult = nScore;
    return nMove;
}
/**
 * スコアを取得：
 **/
unsigned int
Game::score(void)
{
    unsigned int nFlameCnt = 1;
    unsigned int i = 0;
    unsigned int nScoreSum = 0;

    while( (nFlameCnt <= MAX_FLAMENUM) && (i <= (m_nRollCnt-3)) ){
        unsigned int nTempScore = 0;
        unsigned int nMove = 0;

        if((MAX_FLAMENUM == nFlameCnt) || (i == (m_nRollCnt-3))){
            nMove = CalcLastFlameScore(&(m_tblKnockedDown[i]), &nTempScore);
        }
        else{
            nMove = CalcOneFlameScore(&(m_tblKnockedDown[i]), &nTempScore);
        }
        i += nMove;
        nScoreSum += nTempScore;
        nFlameCnt++;
    }

    return nScoreSum;
}
/**
 * スコアをコマンドラインに表示
 **/
void
Game::showScore(void)
{
    printf("Score: %d\n", score());
}

void
Game::NextGame(void)
{
    m_nRollCnt = 0;
    for(int i = 0; i < MAX_ROLL_CNT; i++){
        m_tblKnockedDown[i] = 0;
    }

    printf("== Next Game ==\n");
}