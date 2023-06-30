# from cgitb import small
import requests # HTMLを読み込む為のHTTP要請
from bs4 import BeautifulSoup # クローリングの為
import sys # python interpreterに関する機能
import pyautogui # 自動化の為

# クローリング情報を保存するメモ帳を開く
sys.stdout = open('C:/Users/lsy88/Desktop/Programing/20220607_crawlingEx/crawlingExInput.txt', 'w')

# 検索したいWordを入力
keyword = pyautogui.prompt("検索>> ")

#　Naverニュースクローリング
pageNum = 0 # URLにて１~10pageまでカウントする為の変数
smallNum = 0 #可読性の為の行アキ
num = 0 #Pageナンバーを表現
for i in range(1, 100, 10):
    pageNum = pageNum + i #URLのPageナンバーは10単位で上がる為、１から10単位で100（10page）まで繰り返す
    response = requests.get(f"https://search.naver.com/search.naver?where=news&sm=tab_jum&query={keyword}&start={pageNum}") #URL読み込み
    html = response.text #Textに保存されたHTMLコードを保存
    soup = BeautifulSoup(html, 'html.parser') #サイトの情報抽出
    links = soup.select(".news_tit") #ニュースタイトルクローリング
    for link in links: #該当Page全体をクローリング
        smallNum = smallNum + 1 #行アキの為のカウント
        title = link.text #タイトル抽出
        url = link.attrs['href'] #リンク抽出
        print(title,"\n",url) #タイトルとリンクの間の行アキ
        if smallNum != 10: print("\n") #行アキ
    smallNum = 0 #次のpageに行アキする為に初期化
    num = num + 1 #Pageナンバーカウント
    print(f"\n----------------------------{num}page----------------------------\n\n\n")

#　メモ帳保存後閉じる
sys.stdout.close()
