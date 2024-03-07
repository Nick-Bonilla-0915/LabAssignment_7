/*
    Author: Nicholas Bonilla
    Purpose: Counting number of times each value in an array is swapped
    */
void selectionSort(int *arrNum, int len);
void bubbleSort(int *arrNum, int len);


int main()
{
    //Making arrays
    int arr1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    //Calling sorts
    selectionSort(arr1, 9);
    bubbleSort(arr1, 9);
    selectionSort(arr2, 9);
    bubbleSort(arr2, 9);

    //Final Return
    return 0;
}


void selectionSort(int *arrNum, int len)
{
    //Temp variables
    int min, mIndex, temp, cmp1, cmp2, total, swapped;


    //Copying array
    int arr[len];
    for(int i = 0; i < len; i++)
    {
        arr[i] = arrNum[i];
    }

    int count[len][2];
    for(int i = 0; i < len; i++)
    {
        count[i][0] = arr[i];
        count[i][1] = 0;
    }

    //Looping through array to sort
    for(int i = 0; i < len; i++)
    {
        //Setting initial miminums
        min = arr[i];
        mIndex = i;
        swapped = 0;
        
        for(int j = i; j < len; j++)
        {
            //Searching for minimum
            if(arr[j] < min)
            {
                min = arr[j];
                mIndex = j;
                swapped = 1;
            }
        }

            //Swapping
            temp = arr[mIndex];
            arr[mIndex] = arr[i];
            arr[i] = temp;
            cmp1 = arr[i];
            cmp2 = arr[mIndex];
            

            //Increasing count
            for(int i = 0; i < len; i++)
            {
                if(cmp1 == count[i][0])
                {
                    count[i][1]++;
                }   

                else if(cmp2 == count[i][0])
                {
                    count[i][1]++;
                }
            }

            if(swapped)
            {
                total++;
            }
    }

    //Sorting Count
    for(int i = 0; i < len - 1; i++)
    {
        //Setting initial miminums
        min = count[i][0];
        mIndex = i;
        
        for(int j = i + 1; j < len; j++)
        {
            //Searching for minimum
            if(count[j][0] < min)
            {
                min = count[j][0];
                mIndex = j;
            }
        }

            //Swapping
            temp = count[mIndex][0];
            count[mIndex][0] = count[i][0];
            count[i][0] = temp;
            temp = count[mIndex][1];
            count[mIndex][1] = count[i][1];
            count[i][1] = temp; 
        }

        //Printing Info
        for(int i = 0; i < len; i++)
        {
            printf("%d: %d of times %d is swapped\n", count[i][0], count[i][1], count[i][0]);
        }

        printf("total # of swaps: %d\n", total);
}

void bubbleSort(int *arrNum, int len)
{
    //Making Count array
    int count[len][2];

    //Copying array
    int arr[len];
    for(int i = 0; i < len; i++)
    {
        arr[i] = arrNum[i];
    }

    //Making Variables
    int temp, min, mIndex, total, swapped;

    //Initializing New Array
    for(int i = 0; i < len; i++)
    {
        count[i][0] = arr[i];
        count[i][1] = 0;
    }

    //Sorting Array
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            //Swapping Values
            if(arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                swapped = 1;

                //Increasing Count
                for(int k = 0; k < len; k++)
                {
                    if(arr[i] == count[k][0])
                    {
                        count[k][1]++;
                    }   

                    else if(arr[j] == count[k][0])
                    {
                        count[k][1]++;
                    }
                }

                if(swapped)
                {
                    total++;
                }

                swapped = 0;
            }
        }
    }

    //Sorting Count
    for(int i = 0; i < len; i++)
    {
        //Setting initial miminums
        min = count[i][0];
        mIndex = i;
        
        
        for(int j = i; j < len; j++)
        {
            //Searching for minimum
            if(count[j][0] < min)
            {
                min = count[j][0];
                mIndex = j;
            }
        }

            //Swapping
            temp = count[mIndex][0];
            count[mIndex][0] = count[i][0];
            count[i][0] = temp;
            temp = count[mIndex][1];
            count[mIndex][1] = count[i][1];
            count[i][1] = temp; 
        }

    //Printing Info
    for(int i = 0; i < len; i++)
        {
            printf("%d: %d of times %d is swapped\n", count[i][0], count[i][1], count[i][0]);
        }

    printf("total # of swaps: %d\n", total);
}