class Visitor;

class Element 
{
public:
    virtual void accept(Visitor& Visitor) =  0; // 第一次动态辨析

    virtual ~Element() {}
};

class ElementA : public Element
{
public:
    void accept(Visitor& visitor) override{
        visitor.visitElementA(*this);   // 第二次动态辨析
    }
};

class ElementB : public Element
{
public:
    void accept(Visitor& visitor) override{
        visitor.visitElementB(*this);
    }
};

/**
 * Visitor 应该要可以访问 Element 以及其子类 ElementA 和 ElementB 的所有的数据
 * 否则不能保证可以实现相对应的功能
*/
class Visitor{
public:
    virtual void visitElementA(ElementA& Element) = 0;
    virtual void visitElementB(ElementB& Element) = 0;
    virtual ~Visitor() {}
};

// ============== 以上的部分都是稳定的，所有的需求变化的部分都在下面进行实现

/**
 * ElementA 和 ElementB 新添加的操作
 * 这些操作相当于在 visitor1.cpp 中在 Element 基类中添加操作
*/
class Visitor1 : public Visitor
{
public:
    void visitElementA(ElementA& element) override
    {
        // 针对 elementA 进行操作
    }

    void visitElementB(ElementB& element) override
    {
        // 针对 elementB 进行操作
    }
};

/**
 * 添加新的操作
*/
class Visitor2 : public Visitor
{
public:
    void visitElementA(ElementA& element) override
    {
        // 针对 elementA 进行操作
    }

    void visitElementB(ElementB& element) override
    {
        // 针对 elementB 进行操作
    }
};

int main()
{
    Visitor2 visitor;   /*添加新的需求*/
    ElementB elementB;
    elementB.accept(visitor);   // double dispatch 

    ElementA elementA;
    elementA.accept(visitor);
}