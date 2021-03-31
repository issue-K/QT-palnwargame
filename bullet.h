#ifndef BULLET_H
#define BULLET_H
#include <config.h>
#include <QPixmap>

class Bullet
{
public:
    Bullet();
    //更新子弹的坐标
    void updatePosition();

public:
    //子弹图片
    QPixmap m_Bullet;
    //子弹坐标
    int m_x,m_y;
    //子弹威力
    int force;
    //子弹移动速度
    int m_speed;
    //标注子弹当前是否在移动
    bool m_Free;
    //子弹边框(碰撞检测)
    QRect m_Rect;
};

#endif // BULLET_H
