#include<string>
#include <iostream>
using namespace std;

//本系统380题（继承与组合2）中，派生类Teacher_Cadre（教师兼干部）中有冗余数据以及二义性问题，请改造Teacher(教师)类、Cadre（干部）类、Teacher_Cadre（教师兼干部），消除二义性并去除数据冗余。

//1. 改造后Teacher类对象、Cadre类对象、Teacher_Cadre类对象的数据成员跟原来一样（Teacher_Cadre类的对象中要去除冗余)

//2. 可以引入一个新类。

//3.Teacher_Cadre依旧要求从Teacher类和Cadre类多继承

//4. Teacher_Cadre类中新增的数据成员wage使用double类型
class People{
public:
    People(string nam,int a,char s,string ad,string t);
protected:
    string name;
    int age;
    char sex;
    string addr;
    string tel;
};
class Teacher:virtual public People
{
public:
    Teacher(string nam,int a,char s,string tit,string ad,string t);
    void display();
protected:
    string title;
};

class Cadre:virtual public People
{
public:
    Cadre(string nam,int a,char s,string p,string ad,string t);
    void display();
protected:
    string post;
};
class Teacher_Cadre:public Teacher,public Cadre{
public:
    Teacher_Cadre(string name,int age,char sex,string title,string post,string address,string tele,double wages);
    void show();
private:
    double wage;
};
People::People(string nam,int a,char s,string ad,string t):name(nam),age(a),sex(s),addr(ad),tel(t){

}
Teacher::Teacher(string nam,int a,char s,string tit,string ad,string t):People(nam,a,s,ad,t),title(tit){

}
Cadre::Cadre(string nam,int a,char s,string p,string ad,string t):People(nam,a,s,ad,t),post(p){

}
Teacher_Cadre::Teacher_Cadre(string name,int age,char sex,string title,string post,string address,string tele,double wages):People(name,age,sex,address,tele),Teacher(name,age,sex,title,address,tele),Cadre(name,age,sex,post,address,title),wage(wages){

}
void Teacher::display()
{
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"title:"<<title<<endl;
    cout<<"address:"<<addr<<endl;
    cout<<"tel:"<<tel<<endl;
}

void Cadre::display()
{
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"post:"<<post<<endl;
    cout<<"address:"<<addr<<endl;
    cout<<"tel:"<<tel<<endl;
}

void Teacher_Cadre ::show()
{
    Teacher::display();
    cout<<"post:"<<post<<endl;
    cout<<"wages:"<<wage<<endl;
}

int main()
{
    string name,title,post,address,tele;
    int age;
    char sex;
    float wages;
    cin>>name>>age;
    cin>>sex>>title>>post;
    getline(cin,address);
    cin>>tele>>wages;
    Teacher_Cadre te_ca(name,age,sex,title,post,address,tele,wages);
    te_ca.show();

    cout << sizeof(Teacher) << endl;
    cout << sizeof(Cadre) << endl;
    cout << sizeof(Teacher_Cadre) << endl;

    return 0;
}

