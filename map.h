#ifndef MAP_H
#define MAP_H
#include <QPixmap>

class map
{
public:
    //构造函数
    map(QString MAP_PATH);
    //地图滚动坐标计算
    void mapPosition();

public:
    QPixmap map1;
    QPixmap map2;
    //地图Y轴坐标
    int map1_posY;
    int map2_posY;
    //地图滚动幅度
    int m_scroll_speed;

};

#endif // MAP_H
