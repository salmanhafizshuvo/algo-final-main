#include <stdio.h>
#define nV 4  // nV মানের মাধ্যমে গ্রাফের সংখ্যা নির্ধারণ করা হচ্ছে (এখানে ৪টি নোড হবে)
#define INF 999  // INF মানটি অসীমের জন্য নির্ধারণ করা হয়েছে

// Floyd-Warshall অ্যালগরিদমটি গ্রাফের সব জোড়া নোডের মধ্যে সবচেয়ে কম দূরত্ব বের করার জন্য ব্যবহার করা হয়
void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;

  // গ্রাফের এডজেসেন্সি ম্যাট্রিক্সটি matrix-এ কপি করা হচ্ছে
  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Floyd-Warshall অ্যালগরিদম চালানো হচ্ছে
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        // যদি i থেকে k এবং k থেকে j পর্যন্ত রাস্তায় যাত্রা করে i থেকে j যাওয়ার দূরত্ব কম হয়, তবে সেটা আপডেট করা হচ্ছে
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  
  // ফলাফল প্রিন্ট করা হচ্ছে
  printf("\n\nThe results of the Floyd-Warshall Algorithm\n\n");
  printMatrix(matrix);
}

// ম্যাট্রিক্সটি প্রিন্ট করার জন্য একটি ফাংশন
void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)  // যদি মান INF হয়, তবে INF প্রদর্শন হবে
        printf("%4s", "INF");
      else  // অন্যথায়, যথাযথ মান প্রিন্ট হবে
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

// মেইন ফাংশন যেখানে ব্যবহারকারী ইনপুট দিবে
int main()
{
  int n,i,j,k;
  printf("Enter the total number of nodes: ");  // নোডের সংখ্যা ইনপুট করার জন্য মেসেজ
  scanf("%d", &n);  // নোডের সংখ্যা ইনপুট নেওয়া হচ্ছে
  printf("Enter the adjacency matrix value one by one\n");  // এডজেসেন্সি ম্যাট্রিক্স ইনপুটের নির্দেশনা
  int graph[n][n];  // গ্রাফের জন্য ম্যাট্রিক্স তৈরি করা হচ্ছে
  // গ্রাফের এডজেসেন্সি ম্যাট্রিক্সের মান ইনপুট নেয়া হচ্ছে
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf("G[%d][%d]: ",i+1,j+1);  // G[i][j] এর মান ইনপুট করার জন্য নির্দেশনা
        scanf("%d", &graph[i][j]);  // মান ইনপুট নেওয়া হচ্ছে
    }
  }
  // Floyd-Warshall অ্যালগরিদমের জন্য ফাংশন কল করা হচ্ছে
  floydWarshall(graph);
}
