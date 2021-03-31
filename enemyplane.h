#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>
#include <config.h>
#include <QRect>

class EnemyPlane
{
public:
    EnemyPlane();
    //根据分配的图片去更新自身信息
    void initRect();
    //更新坐标函数
    void updatePosition();
public:
    //图片资源
    QPixmap img_enemy;
    //位置
    int m_x,m_y;
    //总血量,当前血量
    int sum_hp,now_hp;
    //边框
    QRect m_Rect;
    //是否闲置
    bool m_Free;
    //飞行速度
    int m_Speed;
};

#endif // ENEMYPLANE_H
