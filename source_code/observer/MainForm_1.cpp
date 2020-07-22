// MainForm.cpp
class MainForm : public Form,public IProgress	// 继承这个通知抽象接口
{
	TextBox*	textFilePath;
    TextBox* 	textFileNumber;
	// 变动
    ProgressBar* processBar;	// 它就是一个观察者
public:
    void Button1_click()
    {
       	filename = //*******
        number = //********
        ConsoleNotifier cn;
        FileSplitter splitter(filename, number);

        splitter.add_IProgress(this);
        splitter.add_IProgress(&cn);

        splitter.split();

        splitter.remove_IProgress(this);
    }
    
    // 实现抽象接口的抽象方法
    virtual void DoProgress(float value){
        processBar->setValue(value);
    }
};


class ConsoleNotifier : public IProgress{
public:
    virtual void DoProgress(float value){
        cout << ".";
    }
};