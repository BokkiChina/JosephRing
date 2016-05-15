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

	printf("������Joseph��������(1<n<=30)��\n");
	do{
        scanf("%d",&n);
        if(n>0&&n<=30)break;
        fflush(stdin);
        printf("�����������������룺(1<n<=30)\n");
	}while(1);

    printf("\n�������һ������������ֵ(1<m<=30):\n");
    do{
        scanf("%d",&m);
        if(m>0&&m<=30)break;
        fflush(stdin);
        printf("������������������(1<m<=30):\n");
    }while(1);

	Ring=CreateRing(n);

	printf("\n���е�˳��:\n");
	Joseph(Ring,m);

	return 0;
}

List CreateRing(int n)
{
	List NewNode,current;
	Node head;
	int i,code;

	printf("����������ÿ���˵�����(code>0):\n");
    current=&head;

	for(i=1;i<=n;i++)
    {
        do{
            scanf("%d",&code);
            if(code>0&&code<=100)break;
            fflush(stdin);
            printf("������������������(code>0):\n");
        }while(1);

        NewNode=(List)malloc(sizeof(Node));
        NewNode->number=i;
		NewNode->password=code;

        current->next=NewNode;
        current=current->next;
    }
    current->next=head.next;

    printf("\n�ɹ�����Լɪ�򻷣�\n");
    printf("\n��ţ�");
    for(i=1;i<=n;i++)
        printf("%d ",i);
    printf("\n���룺");
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
