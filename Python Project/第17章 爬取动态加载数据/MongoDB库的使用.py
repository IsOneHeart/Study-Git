import pymongo

myclient = pymongo.MongoClient(host='localhost', port=27017)
'''
host  数据库地址
port  端口，默认27017
'''

mydb = myclient.test  # 选择数据库，如果不存在则新建
collection = mydb.student  # 选择集合，如果不存在则新建
mylist = [{'id': '001', 'name': '小明', 'age': 10},
          {'id': '002', 'name': '小红', 'age': 11},
          {'id': '003', 'name': '小刚', 'age': 11},
          {'id': '004', 'name': '小蓝', 'age': 12}]
collection.insert_many(mylist)  # 将字典列表添加到数据库中

print('添加数据后的所有记录：')
for i in collection.find():
    print(i)
print('第一个age为11的记录：\n', collection.find_one({'age': 11}))
print('所有age为11的记录：')
for i in collection.find({'age': 11}):
    print(i)

collection.delete_one({'id': '003'})
print('删除第一个id为003后的所有记录：')
for i in collection.find():
    print(i)

collection.update_one({'age': 12}, {'$set': {'age': 10}})
print('将第一个age为12的记录修改成age为10后的所有记录：')
for i in collection.find():
    print(i)

print('排序后的所有记录：')
for i in collection.find().sort('age'):
    print(i)

print('反向排序后的所有记录：')
for i in collection.find().sort('age', -1):
    print(i)

collection.drop()  # 删除集合
