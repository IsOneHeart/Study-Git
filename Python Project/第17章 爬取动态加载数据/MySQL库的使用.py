import pymysql

# 连接MySQL
db = pymysql.connect(host='localhost',
                     user='root',
                     password='123456',
                     port=3306)
'''
host            数据库地址，本机地址通常为127.0.0.1，也可设置为localhost
port            数据库端口，通常为3306
user            数据库用户名，管理员用户为root
password        数据库密码
db              数据库名
charset         插入数据库时的编码
connect_timeout 连接超时时间，以秒为单位
use_unicode     结果以unicode字符串格式返回
'''

cursor = db.cursor()  # 获取操作游标
cursor.execute('CREATE DATABASE IF NOT EXISTS student_sql Character Set UTF8MB4')  # 创建数据库student_sql
'''
execute()       执行SQL语句
CREATE DATABASE IF NOT EXISTS student_sql: 
尝试创建一个名为student_sql的数据库。如果student_sql这个数据库已经存在，IF NOT EXISTS条件会确保不会抛出错误，而是直接跳过创建过程。
Character Set UTF8MB4: 
指定了新创建数据库的字符集为UTF8MB4。
UTF8MB4是一个字符集，它支持四字节的UTF-8字符，包括表情符号（Emojis）和其他特殊字符。它是UTF8的一个超集，可以存储更多的字符。
'''

cursor.close()  # 关闭游标
db.close()  # 断开连接

# 连接MySQL，并选择数据库
db = pymysql.connect(host='localhost',
                     user='root',
                     password='123456',
                     port=3306,
                     db='student_sql')
cursor = db.cursor()  # 获取操作游标
sql = 'CREATE TABLE IF NOT EXISTS students (id CHAR(20), name CHAR(20), age INT)'  # 创建表student
'''
CREATE TABLE IF NOT EXISTS students (id CHAR(20), name CHAR(20), age INT):
如果数据库中不存在名为student的表，那么就创建一个新的表，该表有三个字段：id（长度为20的字符类型）、name（长度为20的字符类型）和age（整数类型）。
'''
cursor.execute(sql)

student = (('0001', 'bob', 12),
           ('0002', 'lucy', 10),
           ('0003', 'kate', 11))  # 定义数据

try:

    sql = 'INSERT INTO students (id,name,age) VALUES (%s,%s,%s)'  # SQL插入数据语句
    cursor.executemany(sql, student)  # 执行多条SQL语句
    db.commit()  # 提交到数据库执行
    sql = 'SELECT * FROM students'  # SQL查询数据语句，查询所有记录
    cursor.execute(sql)
    results = cursor.fetchall()  # 获取所有记录列表
    print('插入数据后的所有记录：', results)

    sql = 'UPDATE students SET age = %s WHERE name = %s'  # SQL更新数据语句
    cursor.execute(sql, (13, 'bob'))
    db.commit()
    sql = 'SELECT * FROM students'  # SQL查询数据语句，查询所有记录
    cursor.execute(sql)
    results = cursor.fetchall()  # 获取所有记录列表
    print('更新数据后的所有记录：', results)

    sql = 'DELETE FROM students WHERE age <= 10'
    cursor.execute(sql)
    db.commit()
    sql = 'SELECT * FROM students'  # SQL查询数据语句，查询所有记录
    cursor.execute(sql)
    results = cursor.fetchall()  # 获取所有记录列表
    print('删除age小于等于10的数据后的所有记录：', results)

    sql = 'SELECT * FROM students WHERE age >12'
    cursor.execute(sql)
    results = cursor.fetchall()
    print('age大于12的数据后的所有记录：', results)

    sql = 'DELETE FROM students'  # 清空数据库
    cursor.execute(sql)
    db.commit()

except:
    print('ERROR')
    db.rollback()  # 回滚当前事务

cursor.close()
db.close()
