#include <stack>
using namespace std;

class MinStack {
    stack<int> main_stack;
    stack<int> min_stack;

  public:
    MinStack(){ }

    void push(int value){
        main_stack.push(value);
        if(min_stack.empty() or min_stack.top() > value){
            min_stack.push(value);
        }
        else{
            min_stack.push(min_stack.top());
        }
    }

    void pop(){
        main_stack.pop();
        min_stack.pop();
    }

    int top(){
        return main_stack.top();
    }

    int getMin(){
        return min_stack.top();
    }
};

