class Form{/*已经实现*/};
class TextBox{/*已经实现*/};
class ProgressBar{/*已经实现*/};

#include "./FactorySplitter.cpp"

class MainForm : public Form{
	TextBox*		textFilePath;
	TextBox*		textFileNumber;
	ProgressBar*	progressBar;

	ISplitter* prototype;	// 原型对象
public:

	MainForm(ISplitter* prototype){
		this->prototype = prototype;
	}

	void Button1_Click(){
		//string filePath = textFilePath->getText();
		//int number = atoi(textFileNumber->getText().c_str());
		
		
		ISplitter* splitter = prototype->clone();	//  克隆原型
		splitter->split();
	}
};
