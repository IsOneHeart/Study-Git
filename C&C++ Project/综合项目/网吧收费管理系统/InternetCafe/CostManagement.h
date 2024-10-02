#pragma once

void AdmC::Recharge(int adm_id) {
	system("cls");
	page();
	line("�� ֵ");
	spaceE("[�� ��]");
	int uid;
	std::cin >> uid;
	bool isfind = false;
	for (const auto& i : UL) {
		if (i.uid == uid && i.signout == false) { //�˺�ע�����ɳ�ֵ
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
				Recharge(adm_id);
			}
			if (key == 27)
				CostM(adm_id);
		}
	}
	spaceE("[�� ��]");
	float c;
	while (1) {
		if (std::cin >> c) {
			std::cin.clear();
			if (std::cin.peek() == '\n' || std::cin.eof()) {
				break;
			}
			else {
				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				space("������Ч����ֻ�������֡�������������...");
				_getch();
				Recharge(adm_id);
			}
		}
		else {
			std::cin.clear();
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			space("������Ч����ֻ�������֡�������������...");
			_getch();
			Recharge(adm_id);
		}
	}
	space(">>ȷ��[Y] ����ѡ��[N] �˳�[ESC]<<");
	char key;
	while (key = _getch()) {
		if (key == 'Y' || key == 'y') {
			for (auto& i : UL) {
				if (i.uid == uid) {
					i.card_amount += abs(c);
					UserFileWrite();
					UserLogWrite(uid, 'C', std::to_string(c));
					break;
				}
			}
			space("��ֵ�ɹ���");
			CostM(adm_id);
		}
		if (key == 'N' || key == 'n') {
			Recharge(adm_id);
		}
		if (key == 27)
			CostM(adm_id);
	}
}

void AdmC::Refund(int adm_id) {
	system("cls");
	page();
	line("�� ��");
	spaceE("[�� ��]");
	int uid;
	std::cin >> uid;
	bool isfind = false;
	for (const auto& i : UL) {
		if (i.uid == uid) { // �˺�ע��Ҳ���˷�
			isfind = true;
			spaceE("[���˶�]");
			std::cout << i.card_amount << std::endl;
			break;
		}
	}
	if (!isfind) {
		space("δ�ҵ��ÿ��ţ�");
		space(">>  ����ѡ��[N]     �˳�[ESC]  <<");
		char key;
		while (key = _getch()) {
			if (key == 'N' || key == 'n') {
				Refund(adm_id);
			}
			if (key == 27)
				CostM(adm_id);
		}
	}
	spaceE("[�˿��]");
	float c;
	while (1) {
		if (std::cin >> c) {
			std::cin.clear();
			if (std::cin.peek() == '\n' || std::cin.eof()) {
				break;
			}
			else {
				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				space("������Ч����ֻ�������֡�������������...");
				_getch();
				Recharge(adm_id);
			}
		}
		else {
			std::cin.clear();
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			space("������Ч����ֻ�������֡�������������...");
			_getch();
			Recharge(adm_id);
		}
	}
	space(">>ȷ��[Y] ����ѡ��[N] �˳�[ESC]<<");
	char key;
	while (key = _getch()) {
		if (key == 'Y' || key == 'y') {
			for (auto& i : UL) {
				if (i.uid == uid) {
					i.card_amount -= (i.card_amount > c ? c : i.card_amount);
					UserFileWrite();
					UserLogWrite(uid, 'F', std::to_string(c));
					break;
				}
			}
			space("�˷ѳɹ���");
			CostM(adm_id);
		}
		if (key == 'N' || key == 'n') {
			Recharge(adm_id);
		}
		if (key == 27)
			CostM(adm_id);
	}
}

void AdmC::CostM(int adm_id) {
	system("cls");
	page();
	line("�� �� �� �� ϵ ͳ");
	space("(��ESC���ع���ԱȨ��ϵͳ...)");
	space("��  ֵ[C]               ��  ��[F]");
	char key;
	while (key = _getch()) {
		if (key == 'C' || key == 'c')
			Recharge(adm_id);
		if (key == 'F' || key == 'f')
			Refund(adm_id);
		if (key == 27)
			AdmMenu(adm_id);
	}
}