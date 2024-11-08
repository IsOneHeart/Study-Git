#pragma once
#include "studentIndexTable.h"
#include <easyx.h>
#include <conio.h>
#include <windows.h>

#define GUI_WIDTH 1280
#define GUI_HEIGHT 680

#include "studentUI/base.h"
#include "studentUI/form.h"
#include "studentUI/button.h"

void drawStudentGUI(Node** dataTable) {
	initgraph(GUI_WIDTH, GUI_HEIGHT, EX_SHOWCONSOLE | EX_DBLCLKS);
	HWND h = GetHWnd(); //获取窗口句柄
	SetWindowText(h, "基于链式索引查找表的学生信息系统（DGUT ZYX）"); 	//修改窗口标题
	setbkcolor(WHITE); // 设置窗口颜色
	cleardevice(); // 重绘，用设置的颜色填充窗口
	int page = 1;
	long long selectedSno = 0;
	int selectedColor = -2;
	while (1) {
		//cleardevice();
		if (peekmessage(&msg, EX_MOUSE)) {
		}
		BeginBatchDraw(); // 开始批量绘图
		createForm(dataTable, &page, selectedSno, selectedColor);
		createMenu(dataTable, &page, &selectedSno, &selectedColor);
		EndBatchDraw(); // 结束批量绘图
	}
}