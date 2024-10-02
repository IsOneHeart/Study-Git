#include <stdio.h>
#include <easyx.h>
//#include <graphics.h>
#include <conio.h>
#undef UNICODE
#undef _UNICODE

ExMessage msg = { 0 }; // 消息结构体

void draw() {
	putpixel(50, 50, RED); // 绘点
	setlinecolor(BLACK); // 设置线条颜色
	setlinestyle(PS_SOLID, 2); // 设置线条样式
	line(0, 0, getwidth(), getheight()); // 绘线
	setlinestyle(PS_SOLID, 1);
	rectangle(100, 0, 100 + 50, 0 + 30); // 矩形框
	setfillcolor(GREEN); // 设置填充颜色
	fillrectangle(200, 100, 200 + 50, 100 + 30); // 填充矩形
	solidrectangle(100, 300, 100 + 50, 300 + 50); // 无框填充矩形
	roundrect(300, 300, 300 + 50, 300 + 30, 10, 10); // 圆角矩形
	fillroundrect(100, 200, 100 + 50, 200 + 30, 20, 20);
	solidroundrect(50, 300, 50 + 50, 300 + 50, 30, 30);
	circle(20, 20, 20); // 圆形
	setfillcolor(RGB(128, 213, 221));
	fillcircle(40, 40, 20);
	solidcircle(60, 60, 20);
	ellipse(400, 300, 500, 450); //椭圆
	fillellipse(200, 200, 300, 400);
	solidellipse(0, 500, 50, 400);
	POINT points[]{ {30,40},{60,70},{10,50} };
	polyline(points, 4); // 折线
}

void text() {
	printf("Hello EasyX!");
	settextstyle(42, 0, (LPCTSTR)"微软雅黑");
	settextcolor(RED);
	setbkmode(TRANSPARENT); // 文字透明背景
	outtextxy(210, 240, _T("Hello EasyX!"));
	int score = 21;
	char score_c[10];
	sprintf_s(score_c, "分数：%d", score);
	settextstyle(30, 0, "方正舒体 常规");
	outtextxy(210, 300, score_c);
}

bool inArea(int mx, int my, int x, int y, int w, int h) {
	if (mx > x && mx < x + w && my > y && my < y + h) {
		return true;
	}
	return false;
}

bool CreateButton(int x, int y, const char* desp) {
	int gx = 800, gy = 600;
	int width = 150, height = 45;
	int textWidth = textwidth(desp);
	int textHeight = textheight(desp);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT); // 文字透明背景
	if (inArea(msg.x, msg.y, x, y, x + width, y + height)) {
		setfillcolor(RGB(123, 190, 238));
	}
	else {
		setfillcolor(RGB(210, 232, 248));
	}
	fillroundrect(x, y, x + width, y + height, 10, 10); // 圆角矩形  

	// 计算文本位置并绘制文本  
	int xSpace = (width - textWidth) / 2;
	int ySpace = (height - textHeight) / 2;
	outtextxy(x + xSpace, y + ySpace, desp);
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, width, height)) {
		return true;
	}
	return false;
}

int main() {
	initgraph(640, 480, EX_SHOWCONSOLE | EX_DBLCLKS); //窗口大小
	setbkcolor(WHITE); // 设置窗口颜色
	cleardevice(); // 用设置的颜色填充窗口

	draw();
	text();

	while (1) {
		cleardevice();
		if (peekmessage(&msg, EX_MOUSE)) {
		}
		BeginBatchDraw();
		if (CreateButton(400 - 100, 300 - 30, "超级管理员登录")) {
			printf("true\n");
		}
		EndBatchDraw();
	}

	while (1) {
		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				printf("左键(%d,%d)",msg.x,msg.y);
				break;
			case WM_RBUTTONDOWN:
				printf("右键");
				break;
			case WM_MBUTTONDOWN:
				printf("中键");
				break;
			case WM_MOUSEWHEEL:
				printf("滚轮(%d)",msg.wheel); // 前120，后-120
				break;
			case WM_LBUTTONDBLCLK:
				printf("左键双击");
				break;
			case WM_MOUSEMOVE:
				//printf("鼠标移动");
				break;
			}
		}
	}

	getchar(); // 保持窗口
	return 0;
}