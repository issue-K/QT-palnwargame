#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include <QRect>
#include <bullet.h>
class HeroPlane
{
public:
    HeroPlane();
    //发射子弹
    void shoot();
    //设置飞机的位置
    void setPosition(int x,int y);

public:
    //飞机资源图片
    QPixmap m_Plane;
    //飞机坐标
    int m_x,m_y;
    //飞机的矩形边框
    QRect m_Rect;
    //弹夹
    Bullet bullets[BULLET_NUM];
    //子弹发射间隔记录
    int bullet_recorder;
};

#endif // HEROPLANE_H
