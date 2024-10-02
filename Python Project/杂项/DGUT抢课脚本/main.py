from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait
import time
from datetime import datetime


def GrabClassOfDGUT():
    url = 'https://jw.dgut.edu.cn/'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                      'Chrome/58.0.3029.110 Safari/537.3'
    }
    print('test')
    browser = webdriver.Edge()
    wait = WebDriverWait(browser, 10)
    print('浏览器开启')
    browser.get(url)
    browser.maximize_window()  # 最大化窗口
    time.sleep(2)
    try:
        login_button = WebDriverWait(browser, 10).until(
            EC.element_to_be_clickable((By.XPATH, '/html/body/div[2]/div[1]/form/table[1]/tbody/tr[6]/td/a[2]'))
        )
        login_button.click()
        time.sleep(3)
    except:
        raise Exception('ERROR')
    flag = True
    while flag:
        try:
            netGrabClass_button = WebDriverWait(browser, 10).until(
                EC.element_to_be_clickable((By.XPATH, '/html/body/article/div[1]/div/div/div[2]/div/ul/li[3]'))

            )
            netGrabClass_button.click()
            flag = False
        except:
            print('Please login in.')
            continue
    try:
        grabClass_button = WebDriverWait(browser, 10).until(
            EC.element_to_be_clickable((By.XPATH, '/html/body/div/div[13]/div[1]'))
        )
        grabClass_button.click()
        time.sleep(3)
    except:
        raise Exception('ERROR')
    print(
        '选择选课范围：\n主修(本年级/专业)[1]\n主修(分级教学)[2]\n主修(公共任选)[3]\n辅修[4]\n主修(可跨年级/专业)[5]\n特殊培养(本年级/专业)[6]\n特殊培养(公共任选)[7]')
    courseName=input('输入课程名称(全称或连续的可唯一代表的简称:')
    courseRange = input('输入选择(数字):')
    timeChoice = input('抢课时间(格式化输入XX:XX:XX，例如12:29:58):')
    print('操作预设完成，关闭自动化操作浏览器将中断程序。')
    while True:
        if datetime == timeChoice:
            if courseRange != 1:
                try:
                    courseRange_button = WebDriverWait(browser, 10).until(
                        EC.element_to_be_clickable((By.XPATH,
                                                    '/html/body/div[1]/table/tbody/tr[1]/td/form/div/div[5]/table/tbody/tr[1]/td/select[1]'))
                    )
                    courseRange_button.click()
                except:
                    print('ERROR:连接超时或当前不是有效的选课时间。')
                xpath_model = '/html/body/div[1]/table/tbody/tr[1]/td/form/div/div[5]/table/tbody/tr[1]/td/select[1]/option[' + courseRange + ']'
                try:
                    check_button = WebDriverWait(browser, 10).until(
                        EC.element_to_be_clickable((By.XPATH,
                                                    '/html/body/div[1]/table/tbody/tr[1]/td/form/div/div[3]/input[22]'))
                    )
                    check_button.click()
                except:
                    print('ERROR:连接超时或当前不是有效的选课时间。')


if __name__ == '__main__':
    GrabClassOfDGUT()
