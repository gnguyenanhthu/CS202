#include "System.h"

CFile::CFile(){
}

void CFile::print(const int& num) {
}

CFile::CFile(const string& x, const int& s) {
	this->name = x;
	this->size = s;
	this->type = "File";
}

int CFile::getSize() {
	return this->size;
}

string CFile::getType() {
	return this->type;
}

string CFile::getName() {
	return this->name;
}

void CFile::setHidden(bool a, bool b) {
	this->checkHidden = a;
}

CFolder::CFolder(){
}

string CFolder::getName() {
	return this->name;
}

string CFolder::getType() {
	return this->type;
}

int CFolder::getSize() {
	return this->size;
}

CFolder::CFolder(const string& x) {
	this->name = x;
	this->type = "Folder";
	this->size = 0;
}

void CFolder::add(CFile* x) {
	this->size += x->getSize();
	list.push_back(x);
	nfiles++;
}

void CFolder::add(CFolder* x) {
	this->size += x->getSize();
	list.push_back(x);
	nfolders++;
}

void CFolder::print(const int& num) {
	if (num == 0) {
		cout << "Subfolders: ";
		for (int i = 0; i != list.size(); i++) {
			if (list[i]->getType() == "Folder") {
				cout << i + 1 << "/" << list[i]->getName() << endl;
			}
		}
		return;
	}
	if (num == 1) {
		cout << "Files: ";
		for (int i = 0; i != list.size() - 1; i++) {
			if (list[i]->getType() == "File") {
				cout << list[i]->getName() << endl;
			}
		}
	}
	cout << "Nothing to print out";
}


CItem* CFolder::removeByName(const string &a) {
	vector<CItem*>::iterator it;
	for (it = list.begin(); it != list.end(); ++it) {
		if ((*it)->getName() == a) {
			list.erase(it);
			return this;
		}
	}
	return NULL;
}

CItem* CFolder::findByName(const string &b) {
	vector<CItem*>::iterator it;
	for (it = list.begin(); it != list.end(); ++it) {
		if ((*it)->getName() == b) {
			cout << "We found your file!";
			return (*it);
		}
		else cout << "File could not found...";
	}
	return NULL;
}

void CFolder::setHidden(bool a, bool b) {
	if (a == true) {
		checkHidden = true;
		vector<CItem*>::iterator i;
		for (i = list.begin(); i != list.end(); ++i) {
			(*i)->setHidden(true, true);
		}
	}
	else {
		checkHidden = false;
		vector<CItem*>::iterator i;
		for (i = list.begin(); i != list.end(); ++i) {
			(*i)->setHidden(false, false);
		}
	}
}