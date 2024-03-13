#include <iostream>
#include <cstddef>
using namespace std;

void selectionSort(int[], int);
void selectionSort(int, int*);

//Basic Pointer Manipulations
//Program to demonstrate pointers and dynamic variables.
int main()
{
    int* p1, * p2;
    int num1, num2;
    int nums[] = { 33,22,77,44,11 };

    p1 = nums; // &nums[0]

    for (int i = 0; i < 5; i++) {
        printf("at 0x%p: ", p1 + i); // %p format specifier
        cout << *(p1 + i) << endl;  //that which is referred to
    }

    //   selectionSort(nums, 5);
    selectionSort(5, p1);

    for (int i = 0; i < 5; i++) {
        printf("at 0x%p: ", p1 + i); // %p format specifier
        cout << *(p1 + i) << endl;  //that which is referred to
    }

    num1 = 23;   //direct addressing
    num2 = 55;

    p1 = NULL;  // stores the NULL pointer into p1  if(p1 == NULL)

    p1 = &num1;
    p2 = &num2;

    printf("0x%p 0x%p\n", p1, p2);  // p is pointer address
    cout << *p1 << endl;

    printf("0x%p\n", p1 - 3);
    cout << *(p1 - 3) << endl;  //using address arithmetic

    *p1 = 42;   //indirect addressing
    p2 = p1;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    *p2 = 53;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    *p1 = 88;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    p1 = nums;

    for (int i = 0; i < 5; i++) {
        printf("at 0x%p: ", p1 + i);
        cout << *(p1 + i) << endl;
    }

    return 0;
}

void selectionSort(int nums[], int count) {

    /** The method for sorting the numbers */
    for (int i = 0; i < count - 1; i++) {
        // Find the minimum in the nums[i..list.length-1]
        int currentMin = nums[i];
        int currentMinIndex = i;

        for (int j = i + 1; j < count; j++) {
            if (currentMin > nums[j]) {
                currentMin = nums[j];
                currentMinIndex = j;
            }
        }

        // Swap nums[i] with nums[currentMinIndex] if necessary;
        if (currentMinIndex != i) {
            nums[currentMinIndex] = nums[i];
            nums[i] = currentMin;
        }
    }

}


/** The method for sorting the numbers in array using pointers
@param1- number of elements
@param2 - pointer to array
*/
void selectionSort(int count, int* ptr) {

    for (int i = 0; i < count - 1; ++i) {
        // Find the minimum element in the unsorted part of the array
        int* minPtr = ptr + i;

        for (int* j = ptr + i + 1; j < ptr + count; ++j) {
            if (*j < *minPtr) {
                minPtr = j;
            }
        }

        // Swap the minimum element with the first element of the unsorted part
        int temp = *minPtr;
        *minPtr = *(ptr + i);
        *(ptr + i) = temp;
    }
}