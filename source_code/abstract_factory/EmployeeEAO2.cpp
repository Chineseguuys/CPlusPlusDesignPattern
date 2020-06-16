#include <vector>
using namespace std;

class EmployeeDO{/*已经定义*/};
class SqlConnecton{/*已经定义*/};

/**
 * 一系列的抽象的接口
 * 数据库访问的基类
*/
class IDBConnection{

};

// 关于这个抽象基类的一个工厂
class IDBConnectionFactory{
public:
	virtual IDBConnection* CreateDBConnection() = 0;
};

class IDBCommand{

};

class IDBCommandFactory{
public:
	virtual IDBCommand* CreateDBCommned() = 0;
};

class IDataReader{

};

class IDataReaderFactory{
public:
	virtual IDataReader* CreateDataReader() = 0;
};

// 支持SQL Server
class SqlConnection : public IDBConnection{

};

// 具体类的工厂
class SqlConnectionFactory : public IDBCommandFactory{
// 实现抽象方法
};

class SqlCommand : public IDBCommand{

};

// 具体类的工厂
class SqlCommandFactory : public IDBCommandFactory{
// 实现抽象方法
};

class SqlDataReader : public IDataReader{

};

class SqlDataReader : public IDataReaderFactory{
// 实现抽象方法
};


// 也要支持 Oracle
/**
 * Oracle 同样也要实现这些方法
*/
class OracleConnection : public IDBConnection{

};

class OracleCommand : public IDBCommand{

};

class OracleDataReader : public IDataReader{

};

// 甚至更多的数据库类型

class EmployeeEAO{
	/**
	 * 依赖并没有消失，而是被放到了更加上层的代码当中，用传参的方式传入到这里
	 * 当前的类本身不依赖任何的具体类，只依赖于抽象
	 * 具体类型的绑定被延时到运行期间，通过虚函数来实现
	*/
	IDBConnectionFactory*		dbConnectionFactory;
	IDBCommandFactory*			dbCommandFactory;
	IDataReaderFactory*			dataReaderFactory;		
	/**
	 * 这里有非常明显的依赖关系，例如，Oracle 的连接器，一定要搭配 Oracle 的命令。
	 * 所以上面的三个工厂，一个确定下来那么其他的两个也就确定下来，你不可能 ConnectionFactory 
	 * 传入 Oracle 的，CommandFactory 传入 MySQL 的，那代码的执行过程一定会出错
	*/
public:
	vector<EmployeeDO> getEmployees(){
		/**
		 * 我们现在可能使用 SQL Server
		 * 但是以后的需求可能会要求使用 DB2，MYSQL，等等其他的数据库。
		 * 那么应该如何满足这些需求
		*/
		IDBConnection* connection = 
			dbCommandFactory->CreateDBCommned();
		connection->ConnectionString("...");
		
		IDBCommand* command = 
			dbCommandFactory->CreateDBCommned();
		command->CommandText("....");

		command->SetConnection(connection);	// 命令和连接相关联  // 关联性

		IDataReader* reader = dataReaderFactory->CreateDataReader();	// 关联性
		while(reader->Read())
		{
			// ....
		}
	}
};