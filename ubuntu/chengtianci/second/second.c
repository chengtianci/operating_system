#include<stdio.h>
#define M 4 //进程数目P1 P2 P3 ...
#define N 3 //资源数目A,B,C..
#define Stacksize M*N*M //堆栈的大小此处数组的第一个数时堆栈指针，指向当前位置。

void Matrix_Initialization(int array[][N]);
void Matrix_Subtraction(int array1[][N],int array2[][N],int array3[][N]);
int Vector_compare(int* array1,int array2,int n);
int Search_process(int need[][N],int* available,int* flag,int* stack);
int pop(int *stack);
void push(int* stack,int i);
int Check_safe(int need[][N],int* available,int* stack,int* secquence);
void Vector_subtration(int* array1,int*array2,int n);
void Vector_add(int* array1,int array2,int n);
int main() {
	int Max[M][N] = {3,2,2,6,1,3,3,1,4,4,2,2};
	int Allocation[M][N] = {1,0,0,5,1,1,2,1,1,0,0,2};
	int Need[M][N] = {0};
	int Available[N] = {1,1,2};
	int Secquence[M] = {-1,-1,-1,-1};
	int Stack[Stacksize] = {-1};
	Stack[0] = 0;
	/*
	printf("please initialize the max_Maxtri\n");
	Matrix_Initialization(Max);
	printf("please initialize the allocation_Matrix\n");
	Matrix_Initialization(Allocation);
	printf("please initialize the available_Matrix\n");
	for (int i = 0; i < N; ++i) {
  		scanf("%d",&Available[i]);
	}

	*/
	Matrix_Subtraction(Need,Max,Allocation);
	printf("\nMax矩阵\n");
	for (int i = 0; i < M; ++i) {
		printf("\n");
		for(int j = 0;j < N; ++j) {
			printf("%d\n",&Max[i][j] );
		}
	}
	printf("\nAllocation矩阵\n");
	for (int i = 0; i < M; ++i) {
		printf("\n");
		for(int j = 0;j < N; ++j) {
			printf("%d\n",&Allocation[i][j] );
		}
	}
	printf("\nNeed矩阵\n");
	for (int i = 0; i < M; ++i) {
		printf("\n");
		for(int j = 0;j < N; ++j) {
			printf("%d\n",&Need[i][j] );
		}
	}
	if (Check_safe(Need,Available,Stack,Secquence)==0) {
		printf("\nIt's not safe!\n");

	}else {
		printf("\nsafe secquence could be :\n");
		for (int i = 0; i < M; ++i) {
			printf("P%d\n",&Secquence[i] );
		}
	}
	return 0;
}
/* 矩阵相减 array1=array2-array3 M行 N列*/
void Matrix_Subtraction(int array1[][N],int array2[][N],int array3[][N]) {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			array1[i][j] = array2[i][j]-array3[i][j];
		}
	}
}
// 向量相加 array1 = array1 + array2
void Vector_add(int* array1,int* array2,int n) {
	for (int i = 0; i < n; ++i) {
		array1[i]+=array2[i];
	}
}
// 向量相减 array1 = array1 - array2
void Vector_add(int* array1,int* array2,int n) {
	for (int i = 0; i < n; ++i) {
		array1[i]-=array2[i];
	}
}
void Matrix_Initialization(int array1[][M]) {
	for (int i = 0; i < M; ++i) {
		printf("please input the P%d's source\n",i );
		for (int j = 0; j < N; ++j) {
			printf("please input the number of P%d source %c's\n",i,j+65 );
			scanf("%d",&array1[i][j]);
		}
	}
}
// 向量比较 array1中每一个都比array2大返回1.否则返回0 n比较的数组的个数
int Vector_compare(int*array1,int array2,int n) {
	for (int i = 0; i < n; ++i) {
		if (array1[i]<array2[i]) {
			return 0;
		}
	}
	return 1;
}
int Search_process(int need[][N],int* available,int* flag,int* stack) {
	int test = 0;
	for (int i = 0; i < M; ++i) {
		if(flag[i]==0) {
			if(Vector_compare(available,need[i],N)==1) {
				test =1;
				push(Stack,i);
			}
		}
	}
	return test;
}
int Check_safe(int need[][N],int* available,int* stack,int* secquence) {
	int temp;
	int sflag = -1;
	int flag[M]={0};
	if (Search_process(need,available,flag,stack)==0) {
		return 0 ;
	}
	while(stack[0]!= 0 && secquence[M-1]=-1) {
		temp = pop(stack);
		flag[temp] = 1;
		secquence[++sflag] = temp;
		if (secquence[M-1]!=-1) {
			return 1;
		}
		Vector_add(available,need[temp]，N)；
		if (Search_process(need,available,flag,stack)==0){
			flag[temp] = 0;
			Vector_subtration(available,need[temp],N);
			secquence[sflag]=-1;
			sflag--;
		}
	}
	if (secquence[M-1]==-1) {
		return 0 ;
	}
	return 1;
}
void push(int* stack,int i) {
	stack[0]++;
	stack[stack[0]]=i;
}
int  pop(int* stack,int i) {
	int temp = stack[stack[0]];
	stack[0]--;
	return temp;
}