#pragma once // ϵͳ

void AdmC::SuperAdmLogin() {
	system("cls");
	page();
	line("��������Ա��¼");
	space("[��������Ա����](8λ)");
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
		password[count] = '\0'; // �ֶ�����ַ���������
	}
	else {
		password[8] = '\0'; // ȷ���ڵ�8λ����ַ���������
	}
if (!strcmp(password, Super_Administrator_Password)) {
			space("��¼�ɹ���\n");
			SuperAdmMenu();
		}
else {
	space("�������\n");
	/* ���� */
	//printf("��������볤�ȣ�%d\n", strlen(password));
	//printf("��������룺%s\n", password);
	space("����������������...\n");
	_getch();
	SuperAdmLogin();
	}
}

void AdmC::AdmLogin() {
	system("cls");
	page();
	line("����Ա��¼");
	printf(CenterSpace"[����ԱID��¼]");
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
		space("�˺Ų����ڣ�");
		space(">>>>>>> ����[A] �˳�[ESC] <<<<<<<");
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
	space("[����Ա����](8λ)");
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
		password[count] = '\0'; // �ֶ�����ַ���������
	}
	else {
		password[8] = '\0'; // ȷ���ڵ�8λ����ַ���������
	}
	if (!strcmp(password, p->password)) {
		space("��¼�ɹ���\n");
		AdmMenu(adm_id);
	}
	else {
		space("�������\n");
		space("����������������...\n");
		_getch();
		AdmLogin();
	}
}

void AdmC::LoginPage() {
	system("cls");
	page();
	line("�� ¼");
	space(" ��������Ա��¼[1]  ����Ա��½[2]");
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