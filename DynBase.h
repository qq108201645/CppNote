#ifndef _DYN_BASE_H_
#define _DYN_BASE_H_

#include <map>
#include <string>
using namespace std;



typedef void* (*CREATE_FUNC)();//1��������
 class DynObjectFactory
 {
 public:
	 static void* CreateObject(const string& name)//�ӿ�
	 {
		 map<string,CREATE_FUNC>::const_iterator it;
		 it=mapCls_.find(name);//����name
		 if (it==mapCls_.end())
			 return 0;
		 else
			 return it->second();
	 }
	 static void Register(const string& name,CREATE_FUNC func)//5ע�᷽��
	 {
		mapCls_[name]=func;
	 }
 private:
	 static map<string,CREATE_FUNC> mapCls_;//2�����ַ���/��̬���������Ϣ
 };
 _declspec(selectany) map<string,CREATE_FUNC> DynObjectFactory::mapCls_;

 class Register//6����DynObjectFactory::Register
 {
 public:
	 Register(const string& name,CREATE_FUNC func)
	 {
		 DynObjectFactory::Register(name,func);
	 }
 };
//4����class��/��ע�ᵽmap��string

#define  REGISTER_CLASS(class_name) \
 class class_name##Register { \
 public:\
	static void* NewInstance() \
	{\
		return new class_name;\
	}\
 private:\
	static Register reg_;\
 };\
 Register class_name##Register::reg_(#class_name,class_name##Register::NewInstance)

#endif