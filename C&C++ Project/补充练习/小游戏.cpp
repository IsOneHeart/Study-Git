#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define GROUND '~'
#define DINO 'G'
#define OBSTACLE_TOP 'H'
#define OBSTACLE_BOTTOM 'H'
#define HP "\u2588"
#define GAME_WIDTH 50
#define GAME_HEIGHT 10
#define OBSTACLE_HEIGHT 3

char game[GAME_HEIGHT][GAME_WIDTH];
int dino_position = GAME_HEIGHT - 1;// 小恐龙横坐标
int jump_height = 0;
int obstacle_position = GAME_WIDTH - 1;// 障碍物生成位置横坐标
int game_over = 0;
int data;


void showWelcomeScreen() {
    FILE* fp;
    if ((fp = fopen("history.dat", "r")) == NULL) {
        printf("文件打开失败！\n");
        exit(0);
    }
    fscanf(fp, "%d", &data);

    system("cls");

    printf("\n\n\n\n\n\n\n\n\n                                                  **********************\n");
    printf("                                                 *      C恐龙小游戏     *\n");
    printf("                                                  **********************\n");
    printf("\n                                                     历史最高分数：%d",data);
    printf("\n\n\n                                                   点击任意键开始游戏...");

    _getch(); // 等待玩家按下任意键开始游戏
    
    if (fclose(fp) != 0) {
        printf("不能正常关闭文件！\n");
        exit(0);
    }
}

void render() {
    system("cls");
    for (int i = 0; i < GAME_HEIGHT; i++) {
        for (int j = 0; j < GAME_WIDTH; j++) {
            if (i == GAME_HEIGHT - 1) {
                game[i][j] = GROUND; // 地面
            }
            else {
                game[i][j] = ' '; // 天空
            }
        }
    }
    game[dino_position][5] = DINO;
    for (int h = 0; h < OBSTACLE_HEIGHT; h++) {
        game[h][obstacle_position] = OBSTACLE_TOP;
    }
    for (int h = GAME_HEIGHT - OBSTACLE_HEIGHT; h < GAME_HEIGHT; h++) {
        game[h][obstacle_position] = OBSTACLE_BOTTOM;
    }
    for (int i = 0; i < GAME_HEIGHT; i++) {
        for (int j = 0; j < GAME_WIDTH; j++) {
            printf("%c", game[i][j]);
        }
        printf("\n");
    }
}

void update(int *health,int *mark) {
    /* 跳跃控制 */
    if (_kbhit()) {
        char key = _getch();
        if (key == ' ' && jump_height == 0 && dino_position == GAME_HEIGHT - 1) {
            jump_height = 6;
        }
    }
    if (jump_height > 0) {
        dino_position--;
        jump_height--;
    }
    else {
        if (dino_position < GAME_HEIGHT - 1) {
            dino_position++;
        }
    }
    
    /* 障碍物生成器 */
    obstacle_position--; // 障碍物移动
    if (obstacle_position == 0) {
        obstacle_position = GAME_WIDTH - 1;// 生成新障碍物
    }

    /* 受伤与死亡判断 */
    if ((obstacle_position == 5 && dino_position < OBSTACLE_HEIGHT) || (obstacle_position == 5 && dino_position >= GAME_HEIGHT - OBSTACLE_HEIGHT)) {
        (*health)--;
        if (*health <= 0) {
            game_over = 1;
        }
        /* 扣分器 */
        if ((*mark) > 0)
            (*mark)--;
    }

    /* 加分器 */
    if ((obstacle_position == 5 && dino_position >= OBSTACLE_HEIGHT) || (obstacle_position == 5 && dino_position < GAME_HEIGHT - OBSTACLE_HEIGHT)) {
        (*mark)++;
    }
}

void hud(int health,int mark) {
    /* 生命值状态栏 */
    printf("【HP】");
    for (int i = 0;i < health;i++) {
        printf(HP);
        printf(" ");
    }

    /* 分数显示器 */
    printf("      【分数】%d",mark);
}

/* 速度控制器 */
void speed(int mark) {
    int SleepTime = 100; // 初始睡眠时间
    if (SleepTime - mark / 2 >= 1)
        Sleep(SleepTime - mark / 2);
}

/* 历史最高分数记录器 */
void history(int mark) {
    FILE* fp;
    if ((fp = fopen("history.dat", "w")) == NULL) {
        printf("文件打开失败！\n");
        exit(0);
    }
    char data = fgetc(fp);
    if (data != EOF) {
        if ((int)data < mark) {
            fputc(mark, fp);
        }
    }
    if (fclose(fp) != 0) {
        printf("不能正常关闭文件！\n");
        exit(0);
    }
}

int main() {
    int health = 3; // 生命值
    int mark = 0; // 分数

    int consoleWidth = 80; // 控制台宽度，可以根据实际情况进行调整

    showWelcomeScreen(); // 显示游戏启动页面

    srand(time(NULL));
    while (!game_over) {
        render();
        update(&health,&mark);
        hud(health,mark);
        speed(mark);
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n                                                          Game Over!\n\n");
    printf("                                                         最终分数：%d", mark);
    if (mark > data) {
        printf("\n                                                         超越历史%d分！", mark - data);
        FILE* fp;
        if ((fp = fopen("history.dat", "w")) == NULL) {
            printf("文件打开失败！\n");
            exit(0);
        }
        fprintf(fp, "%d", mark);
        if (fclose(fp) != 0) {
            printf("不能正常关闭文件！\n");
            exit(0);
        }
    }
    printf("\n\n\n                                                   一段时间后将自动关闭游戏...");

    Sleep(1000 * 60);// 睡眠
    return 0;
}
