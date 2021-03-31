#include "heroplane.h"
#include <config.h>

HeroPlane::HeroPlane()
{
    //加载飞机图片
    m_Plane.load(HERO_PATH);
    //初始化飞机坐标
    m_x = (GAME_WIDTH-m_Plane.width() )/2;
    m_y = GAME_HEIGHT-m_Plane.height();
    //初始化矩形边框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
}

void HeroPlane::shoot()
{
    //如果记录的数字没有到发射间隔
    if( ++bullet_recorder<BULLET_INTERVAL ) return;
    bullet_recorder = 0;
    //发射子弹
    for(int i=0;i<BULLET_NUM;i++)//找到空闲子弹
    {
        if( !bullets[i].m_Free  )    continue;
        bullets[i].m_Free = false;
        bullets[i].m_x = m_x+( m_Plane.width()-bullets[i].m_Bullet.width() )/2;
        bullets[i].m_y = m_y;
        break;
    }
}

void HeroPlane::setPosition(int x,int y)//设置飞机位置
{
    m_x = x, m_y = y;
    m_Rect.moveTo(m_x,m_y);
}
