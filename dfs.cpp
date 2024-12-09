#include<bits/stdc++.h>   // স্ট্যান্ডার্ড লাইব্রেরি ইনক্লুড
using namespace std;      // std namespace ব্যবহার
#define MAX 5             // ম্যাট্রিক্সের ম্যাক্সিমাম সাইজ 5 হিসাবে সংজ্ঞায়িত

// DFS ফাংশন যা গ্রাফের অ্যাডজেসেন্সি ম্যাট্রিক্স, ভিজিটেড অ্যারে এবং শুরু পয়েন্ট নেয়
void depth_first_search(int adj[][MAX], int visited[], int start){
    int stack[MAX];       // DFS এর জন্য স্ট্যাক ডিক্লেয়ার
    int top = -1, i, k;

    // প্রতিটি নোডকে আনভিজিটেড করে সেট করা হচ্ছে
    for (k = 0; k < MAX; k++)
        visited[k] = 0;

    stack[++top] = start; // শুরু নোড স্ট্যাকে রাখা হচ্ছে
    visited[start] = 1;   // শুরু নোডকে ভিজিটেড চিহ্নিত করা হচ্ছে

    // যতক্ষণ স্ট্যাক ফাঁকা না হয়, ততক্ষণ পর্যন্ত চলবে
    while (top != -1) {
        start = stack[top--];          // স্ট্যাক থেকে নোড বের করা হচ্ছে
        printf("%c ", start + 65);     // নোড প্রিন্ট করা হচ্ছে (ASCII এর মাধ্যমে A, B, C)

        // প্রতিবেশী নোডগুলো খুঁজে বের করা হচ্ছে
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                stack[++top] = i;      // প্রতিবেশী নোড স্ট্যাকে যোগ
                visited[i] = 1;        // নোডকে ভিজিটেড চিহ্নিত
                break;                 // প্রথম আনভিজিটেড প্রতিবেশী নোড পেলে লুপ থেকে বের হওয়া
            }
        }
    }
}

int main()
{
    int visited[MAX] = {};            // ভিজিটেড অ্যারে
    int adj[MAX][MAX], i, j, start = 0;

    printf("Enter the adjacency matrix\n");  // অ্যাডজেসেন্সি ম্যাট্রিক্স ইনপুট
    for (i = 0; i < MAX; i++) {              // সারি
        for (j = 0; j < MAX; j++) {          // কলাম
            scanf("%d", &adj[i][j]);         // মান ইনপুট
        }
    }

    printf("\n\n========== The result of DFS ==========\n");
    depth_first_search(adj, visited, start); // DFS কল
    printf("\n\n");
    return 0;
}
