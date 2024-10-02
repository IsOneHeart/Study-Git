import requests

# 百度翻译
url = 'https://fanyi.baidu.com/sug'
words = input("翻译关键词：")
datavalue = {'kw': words}
headersvalue = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/124.0.0.0 Safari/537.36 Edg/124.0.0.0',
    'Cookie': 'BAIDUID=A2183E4CE28C08D63E79E65D1EBA70B8:FG=1; BAIDUID_BFESS=A2183E4CE28C08D63E79E65D1EBA70B8:FG=1; Hm_lvt_64ecd82404c51e03dc91cb9e8c025574=1709775666; REALTIME_TRANS_SWITCH=1; FANYI_WORD_SWITCH=1; HISTORY_SWITCH=1; SOUND_SPD_SWITCH=1; SOUND_PREFER_SWITCH=1; __bid_n=18e7ab5ac874608d55cfb5; BDUSS=jhtSjUtRElOdy1FZ0c3WVVrZEpVOTJ5aHNrazF-TUZrbjlZY2owTmxXU2Fna2htSUFBQUFBJCQAAAAAAQAAAAEAAABKkwkKAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJr1IGaa9SBmS; BDUSS_BFESS=jhtSjUtRElOdy1FZ0c3WVVrZEpVOTJ5aHNrazF-TUZrbjlZY2owTmxXU2Fna2htSUFBQUFBJCQAAAAAAQAAAAEAAABKkwkKAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJr1IGaa9SBmS; BIDUPSID=A2183E4CE28C08D63E79E65D1EBA70B8; ab_sr=1.0.1_ZjRlODc4NzMyNGNmMjdkZmMwY2NhMjA0NTE5MThlZTg0Y2M5ZmE5ZDM4MzhkZTY4OTY1NTc2YWU4YTQ0NzhiMDEzNmI3Mzk1NWJkYmZhNTg4MzExNGFiNmZiNjQ0MmRlY2FiMjhmMjk1OTU3ODIyY2JhY2E1ZDNhMDNkNDVkNzM4YTRhYmIwYmE4Y2M2YjhkZDUyYmI0YTRlYmQ4MDA4YjVjODMyMmNhNDVkNWJlMjE3MmNlMjVlMzZlZDBiMmRmMWQwOWJjMDA3MDdiMjEyMGMwMzg4MDE1NThmNjA1NjE=; RT="z=1&dm=baidu.com&si=c926e74b-2ed4-48c9-8bde-27c8e24eb62a&ss=lwbq4bus&sl=q&tt=93n&bcn=https%3A%2F%2Ffclog.baidu.com%2Flog%2Fweirwood%3Ftype%3Dperf&ld=1f6ws"'
}
# 传递URL参数，定制请求头，设置Cookie
try:
    response = requests.post(url, data=datavalue,
                             headers=headersvalue, timeout=2)  # response=requests.get(url,params=datavalue,headers=headersvalue)
except requests.Timeout:
    print('连接超时！')
else:
    print('相应类型：', type(response))
    print('请求的URL：', response.url)
    print('响应的状态码：', response.status_code)
    print('请求头：', response.request.headers)
    result = response.json()
    print('JSON解析：', result)
    contains_k = any(item.get('k') is not None for item in result['data'])
    if contains_k:
        print('翻译结果：')
        for item in result['data']:
            print(f"{item['k']} >> {item['v']}")
    else:
        print('翻译失败！请输入词。')

# 有道翻译 反爬虫
'''
headersvalue={
    'User-Agent':'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/124.0.0.0 Mobile Safari/537.36 Edg/124.0.0.0',
    'Cookie':'P_INFO=3030461274; OUTFOX_SEARCH_USER_ID_NCOO=1737460844.0059948; OUTFOX_SEARCH_USER_ID=371363339@112.93.141.159; __yadk_uid=NeOIsqkeSczgKbJ8h8XOsWz9gPYjw8he; rollNum=true; ___rl__test__cookies=1715942789655'
}
url = 'https://m.youdao.com/translate?vendor=fanyi.web'
datavalue = {'inputtext': '爬虫', 'type': 'AUTO'}
r=requests.get(url)
print('相应类型：',type(r))
print('请求的URL：',r.url)
print('响应的状态码：',r.status_code)
print('请求头：',r.request.headers)
response=requests.get(url,params=datavalue,headers=headersvalue)
print('响应的状态码：',r.status_code)
print('请求头：',r.request.headers)
print(response.text)
'''
