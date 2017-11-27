// TestLib.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
//#include "BusinessTree.h"
//#include "KeyValueDataString.h"
//#include "TAttributeString.h"
#include <time.h>
//#include "MyString.h"
#include <strstream>

#include "Json\json.h"
//using namespace MyStd;
#include "BusinessService.h"
#include "BusinessTree.h"
#include "BParam_Login_Post.h"
#include "BParam_Login_Recv.h"
using namespace std;

//class CDerivedRef : public CMyReference<CTBaseNode>
//{

//};


void Format()
{
	char buf[256] = {0,};
	sprintf(buf, "%d", 100);

	printf(buf);
}

struct tagSA
{
	char year : 7;
	char month : 4;
	char day : 5;
	int m : 8;
};
int main()
{
	
//	CBusinessTreeRef pTree = CBusinessTree::GetInstance();
/*
	pTree->AddNode("Root/user/user1");
	pTree->AddNode("Root/user/user2");

	pTree->SetAttributeString("Root/user/user1", "username", "yulin");
	pTree->SetAttributeString("Root/user/user2", "username", "yulin");
	pTree->SetAttributeString("Root/user/user2", "password", "yu123");
	pTree->SetAttributeInt("Root/user/user2", "age", 36);


	std::string strChildNodeName;
	pTree->GetChildNodeName("Root", 0, strChildNodeName);
	std::cout << "Root->0 = " << strChildNodeName << std::endl;
	pTree->GetChildNodeName("Root/user", 0,strChildNodeName);
	std::cout << "Root/user->0 = " << strChildNodeName  << std::endl;
	pTree->GetChildNodeName("Root/user", 1,strChildNodeName);
	std::cout << "Root/user->1 = " << strChildNodeName << std::endl;


	std::string strAttributeValue;
	pTree->GetAttributeValueString("Root/user/user1", "username", strAttributeValue);
	std::cout << "Root/user/user1->username = " << strAttributeValue << std::endl;
	pTree->GetAttributeValueString("Root/user/user2", "username", strAttributeValue);
	std::cout << "Root/user/user2->username = " << strAttributeValue << std::endl;
	pTree->GetAttributeValueString("Root/user/user2", "password", strAttributeValue);
	std::cout << "Root/user/user2->password = " << strAttributeValue << std::endl;
	int iAttributeValue = 0;
	pTree->GetAttributeValueInt("Root/user/user2", "age", iAttributeValue);
	std::cout << "Root/user/user2->age = " << iAttributeValue << std::endl;

	std::cout << "Root/user/user2->attr count = " << pTree->GetAttributeCount("Root/user/user2") << std::endl;
	std::cout << "delete Root/user/user2->attr password" << std::endl;
	pTree->RemoveAttribute("Root/user/user2", "password");
	std::cout << "Root/user/user2->attr count = " << pTree->GetAttributeCount("Root/user/user2") << std::endl;


	pTree->GetAttributeValueString("Root/user/user1", "username", strAttributeValue);
	std::cout << "Root/user/user1->username = " << strAttributeValue << std::endl;
	pTree->GetAttributeValueString("Root/user/user2", "username", strAttributeValue);
	std::cout << "Root/user/user2->username = " << strAttributeValue << std::endl;

	//int iAttributeValue;
	pTree->GetAttributeValueInt("Root/user/user2", "age",iAttributeValue);
	std::cout << "Root/user/user2->age = " << iAttributeValue << std::endl;
	//std::cout << "Root/user/user2->username = " << tree.GetAttributeValueString("Root/user/user2", "password") << std::endl;

	std::cout << "delete Root/user/user2" << std::endl;
	pTree->RemoveNode("Root/user/user2");
	std::cout << "Root/user-> node count = " << pTree->GetChildNodeCount("Root/user") << std::endl;

	//time_t rawtime;

	//time(&rawtime);

	//tm* timeinfo = localtime(&rawtime);
	*/
	//CMyString str;
	//str.Format("123%d",4);
	//std::cout << "str = " << (string)str << std::endl;
	//string str = to_string(10);
	
//	int i = 0;
//	i++;

//	Json::Value value;
	
//	value["user"]["username"] = "yl";
//	value["user"]["password"] = "123";

//	Json::FastWriter writer;
//	string strJson = writer.write(value);

//	CBParam_Login_Post post;
//	CBParam_Login_Recv recv;
//	CBusinessService::GetInstance()->Login(post, recv);

	//map<string,>

	//const char* pData = new char[100];

	//pData = nullptr;

	//pData[1] = 0;

	cout << sizeof(tagSA) << endl;

    return 0;
}