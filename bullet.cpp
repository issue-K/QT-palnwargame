#include "bullet.h"

Bullet::Bullet()
{
    //子弹威力
    force = 1;
    //加载子弹图片
    m_Bullet.load(BULLET_PATH);
    //子弹坐标
    m_x = GAME_WIDTH/2-m_Bullet.width()/2;
    m_y = GAME_HEIGHT;
    //子弹闲置状态
    m_Free = true;
    //子弹速度
    m_speed = BULLET_SPEED;
    //子弹边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_x,m_y);
}

void Bullet::updatePosition()
{
    if( m_Free )    return;//空闲子弹,不需要管
    //子弹向上移动
    m_y -= m_speed;
    m_Rect.moveTo(m_x,m_y);

    if( m_y<=-m_Rect.height() )//子弹超过窗口,变成空闲
        m_Free = true;
}
