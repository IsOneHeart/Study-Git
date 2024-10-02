import PyOfficeRobot
import poai
from PyOfficeRobot.api.chat import wx
from datetime import datetime

bot_name = '@乂心BOT'


def remove_name(text):
    if text.startswith(bot_name):
        return text[len(bot_name):].strip()  # 使用strip()去除可能的尾随空白字符
    return text.strip()  # 总是去除文本两侧的空白字符


def text_controller(text):
    text = remove_name(text)
    print(text)
    if text.strip() == '':
        return '你是谁'
    return text


def chat_zhipu(who, key, model='glm-4', kv=None):
    if kv is None:
        kv = bot_name
    wx.GetSessionList()  # 获取会话列表
    wx.ChatWith(who)  # 打开`who`聊天窗口
    temp_msg = None
    while True:
        try:
            friend_name, receive_msg = wx.GetAllMessage[-1][0], wx.GetAllMessage[-1][1]  # 获取朋友的名字、发送的信息
            if (friend_name == who) & (receive_msg != temp_msg) & (receive_msg[:len(bot_name)] == bot_name):
                """
                条件：
                朋友名字正确:(friend_name == who)
                不是上次的对话:(receive_msg != temp_msg)
                对方内容在自己的预设里:(receive_msg in kv.keys())
                """
                print(f'【{who}】发送：【{receive_msg}】')
                receive_msg = text_controller(receive_msg)
                reply_msg = poai.chat.zhipu(key, prompt=receive_msg, model=model)
                wx.SendMsg(reply_msg, who)  # 向`who`发送消息
        except:
            pass


def chat_zhipu_group(who, key, model='glm-4', kv=None):
    if kv is None:
        kv = bot_name
    wx.GetSessionList()  # 获取会话列表
    wx.ChatWith(who)  # 打开`who`聊天窗口
    temp_msg = None
    while True:
        try:
            friend_name, receive_msg = wx.GetAllMessage[-1][0], wx.GetAllMessage[-1][1]  # 获取朋友的名字、发送的信息
            if (receive_msg != temp_msg) & (receive_msg[:len(bot_name)] == bot_name):
                """
                条件：
                朋友名字正确:(friend_name == who)
                不是上次的对话:(receive_msg != temp_msg)
                对方内容在自己的预设里:(receive_msg in kv.keys())
                """
                print(f'【{who}】发送：【{receive_msg}】')
                receive_msg = text_controller(receive_msg)
                if receive_msg == '关闭程序':
                    wx.SendMsg(f'程序已关闭...({datetime.now()})', who)
                    break
                reply_msg = poai.chat.zhipu(key, prompt=receive_msg, model=model)
                wx.SendMsg(reply_msg, who)  # 向`who`发送消息
        except:
            pass


# Incendio
friend = ['Incendio', 'ZInc', 'bot', '家有儿女']


def chat(what):
    chat_zhipu(who=friend[what], key='a15f2e5ae3fb4df6d3a2848f1f66da63.IrI3Wum0HQeNA6z0',
               model='glm-4')


def choice():
    print(friend)
    what = int(input('choice:'))
    model = input('model(A need @name but B need nothing and C need @ name in group ):')
    if model == 'A':
        chat(what)
    elif model == 'B':
        PyOfficeRobot.chat.chat_by_zhipu(who=friend[what], key='a15f2e5ae3fb4df6d3a2848f1f66da63.IrI3Wum0HQeNA6z0',
                                         model='glm-4')
    elif model == 'C':
        chat_zhipu_group(friend[what], 'a15f2e5ae3fb4df6d3a2848f1f66da63.IrI3Wum0HQeNA6z0', model='glm-4')
    else:
        print('Error')
        exit(0)


choice()
