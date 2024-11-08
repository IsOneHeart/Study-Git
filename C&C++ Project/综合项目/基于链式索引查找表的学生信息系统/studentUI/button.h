#pragma once
#define MENU_WIDTH (GUI_WIDTH*0.08)
#define MENU_HEIGHT 20
#define MENUS_LEN GUI_WIDTH
#define MENU_X 0
#define MENU_Y 0


#include "studentUI/buttonFunction.h"

#undef UNICODE
#undef _UNICODE

ExMessage msg = { 0 }; // 消息结构体

void drawComment(double x, double y, double width, const char* text) {
	double textWidth = textwidth(text);
	double textHeight = textheight(text);
	settextcolor(WHITE);
	setfillcolor(RGB(183, 183, 183));
	settextstyle(12, 0, "幼圆");
	setbkmode(TRANSPARENT); // 文字透明背景
	setfillcolor(RGB(183, 183, 183));
	fillrectangle((int)x, (int)y, (int)(x + width), (int)(y + 20));
	// 计算文本位置并绘制文本  
	double xSpace = (width - textWidth) / 2;
	double ySpace = (SINGLE_HEIGHT - textHeight) / 2;
	outtextxy((int)(x + xSpace), (int)(y + ySpace), text);
}

int createButton(double x, double y, double width, double height, const char* desp, const char* comment) {
	double textWidth = textwidth(desp);
	double textHeight = textheight(desp);
	setbkmode(TRANSPARENT); // 文字透明背景
	if (inArea(msg.x, msg.y, x, y, width, height)) {
		setfillcolor(RGB(183, 183, 183));
		fillrectangle(x, y, x + width, y + height);
		drawComment(x + width / 2, y + height, 200, comment);
	}
	// 计算文本位置并绘制文本  
	double xSpace = (width - textWidth) / 2;
	double ySpace = (height - textHeight) / 2;
	settextcolor(BLACK);
	settextstyle(15, 0, "幼圆");
	outtextxy(x + xSpace, y + ySpace, desp);
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, width, height)) {
		return true;
	}
	return false;
}

int createButton(double x, double y, double width, double height, const char* desp) {
	double textWidth = textwidth(desp);
	double textHeight = textheight(desp);
	setbkmode(TRANSPARENT); // 文字透明背景
	setfillcolor(RGB(201, 203, 204));
	if (inArea(msg.x, msg.y, x, y, width, height)) {
		setfillcolor(RGB(183, 183, 183));
		fillrectangle(x, y, x + width, y + height);
	}
	// 计算文本位置并绘制文本  
	double xSpace = (width - textWidth) / 2;
	double ySpace = (height - textHeight) / 2;
	settextcolor(BLACK);
	settextstyle(15, 0, "幼圆");
	outtextxy(x + xSpace, y + ySpace, desp);
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, width, height)) {
		return true;
	}
	return false;
}

void createMenuButton(const char* desp,const char* comment, int position, void function(Node** dataTable, int* page, long long* selectedSno, int* selectedColor), Node** dataTable, int* page, long long* selectedSno, int* selectedColor) {
	int x = FORM_X + MENU_WIDTH * (position - 1);
	if (createButton(x, MENU_Y, MENU_WIDTH, MENU_HEIGHT, desp, comment)) {
        function(dataTable, page, selectedSno, selectedColor);
	}
}

void createMenu(Node** dataTable, int* page, long long* selectedSno, int* selectedColor) {
	setfillcolor(RGB(201, 203, 204));
	fillrectangle(MENU_X, MENU_Y, MENUS_LEN, MENU_HEIGHT);
	createMenuButton("保存文件", "保存索引表至文件", 1, save, dataTable, page, selectedSno, selectedColor);
	createMenuButton("压缩空间", "尝试将每个节点与下一个节点合并", 2, clear, dataTable, page, selectedSno, selectedColor);
	createMenuButton("查找数据", "根据学号查找学生信息", 3, search, dataTable, page, selectedSno, selectedColor);
	createMenuButton("添加数据", "添加数据至索引表并视情况自动分裂节点", 4, insert, dataTable, page, selectedSno, selectedColor);
	createMenuButton("删除数据", "删除指定学号的数据", 5, del, dataTable, page, selectedSno, selectedColor);
	createMenuButton("修改数据", "根据学号修改学生信息", 6, change, dataTable, page, selectedSno, selectedColor);
	createMenuButton("取消高亮", "取消选中行的选中状态", 7, cancel, dataTable, page, selectedSno, selectedColor);
	createMenuButton("安全退出","释放内存空间后退出程序", 8, exitSafely, dataTable, page, selectedSno, selectedColor);
}

void createForm(Node** dataTable, int* page, long long selectedSno, int selectedColor) {
	double x = FORM_X + FORM_WIDTH / 2 - (FORM_BUTTON_W * 5 / 2);
	drawForm(*dataTable, page, selectedSno, selectedColor);
	setfillcolor(RGB(201, 203, 204));
	fillrectangle(x,FORM_BUTTON_Y, x + FORM_BUTTON_W * 5, FORM_BUTTON_Y + FORM_BUTTON_H);
	if (createButton(x, FORM_BUTTON_Y, FORM_BUTTON_W, FORM_BUTTON_H, "-")) {
		if (*page > 1) {
			(*page)--;
			//drawForm(*dataTable, page);
			Sleep(50); // 防止单击被误判为连点
		}
	}
	int l, m, r;
	if (*page == 1) {
		l = 1;
		m = 2;
		r = -1;
	}
	else if (*page == Pages) {
		l = -1;
		m = Pages - 1;
		r = Pages;
	}
	else {
		l = r = -1;
        m = *page;
	}
	char lc[3], mc[3], rc[3];
    sprintf(lc, "%d", l);
    sprintf(mc, "%d", m);
    sprintf(rc, "%d", r);
	lc[2] = mc[2] = rc[2] ='\0';
	if (createButton(x + FORM_BUTTON_W, FORM_BUTTON_Y, FORM_BUTTON_W, FORM_BUTTON_H, (l>0?lc:"…"))) {
		if (l != -1) {
			*page = l;
			//Sleep(50);
		}
	}
	if (createButton(x + FORM_BUTTON_W * 2, FORM_BUTTON_Y, FORM_BUTTON_W, FORM_BUTTON_H, (m > 0 ? mc : "…"))) {
		*page = m;
		//Sleep(10);
	}
	if (createButton(x + FORM_BUTTON_W * 3, FORM_BUTTON_Y, FORM_BUTTON_W, FORM_BUTTON_H, (r > 0 ? rc : "…"))) {
		if (r != -1) {
			*page = r;
			//Sleep(10);
		}
	}
	if (createButton(x + FORM_BUTTON_W * 4, FORM_BUTTON_Y, FORM_BUTTON_W, FORM_BUTTON_H, (char*)"+")) {
		if (*page < Pages) {
			(*page)++;
			//drawForm(*dataTable, page);
			Sleep(100);
		}
	}
	settextcolor(BLACK);
	settextstyle(15, 0, "幼圆");
	char text[50];
	sprintf(text, "第%d个节点(页)/共%d个节点(页)\0", *page, Pages);
	drawCell(0, FORM_BUTTON_Y, 250, text, 4);
}