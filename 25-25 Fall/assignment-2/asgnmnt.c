// Ad: Ezra
// Soyad: Arslan
// Okul No: 222503204
// Sınıf: 3
// Öğrenim Türü (Örgün/İkinci Öğretim): Örgün

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

#define N 1000      // dizi eleman sayısı
#define MAX_VAL 10000 // max eleman değeri

//fonksiyonlar
void initialize_array(int arr[]);
void print_array(const char *header, int arr[]);
void swap(int* a, int* b);

// sıralama algoritmaları
void insertionSort(int arr[], int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r); 
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high); 

// Ana fonksiyon
int main() {
    int original_arr[N];
    int temp_arr[N]; 
    clock_t start, end;
    double time_used_insertion, time_used_merge, time_used_quick;

    // rastgele sayı üretecinin başlangıcı
    srand(time(NULL));
    initialize_array(original_arr);

    printf("İkinci Ödev\n");
    printf("Eleman Sayısı: %d, Değer Aralığı: 1 - %d\n\n", N, MAX_VAL);
    


    //  dizinin tüm elemanlarını göster
    print_array("Rastgele Dizi %d Elemanlı:", original_arr);

   
    // insertion sort geçen süre ölç
   
    memcpy(temp_arr, original_arr, N * sizeof(int)); //orjinal diziyi kopyalar ki diğer sortlar sırlanmış diziye işlem yapmasın
    start = clock();
    insertionSort(temp_arr, N);
    end = clock();
    time_used_insertion = ((double)(end - start)) / CLOCKS_PER_SEC;

  
    // merge sort geçen süre ölç

    memcpy(temp_arr, original_arr, N * sizeof(int)); //orjinal dizi kopyala
    start = clock();
    mergeSort(temp_arr, 0, N - 1);
    end = clock();
    time_used_merge = ((double)(end - start)) / CLOCKS_PER_SEC;

   
    //qick sort geçen süre ölç 
 
    memcpy(temp_arr, original_arr, N * sizeof(int)); // orjinal dizi kopyalanır
    start = clock();
    quickSort(temp_arr, 0, N - 1);
    end = clock();
    time_used_quick = ((double)(end - start)) / CLOCKS_PER_SEC;

   //geçen süreleri yazdırma
  
    printf("Insertion sort geçen süre: %f saniye\n", time_used_insertion);
    printf("Merge sort geçen süre: %f saniye\n", time_used_merge);
    printf("Quick sort geçen süre: %f saniye\n", time_used_quick);
   
    // sırlanmış diziyi gösterme
    print_array("\n Sıralanmış Dizi %d Elemanlı: ", temp_arr);
    return 0;
}
    // diziyi rastgele doldurur
void initialize_array(int arr[]) {
    for (int i = 0; i < N; i++) {
        arr[i] = (rand() % MAX_VAL) + 1; 
    }
}

// dizinin tüm elemanlarını ekrana yazdırır
void print_array(const char *header, int arr[]) {
    printf(header, N);
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// İki sayıyı yer değiştirir (Quick Sort için gerekli)
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Sıralma algoritmaları

// Insertion Sort

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


// Merge Sort 

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) { arr[k++] = L[i++]; }
    while (j < n2) { arr[k++] = R[j++]; }
}


// Quick Sort 

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
// bu ödevde inserton sort, merge sort, quick sort çalışma süreleri karşılaştırdık. süreleri incelediğimde quick sort en hızlı sıralama yapan algoritma oldu. merge sort ise böl ve yönet ile  insertiona göre daha hızlı çalıştı. İnsertion quickten her seferinde en az 5 kat fazla süre kullandı
