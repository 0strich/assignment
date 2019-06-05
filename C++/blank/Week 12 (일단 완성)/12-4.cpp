#include <iostream>
using namespace std;

template <class T>
class Array{
protected:
    T *m_arr;
    int m_maxSize;
    int m_curSize;
public:
    Array(int size = 5){
        m_maxSize = size;
        m_curSize = 0;
        m_arr = new T[m_maxSize];
    }
    ~Array(){delete m_arr;}

    void Add(int data);
    bool GetAt(int index, T& data);
    bool SetAt(int index, T data);
    int GetSize();
};

template <class T>
void Array<T>::Add(int data){
    if(m_curSize >= m_maxSize){
        T* tmp = m_arr;
        m_maxSize += 5;
        m_arr = new T[m_maxSize];
        for(int i=0; i<m_curSize; i++)
            m_arr[i] = tmp[i];
        delete tmp;
    }
    m_arr[m_curSize] = data;
    m_curSize++;
}

template <class T>
bool Array<T>::GetAt(int index, T& data){
    if(m_curSize > m_maxSize)
        return false;
    data = m_arr[index];
    return true;
}

template <class T>
bool Array<T>::SetAt(int index, T data){
    if(m_curSize > m_maxSize)
        return false;
    data = m_arr[index];
    return true;
}

template <class T>
int Array<T>::GetSize(){
    return m_curSize;
}

int main(){
    Array<int> arr;
    int num;
    cout << "정수를 입력하세요(-1이면 종료) : ";
    cin >> num;
    while(num != -1){
        arr.Add(num);
        cout << "정수를 입력하세요(-1이면 종료) : ";
        cin >> num;
    }
    cout << "입력된 정수 : ";
    for(int i=0; i<arr.GetSize(); i++){
        int data;
        arr.GetAt(i, data);
        cout << data << ' ';
    }
    cout << endl;

    return 0;
}
