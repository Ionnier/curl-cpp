#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
using namespace std;

class User{
private:
    int id;
    string userName;
    string userLastName;
    string userPassword;
    string email;
public:
    User(const int,const string&,const string&,const string&,const string&);
    User(const string&,const string&,const string&,const string&);
    User(const User&);
    virtual ~User();
    virtual void citire(istream&);
    virtual void afisare(ostream&) const;
    User& operator=(const User&);
    friend istream& operator>>(istream&,User&);
    friend ostream& operator<<(ostream&,const User&);
    void set_id(int id){this->id=id;}
    int get_id(){return id;}

    string& get_json(){
        string *json=new string("{\\\"name\\\":\\\""+userName+"\\\"," + "\\\"last_name\\\":\\\""+userLastName+"\\\","+ "\\\"email\\\":\\\""+email+"\\\"," + "\\\"password\\\":\\\""+userPassword+"\\\"");
        if(id!=0){
            (*json)=(*json)+",\\\"id\\\":\\\""+to_string(id)+"\\\"}";
        } else {
            (*json)=(*json)+"}";
        }
        return *json;
    }
};


User::User(const int id=0,const string& userName="",const string& userLastName="",const string& userPassword="",const string& email=""){
    this->id=id;
    this->userName=userName;
    this->userLastName=userLastName;
    this->userPassword=userPassword;
    this->email=email;
}
User::User(const string& userName="",const string& userLastName="",const string& userPassword="",const string& email=""){
    this->id=0;
    this->userName=userName;
    this->userLastName=userLastName;
    this->userPassword=userPassword;
    this->email=email;
}


User::User(const User& aux){
    id=aux.id;
    userName=aux.userName;
    userLastName=aux.userLastName;
    userPassword=aux.userPassword;
    email=aux.email;
}

User::~User(){
    id=0;
    userName="";
    userLastName="";
    userPassword="";
    email="";
}


void User::citire(istream& in){
    id=0;
    cout<<"Introduceti userName:";
    in>>userName;
    cout<<"Introduceti userLastName:";
    in>>userLastName;
    cout<<"Introduceti userPassword:";
    in>>userPassword;
    cout<<"Introduceti email:";
    in>>email;
}


void User::afisare(ostream& out) const {
    out<<"id="<<id<<endl;
    out<<"userName="<<userName<<endl;
    out<<"userLastName="<<userLastName<<endl;
    out<<"userPassword="<<userPassword<<endl;
    out<<"email="<<email<<endl;
}


istream& operator>>(istream& in,User &aux){
    aux.citire(in);
    return in;
}


ostream&  operator<<(ostream& out,const User &aux){
    aux.afisare(out);
    return out;
}


User& User::operator=(const User& aux){
    if (this!=&aux){
        id=aux.id;
        userName=aux.userName;
        userLastName=aux.userLastName;
        userPassword=aux.userPassword;
        email=aux.email;
    }
    return *this;
}

char *string_to_char_array(string &str)
{
    char *c = new char[str.size()];
    for (int i = 0; i < str.size(); i++)
        c[i] = str[i];
    return c;
}

bool get_http_request(string &request)
{
    string comanda = "curl.exe --output .\\output.txt " + request + " >nul 2> nul";
    if (system(string_to_char_array(comanda)) == 0)
    {
        return true;
    }
    return false;
}

bool execute_http_request(string type,string &request,string &payload)
{
    string comanda = "curl.exe -X "+type+" -H \"Content-Type: application/json\" -d "+payload+" --output .\\output.txt \"" + request + "\" >nul 2> nul";
    if (system(string_to_char_array(comanda)) == 0)
    {
        return true;
    }
    return false;
}


int main()
{
    string domain="http://localhost:3000";
    vector<User> users;
    bool ok=true;
    while(ok){
        system("cls");
        cout<<"====================MENU====================\n";
        cout<<"1. Get Users\n";
        cout<<"2. Show Users\n";
        cout<<"3. Add User\n";
        cout<<"4. Edit User\n";
        cout<<"5. Delete User\n";
        cout<<"0. Exit\n";
        cout<<"Option: \n";
        int option;
        cin>>option;
        switch(option){
        case 1:
            {
                string comanda=domain+"/user";
                if(get_http_request(comanda)==true){
                    ifstream f;
                    f.open(".\\output.txt");
                    while (true) {
                        int id;
                        string userName;
                        string userLastName;
                        string userPassword;
                        string email;
                        string password;
                        f>>id>>userName>>userLastName>>userPassword>>email;
                        User user(id,userName,userLastName,userPassword,email);
                        if( f.eof() ) {f.close();break;}
                        users.push_back(user);
                   }
                }
                break;
            }
        case 2:
            {
                for(int i=0;i<users.size();i++)
                    cout<<users[i]<<endl;
                break;
            }
        case 3:
            {
                string comanda=domain+"/user";
                User *user = new User("asd","bs","d","c");
                if(execute_http_request("POST",comanda,user->get_json())){
                    ifstream f;
                    f.open(".\\output.txt");
                    int id;
                    f>>id;
                    user->set_id(id);
                    users.push_back(*user);
                }
                break;
            }
            break;
        case 4:{
            cout<<"ID =";
            int id;
            cin>>id;
            for(int i=0;i<users.size();i++){
                if(id==users[i].get_id()){
                    string comanda=domain+"/user";
                    User original = users[i];
                    cin>>users[i];
                    users[i].set_id(id);
                    if(execute_http_request("PUT",comanda,users[i].get_json())){
                        cout<<"okay\n";
                    } else {
                        users[i]=original;
                    }
                    break;
                }
            }
            break;
        }
        case 5:{
            cout<<"ID =";
            int id;
            cin>>id;
            for(int i=0;i<users.size();i++){
                if(id==users[i].get_id()){
                    string comanda=domain+"/user";
                    users[i].set_id(id);
                    if(execute_http_request("DELETE",comanda,users[i].get_json())){
                        cout<<"okay\n";
                        users.erase(users.begin() + i);
                    }
                    break;
                }
            }
            break;
        }
        case 0:
            ok=false;
            break;
        }

        system("pause");


    }
    return 0;
}
