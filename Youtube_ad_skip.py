import pyautogui # 自動化の為

#下記のイメージと”広告をスキップ”ボタンの見た目がマッチングすれば自動的にクリック
path_1 = 'C:/Users/lsy88/Desktop/Programing/20220527_YoutubeSkip/Skip10sec/check5.PNG'
path_2 = 'C:/Users/lsy88/Desktop/Programing/20220527_YoutubeSkip/Skip10sec/check2.PNG'
path_3 = 'C:/Users/lsy88/Desktop/Programing/20220527_YoutubeSkip/Skip10sec/check3.PNG'
path_4 = 'C:/Users/lsy88/Desktop/Programing/20220527_YoutubeSkip/Skip10sec/check4.PNG'

# 上記のパスを順番に試す為の配列
pathValue = [path_1, path_2, path_3, path_4]
count = 0 # path_1~4の為のカウント

# 広告ありなしに対する条件
while True:

    # イメージの位置選定及びクリック
    img_cature = pyautogui.locateOnScreen(pathValue[count], confidence=0.7)
    print(img_cature, "終了は Ctrl + C")

    # 広告がある場合は10秒待期後クリック（通常5秒以上スキップできない為）
    if img_cature != None:
        countIn = 0 #　内部forの配列カウント
        for countValue in pathValue:
            img_cature = pyautogui.locateOnScreen(pathValue[countIn], confidence=0.7) #　当てはまるイメージ探し
            countIn = countIn + 1 #　4つのイメージが回るまでカウント 
            pyautogui.click(img_cature) #　クリック
    
    # イメージを循環しながら比べられるように配列をカウント
    if count < 3: count = count + 1
    elif count == 3:  count = 0
