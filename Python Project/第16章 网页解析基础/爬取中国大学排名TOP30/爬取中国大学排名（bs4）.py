import requests
from bs4 import BeautifulSoup
import csv

url = 'https://www.shanghairanking.cn/rankings/bcur/2024'
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/58.0.3029.110 Safari/537.3'
}
r = requests.get(url, headers=headers)
r.encoding = 'utf-8'
soup = BeautifulSoup(r.text, 'lxml')

table_rows = soup.select('table.rk-table tbody tr')

count = 1
with open('University_List.csv', 'w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    writer.writerow(['排名', '大学名称'])
    for row in table_rows:
        name_anchor = row.select_one('a.name-cn')
        if name_anchor:
            name = name_anchor.text.strip()  # 获取大学名称
            writer.writerow([count, name])
            print(name)
        count += 1
