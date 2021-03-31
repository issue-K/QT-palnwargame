#include "mainscene.h"
#include "ui_mainscene.h"
#include <config.h>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <bullet.h>
#include <QSound>
#include <QColor>
#include <QBrush>
MainScene::MainScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    initScene();
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene()
{
    //播放背景音乐
    QSound::play(SOUND_BACKGROUND);
    //设置随机数种子
    srand( (unsigned int)time(NULL) );
    //设置窗口的固定尺寸,设置标题
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(":/res/app.ico") );
    m_map = new map(":/res/img_bg_level_1.jpg");
    //场景定时器设置
    timer.setInterval(10);
    //敌机出场间隔
    enemy_record = 0;
    playGame();
}

void MainScene::playGame()
{

    //监听定时器发送的信号
    connect(&timer,&QTimer::timeout,[=](){
            //敌机出场
            enemyToScene();
            //特殊子弹出场
            specialbulletToScene();
            //更新所有元素的坐标
            updatePosition();
            //碰撞检测
            collisionDetection();
            //绘制所有元素
            update();
    });
    //启动定时器
    timer.start();
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,m_map->map1_posY,m_map->map1);
    painter.drawPixmap(0,m_map->map2_posY,m_map->map2);
    //绘制英雄飞机
    painter.drawPixmap(m_hero.m_x,m_hero.m_y,m_hero.m_Plane);
    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        if( m_hero.bullets[i].m_Free==false )
            painter.drawPixmap(m_hero.bullets[i].m_x,m_hero.bullets[i].m_y,m_hero.bullets[i].m_Bullet);
    }
    //绘制敌机
    QBrush red_brush( QColor("#F20900") );
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if( enemys[i].m_Free==false )
        {
            painter.drawPixmap(enemys[i].m_x,enemys[i].m_y,enemys[i].img_enemy);
            painter.setBrush(red_brush);
            float rate = 1.0*enemys[i].now_hp/enemys[i].sum_hp;
            painter.drawRect(enemys[i].m_x,enemys[i].m_y,rate*enemys[i].img_enemy.width(),enemys[i].img_enemy.height()*0.2);
        }
    }
    //绘制爆炸图案
    for(int i=0;i<BOMB_NUM;i++)
    {
        if( bombs[i].m_Free==false )
            painter.drawPixmap(bombs[i].m_x,bombs[i].m_y,bombs[i].vector[bombs[i].m_index]);
    }
    //绘制特殊子弹道具
    if( special_bullet.record )
        painter.drawPixmap(special_bullet.m_x,special_bullet.m_y,special_bullet.img);
}

void MainScene::updatePosition()
{
    //更新地图坐标
    m_map->mapPosition();
    //发射子弹
    m_hero.shoot();
    for(int i=0;i<BULLET_NUM;i++)
    {
        if( m_hero.bullets[i].m_Free==false )
            m_hero.bullets[i].updatePosition();
    }
    //敌机出场
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if( enemys[i].m_Free==false )
            enemys[i].updatePosition();
    }
    //更新爆炸图片的下标
    for(int i=0;i<BOMB_NUM;i++)
    {
        if( bombs[i].m_Free==false )
            bombs[i].updateInfo();
    }
    //更新特殊元素的下标
    if( special_bullet.record )     special_bullet.updatepostion();
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x()-m_hero.m_Rect.width()/2;
    int y = event->y()-m_hero.m_Rect.height()/2;
    if( x<0 )   x = 0;
    if( y<0 )   y = 0;
    if( x>this->width()-m_hero.m_Rect.width() )   x = this->width()-m_hero.m_Rect.width();
    if( y>this->height()-m_hero.m_Rect.height() )  y = this->height()-m_hero.m_Rect.height();
    m_hero.setPosition(x,y);
}
//敌机出场!!!
void MainScene::enemyToScene()
{
    if( ++enemy_record<ENEMY_INTERVAL ) return;
    enemy_record = 0;
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if( enemys[i].m_Free==false )   continue;//非空闲,不能使用
        enemys[i].sum_hp = enemys[i].now_hp = rand()%10+1;//初始化血量
        enemys[i].img_enemy.load(QString(ENEMY_PATH).arg( (enemys[i].sum_hp+2 )/3 ) );
        enemys[i].initRect();//更新矩形框
        enemys[i].m_Free = false;
        enemys[i].m_x = rand()%(GAME_WIDTH-enemys[i].m_Rect.width());
        enemys[i].m_y = -enemys[i].m_Rect.height();
        break;
    }
}
//特殊子弹出场
void MainScene::specialbulletToScene()
{
    if( special_bullet.record ) return;//已经在场景中了,不需要了
    special_bullet.record = 1000000;//持续1000*10ms,也就是10s
    special_bullet.init(SPECIALBULLET_PATH);//初始化自己的速度,
}
//碰撞检测
void MainScene::collisionDetection()
{
    //遍历所有非空闲敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if( enemys[i].m_Free )  continue;
        for(int j=0;j<BULLET_NUM;j++)
        {
            if( m_hero.bullets[j].m_Free )  continue;
            QRect res = m_hero.bullets[j].m_Rect;
            if( res.intersects(enemys[i].m_Rect) )
            {
                m_hero.bullets[j].m_Free = true;
                enemys[i].now_hp -= m_hero.bullets[j].force;
                if( enemys[i].now_hp>0 )    continue;//只有当前血量小于0才执行爆炸效果
                enemys[i].m_Free = true;
                //播放爆炸效果
                for(int k = 0;k<BOMB_NUM;k++ )
                {
                    if( bombs[k].m_Free==false )   continue;
                    bombs[k].m_Free = false;//非空闲
                    //更新爆炸坐标
                    QSound::play(SOUND_BOMB);
                    bombs[k].m_x = enemys[i].m_x;
                    bombs[k].m_y = enemys[i].m_y;
                    break;
                }
                break;
            }
        }
    }
    //查看当前主角飞机是否迟到了特殊子弹
    if( m_hero.m_Rect.intersects(special_bullet.m_rect) )
    {
        for(int j=0;j<BULLET_NUM;j++)//更新所有子弹的威力和图片
        {
            m_hero.bullets[j].m_Bullet = special_bullet.img;
            m_hero.bullets[j].force = special_bullet.force;
        }
        special_bullet.record = 0;//被吃掉
    }
}
