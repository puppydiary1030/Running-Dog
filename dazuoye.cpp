//#define _CRT_SECURE_NO_WARNINGS
//#include <graphics.h>
//#include <stdio.h>
//#include <assert.h>
//#include <time.h>
//#include <stdlib.h>
//#pragma comment(lib, "MSIMG32.LIB")
//
//// ͸����ͼ����
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
//	char beginstring[] = "��ʼð��";
//	char closestring[] = "�ر���Ϸ";
//	char tipstring[] = "����'��'��Ծ������'��'ſ��";
//
//	//����
//	IMAGE img;
//	loadimage(&img, _T("C:\\Users\\28242\\Desktop\\week3 pra\\background.png"), 1200, 800);
//	putimage(0, 0, &img);
//    //������/��ť
//	setfillcolor(RGB(0, 162, 232));
//	solidrectangle(400, 300, 700, 380);
//	solidrectangle(400, 450, 700, 530);
//	solidrectangle(300, 600, 1050, 680);
//	//������ť�ϵ�����
//	settextcolor(RGB(232, 125, 61));
//	setbkmode(TRANSPARENT);
//	settextstyle(80, 0, _T("Consolas"));
//	outtextxy(400 + 10, 300, beginstring);
//	outtextxy(400 + 10, 450, closestring);
//	outtextxy(300 + 10, 600, tipstring);
//	//�����Ϣ
//    bool isHighlighted[2] = { false, false };
//
//    while (true)
//    {
//        MOUSEMSG m = GetMouseMsg();
//        bool needRedraw = false;
//
//        // �������ڿ�ʼ����Ĳ���
//        if (m.x >= 400 && m.x <= 700 && m.y >= 300 && m.y <= 380)
//        {
//            
//            if (GetAsyncKeyState(VK_LBUTTON))
//            {
//                break;
//                //�˳���ǰѭ������ʼ��Ϸ
//            }
//
//        }
//        // ��������"�ر�"��ť����Ĳ���
//        else if (m.x >= 400 && m.x <= 700 && m.y >= 450 && m.y <= 530)
//        {
//            if (m.uMsg == WM_LBUTTONDOWN)
//            {
//                exit(0);
//                //����ر���Ϸ���˳���Ϸ
//            }
//        }
//  
//    }
//
//}
////������Դ
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
////�ϰ���
//
////�����ϰ���
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
////�����ϰ���
//void drawBricks(struct Bricks* p8)
//{
//    setfillcolor(RED);
//    fillrectangle(p8->x, p8->y, p8->x + p8->width, p8->y + p8->height);
//}
////�ƶ��ϰ���
//void moveBricks(struct Bricks* p8)
//{
//    p8->x -= 20;
//    if (p8->x < -p8->width) // ����ϰ����Ƴ���Ļ��������λ��
//    {
//        p8->x = 1200; // ���õ���Ļ�Ҳ�
//        p8->y = rand() % 600; // ����߶�
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
////�����ײ
//int hitBricks(int x, int y, int width, int height, struct Node* list)
//{
//    struct Node*current=list->next;
//    while (current != NULL)
//    {
//        if (current->p8->x >= (x - current->p8->width) && current->p8->x <= (x + width))
//        {
//            if (current->p8->y >= y-current->p8->height && current->p8->y <= (y + height))
//            {
//				return 1; // ��ײ����
//            }
//        }
//		current = current->next;
//    }
//	return 0; // û����ײ
//}
//
//
////������Դ
//void loading() {
//    // ����ͼƬʱ����Alphaͨ��
//    loadimage(&jump, _T("C:\\Users\\28242\\Desktop\\week3 pra\\jump.png"), 0, 0, true);
//    loadimage(&back2, _T("C:\\Users\\28242\\Desktop\\week3 pra\\back2.png"), 1200, 750);
//
//    for (int i = 0; i < 10; i++) {
//        char filename[200];
//        sprintf(filename, "C:\\Users\\28242\\Desktop\\week3 pra\\fly%d.png", i + 1);
//        loadimage(&fly[i], _T(filename), 0, 0, true); // ע�����һ������Ϊtrue
//    }
//
//    for (int i = 0; i < 8; i++) {
//        char filename[200];
//        sprintf(filename, "C:\\Users\\28242\\Desktop\\week3 pra\\fall%d.png", i + 1);
//        loadimage(&fall[i], _T(filename), 0, 0, true); // ע�����һ������Ϊtrue
//    }
//}
//
////С���ƶ��Ķ���
//// ʹ��˫�����Ԥ���صĸĽ��汾
//void moving(int fnum)
//{
//    BeginBatchDraw();
//
//    // �����ڴ滺����
//    IMAGE buffer;
//    buffer.Resize(1200, 800);
//
//    int i = 0;
//    while (true)  // ����ʹ���ʵ����˳�����
//    {
//        // ��ʼ�ڻ����ϻ���
//        SetWorkingImage(&buffer);
//        cleardevice();
//        putimage(0, 0, &back2);
//        setfillcolor(RGB(0, 162, 232));
//        solidrectangle(0, 750, 1200, 800);
//        putimage_alpha(100, 600, &fly[i]);
//
//        // �л��������沢���ƻ�������
//        SetWorkingImage(NULL);
//        putimage(0, 0, &buffer);
//        if (hitBricks(100, 600, 150, 100,list))
//        {
//			MessageBox(hwnd, "С��ײ���ϰ����ˣ�", "��ʾ", MB_OK | MB_ICONWARNING);
//            exit(0);//������Ϸ
//
//        }
//
//        // ����֡����
//        i = (i + 1) % fnum;  // ʹ��ģ����ʵ��ѭ��
//
//
//        printList(list);
//        // ����֡��
//        static DWORD lastTime = GetTickCount();
//        DWORD currentTime = GetTickCount();
//        DWORD deltaTime = currentTime - lastTime;
//
//        // ȷ��ÿ֡���ټ��100ms����������120ms
//        if (deltaTime < 100)
//        {
//            Sleep(100 - deltaTime);
//        }
//        lastTime = GetTickCount();
//		FlushBatchDraw(); // ˢ��������ͼ
//    }
//	EndBatchDraw(); // ����������ͼ
//}
////ſ�µĶ���
//void falling(int fnumber)
//{ 
//
//    BeginBatchDraw();
//    // �����ڴ滺����
//    IMAGE buffer;
//    buffer.Resize(1200, 800);
//
//    int i = 0;
//    while (true)  // ����ʹ���ʵ����˳�����
//    {
//        // ��ʼ�ڻ����ϻ���
//        SetWorkingImage(&buffer);
//        cleardevice();
//        putimage_alpha(100, 700, &fall[i]);
//
//        // �л��������沢���ƻ�������
//        SetWorkingImage(NULL);
//        putimage(0, 0, &buffer);
//
//        // ����֡����
//        i = (i + 1) % fnumber;  // ʹ��ģ����ʵ��ѭ��
//        printList(list);
//        // ����֡��
//        static DWORD lastTime = GetTickCount();
//        DWORD currentTime = GetTickCount();
//        DWORD deltaTime = currentTime - lastTime;
//
//        // ȷ��ÿ֡���ټ��100ms����������120ms
//        if (deltaTime < 100)
//        {
//            Sleep(100 - deltaTime);
//        }
//        lastTime = GetTickCount();
//        FlushBatchDraw();
//    }
//	EndBatchDraw(); // ����������ͼ
//}
////��Ծ�Ķ���
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
//	EndBatchDraw(); // ����������ͼ
//}
////��������
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
//	srand((unsigned int)time(NULL)); // ��ʼ�����������
//    loading();
//	hwnd=initgraph(1200, 800);
//    cleardevice();
//    begin();//��������ʼð������������
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


// �߾��ȼ�ʱ��
int Timer(DWORD interval, int id) {
    static DWORD lastTime[10] = { 0 }; 
    DWORD currentTime = GetTickCount();  

    // ����Ƿ�ﵽʱ����
    if (currentTime - lastTime[id] >= interval) {
        lastTime[id] = currentTime;  // ���ü�ʱ���
        return 1;  // �����ź�
    }
    return 0;  // δ����
}


// ��Ϸ״̬
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

// �ϰ���
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
int dogY = 550; // С����Y����
int jumpStep = 0; // ��Ծ����
// ͸����ͼ����
void putimage_alpha(int x, int y, IMAGE* img) {
    int w = img->getwidth();
    int h = img->getheight();
    AlphaBlend(
        GetImageHDC(NULL), x, y, w, h,
        GetImageHDC(img), 0, 0, w, h,
        { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA }
    );
}
// ��ʼ����
void begin() {
    char beginstring[] = "��ʼð��";
    char closestring[] = "�ر���Ϸ";
    char tipstring[] = "����'��'��Ծ������'��'ſ��";

    // ����
    IMAGE img;
    loadimage(&img, _T("background.png"), 1200, 800);
    putimage(0, 0, &img);

    // ������/��ť
    setfillcolor(RGB(0, 162, 232));
    solidrectangle(400, 300, 700, 380);
    solidrectangle(400, 450, 700, 530);
    solidrectangle(200, 600, 1100, 680);

    // ��ť�ϵ�����
    settextcolor(RGB(232, 125, 61));
    setbkmode(TRANSPARENT);
    settextstyle(80, 0, _T("Consolas"));
    outtextxy(400 + 10, 300, beginstring);
    outtextxy(400 + 10, 450, closestring);
    outtextxy(200 + 10, 600, tipstring);

    while (true) {
        MOUSEMSG m = GetMouseMsg();

        // �������ڿ�ʼ����Ĳ���
        if (m.x >= 400 && m.x <= 700 && m.y >= 300 && m.y <= 380) {
            if (m.uMsg == WM_LBUTTONDOWN) {
                break; // �˳���ǰѭ������ʼ��Ϸ
            }
        }
        // ��������"�ر�"��ť����Ĳ���
        else if (m.x >= 400 && m.x <= 700 && m.y >= 450 && m.y <= 530) {
            if (m.uMsg == WM_LBUTTONDOWN) {
                exit(0); // ����ر���Ϸ���˳���Ϸ
            }
        }
    }
}

// �����ϰ���
struct Bricks* createBricks(int x, int y, int width, int height) {
    struct Bricks* p8 = (struct Bricks*)malloc(sizeof(struct Bricks));
    assert(p8);
    p8->x = x;
    p8->y = y;
    p8->width = width;
    p8->height = height;
    return p8;
}

// �ƶ��ϰ��ﲢ�����Ƿ���Ҫɾ��
int moveAndCheckBricks(struct Bricks* p8) {
    p8->x -= 50;
    return (p8->x < -p8->width); // ����1��ʾ��Ҫɾ��
}

// �����ϰ���
void drawBricks(struct Bricks* p8) {
    setfillcolor(RGB(120, 67, 21));
    fillrectangle(p8->x, p8->y, p8->x + p8->width, p8->y + p8->height);
}

// �����ϰ�������
void updateObstacles(struct Node* headNode) {
    struct Node* current = headNode->next;
    struct Node* prev = headNode;

    while (current != NULL) {
        if (moveAndCheckBricks(current->p8)) {
            // ��Ҫɾ����ǰ�ڵ�
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

// ��������
struct Node* createList() {
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    assert(headNode);
    headNode->p8 = NULL;
    headNode->next = NULL;
    return headNode;
}

// �����ڵ�
struct Node* createNode(struct Bricks* p8) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    assert(node);
    node->p8 = p8;
    node->next = NULL;
    return node;
}

// ����ڵ�
void insertNode(struct Node* headNode, struct Bricks* p8) {
    struct Node* newNode = createNode(p8);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

// ��ӡ����
void printList(struct Node* headNode) {
    struct Node* current = headNode->next;
    while (current != NULL) {
        printf("Bricks at (%d, %d) with size (%d, %d)\n",
            current->p8->x, current->p8->y,
            current->p8->width, current->p8->height);
        current = current->next;
    }
}

// �ͷ���������
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
// �����ײ
int hitBricks(int x, int y, int width, int height, struct Node* list) {
    // ��С��ײ��ⷶΧ
    int shrinkWidth = width * 0.8;
    int shrinkHeight = height * 0.8; 
    int offsetX = (width - shrinkWidth) / 2; // ����ƫ��
    int offsetY = (height - shrinkHeight) / 2;

    struct Node* current = list->next;
    while (current != NULL) {
        if (x + offsetX < current->p8->x + current->p8->width &&
            x + offsetX + shrinkWidth > current->p8->x &&
            y + offsetY < current->p8->y + current->p8->height &&
            y + offsetY + shrinkHeight > current->p8->y) {
            return 1; // ��ײ����
        }
        current = current->next;
    }
    return 0; // û����ײ
}

// ������Դ
void loading() {
    // ����ͼƬʱ����Alphaͨ��
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

// ������Ϸ״̬
void updateGame() {
    // �����������
    if (GetAsyncKeyState(VK_UP) & 0x8000) {  // ����ϼ�ͷ��
        if (currentState == RUNNING) {
            currentState = JUMPING;
            jumpStep = 0;
        }
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {  // ����¼�ͷ��
        if (currentState == RUNNING) {
            currentState = FALLING;
        }
    }
    else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {  // ���ESC��
        exit(0);
    }

    // ����״̬
    switch (currentState) {
    case RUNNING:
        currentFrame = (currentFrame + 1) % 9;
        break;

    case JUMPING:
        if (jumpStep < 4) {
            dogY -= 50; // ����
        }
        else if (jumpStep < 8) {
            dogY += 50; // �½�
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
            dogY = 550; // ����Y����
        }
        break;
    }

    // �ƶ��ϰ���
    struct Node* current = list->next;
    while (current != NULL) {
        moveAndCheckBricks(current->p8);
        current = current->next;
    }

    // �����ײ
    if (currentState == RUNNING || currentState == JUMPING) {
        if (hitBricks(50, dogY + 50, 150, 100, list)) {
            MessageBox(hwnd, "С��ײ���ϰ����ˣ�", "��Ϸ����", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
}

// ��Ⱦ��Ϸ
void renderGame() {
    BeginBatchDraw();
    cleardevice();

    // ���Ʊ���
    putimage(0, 0, &back2);
    setfillcolor(RGB(0, 162, 232));
    solidrectangle(0, 750, 1200, 800);

    // �����ϰ���
    struct Node* current = list->next;
    while (current != NULL) {
        drawBricks(current->p8);
        current = current->next;
    }

    // ����С����ʹ��͸����ͼ��
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

   
    SetWindowText(GetHWnd(), _T("����С���ܿ�"));
    cleardevice();
    begin(); // ��ʼ����
    

    const int fixedYPositions[] = { 400, 500, 650,600,700 };
  
    // ����Ϸѭ��
    while (1) {
        // ��������ϰ���
        if (Timer(1000, 0)) 
        {
            int randomIndex = rand() % 5;
            int fixedY = fixedYPositions[randomIndex];
            insertNode(list, createBricks(1200, fixedY, 30, 20));
        }
        updateObstacles(list);// �����ϰ���λ��
        updateGame();
        renderGame();// ��Ⱦ��Ϸ
        Sleep(50); 
    }

    closegraph();
    return 0;
}



