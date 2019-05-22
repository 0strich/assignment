#-*- coding:utf-8 -*-

from random import *
from time import *

hour, minute = 6, 0
flag = 0
Event = '''
★★★★★★★★★★★★★★★★★★
★   Event Time   ★
★   Random Cube  ★
★★★★★★★★★★★★★★★★★★'''
Past_Branch_Dictionary = {
    1 : (6, 00),
    2 : (6, 30),
    3 : (7, 00),
    4 : (7, 30),
    5 : (7, 40),
    6 : (8, 30)}

Flag_Dictionary= {
    1 : 0,
    2 : 0,
    3 : 0,
    4 : 0,
    5 : 0,
    6 : 0}

Answer_Flag_Dictionary= {
    1 : 1,
    2 : 1,
    3 : 1,
    4 : 1,
    5 : 1,
    6 : 1}

def Time_Flow():
    global hour, minute
    minute += 1
    if(minute >= 60):
        hour += int(minute / 60)
        minute %= 60

def Current_Time():
    global hour, minute
    print('현재 시간 : {}시 {}분\n'.format(hour, minute))

def Input():
    while(True):
        try:
            var = int(input('\nChoose : '))
            if(var == 1 or var == 2):
                print()
                return var
            else:
                print('Only Input 1 or 2')
        except:
            print('Only Input 1 or 2')

def Loading():
    for i in range(3):
        print('★'*(i+1))
        sleep(1)
    print()

def Past_Branch(rand):
    global hour, minute
    global flag, ans
    hour = Past_Branch_Dictionary[rand][0]
    minute = Past_Branch_Dictionary[rand][1]
    if(rand == 1):
        flag = Flag_Dictionary[1]
        ans = Answer_Flag_Dictionary[1]
    else:
        flag = Flag_Dictionary[rand-1]
        ans = Answer_Flag_Dictionary[rand-1]
    sw = 1

def Set_Flag(case, num):
    global flag
    Flag_Dictionary[case] = num
    flag = Flag_Dictionary[case]

def Set_Answer(case, num):
    global ans
    Answer_Flag_Dictionary[case] = num
    ans = Answer_Flag_Dictionary[case]

def Dice_Explain():
    for i in range(1,7):
        print('{} 번째 선택 : {}시 {}분'.format(i, Past_Branch_Dictionary[i][0], Past_Branch_Dictionary[i][1]))

if __name__ == '__main__':
    while(hour < 12):
        if(hour == 6 and minute == 0):
            Current_Time()
            print('**** 따르르릉 ****  **** 따르르릉 ****')
            print('음... 벌써 6시잖아... 일어날까.. 그냥 더잘까...\n')
            print('1. 일어난다      2. 더잔다')
            ans = Input()
            if(ans == 1):
                Set_Flag(1, 1)
                print('음... 아침은 일찍시작해야지... 일어나자..\n')
                print('1. 샤워를 한다    2. 운동을 한다')
                ans = Input()
                if(ans == 1):
                    print('쏴아아악.... 쏴아아악....')
                    print('후.. 시원해 역시 아침 샤워는 냉수 샤워지 ㅋㅋㅋ')
                    print('역시 샤워는 일어나자 마자해야 정신이 번쩍 뜨는군')
                    Loading()
                else:
                    print('운동을 하러 가볼까...')
                    print('(달리는 중) 후우... 후우... 아놔 힘드러')
                    print('그래도 정신이 번쩍드는군!')
                    Loading()
            else:
                print('너무 일찍 일어난거같으니깐 더자자...')
                print('zzzzzzz')
                Loading()
            Set_Answer(2, ans)

        if(hour == 6 and minute == 30):
            Current_Time()
            if(flag):
                print('음.. 이젠 뭘하지..?\n')
                print('1. 밥을 먹는다    2. 운동을 한다')
                ans = Input()
                if(ans == 1):
                    print('음.. 오늘 아침은 어제 끓여놓은 미역국을 먹어야겠네')
                    print('잠깐... 미역국 말고 반찬은 뭐가 있지..?')
                    print('미역국에... 김치, 계란이면 되겠지')
                    print('쩝쩝쩝.. 쩝쩝쩝...')
                    Loading()
                else:
                    print('******* 수영장 *******')
                    print('후.. 역시 아침엔 수영을 꼭 해줘야지')
                    print('어푸... 어푸...')
                    Loading()
            else:
                print('1. 일어난다      2. 더잔다')
                ans = Input()
                if(ans == 1):
                    Set_Flag(2, 1)
                    print('으으음... 30분이라두 더자니 게운하네\n')
                    print('1. 샤워를 한다    2. 밥을 먹는다')
                    ans = Input()
                    if(ans == 1):
                        print('쏴아아악.... 쏴아아악....')
                        print('후.. 시원해 역시 아침 샤워는 냉수 샤워지 ㅋㅋㅋ')
                        print('역시 샤워는 일어나자 마자해야 정신이 번쩍 뜨는군')
                        Loading()
                    else:
                        print('******* 수영장 *******')
                        print('후.. 역시 아침엔 수영을 꼭 해줘야지')
                        print('어푸... 어푸...')
                        Loading()
                else:
                    print('**** 따르르릉 ****  **** 따르르릉 ****')
                    print('음... 조금만 더자자..')
                    Loading()
            Set_Answer(3, ans)

        if(hour == 7 and minute == 0):
            Current_Time()
            if(flag):
                print('음.. 이젠 뭘하지..?\n')
                print('1. 밥을 먹는다    2. 출근준비를 한다')
                ans = Input()
                if(ans==1):
                    print('라면을 끓여볼까..?')
                    print('(보글보글)')
                    print('음.. 맛있다')
                    Loading()
                else:
                    print('흠.. 오늘은 캐쥬얼하게 입고 가야겠군..')
                    Loading()
            else:
                print('**** 따르르릉 ****  **** 따르르릉 ****')
                print('음... 으으으으~~~ 잘잤다~~')
                print('1시간 더잤더니 게운하군~~')
                print('30분동안 뭘할까..?\n')
                print('1. 밥을 먹는다    2. 샤워를 한다')
                ans = Input()
                if(ans == 1):
                    print('음.. 오늘 아침은 어제 끓여놓은 미역국을 먹어야겠네')
                    print('잠깐... 미역국 말고 반찬은 뭐가 있지..?')
                    print('미역국에... 김치, 계란이면 되겠지')
                    print('쩝쩝쩝.. 쩝쩝쩝...')
                    Loading()
                else:
                    print('쏴아아악.... 쏴아아악....')
                    print('후.. 시원해 역시 아침 샤워는 냉수 샤워지 ㅋㅋㅋ')
                    print('역시 샤워는 일어나자 마자해야 정신이 번쩍 뜨는군')
                    Loading()
            Set_Answer(4, ans)

        if(hour == 7 and minute == 30):
            Current_Time()
            print('그럼.. 출근을 해볼까')
            print('오늘 날씨가 좀 흐린걸... 우산을 챙길까..?\n')
            print('1. 챙긴다   2. 안 챙긴다')
            ans = Input()
            Set_Answer(5, ans)
            flag = 0

        if(hour == 7 and minute == 40):
            if(flag == 1):minute = 50
            Current_Time()
            if(ans == 1):
                print('음... 대중교통을 탈까, 택시를 탈까..?\n')
                print('1. 대중교통(30분)  2. 택시(15분)')
                ans = Input()
                if(ans == 1):
                    minute += 29
                else:
                    minute += 14
            else:
                print('아.. 이런 역시 비가오네.. 우산을 다시 가지러 가야하나..?\n')
                print('1. 가지러간다(10분)     2. 가지러가지 않는다')
                ans = Input()
                if(ans == 1):
                    Set_Flag(5, 1)
                    continue
                else:
                    ans = 1
                    continue

        if(hour == 7 and minute == 55):
            Current_Time()
            print('회사 앞에 도착했다.. 현재시간은 {}시 {}분'.format(hour, minute))
            print('빨리 도착했군')
            Loading()
            hour, minute = 8, 30
        elif(hour == 8 and minute == 10):
            Current_Time()
            print('역시 아침 대중교통은 사람이 너무 많아 ㅠㅠ')
            print('어찌됐든... 도착했네')
            Loading()
            hour, minute = 8, 30
        elif(hour == 8 and minute == 5):
            Current_Time()
            print('후.. 우산을 처음부터 챙길걸 그랬군')
            print('택시비만 날렸네')
            hour, minute = 8, 30
            Loading()
        elif(hour == 8 and minute == 20):
            Current_Time()
            print('늦겠다... 뛰어가야지')
            Loading()

        if(hour == 8 and minute == 30):
            Set_Answer(6, ans)
            print('*** 사무실 도착 ***')
            Current_Time()
            print('일하기 전에 커피를 마셔야 할까..?\n')
            print('1. 커피를 마신다   2. 마시지 않는다')
            ans = Input()
            if(ans == 1):
                print('후루룩.. 후루룩...')

        if(hour == 8 and minute == 50):
            Current_Time()
            print(Event)
            print('\n주사위를 굴려서 총 6개의 선택지중 랜덤으로 과거로 돌아갑니다~!')
            Dice_Explain()
            print('\n주사위를 굴리시겠습니까?\n')
            print('1. 굴린다   2. 굴리지 않는다\n')
            ans = Input()
            if(ans == 1):
                rand = randrange(1,len(Past_Branch_Dictionary)+1)
                print('{} (이)가 나왔습니가 !!'.format(rand))
                print('{} 번째 선택으로 돌아갑니가~~!!'.format(rand))
                Loading()
                Past_Branch(rand)
                continue
            else:
                print('그럼.. 열심히 일을 해볼까~~!')
                Loading()

        Time_Flow()
    Current_Time()
    print('체험판이 종료되었습니다')
    print('플레이를 더 원하시면 구매를 해주세요~')
