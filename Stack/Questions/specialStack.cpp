// Question Link : https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

#include <stack>
class SpecialStack 
{
    private:
    	stack<int> st;
    	int mini;
    
    public:
    void push(int data) 
    {
        // if stack is empty
        if(st.empty()) {
            st.push(data);
            mini = data;
            return;
        }
        else {
            if(data < mini) {
                st.push(2*data - mini);  // 2x - prevMin
                mini = data;
            }
            else
                st.push(data);
		}
    }

    int pop() 
    {
        // if Stack is Empty
        if(st.empty())
			return -1;
        else {
            int curr = st.top();
            st.pop();
            if(curr > mini) {
                return curr;
            }
            else {
                int prevMin = mini;
                mini = 2*mini - curr;	// 2x - (2x - prevMin)
                return prevMin;
            }
        }
    }

    int top() 
    {
        // if stack is empty
        if(st.empty())
            return -1;
        else {
            int curr = st.top();
            if(curr < mini)
                return mini;
            else
                return curr;
        }
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() 
    {
        // if stack is empty
        if(st.empty())
			return -1;
        else
            return mini;
    }  
};

/*

Time Complexity: O(1)
Space Complexity: O(1)

*/