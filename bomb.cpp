#include "bomb.h"
#include <config.h>

Bomb::Bomb()
{
    //将所有爆炸的pixmap装进去
    for(int i=1;i<=BOMB_NUM;i++)
        vector.push_back( QPixmap(QString(BOMB_PATH).arg(i)) );
    //坐标
    m_x = 0, m_y = 0;
    //空闲状态
    m_Free = true;
    //当前播放图片下标
    m_index = 0;
    //爆炸间隔
    boom_record = 0;
}

//更新图片索引的函数
void Bomb::updateInfo()
{
    //空闲状态下的爆炸效果,不需要更新
    if( m_Free )    return;
    if( ++boom_record<BOMB_INTERVAL )   return;
    //重置记录
    boom_record = 0;
    //图片下标
    m_index++;
    if( m_index>BOMB_NUM-1 )
    {
        m_index = 0;
        m_Free = true;
    }
}

