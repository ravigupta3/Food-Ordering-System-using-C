
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct details {
    char uname[100];
    int age;
    char pword[100];
    char email[100];
    char mno[10];
};

struct hotels 
{
    char hotel[100];
    char food1[20];
    char food2[20];
    char food3[20];
    int cost1, cost2, cost3;
};

struct hotels m[5];
struct details s[4];

void hotels(); 
void admin();
void signup();
void accountcheck();
int validatename();
int validateage();
int validateemail();
int validatepword();
int validatemno();
void login();
void cart();
void search_by_hotels();
void search_by_food();
void food_order(int food);
void hotel_initialize();
void hotels(int hotel_choice, int choice_again);

int flag = 1, i, j, count = 0, caps = 0;
int small = 0, special = 0, numbers = 0;
int success = 0, x=0, x1=0, x2=0, x3=0, x4=0, x5=0, choice;
char tname[100], tpword1[100];
char temail[100];
char tmno[100];
int tage, total = 0, food_choice, n;
int hotel_choice, search_choice, confirm, choose_again;
int ch, food, hotel_id;
char temp_hname[100], temp_f1[20], temp_f2[20], temp_f3[20];
int  temp_c1, temp_c2, temp_c3;  

void hotel_initialize()
{
  
    strcpy(m[1].hotel, "Anand_Bhavan");
    strcpy(m[1].food1, "Pasta");
    strcpy(m[1].food2, "Fried_Rice");
    strcpy(m[1].food3, "Chopsuey");
    m[1].cost1 = 70;
    m[1].cost2 = 100;
    m[1].cost3 = 95;
  

    strcpy(m[2].hotel, "Kamal_Hotel");
    strcpy(m[2].food1, "Chappati");
    strcpy(m[2].food2, "Noodles");
    strcpy(m[2].food3, "Paneer_Dosa");
    m[2].cost1 = 15;
    m[2].cost2 = 75;
    m[2].cost3 = 80;
  
  
    strcpy(m[3].hotel, "Raj_Bistro");
    strcpy(m[3].food1, "Biriyani");
    strcpy(m[3].food2, "Lobster");
    strcpy(m[3].food3, "Jalebi");
    m[3].cost1 = 90;
    m[3].cost2 = 120;
    m[3].cost3 = 35;
}
void admin() 
{
    int i,choice,choice1,c1,c2,c3,index;
    char temp_hname[100], temp_f1[20], temp_f2[20], temp_f3[20];
    hotel_initialize();
    printf("\n\nWelcome to Admin");
    printf("\n\n1)Add a Hotel\n");
    printf("2)Remove a Hotel \n3)update \n4)exit\n\n");
    printf("Enter your choice\t");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("Hotel Name: ");
        scanf(" %s",temp_hname);
           
        printf("First food: " );
        scanf(" %s",temp_f1);
          
        printf("Cost: ");
        scanf(" %d",&c1);
        
        printf("Second food: " );
        scanf(" %s",temp_f2);
          
        printf("Cost: ");
        scanf(" %d",&c2);
        
        printf("Third food: " );
        scanf(" %s",temp_f3);
          
        printf("Cost: ");
        scanf(" %d",&c3);
           
        strcpy(m[4].hotel, temp_hname);
        strcpy(m[4].food1, temp_f1);
        strcpy(m[4].food2, temp_f2);
        strcpy(m[4].food3, temp_f3);   
	m[4].cost1 = c1;
    	m[4].cost2 = c2;
        m[4].cost3 =c3;
        printf("the new database :\n");
        for(i=1;i<=4;i++)
        {
            printf("hotel %d %s\n", i,m[i].hotel);
            printf("food 1 %s\n", m[i].food1);
            printf("cost 1 %d\n", m[i].cost1);
            printf("food 2 %s\n", m[i].food2);
            printf("cost 2 %d\n", m[i].cost2);
            printf("food 3 %s\n", m[i].food3);
            printf("cost 3 %d\n", m[i].cost3);
        }
        break;
    case 2:
        printf("enter the index of the hotel to be deleted\n");
        scanf("%d",&index);
        for(i=index;i<=3;i++)
        {
            strcpy(m[i].hotel, m[i+1].hotel);
            strcpy(m[i].food1, m[i+1].food1);
            strcpy(m[i].food2,m[i+1].food2);
            strcpy(m[i].food3, m[i+1].food3);
            m[i].cost1=m[i+1].cost1;
            m[i].cost2=m[i+1].cost2;
            m[i].cost3=m[i+1].cost3;
        }
        printf("the new database :\n");
        for(i=1;i<=2;i++)
        {
            printf("hotel %d %s\n", i,m[i].hotel);
            printf("food 1 %s\n", m[i].food1);
            printf("cost 1 %d\n", m[i].cost1);
            printf("food 2 %s\n", m[i].food2);
            printf("cost 2 %d\n", m[i].cost2);
            printf("food 3 %s\n", m[i].food3);
            printf("cost 3 %d\n", m[i].cost3);
        }
        break;
    case 3:
        printf("enter you choice\n");
        printf("1) hotel updation\n");
        printf("2) menu updation\n");
        printf("3) cost updation\n");
        scanf("%d",&choice1);
        switch(choice1)
        {
            case 1: printf("enter index of hotel change:");
                    scanf("%d",&index);
                    printf("perform hotel change\n");
                    scanf(" %s",m[index].hotel);
                    break;
            case 2: printf("enter index of menu change:");
                    scanf("%d",&index);
                    printf("perform menu change\n");
                    scanf(" %s",m[index].food1);
                    scanf(" %s",m[index].food2);
                    scanf(" %s",m[index].food3);
                    break;
            case 3: printf("enter index of cost change:");
                    scanf("%d",&index);
                    printf("perform cost change\n");
                    scanf("%d",&m[index].cost1);
                    scanf("%d",&m[index].cost2);
                    scanf("%d",&m[index].cost3);
                    break;
            default:printf("invalid choice inputed\n");
        }
        printf("the new database :\n");
        for(i=1;i<=3;i++)
        {
            printf("hotel %d %s\n", i,m[i].hotel);
            printf("food 1 %s\n", m[i].food1);
            printf("cost 1 %d\n", m[i].cost1);
            printf("food 2 %s\n", m[i].food2);
            printf("cost 2 %d\n", m[i].cost2);
            printf("food 3 %s\n", m[i].food3);
            printf("cost 3 %d\n", m[i].cost3);
        }
        break;
    case 4:exit(1);
    default:printf("invalid choice inputed\n");
    }
}

int main()
{
    strcpy(s[0].email,"ram@gmail.com");
    strcpy(s[0].pword,"RRrr!!11");
    strcpy(s[0].uname,"Ram");
    strcpy(s[0].mno,"1010101010");
    s[0].age=50;
    
    strcpy(s[1].email,"sam@gmail.com");
    strcpy(s[1].pword,"SSss@@22");
    strcpy(s[1].uname,"Sam");
    strcpy(s[1].mno,"2020202020");
    s[1].age=60;
    
    strcpy(s[2].email,"arun@gmail.com");
    strcpy(s[2].pword,"AAaa##33");
    strcpy(s[2].uname,"Arun");
    strcpy(s[2].mno,"3030303030");
    s[2].age=70;
    
    while(1)
    {
        choice=0;
        printf("Welcome to Food Ordering System\n");
        printf("1)SIGNUP\n");
        printf("2)LOGIN\n");
	printf("3)ADMIN\n");
	printf("4)Exit\n");
        printf("Enter your option: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            signup();
            break;
        }
        case 2: {
            login();
            break;
        }
         case 3: {
    
            admin();
            break;
        }
        case 4: {
    
            return 0;
        }
        default: {
            printf("\nPlease Enter a Valid option!\n\n");
            break;
        }
        }
    }
}

void signup()
{
    printf("\nSign-In\n\n");
    while(x1!=1)
    {
    printf("Enter Your name: ");
    scanf("%s", tname);
    x1 = validatename();
    }
    while(x2!=1)
    {
    printf("Enter Your Age: ");
    scanf("%d", &tage);
    x2 = validateage();
    }
    while(x4!=1)
    {
    printf("Enter Your Email: ");
    scanf("%s", temail);
    x4 = validateemail();
    }
    while(x3!=1)
    {
    printf("Enter Password: ");
    scanf("%s", tpword1);
    x3 = validatepword();
    }
    while(x5!=1)
    {
    printf("Enter Your Mobile Number: ");
    scanf("%s", tmno);
    x5 = validatemno();
    }
    accountcheck();
}

int validatename()
{
    for (i = 0; tname[i] != '\0'; i++) 
    {
        if (!((tname[i] >= 'a' && tname[i] <= 'z')|| (tname[i] >= 'A'&& tname[i] <= 'Z'))) 
        {
            printf("\nPlease Enter a Valid Name!\n\n");
            flag = 0;
            break;
        }
    }
    if(flag==0)
        return 0;
    else
        return 1;
}

int validateage()
{
    if (tage != 0 && tage > 0)
        return 1;
    else
    {
        printf("\nPlease Enter a Valid Age!\n\n");
        return 0;
    }
}

int validatepword()
{
    caps=0;
    small=0;
    numbers=0;
    special=0;
    if ((strlen(tpword1)>=8)&&(strlen(tpword1)<=12))
    {
        for (i=0;tpword1[i]!='\0';i++)
        {
            if (tpword1[i] >= 'A'&& tpword1[i] <= 'Z')
                caps++;
            else if (tpword1[i] >= 'a'&& tpword1[i]<= 'z')
                small++;
            else if (tpword1[i] >= '0'&& tpword1[i]<= '9')
                numbers++;
            else if (tpword1[i] == '@'|| tpword1[i] == '&'|| tpword1[i] == '#'|| tpword1[i]== '*'|| tpword1[i]== '!'|| tpword1[i]=='$'|| tpword1[i]=='%'|| tpword1[i]=='&')
                special++;
        }
        if (caps >= 1 && small >= 1&& numbers >= 1 && special >= 1)
        {
            return 1;
        }
        else
        {
            printf("\nPlease Enter a Valid Password with 8-12 characters and with atleast one uppercase, lowercase, number and a special character!\n\n");
            return 0;
        }
    }
    else
    {
        printf("\nPlease Enter a Valid Password with 8-12 characters and with atleast one uppercase, lowercase, number and a special character!\n\n");
        return 0;
    }
}

int validateemail()
{
    for (i=0;temail[i]!='\0';i++)
    {
        if (temail[i]=='@'||temail[i]=='.')
            count++;
    }
    if (count >= 2 && strlen(temail) >= 5) 
    {
        return 1;
    }
    else 
    {
        printf("\nPlease Enter a Valid Email!\n\n");
        return 0;
    }
}

int validatemno()
{
    if (strlen(tmno) == 10) 
    {
        for (i=0;i<10;i++) 
        {
            if (tmno[i]>='0'&&tmno[i]<='9')
            {
                return 1;
            }
            else 
            {
                printf("\n\nPlease Enter a Valid Mobile Number!\n\n");
                return 0;
            }
        }
    }
    else
    {
        printf("\nPlease Enter a Valid Mobile Number with 10 digits!\n\n");
        return 0;   
    }
}

void accountcheck()
{
    for (i=0;i<3;i++) 
    {
        if (!(strcmp(temail, s[i].email) || strcmp(tpword1,s[i].pword)))
        {
            printf("\nAccount Already exists. Please Login!\n\n");
            login();
            break;
        }
    }
    if (i == 3) 
    {
        strcpy(s[i].uname, tname);
        s[i].age = tage;
        strcpy(s[i].pword, tpword1);
        strcpy(s[i].email, temail);
        strcpy(s[i].mno, tmno);
        printf("\nAccount created!\n\n");
        
        printf("1)Search By Hotels\n");
        printf("2)Search by Food\n");
        printf("3)Exit\n");
        printf("Please enter your choice: ");
            
        scanf("%d", &search_choice);
        switch (search_choice)
        {
            case 1:
            {
                search_by_hotels();
                break;
            }
            case 2:
            {
                search_by_food();
                break;
            }
            case 3:
            {
                   return;
            }
            default:
            {
                printf("\nPlease Enter a Valid Choice!\n\n");
                break;
            }
        }
    }
}
 
void login()
{
    printf("\nLOGIN\n\n");
    printf("Enter Your Email: ");
    scanf("%s", temail);
    printf("Enter Your Password: ");
    scanf("%s", tpword1);
    for (i = 0; i < 4; i++)
    {
        if (!(strcmp(s[i].email, temail)||strcmp(s[i].pword,tpword1)))
        {
            printf("\nYou have successfully logged in!\n\n");
            while(1)
            {
            printf("1)Search By Hotels\n");
            printf("2)Search by Food\n");
            printf("3)Exit\n");
            printf("Please enter your choice: ");
            
            scanf("%d", &search_choice);
            switch (search_choice)
            {
                case 1:
                {
                    search_by_hotels();
                    break;
                }
                case 2:
                {
                    search_by_food();
                    break;
                }
                case 3:
                {
                       return;
                }
                default:
                {
                    printf("\nPlease Enter a Valid Choice!\n\n");
                    break;
                }
            }
            }
        }
        else if(i==3)
        {
            printf("\nAccount does not exist. Please Sign-In!\n\n"); 
            main();
            break;
        }
    }
}

void search_by_food()
{
    total = 0;
    hotel_initialize();
    while (1) {
        printf("\n\nPlease choose the ");
        printf("food\n\n1) %s\t%d\n2) %s\t%d",
               m[1].food1, m[1].cost1,
               m[1].food2, m[1].cost2);
  
        printf("\n3) %s\t%d\n4) %s\t%d\n",
               m[1].food3, m[1].cost3,
               m[2].food1, m[2].cost1);
  
        printf("5) %s\t%d\n6) %s\t%d\n",
               m[2].food2, m[2].cost2,
               m[2].food3, m[2].cost3);
  
        printf("7) %s\t%d\n8) %s\t%d\n",
               m[3].food1, m[3].cost1,
               m[3].food2, m[3].cost2);
  
        printf("9) %s\t%d\n10) Cart\n",
               m[3].food3,
               m[3].cost3);
        printf("11) Exit");
        printf("\nPlease Enter Your Choice\t");
        scanf("%d", &food);
        if (food > 10 && food!=11) {
            printf("Please Enter the ");
            printf("valid choice\n\n");
            search_by_food();
        }
        else if (food == 10)
            cart();
        else if (food == 11)
            exit(1);
 
        else
            food_order(food);
    }
}
  
void food_order(int food)
{
    if (food >= 1 && food <= 3)
        hotel_id = 1;
    else if (food >= 4 && food <= 6)
        hotel_id = 2;
    else
        hotel_id = 3;
    if ((food % 3) == 1) {
        printf("Please Enter the");
        printf(" Count of %s\t",
               m[hotel_id].food1);
        scanf("%d", &n);
        total = total + (n * m[hotel_id].cost1);
    }
    else if ((food % 3) == 2) {
        printf("Please Enter the ");
        printf("Count of %s\t",
               m[hotel_id].food2);
        scanf("%d", &n);
        total = total + (n * m[hotel_id].cost2);
    }
    else if ((food % 3) == 0) {
        printf("Please Enter the ");
        printf("Count of %s\t",
               m[hotel_id].food3);
        scanf("%d", &n);
        total = total + (n * m[hotel_id].cost3);
    }
}


void search_by_hotels()
{
    int choose_again = 1; 
    hotel_initialize(); 
    printf("\nPlease choose your desired Hotel\n\n1) %s\n2) %s\n3) %s", 
           m[1].hotel, 
           m[2].hotel, 
           m[3].hotel); 
    printf("\n4) Exit"); 
    printf("\n\nEnter your choice: ");
    scanf("%d", &hotel_choice);

    if (hotel_choice > 4 || hotel_choice <= 0)  
    {
        printf("\nPlease enter a valid choice\n"); 
        search_by_hotels();
    } 
    else if (hotel_choice == 4) 
    {
        printf("Thank you for using our portal!!"); 
        exit(1);
    }
    else
    {
        hotels(hotel_choice,choose_again);
    }
}

void hotels(int hotel_choice,int choose_again)
{    
    int select,select1; 
    total = 0; 
    
    while (choose_again == 1)
    { 
    printf("The food menu available in %s\n", m[hotel_choice].hotel); 
    printf("1) %s\tRs: %d\n2) %s\tRs: %d\n3) %s\tRs: %d\n\n", 
               m[hotel_choice].food1, 
               m[hotel_choice].cost1, 
               m[hotel_choice].food2, 
               m[hotel_choice].cost2, 
               m[hotel_choice].food3, 
               m[hotel_choice].cost3); 

        printf("To know the cart value, press 4\nTo go back, press 5\n"); 
        scanf("%d", &food_choice); 

        if (food_choice == 1) 
        { 
            printf("Please Enter the quantity of %s: ", m[hotel_choice].food1); 
            scanf("%d", &n); 
            total = total + (n * m[hotel_choice].cost1); 
        }
        else if (food_choice == 2) 
        { 
            printf("Please Enter the quantity of %s: ", m[hotel_choice].food2); 
            scanf("%d", &n); 
            total = total + (n * m[hotel_choice].cost2); 
        } 
        else if (food_choice == 3) 
        { 
            printf("Please Enter the quantity of %s: ", m[hotel_choice].food3); 
            scanf("%d", &n); 
            total = total + (n * m[hotel_choice].cost3);
        } 
        else if (food_choice == 4) 
        {
            if (total == 0)
            { 
                printf("Your cart is empty, Please select some food!\n\n"); 
                printf("Do you want to select? 1. YES, 2. NO\n");
                scanf("%d",&select); 

                if (select != 1)
                {
                    printf("Please press 1. To go back to Hotel list, 2. Exit\n"); 
                    scanf("%d", &select1); 

                    if (select1 == 1) 
                    {
                        search_by_hotels(); 
                        exit(1); 
                    } 
                    else 
                    {
                        printf("Thank you for using  our portal!!"); 
                        exit(1);
                    }
                }
                else if(select==1) 
                {
                    search_by_hotels(); 
                    exit(1); 
                } 
            }

            else
            { 
                printf("\nYour current cart value is: Rs %d\n\n", total);  
            }
        }

        else if (food_choice == 5) 
        {
            search_by_hotels(); 
            exit(1); 
        }
        else 
        {
            printf("Please Enter the valid Choice\n"); 
            scanf("%d", &food_choice);
        }
        printf("\nDo you want to add some more food? 1. YES, 2. NO, 3. To cancel the Order\n"); 
        scanf("%d", &choose_again); 
        
        while(choose_again<0 || choose_again>3)
        {
            printf("Please select the correct option!\n");
            scanf("%d", &choose_again);
        }

        if (choose_again ==2) 
        {
            cart();  
        } 

        if (choose_again == 3)  
        { 
            printf("\nYour order has been cancelled!\n\n"); 
            printf("Do you want to place another order? 1. YES, 2. To exit\n"); 
            scanf("%d", &choose_again); 

            if (choose_again == 1) 
            {
               search_by_hotels(); 
               exit(1); 
            } 

            else 
            {
                printf("Thank you for using Food Ordering System!"); 
                exit(1); 
            }
        }
    }
} 


void cart()
{
    printf("--------------Cart-------------");
    printf("\nYour Total Order ");
    printf("Amount is %d\n", total);
    printf("\n\nDo You wish to order (y=1/n=0): ");
    scanf("%d", &ch);
    if (ch == 1) {
        printf("\n\nThank You for your");
        printf(" order!! Your Food is on the way. Welcome again!!\n\n");
        exit(1);
    }
    else if (ch == 0) {
        printf("Do You want to exit -1\n");
        printf("or Go back -0\t");
        scanf("%d", &confirm);
        if (confirm == 1) {
            printf("\n\n Your order is cancelled!! Exiting..");
            printf("\nThank You visit again!\n");
            exit(1);
        }
        else {
            printf("\n\nThank You\n\n");
            login();
        }
    }
    else {
        printf("\n\nPlease Enter the correct choice\n\n ");
        cart();
    }
}
