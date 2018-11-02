#include<stdio.h>  
#include<malloc.h>  
#define maxsize  1024  //线性表的最大长度  
typedef struct{        //表的类型   
    int data[maxsize];//表的储存空间   
    int last;  
}sqlist,*sqlink;      //说明标示符   
  
  
void CreateList(sqlink L);//创空表  
void ClearList(sqlink L);//置空表  
int GetList(sqlink L,int no);//取表元素   
int LengthList(sqlink L);//求表长  
int InsertList(sqlink L,int data,int no);//插入元素  
int DeleteList(sqlink L,int no);//删除元素  
int LocateList(sqlink L,int data);//定位元素  
int EmptyList(sqlink L);//判空表  
void PrintList(sqlink L);//打印表元素   
   
int main(){  
      
    sqlink L = (sqlink)malloc(sizeof(sqlist));  
    CreateList(L);  
    PrintList(L);  
      
    int data,x;  
    printf("please input data and index : ");  
    scanf("%d %d",&data,&x);  
    InsertList(L,data,x);  
    PrintList(L);  
      
    return 0;  
}   
  
void CreateList(sqlink L){  
    int tempNo = 1;  
    int tempData = 0;  
    do{  
        printf("please input %d elem : ",tempNo);  
        scanf("%d",&tempData);  
        if(tempData!=-1){  
            L->data[tempNo-1] = tempData;  
            L->last = tempNo-1;  
            tempNo++;  
        }  
    }while(tempNo<=maxsize&&tempData!=-1);  
}  
void PrintList(sqlink L){  
    int i;  
    for(i = 0;i<LengthList(L);i++){  
        printf("%d ",L->data[i]);  
    }  
    printf("\n");  
}   
void ClearList(sqlink L){  
    L->last = -1;  
}  
int GetList(sqlink L,int no){  
    int tempData = 0;  
    tempData = L->data[no-1];  
    return tempData;   
}  
int LengthList(sqlink L){  
    int tempL;  
    tempL = L->last+1;  
    return tempL;  
}  
//插入元素   
int InsertList(sqlink L,int data,int no){  
    int j;  
    if(L->last >= maxsize-1){  
        printf("There is no free position\n");  
        return 0;  
    }else if(no<0||no>L->last+1){  
        printf("insert position is Non-existent\n");  
        return 0;  
    }else{  
        for(j=L->last;j>=no-1;j--)  
            L->data[j+1] = L->data[j];  
        L->data[no-1] = data;  
        L->last++;  
        return 0;  
    }  
}  
//删除元素  
int DeleteList(sqlink L,int no){  
    int j;  
    if(no<0||no>L->last){  
        printf("remove elem is Non-existent");  
        return 0;  
    }else{  
        for(j=no;j+1<=L->last;j++)  
            L->data[j] = L->data[j+1];  
        L->last--;  
        return 0;  
    }  
}  
//定位元素  
int LocateList(sqlink L,int data){  
    int i = 0;  
    while(i<=L->last&&L->data[i]!=data)  
        i++;  
    if(i<L->last) return i;  
    else return 0;  
}