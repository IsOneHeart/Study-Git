#pragma once//������

int UserC::UserFileRead() {
	using namespace std;
	ifstream inFile("data/card.txt");
	if (!inFile.is_open()) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
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
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return 0;
	}
	for (const auto& i : UL) { //��������
		outFile << i.uid << " " << i.password << " " << i.card_amount << " "
			<< i.vip << " " << i.signout << endl;
	}
	outFile.close();
	return 1;
}

void AdmC::CardAdd(int adm_id) {
	system("cls");
	page();
	line("�� �� ��");
	User newUser{};
	newUser.uid = UL.empty() ? 100000 : UserFindMaxID() + 1;
	newUser.signout = false;
	spaceE("[ ��  �� ]");
	std::cout << newUser.uid << std::endl;
	spaceE("[��������]");
	char temp_password[9]{};
	strcpy_s(temp_password, GetPassword().c_str());
	std::cout << std::endl;
	spaceE("[ȷ������]");
	if (strcmp(temp_password, GetPassword().c_str()) != 0) {
		space("������������벻ͬ��");
		space("���������������...");
		_getch();
		CardAdd(adm_id);
		return;
	}
	else
		strcpy_s(newUser.password, temp_password);
	std::cout << std::endl;
	spaceE("[�������]");
	std::cin >> newUser.card_amount;
	spaceE("[�Ƿ��Ա]");
	std::string isVIP;
	std::cin >> isVIP;
	if (isVIP == "��" || isVIP == "true" || isVIP == "True" || isVIP == "TRUE" || isVIP == "1")
		newUser.vip = true;
	else if (isVIP == "��" || isVIP == "false" || isVIP == "False" || isVIP == "FALSE" || isVIP == "0")
		newUser.vip = false;
	else {
		space("�Ƿ����룡");
		space("���������������...");
		_getch();
		CardAdd(adm_id);
		return;
	}
	space(">>ȷ��[Y] �������[N] ȡ��[ESC]<<");
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
	line("�� ѯ ��");
	int uid;
	spaceE("[�� ��]");
	std::cin >> uid;
	bool isfind = false;
	for (const auto& i : UL) {
		if (uid == i.uid && i.signout == false) {
			isfind = true;
			std::cout << CenterSpace << "[�� ��]" << i.card_amount << std::endl;
			std::cout << CenterSpace << "[ VIP ]" << (i.vip == true ? "�ѿ�ͨ" : "δ��ͨ") << std::endl;
			break;
		}
	}
	if (!isfind) {
		space("δ�ҵ��ÿ��ţ�");
	}
	space("(��ESC���ؿ�����ϵͳ...)");
	char key;
	while ((key = _getch()) != 27) {
	}
	CardM(adm_id);
}

void AdmC::CardSignOut(int adm_id) {
	system("cls");
	page();
	line("ע �� ��");
	spaceE("[�� ��]");
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
		space("δ�ҵ��ÿ��ţ�");
		space(">>  ����ѡ��[N]     �˳�[ESC]  <<");
		char key;
		while (key = _getch()) {
			if (key == 'N' || key == 'n') {
				CardSignOut(adm_id);
			}
			if (key == 27)
				CardM(adm_id);
		}
	}
	space(">>ȷ��[Y] ����ѡ��[N] �˳�[ESC]<<");
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
			space("ע���ɹ���");
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
	line("�� �� �� ϵ ͳ");
	space("(��ESC���ع���ԱȨ��ϵͳ...)");
	space("��ӿ�[A]   ��ѯ��[E]   ע����[S]");
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