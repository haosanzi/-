#include<iostream>
#include<vector>
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;

//观察者抽象接口,
class Observer {
public:
    Observer(){}
    virtual ~Observer(){}
    virtual void update(){}
};

class Blog{
public:
    Blog(){};
    virtual ~Blog(){}
    void Add(Observer* observer){ //增加观察者 
        m_observers.push_back(observer);
    }
    void Remove(Observer* observer) { //删除观察者 
        m_observers.remove(observer);
    }
    void notify(){
        for(auto itr=m_observers.begin();itr!=m_observers.end();itr++){
            (*itr)->update();
        }
    } 
    virtual void Setstatus(string s) {
        m_status=s;
    } 
    virtual string Getstatus(){
        return m_status;
    }
    
private: //
    list<Observer*> m_observers;//观察者链表 
protected:
    string m_status; //状态 
        
};

class BlogCSDN :public Blog{
private:
    string m_name;//博主姓名
    public:
    BlogCSDN(string name): m_name(name) {}  
    ~BlogCSDN() {}  
    void SetStatus(string s) { m_status = "CSDN通知 : " + m_name + s; } //具体设置状态信息  
    string GetStatus() { return m_status; }  
     
};

class ObserverBlog : public Observer{
private:
    string m_name;
    Blog* m_blog;
public:
    ObserverBlog(string name,Blog *blog): m_name(name), m_blog(blog) {}  
    ~ObserverBlog() {}  
    void update()  //获得更新状态  
    {   
        string status = m_blog->Getstatus();  
        cout<<m_name<<"-------"<<status<<endl; 
    }  
            
};



int main(){
    Blog *blog = new BlogCSDN("wuzhekai1985");  
    Observer *observer1 = new ObserverBlog("tutupig", blog);  
    blog->Add(observer1);  
    blog->Setstatus("发表设计模式C++实现（15）——观察者模式");  
    blog->notify();  
    delete blog; 
    delete observer1;  
    return 0;  
}