// Implimentaion of Stack Using Queue
//Stack : LIFO
//Queue : FIFO
#include<iostream>
#include<queue>
using namespace std;

class stack{
    public:
    queue<int>q1, q2;
    
    void push(int x){
        
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int>q = q1;
        q1 = q2;
        q2 = q;
    }
    void pop(){
        if(q1.empty()){
            return;
        }
        q1.pop();
    }
    int size(){
        if(q1.empty()){
            return -1;
        }
        return q1.size();
    }
    int top(){
        if(q1.empty())
            return -1;
        return q1.front();
    }
};

int main(){
    int x;
    stack st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(34);
    // for(int i=0; i<4; i++){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    cout<<"Top element: "<<st.top()<<endl;
    cout<<"Size of Stack: "<<st.size()<<endl;
    st.pop();

    cout<<"Top element: "<<st.top()<<endl;
    cout<<"Size of Stack: "<<st.size()<<endl;    

    return 0;
}

