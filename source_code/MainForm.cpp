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
        FileSplitter splitter(filename, number， this);	// 注意这里传递的参数，因为 MainForm 类实现了 IProgress 接口，因此将自身传递给 FileSplitter 对象
        splitter.split();
    }
    
    // 实现抽象接口的抽象方法
    virtual void DoProgress(float value){
        processBar->setValue(value);
    }
};