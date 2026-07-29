class MyQueue {
public:

    stack<int> st1;
    stack<int> st2;

    MyQueue() {

    }

    void transfer(stack<int>& st1,stack<int>& st2){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    }
    
    void push(int x) {
        transfer(st2,st1);
        st1.push(x);
        transfer(st1,st2);
    }
    
    int pop() {
        int top=st2.top();
        st2.pop();
        return top;
    }
    
    int peek() {
        return st2.top();
    }
    
    bool empty() {
        return st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
