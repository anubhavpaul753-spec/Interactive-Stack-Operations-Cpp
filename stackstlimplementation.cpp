#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int choice = 0;
    while(true) {
        cout<<"1->push element on stack"<<endl;
        cout<<"2->pop element from stack"<<endl;
        cout<<"3->display top of stack"<<endl;
        cout<<"4->display entire stack"<<endl;
        cout<<"5->reverse the stack"<<endl;
        cout<<"6->Push element at any Index(0-indexed stack)"<<endl;
        cout<<"7->Exit"<<endl;
        cout<<"Whats your choice"<<endl;
        cin>>choice;

        if(choice==1) {
            int num;
            cout<<"The number u want to push is:- "<<endl;
            if(cin>>num) {
                s.push(num);
                cout<<"Pushed "<<num<<" to stack succesfully"<<endl;
            } else {
                cout<<"Invalid input, push failed"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
            }
        }

        else if(choice==2) {
            if(!s.empty()) {
                int popped = s.top();
                s.pop();
                cout<<"Pop successful.. popped "<<popped<<endl;
            } else {
                cout<<"Stack is empty, cannot pop"<<endl;
            }
        }

        else if(choice==3) {
            if(!s.empty()) {
                cout<<"The Top of the stack is "<<s.top()<<endl;
            } else {
                cout<<"Stack is empty, no top element"<<endl;
            }
        }

        else if(choice==4) {
            if(s.size()==0){
                cout<<"Stack is empty...nothing to display"<<endl;
            }
            else{
                stack<int> temp;
                while(s.size()>0){
                    cout<<s.top()<<" ";
                    int t = s.top();
                    s.pop();
                    temp.push(t);
                }
                cout<<endl;
                while(temp.size()>0) {
                    int t = temp.top();
                    temp.pop();
                    s.push(t);
                }
                cout<<"Display Succesfull.."<<endl;
            }
        }
        else if(choice==5) {
            stack<int> t1;
            stack<int> t2;
            while(s.size()>0) {
                int poped = s.top();
                t1.push(poped);
                s.pop();
            }
            while(t1.size()>0) {
                int poped = t1.top();
                t2.push(poped);
                t1.pop();
            }
            while(t2.size()>0) {
                int poped = t2.top();
                s.push(poped);
                t2.pop();
            }
            cout<<"Reversing stack elements in the same stack succesfull"<<endl;
        }
        else if(choice==6) {
            int idx;
            cout<<"Enter the index where u want to push element from 0 to "<<(s.size()-1)<<endl;
            cin>>idx;
            int num;
            cout<<"Enter the element you want to push index "<<idx<<endl;
            cin>>num;
            stack<int> temp;
            int size = s.size();
            for(int i=1; i<=(size-idx); i++) {
                temp.push(s.top());
                s.pop();
            }
            s.push(num);
            while(temp.size()>0) {
                s.push(temp.top());
                temp.pop();
            }
        }
        else if(choice==7) {
            cout<<"Exiting Loop...task executed succesfully"<<endl;
            break;
        }

        else {
            cout<<"Invalid choice, please try again"<<endl;
        }
    }

    return 0;
}
