#pragma once

void AdmC::Recharge(int adm_id) {
	system("cls");
	page();
	line("充 值");
	spaceE("[卡 号]");
	int uid;
	std::cin >> uid;
	bool isfind = false;
	for (const auto& i : UL) {
		if (i.uid == uid && i.signout == false) { //账号注销不可充值
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
				Recharge(adm_id);
			}
			if (key == 27)
				CostM(adm_id);
		}
	}
	spaceE("[金 额]");
	float c;
	while (1) {
		if (std::cin >> c) {
			std::cin.clear();
			if (std::cin.peek() == '\n' || std::cin.eof()) {
				break;
			}
			else {
				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				space("输入无效，请只输入数字。点击任意键继续...");
				_getch();
				Recharge(adm_id);
			}
		}
		else {
			std::cin.clear();
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			space("输入无效，请只输入数字。点击任意键继续...");
			_getch();
			Recharge(adm_id);
		}
	}
	space(">>确定[Y] 重新选择[N] 退出[ESC]<<");
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
			space("充值成功！");
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
	line("退 费");
	spaceE("[卡 号]");
	int uid;
	std::cin >> uid;
	bool isfind = false;
	for (const auto& i : UL) {
		if (i.uid == uid) { // 账号注销也可退费
			isfind = true;
			spaceE("[可退额]");
			std::cout << i.card_amount << std::endl;
			break;
		}
	}
	if (!isfind) {
		space("未找到该卡号！");
		space(">>  重新选择[N]     退出[ESC]  <<");
		char key;
		while (key = _getch()) {
			if (key == 'N' || key == 'n') {
				Refund(adm_id);
			}
			if (key == 27)
				CostM(adm_id);
		}
	}
	spaceE("[退款额]");
	float c;
	while (1) {
		if (std::cin >> c) {
			std::cin.clear();
			if (std::cin.peek() == '\n' || std::cin.eof()) {
				break;
			}
			else {
				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				space("输入无效，请只输入数字。点击任意键继续...");
				_getch();
				Recharge(adm_id);
			}
		}
		else {
			std::cin.clear();
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			space("输入无效，请只输入数字。点击任意键继续...");
			_getch();
			Recharge(adm_id);
		}
	}
	space(">>确定[Y] 重新选择[N] 退出[ESC]<<");
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
			space("退费成功！");
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
	line("费 用 管 理 系 统");
	space("(按ESC返回管理员权限系统...)");
	space("充  值[C]               退  费[F]");
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