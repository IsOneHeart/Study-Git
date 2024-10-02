import requests
import re
from tqdm import tqdm

url = 'https://apd-vlive.apdcdn.tc.qq.com/defaultts.tc.qq.com/B_efeEBb4uHJ8TOTkZIB0oop-98JYhHJIwkMNJd9Xw-zC1QMVj6oWODcA2QhLX4PHA/svp_50112/9gYK8Rvxf5pPSjz3PHiRl3hRBqTIvo1QOxYROrot4TfOx0MIQaHqrZXEgmpaI0skAv-06S9frBOWHj0Q05zlI9-6qXH7iE5KfyVolUBg-QPYnHM3glULO_Zqv05AEIvjnAn7hjM6SB8jsqsEkC2xBGw6LLdOOTorSw-8L3b-OX21FMxFgom90J-OceLpoAeZHV-aweZhN8OF_W36VR14xqk8MrBOhXWl6x1nCj16tCGOrkcD_BjMww/0325_gzc_1000102_0b53raabwaaax4abdzrxeztmbcgddocaah2a.f321212.mp4.m3u8?ver=5'

response = requests.get(url=url)
m3u8_text = response.text

m3u8_text = re.sub('#E.*', '', m3u8_text)
ts_list = m3u8_text.split()

# 获取ts文件的前缀
sub_ts = url.split('?')[0].rsplit('/', 1)[0] + '/'

with open('output.ts', 'wb') as f:
    for ts in tqdm(ts_list):
        ts_url = sub_ts + ts
        try:
            ts_data = requests.get(ts_url).content
            f.write(ts_data)
        except requests.exceptions.RequestException as e:
            print(f"下载 {ts_url} 时出现异常: {e}")

print("视频下载完成")