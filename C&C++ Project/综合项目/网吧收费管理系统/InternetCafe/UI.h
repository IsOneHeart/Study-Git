#pragma once //界面
#define CenterSpace "\n                                                "
#define CenterSpaceEmpty "\n                                                "
#define L1 "——————————————"
#define L2 "——————————————\n"
#define AdmIDLen 3

class UI_Time {
protected:
    void space(const char* words);
    void spaceE(const char* words);
    void page();
    void line(const char* words);
    std::string GetTime();
    std::chrono::system_clock::time_point parse_iso_string(const std::string& s);
    float TimeDifferenceInHours(std::string time_str1, std::string time_str2);
    bool isChiocedTime(std::string time_low, std::string time_high, std::string time);

public:
    UI_Time() {
        //msg = { 0 };
    }
};

void UI_Time::space(const char* words) {
    printf(CenterSpace);
    printf("%s\n", words);
}

void UI_Time::spaceE(const char* words) {
    std::cout << CenterSpace << words;
}

void UI_Time::page() {
    printf("\n\n\n\n\n\n\n\n");
    space(">>>> 网 吧 收 费 管 理 系 统 <<<<\n");
}

void UI_Time::line(const char* words) {
    printf("                                                ");
    size_t len = strlen(words);
    for (size_t i = 0;i < 16 - len / 2;i++) {
        printf("—");
    }
    printf("%s", words);
    for (size_t i = 0;i < 16 - len / 2;i++) {
        printf("—");
    }
    space("");
}

std::string UI_Time::GetTime() {
    // 获取当前时间的Unix时间戳  
    std::time_t now = std::time(nullptr);
    // 创建一个tm结构体来保存结果  
    struct tm local_tm;
    // 使用localtime_s来安全地获取本地时间  
    errno_t err = localtime_s(&local_tm, &now);
    if (err != 0) {
        std::cerr << "Error occurred while getting local time." << std::endl;
        return "";
    }
    char buffer[80];
    // 使用strftime来格式化时间  
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &local_tm);
    std::string current_time(buffer);
    return current_time;
}

std::chrono::system_clock::time_point UI_Time::parse_iso_string(const std::string& s) {
    struct tm tm = {};
    std::istringstream iss(s);
    iss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    std::time_t rawtime = std::mktime(&tm);
    if (rawtime == -1) {
        throw std::runtime_error("无法解析时间字符串！");
    }
    return std::chrono::system_clock::from_time_t(rawtime);
}

float UI_Time::TimeDifferenceInHours(std::string time_str1, std::string time_str2) {
    // 解析字符串为time_point  
    auto tp1 = parse_iso_string(time_str1);
    auto tp2 = parse_iso_string(time_str2);

    // 计算时间差  
    auto duration = tp2 - tp1;

    // 转换为小时
    float hours_difference = static_cast<float>(std::chrono::duration_cast<std::chrono::hours>(duration).count());
    float fractional_hours = static_cast<float>(std::chrono::duration_cast<std::chrono::minutes>(duration).count() % 60 / 60.0);
    hours_difference = abs(hours_difference) + abs(fractional_hours);

    return hours_difference;
}

bool UI_Time::isChiocedTime(std::string time_low, std::string time_high, std::string time) {
    float len = TimeDifferenceInHours(time_low, time_high);
    float dlow = TimeDifferenceInHours(time_low, time);
    float dhigh = TimeDifferenceInHours(time_high, time);
    if (dlow <= len && dhigh <= len)
        return true;
    return false;
}