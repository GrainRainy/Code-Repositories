class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> q1, q2;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (q1.size() > 1)
		{
			q2.push(q1.top());
			q1.pop();
		}
		int save = q1.top();
		q1.pop();
		while (q2.size() > 0)
		{
			q1.push(q2.top());
			q2.pop();
		}
		return save;
    }
    
    /** Get the front element. */
    int peek() {
         while (q1.size() > 1)
		{
			q2.push(q1.top());
			q1.pop();
		}
		int save = q1.top();
		while (q2.size() > 0)
		{
			q1.push(q2.top());
			q2.pop();
		}
		return save;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
