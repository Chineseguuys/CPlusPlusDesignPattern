class Form{/*已经实现*/};
class TextBox{/*已经实现*/};
class ProgressBar{/*已经实现*/};

#include "./FactorySplitter.cpp"

class MainForm : public Form{
	TextBox*		textFilePath;
	TextBox*		textFileNumber;
	ProgressBar*	progressBar;

	SplitterFactory* factory;	// 工厂
public:

	MainForm(SplitterFactory* factory){
		this->factory = factory;
	}

	void Button1_Click(){
		string filePath = textFilePath->getText();
		int number = atoi(textFileNumber->getText().c_str());
		
		
		ISplitter* splitter = factory->CreateSplitter();	// 面向接口 多态的 new
		splitter->split();
	}
};
