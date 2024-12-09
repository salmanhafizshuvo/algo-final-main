#include<bits/stdc++.h>   // স্ট্যান্ডার্ড লাইব্রেরি ইনক্লুড
using namespace std;      // std namespace ব্যবহার

// Prim's algorithm যা MST খুঁজে বের করার জন্য নোড সংখ্যা ও কস্ট ম্যাট্রিক্স নেয়
void prims(int n, int cost[10][10]){
    int i, j, u, v, min, min_cost = 0, visited[10], ne = 1;

    // প্রতিটি নোডকে আনভিজিটেড করে সেট করা হচ্ছে
    for (i = 1; i <= n; i++)
        visited[i] = 0;

    printf("\nThe edges considered for MST are\n");
    visited[1] = 1;  // প্রথম নোড ভিজিটেড হিসেবে চিহ্নিত করা হচ্ছে

    // যতক্ষণ না সকল নোড MST এর অংশ হচ্ছে, ততক্ষণ লুপ চালানো
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                // সর্বনিম্ন খরচের এজ খুঁজে বের করা
                if (cost[i][j] < min) {
                    if (visited[i] == 0)  // যদি নোড আনভিজিটেড হয় তবে স্কিপ
                        continue;
                    else {
                        min = cost[i][j];  // সর্বনিম্ন খরচ আপডেট করা হচ্ছে
                        u = i;             // নোডের উৎস
                        v = j;             // নোডের গন্তব্য
                    }
                }
            }
        }

        // যদি যে কোনো একটি নোড আনভিজিটেড হয় তবে এজটি MST এ যোগ করা হচ্ছে
        if (visited[u] == 0 || visited[v] == 0) {
            printf("No %d edge (%d %d), with minimum cost= %d\n", ne++, u, v, min);
            min_cost = min_cost + min;   // MST এর মোট খরচ আপডেট
            visited[v] = 1;              // গন্তব্য নোডকে ভিজিটেড হিসেবে চিহ্নিত
        }

        // প্রক্রিয়াজাত এজ বাদ দেওয়া হচ্ছে
        cost[u][v] = cost[v][u] = 999;
    }

    printf("\n\nThe total cost of the MST is: %d\n", min_cost);  // MST এর মোট খরচ প্রিন্ট
}

int main()
{
    int i, j, n, cost[10][10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Now enter the cost matrix\n");
    for (i = 1; i <= n; i++) {               // সারি
        for (j = 1; j <= n; j++) {           // কলাম
            printf("cost[%d][%d]: ", i, j);
            scanf("%d", &cost[i][j]);        // কস্ট ম্যাট্রিক্স ইনপুট

            if (cost[i][j] == 0)             // এজ না থাকলে সেট করা হচ্ছে বড় মানে
                cost[i][j] = 999;
        }
    }

    prims(n, cost);  // Prim's algorithm কল
    return 0;
}
