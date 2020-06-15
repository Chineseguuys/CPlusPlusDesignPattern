#include <vector>
using namespace std;

class EmployeeDO{/*已经定义*/};
class SqlConnecton{/*已经定义*/};

class EmployeeEAO{
public:
    vector<EmployeeDO> getEmployees(){
        /**
         * 我们现在可能使用 SQL Server
         * 但是以后的需求可能会要求使用 DB2，MYSQL，等等其他的数据库。
         * 那么应该如何满足这些需求
        */
        SqlConnecton* connection = 
            new SqlConnecton();
        connection->ConnectionString = "...";
        
        SqlCommand* command = 
            new SqlCommand();
        command->CommandText = "....";

        SqlDataReader* reader = command->ExecuteReader();
        while(reader->Read())
        {
            // ....
        }
    }
};