#include<iostream>
#include<string>
using namespace std;


// 一个简单的类创建
//class Student {
//private:
//	string name;
//	int age;
//public:
//
//	void setStu(string name1, int age1) {    // 直接在class内部声明函数并创建函数
//		name = name1;
//		age = age1;
//		show();  // 类的函数里可以调用类的其他函数 当然也可以递归 调用自己 类里面的参数也能一直用
//	}
//
//	void show();   // 在class里面声明函数 在外面创建 但是前提是这个函数必须在public里面 才能被外部访问到
//
//
//
//	// 构造函数（构造函数必须这么写 没有返回值也不写void 函数名必须是类名 但是是可以有参数的 访问权限必须公有）
//	// 一个class里面如果有多个构造函数 就看主函数是怎么调用的 
//	// 构造函数的作用是 在创建class对象的时候能顺便实现初始化
//	// 构造函数只能在创建对象的时候调用一次 不能再次调用 不然就戳了
//	Student() {
//		name.clear(); age = 18;
//		name = "李盈";
//	}
//	Student(string m_name) {
//		name.clear(); age = 18;
//		name = m_name;
//	}
//	Student(string m_name, int m_age) {
//		name.clear();
//		name = m_name;
//		age = m_age;
//	}
//	//Student(string m_name = "蔡坤") {   // 这个可以给默认初始值 不过的话 这个就相当于没有形参了 就和第一个没什么区别 
//	//	name.clear(); age = 28;
//	//	name = m_name;
//	//}
//
//
//
//	// 析构函数（析构函数也是必须以类名作为函数名 不返回类型也不写void 没有参数 不能重载 可以多次调用 访问权限必须公有）
//  //  一般析构函数的用途是释放内存 
//	~Student() {
//		cout << "调用了析构函数" << endl;
//	}
//
//};
//
//inline void Student::show() {   // 在class外部创建函数 注意这个写法  如果前面写了inline就是可以看做这个函数就在class里面 叫内联函数
//	cout << name << ' ' << age << endl;
//}
//
//int main() {
//
//	Student stu;   // 这个既是创建对象 也是调用构造函数 可以调用第一个和第四个 但是两个都有的话就会报错
//	/*Student stu("韩思瑜"); */  // 这个也是
//	/*Student stu("李盈和韩思瑜", 18);*/  // 这个也是
//
//
//	/*stu.setStu("蔡徐坤", 28);*/ 
//	stu.show();
//	
//	stu.~Student();
//	
//	return 0;
//}




// 构造函数的一些细节
//class friends {
//private:
//	int money;
//	int age;
//	string name;
//public:
//	friends(const int& m_money,const int& m_age,const string& m_name):money(m_money),age(m_age),name(m_name) {
//		// 这是直接构造的时候就初始化 不在函数里面初始化 这样更高效
//		cout << "调用了friends" << endl;
//		show();
//	}
//	void show() {
//		cout << money << " " << age << ' ' << name << endl;
//	}
//};
//
//int main() {
//	friends f1(1000, 18, "zhangsan");
//	return 0;
//}

