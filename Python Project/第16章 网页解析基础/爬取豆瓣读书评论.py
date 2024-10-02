import requests
import chardet
from lxml import etree

chapter_url = 'https://book.douban.com/subject/36790949/comments/'  # 《一次告别》评论区网址
headersvalue = {
    # 模拟浏览器请求
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'}
try:
    r = requests.get(chapter_url, headers=headersvalue, timeout=1)
except requests.Timeout:
    print('连接超时！')
else:
    code_type = r.apparent_encoding  # 获取返回内容编码类型
    if code_type == 'GB2312':
        code_type = 'GBK'
    r.encoding = code_type  # 重定义返回内容编码类型
    html = etree.HTML(r.text)  # 创建HTML对象html
    title = html.xpath('//html/body/div[@id="wrapper"]/div[@id="content"]/h1/text()')[0]  # 选择节点并提取文本
    print(title)  # 输出标题
    '''
    marks = html.xpath(
        '//html/body/div[@id="wrapper"]/div[@id="content"]/div/div/div/div/div/ul/li/div[@class="comment"]/h3/span['
        '@class="comment-info"]/span[@class="user-starts allstar40 rating"]/@title')
    '''
    contents = html.xpath(
        '//html/body/div[@id="wrapper"]/div[@id="content"]/div/div/div/div/div/ul/li/div[@class="comment"]/p/span/text()')  # 选择节点并提取文本
    count = 1
    for i in contents:  # 遍历列表
        content = i.strip()  # 移除字符串头尾的空格，并赋值给content
        print(f'[{count}]{content}\n')  # 输出评论
        count += 1
