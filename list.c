/* 包含的头文件 */
#include <stdio.h>
#include <stdlib.h>
 
/* 定义一个表示链表的结构体指针 */
struct list {
	int id;			/* 标识这个元素方便查找 */
	char data[20];		/* 链表中包含的元素 */
	struct list *next;	/* 指向下一个链表的指针 */
};
 
/* 定义一个链表头部 */
static struct list *list_head = NULL;
 
/* 为了保证每一个链表元素的id不同，特意把id定义成一个全局静态变量 */
static int list_id = 0;
 
/**	将指定元素插入到聊表尾部
  * head	: 表示要插入元素的链表的头部的地址
  *	list    : 表示要插入到链表中的元素
  */
static void list_add(struct list **head, struct list *list)
{
	struct list *temp;
 
	/* 判断链表是否为空 */
	if(NULL == *head)
	{
		/* 为空 */
		*head = list;
		(*head)->next = NULL;
	}
	else
	{
		/* 不为空 */
		temp = *head;
		while(temp)
		{
			if(NULL == temp->next)
			{
				temp->next = list;
				list->next = NULL;
			}
			temp = temp->next;
		}
	}
}
 
/** 遍历一个链表，打印链表中每个元素所包含的数据
  * head : 表示要遍历的链表的头部的指针
  */
static void list_print(struct list **head)
{	
	struct list *temp;
 
	temp = *head;
 
	printf("list information :\n");
	while(temp)
	{
		printf("\tlist %d : %s\n", temp->id, temp->data);
		temp = temp->next;
	}
}
 
/* 主函数，程序的入口 */
int main(int argc, char *argv[])
{
	int i = 0;
	struct list *lists = NULL;
 	
	/* 分配10个元素 */
	lists = malloc(sizeof(struct list) * 10);
	if(NULL == lists)
	{
		printf("malloc error!\n");
		return -1;
	}
 	
	/* 将分配的10个元素依次填充数据并加入到链表当中 */
	for(i = 0; i < 10; i++)
	{
		lists[i].id = list_id++;
		sprintf(lists[i].data, "TECH-PRO - %d", i);
 
		list_add(&list_head, &lists[i]);
	}
 	
	/* 遍历链表，把链表中每个元素的信息都打印出来 */
	list_print(&list_head);
 	
	return 0;
}
