class Form{/*已经实现*/};
class TextBox{/*已经实现*/};
class ProgressBar{/*已经实现*/};

#include "./Splitter2.cpp"

class MainForm : public Form{
	TextBox*		textFilePath;
	TextBox*		textFileNumber;
	ProgressBar*	progressBar;

public:
	void Button1_Click(){
		string filePath = textFilePath->getText();
		int number = atoi(textFileNumber->getText().c_str());

		ISplitter* splitter = new BinarySplitter(filePath, number);	// 面向接口
		/**
		 * 虽然这里使用了抽象的接口类型 ISplitter,但是后面的 new 的过程依然是一个具体的类
		 * BinarySplitter，那么依然存在类之间的依赖关系。这种关系是在程序的编译期间就会确定下来
		*/
		/**
		 * 那么我们的设计目标就是要绕开这个 new 带来的依赖的问题
		 * 在面对接口的设计中，我们不能等式的左边变成了依赖抽象，但是等式的右边还是依赖具体类。我们等式
		 * 右边也应该依赖于抽象
		*/
		splitter->split();
	}
};
