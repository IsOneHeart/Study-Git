from bs4 import BeautifulSoup
from selenium import webdriver
import pymongo
import time

from selenium.common import TimeoutException
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC

from selenium.webdriver.support.ui import WebDriverWait

browser = webdriver.Chrome()
wait = WebDriverWait(browser, 10)
'''
driver                   浏览器对象
timeout                  等待时间（秒）
poll_frequency=0.5       检查频率（秒）
ignored_exceptions=None  超时后的异常信息
'''
client = pymongo.MongoClient('localhost', 27017)
mongo = client.cnki  # 选择或新建数据库
collection = mongo.papers  # 选择或新建集合
collection.drop()


def searcher(keyword):
    browser.get('https://www.cnki.net')
    browser.maximize_window()  # 最大化窗口
    time.sleep(2)
    myinput = wait.until(
        EC.presence_of_element_located((By.ID, 'txt_SearchText'))
    )
    myinput.send_keys(keyword)  # 输入文本
    wait.until(
        EC.presence_of_element_located((
            By.CLASS_NAME, 'search-btn'
        ))
    ).click()
    time.sleep(3)
    wait.until(EC.presence_of_element_located(
        (By.CSS_SELECTOR, '[class="icon icon-sort"]')
    )).click()
    wait.until(EC.presence_of_all_elements_located(
        (By.CSS_SELECTOR, '#id_grid_display_num ul li')
    ))[2].click()
    time.sleep(3)
    parse_page()


def parse_page():
    wait.until(
        EC.presence_of_all_elements_located(
            (By.CSS_SELECTOR, '.result-table-list tbody tr')
        )
    )
    html = browser.page_source
    soup = BeautifulSoup(html, 'lxml')
    items = soup.select('.result-table-list tbody tr')
    for i in range(0, len(items)):
        item = items[i]
        detail = item.select('td')
        paper = {
            'index': detail[0].text.strip(),
            'title': detail[1].text.strip(),
            'author': detail[2].text.strip(),
            'resource': detail[3].text.strip(),
            'time': detail[4].text.strip(),
            'database': detail[5].text.strip()
        }
        print(paper)
        data_storage(paper)


def data_storage(paper):
    try:
        collection.insert_one(paper)
    except Exception:
        print('failedly storage!', paper)


def next_page():
    try:
        page_next = wait.until(
            EC.visibility_of_element_located(
                (By.CSS_SELECTOR, '#Page_next_top')
            )
        )
    except TimeoutException:
        return False
    else:
        page_next.click()
        return True


if __name__ == '__main__':
    keyword = 'Python'
    searcher(keyword)
    while True:
        flag = next_page()
        time.sleep(5)
        if flag:
            parse_page()
            continue
        else:
            break
    browser.close()
