#include <stdio.h>
#define INFINITY 9999 // অসীম মানের জন্য একটি বড় সংখ্যা
#define MAX 10 // সর্বোচ্চ নোড সংখ্যা

// ডিক্সট্রা অ্যালগরিদম ফাংশন
void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX]; // বিভিন্ন তথ্য সংরক্ষণের জন্য অ্যারে ডিক্লেয়ার করা
  int visited[MAX], count, mindistance, nextnode, i, j;

  // কস্ট ম্যাট্রিক্স তৈরি করা হচ্ছে
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0) // যদি কোনো সংযোগ না থাকে
        cost[i][j] = INFINITY; // অসীম মান সেট করা হচ্ছে
      else
        cost[i][j] = Graph[i][j]; // সংযোগ থাকলে তার ওজন ব্যবহার করা হচ্ছে

  // প্রাথমিক মান সেট করা
  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i]; // স্টার্ট নোড থেকে প্রতিটি নোডের দূরত্ব
    pred[i] = start; // স্টার্ট নোডকে পূর্ববর্তী হিসেবে ধরা হচ্ছে
    visited[i] = 0; // সব নোডকে আনভিজিটেড হিসেবে সেট করা হচ্ছে
  }

  distance[start] = 0; // স্টার্ট নোডের দূরত্ব শূন্য
  visited[start] = 1; // স্টার্ট নোডকে ভিজিট করা হয়েছে
  count = 1; // প্রথম নোড ভিজিট করা হয়েছে

  // অন্যান্য নোডগুলো প্রসেস করা হচ্ছে
  while (count < n - 1) {
    mindistance = INFINITY; // সর্বনিম্ন দূরত্বের জন্য প্রাথমিক মান

    // আনভিজিটেড নোডগুলোর মধ্যে সর্বনিম্ন দূরত্ব খুঁজে বের করা
    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i; // সর্বনিম্ন দূরত্বের নোড সংরক্ষণ করা
      }

    visited[nextnode] = 1; // নোডটিকে ভিজিট হিসেবে চিহ্নিত করা হচ্ছে
    for (i = 0; i < n; i++)
      if (!visited[i]) // যদি নোডটি ভিজিট না হয়ে থাকে
        if (mindistance + cost[nextnode][i] < distance[i]) { // নতুন দূরত্ব আগের চেয়ে কম হলে আপডেট করা
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode; // নতুন পূর্ববর্তী নোড সেট করা হচ্ছে
        }
    count++; // ভিজিট হওয়া নোডের সংখ্যা বাড়ানো
  }

  // প্রতিটি নোডের দূরত্ব প্রিন্ট করা হচ্ছে
  for (i = 0; i < n; i++)
    if (i != start) { // স্টার্ট নোড বাদে
      printf("\nDistance from source to %d: %d", i + 1, distance[i]);
    }
}

int main() {
  int Graph[MAX][MAX], i, j, n, u;

  // মোট নোডের সংখ্যা ইনপুট নেওয়া হচ্ছে
  printf("Enter the total number of nodes: ");
  scanf("%d", &n);

  // অ্যাডজেসেন্সি ম্যাট্রিক্স ইনপুট নেওয়া হচ্ছে
  printf("\nEnter the adjacency list\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("G[%d][%d]: ", i + 1, j + 1); // সংযোগ ইনপুট নেওয়া
      scanf("%d", &Graph[i][j]);
    }
  }

  u = 0; // স্টার্ট নোড নির্ধারণ করা হচ্ছে
  Dijkstra(Graph, n, u); // ডিক্সট্রা অ্যালগরিদম কল করা হচ্ছে
  return 0;
}
