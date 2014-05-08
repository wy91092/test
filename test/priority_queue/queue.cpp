#include<queue>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Student{
    int _id;
    string _name;
    Student(int id, string name):_id(id),_name(name){

    }
};


//这是个函数对象，它实现了student的比较规则

struct compare{
    bool operator()(const Student &a, const Student &b){
       return a._id <b._id;
    }
};

int main(int argc, char **argv){
   priority_queue<Student, vector<Student>, compare > q;
   q.push(Student(4,"hello")); 
   q.push(Student(5,"hehe")); 
   q.push(Student(3,"haha")); 
   Student tmp=q.top();
   std::cout<<tmp._id<<" "<<tmp._name<<std::endl;
}
