#include <stdio.h>
#include <easyx.h>
#include <conio.h>
#include <Windows.h>
#include <string>

void image_selector(int*);
void image_modifier(int*);
void word_monitor();

void rotator(int* tick) {
	printf("本程序基于C/C++开发，用于快速选择屏幕。\n");
	printf("本程序使用了《原神》表情包及二创图片，完全开源。\n");
	printf("关闭本控制台窗口即可彻底关闭本程序。\n请确保以管理员身份运行，按上键开转...\n");
	int keyDown = 0;
	while (1) {
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (!keyDown) {
				keyDown = 1;
				mouse_event(MOUSEEVENTF_LEFTDOWN, 1920 / 2, 1080 / 2, 0, 0);
				while (GetAsyncKeyState(VK_UP) & 0x8000) {
					mouse_event(MOUSEEVENTF_MOVE, 800, 0, 0, 0);
					image_modifier(tick);
					image_selector(tick);
					Sleep(10); // 每次移动的间隔时间，可以根据需要调整
				}
				printf("开转中...\n");
			}
		}
		else if (keyDown) {
			keyDown = 0;
			//mouse_event(MOUSEEVENTF_LEFTUP, 1920 / 2, 1080 / 2, 0, 0);
			printf("已停转，按上键重新开转...\n");
		}
		Sleep(1);
	}
}

void image_selector(int* tick) {
	IMAGE img;
	std::string path;
	switch (*tick) {
	case 0:
		path = "image//rotator_1.png";
		break;
	case 1:
		path = "image//rotator_2.png";
		break;
	case 2:
		path = "image//rotator_3.png";
		break;
	case 3:
		path = "image//rotator_4.png";
		break;
	case 4:
		path = "image//rotator_5.png";
		break;
	case 5:
		path = "image//rotator_6.png";
		break;
	default:
		*tick = 0;
		path = "image//rotator_1.png";
		break;
	}
	const char* cpath = path.c_str();
	loadimage(&img, cpath);
	putimage((getwidth() - img.getwidth()) / 2, (getheight() - img.getheight()) / 2, &img);
}

void image_modifier(int* tick) {
	*tick = *tick + 1;
}

void word_monitor() {
	std::string words = "请确保以管理员方式运行，长按上键开转...";
	const char* cwords = words.c_str();
	settextstyle(15, 0, "幼圆 常规");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy((getwidth() - textwidth(cwords)) / 2, 0, cwords);
}

int main() {
	initgraph(320, 270);
	setbkcolor(WHITE);
	cleardevice();

	int tick = 0;
	image_selector(&tick);
	word_monitor();

	rotator(&tick);
	//getchar();
	return 0;
}