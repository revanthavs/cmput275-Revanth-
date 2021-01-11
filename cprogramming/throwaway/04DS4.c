#include "stdio.h"
#include "stdlib.h"
menu();
issorted(struct node **sclla, int ln);
isposvalid(int pos);
isempty(struct node *base);
isexisting(struct node *base);
islistvalid(int ln);
errorhandler(int res);
struct node
{
	int info;
	struct node *next;
};
int res;
erase(struct node **lla, int ln)
{
	int ele;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(lla[ln])<0)
		return(-3);
	while(lla[ln]!=NULL)
		delbeg(lla, ln, &ele);
	return(1);
}
uni(struct node **lla, int ln1, int ln2, int ln3)
{
	struct node ** basep;
	int pos;
	if(islistvalid(ln1)<0)
		return(-7);
	if(islistvalid(ln2)<0)
		return(-8);
	if(islistvalid(ln3)<0)
		return(-9);
	if(isexisting(lla[ln3])<0)
		return(-15);
	basep=&lla[ln1];
	while(*basep!=NULL)
	{
		if(searchep(lla, ln3, (*basep)->info, &pos)<0)
			insbeg(lla, ln3, (*basep)->info);
		basep=&((*basep)->next);
	}
	basep=&lla[ln2];
	while(*basep!=NULL)
	{
		if(searchep(lla, ln3, (*basep)->info, &pos)<0)
			insbeg(lla, ln3, (*basep)->info);
		basep=&((*basep)->next);
	}
	return(1);
}
intersection(struct node **lla, int ln1, int ln2, int ln3)
{
	struct node ** basep;
	int pos;
	if(islistvalid(ln1)<0)
		return(-7);
	if(islistvalid(ln2)<0)
		return(-8);
	if(islistvalid(ln3)<0)
		return(-9);
	if(isexisting(lla[ln3])<0)
		return(-15);
	basep=&lla[ln1];
	while(*basep!=NULL)
	{
		if(searchep(lla, ln2, (*basep)->info, &pos)>0)
			if(searchep(lla, ln3, (*basep)->info, &pos)<0)
				insbeg(lla, ln3, (*basep)->info);
		basep=&((*basep)->next);
	}
	return(1);
}
clone(struct node **lla, int ln1, int ln2)
{
	struct node ** basep;
	if(islistvalid(ln1)<0)
		return(-13);
	if(islistvalid(ln2)<0)
		return(-9);
	if(isempty(lla[ln1])<0)
		return(-14);
	if(isexisting(lla[ln2])<0)
		return(-15);
	basep=&lla[ln1];
	while(*basep!=NULL)
	{
		insend(lla, ln2, (*basep)->info);
		basep=&((*basep)->next);
	}
	return(1);
}
mergesss(struct node **lla, int ln1, int ln2, int ln3)
{
	struct node ** basep1, ** basep2;
	if(islistvalid(ln1)<0)
		return(-7);
	if(islistvalid(ln2)<0)
		return(-8);
	if(islistvalid(ln3)<0)
		return(-9);
	if(isexisting(lla[ln3])<0)
		return(-10);
	if(issorted(lla, ln1)<0)
		return(-11);
	if(issorted(lla, ln2)<0)
		return(-12);
	basep1=&lla[ln1];
	basep2=&lla[ln2];
	while(*basep1!=NULL && *basep2!=NULL)
	{
		if( (*basep1)->info < (*basep2)->info)
		{
			insend(lla, ln3, (*basep1)->info);
			basep1=&((*basep1)->next);
		}
		else
		{
			insend(lla, ln3, (*basep2)->info);
			basep2=&((*basep2)->next);
		}
	}
	while(*basep1!=NULL)
	{
		insend(lla, ln3, (*basep1)->info);
		basep1=&((*basep1)->next);
	}
	while(*basep2!=NULL)
	{
		insend(lla, ln3, (*basep2)->info);
		basep2=&((*basep2)->next);
	}
	return(1);
}
mergeuus(struct node **lla, int ln1, int ln2, int ln3)
{
	struct node ** basep;
	if(islistvalid(ln1)<0)
		return(-7);
	if(islistvalid(ln2)<0)
		return(-8);
	if(islistvalid(ln3)<0)
		return(-9);
	if(isexisting(lla[ln3])<0)
		return(-10);
	basep=&lla[ln1];
	while(*basep!=NULL)
	{
		insele(lla, ln3, (*basep)->info);
		basep=&((*basep)->next);
	}
	basep=&lla[ln2];
	while(*basep!=NULL)
	{
		insele(lla, ln3, (*basep)->info);
		basep=&((*basep)->next);
	}
	return(1);
}
mergeuuu(struct node **lla, int ln1, int ln2, int ln3)
{
	struct node ** basep;
	if(islistvalid(ln1)<0)
		return(-7);
	if(islistvalid(ln2)<0)
		return(-8);
	if(islistvalid(ln3)<0)
		return(-9);
	if(isexisting(lla[ln3])<0)
		return(-10);
	basep=&lla[ln1];
	while(*basep!=NULL)
	{
		insend(lla, ln3, (*basep)->info);
		basep=&((*basep)->next);
	}
	basep=&lla[ln2];
	while(*basep!=NULL)
	{
		insend(lla, ln3, (*basep)->info);
		basep=&((*basep)->next);
	}
	return(1);
}
sortdec(struct node **lla, int ln)
{
	struct node *start, *temp;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(lla[ln])<0)
		return(-3);
	if((lla[ln])->next==NULL)
		return(1);
	start=lla[ln];
	lla[ln]=NULL;
	while(start != NULL)
	{
		temp=start;
		start=temp->next;
		insnodedec(&lla[ln], temp);
	}
	return(1);
}
insnodedec(struct node **basep, struct node *temp)
{
	while(*basep!=NULL)
	{
		if(temp->info>(*basep)->info)
			break;
		basep=&((*basep)->next);
	}
	temp->next=*basep;
	*basep=temp;
	return(1);
}






sortasc(struct node **sclla, int ln)
{
	struct node *start, *temp;
	int size, i;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(sclla[ln])<0)
		return(-3);
	if((sclla[ln])->next==sclla[ln])
		return(1);

	count(sclla, ln, &size);
	start= sclla[ln];
	sclla[ln]=NULL;
	for(i=1;i<=size;i++)
	{
		delnodebeg(&start, 0, &temp);
		printf("\n%u: %d ", temp, temp->info);
		insnodeasc(sclla, ln, temp);
	}
	return(1);
}
insnodeasc(struct node **sclla, int ln, struct node *temp)
{
	struct node ** basep;
	int size, i;
	if(isempty(sclla[ln])<0)
	{
		insnodebeg(sclla, ln, temp);
		return(1);
	}
	count(sclla, ln, &size);
	basep=&sclla[ln];
	for(i=1;i<=size;i++)
	{
		if(temp->info<(*basep)->info)
			break;
		basep=&((*basep)->next);
	}
	insnodepos(sclla, ln, temp, i);
	return(1);
}
delele(struct node **sclla, int ln, int ele)
{
	int stat=0, size,i;
	struct node ** basep, *temp;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(sclla[ln])<0)
		return(-3);
	count(sclla, ln, &size);
	for(i=1,basep=&sclla[ln];i<=size;)
	{
		if((*basep)->info==ele)
		{
			delnodepos(sclla, ln, i, &temp);
			free(temp);
			size--;
			stat=1;
			continue;
		}
		basep=&((*basep)->next);
		i++;
	}
	if(stat==0)
		return(-5);
	return(1);
}
delpos(struct node **sclla, int ln, int *elep, int pos)
{
	struct node ** basep,* temp;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(sclla[ln])<0)
		return(-3);
	if(isposvalid(pos)<0)
		return(-4);
	delnodepos(sclla, ln, pos, &temp);
	*elep=temp->info;
	free(temp);
	return(1);
}
delnodepos(struct node **sclla, int ln, int pos, struct node **tempp)
{
	struct node ** basep;
	int size, i;
	count(sclla, ln, &size);
	if(size==1||pos%size==1)
	{
		delnodebeg(sclla, ln, tempp);
		return(1);
	}
	if(pos==size||pos%size==0)
	{
		delnodeend(sclla, ln, tempp);
		return(1);
	}
	basep=&sclla[ln];
	i=1;
	for(i=1;i!=pos;i++)
		basep=&((*basep)->next);
	*tempp=*basep;
	*basep=(*tempp)->next;
	return(1);
}
delend(struct node **sclla, int ln, int *elep)
{
	struct node ** basep,* temp;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(sclla[ln])<0)
		return(-3);
	delnodeend(sclla, ln, &temp);
	*elep=temp->info;
	free(temp);
	return(1);
}
delnodeend(struct node **sclla, int ln, struct node **tempp)
{
	struct node ** basep;
	int size, i;
	if(sclla[ln]==sclla[ln]->next)
	{
		*tempp=sclla[ln];
		sclla[ln]=NULL;
		return(1);
	}
	count(sclla, ln, &size);
	basep=&sclla[ln];
	for(i=1;i<=size-1;i++)
		basep=&((*basep)->next);
	*tempp=*basep;
	*basep=(*tempp)->next;
	*basep=(*tempp)->next;
	return(1);
}
delbeg(struct node **sclla, int ln, int *elep)
{
	struct node * temp;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(sclla[ln])<0)
		return(-3);
	delnodebeg(sclla, ln, &temp);
	*elep=temp->info;
	free(temp);
	return(1);
}
delnodebeg(struct node **sclla, int ln, struct node **tempp)
{
	struct node ** basep;
	int size, i;
	*tempp=sclla[ln];
	if(sclla[ln]==sclla[ln]->next)
	{
		sclla[ln]=NULL;
		return(1);
	}
	count(sclla, ln, &size);
	basep=&sclla[ln];
	for(i=1;i<=size;i++)
		basep=&((*basep)->next);
	sclla[ln]=(*tempp)->next;
	*basep=(*tempp)->next;
	return(1);
}
insele(struct node **sclla, int ln, int ele)
{
	struct node *temp;
	int size;
	if(islistvalid(ln)<0)
		return(-1);
	if(isexisting(sclla[ln])<0)
		if(issorted(sclla, ln)<0)
			return(-6);
	temp=malloc(sizeof(struct node));
	temp->info=ele;
	insnodeele(sclla, ln, temp);
	return(1);
}
insnodeele(struct node **sclla, int ln, struct node *temp)
{
	struct node ** basep;
	int size, i;
	if(isempty(sclla[ln])<0)
	{
		insnodebeg(sclla, ln, temp);
		return(1);
	}
	count(sclla, ln, &size);
	basep=&sclla[ln];
	for(i=1;i<=size;i++)
	{
		if(temp->info<(*basep)->info)
			break;
		basep=&((*basep)->next);
	}
	insnodepos(sclla, ln, temp, i);
	return(1);
}
inspos(struct node **sclla, int ln, int ele, int pos)
{
	struct node *temp, ** basep;
	if(islistvalid(ln)<0)
		return(-1);
	if(isposvalid(pos)<0)
		return(-4);
	temp=malloc(sizeof(struct node));
	temp->info=ele;
	insnodepos(sclla, ln, temp, pos);
	return(1);
}
insnodepos(struct node **sclla, int ln, struct node *temp, int pos)
{
	int size, i;
	struct node **basep;
	count(sclla, ln, &size);
	if(pos==size+1)
	{
		insnodeend(sclla, ln, temp);
		return(1);
	}
	if(pos%size==1 || pos == 1)
	{
		insnodebeg(sclla, ln, temp);
		return(1);
	}
	for(i=1,basep=&sclla[ln];i<pos;i++)
		basep=&((*basep)->next);
	temp->next=*basep;
	*basep=temp;
	return(1);
}
insend(struct node **sclla, int ln, int ele)
{
	struct node *temp;
	if(islistvalid(ln)<0)
		return(-1);
	temp=malloc(sizeof(struct node));
	temp->info=ele;
	insnodeend(sclla, ln, temp);
	return(1);
}
insnodeend(struct node **sclla, int ln, struct node *temp)
{
	struct node **basep;
	int size, i;
	if(isempty(sclla[ln])==-3)      	//if the list is empty
	{
		sclla[ln]=temp;
		temp->next=temp;
		return(1);
	}
	count(sclla, ln, &size);    		//if the list is not empty
	basep=&sclla[ln];
	for(i=1;i<=size;i++)
		basep=&((*basep)->next);
	temp->next=sclla[ln];
	*basep=temp;
	return(1);
}
insbeg(struct node **sclla, int ln, int ele)
{
	struct node *temp, **basep;
	int size;
	if(islistvalid(ln)<0)
		return(-1);
	temp=malloc(sizeof(struct node));
	temp->info=ele;
	insnodebeg(sclla, ln, temp);
	return(1);
}
insnodebeg(struct node **sclla, int ln, struct node *temp)
{
	struct node **basep;
	int size, i;
	if(isempty(sclla[ln])==-3)      	//if the list is empty
	{
		sclla[ln]=temp;
		temp->next=temp;
		return(1);
	}
	count(sclla, ln, &size);    		//if the list is not empty
	temp->next=sclla[ln];
	basep=&sclla[ln];
	for(i=1;i<=size;i++)
		basep=&((*basep)->next);
	*basep=temp;
	sclla[ln]=temp;
	return(1);
}
searchep(struct node **sclla, int ln, int ele, int *posp)
{
	struct node ** basep;
	int size, i;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(sclla[ln])<0)
		return(-3);
	count(sclla, ln, &size);
	basep=&sclla[ln];
	for(i=1;i<=size;i++)
	{
		if(ele == (*basep)->info)
		{
			*posp=i;
			return(1);
		}
		basep=&((*basep)->next);
	}
	return(-5);
}
searchpe(struct node **sclla,int ln, int pos, int *elep)
{
	struct node ** basep;
	int i;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(sclla[ln])<0)
		return(-3);
	if(isposvalid(pos)<0)
		return(-4);
	basep=&sclla[ln];
	i=0;
	while(++i<pos)
		basep=&((*basep)->next);
	*elep=(*basep)->info;
	return(1);
}
display(struct node **sclla, int ln)
{
	struct node ** basep;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(sclla[ln])<0)
		return(-3);
	basep=&sclla[ln];
	printf("\nStart : %u", *basep);
	while((*basep)->next!=sclla[ln])
	{
		printf("\n%u : %d -> %u",(*basep),(*basep)->info, (*basep)->next);
		basep=&((*basep)->next);
	}
	printf("\n%u : %d -> %u",(*basep),(*basep)->info, (*basep)->next);
	return(1);
}
count(struct node **sclla, int ln, int *sizep)
{
	int c=1;
	struct node ** basep;
	if(islistvalid(ln)<0)
		return(-1);
	if(isempty(sclla[ln])<0)
		return(-3);
	basep=&sclla[ln];
	while((*basep)->next!=sclla[ln])
	{
		c++;
		basep=&((*basep)->next);
	}
	*sizep=c;
	return(1);
}
initialize(	struct node **sclla, int ln)
{
	char ch='y';
	int ele;
	struct node ** basep;
	if(islistvalid(ln)<0)
		return(-1);
	if(isexisting(sclla[ln])<0)
		return(-2);
	basep=&sclla[ln];
	while(toupper(ch)=='Y')
	{
		printf("\nEnter the element to insert");
		scanf("%d", &ele);
		*basep=malloc(sizeof(struct node));
		(*basep)->info=ele;
		(*basep)->next=sclla[ln];
		printf("\nInsert one more element(Y/N)");
		ch=getche();
		basep=&((*basep)->next);
	}
	return(1);
}
issorted(struct node **sclla, int ln)
{
	struct node ** basep;
	basep=&sclla[ln];
	while((*basep)->next!=sclla[ln])
	{
		if((*basep)->info>(*basep)->next->info)
			return(-6);
		basep=&((*basep)->next);
	}
	return(1);
}
isposvalid( int pos)
{
	return((pos<1)?-4:1);
}
isempty(struct node *base)
{
	return((base==NULL)?-3:1);
}
isexisting(struct node *base)
{
	return((base!=NULL)?-2:1);
}
islistvalid(int ln)
{
	return((ln<0 || ln>999)?-1:1);
}
errorhandler(int res)
{
	char *emessage[]=
					{
						"",
/* -1  */				"Invalid list number",
/* -2  */				"Existing list",
/* -3  */				"Empty list",
/* -4  */               "Invalid position",
/* -5  */				"Element not found",
/* -6  */				"List not sorted",
/* -7  */				"Invalid 1st list number",
/* -8  */				"Invalid 2nd list number",
/* -9  */				"Invalid target list number",
/* -10 */				"target list not empty",
/* -11 */				"1st list unsorted",
/* -12 */				"2nd list unsorted",
/* -13 */               "Invalid source list number",
/* -14 */				"Empty source list",
/* -15 */				"Existing target list"
					};
	res=res*-1;
	printf("%s", emessage[res]);
	return(1);
}
menu()
{
	//clrscr();
	gotoxy( 20, 1 ); printf("SINGLE CIRCULAR LINKED LIST  APPLICATIONS");
	gotoxy(  2, 3 ); printf("01. INITIALIZE");
	gotoxy(  2, 4 ); printf("02. COUNT");
	gotoxy(  2, 5 ); printf("03. DISPLAY");
	gotoxy(  2, 6 ); printf("04. SEARCH : POS -> ELE");
	gotoxy(  2, 7 ); printf("05. SEARCH : ELE -> POS");
	gotoxy(  2, 8 ); printf("06. INSERTION : AT BIGIN");
	gotoxy(  2, 9 ); printf("07. INSERTION : AT END");
	gotoxy(  2,10 ); printf("08. INSERTION : AT A GIVEN POS");
	gotoxy(  2,11 ); printf("09. INSERTION : AN ELEMENT");
	gotoxy(  2,12 ); printf("10. DELETION : AT BEGIN");
	gotoxy(  2,13 ); printf("11. DELETION : AT END");
	gotoxy(  2,14 ); printf("12. DELETION : AT A GIVEN POS");
	gotoxy(  2,15 ); printf("13. DELETION : AN ELEMENT");
	gotoxy( 42, 3 ); printf("14. SORT : ASCENDING");
	gotoxy( 42, 4 ); printf("15. SORT : DESCENDING");
	gotoxy( 42, 5 ); printf("16. MERGING : US + US = US");
	gotoxy( 42, 6 ); printf("17. MERGING : US + US = S");
	gotoxy( 42, 7 ); printf("18. MERGING : S + S = S");
	gotoxy( 42, 8 ); printf("19. CLONE");
	gotoxy( 42, 9 ); printf("20. INTERSECTION");
	gotoxy( 42,10 ); printf("21. UNION");
	gotoxy( 42,11 ); printf("22. ERASE");
	gotoxy( 42,14 ); printf("00. EXIT");
	gotoxy( 42,16 ); printf("YOUR CHOICE ? ");
}

void main()
{
	struct node * sclla[1000]={0};
	int choice,size,ln, ln1, ln2, ln3, pos, ele;
	while(1)
	{
		menu();
		scanf("%d", &choice);
		//clrscr();
		switch(choice)
		{
			default:
				printf("Wrong choice !!! Try again !!!");
				break;
			case 0:
				printf("Thank you !!! Visit again !!!");
				//getch();
                getchar();
				exit(0);
			case 1:
				printf("Initialize list operation");
				printf("\nEnter list number to initialize");
				scanf("%d", &ln);
				res=initialize(sclla, ln);
				if(res<0)
				{
					printf("\nInitialize operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nInitialize operation successfull");
				break;
			case 2:
				printf("Count list operation");
				printf("\nEnter list number to count");
				scanf("%d", &ln);
				res=count(sclla, ln, &size);
				if(res<0)
				{
					printf("\nCount operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nNo of elements in the list : %d", size);
				printf("\nCount operation successfull");
				break;
			case 3:
				printf("Display list operation");
				printf("\nEnter list number to display");
				scanf("%d", &ln);
				res=display(sclla, ln);
				if(res<0)
				{
					printf("\nDisplay operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nDisplay operation successfull");
				break;
			case 4:
				printf("Search list operation");
				printf("\nEnter list number to search");
				scanf("%d", &ln);
				printf("\nEnter position");
				scanf("%d", &pos);
				res=searchpe(sclla, ln, pos, &ele);
				if(res<0)
				{
					printf("\nSearch list operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\n%d element found in %d position", ele, pos);
				printf("\nSearech operation successfull");
				break;
			case 5:
				printf("Search list operation");
				printf("\nEnter list number to search");
				scanf("%d", &ln);
				printf("\nEnter element");
				scanf("%d", &ele);
				res=searchep(sclla, ln, ele, &pos);
				if(res<0)
				{
					printf("\nSearch list operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\n%d element found in %d position", ele, pos);
				printf("\nSearech operation successfull");
				break;
			case 6:
				printf("Insert at begin operation");
				printf("\nEnter list number to insert element");
				scanf("%d", &ln);
				printf("\nEnter element to insert");
				scanf("%d", &ele);
				res=insbeg(sclla, ln, ele);
				if(res<0)
				{
					printf("\nInsert at begin operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nInsert at begin operation successfull");
				break;
			case 7:
				printf("Insert at end operation");
				printf("\nEnter list number to insert element");
				scanf("%d", &ln);
				printf("\nEnter element to insert");
				scanf("%d", &ele);
				res=insend(sclla, ln, ele);
				if(res<0)
				{
					printf("\nInsert at end operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nInsert at end operation successfull");
				break;
			case 8:
				printf("Insert at a given position operation");
				printf("\nEnter list number to insert element");
				scanf("%d", &ln);
				printf("\nEnter element to insert");
				scanf("%d", &ele);
				printf("\nEnter position to insert");
				scanf("%d", &pos);
				res=inspos(sclla, ln, ele, pos);
				if(res<0)
				{
					printf("\nInsert at a given position operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nInsert at a given position operation successfull");
				break;
			case 9:
				printf("Insert an element operation");
				printf("\nEnter list number to insert element");
				scanf("%d", &ln);
				printf("\nEnter element to insert");
				scanf("%d", &ele);
				res=insele(sclla, ln, ele);
				if(res<0)
				{
					printf("\nInsert an element operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nInsert an element operation successfull");
				break;
			case 10:
				printf("Delete at begin operation");
				printf("\nEnter list number to delete element");
				scanf("%d", &ln);
				res=delbeg(sclla, ln, &ele);
				if(res<0)
				{
					printf("\nDelete at begin operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nElement deleted is %d", ele);
				printf("\nDelete at begin operation successfull");
				break;
			case 11:
				printf("Delete at end operation");
				printf("\nEnter list number to delete element");
				scanf("%d", &ln);
				res=delend(sclla, ln, &ele);
				if(res<0)
				{
					printf("\nDelete at end operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nElement deleted is %d", ele);
				printf("\nDelete at end operation successfull");
				break;
			case 12:
				printf("Delete at a given position operation");
				printf("\nEnter list number to delete element");
				scanf("%d", &ln);
				printf("\nEnter position to delete");
				scanf("%d", &pos);
				res=delpos(sclla, ln, &ele, pos);
				if(res<0)
				{
					printf("\nDelete at a given position operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nElement deleted is %d", ele);
				printf("\nDelete at a given position operation successfull");
				break;
			case 13:
				printf("Delete an element operation");
				printf("\nEnter list number to delete element");
				scanf("%d", &ln);
				printf("\nEnter element to delete");
				scanf("%d", &ele);
				res=delele(sclla, ln, ele);
				if(res<0)
				{
					printf("\nDelete an element operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nDelete an element operation successfull");
				break;
			case 14:
				printf("Sort list - Ascending operation");
				printf("\nEnter list number to sort");
				scanf("%d", &ln);
				res=sortasc(sclla, ln);
				if(res<0)
				{
					printf("\nSorting in ascending order operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nSorting in ascending order operation successfull");
				break;
/*			case 15:
				printf("Sort list - Descending operation");
				printf("\nEnter list number to sort");
				scanf("%d", &ln);
				res=sortdec(lla, ln);
				if(res<0)
				{
					printf("\nSorting in descending order operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nSorting in descending order operation successfull");
				break;
			case 16:
				printf("Merge list - US + US = US operation");
				printf("\nEnter first list number to merge");
				scanf("%d", &ln1);
				printf("\nEnter second list number to merge");
				scanf("%d", &ln2);
				printf("\nEnter target list number to merge");
				scanf("%d", &ln3);
				res=mergeuuu(lla, ln1, ln2, ln3);
				if(res<0)
				{
					printf("\nMerge - US + US = US operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nMerge - US + US = US operation successfull");
				break;
			case 17:
				printf("Merge list - US + US = S operation");
				printf("\nEnter first list number to merge");
				scanf("%d", &ln1);
				printf("\nEnter second list number to merge");
				scanf("%d", &ln2);
				printf("\nEnter target list number to merge");
				scanf("%d", &ln3);
				res=mergeuus(lla, ln1, ln2, ln3);
				if(res<0)
				{
					printf("\nMerge - US + US = S operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nMerge - US + US = S operation successfull");
				break;
			case 18:
				printf("Merge list - S + S = S operation");
				printf("\nEnter first list number to merge");
				scanf("%d", &ln1);
				printf("\nEnter second list number to merge");
				scanf("%d", &ln2);
				printf("\nEnter target list number to merge");
				scanf("%d", &ln3);
				res=mergesss(lla, ln1, ln2, ln3);
				if(res<0)
				{
					printf("\nMerge - S + S = S operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nMerge - S + S = S operation successfull");
				break;
			case 19:
				printf("Clone list operation");
				printf("\nEnter Soure list number");
				scanf("%d", &ln1);
				printf("\nEnter target list number");
				scanf("%d", &ln2);
				res=clone(lla, ln1, ln2);
				if(res<0)
				{
					printf("\nClone list operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nClone list operation successfull");
				break;
			case 20:
				printf("Intersection operation");
				printf("\nEnter 1st list number");
				scanf("%d", &ln1);
				printf("\nEnter 2nd list number");
				scanf("%d", &ln2);
				printf("\nEnter target list number");
				scanf("%d", &ln3);
				res=intersection(lla, ln1, ln2, ln3);
				if(res<0)
				{
					printf("\nIntersection operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nIntersection operation successfull");
				break;
			case 21:
				printf("Union operation");
				printf("\nEnter 1st list number");
				scanf("%d", &ln1);
				printf("\nEnter 2nd list number");
				scanf("%d", &ln2);
				printf("\nEnter target list number");
				scanf("%d", &ln3);
				res=uni(lla, ln1, ln2, ln3);
				if(res<0)
				{
					printf("\nUnion operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nUnion operation successfull");
				break;
			case 22:
				printf("Erase operation");
				printf("\nEnter list number");
				scanf("%d", &ln);
				res=erase(lla, ln);
				if(res<0)
				{
					printf("\nErase operation failed. ");
					errorhandler(res);
					break;
				}
				printf("\nErase operation successfull");
				break;
*/		}
		getch();
	}
}