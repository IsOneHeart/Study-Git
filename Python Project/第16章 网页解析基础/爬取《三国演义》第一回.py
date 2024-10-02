import requests
import chardet
from lxml import etree

chapter_url = 'https://sanguo.5000yan.com/965.html'
r = requests.get(chapter_url)
code_type = r.apparent_encoding  # 获取返回内容编码类型
if code_type == 'GB2312':
    code_type = 'GBK'
r.encoding = code_type  # 重定义返回内容编码类型
html = etree.HTML(r.text)  # 创建HTML对象html
title = html.xpath('//body/div//div/main/section/header/h2/text()')[0]  # 选择h2节点并提取文本，将返回的列表第一项赋值给title
print(title)  # 输出第一回的标题
contents = html.xpath('//body/div//div/main/section/div[@class="grap"]/div/text()')  # 选择div属性为grap的div节点并提取文本
for i in contents:  # 遍历列表
    content = i.strip()  # 移除字符串头尾的空格，并赋值给content
    print(content)  # 输出正文
