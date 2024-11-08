#pragma once

void exitSafely(Node** dataTable, int* page, long long* selectedSno, int* selectedColor) {
	closegraph();
	destroyDataTable(dataTable);
	exit(0);
}

void search(Node** dataTable, int* page, long long* selectedSno, int* selectedColor) {
	char str[13];
	printf("（请在弹窗中输入要查找的学号）\n");
	InputBox(str, 13, "以学号查找：", "以学号查找", NULL, 0, 0, FALSE);
	long long sno;
	Student student;
	int count;
	try {
		sno = atoll(str); // 将char*转换成long long
		count = indexSearch(*dataTable, sno, &student);
	}
	catch (const char* msg) {
        printf("（查找失败）\n");
	}
	if (count != -1) {
		printf("（查找成功，请查看弹窗）\n");
		printf("查找到的学生数据：\n");
		printStudentColumn(&student);
		if(count>0&&count<= Pages)
			*page= count;
		printf("\ncount=%d", count);
		*selectedSno = sno;
		*selectedColor = -2;
	}
}

void cancel(Node** dataTable, int* page, long long* selectedSno, int* selectedColor) {
	*selectedSno = 0;
	*selectedColor = -2;
}

void insert(Node** dataTable, int* page, long long* selectedSno, int* selectedColor) {
    char str[13];
    Student student;
    printf("（请在弹窗中输入要添加的学生信息）\n");
    InputBox(str, 13, "学号", "添加学生信息：", NULL, 0, 0, FALSE);
    student.sno = atoll(str);
    char str1[50];
    InputBox(str1, 50, "姓名", "请输入姓名：", NULL, 0, 0, FALSE);
    student.sname=createString(str1);
    char str2[3];
    InputBox(str2, 10, "性别", "请输入性别（男/女）：", NULL, 0, 0, FALSE);
    student.sex=createString(str2);
    char str3[11];
    InputBox(str3, 20, "出生日期", "请输入出生日期（YYYY-MM-DD）：", NULL, 0, 0, FALSE);
    student.birthday=createString(str3);
    InputBox(str1, 20, "民族", "请输入民族：", NULL, 0, 0, FALSE);
    student.nationality = createString(str1);
    InputBox(str1, 50, "籍贯", "请输入籍贯：", NULL, 0, 0, FALSE);
    student.native=createString(str1);
    InputBox(str1, 20, "政治面貌", "请输入政治面貌：", NULL, 0, 0, FALSE);
    student.political = createString(str1);
    InputBox(str3, 50, "校区", "请输入校区：", NULL, 0, 0, FALSE);
    student.district=createString(str3);
    InputBox(str1, 50, "学生来源", "请输入学生来源：", NULL, 0, 0, FALSE);
    student.studentSource=createString(str1);
    InputBox(str3, 20, "入学日期", "请输入入学日期（YYYY-MM-DD）：", NULL, 0, 0, FALSE);
    student.enterYear=createString(str3);
    InputBox(str, 5, "学年", "请输入学年：", NULL, 0, 0, FALSE);
    student.schoolYear = atoi(str);
    InputBox(str1, 20, "班级", "请输入班级：", NULL, 0, 0, FALSE);
    student.inClass=createString(str1);
    char str4[5];
    InputBox(str4, 20, "专业编号", "请输入专业编号：", NULL, 0, 0, FALSE);
    student.majorNo=createString(str4);
    int insertPage, insertIndex;
    InputBox(str, 5, "插入的节点", "请输入要插入的节点：", NULL, 0, 0, FALSE);
    insertPage = atoi(str);
    InputBox(str, 5, "插入的节点中的位置（从0开始）", "请输入要插入的节点中的位置（从0开始）：", NULL, 0, 0, FALSE);
    insertIndex = atoi(str);
    insertData(dataTable, student, insertPage, insertIndex);
    *page= insertPage;
    *selectedSno = student.sno;
    *selectedColor = -3;
}

void del(Node** dataTable, int* page, long long* selectedSno, int* selectedColor) {
    char str[13];
    int sno;
    printf("（请在弹窗中输入要删除的学生数据的学号）\n");
    InputBox(str, 13, "学号", "删除学生信息：", NULL, 0, 0, FALSE);
    sno = atoll(str);
    *page=deleteData(dataTable, sno);
}

void change(Node** dataTable, int* page, long long* selectedSno, int* selectedColor) {
    char str[13];
    Student student;
    printf("（请在弹窗中输入要修改的学生信息）\n");
    InputBox(str, 13, "学号", "修改学生信息：", NULL, 0, 0, FALSE);
    student.sno = atoll(str);
    char str1[50];
    InputBox(str1, 50, "姓名", "请输入姓名：", NULL, 0, 0, FALSE);
    student.sname = createString(str1);
    char str2[3];
    InputBox(str2, 10, "性别", "请输入性别（男/女）：", NULL, 0, 0, FALSE);
    student.sex = createString(str2);
    char str3[11];
    InputBox(str3, 20, "出生日期", "请输入出生日期（YYYY-MM-DD）：", NULL, 0, 0, FALSE);
    student.birthday = createString(str3);
    InputBox(str1, 20, "民族", "请输入民族：", NULL, 0, 0, FALSE);
    student.nationality = createString(str1);
    InputBox(str1, 50, "籍贯", "请输入籍贯：", NULL, 0, 0, FALSE);
    student.native = createString(str1);
    InputBox(str1, 20, "政治面貌", "请输入政治面貌：", NULL, 0, 0, FALSE);
    student.political = createString(str1);
    InputBox(str3, 50, "校区", "请输入校区：", NULL, 0, 0, FALSE);
    student.district = createString(str3);
    InputBox(str1, 50, "学生来源", "请输入学生来源：", NULL, 0, 0, FALSE);
    student.studentSource = createString(str1);
    InputBox(str3, 20, "入学日期", "请输入入学日期（YYYY-MM-DD）：", NULL, 0, 0, FALSE);
    student.enterYear = createString(str3);
    InputBox(str, 5, "学年", "请输入学年：", NULL, 0, 0, FALSE);
    student.schoolYear = atoi(str);
    InputBox(str1, 20, "班级", "请输入班级：", NULL, 0, 0, FALSE);
    student.inClass = createString(str1);
    char str4[5];
    InputBox(str4, 20, "专业编号", "请输入专业编号：", NULL, 0, 0, FALSE);
    student.majorNo = createString(str4);
    *page = changeData(dataTable, student);
    *selectedSno = student.sno;
    *selectedColor = -3;
}

void clear(Node** dataTable, int* page, long long* selectedSno, int* selectedColor) {
    clearTable(dataTable);
}

void save(Node** dataTable, int* page, long long* selectedSno, int* selectedColor) {
    saveIndexTableToFile(*dataTable, "student.txt");
}