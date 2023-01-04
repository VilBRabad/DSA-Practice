#include <iostream>
#include <stack>

using namespace std;

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
    stack <int> posts;
    int cnt=0;

    User(string u, string p){
        username = u;
        password = p;
        wrongCredentialCount = 0;
    }

    bool login(string u, string p){
        if(username == u && password == p){
            wrongCredentialCount = 0;
            cout<<"You have successfully logged in"<<endl;
            return true;
        }
        else{
            wrongCredentialCount++;
            if(wrongCredentialCount >= 3){
                cout<<"You have entered wrong credentials for 3 consecutive times. Open your email for account recovery."<<endl;
            }else{
                cout<<"Wrong Credentials"<<endl;
            }
            return false;
        }
    }

    void AddPost(){
        cout<<"Do you want to add Pots\n(Y/N) : ";
        string res;
        cin>> res;
        if(res == "Y" || res == "y"){
            cnt++;
            posts.push(cnt);
            cout<<"Post Added"<<endl;
        }else{
            cout<<"Post Not Added"<<endl;
        }
    };

    void likePost(post& p){
        p.likes++;
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

    User U1("Sumit", "b@143");
    U1.login("Sumit", "b@143");

    U1.AddPost();

    post P1(1, "Text");

    U1.likePost(P1);
    P1.showlikes();
    U1.comment();
    U1.deletepost();

    return 0;
}