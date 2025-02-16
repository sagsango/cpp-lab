
#include <iostream>
#include <vector>
#include <queue>
#include <string>

template <typename T>
struct CustomAllocator {
    using value_type = T;

    CustomAllocator() = default;

    template <class U>
    constexpr CustomAllocator(const CustomAllocator<U>&) noexcept {}

    [[nodiscard]] T* allocate(std::size_t n) {
        std::cout << "Allocating " << n << " elements for type: " << typeid(T).name() << "\n";
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) noexcept {
        std::cout << "Deallocating " << n << " elements for type: " << typeid(T).name() << "\n";
        ::operator delete(p);
    }
};

// Allocator comparison operators (can be used with STL containers)
template <class T, class U>
bool operator==(const CustomAllocator<T>&, const CustomAllocator<U>&) { return true; }

template <class T, class U>
bool operator!=(const CustomAllocator<T>&, const CustomAllocator<U>&) { return false; }

int main() {
    // Allocate an integer using the custom allocator
    CustomAllocator<int> intAlloc;
    int* intPtr = intAlloc.allocate(5);
    intAlloc.deallocate(intPtr, 5);

    // Allocate a string using the custom allocator
    CustomAllocator<std::string> stringAlloc;
    std::string* strPtr = stringAlloc.allocate(1);
    new (strPtr) std::string("Hello, World!");  // Placement new to construct the string
    std::cout << *strPtr << std::endl;
    stringAlloc.deallocate(strPtr, 1);

    // Allocate a vector using the custom allocator
    CustomAllocator<std::vector<int>> vectorAlloc;
    std::vector<int>* vecPtr = vectorAlloc.allocate(1);
    new (vecPtr) std::vector<int>{1, 2, 3};  // Placement new to construct the vector
    std::cout << "Vector size: " << vecPtr->size() << std::endl;
    vectorAlloc.deallocate(vecPtr, 1);

    // Allocate a priority queue using the custom allocator
    CustomAllocator<std::priority_queue<int>> pqAlloc;
    std::priority_queue<int>* pqPtr = pqAlloc.allocate(1);
    new (pqPtr) std::priority_queue<int>();  // Placement new to construct the priority queue
    pqPtr->push(5);
    pqPtr->push(3);
    pqPtr->push(7);
    std::cout << "Priority Queue top: " << pqPtr->top() << std::endl;
    pqAlloc.deallocate(pqPtr, 1);

    return 0;
}
