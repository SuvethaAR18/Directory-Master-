#include<stdio.h>
#include<string.h>
#define QSIZE 100
struct node
{
    char fname[30];
    char lname[30];
    char phone[30];
    char city[30];
    char officiality[30];
    struct node* link;
};
struct node *n1 = NULL;
struct node *head;
struct node *top = NULL;          // Stack
struct node *shead;
int History[QSIZE];               // Queue
int front = -1;
int rear = -1;
void Enqueue(int x)
{
    if(front== - 1)
        front = 0;
    rear++;
    History[rear] = x;
}
void DispQueue()
{
    int i;
    printf("\n---------HISTORY TAB------------\n\n");
    for(i = front; i <= rear; i++)
    {
        printf(" Choice %d\n", History[i]);
    }
    Enqueue(11);
}
void push(struct node *x)
{
    if(top == NULL)
    {
        top = x;
        top->link = NULL;
        shead = top;
    }
    else
    {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp = x;
        temp->link = shead;
        top = temp;
        shead = top;
    }
}
void DispStack()
{
    if(top == NULL)
    {
        printf("\nThe bin is empty");
    }
    else
    {
        printf("The details stored in the Recycle bin are :\n\n");
        while(top != NULL)
        {
            printf("First Name : %s\n", top->fname);
            printf("Last Name : %s\n", top->lname);
            printf("Phone Number : %s\n", top->phone);
            printf("City : %s\n", top->city);
            printf("Officiality : %s\n", top->officiality);
            printf("\n-----------------------------------\n");
            top = top->link;
        }
        top = shead;
    }
    Enqueue(12);
}
void Restore()
{
    while(n1->link != NULL)
    {
        n1= n1->link;
    }
    if(n1 == NULL)
    {
        strcpy(n1->fname, top->fname);
        strcpy(n1->lname, top->lname);
        strcpy(n1->phone, top->phone);
        strcpy(n1->city, top->city);
        strcpy(n1->officiality, top->officiality);
        n1->link = NULL;
        head = n1;
        top = NULL;
        printf("\nThe bin is emptied!");
    }
    else
    {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        strcpy(temp->fname, top->fname);
        strcpy(temp->lname, top->lname);
        strcpy(temp->phone, top->phone);
        strcpy(temp->city, top->city);
        strcpy(temp->officiality, top->officiality);
        n1->link = temp;
        temp->link = NULL;
        n1 = temp;
        top = NULL;
        printf("\nThe bin is emptied!");
    }
}
void Create()
{
    printf("Enter the details to be inserted...\n\n");
    n1 = (struct node*)malloc(sizeof(struct node));
    printf("Enter the First Name: ");
    scanf("%s", n1->fname);
    printf("Enter the Last Name: ");
    scanf("%s", n1->lname);
    printf("Enter the Phone Number: ");
    scanf("%s", n1->phone);
    printf("Enter the City: ");
    scanf("%s", n1->city);
    printf("Is it a Personal or Business Contact? ");
    scanf("%s", n1->officiality);
    n1->link = NULL;
    head = n1;
    printf("\nDirectory Created!");
    Enqueue(1);
}
void Insert()
{
    printf("Enter the details to be inserted...\n\n");
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the First Name: ");
    scanf("%s", temp->fname);
    printf("Enter the Last Name: ");
    scanf("%s", temp->lname);
    printf("Enter the Phone Number: ");
    scanf("%s", temp->phone);
    printf("Enter the City: ");
    scanf("%s", temp->city);
    printf("Is it a Personal or Business Contact? ");
    scanf("%s", temp->officiality);
    n1->link = temp;
    temp->link = NULL;
    n1 = temp;
    printf("\nThe contact has been successfully inserted!");
    Enqueue(1);
}
void Delete()
{
    if(n1 == NULL)
    {
        printf("There are no contacts available");
    }
    else
    {
        char fname[30], lname[30];
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        n1 = head;
        temp = head->link;
        printf("Enter the first name and last name of the contact you wish to delete: ");
        scanf("%s", fname);
        scanf("%s", lname);
        if((strcmp(head->fname, fname) == 0) && (strcmp(head->lname, lname) == 0))
        {
            struct node *temp1;
            temp1 = (struct node*)malloc(sizeof(struct node));
            strcpy(temp1->fname, head->fname);
            strcpy(temp1->lname, head->lname);
            strcpy(temp1->phone, head->phone);
            strcpy(temp1->city, head->city);
            strcpy(temp1->officiality, head->officiality);
            push(temp1);
            head = head->link;
            n1 = head;
            printf("\nThe contact has been successfully moved to the recycle bin!");
            Enqueue(2);
            return;
        }
        else
        {
            printf("No such contact available!");
            return;
        }
        while(n1 != NULL)
        {
            if((strcmp(temp->fname, fname) == 0) && (strcmp(temp->lname, lname) == 0))
            {
                struct node *temp1;
                temp1 = (struct node*)malloc(sizeof(struct node));
                strcpy(temp1->fname, temp->fname);
                strcpy(temp1->lname, temp->lname);
                strcpy(temp1->phone, temp->phone);
                strcpy(temp1->city, temp->city);
                strcpy(temp1->officiality, temp->officiality);
                push(temp1);
                n1->link = n1->link->link;
                printf("\nThe contact has been successfully moved to the recycle bin!");
                free(temp);
                break;
            }
            else if((strcmp(head->fname, fname) == 0) && (strcmp(head->lname, lname) == 0))
            {
                struct node *temp1;
                temp1 = (struct node*)malloc(sizeof(struct node));
                strcpy(temp1->fname, head->fname);
                strcpy(temp1->lname, head->lname);
                strcpy(temp1->phone, head->phone);
                strcpy(temp1->city, head->city);
                strcpy(temp1->officiality, head->officiality);
                push(temp1);
                head = head->link;
                n1 = head;
                printf("\nThe contact has been successfully moved to the recycle bin!");
                break;
            }
            else if(temp->link != NULL)
            {
                temp = temp->link;
            }
            else
            {
                printf("No such contact available!");
                break;
            }
        }
    }
    Enqueue(2);
}
void Display(struct node *n1)
{
    if(n1 == NULL)
    {
        printf("\nThe Directory is empty");
    }
    else
    {
        printf("The details stored in the Directory are :\n\n");
        n1 = head;
        while(n1 != NULL)
        {
            printf("First Name : %s\n", n1->fname);
            printf("Last Name : %s\n", n1->lname);
            printf("Phone Number : %s\n", n1->phone);
            printf("City : %s\n", n1->city);
            printf("Officiality : %s\n", n1->officiality);
            printf("\n-----------------------------------\n");
            n1 = n1->link;
        }
    }
    Enqueue(3);
}
void Update()
{
    if(n1 == NULL)
    {
        printf("There are no contacts available");
    }
    else
    {
        char fname[30], lname[30];
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        n1 = head;
        temp = head->link;
        printf("Enter the name of the contact you wish to update: ");
        scanf("%s", fname);
        scanf("%s", lname);
        if((strcmp(head->fname, fname) == 0) && (strcmp(head->lname, lname) == 0))
        {
            printf("Enter the new contact: ");
            scanf("%s", head->phone);
            printf("\nThe contact has been successfully updated!");
            n1 = head;
            Enqueue(4);
            return;
        }
        else
        {
            printf("No such contact available!");
            return;
        }
        while(n1 != NULL)
        {
            if((strcmp(temp->fname, fname) == 0) && (strcmp(temp->lname, lname) == 0))
            {
                printf("Enter the new contact: ");
                scanf("%s", temp->phone);
                printf("\nThe contact has been successfully updated!");
                n1 = temp;
                break;
            }
            else if((strcmp(head->fname, fname) == 0) && (strcmp(head->lname, lname) == 0))
            {
                printf("Enter the new contact: ");
                scanf("%s", head->phone);
                printf("\nThe contact has been successfully updated!");
                n1 = head;
                break;
            }
            else if(temp->link != NULL)
            {
                temp = temp->link;
            }
            else
            {
                printf("No such contact available!");
                break;
            }
        }
    }
    Enqueue(4);
}
void SearchByFname()
{
    char name[30];
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    n1 = head;
    temp = head->link;
    printf("Enter the first name of the contact : ");
    scanf("%s", name);
    if(strcmp(head->fname, name) == 0)
    {
        printf("First Name : %s\n", head->fname);
        printf("Last Name : %s\n", head->lname);
        printf("Phone Number : %s\n", head->phone);
        printf("City : %s\n", head->city);
        printf("Officiality : %s\n", head->officiality);
        Enqueue(5);
        return;
    }
    else
    {
        printf("No such first name available!");
        return;
    }
    while(n1 != NULL)
    {
        if(strcmp(temp->fname, name) == 0)
        {
            printf("First Name : %s\n", temp->fname);
            printf("Last Name : %s\n", temp->lname);
            printf("Phone Number : %s\n", temp->phone);
            printf("City : %s\n", temp->city);
            printf("Officiality : %s\n", temp->officiality);
            break;
        }
        else if(strcmp(head->fname, name) == 0)
        {
            printf("First Name : %s\n", head->fname);
            printf("Last Name : %s\n", head->lname);
            printf("Phone Number : %s\n", head->phone);
            printf("City : %s\n", head->city);
            printf("Officiality : %s\n", head->officiality);
            break;
        }
        else if(temp->link != NULL)
        {
            temp = temp->link;
        }
        else
        {
            printf("No such first name available!");
            break;
        }
    }
    Enqueue(5);
}
void SearchByLname()
{
    char name[30];
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    n1 = head;
    temp = head->link;
    printf("Enter the last name of the contact : ");
    scanf("%s", name);
    if(strcmp(head->lname, name) == 0)
    {
        printf("First Name : %s\n", head->fname);
        printf("Last Name : %s\n", head->lname);
        printf("Phone Number : %s\n", head->phone);
        printf("City : %s\n", head->city);
        printf("Officiality : %s\n", head->officiality);
        Enqueue(6);
        return;
    }
    else
    {
        printf("No such last name available!");
        return;
    }
    while(n1 != NULL)
    {
        if(strcmp(temp->lname, name) == 0)
        {
            printf("First Name : %s\n", temp->fname);
            printf("Last Name : %s\n", temp->lname);
            printf("Phone Number : %s\n", temp->phone);
            printf("City : %s\n", temp->city);
            printf("Officiality : %s\n", temp->officiality);
            break;
        }
        else if(strcmp(head->lname, name) == 0)
        {
            printf("First Name : %s\n", head->fname);
            printf("Last Name : %s\n", head->lname);
            printf("Phone Number : %s\n", head->phone);
            printf("City : %s\n", head->city);
            printf("Officiality : %s\n", head->officiality);
            break;
        }
        else if(temp->link != NULL)
        {
            temp = temp->link;
        }
        else
        {
            printf("No such last name available!");
            break;
        }
    }
    Enqueue(6);
}
void SearchByPartialNo()
{
    char no[30];
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    n1 = head;
    temp = head->link;
    printf("Enter the partial contact : ");
    scanf("%s", no);
    if(strstr(head->phone, no) != 0)
    {
        printf("First Name : %s\n", head->fname);
        printf("Last Name : %s\n", head->lname);
        printf("Phone Number : %s\n", head->phone);
        printf("City : %s\n", head->city);
        printf("Officiality : %s\n", head->officiality);
        Enqueue(7);
        return;
    }
    else
    {
        printf("No such contact available!");
        return;
    }
    while(n1 != NULL)
    {
        if(strstr(temp->phone, no) != 0)
        {
            printf("First Name : %s\n", temp->fname);
            printf("Last Name : %s\n", temp->lname);
            printf("Phone Number : %s\n", temp->phone);
            printf("City : %s\n", temp->city);
            printf("Officiality : %s\n", temp->officiality);
            break;
        }
        else if(strstr(head->phone, no) != 0)
        {
            printf("First Name : %s\n", head->fname);
            printf("Last Name : %s\n", head->lname);
            printf("Phone Number : %s\n", head->phone);
            printf("City : %s\n", head->city);
            printf("Officiality : %s\n", head->officiality);
            break;
        }
        else if(temp->link != NULL)
        {
            temp = temp->link;
        }
        else
        {
            printf("No such contact available!");
            break;
        }
    }
    Enqueue(7);
}
void SortByName()
{
    struct node *temp1;
    temp1 = (struct node*)malloc(sizeof(struct node));
    struct node *temp2;
    temp2 = (struct node*)malloc(sizeof(struct node));
    char a[100], b[100], x[100], y[100], z[100];
    temp1 = head;
    while(temp1 != NULL)
    {
        temp2 = temp1->link;
        while(temp2 != NULL)
        {
            if(strcmp(temp1->fname, temp2->fname) > 0)
            {
                strcpy(a, temp1->fname);
                strcpy(temp1->fname, temp2->fname);
                strcpy(temp2->fname, a);
                strcpy(b, temp1->lname);
                strcpy(temp1->lname, temp2->lname);
                strcpy(temp2->lname, b);
                strcpy(x, temp1->phone);
                strcpy(temp1->phone, temp2->phone);
                strcpy(temp2->phone, x);
                strcpy(y, temp1->city);
                strcpy(temp1->city, temp2->city);
                strcpy(temp2->city, y);
                strcpy(z, temp1->officiality);
                strcpy(temp1->officiality, temp2->officiality);
                strcpy(temp2->officiality, z);
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }
    temp1 = head;
    printf("\nThe sorted list is : \n\n");
    while(temp1 != NULL)
    {
        printf("First Name : %s\n", temp1->fname);
        printf("Last Name : %s\n", temp1->lname);
        printf("Phone Number : %s\n", temp1->phone);
        printf("City : %s\n", temp1->city);
        printf("Officiality : %s\n", temp1->officiality);
        printf("\n-----------------------------------\n");
        temp1 = temp1->link;
    }
    Enqueue(8);
}
void SortByCity()
{
    struct node *temp1;
    temp1 = (struct node*)malloc(sizeof(struct node));
    struct node *temp2;
    temp2 = (struct node*)malloc(sizeof(struct node));
    char a[100], b[100], x[100], y[100], z[100];
    temp1 = head;
    while(temp1 != NULL)
    {
        temp2 = temp1->link;
        while(temp2 != NULL)
        {
            if(strcmp(temp1->city, temp2->city) > 0)
            {
                strcpy(a, temp1->fname);
                strcpy(temp1->fname, temp2->fname);
                strcpy(temp2->fname, a);
                strcpy(b, temp1->lname);
                strcpy(temp1->lname, temp2->lname);
                strcpy(temp2->lname, b);
                strcpy(x, temp1->phone);
                strcpy(temp1->phone, temp2->phone);
                strcpy(temp2->phone, x);
                strcpy(y, temp1->city);
                strcpy(temp1->city, temp2->city);
                strcpy(temp2->city, y);
                strcpy(z, temp1->officiality);
                strcpy(temp1->officiality, temp2->officiality);
                strcpy(temp2->officiality, z);
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }
    temp1 = head;
    printf("\nThe sorted list is : \n\n");
    while(temp1 != NULL)
    {
        printf("First Name : %s\n", temp1->fname);
        printf("Last Name : %s\n", temp1->lname);
        printf("Phone Number : %s\n", temp1->phone);
        printf("City : %s\n", temp1->city);
        printf("Officiality : %s\n", temp1->officiality);
        printf("\n-----------------------------------\n");
        temp1 = temp1->link;
    }
    Enqueue(9);
}
void SortByOfficiality()
{
    struct node *temp1;
    temp1 = (struct node*)malloc(sizeof(struct node));
    struct node *temp2;
    temp2 = (struct node*)malloc(sizeof(struct node));
    char a[100], b[100], x[100], y[100], z[100];
    temp1 = head;
    while(temp1 != NULL)
    {
        temp2 = temp1->link;
        while(temp2 != NULL)
        {
            if(strcmp(temp1->officiality, temp2->officiality) > 0)
            {
                strcpy(a, temp1->fname);
                strcpy(temp1->fname, temp2->fname);
                strcpy(temp2->fname, a);
                strcpy(b, temp1->lname);
                strcpy(temp1->lname, temp2->lname);
                strcpy(temp2->lname, b);
                strcpy(x, temp1->phone);
                strcpy(temp1->phone, temp2->phone);
                strcpy(temp2->phone, x);
                strcpy(y, temp1->city);
                strcpy(temp1->city, temp2->city);
                strcpy(temp2->city, y);
                strcpy(z, temp1->officiality);
                strcpy(temp1->officiality, temp2->officiality);
                strcpy(temp2->officiality, z);
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }
    temp1 = head;
    printf("\nThe sorted list is : \n\n");
    while(temp1 != NULL)
    {
        printf("First Name : %s\n", temp1->fname);
        printf("Last Name : %s\n", temp1->lname);
        printf("Phone Number : %s\n", temp1->phone);
        printf("City : %s\n", temp1->city);
        printf("Officiality : %s\n", temp1->officiality);
        printf("\n-----------------------------------\n");
        temp1 = temp1->link;
    }
    Enqueue(10);
}
int main()
{
    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
    {
	system("cls");
    printf("\n  \t\t\t****  AUTHORIZED USER LOGIN  ****  \n");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
    if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n      LOGIN IS SUCCESSFUL");
	int i=0;
	time_t t;
	time(&t);
	system("cls");   // FOR CLEARING SCREEN
	printf(" -------------------------------------------------------------------------\n");
	printf("|                                                                         |\n");
	printf("|                                                                         |\n");
	printf("|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
	printf("|  O        O    O O      O        O      O    O O    O O        O        |\n");
	printf("|  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
	printf("|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
	printf("|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
	printf("|                                                                         |\n");
	printf(" -------------------------------------------------------------------------\n");
 	printf("\t\t*****************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*              PHONE DIRECTORY                  *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*        HOW ABOUT YOUR PHONE NUMBER?           *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*****************\n\n\n");
    for(i=0;i<80;i++)
    printf("-");
    printf("\nCurrent date and time : %s", ctime(&t));
    for(i=0;i<80;i++)
    printf("-");
	printf(" \n Press any key to continue:");
	getch();
    system("cls");
	int choice, choice1 = 1, ch;
	char fn[30];
    do{
            printf("\nEnter your choice : \n\n");
            printf(" \n Enter 1 -> Add Contact");
            printf("\n------------------------");
            printf(" \n Enter 2 -> Delete Contact");
            printf("\n----------------------------------");
            printf(" \n Enter 3 -> Display the details");
            printf("\n-----------------------------------");
            printf(" \n Enter 4 -> Update Contact");
            printf("\n-----------------------------------");
            printf(" \n Search");
            printf("\n-------Enter 5 -> By First Name");
            printf("\n-------Enter 6 -> By Last Name");
            printf("\n-------Enter 7 -> By Partial Number");
            printf("\n-----------------------------------");
            printf(" \n Sort");
            printf("\n-------Enter 8 -> By Name");
            printf("\n-------Enter 9 -> By City");
            printf("\n-------Enter 10 -> By Officiality");
            printf("\n-----------------------------------");
            printf(" \n Enter 11 -> History Tab");
            printf("\n-----------------------------------");
            printf(" \n Enter 12 -> Recycle Bin");
            printf("\n-----------------------------------");
           	printf("\n");
            scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            if(n1 == NULL)
            {
                Create();
            }
            else
            {
                Insert();
            }
            break;
        case 2:
            Delete();
            break;
        case 3:
            Display(n1);
            break;
        case 4:
            Update();
            break;
        case 5:
            SearchByFname();
            break;
        case 6:
            SearchByLname();
            break;
        case 7:
            SearchByPartialNo();
            break;
        case 8:
            SortByName();
            break;
        case 9:
            SortByCity();
            break;
        case 10:
            SortByOfficiality();
            break;
        case 11:
            DispQueue();
            break;
        case 12:
            DispStack();
            if(top != NULL)
            {
                printf("\nDo you wish to restore the recently deleted contact? [yes=1/no=0] ");
                scanf("%d", &ch);
                if(ch == 1)
                    Restore();
            }
            break;
        default:
            printf("\nNot a choice!");
    }
    printf("\nDo you wish to continue?[yes=1/no=0]");
    scanf("%d", &choice1);
    }while(choice1==1);
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch();
	}
    }while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong User Name and Password for three times!!!");
		getch();
    }
    system("cls");
}
