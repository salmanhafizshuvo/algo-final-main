#include <iostream>
#include <vector>

using namespace std;

// সিভ অফ এরাটোস্থেনিস ফাংশন, যা n পর্যন্ত সব প্রাইম সংখ্যা নির্ণয় করে
void sieveOfEratosthenes(int n) {
    // একটি বুলিয়ান ভেক্টর তৈরি করা হচ্ছে যেখানে সব ভ্যালু শুরুতে true থাকবে
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 এবং 1 প্রাইম নয়, তাই false সেট করা হলো

    // প্রতিটি সংখ্যা পরীক্ষা করা হচ্ছে
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            // প্রাইম সংখ্যার গুণিতকগুলো প্রাইম নয়, তাই false করা হচ্ছে
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // সব প্রাইম সংখ্যা প্রিন্ট করা হচ্ছে
    cout << "প্রাইম সংখ্যা (২ থেকে " << n << " পর্যন্ত): ";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    // ব্যবহারকারীর কাছ থেকে একটি সংখ্যা ইনপুট নেওয়া হচ্ছে
    cout << "একটি সংখ্যা লিখুন: ";
    cin >> n;

    // সিভ অফ এরাটোস্থেনিস ফাংশন কল করা হচ্ছে
    sieveOfEratosthenes(n);

    return 0;
}
