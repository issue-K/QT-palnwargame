#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <map.h>
#include <heroplane.h>
#include <QMouseEvent>
#include <bullet.h>
#include <enemyplane.h>
#include <bomb.h>
#include <bullettool.h>
namespace Ui {
class MainScene;
}

class MainScene : public QWidget
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();
    //初始化场景
    void initScene();
    //启动游戏
    void playGame();
    //绘制函数
    void paintEvent(QPaintEvent *);
    //每秒需要更新的内容
    void updatePosition();
    //捕捉鼠标移动的函数
    void mouseMoveEvent(QMouseEvent *event);
    //敌机出场
    void enemyToScene();
    //特殊子弹出场
    void specialbulletToScene();
    //碰撞检测
    void collisionDetection();

public:
    //地图对象
    map *m_map;
    //飞机对象
    HeroPlane m_hero;
    //敌机数组
    EnemyPlane enemys[ENEMY_NUM];
    //爆炸类数组
    Bomb bombs[BOMB_NUM];
    //特殊子弹道具
    BulletTool special_bullet;
    //启动游戏更新场景的定时器
    QTimer timer;
    //记录敌机出场的间隔
    int enemy_record;

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
