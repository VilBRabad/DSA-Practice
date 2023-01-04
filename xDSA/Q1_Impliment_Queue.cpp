#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    int qfront, rear;
    int *arr;
    int size;

    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        if(qfront == size){
            cout<<"Queue is Full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear){
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                rear = 0;
                qfront = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear){
            return -1;
        }
        return arr[qfront];
    }
};


int main()
{

    Queue Q;
    Q.enqueue(2);
    Q.enqueue(3);
    cout << Q.dequeue() << " ";
    Q.enqueue(5);
    cout << Q.dequeue();

    return 0;
}