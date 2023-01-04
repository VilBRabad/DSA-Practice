#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack{
    int top;
public:
    int a[MAX];
    Stack (){
        top = -1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x){
    if(top >= (MAX-1)){
        cout<<"Stack Overflow";
        return false;
    }
    else{
        a[++top] = x;
        return true;
    }
}

int Stack::pop(){
    if(top < 0){
        cout<<"Stack is Underflow";
        return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if(top < 0){
        cout<<"Stack is Empty";
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top < 0);
}

int main(){

    Stack s;
    s.push(23);
    s.push(45);
    s.push(7);

    s.pop(); //removes 7

    cout<<s.isEmpty()<<endl; //Returns false
    cout<<"Elements in Stack are = ";
    while(!s.isEmpty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<s.isEmpty();  //return true because in loop all elements are pop()
    

    return 0;
}