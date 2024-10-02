import json

data = [{'姓名': '小明', '性别': '男', '生日': '2016-06-06'},
        {'姓名': '小红', '性别': '女', '生日': '2017-07-07'}]
json_data = json.dumps(data, indent=2, ensure_ascii=False)
print(json_data)
with open('data.json', 'w', encoding='utf-8') as file:
    file.write(json_data)

print('解析tntfood.json为Python数据类型：')
with open('tntfood.json', 'r', encoding='utf-8') as js:
    result = js.read()
    data = json.loads(result)
    print(data)
