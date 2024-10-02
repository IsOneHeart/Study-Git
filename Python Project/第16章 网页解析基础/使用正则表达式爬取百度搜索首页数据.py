import requests
import re

url = 'https://www.baidu.com/'
headersvalue = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 '
                  'Safari/537.36 Edg/125.0.0.0'
}
r = requests.get(url, headers=headersvalue)
html = r.text
pattern = re.compile('<span.*?title-content-index.*?>(.*?)</span>.*?title-content-title.*?>('
                     '.*?)</span>.*?<span.*?title-content-mark.*?>(.*?)</span>')
items = re.findall(pattern, html)
for item in items:
    print(item)
