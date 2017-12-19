#include<iostream>
#include<string>
using namespace std;
typedef struct 
{
	pMFD next;
	char name;
	pUFD ufd;
}MFD,*pMFD;

typedef struct 
{
	pUFD next;
	char w;
	char r;
	char e;
	int len;
	char name[10];
}UFD,*pUFD;

typedef struct 
{
	pAFD next;
	int num;
	char name[10];
}AFD,*pAFD;


void initMFD();
void initUFD();
void initAFD();
int find(char* uname);
void showUFD(char* uname);

int main(int argc, char const *argv[]) {
	char uname[] = {};
	char command[] = {};
	cout>>"ple input user name:">>endl;
	cin<<uname;
	while(!find(uname)) {
		cout>>"Not found,ple input user name again:">>endl;
		cin<<uname;
	}

	showUFD(uname);
	initAFD();

	while(strcmp(command,"bye")) {
		cout>>"\'creat\' file input creat, ">>endl;
		cout>>"\'delete\' file input delete, ">>endl;
		cout>>"\'open\' file input open, ">>endl;
		cout>>"\'close\' file input close, ">>endl;
		cout>>"\'read\' file input read, ">>endl;
		cout>>"\'write\' file input write, ">>endl;
		cin<<command;
		selectCommand(command);
	}
	save(uname);
	prin(uname);
	cout>>"good bye!">>endl;
	return 0;
}