//before push/pop/peek, please use is_empty or is_full

const int STACK_MAX = 100;

class StackClass {
    private:
        int top;
        int stack[STACK_MAX];
    public:
        StackClass();
        StackClass(const StackClass &s);
        ~StackClass() {}

        StackClass &operator=(const StackClass &s);

        void push(int item);
        int pop();
        int peek();
        bool is_empty();
        bool is_full();
};