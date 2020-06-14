// FileSplitter.cpp

// 抽象的基类
class IProgress
{
public:
    virtual void DoProgress(float ) = 0;
    virtual ~IProgress();
};

class FileSplitter
{
    string m_filePath;
    int m_filenumber;
    // 变化
    //ProgressBar* m_progressBar;	// 具体通知控件
    vector<IProgress*> m_iprogressVector;	// 抽象的接口,支持多个观察者
    /**
    * 上面的这一行是整个设计过程中的关键
    */

public:
    FileSplitter(string filepath, int filenumber)
        : m_filePath(filepath),
    	m_filenumber(filenumber)
        {}

    void add_IProgress(IProgress* iprogress){
        m_iprogressVector.push_back(iprogress);
    }

    void remove_IProgress(IProgress* iprogress){
        m_iprogressVector.remove(iprogress);
    }

    void split()
    {
        // 1. 读取大文件
        // 2. 分批次向小文件中进行写入
        for (int i =  0; i< m_filenumber; ++i)
        {
            //***********
            
            //变化
            float progressValue = m_filenumber;
            progressValue = (i + 1) / progressValue;
            onProgress(progressValue);
        }
    }

protected:
    void onProgress(float value){
        vector<IProgress*>::iterator iter = m_iprogressVector.begin();

        while(iter != m_iprogressVector.end()){
            (*iter)->DoProgress(value); //更新进度条
            ++iter;
        }
    }
};