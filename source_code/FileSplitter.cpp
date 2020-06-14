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
IProgress* m_iprogress;	// 抽象的接口
/**
 * 上面的这一行是整个设计过程中的关键
*/

public:
    FileSplitter(string filepath, int filenumber, Iprogress iprogress)
        : m_filePath(filepath),
    	m_filenumber(filenumber),
    	// 变化
    	m_iprogress(iprogress)
        {}

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
        if (m_iprogress != nullptr){
            m_iprogress->DoProgress(value); // 更新进度条
        }
    }
};