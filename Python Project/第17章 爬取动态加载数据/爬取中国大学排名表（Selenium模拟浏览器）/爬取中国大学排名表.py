from selenium import webdriver
from selenium.webdriver.common.by import By
import time
import csv

url = 'https://www.shanghairanking.cn/rankings/bcur/2024'
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/58.0.3029.110 Safari/537.3'
}
browser = webdriver.Chrome()
browser.get(url)
time.sleep(2)

count = 1
with open('University_List.csv', 'w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    writer.writerow(['排名', '大学名称'])
    while True:
        table_rows = browser.find_elements(by=By.CSS_SELECTOR, value='table.rk-table tbody tr')
        for row in table_rows:
            name_anchor = row.find_element(by=By.CSS_SELECTOR, value='a.name-cn')
            if name_anchor:
                name = name_anchor.text.strip()  # 获取大学名称
                writer.writerow([count, name])
                print(name, ' ', end='')
                if count % 10 == 0:
                    print('')
            if count % 30 == 0:
                try:
                    next_page = browser.find_element(by=By.XPATH, value='//li[@title="下一页"]/a')
                    next_page.click()
                    time.sleep(2)
                except:
                    raise ValueError
            if count == 594:
                exit(0)
            count += 1
