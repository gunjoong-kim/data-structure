
//implement stack with linked list

typedef struct {
    int data;
    node *next;
} node;

class StackClass {
    private:
        node *top;
    public:
        StackClass();
        StackClass(const StackClass &s);
        ~StackClass();
        void push(int item);
        int pop();
        bool is_empty();
};