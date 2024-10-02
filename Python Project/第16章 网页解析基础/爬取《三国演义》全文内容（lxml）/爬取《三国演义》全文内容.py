import requests
from lxml import etree
import os
import time

base_url = 'https://sanguo.5000yan.com/'


class Bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'  # 重置颜色
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def get_allpage_info(from_page=1, to_page=120):
    if (from_page < 1 or from_page > 120 or to_page < 1 or to_page > 120) or from_page > to_page:
        raise ValueError('PageError: Invalid page range or from_page is greater than to_page.')
    total_pages = to_page - from_page + 1
    gui_len = max(5, int(total_pages / 10))  # 动态调整进度条长度
    for count in range(from_page, to_page + 1):  # 注意这里应该是 to_page + 1
        url = base_url + str(965 + count - 1) + '.html'  # 确保URL结构正确
        get_onepage_info(url)
        progress = (count - from_page + 1) / total_pages
        os.system('cls' if os.name == 'nt' else 'clear')  # 跨平台清屏
        print_progress_bar(progress, gui_len)
        # time.sleep(1)


def print_progress_bar(progress, gui_len):
    filled_len = int(progress * gui_len)
    bar = '[' + Bcolors.OKGREEN + '▇' * filled_len + Bcolors.ENDC + '▇' * (gui_len - filled_len) + ']'
    print(f'{bar} {progress * 100:.2f}%', end='\r')


def get_onepage_info(url):
    r = requests.get(url)
    code_type = r.apparent_encoding  # 获取返回内容编码类型
    if code_type == 'GB2312':
        code_type = 'GBK'
    r.encoding = code_type  # 重定义返回内容编码类型
    html = etree.HTML(r.text)  # 创建HTML对象html
    title = html.xpath('//body/div//div/main/section/header/h2/text()')[0]  # 选择h2节点并提取文本，将返回的列表第一项赋值给title
    contents = html.xpath('//body/div//div/main/section/div[@class="grap"]/div/text()')  # 选择div属性为grap的div节点并提取文本
    with open(title + '.txt', 'w') as file:
        file.write(title)
        for i in contents:  # 遍历列表
            content = i.strip()  # 移除字符串头尾的空格，并赋值给content
            file.write(content)  # 输出正文


if __name__ == '__main__':
    get_allpage_info(1, 5)
