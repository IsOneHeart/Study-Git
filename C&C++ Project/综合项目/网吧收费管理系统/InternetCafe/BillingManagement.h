#pragma once

void AdmC::UserLogIn(int adm_id) {
	system("cls");
	page();
	line("�� ��");
	spaceE("[�� ��]");
	int uid;
	std::cin >> uid;
	bool isfind = false;
	float amount;
	for (const auto& i : UL) {
		if (i.uid == uid && i.signout == false) {
			isfind = true;
			amount = i.card_amount;
			spaceE("[�� ��]");
			if (strcmp(i.password, GetPassword().data()) != 0) {
				space("�������");
				space(">>  ��������[N]     �˳�[ESC]  <<");
				char key;
				while (key = _getch()) {
					if (key == 'N' || key == 'n') {
						UserLogIn(adm_id);
					}
					if (key == 27)
						BM(adm_id);
				}
			}
			break;
		}
	}
	if (!isfind) {
		space("δ�ҵ��ÿ��ţ�");
		space(">>  ��������[N]     �˳�[ESC]  <<");
		char key;
		while (key = _getch()) {
			if (key == 'N' || key == 'n') {
				UserLogIn(adm_id);
			}
			if (key == 27)
				BM(adm_id);
		}
	}

	std::list<Log> logs = UserLogRead(uid);
	bool isLogedIn = false;
	for (const auto& i : logs) {
		if (i.flag == 'O')
			isLogedIn = false;
		if (i.flag == 'I')
			isLogedIn = true;
	}
	if (isLogedIn) {
		space("");
		space("���ϻ��������ظ�������");
		space(">>  ��������[N]     �˳�[ESC]  <<");
		char key;
		while (key = _getch()) {
			if (key == 'N' || key == 'n') {
				UserLogIn(adm_id);
			}
			if (key == 27)
				BM(adm_id);
		}
	}

	if (amount < 10) {
		space("");
		space("�����ϻ�һСʱ���޷��ϻ���");
		space("���������˳�...");
		_getch();
		BM(adm_id);
	}
	else {
		space("");
		space(">>ȷ��[Y] ����ѡ��[N] ȡ��[ESC]<<");
		char key;
		while (1) {
			key = _getch();
			if (key == 'Y' || key == 'y') {
				space("���ϻ������������˳�...");
				std::string newlog;
				newlog = std::to_string(uid) + " " + "I" + " " + GetTime() + " �ϻ�";
				spaceE("[LOG]");
				std::cout << newlog << std::endl;
				UserLogWrite(uid, 'I', "�ϻ�");
				_getch();
				BM(adm_id);
				break;
			}
			if (key == 'N' || key == 'n') {
				UserLogIn(adm_id);
				break;
			}
			if (key == 27) {
				BM(adm_id);
				break;
			}
		}
	}
}

void AdmC::UserLogOut(int adm_id) {
	system("cls");
	page();
	line("�� ��");
	spaceE("[�� ��]");
	int uid;
	std::cin >> uid;
	bool isfind = false;
	bool isvip = false;
	float amount;
	for (const auto& i : UL) {
		if (i.uid == uid && i.signout == false) {
			isfind = true;
			if (i.vip == true)
				isvip = true;
			amount = i.card_amount;
			spaceE("[�� ��]");
			if (strcmp(i.password, GetPassword().data()) != 0) {
				space("�������");
				space(">>  ��������[N]     �˳�[ESC]  <<");
				char key;
				while (key = _getch()) {
					if (key == 'N' || key == 'n') {
						UserLogIn(adm_id);
					}
					if (key == 27)
						BM(adm_id);
				}
			}
			break;
		}
	}
	if (!isfind) {
		space("δ�ҵ��ÿ��ţ�");
		space(">>  ��������[N]     �˳�[ESC]  <<");
		char key;
		while (key = _getch()) {
			if (key == 'N' || key == 'n') {
				UserLogIn(adm_id);
			}
			if (key == 27)
				BM(adm_id);
		}
	}

	std::list<Log> logs = UserLogRead(uid);
	bool isLogedIn = false;
	for (const auto& i : logs) {
		if (i.flag == 'O')
			isLogedIn = false;
		if (i.flag == 'I')
			isLogedIn = true;
	}
	if (!isLogedIn) {
		space("");
		space("���»��������ظ�������");
		space(">>  ��������[N]     �˳�[ESC]  <<");
		char key;
		while (key = _getch()) {
			if (key == 'N' || key == 'n') {
				UserLogOut(adm_id);
			}
			if (key == 27)
				BM(adm_id);
		}
	}

	space("");
	space(">>ȷ��[Y] ����ѡ��[N] ȡ��[ESC]<<");
	char key;
	while (1) {
		key = _getch();
		if (key == 'Y' || key == 'y') {
			space("���»������������˳�...");
			std::string newlog, now_time = GetTime();
			newlog = std::to_string(uid) + " " + "I" + " " + now_time + " �»�";
			spaceE("[LOG]");
			std::cout << newlog << std::endl;
			UserLogWrite(uid, 'O', "�»�");
			std::list<Log> logs = UserLogRead(uid);
			std::string target_time;
			for (const auto& i : logs) {
				if (i.flag == 'I') //���������һ��I flag
					target_time = i.data + " " + i.time;
			}
			float dh = TimeDifferenceInHours(now_time, target_time);
			float money;
			if (dh < 1) {
				money = 10 * dh;
			}
			else if (dh < 2) {
				money = 10 + 9 * (dh - 1);
			}
			else if (dh < 3) {
				money = 10 + 9 + 8 * (dh - 2);
			}
			else if (dh >= 3) {
				money = 10 + 9 + 8 + 7 * (dh - 3);
			}
			if (isvip)
				money *= static_cast<float>(0.8);
			spaceE("[�ϻ�ʱ��]");
			std::cout << dh << "Сʱ" << std::endl;
			spaceE("[�ϻ�����]");
			std::string desp = std::to_string(money);
			UserLogWrite(uid, 'P', desp);
			std::cout << money << "Ԫ" << (isvip ? "�������Ա�����Żݣ�":"") << std::endl;
			if (amount < money) {
				spaceE("�����㣡��ѡ��������ʽ֧����");
				money -= amount;
				UserLogWrite(uid, 'A', std::to_string(money));
				for (auto& i : UL) {
					if (i.uid == uid) {
						i.card_amount = 0;
						UserFileWrite();
						break;
					}
				}
			}
			else {
				for (auto& i : UL) {
					if (i.uid == uid) {
						i.card_amount -= money;
						UserFileWrite();
						break;
					}
				}
				space("�Զ��۷ѳɹ���");
			}
			_getch();
			BM(adm_id);
			break;
		}
		if (key == 'N' || key == 'n') {
			UserLogIn(adm_id);
			break;
		}
		if (key == 27) {
			BM(adm_id);
			break;
		}
	}
}

void AdmC::BM(int adm_id) {
	system("cls");
	page();
	line("�� �� �� �� ϵ ͳ");
	space("(��ESC���ع���ԱȨ��ϵͳ...)");
	space("��  ��[I]               ��  ��[O]");
	char key;
	while (key = _getch()) {
		if (key == 'I' || key == 'i')
			UserLogIn(adm_id);
		if (key == 'O' || key == 'o')
			UserLogOut(adm_id);
		if (key == 27)
			AdmMenu(adm_id);
	}
}