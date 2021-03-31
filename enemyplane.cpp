#include "enemyplane.h"

EnemyPlane::EnemyPlane()
{
    //敌机资源加载(不需要,出来的时候再初始化)

    //敌机位置
    m_x = 0, m_y = 0;
    //血量
    now_hp = 0; sum_hp = 0;
    //敌机状态
    m_Free = true;
    //敌机速度
    m_Speed = ENEMY_SPEED;
}

void EnemyPlane::initRect()
{

    //敌机矩形框
    m_Rect.setWidth(img_enemy.width());
    m_Rect.setHeight(img_enemy.height());
    m_Rect.moveTo(m_x,m_y);
}

void EnemyPlane::updatePosition()
{
    if( m_Free==true )  return;//空闲的,不需要移动
    m_y += m_Speed;//往前飞
    m_Rect.moveTo(m_x,m_y);
    if( m_y>=GAME_HEIGHT )
        m_y = 0, m_Free = true;
}
