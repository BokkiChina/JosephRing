#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node{
	int number;
	int password;
	struct node *next;
}Node,*List;

List CreateRing();
void Joseph(List Ring,int m);

int main()
{
	int m,n;
	List Ring;

	printf("请输入Joseph环的人数(1<n<=30)：\n");
	do{
        scanf("%d",&n);
        if(n>0&&n<=30)break;
        fflush(stdin);
        printf("输入有误，请重新输入：(1<n<=30)\n");
	}while(1);

    printf("\n请输入第一个报数的上限值(1<m<=30):\n");
    do{
        scanf("%d",&m);
        if(m>0&&m<=30)break;
        fflush(stdin);
        printf("输入有误，请重新输入(1<m<=30):\n");
    }while(1);

	Ring=CreateRing(n);

	printf("\n出列的顺序:\n");
	Joseph(Ring,m);

	return 0;
}

List CreateRing(int n)
{
	List NewNode,current;
	Node head;
	int i,code;

	printf("请依次输入每个人的密码(code>0):\n");
    current=&head;

	for(i=1;i<=n;i++)
    {
        do{
            scanf("%d",&code);
            if(code>0&&code<=100)break;
            fflush(stdin);
            printf("输入有误，请重新输入(code>0):\n");
        }while(1);

        NewNode=(List)malloc(sizeof(Node));
        NewNode->number=i;
		NewNode->password=code;

        current->next=NewNode;
        current=current->next;
    }
    current->next=head.next;

    printf("\n成功创建约瑟夫环：\n");
    printf("\n序号：");
    for(i=1;i<=n;i++)
        printf("%d ",i);
    printf("\n密码：");
    for(current=head.next,i=1;i<=n;i++)
    {
        printf("%d ",current->password);
        current=current->next;
    }
    putchar('\n');

	return head.next;
}


void Joseph(List Ring,int m)
{
	int i;
	Node *prior=Ring;
	if(Ring==Ring->next)
	{
		printf("%d\n",Ring->number);
		return;
	}
	for(i=1;i<m;i++)
	{
		Ring=Ring->next;
	}
	printf("%d ",Ring->number);
	m=Ring->password;

	while(prior->next!=Ring)prior=prior->next;
	prior->next=Ring->next;

	Joseph(Ring->next,m);
}
