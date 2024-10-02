import requests
import chardet

base_url = 'https://movie.douban.com/top250'
headers_value = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 '
                  'Safari/537.36 Edg/125.0.0.0'
}
for i in range(0, 4):
    params_value = {'start': str(i * 25), 'filter': ''}
    try:
        r = requests.get(base_url, params=params_value, headers=headers_value, timeout=1)
    except requests.Timeout:
        print('Time Out!')
    else:
        print(r.status_code)
        print(r.url)
        code_type = chardet.detect(r.content)['encoding']
        with open('moive.txt','a+',encoding='utf-8') as f:
            f.write(r.content.decode(code_type))