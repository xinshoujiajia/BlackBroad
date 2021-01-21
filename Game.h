#ifndef GAME_H
#define GAME_H

#include<SDL2/SDL.h>
#include"vector.h"

const int Width=600;//屏幕宽度
const int Height=400;//屏幕高度

class Game
{
public:

    //Game类构造函数
    Game();

    //初始化游戏
    bool Initialize();

    //游戏循环
    void RunLoop();

    //关闭游戏
    void Shoutdown();
    
private:
    //处理输入
    void ProcessInput();

    //更新游戏数据
    void UpdateGame();

    //生成输出
    void GenerateOutput();

    //游戏主窗口
    SDL_Window *mWindow;

    //游戏是否继续运行
    bool mIsRunning;

    //流逝时间
    Uint32 mTicksCount;

    //渲染器
    SDL_Renderer *mRenderer;
};

#endif
