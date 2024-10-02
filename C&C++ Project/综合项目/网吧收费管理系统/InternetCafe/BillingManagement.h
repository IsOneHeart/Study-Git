#pragma once

void AdmC::UserLogIn(int adm_id) {
	system("cls");
	page();
	line("上 机");
	spaceE("[卡 号]");
	int uid;
	std::cin >> uid;
	bool isfind = false;
	float amount;
	for (const auto& i : UL) {
		if (i.uid == uid && i.signout == false) {
			isfind = true;
			amount = i.card_amount;
			spaceE("[密 码]");
			if (strcmp(i.password, GetPassword().data()) != 0) {
				space("密码错误！");
				space(">>  重新输入[N]     退出[ESC]  <<");
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
		space("未找到该卡号！");
		space(">>  重新输入[N]     退出[ESC]  <<");
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
		space("已上机，不可重复操作！");
		space(">>  重新输入[N]     退出[ESC]  <<");
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
		space("余额不足上机一小时，无法上机！");
		space("点击任意键退出...");
		_getch();
		BM(adm_id);
	}
	else {
		space("");
		space(">>确认[Y] 重新选择[N] 取消[ESC]<<");
		char key;
		while (1) {
			key = _getch();
			if (key == 'Y' || key == 'y') {
				space("已上机！点击任意键退出...");
				std::string newlog;
				newlog = std::to_string(uid) + " " + "I" + " " + GetTime() + " 上机";
				spaceE("[LOG]");
				std::cout << newlog << std::endl;
				UserLogWrite(uid, 'I', "上机");
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
	line("下 机");
	spaceE("[卡 号]");
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
			spaceE("[密 码]");
			if (strcmp(i.password, GetPassword().data()) != 0) {
				space("密码错误！");
				space(">>  重新输入[N]     退出[ESC]  <<");
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
		space("未找到该卡号！");
		space(">>  重新输入[N]     退出[ESC]  <<");
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
		space("已下机，不可重复操作！");
		space(">>  重新输入[N]     退出[ESC]  <<");
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
	space(">>确认[Y] 重新选择[N] 取消[ESC]<<");
	char key;
	while (1) {
		key = _getch();
		if (key == 'Y' || key == 'y') {
			space("已下机！点击任意键退出...");
			std::string newlog, now_time = GetTime();
			newlog = std::to_string(uid) + " " + "I" + " " + now_time + " 下机";
			spaceE("[LOG]");
			std::cout << newlog << std::endl;
			UserLogWrite(uid, 'O', "下机");
			std::list<Log> logs = UserLogRead(uid);
			std::string target_time;
			for (const auto& i : logs) {
				if (i.flag == 'I') //遍历到最后一个I flag
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
			spaceE("[上机时长]");
			std::cout << dh << "小时" << std::endl;
			spaceE("[上机费用]");
			std::string desp = std::to_string(money);
			UserLogWrite(uid, 'P', desp);
			std::cout << money << "元" << (isvip ? "（已享会员八折优惠）":"") << std::endl;
			if (amount < money) {
				spaceE("卡余额不足！请选择其他方式支付。");
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
				space("自动扣费成功！");
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
	line("计 费 管 理 系 统");
	space("(按ESC返回管理员权限系统...)");
	space("上  机[I]               下  机[O]");
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