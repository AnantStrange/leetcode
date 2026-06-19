struct Node{
    int val;
    Node* next;
};
Node* newNode(int i){
    Node* to_return = new Node;
    to_return->val = i;
    to_return->next = nullptr;
    return to_return;
}

class Stack{
    Node* head;
  public:
    Stack(){
        head = nullptr;
    }

    void push(int value){
        if(!head){
            head = newNode(value);
            return;
        }
        Node* to_insert = newNode(value);
        to_insert->next = head;
        head = to_insert;
    }

    void pop(){
        if(!head){
            return;
        }
        Node* to_del = head;
        head = head->next;
        delete  to_del;
    }

    int top(){
        if(!head){
            return -99;
        }
        return head->val;
    }

    bool isEmpty(){
        if(!head){
            return true;
        }
        return false;
    }
};

class MinStack {
    Stack *main_stack;
    Stack *min_stack;

  public:
    MinStack(){
        main_stack = new Stack;
        min_stack = new Stack;
    }

    void push(int value){
        main_stack->push(value);
        if(min_stack->isEmpty() or min_stack->top() > value){
            min_stack->push(value);
        }
        else{
            min_stack->push(min_stack->top());
        }
    }

    void pop(){
        main_stack->pop();
        min_stack->pop();
    }

    int top(){
        return main_stack->top();
    }

    int getMin(){
        return min_stack->top();
    }
};

