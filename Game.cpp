#include"Game.h"

//Game类构造函数
Game::Game()
{
    mWindow=nullptr;
    mIsRunning=true;
    mTicksCount=0;
}

//初始化游戏
bool Game::Initialize()
{
    //初始化SDL库
    int sdlResult=SDL_Init(SDL_INIT_VIDEO);
    //检查初始化成功
    if(sdlResult!=0)
    {
        SDL_Log("Error:%s",SDL_GetError());
        return false;
    }
    mWindow=SDL_CreateWindow(
        "test", //窗口标题
        100,    //左上角X坐标
        100,    //左上角Y坐标
        Width,   //窗口宽度
        Height,    //窗口高度
        0);     //标志
    //检查窗口创建成功
    if (!mWindow)
    {
        SDL_Log("Error:%s",SDL_GetError());
        return false;
    }
    //创建渲染器
    mRenderer=SDL_CreateRenderer(
        mWindow,
        -1,
        SDL_RENDERER_ACCELERATED|
        SDL_RENDERER_PRESENTVSYNC);
    //检查渲染器创建成功
    if (!mRenderer)
    {
        SDL_Log("Error:%s",SDL_GetError());
        return false;
    }
    return true;
}

//关闭游戏
void Game::Shoutdown()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

//游戏循环
void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
    
}

//处理输入
void Game::ProcessInput()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
        switch (event.type)
        {
        case SDL_QUIT:
            mIsRunning=false;
            break;
        
        default:
            break;
        }
    const Uint8 *State=SDL_GetKeyboardState(NULL);
    if(State[SDL_SCANCODE_ESCAPE])
        mIsRunning=false;
}

//更新游戏数据
void Game::UpdateGame()
{
    while(!SDL_TICKS_PASSED(SDL_GetTicks(),mTicksCount+16));
    float deltaTime=(SDL_GetTicks()-mTicksCount)/1000.0f;
    if (deltaTime > 0.05f)
		deltaTime = 0.05f;
    mTicksCount=SDL_GetTicks();
}

//生成输出
void Game::GenerateOutput()
{
    //设置黑色颜色清除背景
    SDL_SetRenderDrawColor(
        mRenderer,
        0,  //R
        0,  //G
        0,  //B
        0   //A
    );
    SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);
}