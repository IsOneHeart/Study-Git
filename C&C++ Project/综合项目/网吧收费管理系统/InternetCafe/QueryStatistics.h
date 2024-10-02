#pragma once

void AdmC::QueryTranRecords(int adm_id) {
	system("cls");
	page();
	line("查 询 消 费 记 录");
	int uid;
	spaceE("[卡 号]");
	std::cin >> uid;
	bool isfind = false;
	for (const auto& i : UL) {
		if (i.uid == uid && i.signout == false) {
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
				QueryTranRecords(adm_id);
			}
			if (key == 27)
				QueryStatistics(adm_id);
		}
	}

	int year, month, year1, month1;
	spaceE("[起始年份]");
	std::cin >> year;
	spaceE("[起始月份]");
	std::cin >> month;
	spaceE("[终止年份]");
	std::cin >> year1;
	spaceE("[终止月份]");
	std::cin >> month1;
	if (month < 1 || month>12 || month1 < 1 || month1>12) {
		space("月份输入出错！");
		space(">>  重新选择[N]     退出[ESC]  <<");
		char key;
		while (key = _getch()) {
			if (key == 'N' || key == 'n') {
				QueryTranRecords(adm_id);
			}
			if (key == 27)
				QueryStatistics(adm_id);
		}
	}
	std::string time_low, time_high;
	if (month < 10) {
		time_low = std::to_string(year) + "-0" + std::to_string(month) + "-" + "01 00:00:00";
	}
	else
		time_low = std::to_string(year) + "-" + std::to_string(month) + "-" + "01 00:00:00";
	if (month1 < 10) {
		time_high = std::to_string(year1) + "-0" + std::to_string(month1) + "-" + "01 00:00:00";
	}
	else
		time_high = std::to_string(year1) + "-" + std::to_string(month1) + "-" + "01 00:00:00";
	std::list<Log> logs = UserLogRead(uid);
	bool find = false;
	for (const auto& i : logs) {
		if (i.flag == 'P' || i.flag == 'C' || i.flag == 'A') {
			find = true;
			std::string time = i.data + " " + i.time;
			if (isChiocedTime(time_low, time_high, time)) {
				std::cout << CenterSpace << time << " " << (i.flag == 'P' ? "消费" : (i.flag == 'C' ? "充值": "其他方式支付")) << i.desp << "元" << std::endl;
			}
		}
	}
	if (!find) {
		space("未找到相关记录！");
	}
	space("<-返回上一级[ESC]");
	while (char key = _getch()) {
		if (key == 27)
			break;
	}
	QueryStatistics(adm_id);
}

void AdmC::CalTotalRevenue(int adm_id) {
	system("cls");
	page();
	line("统 计 总 营 业 额");
	int year, month, year1, month1;
	spaceE("[起始年份]");
	std::cin >> year;
	spaceE("[起始月份]");
	std::cin >> month;
	spaceE("[终止年份]");
	std::cin >> year1;
	spaceE("[终止月份]");
	std::cin >> month1;
	if (month < 1 || month>12 || month1 < 1 || month1>12) {
		space("月份输入出错！");
		space(">>  重新选择[N]     退出[ESC]  <<");
		char key;
		while (key = _getch()) {
			if (key == 'N' || key == 'n') {
				QueryTranRecords(adm_id);
			}
			if (key == 27)
				QueryStatistics(adm_id);
		}
	}
	std::string time_low, time_high;
	if (month < 10) {
		time_low = std::to_string(year) + "-0" + std::to_string(month) + "-" + "01 00:00:00";
	}
	else
		time_low = std::to_string(year) + "-" + std::to_string(month) + "-" + "01 00:00:00";
	if (month1 < 10) {
		time_high = std::to_string(year1) + "-0" + std::to_string(month1) + "-" + "01 00:00:00";
	}
	else
		time_high = std::to_string(year1) + "-" + std::to_string(month1) + "-" + "01 00:00:00";
	using namespace std;
	int filenum = 10000;
	float total = 0;
	while (1) {
		string filename = to_string(filenum) + "U.txt";
		ifstream inFile("data/log/" + filename);
		if (!inFile.is_open())
			break;
		filenum++;
		string line;
		while (getline(inFile, line)) {
			int uid;
			char flag;
			std::string data, time, desp;
			stringstream ss(line);
			if (!(ss >> uid >> flag >> data >> time >> desp)) {
				continue;
			}
			try {
				if (flag == 'C' || flag == 'A') {
					std::string time_str = data + " " + time;
					if (isChiocedTime(time_low, time_high, time_str)) {
						total += stof(desp);
					}
				}
				if (flag == 'F') {
					std::string time_str = data + " " + time;
					if (isChiocedTime(time_low, time_high, time_str)) {
						total -= stof(desp);
					}
				}
			}
			catch (const std::exception& e) {
				std::cerr << CenterSpace << "解析错误: " << e.what() << std::endl;
			}
		}
		inFile.close();
	} 
	std::cout << CenterSpace << "[总营业额]" << total << "元" << std::endl;
	space("<-返回上一级[ESC]");
	while (char key = _getch()) {
		if (key == 27)
			break;
	}
	QueryStatistics(adm_id);
}

void AdmC::CalMonthlyRevenue(int adm_id) {
	system("cls");
	page();
	line("统 计 月 营 业 额");
	int year;
	spaceE("[年 份]");
	std::cin >> year;
	std::string time_low = std::to_string(year) + "-01-01 00:00:00";
	std::string time_high;
	float rev[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	using namespace std;
	int filenum = 10000;
	int LogInCount[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	while (1) {
		string filename = to_string(filenum) + "U.txt";
		ifstream inFile("data/log/" + filename);
		if (!inFile.is_open())
			break;
		filenum++;
		string line;
		int month = 1;
		while (month <= 12) {
			if (month < 10)
				time_high = std::to_string(year + 1) + "-0" + std::to_string(month) + "-01 00:00 : 00";
			else
				time_high = std::to_string(year + 1) + "-" + std::to_string(month) + "-01 00:00 : 00";
			month++;
			while (getline(inFile, line)) {
				int uid;
				char flag;
				std::string data, time, desp;
				stringstream ss(line);
				if (!(ss >> uid >> flag >> data >> time >> desp)) {
					continue;
				}
				if (flag == 'I') {
					LogInCount[month-1]++;
				}
				try {
					if (flag == 'C' || flag == 'A') {
						std::string time_str = data + " " + time;
						if (isChiocedTime(time_low, time_high, time_str)) {
							rev[month-1] += stof(desp);
						}
					}
					if (flag == 'F') {
						std::string time_str = data + " " + time;
						if (isChiocedTime(time_low, time_high, time_str)) {
							rev[month - 1] -= stof(desp);
						}
					}
				}
				catch (const std::exception& e) {
					std::cerr << CenterSpace << "解析错误: " << e.what() << std::endl;
				}
			}
		}
		inFile.close();
	}
	std::string monthZH[12] = {"一  ","二  ","三  ","四  ","五  ","六  ",
		"七  ","八  ","九  ","十  ","十一","十二" };
	std::string result[12] = {};
	for (int i = 0;i < 12;i++) {
		result[i] = "[" + monthZH[i] + "月]营业额" + std::to_string(rev[i]) + "元，上机次数" + to_string(LogInCount[i]) + "次";
		std::cout << CenterSpace << result[i] << std::endl;
	}
	ofstream outFile("data/rev/" + to_string(year) + ".txt");
	if (!outFile.is_open()) {
		space("文件打开失败，无法保存至文件！");
	}
	else {
		for (int i = 0;i < 12;i++) {
			outFile << result[i] << endl;
		}
		cout << CenterSpace << "已保存至.../data/rev/" << year << ".txt" << endl;
	}

	space("<-返回上一级[ESC]");
	while (char key = _getch()) {
		if (key == 27)
			break;
	}
	QueryStatistics(adm_id);
}

void AdmC::QueryStatistics(int adm_id) {
	system("cls");
	page();
	line("查 询 系 统");
	space("<-返回上一级[ESC]");
	space("查询消费记录[E]   统计总营业额[T]");
	space("统计月营业额[M]");
	char key;
	while (key = _getch()) {
		if (key == 'E' || key == 'e') {
			QueryTranRecords(adm_id);
		}
		if (key == 'T' || key == 't') {
			CalTotalRevenue(adm_id);
		}
		if (key == 'M' || key == 'm') {
			CalMonthlyRevenue(adm_id);
		}
		if (key == 27) {
			AdmMenu(adm_id);
		}
	}
}