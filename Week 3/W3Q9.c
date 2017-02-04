#include<stdio.h>
#include<stdlib.h>

int getMonth(int year,int date){
	int nextmonth = 31;
	if(date<nextmonth){
		return 1;
	}
	nextmonth += 28;
	if(year%4 == 0){
		nextmonth += 1;
	}
	if(date<nextmonth){
		return 2;
	}
	nextmonth += 31;
	if(date<nextmonth){
		return 3;
	}
	nextmonth += 30;
	if(date<nextmonth){
		return 4;
	}
	nextmonth += 31;
	if(date<nextmonth){
		return 5;
	}
	nextmonth += 30;
	if(date<nextmonth){
		return 6;
	}
	nextmonth += 31;
	if(date<nextmonth){
		return 7;
	}
	nextmonth += 31;
	if(date<nextmonth){
		return 8;
	}
	nextmonth += 30;
	if(date<nextmonth){
		return 9;
	}
	nextmonth += 31;
	if(date<nextmonth){
		return 10;
	}
	nextmonth += 30;
	if(date<nextmonth){
		return 11;
	}
	nextmonth += 31;
	if(date<nextmonth){
		return 12;
	}
	return 0;
}

int getDayOfMonth(int year,int date){
	int nextmonth = 31;
	int startmonth = 0;
	if(date<nextmonth){
		return date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 28;
	if(year%4 == 0){
		nextmonth += 1;
	}
	if(date<nextmonth){
		return date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 31;
	if(date<nextmonth){
		return date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 30;
	if(date<nextmonth){
		return date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 31;
	if(date<nextmonth){
		return date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 30;
	if(date<nextmonth){
		return date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 31;
	if(date<nextmonth){
		return date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 31;
	if(date<nextmonth){
		return date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 30;
	if(date<nextmonth){
		return date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 31;
	if(date<nextmonth){
		return  date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 30;
	if(date<nextmonth){
		return  date-startmonth;
	}
	startmonth = nextmonth;
	nextmonth += 31;
	if(date<nextmonth){
		return  date-startmonth;
	}
	return 0;
}

void printDate(int year, int date){
	int diff = year - 1900;
	int dayofweek = -2;
	int i;
	for(i=0;i<diff;i++){
		dayofweek += 1;
		if(i%4 == 0){
			dayofweek += 1;
		}
	}
	dayofweek += date;
	dayofweek = dayofweek%7;
	int month = getMonth(year,date+1);
	int dayofmonth = getDayOfMonth(year,date);
	char *daylist[7];
	daylist[0]="Monday";
	daylist[1]="Tuesday";
	daylist[2]="Wednesday";
	daylist[3]="Thursday";
	daylist[4]="Friday";
	daylist[5]="Saturday";
	daylist[6]="Sunday";
	char *monthlist[12];
	monthlist[0]="January";
	monthlist[1]="February";
	monthlist[2]="March";
	monthlist[3]="April";
	monthlist[4]="May";
	monthlist[5]="June";
	monthlist[6]="July";
	monthlist[7]="August";
	monthlist[8]="September";
	monthlist[9]="October";
	monthlist[10]="November";
	monthlist[11]="December";
	printf("%s %d, %s\n",monthlist[month-1],dayofmonth,daylist[dayofweek]);
}

int main( int argc, char *argv[] ) {
	if(argc != 3){
		printf("Usage: %s <year> <day_of_year>\n",argv[0]);
		return 1;
	}
	int year = atoi(argv[1]);
	int date = atoi(argv[2]);
	printDate(year,date);
	return 0;
}