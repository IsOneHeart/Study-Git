#pragma once//卡管理

int UserC::UserFileRead() {
	using namespace std;
	ifstream inFile("data/card.txt");
	if (!inFile.is_open()) {
		cerr << "文件打开失败！" << endl;
		return 0;
	}
	string line;
	while (getline(inFile, line)) {
		stringstream ss(line);
		User user{};
		if (!(ss >> user.uid >> user.password >> 
			user.card_amount >> user.vip >> user.signout))
			continue;
		UL.push_back(user);
	}
	inFile.close();
	return 1;
}

int UserC::UserFileWrite() {
	using namespace std;
	fstream outFile("data/card.txt", ios::out | ios::trunc);
	if (!outFile.is_open()) {
		cerr << "文件打开失败！" << endl;
		return 0;
	}
	for (const auto& i : UL) { //遍历链表
		outFile << i.uid << " " << i.password << " " << i.card_amount << " "
			<< i.vip << " " << i.signout << endl;
	}
	outFile.close();
	return 1;
}

void AdmC::CardAdd(int adm_id) {
	system("cls");
	page();
	line("添 加 卡");
	User newUser{};
	newUser.uid = UL.empty() ? 100000 : UserFindMaxID() + 1;
	newUser.signout = false;
	spaceE("[ 卡  号 ]");
	std::cout << newUser.uid << std::endl;
	spaceE("[创建密码]");
	char temp_password[9]{};
	strcpy_s(temp_password, GetPassword().c_str());
	std::cout << std::endl;
	spaceE("[确认密码]");
	if (strcmp(temp_password, GetPassword().c_str()) != 0) {
		space("两次输入的密码不同！");
		space("按任意键重新输入...");
		_getch();
		CardAdd(adm_id);
		return;
	}
	else
		strcpy_s(newUser.password, temp_password);
	std::cout << std::endl;
	spaceE("[开卡金额]");
	std::cin >> newUser.card_amount;
	spaceE("[是否会员]");
	std::string isVIP;
	std::cin >> isVIP;
	if (isVIP == "是" || isVIP == "true" || isVIP == "True" || isVIP == "TRUE" || isVIP == "1")
		newUser.vip = true;
	else if (isVIP == "否" || isVIP == "false" || isVIP == "False" || isVIP == "FALSE" || isVIP == "0")
		newUser.vip = false;
	else {
		space("非法输入！");
		space("按任意键重新输入...");
		_getch();
		CardAdd(adm_id);
		return;
	}
	space(">>确认[Y] 重新添加[N] 取消[ESC]<<");
	char key;
	while (1) {
		key = _getch();
		if (key == 'Y' || key == 'y') {
			UL.push_back(newUser);
			UserFileWrite();
			CardM(adm_id);
			break;
		}
		if (key == 'N' || key == 'n') {
			CardAdd(adm_id);
			break;
		}
		if (key == 27) {
			CardM(adm_id);
			break;
		}
	}
}

void AdmC::CardExaime(int adm_id) {
	system("cls");
	page();
	line("查 询 卡");
	int uid;
	spaceE("[卡 号]");
	std::cin >> uid;
	bool isfind = false;
	for (const auto& i : UL) {
		if (uid == i.uid && i.signout == false) {
			isfind = true;
			std::cout << CenterSpace << "[余 额]" << i.card_amount << std::endl;
			std::cout << CenterSpace << "[ VIP ]" << (i.vip == true ? "已开通" : "未开通") << std::endl;
			break;
		}
	}
	if (!isfind) {
		space("未找到该卡号！");
	}
	space("(按ESC返回卡管理系统...)");
	char key;
	while ((key = _getch()) != 27) {
	}
	CardM(adm_id);
}

void AdmC::CardSignOut(int adm_id) {
	system("cls");
	page();
	line("注 销 卡");
	spaceE("[卡 号]");
	int uid;
	std::cin >> uid;
	bool isfind = false;
	for (const auto& i : UL) {
		if (i.uid == uid) {
			isfind = true;
			break;
		}
	}
	if (!isfind) {
		space("未找到该卡号！");
		space(">>  重新选择[N]     退出[ESC]  <<");
		char key;
		while (key = _getch()) {
			if (key == 'N' || key == 'n') {
				CardSignOut(adm_id);
			}
			if (key == 27)
				CardM(adm_id);
		}
	}
	space(">>确定[Y] 重新选择[N] 退出[ESC]<<");
	char key;
	while (key = _getch()) {
		if (key == 'Y' || key == 'y') {
			for (auto& i : UL) {
				if (i.uid == uid) {
					i.signout = true;
					UserFileWrite();
					break;
				}
			}
			space("注销成功！");
			CardM(adm_id);
		}
		if (key == 'N' || key == 'n') {
			CardSignOut(adm_id);
		}
		if (key == 27)
			CardM(adm_id);
	}
}

void AdmC::CardM(int adm_id) {
	system("cls");
	page();
	line("卡 管 理 系 统");
	space("(按ESC返回管理员权限系统...)");
	space("添加卡[A]   查询卡[E]   注销卡[S]");
	char key;
	while (1) {
		key = _getch();
		if (key == 'A' || key == 'a')
			CardAdd(adm_id);
		if (key == 'E' || key == 'e')
			CardExaime(adm_id);
		if (key == 'S' || key == 's')
			CardSignOut(adm_id);
		if(key==27)
			AdmMenu(adm_id);
	}
}