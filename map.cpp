#include "map.h"
#include <config.h>
map::map(QString MAP_PATH)
{
    //初始化加载地图对象
    map1.load(MAP_PATH);
    map2.load(MAP_PATH);
    map1_posY = -GAME_HEIGHT;
    map2_posY = 0;

    //地图滚动
    m_scroll_speed = MAP_SCROLL_SPEED;
}

void map::mapPosition()
{
    //处理第一张图片滚动位置
    map1_posY += m_scroll_speed; //第一张图往下跑
    if( map1_posY>=0 )    map1_posY = -GAME_HEIGHT;
    map2_posY += m_scroll_speed;
    if( map2_posY>=GAME_HEIGHT )  map2_posY = 0;
}
