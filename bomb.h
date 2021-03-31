#ifndef BOMB_H
#define BOMB_H

#include <QPixmap>
class Bomb
{
public:
    Bomb();
    void updateInfo();
public:
    //爆炸的资源图片数组
    QVector<QPixmap>vector;
    //爆炸位置
    int m_x,m_y;
    //爆炸状态
    bool m_Free;
    //爆炸切图时间间隔
    int boom_record;
    //当前爆炸显示图片下标
    int m_index;
};

#endif // BOMB_H
