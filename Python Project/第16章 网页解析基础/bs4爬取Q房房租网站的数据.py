import requests
from bs4 import BeautifulSoup
import re

url = 'https://shenzhen.qfang.com/sale'
r = requests.get(url)

# 创建BeautifulSoup对象，并设置使用lxml解析器
soup = BeautifulSoup(r.text, 'lxml')
'''
html.parser  Python标准库的HTML
lxml         lxml HTML
xml          lxml XML
htm15lib     htm15lib
'''

# bs4的Tag标签（HTML标签）
print('soup类型：', type(soup))
print('soup.li类型：', type(soup.li))
print('li节点\n', soup.li)
print('li节点的name属性：', soup.li.name)
print('li节点的contents属性：', soup.li.contents)
print('li节点的string属性：', soup.li.string)
print('li节点的attrs属性：', soup.li.attrs)
print('li节点的attrs属性的class属性值：', soup.li.attrs['class'])
print('li节点下a节点的string属性：', soup.li.a.string)

# 方法选择器
print('所有span节点个数：', len(soup.find_all('span')))
print('class属性值为amount的所有sapn节点个数：',
      len(soup.find_all('span', attrs={'class': 'amount'})))
print('class属性值为amount的所有span节点：')
i = 0
for node in soup.find_all('span', attrs={'class': 'amount'}):
    i += 1
    if i % 3 == 0:
        print(node)
    else:
        print(node, end=' ')
print('')
print("前3个class属性值为amount的span节点：\n", soup.find_all('span', attrs={'class': 'amount'}, limit=3))
print('string属性包含“2室1厅"的前3个节点的文本：', soup.find_all(string=re.compile('2室1厅'), limit=3))

# 获取第一个房源标题，并赋值给title
# div下的a下的string
title = soup.find('div', class_='list-main-header clearfix').a.string.strip()
print('第一个房源标题：', title)

# CSS选择器
print('div节点下所有a节点个数：', len(soup.select('div a')))
node_a = soup.select('.list-main-header')[0].select('a')
print('第一个a节点的href属性值：', node_a[0]['href'])
print('第一个a节点的文本：', node_a[0].string)

house = soup.select('.list-result li')[0]
house_metas = house.select('[class="house-metas clearfix"] p')
for item in house_metas:
    print(item.string.strip())
list_price = house.select('[class="list-price"] span')
print(list_price[0].string + list_price[1].string)
location = house.select('[class="house-location clearfix"] div')[0].text.strip()
print(location)
