class Singleton {
public:
    // factory method (used for accessing the single instance of the class)
    static Singleton &getInstance();

    // public methods
    int getData();  
    void setData(int data);

private:  
    // private constructor for preventing object creation through new operator
    Singleton();

    // singleton instance
    static Singleton *_INSTANCE;
    int _data;    
};