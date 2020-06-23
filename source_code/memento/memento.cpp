#include <string>
using namespace std;

class Memento
{
	/**
	 * 这里的保存只是 一个简单的示例， 正式的快照可能采用一定编码方式对需要
	 * 保存快照的类的内容进行保存，可能是二进制的数据，也可能是字符串值，只要
	 * 可以恢复就可以了
	*/
	string state;
public:
	Memento(const string& s) : state(s) {}
	string getState() const { return state; }
	void setState(const string& s) { state = s; } 
};

class Originator
{
	/**
	 * 这个类拥有很多的状态需要进行保存
	*/
	string state;
	// ....
public:
	Originator() {}
	/**
	 * 我们需要在某些时刻对这个类的状态保存快照
	*/
	Memento createMemento() {
		Memento m (state);
		return m;
	}

	void setMemento(const Memento& m)
	{
		/**
		 * 这里也只是一个示例化的方法，正式的恢复的过程可能是从某种编码的二进制文件中恢复，
		 * 或者从某种字符串文件中进行恢复，序列化的技术 等等
		*/
		state = m.getState();
	}
};
/**
 * 这个模式本身很简单，难度在于使用什么方式保存快照，如果需要频繁的保存快照，可能就要考虑存储空间和内存开销方面的考虑，
 * 在快照的存储方式和编码方式上进行优化
*/

int main()
{
	Originator origin;

	// 存储到备忘录
	Memento mem = origin.createMemento();

	// 从备忘录中进行恢复
	origin.setMemento(mem);

}