class Form{/*已经实现*/};
class TextBox{/*已经实现*/};
class ProgressBar{/*已经实现*/};

class MainForm : public Form{
	TextBox*		textFilePath;
	TextBox*		textFileNumber;
	ProgressBar*	progressBar;

public:
	void Button1_Click(){
		string filePath = textFilePath->getText();
		int number = atoi(textFileNumber->getText().c_str());

		FileSplitter* splitter = new FileSplitter(filePath, number);

		splitter->split();
	}
};
