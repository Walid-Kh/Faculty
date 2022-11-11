#include <bits/stdc++.h>
#include <chrono>
#pragma comment(linker, "/STAC K:268435456")
using namespace std;
using namespace std::chrono;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
class solution
{
    void selectionSort(vector<int> &arr, int len)
    {
        for (int i = 0; i < len; i++)
        {
            int min = i;
            for (int j = i; j < len; j++)
                if (arr[j] < arr[min])
                    min = j;
            swap(arr[i], arr[min]);
        }
    }
    void insertionSort(vector<int> &arr, int len, int begin = 0)
    {
        for (int i = begin; i < len; i++)
        {
            int j = i - 1;
            int selectedElement = arr[i];
            while (arr[j] > selectedElement && j > -1)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = selectedElement;
        }
    }
    void merge(vector<int> &arr, int left, int mid, int end)
    {
        const int sizeOfArrOne = (mid - left + 1);
        const int sizeOfArrTwo = (end - mid);
        vector<int> leftArr(sizeOfArrOne);
        vector<int> rightArr(sizeOfArrTwo);
        for (int i = 0; i < sizeOfArrOne; i++)
            leftArr[i] = arr[i + left];
        for (int i = 0; i < sizeOfArrTwo; i++)
            rightArr[i] = arr[i + mid + 1];
        int indexOfArrOne = 0, indexOfArrTwo = 0, indexOfMerged = left;
        while (indexOfArrOne < sizeOfArrOne && indexOfArrTwo < sizeOfArrTwo)
        {
            if (leftArr[indexOfArrOne] <= rightArr[indexOfArrTwo])
            {
                arr[indexOfMerged] = leftArr[indexOfArrOne];
                indexOfArrOne++;
            }
            else
            {
                arr[indexOfMerged] = rightArr[indexOfArrTwo];
                indexOfArrTwo++;
            }
            indexOfMerged++;
        }
        while (indexOfArrOne < sizeOfArrOne)
        {
            arr[indexOfMerged] = leftArr[indexOfArrOne];
            indexOfArrOne++;
            indexOfMerged++;
        }
        while (indexOfArrTwo < sizeOfArrTwo)
        {
            arr[indexOfMerged] = rightArr[indexOfArrTwo];
            indexOfArrTwo++;
            indexOfMerged++;
        }
    }
    void mergeSort(vector<int> &arr, int e, int b = 0)
    {
        if (b >= e)
            return;
        int mid = b + (e - b) / 2;
        mergeSort(arr, mid, b);
        mergeSort(arr, e, mid + 1);
        merge(arr, b, mid, e);
    }
    int partition(vector<int> &arr, int b, int e)
    {
        int pivot = arr[e];
        int i = b - 1;
        for (int j = b; j <= e; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[e]);
        return i + 1;
    }
    void quickSort(vector<int> &arr, int len, int b = 0)
    {
        if (b < len)
        {
            int pi = partition(arr, b, len);
            quickSort(arr, pi - 1, b);
            quickSort(arr, len, pi + 1);
        }
    }
    void hybridSort(vector<int> &arr, int len)
    {
        hybridSort(arr, 0, len);
    }
    void hybridSort(vector<int> &arr, int begin, int end)
    {
        if (begin >= end)
            return;
        if (end - begin + 1 <= 500)
        {
            unsigned long long average = 0;
            for (int i = begin; i < begin + 10; i++)
                average += arr[i];
            average /= (10);
            if (abs((long)(arr[end] - average)) > 200000)
                insertionSort(arr, end, begin);
            else
                quickSort(arr, end, begin);
            return;
        }
        int mid = begin + (end - begin) / 2;
        hybridSort(arr, begin, mid);
        hybridSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }

public:
    solution(int sortAlgoNum, string dataFileName, string outputFileName, string runningTimeFileName)
    {
        vector<int> arr(500000);
        int x, len = 0;
        ifstream dataFile(dataFileName);
        while (dataFile >> x)
        {
            arr[len] = x;
            len++;
        }
        dataFile.close();
        auto start = high_resolution_clock::now();
        switch (sortAlgoNum)
        {
        case 0:
            selectionSort(arr, len);
            break;
        case 1:
            insertionSort(arr, len);
            break;
        case 2:
            mergeSort(arr, len - 1);
            break;
        case 3:
            quickSort(arr, len - 1);
            break;
        case 4:
            hybridSort(arr, len);
            break;
        }
        auto finish = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(finish - start);
        ofstream outputFile(outputFileName);
        for (int i = 0; i < len; i++)
            outputFile << arr[i] << '\n';
        outputFile.close();
        ofstream runningTimeFile(runningTimeFileName);
        runningTimeFile << duration.count();
    }
};
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution *x = new solution(atoi(argv[1]), argv[2], argv[3], argv[4]);
    delete x;
    return 0;
}