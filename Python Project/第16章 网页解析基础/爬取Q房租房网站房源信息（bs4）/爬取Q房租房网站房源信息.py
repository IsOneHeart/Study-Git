import requests
import math
from bs4 import BeautifulSoup
import csv
import time

base_url = 'https://shenzhen.qfang.com/sale'
headersvalue = {
    'Cookie': 'cookieId=c7771551-7237-40d6-acdb-f7aa7e670ed3; '
              'SECKEY_ABVK=Vr3ExIN5qzh+/nzoaatcIrfWyOyul9dqzLsGcpviymktTbVupuuUv9qbI3Fsrsul; '
              'BMAP_SECKEY=iTsVqBoUliap3xM6RsX4kDuoO6lpfOJsdGv-RzWlIqosgggKeEcUZSPLAcjR1UQl_OHR33FE9IAfBTKWQYyQzK1a'
              '-mDkfmvqqoBKsiaZLIgrQtYKMEPrWxASD9pZt7CQwU9hawi03MvGnJam9CJmjQLt7IsEWe3XBaFDBfXxAE4mSyt35v0boXikDUqk'
              'VKNw; language=SIMPLIFIED; _ga=GA1.1.98844768.1718335160; CITY_NAME=SHENZHEN; Hm_lvt_561b8479f4e1e9841'
              '9908032a2629883=1718335175; sid=e7a4f5da-acb8-45de-9be7-75e46da55e54; qchatid=6ad8a245-57df-4454-a23d'
              '-514a2b808b4d; JSESSIONID=aaaHY7LpdPKxz-HSmIv_y; cookieId=b40d6899-5fe7-4445-9c2e-25196e62cfe9; cookieId'
              '=413d8574-8656-4761-aee3-4c987107ef09; SALEROOMREADRECORDCOOKIE=504666136; WINDOW_DEVICE_PIXEL_RATIO='
              '1.25; looks=SALE%2C504666136%2C3515973; Hm_lpvt_561b8479f4e1e98419908032a2629883=1718343704; _ga_GV01F4'
              'QGNH=GS1.1.1718343695.2.1.1718343704.0.0.0'
}


def get_allpage_info():
    r = requests.get(base_url, headers=headersvalue)
    soup = BeautifulSoup(r.text, 'lxml')
    total_house = soup.select('.list-total span')[0].text.strip()
    total_page = math.ceil(int(total_house) / 30)
    for i in range(1, total_page + 1):
        url = base_url + '/f' + str(i)
        get_onepage_info(url)
        time.sleep(1)


def get_onepage_info(url):
    r = requests.get(url, headers=headersvalue)
    soup = BeautifulSoup(r.text, 'lxml')
    house_list = soup.select('.list-result')[0].select('[class="items clearfix"]')
    for house in house_list:
        info_list = []
        name = house.select('[class="list-main-header clearfix"] a')[0].text.strip()
        info_list.append(name)
        house_metas = house.select('[class="house-metas clearfix"] p')
        for item in house_metas:
            if item.text == None:
                info_list.append('None')
            else:
                info_list.append(item.text.strip())
        list_price = house.select('.list-price span')
        price = list_price[0].text + list_price[1].text
        info_list.append(price)
        location = house.select('[class="house-location clearfix"] div')[0].text.strip()
        info_list.append(location)
        save_csvfile(info_list)


def save_csvfile(list):
    with open('house_info.csv', 'a', newline='', encoding='utf-8') as file:
        writer = csv.writer(file)
        writer.writerow(list)


if __name__ == '__main__':
    get_allpage_info()
