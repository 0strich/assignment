#include <iostream>
using namespace std;

template <class T>
class MyStack{
    int m_top_index;
    T m_data[100];
public:
    MyStack();
    void Push(T element);
    T Pop();
    T Peek();
};

template <class T>
MyStack<T>::MyStack(){
    m_top_index = 0;
}

template <class T>
void MyStack<T>::Push(T element){
    if(m_top_index == 100){
        cout << "stack full";
        return ;
    }
    m_data[m_top_index] = element;
    m_top_index++;
}

template <class T>
T MyStack<T>::Pop(){
    if(m_top_index == 0){
        cout << "stack empty";
        return 0;
    }
    m_top_index--;
    return m_data[m_top_index];
}

template <class T>
T MyStack<T>::Peek(){
    if(m_top_index == 0){
        cout << "stack is empty";
        return 0;
    }
    return m_data[m_top_index-1];
}

int main(){
    MyStack<int> iStack;
    iStack.Push(3);
    iStack.Push(5);
    cout << iStack.Peek() << endl;
    cout << iStack.Pop() << endl;

    MyStack<double> dStack;
    dStack.Push(2.2);
    cout << dStack.Pop() << endl;

    MyStack<char> *p = new MyStack<char>;
    p->Push('k');
    cout << p->Pop() << endl;
    cout << p->Peek() << endl;
    delete p;

    return 0;
}
