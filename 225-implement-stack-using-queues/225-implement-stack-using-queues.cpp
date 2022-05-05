class MyStack {
public:
    
    queue<int> primary;
    queue<int> auxiliary;
    
    MyStack() {
        
    }
    
    void push(int x) {
        while(!primary.empty()){
            auxiliary.push(primary.front());
            primary.pop();
        }
        primary.push(x);
        while(!auxiliary.empty()){
            primary.push(auxiliary.front());
            auxiliary.pop();
        }
    }
    
    int pop() {
        int top = primary.front();
        primary.pop();
        return top;
    }
    
    int top() {
        return primary.front();
    }
    
    bool empty() {
        return primary.empty();
    }
};