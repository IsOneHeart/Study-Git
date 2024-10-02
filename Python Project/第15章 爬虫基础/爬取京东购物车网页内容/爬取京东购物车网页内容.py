from urllib import request, robotparser
import requests
import chardet
from time import sleep

rp = robotparser.RobotFileParser()  # 创建RobotFileParser类对象rp
rp.set_url('https://jd.com/robots.txt')
rp.read()  # 读取
url = 'https://cart.jd.com/cart_index/'
user_agent = 'Baiduspider'
print(rp.can_fetch(user_agent, url))

headersvalue = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36 Edg/125.0.0.0',
                'Cookie': 'unpl=JF8EAJhnNSttD09XVhhRSRNESFRQW18OSUQFbm8HU1sLTVFWT1AZQUB7XlVdWBRKEx9sZxRUW1NKVQ4bACsSEXteU11bD00VB2xXVgQFDQ8WUUtBSUt-SVxRWFULShIAaWYHZG1bS2QFGjIdEBlLXVdcVAh7FjNoVzVkWlxOUQ0ZMhoiEXsfAAJZAUMQB2wqA1ZUWEtXBxICKxMgSA; __jdv=76161171|baidu-search|t_262767352_baidusearch|cpc|304792042703_0_f52b2bc0e2854373b709367b74bec3ba|1716282014475; __jdu=738112381; areaId=19; ipLoc-djd=19-1655-0-0; shshshfpa=d840b226-72e6-5fdb-dce0-4ce846f6853e-1716282016; shshshfpx=d840b226-72e6-5fdb-dce0-4ce846f6853e-1716282016; thor=5BCDE6118C1D5B458AD54034B5EAEC49EB7A525C7D81A784D1F980B87DEBA5DCFA5D02E43182693815B9EBFFA6A1C213EA1372F90DB5119899DC4A345634FBC6E6233FD42B99EB28CD871E911841F2F43A2F6D22F5A8745325FB86CF3712CDCBC5D5E2C372090E02145D5CC4155A5B89FDAEF7EFDBAF59E161DB5F89C0B9AFE25F664EA51E9168A06764D5CB42CDE0D6; flash=2_Kcw4b8RqXSIKivGJ7QtQnDxTNo0h0UrCIXgF7Yivh-UZb2-jTYI3m8bNnhDjQGPmArF3BP27pyH501U4avpqCndtrWIO39j63WIdWSZ2CI3Fqd_QRC36jlcOMVtAifmB5uGPcRXGLIstnO2jk4yvdVTbHhwtJYq8iFSLOGhp8pP*; pin=IsOneHeart; _tp=NsUWi2EsHRtUw2cUwY%2Fizg%3D%3D; _pst=IsOneHeart; TrackID=1fUf_ibmrKvY8btCtWx2ym8yrTt8JUnkFNrW3ZN5zXAcdrjQNVetTj7qmiU2xoC2cGKVMPVlVGuO0nvhAwbroERhN4gRaZKs-3Pz1Ms64Xaj-rJILG856yrA8whGkGiL_|||DetxQ2136sbsy892wGhWuA; unick=4347b5hhr7r99z; pinId=DetxQ2136sbsy892wGhWuA; user-key=LQFK3EFpR2VKSpCHIwtm9oNREm4QBFj1; 3AB9D23F7A4B3C9B=FXVJT6E2KM7MY6LTZUMMFW3EMSVZZUEKYYOLJLJGILQTT554DY2V6LSXJNMPR3ZTJRMCGEBUREQJKI7ZLCOJIV4XME; cn=1; __jda=76161171.738112381.1716282014.1716282014.1716282014.1; __jdb=76161171.15.738112381|1.1716282014; __jdc=76161171; 3AB9D23F7A4B3CSS=jdd03FXVJT6E2KM7MY6LTZUMMFW3EMSVZZUEKYYOLJLJGILQTT554DY2V6LSXJNMPR3ZTJRMCGEBUREQJKI7ZLCOJIV4XMEAAAAMPTJWXUJYAAAAADCOVGRZFSV7V3UX; shshshfpb=BApXclAFlmepAthw2gKGxb24pJZ_9MDTkBlRpJzlo9xJ1MhpZUYC2'}
for i in range(0,10):
    try:
        r=requests.get(url,headers=headersvalue,timeout=1)
    except requests.Timeout:
        print('Time Out!')
    else:
        print(r.status_code," ",end=" ")
        code_type=chardet.detect(r.content)['encoding']
        with open('jd.txt','a+',encoding='utf-8') as f:
            f.write(r.content.decode(code_type))
        sleep(1)