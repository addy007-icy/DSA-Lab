#include<stdio.h>
#include<string.h>

int x=0;
struct Item
{
	char itemName[20];
	int itemCode;
	float price;
	int QtyInStock;
	int IsHighDemand;
	int SoldToday;
}Item;

struct Item item_list[100];
int addItems() 
{
	char itemName1[20];
	int itemCode1;
	float price1;
	int QtyInStock1;
	int IsHighDemand1;
	int SoldToday1;
	printf("Enter Itemname followed by itemCode price QtyInStock IsHighDemand SoldToday\n" );
	scanf("%[^\n]%*c",itemName1);	
	scanf("%d %f %d %d %d",&itemCode1,&price1,&QtyInStock1,&IsHighDemand1,&SoldToday1);

	strcpy(item_list[x].itemName,itemName1);//char *strcpy(char *dest, char *src);
	item_list[x].itemCode = itemCode1;
	item_list[x].price = price1;
	item_list[x].QtyInStock = QtyInStock1;
	item_list[x].IsHighDemand = IsHighDemand1;
	item_list[x].SoldToday = SoldToday1;
	return ++x;
}
void update_price()
{
	int itemcode;
	float updated_price;
	printf(" :: Enter Item code and Updated price" );
	scanf("%d %f",&itemcode,&updated_price);
	int i;
	for(i = 0;i<x ; i++)
	{
		if(item_list[i].itemCode==itemcode)
		{
			item_list[i].price = updated_price;
			return;
		}
	}

}

void update_stock()
{
	int item_code;
	printf(" :: Enter Item code and Updated stock" );
	float updated_stock;
	scanf("%d %f",&item_code,&updated_stock);
	int i;
	for(i=0;i<x;i++)
	{
		if(item_list[i].itemCode==item_code)
		{
			item_list[i].QtyInStock = updated_stock;
			return;
		}
	}

}
void show()
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("%s %f\n",item_list[i].itemName,item_list[i].price );
	}
}
void sell()
{
	int i;
	int item_code;
	scanf("%d",&item_code);
	for(i=0;i<x;i++)
	{
		if(item_list[i].itemCode==item_code)
		{
			item_list[i].QtyInStock--;
			item_list[i].SoldToday=1;
			return;
		}
	}
}

int main()
{
	
	x = addItems();
	printf("update_price\n" );
	update_price();
	printf("update_stock\n" );
	update_stock();
	printf("show\n" );
	show();
	printf("sell\n" );
	sell();
	return 0;
}