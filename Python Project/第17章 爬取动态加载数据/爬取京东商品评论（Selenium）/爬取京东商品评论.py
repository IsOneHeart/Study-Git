from bs4 import BeautifulSoup
from selenium import webdriver
import time
from selenium.common import TimeoutException
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait

url = ('https://search.jd.com/Search?keyword=jd%20cn&enc=utf-8&cu=true&utm_source=baidu-search&utm_medium=cpc'
       '&utm_campaign=t_262767352_baidusearch&utm_term=201732667922_0_c775bd78007f4c83aa673b8ebebc5456')
browser = webdriver.Chrome()
wait = WebDriverWait(browser, 10)


def searcher(myid, password, keyword, n, c):
    browser.get(url)
    browser.maximize_window()  # 最大化窗口
    time.sleep(2)

    myinput = wait.until(
        EC.presence_of_element_located((By.ID, 'loginname'))
    )
    myinput.send_keys(myid)  # 输入文本

    myinput = wait.until(
        EC.presence_of_element_located((By.ID, 'nloginpwd'))
    )
    myinput.send_keys(password)  # 输入文本

    wait.until(
        EC.presence_of_element_located((
            By.ID, 'loginsubmit'
        ))
    ).click()

    time.sleep(2)
    myinput = wait.until(
        EC.presence_of_element_located((By.ID, 'key'))
    )
    myinput.send_keys(keyword)  # 输入文本
    try:
        search_button = WebDriverWait(browser, 10).until(
            EC.element_to_be_clickable((By.CSS_SELECTOR, '[class="button cw-icon"]'))
        )
        search_button.click()
        time.sleep(3)
        gods(n, c)
    except:
        raise Exception('ERROR')


def gods(n, c):
    # 获取商品链接的列表
    product_links = browser.find_element(By.CLASS_NAME, 'p-name p-name-type-2')
    product_links.click()
    time.sleep(3)
    comments(c)
    '''
        # 遍历前n个商品链接
    for count, link in enumerate(product_links):
        if count >= n:
            break

            # 点击链接进入商品页面
        link.click()
        time.sleep(2)  # 等待商品页面加载完成（如果需要）

        # 在商品页面上执行评论操作
        comments(c)
    '''


def comments(c):
    wait.until(EC.presence_of_element_located(
        (By.CSS_SELECTOR, '[data-anchor="#comment"]')
    )).click()
    time.sleep(2)
    html = browser.page_source
    soup = BeautifulSoup(html, 'lxml')
    items = soup.select('.comment-item div')
    count = 0
    for item in items:
        comment = soup.select('.comment-con p')[0].text.strip()
        print(comment)
        if count >= c:
            break
        count += 1


if __name__ == '__main__':
    searcher(13531186701, 'Zyx!159357', '口罩', 3, 3)
