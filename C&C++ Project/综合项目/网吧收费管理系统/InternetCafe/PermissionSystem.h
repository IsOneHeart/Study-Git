#pragma once //权限管理

int AdmC::CreateAdm() {
    if (head == nullptr) {
        return -1;
    }
    std::string name;
    int adm_id = 0;
    char password[9]{};
    int card_manager = 0;
    int billing_manager = 0;
    int billing_standrd_manager = 0;
    int cost_manager = 0;
    system("cls");
    page();
    line("添加管理员");
    adm_id = AdmFindMaxID() + 1;
    std::cout << CenterSpaceEmpty << "新管理员ID：" << std::right << std::setw(3) << std::setfill('0') << adm_id << std::endl;
    std::cout << CenterSpaceEmpty << "新管理员昵称(不可包含空格)：";
    std::cin >> name;
    std::cout << CenterSpaceEmpty << "新管理员初始密码(8位)：";
    int count = 0;
    while (count < 8) {
        password[count] = _getch();
        if (password[count] == '\b') {
            if (count > 0) {
                std::cout << "\b \b";
                count--;
            }
            continue;
        }
        if (password[count] == '\n') {
            password[count] = '\0';
            break;
        }
        std::cout << "*";
        count++;
    }
    if (count < 9) {
        password[count] = '\0'; // 手动添加字符串结束符
    }
    else {
        password[8] = '\0'; // 确保在第8位添加字符串结束符
    }
    space("（“是”填“1”，“否”填“0”）");
    int isop1 = 0, isop2 = 0, isop3 = 0, isop4 = 0;
    std::cout << CenterSpaceEmpty << "是否具有管理计费权限：";
    std::cin >> isop1;
    billing_manager = (isop1 == 1) ? 1 : 0;
    std::cout << CenterSpaceEmpty << "是否具有管理计费标准权限：";
    std::cin >> isop2;
    billing_standrd_manager = (isop2 == 1) ? 1 : 0;
    std::cout << CenterSpaceEmpty << "是否具有管理卡权限：";
    std::cin >> isop3;
    card_manager = (isop3 == 1) ? 1 : 0;
    std::cout << CenterSpaceEmpty << "是否具有管理费用权限：";
    std::cin >> isop4;
    cost_manager = (isop4 == 1) ? 1 : 0;
    space(">>确认[Y] 重新添加[N] 取消[ESC]<<");
    char key;
    while (1) {
        key = _getch();
        if (key == 'Y' || key == 'y') {
            AdmListInsert(name, password, card_manager, billing_manager, billing_standrd_manager, cost_manager);
            AdmFileWrite();
            break;
        }
        if (key == 'N' || key == 'n') {
            CreateAdm();
            break;
        }
        if (key == 27) {
            SuperAdmMenu();
            break;
        }
    }
    SuperAdmMenu();
    return 1;
}

int AdmC::DeleteAdm() {
    system("cls");
    page();
    line("删除管理员");
    std::cout << CenterSpace << "请输入要删除的管理员ID：";
    int del_id = 0;
    std::cin >> del_id;
    space(">>确认[Y] 重新删除[N] 取消[ESC]<<");
    char key;
    while (1) {
        key = _getch();
        if (key == 'Y' || key == 'y') {
            if (AdmListDelete(del_id) == 0) {
                space("删除失败！");
            }
            else
                std::cout << CenterSpace << "删除管理员" << del_id << "成功！";
            AdmFileWrite();
            break;
        }
        if (key == 'N' || key == 'n') {
            DeleteAdm();
            break;
        }
        if (key == 27) {
            SuperAdmMenu();
            break;
        }
    }
    char key2;
    space("<-返回上一级[ESC]");
    while ((key2 = _getch()) != 27) {
        // 等待用户按下ESC键，然后返回超级管理员菜单
    }
    SuperAdmMenu(); // 返回超级管理员菜单
    return 1;
}

int AdmC::op() {
    system("cls");
    page();
    line("配置管理员权限");
    std::cout << CenterSpace << "请输入要配置的管理员ID：";
    int adm_id;
    std::cin >> adm_id;
    Administrator* p = head->next;
    int flag = 0;
    while (p != nullptr) {
        if (p->adm_id == adm_id) {
            std::cout << CenterSpace << "管理计费 \t" << (p->billing_manager == 1 ? "√" : "×");
            std::cout << CenterSpace << "管理计费标准 \t" << (p->billing_standrd_manager == 1 ? "√" : "×");
            std::cout << CenterSpace << "管理卡权限 \t" << (p->card_manager == 1 ? "√" : "×");
            std::cout << CenterSpace << "管理费用 \t" << (p->cost_manager == 1 ? "√" : "×");
            flag = 1;
            break;
        }
        p = p->next;
    }
    if (flag == 0) {
        std::cout << CenterSpace << "管理员" << std::setw(3) << adm_id << "不存在！";
    }
    else {
        int card_manager = 0;
        int billing_manager = 0;
        int billing_standrd_manager = 0;
        int cost_manager = 0;
        space("（“是”填“1”，“否”填“0”）");
        int isop1 = 0, isop2 = 0, isop3 = 0, isop4 = 0;
        std::cout << CenterSpaceEmpty << "是否具有管理计费权限：";
        std::cin >> isop1;
        billing_manager = (isop1 == 1) ? 1 : 0;
        std::cout << CenterSpaceEmpty << "是否具有管理计费标准权限：";
        std::cin >> isop2;
        billing_standrd_manager = (isop2 == 1) ? 1 : 0;
        std::cout << CenterSpaceEmpty << "是否具有管理卡权限：";
        std::cin >> isop3;
        card_manager = (isop3 == 1) ? 1 : 0;
        std::cout << CenterSpaceEmpty << "是否具有管理费用权限：";
        std::cin >> isop4;
        cost_manager = (isop4 == 1) ? 1 : 0;
        space(">>确认[Y] 重新配置[N] 取消[ESC]<<");
        char key;
        while (1) {
            key = _getch();
            if (key == 'Y' || key == 'y') {
                p->billing_manager = billing_manager;
                p->billing_standrd_manager = billing_standrd_manager;
                p->card_manager = card_manager;
                p->cost_manager = cost_manager;
                space("重新配置成功！");
                AdmFileWrite();
                break;
            }
            if (key == 'N' || key == 'n') {
                op();
                break;
            }
            if (key == 27) {
                SuperAdmMenu();
                break;
            }
        }
    }
    char key2;
    space("<-返回上一级[ESC]");
    while ((key2 = _getch()) != 27) {
        // 等待用户按下ESC键，然后返回超级管理员菜单
    }
    SuperAdmMenu(); // 返回超级管理员菜单
    return 1;
}

void AdmC::SuperAdmMenu() {
    system("cls");
    page();
    line("超级管理员权限系统");
    space("添加管理员[1]    删除管理员[2]");
    space("配置权限[3]      查看管理员[4]");
    while (1) {
        char key = _getch();
        bool isbreak = false;
        switch (key) {
        case '1':
            CreateAdm();
            isbreak = true;
            break;
        case '2':
            DeleteAdm();
            isbreak = true;
            break;
        case '3':
            op();
            isbreak = true;
            break;
        case '4':
            AdmExamine();
            isbreak = true;
            break;
        default:
            SuperAdmMenu();
        }
        if (isbreak)
            break;
    }
    AdmListDestory();
}

int AdmC::AdmFileRead() {
    using namespace std;
    fstream file;
    file.open("data/adm.txt", ios::in);
    if (!file.is_open()) {
        cerr << "文件打开失败！" << endl;
        return 0;
    }
    Adm* current = head;   // current 指向链表的当前末尾  
    string line;
    // 从文件逐行读取  
    while (getline(file, line)) {
        stringstream ss(line);
        Adm* newnode = new Adm;
        // 尝试按照特定格式解析行内容  
        if (!(ss >> newnode->name >> newnode->adm_id >> newnode->password
            >> newnode->billing_manager >> newnode->billing_standrd_manager
            >> newnode->card_manager >> newnode->cost_manager)) {
            delete newnode; // 解析失败，释放内存  
            continue;
        }
        // 检查管理员名称是否已存在  
        if (AdmListFindName(newnode->name)==1) {
            delete newnode;
            continue;
        }
        // 将新节点添加到链表的末尾  
        if (current == nullptr) {
            head = newnode; // 如果链表为空，则head指向新节点  
        }
        else {
            current->next = newnode; // 否则，将新节点添加到当前末尾之后  
        }
        current = newnode; // 更新current为新的末尾节点  
        current->next = nullptr; // 确保新节点的next为nullptr，表示链表结束  
    }
    file.close();
    return 1; // 读取成功  
}

//int AdmFileRead1(Adm* head) { // AdmFileRead()的废案
    //char name[50];   //废案的废案
    //int adm_id = 0;
    //char password[50];
    //int card_manager = 0;
    //int billing_manager = 0;
    //int billing_standrd_manager = 0;
    //int cost_manager = 0;
    /*
    FILE* fp;
    if (fopen_s(&fp, "data//adm.txt", "r") != 0) {
        return 0; // 文件打开失败
    }
    char buffer[256]; // 假设一行最多256个字符
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        Adm* p = head;
        while (p != NULL) {
            p = p->next;
        }
        Adm* newnode = (Adm*)malloc(sizeof(Adm));
        if (newnode == NULL) {
            return 0; // 内存分配失败
        }
        if (sscanf_s(buffer, "%s %d %s %d %d %d %d",
            newnode->name, (unsigned int)sizeof(newnode->name),
            &newnode->adm_id,
            newnode->password, (unsigned int)sizeof(newnode->password),
            &newnode->billing_manager,
            &newnode->billing_standrd_manager,
            &newnode->card_manager,
            &newnode->cost_manager) != 7) {
            continue; // 数据格式不匹配，跳过这一行
        }
        if (AdmListFindName(head, newnode->name) == 1) {
            return -1; // 该管理员昵称已存在
        }
        if (strcmp(newnode->name, "超级管理员") == 0) {
            return -2; // 管理员昵称不可为"超级管理员"
        }
        */
        /*
        修了两个小时修不好的bug：用定义的变量赋值给结构体内变量报错
        Expression :( L " Buffer is too small "&&0)
        For information on how your program can cause an assertion failure , see the Visual C ++ documentation on asserts .
        */
        //strcpy_s(newnode->name, sizeof(newnode->name), name);
        //newnode->adm_id = adm_id;
        //strcpy_s(newnode->password, sizeof(newnode->password), password);
        //newnode->billing_manager = billing_manager;
        //newnode->billing_standrd_manager = billing_standrd_manager;
        //newnode->card_manager = card_manager;
        //newnode->cost_manager = cost_manager;
/*
        newnode->next = NULL;
        p->next = newnode;
    }
    fclose(fp);
    return 1; // 读取成功
}
*/

int AdmC::AdmFileWrite() {
    using namespace std;
    fstream file; //FILE* fp;
    file.open("data/adm.txt", ios::trunc | ios::out);
    if (!file.is_open())
        return 0;
    Adm* p = head->next;
    while (p != NULL) {
        /*
        fprintf_s(fp, "%s %d %s %d %d %d %d\n",
            p->name, p->adm_id, p->password,
            p->billing_manager, p->billing_standrd_manager, p->card_manager, p->cost_manager);
        */
        file << p->name << " " << p->adm_id << " " << p->password << " " << p->billing_manager << " " << p->billing_standrd_manager << " " << p->card_manager << " " << p->cost_manager << endl;
        p = p->next;
    }
    file.close(); //fclose(fp);
    return 1; // 写入成功
}

int AdmC::AdmExamine() {
    system("cls");
    page();
    line("管理员查看");
    space("(按ESC返回超级管理员权限系统...)");
    Adm* p = head->next;
    printf("\n              ");
    printf("\t%-10s \t%-8s \t%-8s \t%-12s \t%-8s \t%-8s", "昵称", "管理员ID", "管理计费", "管理计费标准", "管理卡", "管理费用");
    while (p != NULL) {
        printf("\n                ");
        /*
        printf("\t%-10s \t%-8d \t%-8s \t%-12s \t%-8s \t%-8s", p->name, p->adm_id,
            p->billing_manager ? "是" : "否",
            p->billing_standrd_manager ? "是" : "否",
            p->card_manager ? "是" : "否",
            p->cost_manager ? "是" : "否");
        */
        std::cout << std::left << std::setw(10)<< p->name << "\t" << std::right
            << std::setw(3) << std::setfill('0') << p->adm_id << "\t" << "        " << std::setfill(' ') << std::left
            << std::setw(8) << (p->billing_manager ? "是" : "否") << "\t"
            << std::setw(12) << (p->billing_standrd_manager ? "是" : "否") << "\t"
            << std::setw(8) << (p->card_manager ? "是" : "否") << "\t"
            << std::setw(8) << (p->cost_manager ? "是" : "否");
        p = p->next;
    }
    char key;
    while ((key = _getch()) != 27) {
        // 等待用户按下ESC键，然后返回超级管理员菜单
    }
    SuperAdmMenu(); // 返回超级管理员菜单
    return 1;
}

void AdmC::AdmMenu(int adm_id) {
    system("cls");
    page();
    line("管理员权限系统");
    Adm* p = head->next;
    int flag = 0;
    while (p != nullptr) {
        if (p->adm_id == adm_id) {
            flag = 1;
            break;
        }
        p = p->next;
    }
    if (flag == 0) {
        space("非法登录！");
        exit(0);
    }
    //printf(CenterSpace">>〇%s %03d   -注销[DELETE]", p->name, p->adm_id);
    std::cout << CenterSpace << ">>〇" << p->name << " " << std::right << std::setw(3) << std::setfill('0') << p->adm_id << "   -注销[DELETE]";
    int haveop = 0;
    printf("\n");
    printf(CenterSpace"%s \t%s", "查询统计", "[E]");
    if (p->billing_manager == 1) {
        haveop = 1;
        printf(CenterSpace"%s \t%s", "管理计费", "[Q]");
    }
    if (p->billing_standrd_manager == 1) {
        haveop = 1;
        printf(CenterSpace"%s \t%s", "管理计费标准", "[W]");
    }
    if (p->card_manager == 1) {
        haveop = 1;
        printf(CenterSpace"%s \t%s", "管理卡  ", "[A]");
    }
    if (p->cost_manager == 1) {
        haveop = 1;
        printf(CenterSpace"%s \t%s", "管理费用", "[S]");
    }
    if (haveop == 0)
        space("您还没有任何管理员权限...");
    char key;
    while (1) {
        key = _getch();
        if (key == 127) { // DELETE
            AdmListDestory();
            LoginPage();
            break;
        }
        if (key == 'E' || key == 'e') {
            QueryStatistics(adm_id);
            break;
        }
        if ((key == 'Q' || key == 'q') && p->billing_manager == 1) {
            BM(adm_id);
            break;
        }
        if ((key == 'W' || key == 'w') && p->billing_standrd_manager == 1) {
            BSM(adm_id);
            break;
        }
        if ((key == 'A' || key == 'a') && p->card_manager == 1) {
            CardM(adm_id);
            break;
        }
        if ((key == 'S' || key == 's') && p->cost_manager == 1) {
            CostM(adm_id);
            break;
        }
    }
}