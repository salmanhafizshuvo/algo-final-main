#include<bits/stdc++.h>  // স্ট্যান্ডার্ড লাইব্রেরি ইনক্লুড
using namespace std;     // std namespace ব্যবহার
#define MAX 5            // ম্যাট্রিক্সের ম্যাক্সিমাম সাইজ 5 হিসাবে সংজ্ঞায়িত

// BFS ফাংশন যা গ্রাফের অ্যাডজেসেন্সি ম্যাট্রিক্স, ভিজিটেড অ্যারে এবং শুরু পয়েন্ট নেয়
void breadth_first_search(int adj[][MAX], int visited[], int start){
    int queue[MAX], rear= -1, front= -1, i, k;

    // প্রতিটি নোডকে আনভিজিটেড করে সেট করা হচ্ছে
    for (k=0; k<MAX; k++)
        visited[k]=0;

    queue[++rear] = start;  // শুরু নোড কিউতে রাখা হচ্ছে
    ++front;                // ফ্রন্ট বাড়ানো হচ্ছে
    visited[start] = 1;     // শুরু নোডকে ভিজিটেড চিহ্নিত করা হচ্ছে

    // যতক্ষণ কিউ ফাঁকা না হয়, ততক্ষণ পর্যন্ত চলবে
    while (rear >= front){
        start = queue[front++];   // কিউ থেকে নোড বের করা হচ্ছে
        printf("%c ", start + 65); // নোড প্রিন্ট করা হচ্ছে (ASCII মাধ্যমে A, B, C)

        // প্রতিবেশী নোডগুলো খুঁজে বের করা হচ্ছে
        for (i = 0; i < MAX; i++){
            if (adj[start][i] == 1 && visited[i] == 0){
                queue[++rear] = i;   // প্রতিবেশী নোড কিউতে যোগ
                visited[i] = 1;      // নোডকে ভিজিটেড চিহ্নিত
            }
        }
    }
}

int main()
{
    int visited[MAX] = {};           // ভিজিটেড অ্যারে
    int adj[MAX][MAX], i, j, start = 0;

    printf("Enter the adjacency matrix\n");  // অ্যাডজেসেন্সি ম্যাট্রিক্স ইনপুট
    for (i = 0; i < MAX; i++){               // সারি
        for (j = 0; j < MAX; j++){           // কলাম
            scanf("%d", &adj[i][j]);         // মান ইনপুট
        }
    }

    printf("\n========== The result of BFS ==========\n");
    breadth_first_search(adj, visited, start);  // BFS কল
    return 0;
}
