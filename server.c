#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr


struct student
{
    long long int aadhar;
    char name[20];
    char state[15];
    char mail[20];
    char mobile[12];
    char branch[20];
    float marks ;

};
void func(int connfd)
{
	char buff[MAX];
	int n;
	int size ;
	 FILE *fp,*ft;
	struct student std,stud ;
		bzero(buff, MAX);
		__fpurge(stdin);
		// read the message from client and copy it in buffer
		read(connfd, buff, sizeof(buff));
		// print buffer which contains the client contents
		printf(" %s\n ", buff);
		bzero(buff, MAX);
		
		char abc[60]="enter your name ";
		write(connfd, abc, sizeof(abc));

		bzero(buff, MAX);



		// read the message from client and copy it in buffer
		read(connfd, buff, sizeof(buff));
		// print buffer which contains the client contents
		strcpy(stud.name , buff);
		stud.name[strlen(stud.name)-1]='\0';
		bzero(buff, MAX);
		
		 char bcd[60]="enter your state ";
		write(connfd, bcd, sizeof(bcd));
		__fpurge(stdin);



		// read the message from client and copy it in buffer
		read(connfd, buff, sizeof(buff));
		// print buffer which contains the client contents
		strcpy(stud.state , buff);
		stud.state[strlen(stud.state)-1]='\0';
		bzero(buff, MAX);
		
		char cde[60]="enter your mail  ";
		write(connfd, cde, sizeof(cde));



		// read the message from client and copy it in buffer
		read(connfd, buff, sizeof(buff));
		// print buffer which contains the client contents
		strcpy(stud.mail , buff);
		stud.mail[strlen(stud.mail)-1]='\0';
		bzero(buff, MAX);
		__fpurge(stdin);
		char def[60]="enter your mobile no . ";
		write(connfd, def, sizeof(def)) ;
		__fpurge(stdin);


		// read the message from client and copy it in buffer
		read(connfd, buff, sizeof(buff));
		// print buffer which contains the client contents
		strcpy(stud.mobile , buff);
		stud.mobile[strlen(stud.mobile)-1]='\0';
		bzero(buff, MAX);
		__fpurge(stdin);
		char efg[60]="enter your branch  ";
		write(connfd, efg, sizeof(efg)) ;


		// read the message from client and copy it in buffer
		read(connfd, buff, sizeof(buff));
		// print buffer which contains the client contents
		strcpy(stud.branch , buff);
		stud.branch[strlen(stud.branch)-1]='\0';
		bzero(buff, MAX);
		int i=1 ;
		

		 fp = fopen("mp.txt","ab+");
    if(fp == NULL)
    {
        printf("Error opening file mp");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        printf("Error opening file temp");
        exit(1);
    }
    int flag=0 ;
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(std.marks>stud.marks)
        {
            fwrite(&std,sizeof(std),1,ft);
        }
        else
        {
            if(flag==0)
            {
              fwrite(&stud,sizeof(std),1,ft);
              fwrite(&std,sizeof(std),1,ft);
              flag=1 ;
            }
            else
            {
                fwrite(&std,sizeof(std),1,ft);
            }
        }

    }
    if(flag==0)
    {
        fwrite(&stud,sizeof(stud),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("mp.txt");
    rename("temp.txt","mp.txt");

}
int addserver()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("server accept failed...\n");
		exit(0);
	}
	else
		printf("server accept the client...\n");

	// Function for chatting between client and server
	func(connfd);

	// After chatting close the socket
	close(sockfd);
}

void add()
{

    FILE *fp,*ft;
    struct student std , stud;
	 __fpurge(stdin);
    fflush(stdin);
    __fpurge(stdin);


    printf("enter your state :");                       // STATE
    gets(stud.state);
  //  strupr(stud.state);
     __fpurge(stdin);
	
	printf("enter your  name:");                     // aadhar
    gets(stud.name);
  //  strupr(stud.state);
    __fpurge(stdin);


    printf("enter your aadhar number :");
    scanf("%lld",&stud.aadhar);

    __fpurge(stdin);
    printf("enter your email address :");               // EMAIL ADDRESS
    gets(stud.mail);
   // strlwr(stud.mail);
     __fpurge(stdin);
     fflush(stdin);

    printf("enter the branch :");                       // BRANCH
    gets(stud.branch);
   // strupr(stud.branch);
     __fpurge(stdin);

    printf("enter the marks :");                        // MARKS
    scanf("%f",&stud.marks);
    __fpurge(stdin);

    printf("enter mobile number :");                     // MOBILE NUMBER
    gets(stud.mobile);
     __fpurge(stdin);

    fp = fopen("mp.txt","ab+");
    if(fp == NULL)
    {
        printf("Error opening file mp");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        printf("Error opening file temp");
        exit(1);
    }
    int flag=0 ;
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(std.marks>stud.marks)
        {
            fwrite(&std,sizeof(std),1,ft);
        }
        else
        {
            if(flag==0)
            {
              fwrite(&stud,sizeof(std),1,ft);
              fwrite(&std,sizeof(std),1,ft);
              flag=1 ;
            }
            else
            {
                fwrite(&std,sizeof(std),1,ft);
            }
        }

    }
    if(flag==0)
    {
        fwrite(&stud,sizeof(stud),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("mp.txt");
    rename("temp.txt","mp.txt");

}
void view()
{
     system("cls");
    FILE *fp;
    int i=1 ;
    struct student std;
    fp = fopen("mp.txt","rb+");
    if(fp == NULL){
        printf("Error opening file.");
        return ;
    }
    printf("\n\n\n\tS.No   Name of Student          Marks      Mobile No              state           Branch\n");
    printf("\t----------------------------------------------------------------------------------------\n");

    while(fread(&std,sizeof(std),1,fp) == 1)
    {

       printf("\t%-7d %-22s    %-20s %-18s %-13s\n\n",i,std.name  , std.mobile,std.state,std.branch);
	//    printf("%-7d a%-22sa %0.2f\t   b%-20sb c%-18sc d%-13sd\n\n",i,std.name ,std.marks , std.mobile,std.state,std.branch);

	/*	printf("a%sa %d\n",std.name,strlen(std.name));
		printf("a%sa%d\n",std.mobile,strlen(std.mobile));
		printf("a%sa%d\n",std.branch ,strlen(std.branch));
		printf("a%sa%d\n",std.state ,strlen(std.state));*/
        i++;
    }
    fclose(fp);


}
void searchbyname()
{
    FILE *fp;
    struct student std;
    char stname[20];
__fpurge(stdin);

    printf("<--:SEARCH RECORD:-->");
    printf("Enter name of student : ");
    fflush(stdin);
	__fpurge(stdin);

    gets(stname);
 //   strupr(stname);
    fp = fopen("mp.txt","rb+");
    if(fp == NULL)
    {

        printf("Error opening file");
        return ;
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0)
        {

            printf("Name : %s\n",std.name);

            printf("Mobile Number : %s\n\n",std.mobile);

            printf("E-mail : %s\n\n",std.mail);

            printf("State : %s\n\n",std.state);

            printf("Branch : %s\n\n",std.branch);

            printf("aadhar number :",std.aadhar);

             printf("Marks : %f\n\n",std.marks);

        }
    }
    fclose(fp);
}
void searchbybranch()
{
        FILE *fp;
        int i=1;
    struct student std;
    char stbranch[20];
    //printf("<--:SEARCH RECORD:-->");
    printf("Enter branch of student : ");
    fflush(stdin);
    gets(stbranch);
   // strupr(stbranch);
    printf("%s\n",stbranch);
    fp = fopen("mp.txt","rb+");
    if(fp == NULL)
    {

        printf("Error opening file");
        return ;
    }
     printf("S.No   Name of Student          Marks      Mobile No              state           Branch\n");
    printf("----------------------------------------------------------------------------------------\n");
     while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stbranch,std.branch) == 0)
        {
           //  printf("%-7d a%-22sa %0.2f\t   b%-20sb c%-18sc d%-13sd\n\n",i,std.name ,std.marks , std.mobile,std.state,std.branch);
		printf("a%sa\n",std.name);
		printf("a%sa\n",std.mobile);
		
        i++;
        }
     }
    fclose(fp);

}
void searchbystate()
{
     FILE *fp;
        int i=1;
    struct student std;
    char ststate[20];
	__fpurge(stdin);
    //printf("<--:SEARCH RECORD:-->");
    printf("Enter state of student : ");
    fflush(stdin);
	__fpurge(stdin);
    gets(ststate);
  //  strupr(ststate);
    fflush(stdin);
    fp = fopen("mp.txt","rb+");
    if(fp == NULL)
    {

        printf("Error opening file");
        return ;
    }
     printf("S.No   Name of Student          Marks      Mobile No              state           Branch\n");
    printf("----------------------------------------------------------------------------------------\n");
     while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(ststate,std.state) == 0)
        {
             printf("%-7d %-22s %0.2f\t   %-20s %-18s %-13s\n\n",i,std.name ,std.marks , std.mobile,std.state,std.branch);
             i++;
        }
     }
    fclose(fp);

}
void searchbymo()
{
     FILE *fp;
    struct student std;
    char stname[20];
   // printf("<--:SEARCH RECORD:-->");
	__fpurge(stdin);
    printf("Enter mobile number of student : ");
    fflush(stdin);
	__fpurge(stdin);
    gets(stname);
    fp = fopen("mp.txt","rb+");
    if(fp == NULL)
    {

        printf("Error opening file");
        return ;
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.mobile) == 0)
        {

            printf("Name : %s\n",std.name);

            printf("Mobile Number : %s\n\n",std.mobile);

            printf("E-mail : %s\n\n",std.mail);

            printf("State : %s\n\n",std.state);


            printf("Branch : %s\n\n",std.branch);

            printf("aadhar number :",std.aadhar);

            printf("Marks : %f\n\n",std.marks);

        }
    }
    fclose(fp);
}
void searchbyemail()
{
     FILE *fp;
    struct student std;
    char stname[20];
   // printf("<--:SEARCH RECORD:-->");
    printf("Enter Emails number of student : ");
    fflush(stdin);
    gets(stname);
 //   strlwr(stname);
    fflush(stdin);
    fp = fopen("mp.txt","rb+");
    if(fp == NULL)
    {

        printf("Error opening file");
        return ;
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.mail) == 0)
        {

            printf("Name : %s\n",std.name);

            printf("Mobile Number : %s\n\n",std.mobile);

            printf("E-mail : %s\n\n",std.mail);

            printf("aadhar number :",std.aadhar);

            printf("State : %s\n\n",std.state);

            printf("Branch : %s\n\n",std.branch);

            printf("Marks : %f\n\n",std.marks);

        }
    }
    fclose(fp);

}
void searchbyaadhar()
{
    FILE *fp;
    struct student std;
    long long int num ;
    printf("Enter aadhar umber of student : ");
    fp = fopen("mp.txt","rb+");
    if(fp == NULL)
    {

        printf("Error opening file");
        return ;
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(std.aadhar == num)
        {

            printf("Name : %s\n",std.name);

            printf("Mobile Number : %s\n\n",std.mobile);

            printf("E-mail : %s\n\n",std.mail);

            printf("aadhar number :",std.aadhar);

            printf("State : %s\n\n",std.state);

            printf("Branch : %s\n\n",std.branch);

            printf("Marks : %f\n\n",std.marks);

        }
    }
    fclose(fp);
}
void personal()
{
    int ch;
    printf("1.Name\n2.Mobile no\n3.Email\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:searchbyname();
                break;
        case 2:searchbymo();
                break;
        case 3:searchbyemail();
                break;

        case 4 : searchbyaadhar();
        default: printf("Enter correct choice:");
                break;
    }
}
void search()
{
    system("cls");
    int ch;
    printf("\n\n\n\t1.Personal Information\n\n\t2.Branch\n\n\t3.State\n\n\tEnter your Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        personal();
        break;
    case 2:
        searchbybranch();
        break;
    case 3:
        searchbystate();
        break;
    default:printf("Enter correct choice\n");
    break;
    }
}
void modify()
{

}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    printf("<--:DELETE RECORD:-->");
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("mp.txt","rb+");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("mp.txt");
    rename("temp.txt","mp.txt");
}
void menu()
{
    while(1)
    {

        int choice;
        printf("\n\n\n\t-------------------------:MENU:-----------------------");
        printf("\n\n\n\tEnter  number to perform following task.");
        printf("\n\n\t1 : Add Record.");
        printf("\n\n\t2 : View Record.");
        printf("\n\n\t3 : Search Record.");
        printf("\n\n\t4 : Modify Record.");
        printf("\n\n\t5 : Delete.");
        printf("\n\n\t6 : Exit.");
        printf("\n\n\tEnter your choice.");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            add();
            break;

        case 2:
            view();
            break;

        case 3:
            search();
            break;

        case 4:
            modify();
            break;

        case 5:
            deleterec();
            break;

        case 6:
            exit(1);
            break;
	case 7:
	    addserver();
        default:

            printf("Invalid Choice.");
        }
    }
}

int main()
{


    printf("hiiiiiii");
    menu();
}
