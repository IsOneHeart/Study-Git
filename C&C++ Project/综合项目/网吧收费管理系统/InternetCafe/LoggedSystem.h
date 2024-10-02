#pragma once // 系统

void AdmC::SuperAdmLogin() {
	system("cls");
	page();
	line("超级管理员登录");
	space("[超级管理员密码](8位)");
	printf("\n");
	printf(CenterSpace);
	printf(">>");
	int count = 0;
	char password[9] = {};
	while (count < 8) {
		password[count] = _getch();
		if (password[count] == '\b') {
			if (count > 0) {
				printf("\b \b");
				count--;
			}
			continue;
		}
		if (password[count] == '\n') {
			password[count] = '\0';
			break;
		}
		printf("*");
		count++;
	}
	if (count < 8) {
		password[count] = '\0'; // 手动添加字符串结束符
	}
	else {
		password[8] = '\0'; // 确保在第8位添加字符串结束符
	}
if (!strcmp(password, Super_Administrator_Password)) {
			space("登录成功！\n");
			SuperAdmMenu();
		}
else {
	space("密码错误！\n");
	/* 调试 */
	//printf("输入的密码长度：%d\n", strlen(password));
	//printf("输入的密码：%s\n", password);
	space("点击任意键重新输入...\n");
	_getch();
	SuperAdmLogin();
	}
}

void AdmC::AdmLogin() {
	system("cls");
	page();
	line("管理员登录");
	printf(CenterSpace"[管理员ID登录]");
	int adm_id;
	std::cin >> adm_id;
	//Adm* head = NULL;
	//AdmListInitiate();
	//AdmFileRead();
	Adm* p = head->next;
	int flag = 0;
	while (p != NULL) {
		if (p->adm_id == adm_id) {
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag == 0) {
		space("账号不存在！");
		space(">>>>>>> 重试[A] 退出[ESC] <<<<<<<");
		char key;
		while (key = _getch()) {
			if (key == 'A' || key == 'a') {
				AdmListDestory();
				AdmLogin();
			}
			if (key == 27) {
				AdmListDestory();
				LoginPage();
			}
		}
	}
	space("[管理员密码](8位)");
	printf("\n");
	printf(CenterSpace);
	printf(">>");
	int count = 0;
	char password[9] = {};
	while (count < 8) {
		password[count] = _getch();
		if (password[count] == '\b') {
			if (count > 0) {
				printf("\b \b");
				count--;
			}
			continue;
		}
		if (password[count] == '\n') {
			password[count] = '\0';
			break;
		}
		printf("*");
		count++;
	}
	if (count < 8) {
		password[count] = '\0'; // 手动添加字符串结束符
	}
	else {
		password[8] = '\0'; // 确保在第8位添加字符串结束符
	}
	if (!strcmp(password, p->password)) {
		space("登录成功！\n");
		AdmMenu(adm_id);
	}
	else {
		space("密码错误！\n");
		space("点击任意键重新输入...\n");
		_getch();
		AdmLogin();
	}
}

void AdmC::LoginPage() {
	system("cls");
	page();
	line("登 录");
	space(" 超级管理员登录[1]  管理员登陆[2]");
	while (1) {
		char key = _getch();
		bool isbreak = false;
		switch (key) {
		case '1':
			SuperAdmLogin();
			isbreak = true;
			break;
		case '2':
			AdmLogin();
			isbreak = true;
			break;
		default:
			LoginPage();
		}
		if (isbreak == true) 
			break;
	}
}