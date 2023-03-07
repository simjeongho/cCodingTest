#include<stdio.h>
#include<string.h>

#define TRUE 1            //1��ȯ 
#define FALSE 0           //0��ȯ 
#define MINUS -1          //-1��ȯ 
#define MAX_SIZE 10000    //���� �迭 ������ 

typedef struct _stack {    //���� ����ü. 
    int arr[MAX_SIZE];
    int top;
} Stack;

void StackInit(Stack* sp) {    //���� �ʱ�ȭ �Լ� 
    sp->top = -1;
}

int IsEmpty(Stack* sp) {    //������ ����ִ��� Ȯ�� 
    if (sp->top == -1) return TRUE;

    return FALSE;
}

int Size(Stack* sp) {    //������ size ��ȯ 
    return sp->top + 1;
}


int IsFull(Stack* sp) {        //������ �� ���ִ��� Ȯ�� 
    if (sp->top + 1 >= MAX_SIZE) return TRUE;

    return FALSE;
}

void Push(Stack* sp, int data) {    //������ push 
    if (IsFull(sp) == TRUE) return;

    //top�� �ϳ� �ø� �� data ����
    sp->arr[++(sp->top)] = data;
}

int Pop(Stack* sp) {    //������ pop. 
    if (IsEmpty(sp) == TRUE) return MINUS;

    //top�� ����Ű�� ���� ��ȯ �� top�� �ϳ� ����.
    return sp->arr[(sp->top)--];
}

int Peek(Stack* sp) {    //������ ������ ���ڸ� ��ȯ�մϴ�. 
    if (IsEmpty(sp) == TRUE) return MINUS;

    return sp->arr[sp->top];
}


int main(void) {
    int i;
    char str[6];
    Stack stack;
    int n, num;

    scanf("%d", &n);
    fgetc(stdin);    //���� ���� 
    StackInit(&stack);    //stack �ʱ�ȭ. 


    for (i = 0; i < n; i++) {

        scanf("%s", str);
        fgetc(stdin);    //���� ����. 

        if (!strcmp(str, "push")) {    //push �� ��� 

            scanf("%d", &num);
            fgetc(stdin);    //���� ����. 
            Push(&stack, num);

        }
        else if (!strcmp(str, "pop")) {    //pop�� ��� 

            printf("%d\n", Pop(&stack));

        }
        else if (!strcmp(str, "empty")) {    //empty�ΰ�� 

            printf("%d\n", IsEmpty(&stack));

        }
        else if (!strcmp(str, "size")) {        //size�� ���  

            printf("%d\n", Size(&stack));

        }
        else if (!strcmp(str, "top")) {        //top�� ��� 

            printf("%d\n", Peek(&stack));

        }
    }


    return 0;
}
