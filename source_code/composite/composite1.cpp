#include <algorithm>
#include <string>
#include <list>
using namespace std;

class Componet
{
public:
	virtual void process() = 0;
	virtual ~Componet() {}
};

class Composite : public Componet
{
	string name;
	list<Componet*>	elements;
public:
	Composite(const string& s) : name(s) {}
	/**
	 * add() 和 remove() 方法没有放入 Componet 接口当中，因为
	 * 叶子节点没有必要实现这些功能
	*/
	void add(Componet* element) {
		elements.push_back(element);
	}
	void remove(Componet* element){
		elements.remove(element);
	}
	// 多态
	void process(){
		// process current node
		
		// process leaf node

		for (auto& e : elements)
		/**
		 * 使用树形的结构对叶子节点和非叶子节点进行分别的处理
		*/
			e->process();	// 多态的调用
	}
};


class Leaf : public Componet 
{
	string name;
public:
	Leaf(string s) : name(s) {}
	// 多态
	void process(){
		// process current node
	}
};

/**
 * 传入 Invoke() 函数的不论时什么类型都可以进行正确的处理
*/
void Invoke (Componet& c)
{
	// ....
	c.process();
	// ....
}

int main()
{
	Composite root("root");
	Composite treenode1("treenode1");
	Leaf leaf("leaf1");

	Invoke(root);
	Invoke(treenode1);
	Invoke(leaf);
}