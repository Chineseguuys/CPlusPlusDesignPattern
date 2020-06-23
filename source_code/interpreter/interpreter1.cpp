#include <iostream>
#include <map>
#include <stack>
using namespace std;

/**
 * 总的表达时的基类
*/
class Expression{
public:
	virtual int interpreter(map<char, int>& var) = 0;
	virtual ~Expression() {}
};


// 变量表达式
/**
 * 变量表达式的解析过程就是返回自己的值
*/
class VarExpression : public Expression
{
	char key;
public:
	VarExpression(const char& key){
		this->key = key;
	}

	int interpreter(map<char, int>& var) override{
		return var[key];
	}
};

// 符号表达时
/**
 * 符号表达时用于存储二目运算符参与运算的双方的变量表达式
*/
class SymbolExpression : public Expression 
{
protected:
	Expression* left;
	Expression* right;

public:
	SymbolExpression(Expression* left, Expression* right)
		: left(left), right(right)
	{}
};

// 加法运算
class AddExpression : public SymbolExpression
{
public:
	AddExpression(Expression* left, Expression* right):
		SymbolExpression(left, right)
	{}

	int interpreter(map<char, int>& var) override
	{
		return left->interpreter(var) + right->interpreter(var);
	}
};


// 减法运算
class SubExpression : public SymbolExpression
{
public:
	SubExpression(Expression* left, Expression* right):
		SymbolExpression(left, right)
	{}

	int interpreter(map<char, int>& var) override
	{
		return left->interpreter(var) - right->interpreter(var);
	}
};

/**
 * 语句解释 将语句解释为一个个的模块
*/
Expression* analyse(string expStr)
{
	stack<Expression*> expstack;
	Expression* left = nullptr;
	Expression* right = nullptr;

	for (int i = 0; i < expStr.size(); ++i){
		switch(expStr[i])
		{
			case '+':
				left = expstack.top();
				right = new VarExpression(expStr[++i]);
				expstack.push(new AddExpression(left, right));
				break;
			case '-':
				left = expstack.top();
				right = new VarExpression(expStr[++i]);
				expstack.push(new SubExpression(left, right));
				break;
			default:
				expstack.push(new VarExpression(expStr[i]));
		}
	}
	Expression* expression = expstack.top();
	return expression;
}

int main()
{
	string expStr = "a+b-c+d";	/*变化的部分*/
	map<char , int> var;
	var.insert(make_pair('a', 5));
	var.insert(make_pair('b', 2));
	var.insert(make_pair('c', 1));
	var.insert(make_pair('d', 6));

	Expression* expression = analyse(expStr);
	int result = expression->interpreter(var);

	cout << result << endl;

	return 0;
}