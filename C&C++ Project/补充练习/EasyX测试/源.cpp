#include <stdio.h>
#include <easyx.h>
//#include <graphics.h>
#include <conio.h>
#undef UNICODE
#undef _UNICODE

ExMessage msg = { 0 }; // ��Ϣ�ṹ��

void draw() {
	putpixel(50, 50, RED); // ���
	setlinecolor(BLACK); // ����������ɫ
	setlinestyle(PS_SOLID, 2); // ����������ʽ
	line(0, 0, getwidth(), getheight()); // ����
	setlinestyle(PS_SOLID, 1);
	rectangle(100, 0, 100 + 50, 0 + 30); // ���ο�
	setfillcolor(GREEN); // ���������ɫ
	fillrectangle(200, 100, 200 + 50, 100 + 30); // ������
	solidrectangle(100, 300, 100 + 50, 300 + 50); // �޿�������
	roundrect(300, 300, 300 + 50, 300 + 30, 10, 10); // Բ�Ǿ���
	fillroundrect(100, 200, 100 + 50, 200 + 30, 20, 20);
	solidroundrect(50, 300, 50 + 50, 300 + 50, 30, 30);
	circle(20, 20, 20); // Բ��
	setfillcolor(RGB(128, 213, 221));
	fillcircle(40, 40, 20);
	solidcircle(60, 60, 20);
	ellipse(400, 300, 500, 450); //��Բ
	fillellipse(200, 200, 300, 400);
	solidellipse(0, 500, 50, 400);
	POINT points[]{ {30,40},{60,70},{10,50} };
	polyline(points, 4); // ����
}

void text() {
	printf("Hello EasyX!");
	settextstyle(42, 0, (LPCTSTR)"΢���ź�");
	settextcolor(RED);
	setbkmode(TRANSPARENT); // ����͸������
	outtextxy(210, 240, _T("Hello EasyX!"));
	int score = 21;
	char score_c[10];
	sprintf_s(score_c, "������%d", score);
	settextstyle(30, 0, "�������� ����");
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
	setbkmode(TRANSPARENT); // ����͸������
	if (inArea(msg.x, msg.y, x, y, x + width, y + height)) {
		setfillcolor(RGB(123, 190, 238));
	}
	else {
		setfillcolor(RGB(210, 232, 248));
	}
	fillroundrect(x, y, x + width, y + height, 10, 10); // Բ�Ǿ���  

	// �����ı�λ�ò������ı�  
	int xSpace = (width - textWidth) / 2;
	int ySpace = (height - textHeight) / 2;
	outtextxy(x + xSpace, y + ySpace, desp);
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, width, height)) {
		return true;
	}
	return false;
}

int main() {
	initgraph(640, 480, EX_SHOWCONSOLE | EX_DBLCLKS); //���ڴ�С
	setbkcolor(WHITE); // ���ô�����ɫ
	cleardevice(); // �����õ���ɫ��䴰��

	draw();
	text();

	while (1) {
		cleardevice();
		if (peekmessage(&msg, EX_MOUSE)) {
		}
		BeginBatchDraw();
		if (CreateButton(400 - 100, 300 - 30, "��������Ա��¼")) {
			printf("true\n");
		}
		EndBatchDraw();
	}

	while (1) {
		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				printf("���(%d,%d)",msg.x,msg.y);
				break;
			case WM_RBUTTONDOWN:
				printf("�Ҽ�");
				break;
			case WM_MBUTTONDOWN:
				printf("�м�");
				break;
			case WM_MOUSEWHEEL:
				printf("����(%d)",msg.wheel); // ǰ120����-120
				break;
			case WM_LBUTTONDBLCLK:
				printf("���˫��");
				break;
			case WM_MOUSEMOVE:
				//printf("����ƶ�");
				break;
			}
		}
	}

	getchar(); // ���ִ���
	return 0;
}