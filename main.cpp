// #include <iostream>
// #include <chrono>
// #include <thread>
// #include <mutex>
// #include <condition_variable>

// class TokenBucket {
// public:
//     TokenBucket(int capacity, int refillRate)
//         : capacity_(capacity), tokens_(capacity), refillRate_(refillRate) {}

//     bool tryConsume() {
//         std::unique_lock<std::mutex> lock(mutex_);
//         refillTokens();
//         if (tokens_ > 0) {
//             --tokens_;
//             return true;
//         }
//         return false;
//     }

// private:
//     void refillTokens() {
//         auto now = std::chrono::steady_clock::now();
//         int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastRefill_).count();
//         int newTokens = elapsed * refillRate_ / 1000;
//         if (newTokens > 0) {
//             tokens_ = std::min(tokens_ + newTokens, capacity_);
//             lastRefill_ = now;
//         }
//     }

// private:
//     int capacity_;
//     int tokens_;
//     int refillRate_;
//     std::chrono::steady_clock::time_point lastRefill_;
//     std::mutex mutex_;
// };
#include "orderbook.h"
int main() {
    TokenBucket tokenBucket(10, 5); // Allow 5 tokens to be consumed per second

    for (int i = 0; i < 20; ++i) {
        if (tokenBucket.tryConsume()) {
            std::cout << "Operation " << i + 1 << " allowed." << std::endl;
        } else {
            std::cout << "Operation " << i + 1 << " denied (rate limited)." << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
