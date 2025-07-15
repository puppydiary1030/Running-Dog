//#define _CRT_SECURE_NO_WARNINGS
//#include <graphics.h>
//#include <stdio.h>
//#include <assert.h>
//#include <time.h>
//#include <stdlib.h>
//#pragma comment(lib, "MSIMG32.LIB")
//
//// 透明贴图函数
//void putimage_alpha(int x, int y, IMAGE* img) {
//    int w = img->getwidth();
//    int h = img->getheight();
//    AlphaBlend(
//        GetImageHDC(NULL), x, y, w, h,
//        GetImageHDC(img), 0, 0, w, h,
//        { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA }
//    );
//}
//void begin()
//{
//	char beginstring[] = "开始冒险";
//	char closestring[] = "关闭游戏";
//	char tipstring[] = "按下'↑'跳跃，按下'↓'趴下";
//
//	//背景
//	IMAGE img;
//	loadimage(&img, _T("C:\\Users\\28242\\Desktop\\week3 pra\\background.png"), 1200, 800);
//	putimage(0, 0, &img);
//    //三个框/按钮
//	setfillcolor(RGB(0, 162, 232));
//	solidrectangle(400, 300, 700, 380);
//	solidrectangle(400, 450, 700, 530);
//	solidrectangle(300, 600, 1050, 680);
//	//三个按钮上的文字
//	settextcolor(RGB(232, 125, 61));
//	setbkmode(TRANSPARENT);
//	settextstyle(80, 0, _T("Consolas"));
//	outtextxy(400 + 10, 300, beginstring);
//	outtextxy(400 + 10, 450, closestring);
//	outtextxy(300 + 10, 600, tipstring);
//	//鼠标信息
//    bool isHighlighted[2] = { false, false };
//
//    while (true)
//    {
//        MOUSEMSG m = GetMouseMsg();
//        bool needRedraw = false;
//
//        // 检查鼠标在开始区域的操作
//        if (m.x >= 400 && m.x <= 700 && m.y >= 300 && m.y <= 380)
//        {
//            
//            if (GetAsyncKeyState(VK_LBUTTON))
//            {
//                break;
//                //退出当前循环，开始游戏
//            }
//
//        }
//        // 检查鼠标在"关闭"按钮区域的操作
//        else if (m.x >= 400 && m.x <= 700 && m.y >= 450 && m.y <= 530)
//        {
//            if (m.uMsg == WM_LBUTTONDOWN)
//            {
//                exit(0);
//                //点击关闭游戏，退出游戏
//            }
//        }
//  
//    }
//
//}
////加载资源
//IMAGE fly[10];
//IMAGE jump;
//IMAGE fall[8];
//IMAGE back2;
//HWND hwnd = NULL;
//struct Bricks
//{
//    int x, y, width, height;
//};
//struct Node
//{
//    struct Bricks* p8;
//    struct Node* next;
//};
//struct Node* list = NULL;
//
//
////障碍物
//
////创建障碍物
//struct Bricks* createBricks(int x, int y, int width, int height)
//{
//	struct Bricks* p8 = (struct Bricks*)malloc(sizeof(struct Bricks));
//    assert(p8);
//    p8->x = x;
//    p8->y = y;
//    p8->width = width;
//    p8->height = height;
//    return p8;
//}
//int Timer(time_t num, int id)
//{
//    static time_t start[10];
//    time_t end=clock();
//    if (end - start[id] >= num)
//    {
//        start[id] = end;
//        return 1;
//    }
//    return 0;
//}
//
//
////绘制障碍物
//void drawBricks(struct Bricks* p8)
//{
//    setfillcolor(RED);
//    fillrectangle(p8->x, p8->y, p8->x + p8->width, p8->y + p8->height);
//}
////移动障碍物
//void moveBricks(struct Bricks* p8)
//{
//    p8->x -= 20;
//    if (p8->x < -p8->width) // 如果障碍物移出屏幕，则重置位置
//    {
//        p8->x = 1200; // 重置到屏幕右侧
//        p8->y = rand() % 600; // 随机高度
//    }
//}
//
//
//struct Node* createList()
//{
//	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
//    assert(headNode);
//    headNode->p8 = NULL;
//    headNode->next = NULL;
//	return headNode;
//}
//struct Node* createNode(struct Bricks* p8)
//{
//    struct Node* node = (struct Node*)malloc(sizeof(struct Node));  
//    assert(node);
//    node->p8 = p8;
//    node->next = NULL;
//    return node;
//}
//void insertNode(struct Node* headNode, struct Bricks*p8)
//{ 
//    struct Node* newNode = createNode(p8);
//    newNode->next = headNode->next;
//    headNode->next = newNode;
//}
//void printList(struct Node* headNode)
//{
//    struct Node* current = headNode->next;
//    while (current != NULL)
//    {
//        printf("Bricks at (%d, %d) with size (%d, %d)\n", current->p8->x, current->p8->y, current->p8->width, current->p8->height);
//        current = current->next;
//    }
//}
////检测碰撞
//int hitBricks(int x, int y, int width, int height, struct Node* list)
//{
//    struct Node*current=list->next;
//    while (current != NULL)
//    {
//        if (current->p8->x >= (x - current->p8->width) && current->p8->x <= (x + width))
//        {
//            if (current->p8->y >= y-current->p8->height && current->p8->y <= (y + height))
//            {
//				return 1; // 碰撞发生
//            }
//        }
//		current = current->next;
//    }
//	return 0; // 没有碰撞
//}
//
//
////加载资源
//void loading() {
//    // 加载图片时保留Alpha通道
//    loadimage(&jump, _T("C:\\Users\\28242\\Desktop\\week3 pra\\jump.png"), 0, 0, true);
//    loadimage(&back2, _T("C:\\Users\\28242\\Desktop\\week3 pra\\back2.png"), 1200, 750);
//
//    for (int i = 0; i < 10; i++) {
//        char filename[200];
//        sprintf(filename, "C:\\Users\\28242\\Desktop\\week3 pra\\fly%d.png", i + 1);
//        loadimage(&fly[i], _T(filename), 0, 0, true); // 注意最后一个参数为true
//    }
//
//    for (int i = 0; i < 8; i++) {
//        char filename[200];
//        sprintf(filename, "C:\\Users\\28242\\Desktop\\week3 pra\\fall%d.png", i + 1);
//        loadimage(&fall[i], _T(filename), 0, 0, true); // 注意最后一个参数为true
//    }
//}
//
////小狗移动的动作
//// 使用双缓冲和预加载的改进版本
//void moving(int fnum)
//{
//    BeginBatchDraw();
//
//    // 创建内存缓冲区
//    IMAGE buffer;
//    buffer.Resize(1200, 800);
//
//    int i = 0;
//    while (true)  // 或者使用适当的退出条件
//    {
//        // 开始在缓冲上绘制
//        SetWorkingImage(&buffer);
//        cleardevice();
//        putimage(0, 0, &back2);
//        setfillcolor(RGB(0, 162, 232));
//        solidrectangle(0, 750, 1200, 800);
//        putimage_alpha(100, 600, &fly[i]);
//
//        // 切换回主画面并绘制缓冲内容
//        SetWorkingImage(NULL);
//        putimage(0, 0, &buffer);
//        if (hitBricks(100, 600, 150, 100,list))
//        {
//			MessageBox(hwnd, "小狗撞到障碍物了！", "提示", MB_OK | MB_ICONWARNING);
//            exit(0);//结束游戏
//
//        }
//
//        // 更新帧索引
//        i = (i + 1) % fnum;  // 使用模运算实现循环
//
//
//        printList(list);
//        // 控制帧率
//        static DWORD lastTime = GetTickCount();
//        DWORD currentTime = GetTickCount();
//        DWORD deltaTime = currentTime - lastTime;
//
//        // 确保每帧至少间隔100ms，但不超过120ms
//        if (deltaTime < 100)
//        {
//            Sleep(100 - deltaTime);
//        }
//        lastTime = GetTickCount();
//		FlushBatchDraw(); // 刷新批量绘图
//    }
//	EndBatchDraw(); // 结束批量绘图
//}
////趴下的动作
//void falling(int fnumber)
//{ 
//
//    BeginBatchDraw();
//    // 创建内存缓冲区
//    IMAGE buffer;
//    buffer.Resize(1200, 800);
//
//    int i = 0;
//    while (true)  // 或者使用适当的退出条件
//    {
//        // 开始在缓冲上绘制
//        SetWorkingImage(&buffer);
//        cleardevice();
//        putimage_alpha(100, 700, &fall[i]);
//
//        // 切换回主画面并绘制缓冲内容
//        SetWorkingImage(NULL);
//        putimage(0, 0, &buffer);
//
//        // 更新帧索引
//        i = (i + 1) % fnumber;  // 使用模运算实现循环
//        printList(list);
//        // 控制帧率
//        static DWORD lastTime = GetTickCount();
//        DWORD currentTime = GetTickCount();
//        DWORD deltaTime = currentTime - lastTime;
//
//        // 确保每帧至少间隔100ms，但不超过120ms
//        if (deltaTime < 100)
//        {
//            Sleep(100 - deltaTime);
//        }
//        lastTime = GetTickCount();
//        FlushBatchDraw();
//    }
//	EndBatchDraw(); // 结束批量绘图
//}
////跳跃的动作
//void jumping()
//{
//    BeginBatchDraw();
//    int y = 600;
//    for (int i = 0; i < 6; i++)
//    {
//        cleardevice();
//        rectangle(0, 750, 1200, 800);
//        putimage_alpha(100, y, &jump);
//        y -= 30;
//        printList(list);
//        Sleep(100);
//    }
//    for (int i = 0; i < 6; i++)
//    {
//        cleardevice();
//        rectangle(0, 750, 1200, 800);
//        putimage_alpha(100, y, &jump);
//        y += 30;
//        printList(list);
//        Sleep(100);
//        FlushBatchDraw();
//    }
//	EndBatchDraw(); // 结束批量绘图
//}
////按键反馈
//void keyDown()
//{ 
//    if (GetAsyncKeyState('w')||GetAsyncKeyState(VK_UP))
//    {
//        jumping();
//    }
//    if(GetAsyncKeyState('a')||GetAsyncKeyState(VK_DOWN))
//    {
//        falling(8);
//	}
//    if (GetAsyncKeyState(VK_ESCAPE))
//    {
//        exit(0);
//    }
//}   
//
//int main()
//
//{
//
//    list = createList();
//	srand((unsigned int)time(NULL)); // 初始化随机数种子
//    loading();
//	hwnd=initgraph(1200, 800);
//    cleardevice();
//    begin();//如果点击开始冒险则往下运行
//   
//	
//    while (1)
//    {
//        moving(10);
//        keyDown();
//        if (Timer(1000, 0))
//        {
//			insertNode(list, createBricks(1200, rand() % 600, 100, 50));
//        }
//    }
//   
//	
//
//   
//
//	closegraph();
//	return 0;
//
//}
#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>
#include <windows.h>  
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "MSIMG32.LIB")
#pragma comment(lib, "winmm.lib")


// 高精度计时器
int Timer(DWORD interval, int id) {
    static DWORD lastTime[10] = { 0 }; 
    DWORD currentTime = GetTickCount();  

    // 检查是否达到时间间隔
    if (currentTime - lastTime[id] >= interval) {
        lastTime[id] = currentTime;  // 重置计时起点
        return 1;  // 触发信号
    }
    return 0;  // 未触发
}


// 游戏状态
enum GameState {
    RUNNING,
    JUMPING,
    FALLING
};


IMAGE fly[10];
IMAGE jump;
IMAGE fall[8];
IMAGE back2;
HWND hwnd = NULL;

// 障碍物
struct Bricks {
    int x, y, width, height;
};

struct Node {
    struct Bricks* p8;
    struct Node* next;
};

struct Node* list = NULL;
GameState currentState = RUNNING;
int currentFrame = 0;
int dogY = 550; // 小狗的Y坐标
int jumpStep = 0; // 跳跃步数
// 透明贴图函数
void putimage_alpha(int x, int y, IMAGE* img) {
    int w = img->getwidth();
    int h = img->getheight();
    AlphaBlend(
        GetImageHDC(NULL), x, y, w, h,
        GetImageHDC(img), 0, 0, w, h,
        { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA }
    );
}
// 开始界面
void begin() {
    char beginstring[] = "开始冒险";
    char closestring[] = "关闭游戏";
    char tipstring[] = "按下'↑'跳跃，长按'↓'趴下";

    // 背景
    IMAGE img;
    loadimage(&img, _T("background.png"), 1200, 800);
    putimage(0, 0, &img);

    // 三个框/按钮
    setfillcolor(RGB(0, 162, 232));
    solidrectangle(400, 300, 700, 380);
    solidrectangle(400, 450, 700, 530);
    solidrectangle(200, 600, 1100, 680);

    // 按钮上的文字
    settextcolor(RGB(232, 125, 61));
    setbkmode(TRANSPARENT);
    settextstyle(80, 0, _T("Consolas"));
    outtextxy(400 + 10, 300, beginstring);
    outtextxy(400 + 10, 450, closestring);
    outtextxy(200 + 10, 600, tipstring);

    while (true) {
        MOUSEMSG m = GetMouseMsg();

        // 检查鼠标在开始区域的操作
        if (m.x >= 400 && m.x <= 700 && m.y >= 300 && m.y <= 380) {
            if (m.uMsg == WM_LBUTTONDOWN) {
                break; // 退出当前循环，开始游戏
            }
        }
        // 检查鼠标在"关闭"按钮区域的操作
        else if (m.x >= 400 && m.x <= 700 && m.y >= 450 && m.y <= 530) {
            if (m.uMsg == WM_LBUTTONDOWN) {
                exit(0); // 点击关闭游戏，退出游戏
            }
        }
    }
}

// 创建障碍物
struct Bricks* createBricks(int x, int y, int width, int height) {
    struct Bricks* p8 = (struct Bricks*)malloc(sizeof(struct Bricks));
    assert(p8);
    p8->x = x;
    p8->y = y;
    p8->width = width;
    p8->height = height;
    return p8;
}

// 移动障碍物并返回是否需要删除
int moveAndCheckBricks(struct Bricks* p8) {
    p8->x -= 50;
    return (p8->x < -p8->width); // 返回1表示需要删除
}

// 绘制障碍物
void drawBricks(struct Bricks* p8) {
    setfillcolor(RGB(120, 67, 21));
    fillrectangle(p8->x, p8->y, p8->x + p8->width, p8->y + p8->height);
}

// 更新障碍物链表
void updateObstacles(struct Node* headNode) {
    struct Node* current = headNode->next;
    struct Node* prev = headNode;

    while (current != NULL) {
        if (moveAndCheckBricks(current->p8)) {
            // 需要删除当前节点
            struct Node* toDelete = current;
            prev->next = current->next;
            current = current->next;

            free(toDelete->p8);
            free(toDelete);
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

// 创建链表
struct Node* createList() {
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    assert(headNode);
    headNode->p8 = NULL;
    headNode->next = NULL;
    return headNode;
}

// 创建节点
struct Node* createNode(struct Bricks* p8) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    assert(node);
    node->p8 = p8;
    node->next = NULL;
    return node;
}

// 插入节点
void insertNode(struct Node* headNode, struct Bricks* p8) {
    struct Node* newNode = createNode(p8);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

// 打印链表
void printList(struct Node* headNode) {
    struct Node* current = headNode->next;
    while (current != NULL) {
        printf("Bricks at (%d, %d) with size (%d, %d)\n",
            current->p8->x, current->p8->y,
            current->p8->width, current->p8->height);
        current = current->next;
    }
}

// 释放整个链表
void freeList(struct Node* headNode) {
    struct Node* current = headNode->next;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current->p8);
        free(current);
        current = next;
    }
    free(headNode);
}
// 检测碰撞
int hitBricks(int x, int y, int width, int height, struct Node* list) {
    // 缩小碰撞检测范围
    int shrinkWidth = width * 0.8;
    int shrinkHeight = height * 0.8; 
    int offsetX = (width - shrinkWidth) / 2; // 居中偏移
    int offsetY = (height - shrinkHeight) / 2;

    struct Node* current = list->next;
    while (current != NULL) {
        if (x + offsetX < current->p8->x + current->p8->width &&
            x + offsetX + shrinkWidth > current->p8->x &&
            y + offsetY < current->p8->y + current->p8->height &&
            y + offsetY + shrinkHeight > current->p8->y) {
            return 1; // 碰撞发生
        }
        current = current->next;
    }
    return 0; // 没有碰撞
}

// 加载资源
void loading() {
    // 加载图片时保留Alpha通道
    loadimage(&jump, _T("jump.png"), 100, 100, true);
    loadimage(&back2, _T("back2.png"), 1200, 750);

    for (int i = 0; i < 9; i++) {
        char filename[200];
        sprintf(filename, "fly%d.png", i + 1);
        loadimage(&fly[i], _T(filename), 150, 100, true); 
    }

    for (int i = 0; i < 3; i++) {
        char filename[200];
        sprintf(filename, "fall%d.png", i + 1);
        loadimage(&fall[i], _T(filename),150, 100, true); 
    }
}

// 更新游戏状态
void updateGame() {
    // 处理键盘输入
    if (GetAsyncKeyState(VK_UP) & 0x8000) {  // 检测上箭头键
        if (currentState == RUNNING) {
            currentState = JUMPING;
            jumpStep = 0;
        }
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {  // 检测下箭头键
        if (currentState == RUNNING) {
            currentState = FALLING;
        }
    }
    else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {  // 检测ESC键
        exit(0);
    }

    // 更新状态
    switch (currentState) {
    case RUNNING:
        currentFrame = (currentFrame + 1) % 9;
        break;

    case JUMPING:
        if (jumpStep < 4) {
            dogY -= 50; // 上升
        }
        else if (jumpStep < 8) {
            dogY += 50; // 下降
        }
        else {
            currentState = RUNNING;
            dogY = 600;
        }
        jumpStep++;
        break;

    case FALLING:
        currentFrame = (currentFrame + 1) % 3;
       
        if (!(GetAsyncKeyState(VK_DOWN) & 0x8000) && !(GetAsyncKeyState('S') & 0x8000)) {
            currentState = RUNNING;
            dogY = 550; // 重置Y坐标
        }
        break;
    }

    // 移动障碍物
    struct Node* current = list->next;
    while (current != NULL) {
        moveAndCheckBricks(current->p8);
        current = current->next;
    }

    // 检测碰撞
    if (currentState == RUNNING || currentState == JUMPING) {
        if (hitBricks(50, dogY + 50, 150, 100, list)) {
            MessageBox(hwnd, "小狗撞到障碍物了！", "游戏结束", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
}

// 渲染游戏
void renderGame() {
    BeginBatchDraw();
    cleardevice();

    // 绘制背景
    putimage(0, 0, &back2);
    setfillcolor(RGB(0, 162, 232));
    solidrectangle(0, 750, 1200, 800);

    // 绘制障碍物
    struct Node* current = list->next;
    while (current != NULL) {
        drawBricks(current->p8);
        current = current->next;
    }

    // 绘制小狗（使用透明贴图）
    switch (currentState) {
    case RUNNING:
        putimage_alpha(100, dogY, &fly[currentFrame]);
        break;
    case JUMPING:
        putimage_alpha(120, dogY, &jump);
        break;
    case FALLING:
        putimage_alpha(100, 650, &fall[currentFrame]);
        break;
    }

    EndBatchDraw();
}

int main() {
    list = createList();
    srand((unsigned int)time(NULL));
    loading();
    hwnd = initgraph(1200, 800);
    PlaySound(_T(".\\audio\\bg.wav"), NULL, SND_LOOP | SND_ASYNC);

   
    SetWindowText(GetHWnd(), _T("线条小狗跑酷"));
    cleardevice();
    begin(); // 开始界面
    

    const int fixedYPositions[] = { 400, 500, 650,600,700 };
  
    // 主游戏循环
    while (1) {
        // 随机生成障碍物
        if (Timer(1000, 0)) 
        {
            int randomIndex = rand() % 5;
            int fixedY = fixedYPositions[randomIndex];
            insertNode(list, createBricks(1200, fixedY, 30, 20));
        }
        updateObstacles(list);// 更新障碍物位置
        updateGame();
        renderGame();// 渲染游戏
        Sleep(50); 
    }

    closegraph();
    return 0;
}



