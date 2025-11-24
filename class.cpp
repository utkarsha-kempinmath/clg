#include <iostream>
using namespace std;

class abc {
    public:
        int rolls;
        string name; 
        string skills;
        float cgpa;
        string email;
        string number;
        void insertData(){
            cout<<"enter name"<<endl;
            cin>>name;
            cout<<"enter roll no"<<endl;
            cin>>rolls;
        }
        void resume(){
            cout<<"enter email"<<endl;
            cin>>email;
            cout<<"enter mobile no"<<endl;
            cin>>number;
            if (number.length()>10)
            {
                cout<<"re-enter number"<<endl;
                cin>>number;
            }
            cout<<"enter skills"<<endl;
            cin>>skills;
            cout<<"enter cgpa"<<endl;
            cin>>cgpa;
        }
        void show() {
            cout<<"name: "<< name<<endl;
            cout<<"roll no: "<< rolls <<endl;
            cout<<"email: "<< email <<endl;
            cout<<"mobile number: "<<number<<endl;
            cout<<"skills: "<< skills<<endl;
            cout<<"cgpa: "<< cgpa<<endl;
        };
};

int main(){
    abc s1;
    s1.insertData();
    s1.resume();
    s1.show();
}
