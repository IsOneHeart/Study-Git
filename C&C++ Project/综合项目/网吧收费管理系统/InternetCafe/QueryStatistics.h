#pragma once

void AdmC::QueryTranRecords(int adm_id) {
	system("cls");
	page();
	line("�� ѯ �� �� �� ¼");
	int uid;
	spaceE("[�� ��]");
	std::cin >> uid;
	bool isfind = false;
	for (const auto& i : UL) {
		if (i.uid == uid && i.signout == false) {
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
				QueryTranRecords(adm_id);
			}
			if (key == 27)
				QueryStatistics(adm_id);
		}
	}

	int year, month, year1, month1;
	spaceE("[��ʼ���]");
	std::cin >> year;
	spaceE("[��ʼ�·�]");
	std::cin >> month;
	spaceE("[��ֹ���]");
	std::cin >> year1;
	spaceE("[��ֹ�·�]");
	std::cin >> month1;
	if (month < 1 || month>12 || month1 < 1 || month1>12) {
		space("�·��������");
		space(">>  ����ѡ��[N]     �˳�[ESC]  <<");
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
				std::cout << CenterSpace << time << " " << (i.flag == 'P' ? "����" : (i.flag == 'C' ? "��ֵ": "������ʽ֧��")) << i.desp << "Ԫ" << std::endl;
			}
		}
	}
	if (!find) {
		space("δ�ҵ���ؼ�¼��");
	}
	space("<-������һ��[ESC]");
	while (char key = _getch()) {
		if (key == 27)
			break;
	}
	QueryStatistics(adm_id);
}

void AdmC::CalTotalRevenue(int adm_id) {
	system("cls");
	page();
	line("ͳ �� �� Ӫ ҵ ��");
	int year, month, year1, month1;
	spaceE("[��ʼ���]");
	std::cin >> year;
	spaceE("[��ʼ�·�]");
	std::cin >> month;
	spaceE("[��ֹ���]");
	std::cin >> year1;
	spaceE("[��ֹ�·�]");
	std::cin >> month1;
	if (month < 1 || month>12 || month1 < 1 || month1>12) {
		space("�·��������");
		space(">>  ����ѡ��[N]     �˳�[ESC]  <<");
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
				std::cerr << CenterSpace << "��������: " << e.what() << std::endl;
			}
		}
		inFile.close();
	} 
	std::cout << CenterSpace << "[��Ӫҵ��]" << total << "Ԫ" << std::endl;
	space("<-������һ��[ESC]");
	while (char key = _getch()) {
		if (key == 27)
			break;
	}
	QueryStatistics(adm_id);
}

void AdmC::CalMonthlyRevenue(int adm_id) {
	system("cls");
	page();
	line("ͳ �� �� Ӫ ҵ ��");
	int year;
	spaceE("[�� ��]");
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
					std::cerr << CenterSpace << "��������: " << e.what() << std::endl;
				}
			}
		}
		inFile.close();
	}
	std::string monthZH[12] = {"һ  ","��  ","��  ","��  ","��  ","��  ",
		"��  ","��  ","��  ","ʮ  ","ʮһ","ʮ��" };
	std::string result[12] = {};
	for (int i = 0;i < 12;i++) {
		result[i] = "[" + monthZH[i] + "��]Ӫҵ��" + std::to_string(rev[i]) + "Ԫ���ϻ�����" + to_string(LogInCount[i]) + "��";
		std::cout << CenterSpace << result[i] << std::endl;
	}
	ofstream outFile("data/rev/" + to_string(year) + ".txt");
	if (!outFile.is_open()) {
		space("�ļ���ʧ�ܣ��޷��������ļ���");
	}
	else {
		for (int i = 0;i < 12;i++) {
			outFile << result[i] << endl;
		}
		cout << CenterSpace << "�ѱ�����.../data/rev/" << year << ".txt" << endl;
	}

	space("<-������һ��[ESC]");
	while (char key = _getch()) {
		if (key == 27)
			break;
	}
	QueryStatistics(adm_id);
}

void AdmC::QueryStatistics(int adm_id) {
	system("cls");
	page();
	line("�� ѯ ϵ ͳ");
	space("<-������һ��[ESC]");
	space("��ѯ���Ѽ�¼[E]   ͳ����Ӫҵ��[T]");
	space("ͳ����Ӫҵ��[M]");
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