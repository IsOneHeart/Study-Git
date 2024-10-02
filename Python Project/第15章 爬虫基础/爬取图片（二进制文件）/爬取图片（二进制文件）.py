import requests

url = input("请输入图片网址：")  # 'https://pic4.zhimg.com/v2-60f227bfdf2cc1a5d017e543f98ff2b7_r.jpg'
path = input("请输入保存路径（含文件名）：")  # 'download.jpg'
try:
    r = requests.get(url, timeout=5)
except requests.Timeout:
    print("连接超时！")
else:
    print('二进制类型返回内容：', r.content)
    print('文本类型返回内容：', r.text)
    with open(path, 'wb') as f:
        f.write(r.content)
    print("图片已下载为", path)
