#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
int *airplanes = NULL;
int size;
int flight_no[12];
string dest[20];
float dtime[10]; //departure time
float atime[10]; // arrival time
float ltime[10]; //landing time
int a;
float air;
float ground;

void menu()
{
    printf("Airport Menu Options \n");
    printf("\n1 = Enter Flight Information \n" );
    printf("2 = Display Flight Information \n");
    printf("3 = Display Runway Status \n\n");
    printf("0 = quit\n\n");
}

void flightinformation()
{
int a;
   printf("How many Flight Information you would like to key in : \n);
   scanf("%d",&size);
   float *airplanes[size];

	for(a = 0; a < size; a++)
	{
		printf("Enter Flight Information for %d\n\n",airplanes[a]);
		printf("Flight Number = %d\n",flight_no[a]);
		printf("Destination = %s\n",dest[a]);
       		
		 printf("Departure Time (in 24 Hours Mode) \n");
      		 scanf("%f",&dtime[a]);

			if(dtime[a]<0000 || dtime[a] >2400)
			{
       				printf("Error!\n");
			}
      
		 printf("Arrival Time (in 24 Hours Mode) \n");
      		 scanf("%f",&atime[a]);

			if(atime[a]<0000 || atime[a] >2400)
			{
			           printf("Error!\n\n");
			}
	}

//delete []airplanes;      
}

void displayflightinfo()
{
int i,a=1;

	for(i=0;i<size;i++,a++)
	{
		printf("\n**********# %d**********\n",a);
		printf("\n%d\n",airplanes[i]);
		printf("FLIGHT NUMBER = %d\n",flight_no[i]);
		printf("DESTINATION = %d\n",dest[i]);
		printf("ARRIVAL TIME = %d\n",atime[i]);
		printf("DEPARTURE TIME = %d\n",dtime[i]);
	}
}

void displayrunwaystatus(void)
{
     cout <<"Enter a Plane number to check its status" <<endl;
     int j;
     cout <<"Plane ";
     cin  >>j;
	for(int i=1;i >= atime[j];i++)
	{
             		air = air + 1;
             		ltime[j] = atime[j] + (exp(1.5));
             		cout << "Landing Time : " << ltime[j] <<endl;

			if(i==ltime[j])
			{
                   			cout << "Runway is occupied" << endl;
			}

			if(i>=ltime[j])
			{
                    			air = air - 1;
                    			ground = ground + 1;

				if(air > 0)
				{
                           				ltime[j] = i + exp(1.5);
				}
			
				else
                   				 cout << "Runway is free" <<endl;
                    				 ltime[j] = atime[j] + exp(1.5);  
			} 
	}

}

int main()
{

int a; 
 
do
{
        cout <<endl;
        menu();
        cin >> a;
        cout <<endl;

switch(a)
{
	case 1: 
		flightinformation();
		break;

	case 2: 
		displayflightinfo();
		break;

	case 3: 
		displayrunwaystatus();
		break;
}
}while (a!= 0);       
return 0;
}
/*
functions converted to c
1.menu
2.displayflightinfo

remaining
1.flightinformation
2.displayrunwaystatus

*/