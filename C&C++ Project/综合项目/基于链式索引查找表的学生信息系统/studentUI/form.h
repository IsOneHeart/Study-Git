#pragma once
#define FORM_X (FORM_WIDTH * 0.02)
#define FORM_Y 20
#define FORM_WIDTH GUI_WIDTH
#define SINGLE_HEIGHT 30

#define SNO_W (FORM_WIDTH * 0.08)
#define SNAME_W (FORM_WIDTH * 0.05)
#define SEX_W (FORM_WIDTH * 0.04)
#define BIRTHDAY_W (FORM_WIDTH * 0.08)
#define NATIONALITY_W (FORM_WIDTH * 0.07)
#define NATIVE_W (FORM_WIDTH * 0.10)
#define POLITICAL_W (FORM_WIDTH * 0.08)
#define DISTRICT_W (FORM_WIDTH * 0.07)
#define STUDENTSOURCE_W (FORM_WIDTH * 0.10)
#define ENTERYEAR_W (FORM_WIDTH * 0.08)
#define SCHOOLYEAR_W (FORM_WIDTH * 0.04)
#define CLASS_W (FORM_WIDTH * 0.11)
#define MAJORNO_W (FORM_WIDTH * 0.06)

#define SNO_X (FORM_WIDTH * 0.02)
#define SNAME_X (FORM_WIDTH * 0.10)
#define SEX_X (FORM_WIDTH * 0.15)
#define BIRTHDAY_X (FORM_WIDTH * 0.19)
#define NATIONALITY_X (FORM_WIDTH * 0.27)
#define NATIVE_X (FORM_WIDTH * 0.34)
#define POLITICAL_X (FORM_WIDTH * 0.44)
#define DISTRICT_X (FORM_WIDTH * 0.52)
#define STUDENTSOURCE_X (FORM_WIDTH * 0.59)
#define ENTERYEAR_X (FORM_WIDTH * 0.69)
#define SCHOOLYEAR_X (FORM_WIDTH * 0.77)
#define CLASS_X (FORM_WIDTH * 0.81)
#define MAJORNO_X (FORM_WIDTH * 0.92)

#define FORM_BUTTON_W SINGLE_HEIGHT
#define FORM_BUTTON_H SINGLE_HEIGHT
#define FORM_BUTTON_Y (FORM_Y + SINGLE_HEIGHT * (MAXSIZE + 1))

void drawCell(double x, double y, double width, char* text, int color);

// 表格单元
void drawCell(double x, double y, double width, char* text, int color) {
	double textWidth = textwidth(text);
	double textHeight = textheight(text);
	switch (color) {
	case -3: // 黄色标记行
		setfillcolor(YELLOW);
		break;
	case -2: // 绿色标记行
		setfillcolor(RGB(95, 212, 128));
		break;
	case -1: //表头
        setfillcolor(RGB(123, 190, 238)); 
		break;
	case 0: // 奇数行
		setfillcolor(RGB(234, 236, 244)); //RGB(123, 190, 238)
		break;
	case 1: // 偶数行
        setfillcolor(RGB(215, 228, 241)); //RGB(210, 232, 248)
		break;
	case 2: //偶数行序号
		setfillcolor(RGB(201, 203, 204));
		break;
	case 3: //奇数行序号
		setfillcolor(RGB(183, 183, 183));
		break;
	case 4:
		setfillcolor(WHITE);
		break;
	}
	fillrectangle((int)x, (int)y, (int)(x + width), (int)(y + SINGLE_HEIGHT));
	// 计算文本位置并绘制文本  
	double xSpace = (width - textWidth) / 2;
	double ySpace = (SINGLE_HEIGHT - textHeight) / 2;
	settextcolor(BLACK);
	settextstyle(15, 0, "幼圆");
	setbkmode(TRANSPARENT); // 文字透明背景
	outtextxy((int)(x + xSpace), (int)(y + ySpace), text);
}

// 绘制单行，已弃用
/*
void drawSingleRow(const Student* student, int rowCount, int no) {
	int h = FORM_Y + SINGLE_HEIGHT * (rowCount); // 计算到表头的最短距离
	int color;
    if (rowCount % 2 == 0)  //计算奇偶行
        color = 0;
    else
        color = 1;
	char charNo[5]; // 取决于学生人数
	sprintf(charNo, "%d", no); 
	charNo[4] = '\0';
	drawCell(FORM_X - (FORM_WIDTH * 0.02), h, (FORM_WIDTH * 0.04), charNo, (no % 2 == 0 ? 2 : 3));
	char sno[13];
    sprintf(sno, "%lld", student->sno); // 将学号转换为字符串
	sno[12] = '\0';
	drawCell(FORM_X + SNO_X, h, SNO_W, sno, color);
    drawCell(FORM_X + SNAME_X, h, SNAME_W, student->sname.data, color);
    drawCell(FORM_X + SEX_X, h, SEX_W, student->sex.data, color);
    drawCell(FORM_X + BIRTHDAY_X, h, BIRTHDAY_W, student->birthday.data, color);
	drawCell(FORM_X + NATIONALITY_X, h, NATIONALITY_W, student->nationality.data, color);
    drawCell(FORM_X + NATIVE_X, h, NATIVE_W, student->native.data, color);
    drawCell(FORM_X + POLITICAL_X, h, POLITICAL_W, student->political.data, color);
    drawCell(FORM_X + DISTRICT_X, h, DISTRICT_W, student->district.data, color);
    drawCell(FORM_X + STUDENTSOURCE_X, h, STUDENTSOURCE_W, student->studentSource.data, color);
    drawCell(FORM_X + ENTERYEAR_X, h, ENTERYEAR_W, student->enterYear.data, color);
	char schoolYear[2];
	sprintf(schoolYear, "%d", student->schoolYear);
	schoolYear[1] = '\0';
    drawCell(FORM_X + SCHOOLYEAR_X, h, SCHOOLYEAR_W, schoolYear, color);
    drawCell(FORM_X + CLASS_X, h, CLASS_W, student->inClass.data, color);
    drawCell(FORM_X + MAJORNO_X, h, MAJORNO_W, student->majorNo.data, color);
	//FlushBatchDraw();
}
*/

// 绘制选中的行
void drawSelectRow(const Student* student, int rowCount, int no, int color) {
	int h = FORM_Y + SINGLE_HEIGHT * (rowCount); // 计算到表头的最短距离
	char charNo[5]; // 取决于学生人数
	sprintf(charNo, "%d", no);
	charNo[4] = '\0';
	drawCell(FORM_X - (FORM_WIDTH * 0.02), h, (FORM_WIDTH * 0.04), charNo, (no % 2 == 0 ? 2 : 3));
	char sno[13];
	sprintf(sno, "%lld", student->sno); // 将学号转换为字符串
	sno[12] = '\0';
	drawCell(FORM_X + SNO_X, h, SNO_W, sno, color);
	drawCell(FORM_X + SNAME_X, h, SNAME_W, student->sname.data, color);
	drawCell(FORM_X + SEX_X, h, SEX_W, student->sex.data, color);
	drawCell(FORM_X + BIRTHDAY_X, h, BIRTHDAY_W, student->birthday.data, color);
	drawCell(FORM_X + NATIONALITY_X, h, NATIONALITY_W, student->nationality.data, color);
	drawCell(FORM_X + NATIVE_X, h, NATIVE_W, student->native.data, color);
	drawCell(FORM_X + POLITICAL_X, h, POLITICAL_W, student->political.data, color);
	drawCell(FORM_X + DISTRICT_X, h, DISTRICT_W, student->district.data, color);
	drawCell(FORM_X + STUDENTSOURCE_X, h, STUDENTSOURCE_W, student->studentSource.data, color);
	drawCell(FORM_X + ENTERYEAR_X, h, ENTERYEAR_W, student->enterYear.data, color);
	char schoolYear[2];
	sprintf(schoolYear, "%d", student->schoolYear);
	schoolYear[1] = '\0';
	drawCell(FORM_X + SCHOOLYEAR_X, h, SCHOOLYEAR_W, schoolYear, color);
	drawCell(FORM_X + CLASS_X, h, CLASS_W, student->inClass.data, color);
	drawCell(FORM_X + MAJORNO_X, h, MAJORNO_W, student->majorNo.data, color);
}

// 绘制学生信息表表格
void drawForm(Node* head, int* page, long long selectedSno, int selectedColor) {
	if (*page > Pages)
		return;
	Node* current = head;
	int i, count = 0, color = -1, no = 0;
	drawCell(FORM_X- (FORM_WIDTH * 0.02), FORM_Y, (FORM_WIDTH * 0.04), (char*)"索引表", 2);
	drawCell(FORM_X + SNO_X, FORM_Y, SNO_W, (char*)"学号", color);
	drawCell(FORM_X + SNAME_X, FORM_Y, SNAME_W, (char*)"姓名", color);
	drawCell(FORM_X + SEX_X, FORM_Y, SEX_W, (char*)"性别", color);
	drawCell(FORM_X + BIRTHDAY_X, FORM_Y, BIRTHDAY_W, (char*)"出生日期", color);
	drawCell(FORM_X + NATIONALITY_X, FORM_Y, NATIONALITY_W, (char*)"民族", color);
	drawCell(FORM_X + NATIVE_X, FORM_Y, NATIVE_W, (char*)"籍贯", color);
	drawCell(FORM_X + POLITICAL_X, FORM_Y, POLITICAL_W, (char*)"政治面貌", color);
	drawCell(FORM_X + DISTRICT_X, FORM_Y, DISTRICT_W, (char*)"校区", color);
	drawCell(FORM_X + STUDENTSOURCE_X, FORM_Y, STUDENTSOURCE_W, (char*)"学生来源", color);
	drawCell(FORM_X + ENTERYEAR_X, FORM_Y, ENTERYEAR_W, (char*)"入学日期", color);
	drawCell(FORM_X + SCHOOLYEAR_X, FORM_Y, SCHOOLYEAR_W, (char*)"学龄", color);
	drawCell(FORM_X + CLASS_X, FORM_Y, CLASS_W, (char*)"班级", color);
	drawCell(FORM_X + MAJORNO_X, FORM_Y, MAJORNO_W, (char*)"专业号", color);
	while (current != NULL) {
		count++;
		for (i = 0; i < current->count; ++i) {
			no++;
			if (count == *page) {
				if (current->data[i].sno == selectedSno) {
					color = selectedColor;
				}
				else if ((i + 1) % 2 == 0)  //计算奇偶行
					color = 0;
				else
					color = 1;
				drawSelectRow(&current->data[i], i+1, no, color);
				for (int j = 0;j < MAXSIZE - current->count;++j) {
					int h = FORM_Y + SINGLE_HEIGHT * (j+ current->count +1); // 计算到表头的最短距离
					char empty[2]= { ' ', '\0' };
					color = 0;
					drawCell(FORM_X - (FORM_WIDTH * 0.02), h, (FORM_WIDTH * 0.04), empty, (no % 2 == 0 ? 2 : 3));
					drawCell(FORM_X + SNO_X, h, SNO_W, empty, color);
					drawCell(FORM_X + SNAME_X, h, SNAME_W, empty, color);
					drawCell(FORM_X + SEX_X, h, SEX_W, empty, color);
					drawCell(FORM_X + BIRTHDAY_X, h, BIRTHDAY_W, empty, color);
					drawCell(FORM_X + NATIONALITY_X, h, NATIONALITY_W, empty, color);
					drawCell(FORM_X + NATIVE_X, h, NATIVE_W, empty, color);
					drawCell(FORM_X + POLITICAL_X, h, POLITICAL_W, empty, color);
					drawCell(FORM_X + DISTRICT_X, h, DISTRICT_W, empty, color);
					drawCell(FORM_X + STUDENTSOURCE_X, h, STUDENTSOURCE_W, empty, color);
					drawCell(FORM_X + ENTERYEAR_X, h, ENTERYEAR_W, empty, color);
					drawCell(FORM_X + SCHOOLYEAR_X, h, SCHOOLYEAR_W, empty, color);
					drawCell(FORM_X + CLASS_X, h, CLASS_W, empty, color);
					drawCell(FORM_X + MAJORNO_X, h, MAJORNO_W, empty, color);
				}
			}
		}
		current = current->next;
	}
}
