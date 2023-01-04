#include <iostream>
#include <stack>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class post{
    int postId;
public:
    string postType;
    int likes;

    post(int pId, string pT){
        postId = pId;
        postType = pT;
        likes = 0;
    }

    int showlikes(){
        cout<<"Post Likes: "<<likes<<endl;
        return likes;
    }


};

class User{
    string password;
public:
    string username;
    int wrongCredentialCount;
    stack <int> Posts;
    Node* head;

    User(string u, string p){
        username = u;
        password = p;
        wrongCredentialCount = 0;
        head = NULL;
    }

    bool login(string u, string p){
        if(username == u && password == p){
            wrongCredentialCount = 0;
            cout<<"You have successfully logged in"<<endl;
            return true;
        }else{
            wrongCredentialCount++;
            if(wrongCredentialCount >= 3){
                cout<<"You have entered wrong credentials for 3 consecutive times. Open your email for account recovery."<<endl;
            }else{
                cout<<"Wrong Credentials"<<endl;
            }
            return false;
        }
    }

    void AddPost(int postNo){
        Posts.push(postNo);
    }

    void PostConfirmation(){
        while(Posts.size() != 0){
            cout<<"Do you want to add Post\n(Y/N)"<<endl;
            string res;
            cin>> res;
            if(res == "Y" || res == "y"){
                    if(head==NULL){
                        Node* newNode;
                        newNode->data = Posts.top();
                        head = newNode;
                    }else{
                        Node* temp = head;
                        while(temp->next != NULL){
                            temp = temp->next;
                        }
                        Node* newNode;
                        newNode->data = Posts.top();
                        temp->next = newNode;
                    }
                cout<<"Post Added"<<endl;

            }else{

                cout<<"Post Not Added"<<endl;
            }
            Posts.pop();
        }
    };

    void likePost(post& p){
        p.likes++;
    };

    void viewPosts(){
        cout<<"Your Post are: ";
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    };
    void comment(){
        cout<<"you have 2 comment:"<<endl;
    }
    void deletepost() {
        cout<<"Post deleted!"<<endl;
        
    }
};

int main()
{

    User U1("Bhavesh", "b@143");

    U1.login("Bhavesh", "b@143");

    int postNo = 1;
    U1.AddPost(postNo);
    U1.PostConfirmation();

    post P1(1, "Text");
    U1.likePost(P1);
    P1.showlikes();
    U1.comment();
    U1.deletepost();

    U1.viewPosts();

    return 0;
}
