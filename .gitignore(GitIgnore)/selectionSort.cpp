void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}


void bubbleSort(int arr[], int size) {
    int counter = 1;
    while (counter < size - 1) {
        for (int i = 0; i < size - counter; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current and j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void merge(int arr[], int LB, int mid, int UB) {
    int n1 = mid - LB + 1;
    int n2 = UB - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++) {
        a[i] = arr[LB + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = LB;

    while (i < n1 and j < n2) {
        if (a[i] < b[i]) {
            arr[k] = a[i];
            k++;
            j++;
        } else
            arr[k] = b[j];
        k++;
        j++;
    }
    while (i<n1){
        arr[k]=a[i];
        k++;
        i++;
    }
    while (j<n2){
        arr[k]=b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int LB, int UB) {
    if (LB < UB) {
        int mid = (LB + UB) / 2;
        mergeSort(arr, LB, mid);
        mergeSort(arr, mid + 1, UB);

        merge(arr,LB,mid,UB);
    }

}

