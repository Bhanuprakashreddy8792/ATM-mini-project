#include <stdio.h>
#include <conio.h>
unsigned long amount=100000, deposit, withdraw;
int choice,i,pin, k;
char transaction ='y';
char ch,apin[4];

void main()
{
 while (pin != 1234)
  {
    printf("\t\t\t\t\tENTER YOUR SECRET PIN  : ");

    for(i=0;i<4;i++)
    {
        ch = getch();

        if(ch==4)
        {
            if(i>0){
                i--;
                printf("\b \b");
            }
        }
        else{
        apin[i] = ch;
        ch = '*' ;
        printf("%c",ch);
        }
    }
    apin[i] = ' ';
    printf("\n");
    pin = atoi(apin);
     system("cls");
    if (pin != 1234)
    printf("\t\t\t\t\t\n\nPLEASE ENTER VALID PIN!!!!!!!!!\n");

  }
do
 {   system("color 07");
    printf("\t\t\t\t\t**************** WELCOME TO ATM ******************\n\n");
    printf("\t\t\t\t\t 1. Check Balance\n\n");
    printf("\t\t\t\t\t 2. Withdraw Cash\n\n");
    printf("\t\t\t\t\t 3. Deposit Cash\n\n");
    printf("\t\t\t\t\t 4. Quit\n");
    printf("\t\t\t\t\t**************************************************\n\n\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
 switch (choice)
  {
    case 1:
            system("cls");
		    system("color 01");
			printf("\n\t\t\t\tYOUR BALANCE IN Rs : %lu ", amount);
			break;
    case 2:
            system("cls");
            system("color 02");
			printf("\n\t\t\t\tENTER THE AMOUNT TO WITHDRAW: ");
			scanf("%lu", &withdraw);
			  if (withdraw % 100 != 0)
			  {
				printf("\n\t\t\t\tPLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
              }
			  else if (withdraw >(amount - 500))
			  {
				printf("\n\t\t\t\tINSUFFICENT BALANCE");
			  }
			  else
			  {
				amount = amount - withdraw;
				printf("\t\tprocessing...............................................");
				sleep(2);
				printf("\n\n\t\t\t\t PLEASE COLLECT YOUR CASH\n\n");
				FILE *fr;
                fr = fopen("credited receipt.txt", "w");
                fprintf(fr,"\t\t\t  ****************************************************\n\t\t\t   1265 HIGHWAY\t\tBANK\t\t DATE : %s\n\t\t\t\t\t\t\t\t TIME : %s\n\n\t\t\t  ****************************************************",__DATE__,__TIME__);
                fprintf(fr,"\n\t\t\t\tTRANSACTION         : Withdraw\n\t\t\t\tACCOUNT NUMBER      : XXXX XXXX XXXX 0987\n\t\t\t\tAMOUNT WITHDRAW     : %d\n\t\t\t\tBALANCE             : %d\n\t\t\t  ****************************************************\n\n\t\t\t    *****THANK YOU FOR CHOOSING OUR ATM SERVICE*****\n\n\t\t\t\t\t   ***VISIT AGAIN***",withdraw,amount);
                fclose(fr);
				printf("\n\t\t\t\t YOUR CURRENT BALANCE IS %lu", amount);
			  }
			  break;
   case 3:
            system("cls");
            system("color 03");
			printf("\n\t\t\t\tENTER THE AMOUNT TO DEPOSIT ");
            scanf("\t\t\t\t %lu", &deposit);
            printf("\n\t\tprocessing...............................................\n");
				sleep(2);
                amount = amount + deposit;
                FILE *fr;
                fr = fopen("deposit receipt.txt", "w");
                fprintf(fr,"\t\t\t  ****************************************************\n\t\t\t   1265 HIGHWAY\t\tBANK\t\t DATE : %s\n\t\t\t\t\t\t\t\t TIME : %s\n\n\t\t\t  ****************************************************",__DATE__,__TIME__);
                fprintf(fr,"\n\t\t\t\tTRANSACTION         : Deposit\n\t\t\t\tACCOUNT NUMBER      : XXXX XXXX XXXX 0987\n\t\t\t\tAMOUNT DEPOSIT      : %d\n\t\t\t\tBALANCE             : %d\n\t\t\t  ****************************************************\n\n\t\t\t    *****THANK YOU FOR CHOOSING OUR ATM SERVICE*****\n\n\t\t\t\t\t   ***VISIT AGAIN***",deposit,amount);
                fclose(fr);
                printf("\n\t\t\t\tYOUR BALANCE IS %lu", amount);
			    break;
   case 4:
			printf("\n \t\t\t\tTHANK YOU FOR USING OUR ATM......");
			break;
  default:
			printf("\n \t\t\t\tINVALID CHOICE!!!!");

  }
        printf("\n\n\n\t\t\t\t DO U WISH TO HAVE ANOTHER TRANSCATION?(yes[1]/no[0]): \n");
        fflush(stdin);
        scanf("%c", &transaction);
        if (transaction == '0')
                    k = 1;
 }
	  while (!k);
	 printf("\n\n\t\t\t\t*****THANKS FOR USING OUR ATM SERVICE*****\n\n");
}
