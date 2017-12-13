#include<iostream>
using namespace std;

#define MAX_PEOC_ID 65536
#define TIME_SLICE 2

//进程控制块
typedef struct PCB {
	char name[10];//进程ID
	char state;//进程状态 W/R
	int ArriveTime;//进程到达时间
	int StratTime;//进程开始时间
	int FinishTime;//进程结束时间
	int ServiceTime;//进程服务时间
	float WholeTime;//进程周转时间
	float Weight_WholeTime;//带权周转时间
	double Average_WholeTime;//平均周转时间
	double Average_Weight_WholeTime;//平均带权周转时间

	int RunTime;//已经占用CPU时间
	int NeedTime;//还要用CPU时间

	int Prio;//优先级

	struct PCB *next;

}pcb;
double Sum_WholeTime = 0,Sum_Weight_WholeTime = 0;
int time = 0;
int Proc_Num = 0;
pcb *head = NULL;
pcb *tail = NULL;

void PrioCreateProccess() {
	cout<<"请输入进程的个数："；
	cin>>Proc_Num;
	if (Proc_Num > MAX_PEOC_ID) {		
		cout<<"sorry I cant give u PCB!!";
		return;
	}
	for (int i = 0; i < Proc_Num; ++i){
		pcb *new_proc = NULL；
		if ((new_proc=(pcb*)malloc(sizeof(pcb))) == NULL) {
			perror("malloc");
			return;
		}
		cout<<"请输入第"<<i<<"个进程名:";
		cin>>new_proc->name;
		cout<<"请输入第"<<i<<"个进程到达时间:";
		cin>>new_proc->ArriveTime;
		cout<<"请输入第"<<i<<"个进程服务时间:";
		cin>>new_proc->ServiceTime;
		cout<<"请输入第"<<i<<"个进程优先级:（值越小优先级越高）";
		cin>>new_proc->Prio;
		new_proc->next;
		if(head == NULL) {
			new_proc-> = head;
			head = new_proc;
			tail = head;
			time = new_proc->ArriveTime;
		}else {
			if (head->Prio > new_proc->Prio) {
				new_proc->next = head;
				head = new_proc;
			}else {
				pcb *cur_proc = head;
				while(cur_proc->next != NULL && cur_proc->next->Prio < new_proc->Prio) {
					cur_proc = cur_proc->next;
				}
				if (cur_proc->next == NULL) {
					tail = new_proc;
				}
				new_proc->next = cur_proc->next;
				cur_proc->next = new_proc;
				
			}
			if (new_proc->ArriveTime <time) {
				time = new_proc->ArriveTime;
			}
		}
		new_proc->StratTime = 0;
		new_proc->FinishTime = 0;
		new_proc->WholeTime = 0;
		new_proc->Weight_WholeTime = 0;
		new_proc->Average_WholeTimew = 0;
		new_proc->Average_Weight_WholeTime = 0;
		new_proc->state = 'W';
		new_proc->RunTime = 0;
		new_proc->NeedTime = 0;
	}
}
void FCFS() {
	pcb *cur_proc = head;
	pcb *new_proc =NULL;
	while(cur_proc) {
		if (cur_proc->state == 'W') {
			new_proc = cur_proc;
			RunProccess(new_proc);
		}
		cur_proc = cur_proc->next;
		head = cur_proc;
		free (new_proc);
		new_proc = NULL;
	}
}
void RunProccess() {
	proc->StartTime=time;  
    cout<<"时刻 "<<time<<" 开始执行时间  "<<proc->name<<endl;  
    time+=proc->ServiceTime;  
    proc->state='R';  
    proc->FinshTime=time;  
    proc->WholeTime=proc->FinshTime-proc->ArriveTime;  
    proc->Weight_WholeTime=proc->WholeTime/proc->ServiceTime;  
      
    Sum_WholeTime+=proc->WholeTime;  
    Sum_Weight_WholeTime+=proc->Weight_WholeTime;  
  
    proc->Average_WholeTime=Sum_WholeTime/Proc_Num;  
    proc->Average_Weight_WholeTime=Sum_Weight_WholeTime/Proc_Num;  
    printf("  到达时间  开始时间  服务时间  完成时间  周转时间  带权周转时间\n");  
    printf("%6d    %6d    %6d    %6d    %8.1f    %8.2f\n",  
        proc->ArriveTime,proc->StartTime,proc->ServiceTime,  
        proc->FinshTime,proc->WholeTime,proc->Weight_WholeTime);  
      
    //printf("¹² %d ¸ö½ø³Ì\n",Proc_Num);  
    printf("  平均周转时间  平均带权周转时间  \n");  
    printf("  %10.2f        %10.2f\n",proc->Average_WholeTime,  
        							  proc->Average_Weight_WholeTime);  
}
int main(int argc, char const *argv[])
{
	while(true) {
		PrioCreateProccess();
		FCFS();
	}
	return 0;
}
