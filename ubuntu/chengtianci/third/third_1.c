//动态内存分配   
#include<stdio.h>  
int temp=0;//定义一个全局变量！这个变量起很大作用  
typedef struct _BiTNode//定义 表 的结构体   
 {  
    int address;//首地址   
    int length;//空闲区长度   
    bool state;//区域状态 “1”表示已分配， “0”表示未分配   
    int homework; //作业名   
    struct _BiTNode *lchild;//指向左孩子的指针   
    struct _BiTNode *rchild;//右孩子   
}BiTNode,*pBiTree;  
void Init_BiTree(pBiTree l)   {         
    l->address = 5;  
    l->length = 507;  
    l->state = 0;      
    l->homework=NULL;  
    l->lchild = NULL;  
    l->rchild = NULL;  
    printf("初始化完成！\n");  
}   
int Print(pBiTree p)   {     
    printf("\n\t\t%d\t%d\t",p->address,p->length);  
    if(p->state==1)  
        printf("Busy  \t");  
    else  
        printf("Free  \t");  
    if(p->homework!=0)  
        printf("%d\n",p->homework);  
    else   
        printf("\n");   
}  
//先序遍历    
void PreOrder(pBiTree p)     {     
    if(p != NULL)    
    {           
        if(!p->lchild&&!p->rchild)        
            Print(p);  //输出该结点  
        PreOrder(p->lchild);  //遍历左子树     
        PreOrder(p->rchild); //遍历右子树    
    }    
}    
void Insert_PreOrder(pBiTree p,int length,int homework)//插入新作业     
{     
    if(p != NULL)    
    {       
        if((p->state==0)&&(length<p->length)&&(!p->lchild)&&(!p->rchild)&&temp==0)//判断节点是否有左右孩子，是否小于空闲区长度，是否状态为0（表示区域无作业运行）   
        {    
            pBiTree  x1 =new BiTNode;//进行插入，动态申请两个空间 x1,x2   
            pBiTree  x2 =new BiTNode;  
            x1->homework=homework;//x1为作业   
            x2->homework=NULL;//x2为剩余的空闲区   
            x1->address=p->address;//把原空闲区的首地址给作业的首地址   
            x1->state=1;//作业的状态改为1   
            x1->length=length;//作业的长度为传入的长度   
            x2->address=x1->address+length;//新空闲区的首地址为 x1首地址与x1长度之和   
            x2->length=p->length-x1->length;  
            p->lchild=x1;  
            p->rchild=x2;  
            x2->state=0;  
            x1->lchild=NULL;  
            x1->rchild=NULL;  
            x2->rchild=NULL;  
            x2->lchild=NULL;   
            temp=1;  
        }         
        else  
        {     
            Insert_PreOrder(p->lchild,length,homework);  //遍历左子树     
            Insert_PreOrder(p->rchild,length,homework); //遍历右子树    
        }   
    }    
}   
void Delect_PreOrder(pBiTree p,int homework) //遍历修改，将状态修改为0。即为空闲区    
 {     
    if(p != NULL)    
    {           
        if(p->homework==homework)//当查询到作业名相同的作业。进行修改   
        {  
            p->homework=NULL;//将作业名修改为空   
            p->state=0;//将作业名状态修改为空闲   
        }     
    Delect_PreOrder(p->lchild,homework);  //遍历左子树     
    Delect_PreOrder(p->rchild,homework); //遍历右子树    
    }    
}    
int main()   {     
    BiTNode l;  
    Init_BiTree(&l);  
    //初始化   
    printf("\n   初始化:\t首地址\t长度\t状态\t作业名\n");  
  
    PreOrder(&l);  
    //插入作业1   
    temp=0;  
    Insert_PreOrder(&l,300,1);  
    printf("\n插入作业1:\t首地址\t长度\t状态\t作业名\n");  
    PreOrder(&l);    
    //插入作业2   
    temp=0;  
    Insert_PreOrder(&l,100,2);  
    printf("\n插入作业2:\t首地址\t长度\t状态\t作业名\n");  
    PreOrder(&l);  
    //释放作业1   
    Delect_PreOrder(&l,1);   
    printf("\n释放作业1:\t首地址\t长度\t状态\t作业名\n");  
    PreOrder(&l);     
    //插入作业3   
    temp=0;  
    Insert_PreOrder(&l,150,3);  
    printf("\n插入作业3:\t首地址\t长度\t状态\t作业名\n");  
    PreOrder(&l);  
    //插入作业4   
    temp=0;  
    Insert_PreOrder(&l,30,4);  
    printf("\n插入作业4:\t首地址\t长度\t状态\t作业名\n");  
    PreOrder(&l);  
    //插入作业5   
    temp=0;  
    Insert_PreOrder(&l,40,5);  
    printf("\n插入作业5:\t首地址\t长度\t状态\t作业名\n");  
    PreOrder(&l);  
    //插入作业6   
    temp=0;  
    Insert_PreOrder(&l,60,6);  
    printf("\n插入作业6:\t首地址\t长度\t状态\t作业名\n");  
    PreOrder(&l);  
    //释放作业4   
    Delect_PreOrder(&l,4);   
    printf("\n释放作业4:\t首地址\t长度\t状态\t作业名\n");  
    PreOrder(&l);     
    return 0;  
}   