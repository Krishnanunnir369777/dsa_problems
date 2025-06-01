


void deletefromHeap()   // delete root from heap
{
    if (size == 0)
    {
        cout << "No element present" << endl;
        return;
    }

    // Replace root with last element
    arr[1] = arr[size];
    size--;

    int i = 1;

    while (i <= size)
    {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;
        int largest = i;

        if (leftIndex <= size && arr[leftIndex] > arr[largest])
        {
            largest = leftIndex;
        }

        if (rightIndex <= size && arr[rightIndex] > arr[largest])
        {
            largest = rightIndex;
        }

        // If current is larger than both children, break
        if (largest == i)
            break;

        swap(arr[i], arr[largest]);
        i = largest;
    }
}
