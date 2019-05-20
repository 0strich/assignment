#-*- coding:utf-8 -*-

from random import *
from time import *

hour, minute = 7, 0
flag = 0
Event = '''★★★★★★★★★★★★★★★★★★
★   Event Time   ★
★   Random Cube  ★
★★★★★★★★★★★★★★★★★★'''

def Time():
    global hour, minute
    minute += 1
    if(minute >= 60):
        hour += int(minute / 60)
        minute %= 60

def Real_Time():
    global hour, minute
    print('현재 시간 : {}시 {}분'.format(hour, minute))

def Input():
    while(True):
        var = int(input('Choose\n'))
        if(var == 1 or var == 2):
            print()
            return var
        else:
            print('Only Input 1 or 2',end='\n\n')

def Loading(repeat):
    for i in range(repeat):
        print('★'*(i+1))
        sleep(1)

def Back_to_the_past(rand):
    var = rand * 10
    global hour, minute
    if(minute >= var):
        minute -= var
    else:
        hour -= 1
        minute = 60 - (var - minute)

if __name__ == '__main__':
    while(True):
        # 기상 시간
        if(hour == 7 and minute == 10):
            Real_Time()
            print('출근시간이 8시 30분까지니깐 7시 반에 출발해야겠군..', end='\n\n')

        if(hour == 7 and minute == 30):
            Real_Time()
            print('그럼.. 출근을 해볼까')
            print('오늘 날씨가 좀 흐린걸... 우산을 챙길까..?')
            print('1. 챙긴다   2. 안 챙긴다', end='\n\n')
            ans = Input()

        # ans 변수에 따라 출근할지, 우산을 다시 챌기러 갈지 선택
        if(hour == 7 and minute == 40):
            # 우산을 가지러 갔다온 경우 flag 를 1로 변경 하고 10분 늘린다
            if(flag == 1):minute = 50
            Real_Time()
            if(ans == 1):
                print('음... 대중교통을 탈까, 택시를 탈까..?')
                print('1. 대중교통(30분)  2. 택시(15분)', end='\n\n')
                ans = Input()
                if(ans == 1):
                    minute += 29
                else:
                    minute += 14
            else:
                print('아.. 이런 역시 비가오네.. 우산을 다시 가지러 가야하나..?')
                print('1. 가지러간다(10분)     2. 가지러가지 않는다', end='\n\n')
                ans = Input()
                if(ans == 1):
                    flag = 1
                    continue
                else:
                    ans = 1
                    continue

        if(hour == 7 and minute == 55):
            Real_Time()
            print('회사 앞에 도착했다.. 현재시간은 {}시 {}분'.format(hour, minute))
            print('빨리 도착했군',end='\n\n')
            Loading(6)
            hour, minute = 8, 30
        elif(hour == 8 and minute == 10):
            Real_Time()
            print('역시 아침 대중교통은 사람이 너무 많아 ㅠㅠ')
            print('어찌됐든... 도착했네',end='\n\n')
            Loading(2)
            hour, minute = 8, 30
        elif(hour == 8 and minute == 5):
            Real_Time()
            print('후.. 우산을 처음부터 챙길걸 그랬군')
            print('택시비만 날렸네',end='\n\n')
            hour, minute = 8, 30
            Loading(4)
        elif(hour == 8 and minute == 20):
            Real_Time()
            print('늦겠다... 뛰어가야지',end='\n\n')
            Loading(2)

        if(hour == 8 and minute == 30):
            print('*** 사무실 도착 ***')
            Real_Time()
            print('일하기 전에 커피를 마셔야 할까..?')
            print('1. 커피를 마신다   2. 마시지 않는다', end='\n\n')
            ans = Input()
            if(ans == 1):
                print('후루룩.. 후루룩...',end='\n\n')

        if(hour == 8 and minute == 50):
            print(Event)
            print('주사위를 굴리시겠습니까?')
            print('1. 굴린다   2. 굴리지 않는다',end='\n\n')
            ans = Input()
            if(ans == 1):
                rand = randrange(1,7)
                print('{} (이)가 나왔습니가 !!'.format(rand))
                print('{} 분 전으로 돌아갑니가~~!!'.format(rand * 10))
                Loading(rand)
                Back_to_the_past(rand)

        Time()
