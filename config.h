#ifndef CONFIG_H
#define CONFIG_H

//游戏配置数据
#define GAME_WIDTH 512
#define GAME_HEIGHT 768
#define GAME_TITLE "飞机大战1.0"
#define GAME_RES_PATH "./plane.rcc"
#define GAME_RATE 10 //地图滚动刷新率

//地图配置数据
#define MAP_SCROLL_SPEED 2//地图滚动速度
//英雄配置信息
#define HERO_PATH ":/res/hero.png"
#define BOSS_PATH ":/extra/BOSS.png"
//子弹配置信息
#define BULLET_PATH ":/res/bullet_11.png"
#define BULLET_SPEED 5//子弹移动速度
//特殊子弹
#define SPECIALBULLET_PATH ":/res/bullet_14.png"

#define BULLET_NUM 30 //弹夹的子弹容量
#define BULLET_INTERVAL 20 //发射子弹的时间间隔

//敌机配置信息
#define ENEMY_PATH ":/res/img-plane_%1.png"
#define ENEMY_NUM 20 //敌机数量
#define ENEMY_SPEED 4 //敌机速度
#define ENEMY_INTERVAL 50 //敌机出场间隔

//爆炸配置数据
#define BOMB_PATH ":/res/bomb-%1.png"
#define BOMB_NUM 20//爆炸类的数量
#define BOMB_MAX 7 //爆炸图片最大索引
#define BOMB_INTERVAL 20 //爆炸切图时间间隔
//音效资源
#define SOUND_BACKGROUND ":/res/bg.wav"
#define SOUND_BOMB ":/res/bomb.wav"
#endif // CONFIG_H
