import requests
import re
import csv

url = 'https://www.shanghairanking.cn/rankings/bcur/2024'
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/58.0.3029.110 Safari/537.3'}
r = requests.get(url, headers=headers)
r.encoding = 'utf-8'  # 显式设置编码为UTF-8
html = r.text
pattern = re.compile(r'<a\s+[^>]*?class="name-cn"[^>]*?>(.*?)</a>', re.DOTALL)
items = re.findall(pattern, html)
count = 1
with open('Unveristy Top30.csv', 'w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    writer.writerow(['排名', '大学名称'])
    for item in items:
        print(item.strip())
        writer.writerow([count, item.strip()])
        count += 1
'''
在Python的正则表达式模块re中，re.DOTALL（或者等价地，使用编译选项的简写re.S）是一个特殊的标志，它使得.（点号）能够匹配任何字符，
包括换行符\n。默认情况下，.在正则表达式中不匹配换行符。

当你使用re.DOTALL或re.S标志时，.将会匹配任何字符，包括换行符，这样你就可以跨越多行来匹配文本。这在处理包含多行文本的数据时特别有用，
比如HTML或XML文档，其中文本可能跨越多行。
'''
