#pragma once

int AdmC::BSExamine(int adm_id) {
    system("cls");
    page();
    line("计 费 标 准");
    space("<-返回上一级[ESC]");
    std::cout << std::endl;
    std::ifstream fp("data\\rate.txt");
    if (!fp.is_open()) {
        std::cerr << "文件打开失败！" << std::endl;
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
    line("新 增 计 费 标 准");
    FILE* fp;
    char words[1000];
    space("新增标准：(输入‘#’结束)\n");
    printf("<<\n");
    if (fopen_s(&fp, "data//rate.txt", "a+") != 0) {
        printf("文件打开失败！");
        return 0;
    }
    fprintf_s(fp, "<rate>\n\n");
    while (1) {
        if (scanf_s("%999s", words, static_cast<unsigned int>(sizeof(words))) != 1) { // 读取最多999个字符，保留一个位置给空字符   
            continue;
        }
        size_t len = strlen(words);
        if (len > 0 && words[len - 1] == '#') {
            words[len - 1] = '\n'; // 直接将 '#' 替换为空字符   
            fprintf(fp, "%s", words); // 写入不包含 '#' 的字符串  
            break; // 输入结束，退出循环  
        }
        fprintf(fp, "%s\n", words);
    }
    printf("\n");
    space("输入结束！");
    fclose(fp);
    space("<-返回上一级[ESC]");
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
    line("删 除 计 费 标 准");
    space("<-返回上一级[ESC]");
    std::cout << std::endl;
    std::ifstream inFile("data/rate.txt");
    if (!inFile) {
        std::cerr << "文件打开失败！" << std::endl;
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
        std::cout << "没有找到任何<rate>块！" << std::endl;
        return 1;
    } 
    for (size_t i = 0; i < rateBlocks.size(); ++i) {
        std::cout << CenterSpace << "【" << (i + 1) << "】\n" << rateBlocks[i];
    }
    int choice;
    std::cout << CenterSpace << "请输入要删除的标准序号（1-" << rateBlocks.size() << "）: ";
    std::cin >> choice;
    if (choice < 1 || choice > rateBlocks.size()) {
        space("输入无效，请输入有效的序号！");
        space("点击任意键继续...");
        _getch();
        BSDel(adm_id);
        return 1;
    }
    // 删除指定的 rate 块  
    rateBlocks.erase(rateBlocks.begin() + (choice - 1));
    // 创建一个临时文件来保存修改后的内容  
    std::ofstream tempFile("data//rate_temp.txt");
    if (!tempFile) {
        std::cerr << "临时文件创建失败！" << std::endl;
        return 0;
    }

    // 将修改后的 rate 块写回到临时文件中  
    for (const auto& block : rateBlocks) {
        tempFile << "<rate>\n" << block << std::endl;
    }

    tempFile.close();
    std::ifstream tempFileStream("data/rate_temp.txt");
    if (!tempFileStream) {
        std::cerr << "无法打开临时文件 data/rate_temp.txt" << std::endl;
        return 1;
    }
    // 原始文件
    std::fstream File("data/rate.txt", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc); // 使用 binary 模式以防有不可见的特殊字符  
    if (!File) {
        std::cerr << "无法打开原始文件 data/rate.txt" << std::endl;
        tempFileStream.close(); // 关闭临时文件流  
        return 1;
    }
    // 备份文件
    std::ofstream BackupFile("data/rate_backup.txt");
    if (!BackupFile) {
        std::cerr << "无法创建备份文件 data/rate_backup.txt" << std::endl;
        tempFileStream.close(); // 关闭临时文件流  
        File.close(); // 关闭原始文件流  
        return 1;
    }
    // 将原始文件的内容复制到备份文件中  
    BackupFile << File.rdbuf(); // 使用 rdbuf() 来复制流缓冲区的内容   
    File << tempFileStream.rdbuf();
    // 关闭所有文件流  
    tempFileStream.close();
    File.close();
    BackupFile.close();

    /*
    // 删除原始文件  
    if (std::remove("data/rate.txt") != 0) {
        std::cerr << "原始文件删除失败！" << std::endl;
    }
    // 将临时文件重命名为原始文件名  
    if (std::rename("data/rate_temp.txt", "data//rate.txt") != 0) {
        std::cerr << "临时文件重命名失败！" << std::endl;
    }
    */

    space("计费标准已成功删除！");
    while ((_getch()) != 27) {
    }
    BSM(adm_id);
    return 1;
}

int AdmC::BSDel(int adm_id, int choice) {
    std::ifstream inFile("data/rate.txt");
    if (!inFile) {
        std::cerr << "文件打开失败！" << std::endl;
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
        std::cout << "没有找到任何<rate>块！" << std::endl;
        return 1;
    }
    for (size_t i = 0; i < rateBlocks.size(); ++i) {
        std::cout << "【" << (i + 1) << "】\n" << rateBlocks[i] << std::endl;
    }
    if (choice < 1 || choice > rateBlocks.size()) {
        return 0;
    }
    // 删除指定的 rate 块  
    rateBlocks.erase(rateBlocks.begin() + (choice - 1));
    // 创建一个临时文件来保存修改后的内容  
    std::ofstream tempFile("data//rate_temp.txt");
    if (!tempFile) {
        std::cerr << "临时文件创建失败！" << std::endl;
        return 0;
    }

    // 将修改后的 rate 块写回到临时文件中  
    for (const auto& block : rateBlocks) {
        tempFile << "<rate>\n" << block << std::endl;
    }

    tempFile.close();
    std::ifstream tempFileStream("data/rate_temp.txt");
    if (!tempFileStream) {
        std::cerr << "无法打开临时文件 data/rate_temp.txt" << std::endl;
        return 1;
    }
    // 原始文件
    std::fstream File("data/rate.txt", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc); // 使用 binary 模式以防有不可见的特殊字符  
    if (!File) {
        std::cerr << "无法打开原始文件 data/rate.txt" << std::endl;
        tempFileStream.close(); // 关闭临时文件流  
        return 1;
    }
    // 备份文件
    std::ofstream BackupFile("data/rate_backup.txt");
    if (!BackupFile) {
        std::cerr << "无法创建备份文件 data/rate_backup.txt" << std::endl;
        tempFileStream.close(); // 关闭临时文件流  
        File.close(); // 关闭原始文件流  
        return 1;
    }
    // 将原始文件的内容复制到备份文件中  
    BackupFile << File.rdbuf(); // 使用 rdbuf() 来复制流缓冲区的内容   
    File << tempFileStream.rdbuf();
    // 关闭所有文件流  
    tempFileStream.close();
    File.close();
    BackupFile.close();

    return 1;
}

int AdmC::BSModify(int adm_id) {
    system("cls");
    page();
    line("修 改 计 费 标 准");
    space("<-返回上一级[ESC]");
    std::cout << std::endl;
    std::ifstream inFile("data/rate.txt");
    if (!inFile) {
        std::cerr << "文件打开失败！" << std::endl;
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
        std::cout << CenterSpace << "没有找到任何<rate>块！" << std::endl;
        return 1;
    }

    // 显示块内容并让用户选择  
    for (size_t i = 0; i < rateBlocks.size(); ++i) {
        std::cout << CenterSpace <<"【" << (i + 1) << "】\n" << rateBlocks[i] << std::endl;
    }
    int choice;
    std::cout << "请输入要修改的标准序号（1-" << rateBlocks.size() << "）: ";
    std::cin >> choice;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区  

    if (choice < 1 || choice > rateBlocks.size()) {
        space("输入无效，请输入有效的序号！");
        space("点击任意键继续...");
        _getch(); 
        return 1;
    }

    // 读取用户输入的新<rate>块内容  
    std::string newRateBlock;
    space("修改标准：(输入‘#’结束)\n<<");
    std::getline(std::cin, newRateBlock, '#');

    // 将修改后的内容写回到一个新的临时文件中  
    std::ofstream tempFile("data/rate_temp.txt");
    if (!tempFile) {
        std::cerr << "临时文件打开失败！" << std::endl;
        return 1;
    }

    // 重新打开原始文件以读取和写入除选定块之外的内容  
    inFile.clear(); // 清除文件流的任何错误状态  
    inFile.seekg(0, std::ios::beg); // 将文件指针移回文件开头  

    size_t blockIndex = static_cast<size_t>(choice - 1);
    size_t currentBlockIndex = 0;
    bool isModifying = false;

    while (std::getline(inFile, line)) {
        if (line == "<rate>") {
            if (currentBlockIndex == blockIndex) {
                tempFile << "<rate>\n" << newRateBlock; // 写入新的<rate>块  
                if (!tempFile.eof())
                    tempFile << "<rate>\n";
                isModifying = true;
            }
            else {
                tempFile << line << std::endl; // 写入原始<rate>标签  
            }
            currentBlockIndex++;
        }
        else {
            if (isModifying && currentBlockIndex == blockIndex) {
                continue;
            }
            tempFile << line << std::endl; // 写入非<rate>块的内容或其余<rate>块的内容  
        }
    }

    inFile.close();
    tempFile.close();

    std::ifstream tempFileStream("data/rate_temp.txt");
    if (!tempFileStream) {
        std::cerr << "无法打开临时文件 data/rate_temp.txt" << std::endl;
        return 1;
    }
    // 原始文件
    std::fstream File("data/rate.txt", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc); // 使用 binary 模式以防有不可见的特殊字符  
    if (!File) {
        std::cerr << "无法打开原始文件 data/rate.txt" << std::endl;
        tempFileStream.close(); 
    }
    // 备份文件
    std::ofstream BackupFile("data/rate_backup.txt");
    if (!BackupFile) {
        std::cerr << "无法创建备份文件 data/rate_backup.txt" << std::endl;
        tempFileStream.close(); 
        File.close();  
        return 1;
    }
    // 将原始文件的内容复制到备份文件中  
    BackupFile << File.rdbuf(); // 使用 rdbuf() 来复制流缓冲区的内容   
    File << tempFileStream.rdbuf();
    tempFileStream.close();
    File.close();
    BackupFile.close();

    BSDel(adm_id, choice + 1);

    space("计费标准已成功删除！");
    while ((_getch()) != 27) {
    }
    BSM(adm_id);
    return 1;
}

void AdmC::BSM(int adm_id) {
    system("cls");
    page();
    line("计费标准管理");
    space("(按ESC返回管理员权限系统...)");
    space("查看计费标准[1] 新增计费标准[2]");
    space("删除计费标准[3] 修改计费标准[4]");
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