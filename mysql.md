# ubuntu下 mysql 配置教程

#### 一、安装

* `sudo apt install mysql-server`
* `sudo apt install mysql-client`



#### 二、基本命令

* 安装完可使用以下三条命令
* `sudo service mysql status ` ：查看状态
* `sudo service mysql restart`：重启
* `sudo service mysql stop`：停止



#### 三、使用mysql

* 首先使用root用户登陆mysql： `sudo mysql -u root`，输入密码便可进入mysql
* 支持中文设置， 执行以下命令：
  * `SHOW VARIABLES LIKE ‘%char%’;`
  * `SHOW VARIABLES LIKE ‘%colla%’;`
  * `注：mysql以“；”为语句结束标志符。使用exit可退出mysql`
  * 修改/etc/mysql/mysql.cnf，在最后增加：
  * `[client]
     default-character-set = utf8
     [mysqld]
     character-set-server = utf8
     collation-server = utf8_general_ci
     bind-address = 0.0.0.0`
  * 重启mysql服务（基本命令2）
  * 查看监听地址：`netstat -tap | grep mysql`
* 创建普通用户（非root）
  * 依然在root用户的mysql下操作
  * 创建用户：`CREATE USER 'username'@'%' IDENTIFIED BY 'passwd';`
  * 刷新权限：`flush privileges;`
  * 给用户授权：`grant all on *.* to 'username'@'%'` （这是所有权限，也可以指定部分权限分配）
  * 再次刷新权限：`flush privileges;`
* 使用普通用户
  * 创建database `CREATE DATABASE YoyDataBaseName`



#### 四、在qt上使用mysql

* 首先在.pro上添加 `QT+=sql`

* 打开数据库：

  ```c++
  QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName("0.0.0.0");				// ip 地址
  db.setUserName("robotmaster");	// mysql的用户
  db.setPassword("123456");				// mysql的密码
  db.setDatabaseName("users");		// mysql的用户的databasse
  if(!db.open())
  {
          qDebug()<<"Database connected failed!";
          return;
  }
  ```

* 编译libsqlmysql.so (若Qt5.9.2/5.9.2/gcc_64/plugins/sqldrivers没有该文件，需要自行编译并cp过去)

  * 进入qt安装目录中的mysql，例如: /opt/Qt5.0.0/5.0.0/Src/qtbase/src/plugins/sqldrivers/mysql

  * 在mysql.pro文件添加以下代码 。注：可通过命令`whereis mysql.h`和`whereis libmysqlclient` 查看对应路径

  * ```properties
    INCLUDEPATH+=/usr/include/mysql
    LIBS+=-L/usr/lib/x86_64-linux-gnu -lmysqlclient
    ```

  * 注释文件/opt/Qt5.0.0/5.0.0/qtbase/src/plugins/sqldrivers/qsqldriverbase.pri中的include那行。

  * ```properties
    # include($$shadowed($$PWD)/qtsqldrivers-config.pri)
    若没有则忽略
    ```

  * 在mysql文件夹下，使用sudo qmake 。 若无错误执行sudo make

  * 若编译成功，.so文件将在/opt/Qt5.0.0/5.0.0/gcc_64/plugins/sqldrivers目录下



#### 五、qt安装

* 在该网站选取对应的版本下载`https://download.qt.io/archive/qt/`

* 下载完使用` ./xxx.run`或`双击打开`运行

* 安装时勾选`Source Components` (点击Qt 5.x.x 即可看到)

* 一路Next安装完毕

* 在`/usr/lib/`目录下创建qtcreator文件，增加以下代码

* ```
  #! /bin/sh
  export QT_HOME=/opt/Qt5.x.x/Tools/QtCreator/bin
  $QT_HOME/qtcreator $*
  
  #QT_HOME为自己的Qt安装目录
  ```

* 使用命令`qtcreate`即可打开qt
