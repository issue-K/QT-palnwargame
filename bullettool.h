#ifndef BULLETTOOL_H
#define BULLETTOOL_H
#include <QRect>
#include <QPixmap>
class BulletTool
{
public:
    BulletTool();
    void init(QString w);
    void New_Speed();
    void updatepostion();

public:
    int m_x,m_y;//位置
    int speed_x,speed_y;//移动速度
    int record;//销毁时间
    int force = 1;
    QPixmap img;//道具的图片资源
    QRect m_rect;

};

#endif // BULLETTOOL_H
