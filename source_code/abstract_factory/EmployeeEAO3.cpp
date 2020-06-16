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

class IDBCommand{

};

class IDataReader{

};

/**
 * 三个工厂合并为一个
*/
class IDBFactory{
public:
	virtual IDBConnection*	CreateDBConnection() = 0;
	virtual IDBCommand*		CreateDBCommand() = 0;
	virtual IDataReader*	CreateDataReader() = 0;	
};


// 支持SQL Server
class SqlConnection : public IDBConnection{

};

class SqlCommand : public IDBCommand{

};

class SqlDataReader : public IDataReader{

};

// SQL Server 的工厂
class SqlDBFactory : public IDBFactory{
// 实现三个抽象方法
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
	IDBFactory* 	dbFactory;	

public:
	vector<EmployeeDO> getEmployees(){
		/**
		 * 我们现在可能使用 SQL Server
		 * 但是以后的需求可能会要求使用 DB2，MYSQL，等等其他的数据库。
		 * 那么应该如何满足这些需求
		*/
		IDBConnection* connection = 
			dbFactory->CreateDBCommned();
		connection->ConnectionString("...");
		
		IDBCommand* command = 
			dbFactory->CreateDBCommned();
		command->CommandText("....");

		command->SetConnection(connection);	// 命令和连接相关联  // 关联性

		IDataReader* reader = dbFactory->CreateDataReader();	// 关联性
		while(reader->Read())
		{
			// ....
		}
	}
};