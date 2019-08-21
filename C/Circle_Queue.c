#include <stdio.h>
#define MAX 11                   // 삽입가능 요소 : 10개 (MAX - 1)

int front = 0;
int rear = 0;
int queue[MAX];

int IsEmpty();                  // 비어있는지 확인
int IsFull();                   // Full 인지 확인
void Insert(int value);         // 값 추가
int Delete();                   // 값 삭제
int get_count();                // 값 카운트 (과제요구)

int main(){

    for(int i = 1; i <= 7; i++) // 1 ~ 7 까지 순서대로 Insert
        Insert(i);
    
    printf("요소의 개수는 %d개 입니다.\n", get_count());

    return 0;
}



int IsEmpty(){
    if(front==rear)     //front와 rear가 같으면 큐는 비어있는 상태 
        return 1;
    else 
        return 0;
}
int IsFull(){
    int tmp=(rear+1)%MAX;   //원형 큐에서 rear+1을 MAX로 나눈 나머지값이
    if(tmp==front)          //front와 같으면 큐는 가득차 있는 상태 
        return 1;
    else
        return 0;
}
void Insert(int value){
    if(IsFull())
        printf("Queue is Full.\n");
    else
        queue[++rear]=value;
}
int Delete(){
    if(IsEmpty())
        printf("Queue is Empty.\n");
    else{
        front = (front+1)%MAX;
        return queue[front];
    }
}
// 과제 결과
int get_count(){
    // 요소의 개수를 카운트할 cnt 함수
    int cnt = 0;
    if(IsFull())                            // 요소의 개수가 가득차있으면 MAX-1 을 반환
        return MAX-1;
    else{
        while(cnt != (rear % MAX)) cnt++;   // rear % MAX 의 수만큼 cnt++ 연산 (요소 개수 카운트)
        return cnt;                         // 구해진 요소 개수를 반환
    }
}
