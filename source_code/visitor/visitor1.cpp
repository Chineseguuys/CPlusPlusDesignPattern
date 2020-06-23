class Element 
{
public:
    virtual void Fun1() = 0;
    /**
     * 如果我们在这里需要添加一个类 Fun2()
     * 那么我们可能需要在每一个子类中进行修改，修改量非常的大
    */
    
    virtual ~Element() {}
};

class ElementA : public Element
{
public:
    virtual void Fun1(){
        // .....
    }
};

class ElementB : public Element
{
    public:
        virtual void Fun1(){
            // ......
        }
};

