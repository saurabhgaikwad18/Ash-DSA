

#include <iostream>

using namespace std;

class Employee
{
public:
    std::string name;
    int salary;

    void getDetails()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }

    void displayDetails()
    {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

void merge(Employee *arr, int low, int mid, int high)
{
    int size1 = mid - low + 1;
    int size2 = high - mid;
    Employee *leftArr = new Employee[size1];
    Employee *rightArr = new Employee[size2];

    for (int i = 0; i < size1; i++)
    {
        leftArr[i] = arr[low + i];
    }

    for (int i = 0; i < size2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < size1 && j < size2)
    {
        if (leftArr[i].salary <= rightArr[j].salary)
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < size1)
    {
        arr[k++] = leftArr[i++];
    }

    while (j < size2)
    {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(Employee *arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    const int size = 10;
    Employee employees[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter details for employee " << i + 1 << endl;
        employees[i].getDetails();
    }

    mergeSort(employees, 0, size - 1);

    cout << "Top 5 employees with highest salary:" << endl;
    for (int i = size - 1; i >= size - 5; i--)
    {
        employees[i].displayDetails();
    }

    return 0;
}
