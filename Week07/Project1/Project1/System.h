#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CFolder : public CItem {
private:
	string name, type;
	int size, nfiles, nfolders;
	vector< CItem* > list;
public:
	CFolder();
	CFolder(const string &x);
	void add(CFile* x);
	void add(CFolder* x);
	void print(const int &num);
	string getType();
	string getName();
	int getSize();
	CItem* removeByName(const string &a);
	CItem* findByName(const string &b);
	void setHidden(bool a, bool b);
};

class CFile : public CItem {
public:
	CFile();
	CFile(const string &x, const int &s);
	int getSize();
	string getType();
	string getName();
	void print(const int &num);
	void setHidden(bool a, bool b);

};

class CItem {
protected:
	string name, type;
	int size;
	bool checkHidden;
public:
	virtual int getSize() = 0;
	virtual string getType() = 0;
	virtual string getName() = 0;
	virtual void print(const int &num) = 0;
	virtual void setHidden(bool a, bool b) = 0;
};
#endif

