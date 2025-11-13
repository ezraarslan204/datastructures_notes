// Ad:Ezra
// Soyad:ARslan
// Okul No:222503204
// Sınıf:3
// Öğrenim Türü (Örgün/İkinci Öğretim):örgün

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //rastgele farklı sayı üretmesi için

#define MIN_RANGE 1
#define MAX_RANGE 20
#define INSERT_COUNT 40
//ikili ağaç yapısı
struct BinaryTreeNode {
    int key;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};
// ağaçyapısında yeni düğüm
struct BinaryTreeNode* newNodeCreate(int value) {
    struct BinaryTreeNode* temp = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    if (temp == NULL) {
        perror("Hafıza ayırma hatası");
        exit(EXIT_FAILURE);
    }
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct BinaryTreeNode* insert(struct BinaryTreeNode* root, int key) {
    if (root == NULL) {
        return newNodeCreate(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    
    return root;
}

//ağaçta gezinme 
void analyzeBST(struct BinaryTreeNode* root, int* sum, int* total_nodes, int* odd_count, int* even_count, int* leaf_count) {
    if (root != NULL) {
    
        *sum += root->key;
        *total_nodes += 1;
        
        if (root->key % 2 == 0) {
            *even_count += 1;
        } else {
            *odd_count += 1;
        }

       
        if (root->left == NULL && root->right == NULL) {
            *leaf_count += 1;
        }

           analyzeBST(root->left, sum, total_nodes, odd_count, even_count, leaf_count);
        analyzeBST(root->right, sum, total_nodes, odd_count, even_count, leaf_count);
    }
}


int main() {
    struct BinaryTreeNode *root = NULL;
    
    // rastgele sayı üretmek için
    srand(time(0)); 

    printf("----Eklenen sayılar-------:\n");
       int inserted_numbers[INSERT_COUNT]; 
    int distinct_insertion_attempt = 0; 
    
    // 1-20 arası 40 rastgele sayı üret ve ekle
    for (int i = 0; i < INSERT_COUNT; i++) {
        // Rastgele sayı üretimi: [MIN_RANGE, MAX_RANGE]
        int random_key = (rand() % (MAX_RANGE - MIN_RANGE + 1)) + MIN_RANGE;
        
        root = insert(root, random_key);
        
        inserted_numbers[i] = random_key;
        distinct_insertion_attempt++;
    }

    // rastgele eklenen sayıların çıktısı
    printf(" %d ", distinct_insertion_attempt);
    for (int i = 0; i < INSERT_COUNT; i++) {
        printf("%d%s", inserted_numbers[i], (i == INSERT_COUNT - 1) ? "" : ", ");
    }
    printf("\n\n");
    
    //analizler
    int sum = 0;
    int total_nodes = 0; 
    int odd_count = 0;
    int even_count = 0;
    int leaf_count = 0;
    

    analyzeBST(root, &sum, &total_nodes, &odd_count, &even_count, &leaf_count);

    double average = 0.0;
    if (total_nodes > 0) {
        average = (double)sum / total_nodes;
    }

    printf("--------CEVAPLAR--------\n");
  
    printf(" Aritmetik ortalama: %.2f\n", average);
    printf(" Çift sayı adedi: %d\n", even_count);
    printf(" Tek sayı adedi: %d\n", odd_count);
    printf(" Leaf sayısı: %d\n", leaf_count);


    return 0;
}
