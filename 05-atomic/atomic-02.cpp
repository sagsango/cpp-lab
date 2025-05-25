#include <atomic>

int main() {
    std::atomic_int64_t num;
    num.fetch_add(1);
    num.fetch_and(2);
    num.fetch_or(3);
    num.fetch_sub(4);
    num.fetch_xor(5);
    int64_t expect = num.load();
    num.compare_exchange_strong(expect, 32, std::memory_order_acquire);
    return 0;
}
