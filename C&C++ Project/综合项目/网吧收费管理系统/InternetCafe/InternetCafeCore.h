#pragma once // 核心系统
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <string>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <vector> 
#include <functional>
#include <list>
#include <ctime>
#include <numeric>
#include <__msvc_chrono.hpp>

#include "UI.h"
#define Super_Administrator_Password "IamSA666"
#define Administrator_Initial_Password "12345678"


class UserC {
protected:
    typedef struct User {
        int uid;
        char password[9];
        float card_amount;
        bool vip;
        bool signout;
        //struct User* next;
    }User;

    typedef struct Log {
        char flag;
        std::string data;
        std::string time;
        std::string desp;
    }Log;

    std::list<User> UL;

    int UserFindMaxID();
    int UserFileRead();
    int UserFileWrite();
    std::string GetPassword();

public:
    UserC(){
        UserFileRead();
    }
    ~UserC(){
        UserFileWrite();
    }
};

class AdmC: public UserC, public UI_Time {
private:
    typedef struct Administrator {
        std::string name;
        int adm_id;
        char password[9];
        int card_manager;
        int billing_manager;
        int billing_standrd_manager;
        int cost_manager;
        struct Administrator* next;
    }Adm;

    struct Administrator* head;
    int AdmListInitiate();
    int AdmFileWrite();
    int CreateAdm();
    int DeleteAdm();
    int op();
    int AdmFileRead();
    int AdmListFindName(const std::string& name);
    int AdmFindMaxID();
    int AdmListInsert(const std::string& name, const char* password, int card_manager, int billing_manager, int billing_standrd_manager, int cost_manager);
    int AdmListDelete(int adm_id);
    int AdmListDestory();
    int AdmExamine();
    int BSExamine(int adm_id);
    int BSAdd(int adm_id);
    int BSDel(int adm_id);
    int BSDel(int adm_id, int choice);
    void BSM(int adm_id);
    int BSModify(int adm_id);
    void CardM(int adm_id);
    void AdmLogin();
    void AdmMenu(int adm_id);
    void SuperAdmMenu();
    void BM(int adm_id);
    void CostM(int adm_id);
    void SuperAdmLogin();
    void CardAdd(int adm_id);
    void CardExaime(int adm_id);
    void CardSignOut(int adm_id);
    void Recharge(int adm_id);
    void Refund(int adm_id);
    void UserLogIn(int adm_id);
    void UserLogOut(int adm_id);
    int UserLogWrite(int uid, char flag, std::string desp);
    std::list<Log> UserLogRead(int uid) {
        using namespace std;
        int filenum = uid / 10;
        string filename = to_string(filenum) + "U.txt";
        list<Log> logs;
        ifstream inFile("data/log/" + filename);
        if (!inFile.is_open()) {
            cerr << "日志文件打开失败！" << endl;
            return logs;
        }
        string line;
        while (getline(inFile, line)) {
            Log l;
            int breakuid;
            stringstream ss(line);
            if (!(ss >> breakuid >> l.flag >> l.data >> l.time >> l.desp)) {
                continue;
            }
            if (breakuid == uid)
                logs.push_back(l);
        }
        return logs;
    }
    void QueryStatistics(int adm_id);
    void QueryTranRecords(int adm_id);
    void CalTotalRevenue(int adm_id);
    void CalMonthlyRevenue(int adm_id);

public:
    AdmC() {
        AdmListInitiate();
        AdmFileRead();
    }
    ~AdmC() {
        Adm* current = head;
        while (current != nullptr) {
            Adm* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void LoginPage();
};

int AdmC::AdmListInitiate() {
    head = new Adm;
    if (head == nullptr) {
        std::cout << "[创建链表]内存块分配失败！\n";
        return 0;
    }
    head->next = nullptr;
    return 1;
}

int AdmC::AdmListFindName(const std::string& name) {
    if (head == nullptr || head->next == nullptr) {
        return -1;
    }
    Administrator* p = head->next;
    while (p != nullptr) {
        if (p->name == name) {
            return 1; // 找到  
        }
        p = p->next;
    }
    return -1; // 未找到  
}

int AdmC::AdmFindMaxID() {
    Adm* p = head; 
    int temp_max_id = p->adm_id;
    Adm* current = p->next;
    while (current != nullptr) {
        if (current->adm_id > temp_max_id) {
            temp_max_id = current->adm_id;
        }
        current = current->next;
    }
    return temp_max_id;
}

int AdmC::AdmListInsert(const std::string& name, const char* password, int card_manager, int billing_manager, int billing_standrd_manager, int cost_manager) {
    if (head == nullptr) {
        if (!AdmListInitiate()) {
            return 0;
        }
    }
    Administrator* newAdmin = new Administrator;
    if (newAdmin == nullptr) {
        std::cout << "内存块分配失败！\n";
        return 0;
    }
    newAdmin->name = name;
    newAdmin->adm_id = AdmFindMaxID() + 1; 
    strncpy_s(newAdmin->password, sizeof(newAdmin->password), password, _TRUNCATE);
    newAdmin->card_manager = card_manager;
    newAdmin->billing_manager = billing_manager;
    newAdmin->billing_standrd_manager = billing_standrd_manager;
    newAdmin->cost_manager = cost_manager;
    newAdmin->next = nullptr; 
    Administrator* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newAdmin;
    return 1;
}

int AdmC::AdmListDelete(int adm_id) {
    if (head == nullptr || head->next == nullptr) {
        return 0; // 链表为空  
    }
    Adm* prev = head;
    Adm* current = head->next;
    while (current != nullptr && current->adm_id != adm_id) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        return 0; // 未找到对应ID的管理员  
    }
    prev->next = current->next;
    delete current;
    return 1;
}

int AdmC::AdmListDestory() {
    Adm* p1, * p2;
    p1 = head->next;
    while (p1 != nullptr) {
        p2 = p1->next;
        delete p1;
        p1 = p2;
    }
    head->next = nullptr;
    return 1;
}

int UserC::UserFindMaxID() {
    int temp_max_uid = 0;
    for (const auto& i : UL)
        temp_max_uid = i.uid > temp_max_uid ? i.uid : temp_max_uid;
    return temp_max_uid;
}

std::string UserC::GetPassword() {
    int count = 0;
    char password[9]{};
    while (count < 8) {
        password[count] = _getch();
        if (password[count] == '\b') {
            if (count > 0) {
                printf("\b \b");
                count--;
            }
            continue;
        }
        if (password[count] == '\n') {
            password[count] = '\0';
            break;
        }
        printf("*");
        count++;
    }
    if (count < 8) {
        password[count] = '\0'; // 手动添加字符串结束符
    }
    else {
        password[8] = '\0'; // 确保在第8位添加字符串结束符
    }
    std::string str_password(password);
    return str_password;
}

#include "UI.h"
#include "CardManagement.h"
#include "BillingStandardManagement.h"
#include "BillingManagement.h"
#include "CostManagement.h"
#include "QueryStatistics.h"
#include "PermissionSystem.h"
#include "LoggedSystem.h"

int AdmC::UserLogWrite(int uid, char flag, std::string desp) {
    using namespace std;
    int filenum = uid / 10;
    string filename = to_string(filenum) + "U.txt";
    ofstream outFile("data/log/" + filename, ios::app);
    if (!outFile.is_open()) {
        cerr << "日志文件打开失败！" << endl;
        return 0;
    }

    outFile << uid << " " << flag << " " << GetTime() << " " << desp << endl;
    return 1;
}