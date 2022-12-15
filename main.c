#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct items
{
    char item[20];
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date [50];
    int numOfItems;
    struct items itm[50];

};
//Function to Generate biils
void generateBillHeder(char name[40],char date [30])
{
    printf("\n\n\n");
    printf("\n========================================\n");
    printf("\t Green University(Caffe)");
    printf("\n========================================");
    printf("\nDate:%s",date);
    printf("\nInvoice To: %s",name);
    printf("\n");
    printf("----------------------------------------\n");
    printf("Items\t\t");
    printf("qty\t\t");
    printf("Total");
    printf("\n----------------------------------------");
    printf("\n\n");
}
void generateBillBody(char item[30],int qty, float price)
{
    printf("%s\t\t",item);
    printf("%d\t\t",qty);
    printf("%2.2f\t\t",qty * price);
    printf("\n");
}

void generateBillFooter(float total)
{
    printf("\n");
    //10% discount
    float dis = 0.1*total;

    float netTotal=total-dis;
    //VAT = The government has proposed 5% tax for the restaurant sector in the national budget for FY23

    float vat =0.05*netTotal,grandTotal= netTotal + vat; //netTotal + VAT
    printf("----------------------------------------\n");
    printf("Sub total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\----------------");
    printf("\nNet Total \t\t\t%2.f",netTotal);
    printf("\nVAT @5%s\t\t\t\t%.2f","%",vat);
    printf("\n----------------------------------------");
    printf("\nGrand Total \t\t\t%.2f",grandTotal);
    printf("\n----------------------------------------\n");
}

int main()
{
    int opt, n;
    float total;
    struct orders ord;
    //Main Dashboard
    printf("========== Green University(Caffe) ==========");
    printf("\n\nSelect Your Preferred operation");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Show all Invoices");
    printf("\n3.Search Invoices");
    printf("\n4.Exit");

    printf("\n\nYour choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);
    switch(opt)
    {
    case 1:
        printf("\nEnter the name of Customer:\t");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1]=0;
        strcpy(ord.date,__DATE__);
        printf("\nEnter the number of items:\t");
        scanf("%d",&n);
        ord.numOfItems = n;
        for (int i=0; i<n; i++)
        {
            fgetc(stdin);
            printf("\n\n");
            printf("Enter name of %d Items:\t",i+1);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("Enter the quantity:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("Enter the unit price:\t");
            scanf("%f",&ord.itm[i].price);
            total += ord.itm[i].qty*ord.itm[i].price;
        }
        generateBillHeder(ord.customer,ord.date);
        for (int i=0; i<ord.numOfItems; i++)
        {
            generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        }
        generateBillFooter(total);
    }

    printf("\n\n\n\n\n");



    return 0;

}
