#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Command
{
public:
	virtual void execute() = 0;
};

/**
 * 所有继承自 Command 的对象就是一个行为对象
 * 这个对象表征一个行为 ： 比如厨师做饭
*/
class ConcreteCommand1 : public Command
{
	string args;
	/**   
	 * 可能有更多的可以操作的对象
	*/
public:
	ConcreteCommand1(const string& a) : args(a) {}
	void execute() override
	{
		cout << "#1 process ..." << args << endl;
	}
};

/**
 * 这个类代表了另一个行为 ： 比如厨师烧汤
*/
class ConcreteCommand2 : public Command
{
	string args;
public:
	ConcreteCommand2(const string& a) : args(a) {}
	void execute() override
	{
		cout << "#2 process ..." << args << endl;
	}
};

/**
 * 这里 也使用了 Composite 设计模式
 * 这个类相应的可以看作是服务员，我们所有的请求只要告诉服务员就可以了，不管是做饭还是烧汤
*/
class MacroCommand : public Command
{
	vector<Command*>	commands;
public:
	void addCommand(Command* c) { this->commands.push_back(c); }
	/**
	 * 服务员去和厨师进行沟通
	*/
	void execute() override
	{
		for (auto &c : this->commands)
			c->execute();
	}
};

int main()
{
	ConcreteCommand1 command1("Args ###");
	ConcreteCommand2 command2("Args $$$");

	MacroCommand macro;
	macro.addCommand(&command1);
	macro.addCommand(&command2);

	macro.execute();
}