// 业务操作
class Stream{
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};
/**
 * 对于不同的流，具有不同的实现的方式
*/
//主体类
class FileStream : public Stream{
public:
    virtual char Read(int number){
        // 读文件
    }

    virtual void Seek(int position){
        //定位文件流
    }

    virtual void Write(char data){
        // 写文件
    }
};

class NetworkStream : public Stream{
public:
    virtual char Read(int number){
        // 读网络流
    }

    virtual void Seek(int position){
        //定位网络流
    }

    virtual void Write(char data){
        // 写网络流
    }
};

class MemoryStream : public Stream{
public:
    virtual char Read(int number){
        // 读内存流
    }

    virtual void Seek(int position){
        //定位内存流
    }

    virtual void Write(char data){
        // 写内存流
    }
};

/**
 * 我们对于每一种流，可能有加密的需求
 * 我们需要对文件流进行加密，对网络流进行加密，对内存流进行加密
*/
//扩展操作
class CryptoFileStream : public FileStream{
public:
    virtual char Read(int number){
        //额外的加密操作
        FileStream::Read(number);
        //额外的加密操作
    }
    virtual void Seek(int position){
        //额外的加密操作
        FileStream::Seek(position);
        //额外的加密操作
    }
    virtual void Write(char data){
        //额外的加密操作
        FileStream::Write(data);
        //额外的加密操作
    }
};

class CryptoNetworkStream : public NetworkStream{
public:
    virtual char Read(int number){
        //额外的加密操作
        NetworkStream::Read(number);
        //额外的加密操作
    }
    virtual void Seek(int position){
        //额外的加密操作
        NetworkStream::Seek(position);
        //额外的加密操作
    }
    virtual void Write(char data){
        //额外的加密操作
        NetworkStream::Write(data);
        //额外的加密操作
    }
};

class CryptoMemoryStream : public MemoryStream{
public:
    virtual char Read(int number){
        //额外的加密操作
        MemoryStream::Read(number);
        //额外的加密操作
    }

    virtual void Seek(int position){
        //额外的加密操作
        MemoryStream::Seek(position);
        //额外的加密操作
    }
    virtual void Write(char data){
        //额外的加密操作
        MemoryStream::Write(data);
        //额外的加密操作
    }
};

/**
 * 如果我们还有对于流的缓冲操作的需求的话
*/

class BufferedFileStream : public FileStream{
    // .....
};

class BufferedNetworkStream : public FileStream{
    //.....
};

class BufferedMemoryStream : public MemoryStream{
    // ....
};

/***
 * 如果我们即需要进行缓冲又需要进行加密的话
*/

class CryptoBufferedFileStream : FileStream{
public:
    virtual char Read(int number){
        //额外的加密的操作
        //额外的缓冲的操作
        FileStream::Read(number);
        //.....
    }
    virtual void Seek(int position){
        // ....
    }
    virtual void Write(char data){
        // ....
    }
};


void process(){
    // 编译时装配
    CryptoFileStream *fs1 = new CryptoFileStream();
    BufferedFileStream * fs2 = new BufferedFileStream();
    CryptoBufferedFileStream * fs3 = new CryptoBufferedFileStream();
}