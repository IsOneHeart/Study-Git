#pragma once

int AdmC::BSExamine(int adm_id) {
    system("cls");
    page();
    line("�� �� �� ׼");
    space("<-������һ��[ESC]");
    std::cout << std::endl;
    std::ifstream fp("data\\rate.txt");
    if (!fp.is_open()) {
        std::cerr << "�ļ���ʧ�ܣ�" << std::endl;
        return 0;
    }
    std::string line;
    while (std::getline(fp, line)) {
        if (line != "<rate>\n" && line != "<rate>") {
            std::cout << line << std::endl;
        }
    }
    fp.close();
    char key2;
    while ((key2 = _getch()) != 27) {
    }
    BSM(adm_id);
    return 1;
}

int AdmC::BSAdd(int adm_id) {
    system("cls");
    page();
    line("�� �� �� �� �� ׼");
    FILE* fp;
    char words[1000];
    space("������׼��(���롮#������)\n");
    printf("<<\n");
    if (fopen_s(&fp, "data//rate.txt", "a+") != 0) {
        printf("�ļ���ʧ�ܣ�");
        return 0;
    }
    fprintf_s(fp, "<rate>\n\n");
    while (1) {
        if (scanf_s("%999s", words, static_cast<unsigned int>(sizeof(words))) != 1) { // ��ȡ���999���ַ�������һ��λ�ø����ַ�   
            continue;
        }
        size_t len = strlen(words);
        if (len > 0 && words[len - 1] == '#') {
            words[len - 1] = '\n'; // ֱ�ӽ� '#' �滻Ϊ���ַ�   
            fprintf(fp, "%s", words); // д�벻���� '#' ���ַ���  
            break; // ����������˳�ѭ��  
        }
        fprintf(fp, "%s\n", words);
    }
    printf("\n");
    space("���������");
    fclose(fp);
    space("<-������һ��[ESC]");
    while (1) {
        char key = _getch();
        if (key == 27) {
            BSM(adm_id);
            break;
        }
    }
    return 1;
}

int AdmC::BSDel(int adm_id) {
    system("cls");
    page();
    line("ɾ �� �� �� �� ׼");
    space("<-������һ��[ESC]");
    std::cout << std::endl;
    std::ifstream inFile("data/rate.txt");
    if (!inFile) {
        std::cerr << "�ļ���ʧ�ܣ�" << std::endl;
        return 0;
    }
    std::string line;
    std::vector<std::string> rateBlocks;
    bool inRateBlock = false;
    std::string currentBlock;
    while (std::getline(inFile, line)) {
        if (line == "<rate>") {
            if (inRateBlock) { 
                rateBlocks.push_back(currentBlock);
            }
            inRateBlock = true;
            currentBlock.clear();
        }
        else if (inRateBlock) { 
            currentBlock += line + "\n";
        }
    }
    if (inRateBlock && !currentBlock.empty()) {
        rateBlocks.push_back(currentBlock);
    }
    if (rateBlocks.empty()) {
        std::cout << "û���ҵ��κ�<rate>�飡" << std::endl;
        return 1;
    } 
    for (size_t i = 0; i < rateBlocks.size(); ++i) {
        std::cout << CenterSpace << "��" << (i + 1) << "��\n" << rateBlocks[i];
    }
    int choice;
    std::cout << CenterSpace << "������Ҫɾ���ı�׼��ţ�1-" << rateBlocks.size() << "��: ";
    std::cin >> choice;
    if (choice < 1 || choice > rateBlocks.size()) {
        space("������Ч����������Ч����ţ�");
        space("������������...");
        _getch();
        BSDel(adm_id);
        return 1;
    }
    // ɾ��ָ���� rate ��  
    rateBlocks.erase(rateBlocks.begin() + (choice - 1));
    // ����һ����ʱ�ļ��������޸ĺ������  
    std::ofstream tempFile("data//rate_temp.txt");
    if (!tempFile) {
        std::cerr << "��ʱ�ļ�����ʧ�ܣ�" << std::endl;
        return 0;
    }

    // ���޸ĺ�� rate ��д�ص���ʱ�ļ���  
    for (const auto& block : rateBlocks) {
        tempFile << "<rate>\n" << block << std::endl;
    }

    tempFile.close();
    std::ifstream tempFileStream("data/rate_temp.txt");
    if (!tempFileStream) {
        std::cerr << "�޷�����ʱ�ļ� data/rate_temp.txt" << std::endl;
        return 1;
    }
    // ԭʼ�ļ�
    std::fstream File("data/rate.txt", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc); // ʹ�� binary ģʽ�Է��в��ɼ��������ַ�  
    if (!File) {
        std::cerr << "�޷���ԭʼ�ļ� data/rate.txt" << std::endl;
        tempFileStream.close(); // �ر���ʱ�ļ���  
        return 1;
    }
    // �����ļ�
    std::ofstream BackupFile("data/rate_backup.txt");
    if (!BackupFile) {
        std::cerr << "�޷����������ļ� data/rate_backup.txt" << std::endl;
        tempFileStream.close(); // �ر���ʱ�ļ���  
        File.close(); // �ر�ԭʼ�ļ���  
        return 1;
    }
    // ��ԭʼ�ļ������ݸ��Ƶ������ļ���  
    BackupFile << File.rdbuf(); // ʹ�� rdbuf() ��������������������   
    File << tempFileStream.rdbuf();
    // �ر������ļ���  
    tempFileStream.close();
    File.close();
    BackupFile.close();

    /*
    // ɾ��ԭʼ�ļ�  
    if (std::remove("data/rate.txt") != 0) {
        std::cerr << "ԭʼ�ļ�ɾ��ʧ�ܣ�" << std::endl;
    }
    // ����ʱ�ļ�������Ϊԭʼ�ļ���  
    if (std::rename("data/rate_temp.txt", "data//rate.txt") != 0) {
        std::cerr << "��ʱ�ļ�������ʧ�ܣ�" << std::endl;
    }
    */

    space("�Ʒѱ�׼�ѳɹ�ɾ����");
    while ((_getch()) != 27) {
    }
    BSM(adm_id);
    return 1;
}

int AdmC::BSDel(int adm_id, int choice) {
    std::ifstream inFile("data/rate.txt");
    if (!inFile) {
        std::cerr << "�ļ���ʧ�ܣ�" << std::endl;
        return 0;
    }
    std::string line;
    std::vector<std::string> rateBlocks;
    bool inRateBlock = false;
    std::string currentBlock;
    while (std::getline(inFile, line)) {
        if (line == "<rate>") {
            if (inRateBlock) {
                rateBlocks.push_back(currentBlock);
            }
            inRateBlock = true;
            currentBlock.clear();
        }
        else if (inRateBlock) {
            currentBlock += line + "\n";
        }
    }
    if (inRateBlock && !currentBlock.empty()) {
        rateBlocks.push_back(currentBlock);
    }
    if (rateBlocks.empty()) {
        std::cout << "û���ҵ��κ�<rate>�飡" << std::endl;
        return 1;
    }
    for (size_t i = 0; i < rateBlocks.size(); ++i) {
        std::cout << "��" << (i + 1) << "��\n" << rateBlocks[i] << std::endl;
    }
    if (choice < 1 || choice > rateBlocks.size()) {
        return 0;
    }
    // ɾ��ָ���� rate ��  
    rateBlocks.erase(rateBlocks.begin() + (choice - 1));
    // ����һ����ʱ�ļ��������޸ĺ������  
    std::ofstream tempFile("data//rate_temp.txt");
    if (!tempFile) {
        std::cerr << "��ʱ�ļ�����ʧ�ܣ�" << std::endl;
        return 0;
    }

    // ���޸ĺ�� rate ��д�ص���ʱ�ļ���  
    for (const auto& block : rateBlocks) {
        tempFile << "<rate>\n" << block << std::endl;
    }

    tempFile.close();
    std::ifstream tempFileStream("data/rate_temp.txt");
    if (!tempFileStream) {
        std::cerr << "�޷�����ʱ�ļ� data/rate_temp.txt" << std::endl;
        return 1;
    }
    // ԭʼ�ļ�
    std::fstream File("data/rate.txt", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc); // ʹ�� binary ģʽ�Է��в��ɼ��������ַ�  
    if (!File) {
        std::cerr << "�޷���ԭʼ�ļ� data/rate.txt" << std::endl;
        tempFileStream.close(); // �ر���ʱ�ļ���  
        return 1;
    }
    // �����ļ�
    std::ofstream BackupFile("data/rate_backup.txt");
    if (!BackupFile) {
        std::cerr << "�޷����������ļ� data/rate_backup.txt" << std::endl;
        tempFileStream.close(); // �ر���ʱ�ļ���  
        File.close(); // �ر�ԭʼ�ļ���  
        return 1;
    }
    // ��ԭʼ�ļ������ݸ��Ƶ������ļ���  
    BackupFile << File.rdbuf(); // ʹ�� rdbuf() ��������������������   
    File << tempFileStream.rdbuf();
    // �ر������ļ���  
    tempFileStream.close();
    File.close();
    BackupFile.close();

    return 1;
}

int AdmC::BSModify(int adm_id) {
    system("cls");
    page();
    line("�� �� �� �� �� ׼");
    space("<-������һ��[ESC]");
    std::cout << std::endl;
    std::ifstream inFile("data/rate.txt");
    if (!inFile) {
        std::cerr << "�ļ���ʧ�ܣ�" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> rateBlocks;
    bool inRateBlock = false;
    std::string currentBlock;
    while (std::getline(inFile, line)) {
        if (line == "<rate>") {
            if (inRateBlock) {
                rateBlocks.push_back(currentBlock);
            }
            inRateBlock = true;
            currentBlock.clear();
        }
        else if (inRateBlock) {
            currentBlock += line + "\n";
        }
    }
    if (inRateBlock && !currentBlock.empty()) {
        rateBlocks.push_back(currentBlock);
    }

    if (rateBlocks.empty()) {
        std::cout << CenterSpace << "û���ҵ��κ�<rate>�飡" << std::endl;
        return 1;
    }

    // ��ʾ�����ݲ����û�ѡ��  
    for (size_t i = 0; i < rateBlocks.size(); ++i) {
        std::cout << CenterSpace <<"��" << (i + 1) << "��\n" << rateBlocks[i] << std::endl;
    }
    int choice;
    std::cout << "������Ҫ�޸ĵı�׼��ţ�1-" << rateBlocks.size() << "��: ";
    std::cin >> choice;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����  

    if (choice < 1 || choice > rateBlocks.size()) {
        space("������Ч����������Ч����ţ�");
        space("������������...");
        _getch(); 
        return 1;
    }

    // ��ȡ�û��������<rate>������  
    std::string newRateBlock;
    space("�޸ı�׼��(���롮#������)\n<<");
    std::getline(std::cin, newRateBlock, '#');

    // ���޸ĺ������д�ص�һ���µ���ʱ�ļ���  
    std::ofstream tempFile("data/rate_temp.txt");
    if (!tempFile) {
        std::cerr << "��ʱ�ļ���ʧ�ܣ�" << std::endl;
        return 1;
    }

    // ���´�ԭʼ�ļ��Զ�ȡ��д���ѡ����֮�������  
    inFile.clear(); // ����ļ������κδ���״̬  
    inFile.seekg(0, std::ios::beg); // ���ļ�ָ���ƻ��ļ���ͷ  

    size_t blockIndex = static_cast<size_t>(choice - 1);
    size_t currentBlockIndex = 0;
    bool isModifying = false;

    while (std::getline(inFile, line)) {
        if (line == "<rate>") {
            if (currentBlockIndex == blockIndex) {
                tempFile << "<rate>\n" << newRateBlock; // д���µ�<rate>��  
                if (!tempFile.eof())
                    tempFile << "<rate>\n";
                isModifying = true;
            }
            else {
                tempFile << line << std::endl; // д��ԭʼ<rate>��ǩ  
            }
            currentBlockIndex++;
        }
        else {
            if (isModifying && currentBlockIndex == blockIndex) {
                continue;
            }
            tempFile << line << std::endl; // д���<rate>������ݻ�����<rate>�������  
        }
    }

    inFile.close();
    tempFile.close();

    std::ifstream tempFileStream("data/rate_temp.txt");
    if (!tempFileStream) {
        std::cerr << "�޷�����ʱ�ļ� data/rate_temp.txt" << std::endl;
        return 1;
    }
    // ԭʼ�ļ�
    std::fstream File("data/rate.txt", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc); // ʹ�� binary ģʽ�Է��в��ɼ��������ַ�  
    if (!File) {
        std::cerr << "�޷���ԭʼ�ļ� data/rate.txt" << std::endl;
        tempFileStream.close(); 
    }
    // �����ļ�
    std::ofstream BackupFile("data/rate_backup.txt");
    if (!BackupFile) {
        std::cerr << "�޷����������ļ� data/rate_backup.txt" << std::endl;
        tempFileStream.close(); 
        File.close();  
        return 1;
    }
    // ��ԭʼ�ļ������ݸ��Ƶ������ļ���  
    BackupFile << File.rdbuf(); // ʹ�� rdbuf() ��������������������   
    File << tempFileStream.rdbuf();
    tempFileStream.close();
    File.close();
    BackupFile.close();

    BSDel(adm_id, choice + 1);

    space("�Ʒѱ�׼�ѳɹ�ɾ����");
    while ((_getch()) != 27) {
    }
    BSM(adm_id);
    return 1;
}

void AdmC::BSM(int adm_id) {
    system("cls");
    page();
    line("�Ʒѱ�׼����");
    space("(��ESC���ع���ԱȨ��ϵͳ...)");
    space("�鿴�Ʒѱ�׼[1] �����Ʒѱ�׼[2]");
    space("ɾ���Ʒѱ�׼[3] �޸ļƷѱ�׼[4]");
    while (1) {
        char key = _getch();
        bool isbreak = false;
        switch (key) {
        case '1':
            BSExamine(adm_id);
            isbreak = true;
            break;
        case '2':
            BSAdd(adm_id);
            isbreak = true;
            break;
        case '3':
            BSDel(adm_id);
            isbreak = true;
            break;
        case '4':
            BSModify(adm_id);
            isbreak = true;
            break;
        case 27:
            AdmMenu(adm_id);
            break;
        }
        if (isbreak)
            break;
    }
}