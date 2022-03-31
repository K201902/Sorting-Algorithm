#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<ctime>
#include<fstream>
using namespace std;
class sortingAlgo
{
	public:
		void insertion (int arr[], int size) // Insertion Sort
		{
			for(int i = 1; i < size; i++)
			{
				int temp = arr[i];
				int j = i - 1;
				while(arr[j] > temp && j >= 0)
				{
					arr[j+1] = arr[j];
					j--;
				}
				arr[j+1] = temp;
			}
		}

		void merge(int arr[], int left, int mid, int right) // Merge Sort
		{ 
		  
		  int size1 = mid - left + 1;
		  int size2 = right - mid;
		  
		  	int L[size1], R[size2];
			for (int i = 0; i < size1; i++)
		  	{
		    	L[i] = arr[left + i];
			}
		  	for (int j = 0; j < size2; j++)
		  	{
		  	    R[j] = arr[mid + 1 + j];
			}
			
			int index1 = 0, index2 = 0;
            int indexmerge = left;
            
		   while (index1 < size1 && index2 < size2) 
		   {
				if (L[index1] <= R[index2]) 
				{
				    arr[indexmerge] = L[index1];
				    index1++;
			    } 
				else 
				{
			      arr[indexmerge] = R[index2];
			      index2++;
			    }
		    indexmerge++;
		   }
		   
			while (index1 < size1) 
			{
			    arr[indexmerge] = L[index1];
			    index1++;
			    indexmerge++;
			}
		
			while (index2 < size2) 
			{
				arr[indexmerge] = R[index2];
			    index2++;
			    indexmerge++;
			}
		}

		void Msort(int arr[], int start, int end) {
		  if (start < end) 
		  {
		    int mid = start + (end - start) / 2;
		    
			Msort(arr, start, mid);
		    Msort(arr, mid + 1, end);
			merge(arr, start, mid, end);
		  }
		}
		
		void swap(int *a, int *b)
		{
			int temp = *a;
			*a = *b;
			*b = temp;
		}

		void quicksortmiddle(int arr[], int low, int high) 
		{

	      	int i = low, j = high;
			int temp;
	
		    int pivot = arr[(low + high) / 2];
		    int mid = (low + high) / 2; // Quick sort using middle as pivot
		    
	      while (i <= j) 
		  {
			while (arr[i] < pivot)
				i++;
	
	        while (arr[j] > pivot)
				j--;
	
	            if (i <= j) 
				{
					swap(&arr[i], &arr[j]);
					i++;
					j--;
	            }
	        }
			if (low < j)
				 quicksortmiddle(arr, low, j);

      		if (i < high)
				quicksortmiddle(arr, i, high);
		}
		
		void quicksortrandom(int arr[], int low, int high) 
		{
			srand (time(0));
	    	int i = low, j = high;
			int temp;
	
		    int pivot;
			do
			{
				pivot = rand(); // Quick Sort using random numbers as pivot
			} while(pivot > high);
			
			pivot = arr[pivot];
		    int mid = (low + high) / 2;
			
			while (i <= j) 
			{
				while (arr[i] < pivot)
				{
					i++;
				}	
	
	            while (arr[j] > pivot)
				{
					j--;
				}	
	
	            if (i <= j) 
				{
					swap(&arr[i], &arr[j]);
	                i++;
	                j--;
	            }
	        }
			
			if (low < j)
				 quicksortmiddle(arr, low, j);

      		if (i < high)
				quicksortmiddle(arr, i, high);
		}
		
		void quicksortmedian(int arr[], int low, int high) // Quick Sort using median as pivot
		{
			int i = low, j = high;
			int temp;
	
		    int pivot; 
		    //Condition to check whether the array has an even length or not
			if((high - low) % 2 == 1)
			{
				pivot = arr[(high - low) + 1 / 2];
			}
			else if((high - low) % 2 == 0)
			{
				pivot = (arr[(high / 2) + 1] + arr[high / 2]) / 2;
			}
			int mid = (low + high) / 2;
			
	      while (i <= j) 
		  {
		  	while (arr[i] < pivot)
				i++;
	
	        while (arr[j] > pivot)
				j--;
	
	            if (i <= j) 
				{
					swap(&arr[i], &arr[j]);
					i++;
					j--;
	            }
	        }
	        if (low < j)
				 quicksortmiddle(arr, low, j);

      		if (i < high)
				quicksortmiddle(arr, i, high);
		}
		
		void quicksortupdatemedian(int arr[], int low, int high) // Quick Sort using updated median as pivot
		{
			int i = low, j = high - 1;
			int temp;
	
		    int pivot; 
		    //Condition to check whether the array has an even length or not
			if((high - low) % 2 == 1)
			{
				pivot = arr[(high - low) + 1 / 2];
			}
			else if((high - low) % 2 == 0)
			{
				pivot = (arr[(high / 2) + 1] + arr[high / 2]) / 2;
			}
			int mid = (low + high) / 2;
			
			if (arr[mid] < arr[low])
			{
				swap (&arr[low], &arr[mid]);
			}
			if (arr[high] < arr[mid])
			{
				swap (&arr[mid], &arr[high]);
				if (arr[mid] < arr[low])
				{
					swap (&arr[mid], &arr[low]);
				}
			}
			
	      while (i <= j) 
		  {
		  	while (arr[i] < pivot)
				i++;
	
	        while (arr[j] > pivot)
				j--;
	
	            if (i <= j) 
				{
					swap(&arr[i], &arr[j]);
					i++;
					j--;
	            }
	        }
	        if (low < j)
				 quicksortmiddle(arr, low, j);

      		if (i < high)
				quicksortmiddle(arr, i, high);
		}
		
		void show(int arr[], int size) 
		{
		  for (int i = 0; i < size; i++)
		    {
			cout <<  "\n " <<  arr[i];
			}
		  cout << endl;
		}
};

int main()
{
	sortingAlgo obj;
	
	ofstream size50, size100, size200, size300, size400, size500, size1000;
	
	size50.open("50 Numbers File.txt");
	size100.open("100 Numbers File.txt");
	size200.open("200 Numbers File.txt");
	size300.open("300 Numbers File.txt");
	size400.open("400 Numbers File.txt");
	size500.open("500 Numbers File.txt");
	size1000.open("1000 Numbers File.txt");
	
	//For calculating time difference
	float timee[7] = {0};
	float start, end;
	
	int arr[50];
	int arr100[100];
	int arr200[200];
	int arr300[300];
	int arr400[400];
	int arr500[500];
	int arr1000[1000];
	
	srand (time(0));
	
	//Storing in the files
	for(int i = 0; i < 50; i++)
	{
		arr[i] = rand();
		size50 << " " << arr[i];
	}
	
	for(int i = 0; i < 100; i++)
	{
		arr100[i] = rand();
		size100 << " " << arr100[i];
	}
	
	for(int i = 0; i < 200; i++)
	{
		arr200[i] = rand();
		size200 << " " << arr200[i];
	}
	
	for(int i = 0; i < 300; i++)
	{
		arr300[i] = rand();
		size300 << " " << arr300[i];
	}
	
	for(int i = 0; i < 400; i++)
	{
		arr400[i] = rand();
		size400 << " " << arr400[i];
	}
	
	for(int i = 0; i < 500; i++)
	{
		arr500[i] = rand();
		size500 << " " << arr500[i];
	}
	
	for(int i = 0; i < 1000; i++)
	{
		arr1000[i] = rand();
		size1000 << " " << arr1000[i];
	}
	
	//Auxiliary arrays
	int aux[50];
	int aux100[100];
	int aux200[200];
	int aux300[300];
	int aux400[400];
	int aux500[500];
	int aux1000[1000];
	
	for(int i = 0; i < 50; i++)
	{
		aux[i] = arr[i];
	}
	
	for(int i = 0; i < 100; i++)
	{
		aux100[i] = arr100[i];
	}
	
	for(int i = 0; i < 200; i++)
	{
		aux200[i] = arr200[i];
	}
	
	for(int i = 0; i < 300; i++)
	{
		aux300[i] = arr300[i];
	}
	
	for(int i = 0; i < 400; i++)
	{
		aux400[i] = arr400[i];
	}
	
	for(int i = 0; i < 500; i++)
	{
		aux500[i] = arr500[i];
	}
	
	for(int i = 0; i < 1000; i++)
	{
		aux1000[i] = arr1000[i];
	}
	
//	For 50 numbers
	start = clock();
	obj.insertion(arr, 50);
	for(int i = 0; i < 50; i++)
	{
		arr[i] = aux[i];
	}
	
	obj.Msort(arr, 0, 50);
	for(int i = 0; i < 50; i++)
	{
		arr[i] = aux[i];
	}
	
	obj.quicksortmiddle(arr, 0, 49);
	for(int i = 0; i < 50; i++)
	{
		arr[i] = aux[i];
	}
	
	obj.quicksortrandom(arr, 0, 49);
	for(int i = 0; i < 50; i++)
	{
		arr[i] = aux[i];
	}
	
	obj.quicksortmedian(arr, 0, 49);
	for(int i = 0; i < 50; i++)
	{
		arr[i] = aux[i];
	}
	obj.quicksortupdatemedian(arr, 0, 49);
	for(int i = 0; i < 50; i++)
	{
		arr[i] = aux[i];
	}
	end = clock();
	cout << endl << endl << "For 50 Numbers" << endl << endl;
	obj.show(arr,50);
	cout << endl << endl << "Time Difference: " << end-start << endl << endl;
	timee[0] = end - start;
	
//	For 100 numbers
	start = clock();
	obj.insertion(arr100, 100);
	for(int i = 0; i < 100; i++)
	{
		arr100[i] = aux100[i];
	}
	
	obj.Msort(arr100, 0, 100);
	for(int i = 0; i < 100; i++)
	{
		arr100[i] = aux100[i];
	}
	
	obj.quicksortmiddle(arr100, 0, 99);
	for(int i = 0; i < 100; i++)
	{
		arr100[i] = aux100[i];
	}
	
	obj.quicksortrandom(arr100, 0, 99);
	for(int i = 0; i < 100; i++)
	{
		arr100[i] = aux100[i];
	}
	
	obj.quicksortmedian(arr100, 0, 99);
	for(int i = 0; i < 100; i++)
	{
		arr100[i] = aux100[i];
	}
	obj.quicksortupdatemedian(arr100, 0, 99);
	end = clock();
	cout << endl << endl << "For 100 Numbers" << endl << endl;
	obj.show(arr100,100);
	cout << endl << endl << "Time Difference: " << end-start << endl << endl;
	timee[1] = end - start;

	//For 200 numbers
	start = clock();
	obj.insertion(arr200, 200);
	for(int i = 0; i < 200; i++)
	{
		arr200[i] = aux200[i];
	}
	
	obj.Msort(arr200, 0, 200);
	for(int i = 0; i < 200; i++)
	{
		arr200[i] = aux200[i];
	}
	
	obj.quicksortmiddle(arr200, 0, 199);
	for(int i = 0; i < 200; i++)
	{
		arr200[i] = aux200[i];
	}
	
	obj.quicksortrandom(arr200, 0, 199);
	for(int i = 0; i < 200; i++)
	{
		arr200[i] = aux200[i];
	}
	
	obj.quicksortmedian(arr200, 0, 199);
	for(int i = 0; i < 200; i++)
	{
		arr200[i] = aux200[i];
	}
	obj.quicksortupdatemedian(arr200, 0, 199);
	end = clock();
	cout << endl << endl << "For 200 Numbers" << endl << endl;
	obj.show(arr200,200);
	cout << endl << endl << "Time Difference: " << end-start << endl << endl;
	timee[2] = end - start;
	

	//For 300 numbers
	start = clock();
	obj.insertion(arr300, 300);
	for(int i = 0; i < 300; i++)
	{
		arr300[i] = aux300[i];
	}
	
	obj.Msort(arr300, 0, 300);
	for(int i = 0; i < 300; i++)
	{
		arr300[i] = aux300[i];
	}
	
	obj.quicksortmiddle(arr300, 0, 299);
	for(int i = 0; i < 300; i++)
	{
		arr300[i] = aux300[i];
	}
	
	obj.quicksortrandom(arr300, 0, 299);
	for(int i = 0; i < 300; i++)
	{
		arr300[i] = aux300[i];
	}
	
	obj.quicksortmedian(arr300, 0, 299);
	for(int i = 0; i < 300; i++)
	{
		arr300[i] = aux300[i];
	}
	obj.quicksortupdatemedian(arr300, 0, 299);
	end = clock();
	cout << endl << endl << "For 300 Numbers" << endl << endl;
	obj.show(arr300,300);
	cout << endl << endl << "Time Difference: " << end-start << endl << endl;
	timee[3] = end - start;
	
	
	//For 400 numbers
	start = clock();
	obj.insertion(arr400, 400);
	for(int i = 0; i < 400; i++)
	{
		arr400[i] = aux400[i];
	}
	
	obj.Msort(arr400, 0, 400);
	for(int i = 0; i < 400; i++)
	{
		arr400[i] = aux400[i];
	}
	
	obj.quicksortmiddle(arr400, 0, 399);
	for(int i = 0; i < 400; i++)
	{
		arr400[i] = aux400[i];
	}
	
	obj.quicksortrandom(arr400, 0, 399);
	for(int i = 0; i < 400; i++)
	{
		arr400[i] = aux400[i];
	}
	
	obj.quicksortmedian(arr400, 0, 399);
	for(int i = 0; i < 400; i++)
	{
		arr400[i] = aux400[i];
	}
	obj.quicksortupdatemedian(arr400, 0, 399);
	end = clock();
	cout << endl << endl << "For 400 Numbers" << endl << endl;
	obj.show(arr400,400);
	cout << endl << endl << "Time Difference: " << end-start << endl << endl;
	timee[4] = end - start;
	
	
	//For 500 numbers
	start = clock();
	obj.insertion(arr500, 500);
	for(int i = 0; i < 500; i++)
	{
		arr500[i] = aux500[i];
	}
	
	obj.Msort(arr500, 0, 500);
	for(int i = 0; i < 500; i++)
	{
		arr500[i] = aux500[i];
	}
	
	obj.quicksortmiddle(arr500, 0, 499);
	for(int i = 0; i < 500; i++)
	{
		arr500[i] = aux500[i];
	}
	
	obj.quicksortrandom(arr500, 0, 499);
	for(int i = 0; i < 500; i++)
	{
		arr500[i] = aux500[i];
	}
	
	obj.quicksortmedian(arr500, 0, 499);
		for(int i = 0; i < 500; i++)
	{
		arr500[i] = aux500[i];
	}
	obj.quicksortupdatemedian(arr500, 0, 499);
	end = clock();
	cout << endl << endl << "For 500 Numbers" << endl << endl;
	obj.show(arr500,500);
	cout << endl << endl << "Time Difference: " << end-start << endl << endl;
	timee[5] = end - start;
	
	//For 1000 numbers
	start = clock();
	obj.insertion(arr1000, 1000);
	for(int i = 0; i < 1000; i++)
	{
		arr1000[i] = aux1000[i];
	}
	
	obj.Msort(arr1000, 0, 1000);
	for(int i = 0; i < 1000; i++)
	{
		arr1000[i] = aux1000[i];
	}
	
	obj.quicksortmiddle(arr1000, 0, 999);
	for(int i = 0; i < 1000; i++)
	{
		arr1000[i] = aux1000[i];
	}
	
	obj.quicksortrandom(arr1000, 0, 999);
	for(int i = 0; i < 1000; i++)
	{
		arr1000[i] = aux1000[i];
	}
	obj.quicksortmedian(arr1000, 0, 999);
	for(int i = 0; i < 1000; i++)
	{
		arr1000[i] = aux1000[i];
	}
	obj.quicksortupdatemedian(arr1000, 0, 999);
	end = clock();
	cout << endl << endl << "For 1000 Numbers" << endl << endl;
	obj.show(arr1000,1000);
	cout << endl << endl << "Time Difference: " << end-start << endl << endl;
	timee[6] = end - start;
	
	
	//Storing in the files
	for(int i = 0; i < 50; i++)
	{
		size50 << " " << arr[i];
	}
	
	for(int i = 0; i < 100; i++)
	{
		size100 << " " << arr100[i];
	}
	
	for(int i = 0; i < 200; i++)
	{
		size200 << " " << arr200[i];
	}
	
	for(int i = 0; i < 300; i++)
	{
		size300 << " " << arr300[i];
	}
	
	for(int i = 0; i < 400; i++)
	{
		size400 << " " << arr400[i];
	}
	
	for(int i = 0; i < 500; i++)
	{
		size500 << " " << arr500[i];
	}
	
	for(int i = 0; i < 1000; i++)
	{
		size1000 << " " << arr1000[i];
	} 

	//Closing the files
	size50.close();
	size100.close();
	size200.close();
	size300.close();
	size400.close();
	size500.close();
	size1000.close();
} 
