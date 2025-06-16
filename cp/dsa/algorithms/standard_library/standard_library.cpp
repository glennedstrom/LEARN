#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
using namespace std;

void demonstrateSequentialContainers() {
    std::cout << "\n=== SEQUENTIAL CONTAINERS ===\n";
    
    // VECTOR OPERATIONS
    std::cout << "\n--- VECTOR ---\n";
    std::vector<int> vec;
    
    // Construction methods
    std::vector<int> vec1;                          // Default
    std::vector<int> vec2(5);                       // Size constructor
    std::vector<int> vec3(5, 42);                   // Fill constructor {42, 42, 42, 42, 42}
    std::vector<int> vec4{1, 2, 3, 4, 5};          // Initializer list
    std::vector<int> vec5(vec4.begin(), vec4.end()); // Range constructor
    std::vector<int> vec6(vec4);                    // Copy constructor
    std::vector<int> vec7(std::move(vec5));         // Move constructor

    auto& container = vec7;
    cout << "#####################################################################################" << endl;
    for_each(container.begin(), container.end(), [](int num){cout << num << " ";});
    cout << endl;
    cout << "#####################################################################################" << endl;
    
    // Element access
    vec4.push_back(6);
    std::cout << "vec4[0]: " << vec4[0] << std::endl;
    std::cout << "vec4.at(1): " << vec4.at(1) << std::endl;
    std::cout << "vec4.front(): " << vec4.front() << std::endl;
    std::cout << "vec4.back(): " << vec4.back() << std::endl;
    std::cout << "vec4.data(): " << vec4.data() << std::endl;
    
    // Capacity operations
    std::cout << "Size: " << vec4.size() << std::endl;
    std::cout << "Capacity: " << vec4.capacity() << std::endl;
    std::cout << "Max size: " << vec4.max_size() << std::endl;
    std::cout << "Empty: " << vec4.empty() << std::endl;
    
    vec4.reserve(20);
    std::cout << "After reserve(20), capacity: " << vec4.capacity() << std::endl;
    
    vec4.resize(10, 99);
    std::cout << "After resize(10, 99), size: " << vec4.size() << std::endl;
    
    vec4.shrink_to_fit();
    std::cout << "After shrink_to_fit(), capacity: " << vec4.capacity() << std::endl;
    
    // Modifiers
    vec4.push_back(100);
    vec4.pop_back();
    vec4.insert(vec4.begin() + 2, 777);
    vec4.emplace(vec4.begin() + 3, 888);
    vec4.emplace_back(999);
    vec4.erase(vec4.begin() + 1);
    vec4.erase(vec4.begin() + 2, vec4.begin() + 4);
    
    std::vector<int> temp{10, 20, 30};
    vec4.assign(temp.begin(), temp.end());
    vec4.assign(3, 50);
    vec4.assign({70, 80, 90});
    
    // Swap
    std::vector<int> other{1, 2, 3};
    vec4.swap(other);
    
    // Clear
    vec4.clear();
    
    // DEQUE OPERATIONS
    std::cout << "\n--- DEQUE ---\n";
    std::deque<int> deq{1, 2, 3, 4, 5};
    
    deq.push_back(6);
    deq.push_front(0);
    deq.pop_back();
    deq.pop_front();
    deq.emplace_back(7);
    deq.emplace_front(-1);
    
    std::cout << "Deque front: " << deq.front() << ", back: " << deq.back() << std::endl;
    
    // LIST OPERATIONS
    std::cout << "\n--- LIST ---\n";
    std::list<int> lst{5, 2, 8, 1, 9};
    
    lst.push_back(10);
    lst.push_front(0);
    lst.pop_back();
    lst.pop_front();
    lst.emplace_back(11);
    lst.emplace_front(-1);
    
    // List-specific operations
    std::list<int> lst2{100, 200};
    lst.splice(lst.begin(), lst2); // Move all from lst2 to lst
    
    lst.remove(100); // Remove all elements with value 100
    lst.remove_if([](int x) { return x > 10; }); // Remove elements > 10
    
    lst.sort();
    lst.unique(); // Remove consecutive duplicates
    lst.reverse();
    
    std::list<int> lst3{15, 25, 35};
    lst3.sort();
    lst.merge(lst3); // Merge sorted lists
    
    std::cout << "List size after operations: " << lst.size() << std::endl;
    
    // FORWARD_LIST OPERATIONS
    std::cout << "\n--- FORWARD_LIST ---\n";
    std::forward_list<int> flst{1, 2, 3, 4};
    
    flst.push_front(0);
    flst.pop_front();
    flst.emplace_front(-1);
    flst.insert_after(flst.begin(), 99);
    flst.erase_after(flst.begin());
    
    flst.sort();
    flst.unique();
    flst.reverse();
    
    std::cout << "Forward list front: " << flst.front() << std::endl;
    
    // ARRAY OPERATIONS
    std::cout << "\n--- ARRAY ---\n";
    std::array<int, 5> arr{1, 2, 3, 4, 5};
    
    std::cout << "Array[0]: " << arr[0] << std::endl;
    std::cout << "Array.at(1): " << arr.at(1) << std::endl;
    std::cout << "Array.front(): " << arr.front() << std::endl;
    std::cout << "Array.back(): " << arr.back() << std::endl;
    std::cout << "Array.data(): " << arr.data() << std::endl;
    std::cout << "Array size: " << arr.size() << std::endl;
    
    arr.fill(42);
    std::array<int, 5> arr2{10, 20, 30, 40, 50};
    arr.swap(arr2);
}

void demonstrateAssociativeContainers() {
    std::cout << "\n=== ASSOCIATIVE CONTAINERS ===\n";
    
    // MAP OPERATIONS
    std::cout << "\n--- MAP ---\n";
    std::map<std::string, int> mp;
    
    // Insertion methods
    mp["apple"] = 5;
    mp.insert({"banana", 3});
    mp.insert(std::make_pair("cherry", 8));
    mp.emplace("date", 2);
    mp.emplace_hint(mp.end(), "elderberry", 1);
    
    // Access
    std::cout << "mp[\"apple\"]: " << mp["apple"] << std::endl;
    std::cout << "mp.at(\"banana\"): " << mp.at("banana") << std::endl;
    
    // Search operations
    auto it = mp.find("cherry");
    if (it != mp.end()) {
        std::cout << "Found cherry: " << it->second << std::endl;
    }
    
    std::cout << "Count of 'apple': " << mp.count("apple") << std::endl;
    
    auto range = mp.equal_range("banana");
    std::cout << "Equal range for banana spans " 
              << std::distance(range.first, range.second) << " elements\n";
    
    auto lower = mp.lower_bound("cherry");
    auto upper = mp.upper_bound("cherry");
    std::cout << "Lower bound for cherry: " << lower->first << std::endl;
    
    // Erase
    mp.erase("date");
    mp.erase(mp.find("elderberry"));
    
    // SET OPERATIONS
    std::cout << "\n--- SET ---\n";
    std::set<int> st{5, 2, 8, 2, 1, 9}; // Duplicates automatically removed
    
    st.insert(10);
    st.emplace(15);
    st.emplace_hint(st.end(), 20);
    
    std::cout << "Set size: " << st.size() << std::endl;
    std::cout << "Set contains 5: " << (st.count(5) > 0) << std::endl;
    
    auto it_set = st.find(8);
    if (it_set != st.end()) {
        std::cout << "Found 8 in set\n";
    }
    
    st.erase(2);
    
    // MULTIMAP AND MULTISET
    std::cout << "\n--- MULTIMAP ---\n";
    std::multimap<std::string, int> mmp;
    mmp.insert({"key", 1});
    mmp.insert({"key", 2});
    mmp.insert({"key", 3});
    
    std::cout << "Multimap count for 'key': " << mmp.count("key") << std::endl;
    
    std::multiset<int> mst{1, 2, 2, 3, 3, 3};
    std::cout << "Multiset count for 3: " << mst.count(3) << std::endl;
}

void demonstrateUnorderedContainers() {
    std::cout << "\n=== UNORDERED CONTAINERS ===\n";
    
    // UNORDERED_MAP OPERATIONS
    std::cout << "\n--- UNORDERED_MAP ---\n";
    std::unordered_map<std::string, int> ump;
    
    ump["first"] = 1;
    ump.insert({"second", 2});
    ump.emplace("third", 3);
    
    std::cout << "Unordered map size: " << ump.size() << std::endl;
    std::cout << "Bucket count: " << ump.bucket_count() << std::endl;
    std::cout << "Load factor: " << ump.load_factor() << std::endl;
    std::cout << "Max load factor: " << ump.max_load_factor() << std::endl;
    
    std::cout << "Bucket for 'first': " << ump.bucket("first") << std::endl;
    std::cout << "Bucket size for bucket 0: " << ump.bucket_size(0) << std::endl;
    
    ump.rehash(10);
    std::cout << "After rehash(10), bucket count: " << ump.bucket_count() << std::endl;
    
    // UNORDERED_SET OPERATIONS
    std::cout << "\n--- UNORDERED_SET ---\n";
    std::unordered_set<int> ust{1, 2, 3, 4, 5};
    
    ust.insert(6);
    ust.emplace(7);
    
    std::cout << "Unordered set contains 3: " << (ust.count(3) > 0) << std::endl;
    std::cout << "Unordered set size: " << ust.size() << std::endl;
}

void demonstrateContainerAdaptors() {
    std::cout << "\n=== CONTAINER ADAPTORS ===\n";
    
    // STACK OPERATIONS
    std::cout << "\n--- STACK ---\n";
    std::stack<int> stk;
    
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.emplace(4);
    
    std::cout << "Stack size: " << stk.size() << std::endl;
    std::cout << "Stack top: " << stk.top() << std::endl;
    
    stk.pop();
    std::cout << "After pop, top: " << stk.top() << std::endl;
    std::cout << "Stack empty: " << stk.empty() << std::endl;
    
    // QUEUE OPERATIONS
    std::cout << "\n--- QUEUE ---\n";
    std::queue<int> que;
    
    que.push(1);
    que.push(2);
    que.push(3);
    que.emplace(4);
    
    std::cout << "Queue size: " << que.size() << std::endl;
    std::cout << "Queue front: " << que.front() << std::endl;
    std::cout << "Queue back: " << que.back() << std::endl;
    
    que.pop();
    std::cout << "After pop, front: " << que.front() << std::endl;
    
    // PRIORITY_QUEUE OPERATIONS
    std::cout << "\n--- PRIORITY_QUEUE ---\n";
    std::priority_queue<int> pq;
    
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(2);
    pq.emplace(5);
    
    std::cout << "Priority queue size: " << pq.size() << std::endl;
    std::cout << "Priority queue top: " << pq.top() << std::endl;
    
    pq.pop();
    std::cout << "After pop, top: " << pq.top() << std::endl;
    
    // Min heap priority queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    min_pq.push(3);
    min_pq.push(1);
    min_pq.push(4);
    std::cout << "Min priority queue top: " << min_pq.top() << std::endl;
}

void demonstrateIterators() {
    std::cout << "\n=== ITERATORS ===\n";
    
    std::vector<int> vec{1, 2, 3, 4, 5};
    
    // Iterator types
    std::cout << "\n--- Iterator Types ---\n";
    auto it_begin = vec.begin();
    auto it_end = vec.end();
    auto it_cbegin = vec.cbegin(); // const iterator
    auto it_cend = vec.cend();
    auto it_rbegin = vec.rbegin(); // reverse iterator
    auto it_rend = vec.rend();
    auto it_crbegin = vec.crbegin(); // const reverse iterator
    auto it_crend = vec.crend();
    
    std::cout << "First element: " << *it_begin << std::endl;
    std::cout << "Last element (reverse): " << *it_rbegin << std::endl;
    
    // Iterator arithmetic
    std::cout << "Element at begin+2: " << *(it_begin + 2) << std::endl;
    std::cout << "Distance begin to end: " << std::distance(it_begin, it_end) << std::endl;
    
    // Iterator advancement
    std::advance(it_begin, 2);
    std::cout << "After advance(2): " << *it_begin << std::endl;
    
    auto it_next = std::next(vec.begin(), 3);
    auto it_prev = std::prev(vec.end(), 2);
    std::cout << "next(begin, 3): " << *it_next << std::endl;
    std::cout << "prev(end, 2): " << *it_prev << std::endl;
}

void demonstrateAlgorithms() {
    std::cout << "\n=== STL ALGORITHMS ===\n";
    
    std::vector<int> vec{5, 2, 8, 1, 9, 3, 7, 4, 6};
    std::vector<int> vec_copy = vec;
    
    // Searching algorithms
    std::cout << "\n--- Searching ---\n";
    auto it = std::find(vec.begin(), vec.end(), 8);
    if (it != vec.end()) {
        std::cout << "Found 8 at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    
    auto it_if = std::find_if(vec.begin(), vec.end(), [](int x) { return x > 7; });
    if (it_if != vec.end()) {
        std::cout << "First element > 7: " << *it_if << std::endl;
    }
    
    std::cout << "Count of elements > 5: " 
              << std::count_if(vec.begin(), vec.end(), [](int x) { return x > 5; }) << std::endl;
    
    // Sorting algorithms
    std::cout << "\n--- Sorting ---\n";
    std::sort(vec.begin(), vec.end());
    std::cout << "After sort: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    std::stable_sort(vec_copy.begin(), vec_copy.end(), std::greater<int>());
    std::cout << "After stable_sort (descending): ";
    for (int x : vec_copy) std::cout << x << " ";
    std::cout << std::endl;
    
    std::partial_sort(vec_copy.begin(), vec_copy.begin() + 3, vec_copy.end());
    std::cout << "After partial_sort (first 3): ";
    for (int x : vec_copy) std::cout << x << " ";
    std::cout << std::endl;
    
    // Binary search (requires sorted container)
    bool found = std::binary_search(vec.begin(), vec.end(), 5);
    std::cout << "Binary search for 5: " << found << std::endl;
    
    auto lower = std::lower_bound(vec.begin(), vec.end(), 5);
    auto upper = std::upper_bound(vec.begin(), vec.end(), 5);
    std::cout << "Lower bound for 5: " << std::distance(vec.begin(), lower) << std::endl;
    std::cout << "Upper bound for 5: " << std::distance(vec.begin(), upper) << std::endl;
    
    // Transforming algorithms
    std::cout << "\n--- Transforming ---\n";
    std::vector<int> squared(vec.size());
    std::transform(vec.begin(), vec.end(), squared.begin(), [](int x) { return x * x; });
    std::cout << "Squared: ";
    for (int x : squared) std::cout << x << " ";
    std::cout << std::endl;
    
    std::replace(vec.begin(), vec.end(), 5, 50);
    std::cout << "After replace 5 with 50: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    std::replace_if(vec.begin(), vec.end(), [](int x) { return x > 8; }, 99);
    std::cout << "After replace_if > 8 with 99: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    // Copying algorithms
    std::cout << "\n--- Copying ---\n";
    std::vector<int> dest(5);
    std::copy(vec.begin(), vec.begin() + 5, dest.begin());
    std::cout << "Copied first 5: ";
    for (int x : dest) std::cout << x << " ";
    std::cout << std::endl;
    
    std::vector<int> dest_if;
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(dest_if), 
                 [](int x) { return x < 10; });
    std::cout << "Copy_if < 10: ";
    for (int x : dest_if) std::cout << x << " ";
    std::cout << std::endl;
    
    // Removing algorithms
    std::cout << "\n--- Removing ---\n";
    vec = {1, 2, 3, 2, 4, 2, 5}; // Reset vector
    auto new_end = std::remove(vec.begin(), vec.end(), 2);
    vec.erase(new_end, vec.end());
    std::cout << "After remove 2: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    vec = {1, 1, 2, 2, 3, 3, 4}; // Reset with duplicates
    new_end = std::unique(vec.begin(), vec.end());
    vec.erase(new_end, vec.end());
    std::cout << "After unique: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    // Accumulating algorithms
    std::cout << "\n--- Accumulating ---\n";
    vec = {1, 2, 3, 4, 5};
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum: " << sum << std::endl;
    
    int product = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
    std::cout << "Product: " << product << std::endl;
    
    // Min/Max algorithms
    std::cout << "\n--- Min/Max ---\n";
    vec = {5, 2, 8, 1, 9, 3, 7};
    auto min_it = std::min_element(vec.begin(), vec.end());
    auto max_it = std::max_element(vec.begin(), vec.end());
    auto minmax_pair = std::minmax_element(vec.begin(), vec.end());
    
    std::cout << "Min: " << *min_it << std::endl;
    std::cout << "Max: " << *max_it << std::endl;
    std::cout << "MinMax: " << *minmax_pair.first << ", " << *minmax_pair.second << std::endl;
    
    // Partitioning algorithms
    std::cout << "\n--- Partitioning ---\n";
    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto partition_point = std::partition(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << "After partition (even first): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    std::cout << "Partition point: " << std::distance(vec.begin(), partition_point) << std::endl;
    
    // Permutation algorithms
    std::cout << "\n--- Permutations ---\n";
    vec = {1, 2, 3};
    std::cout << "Next permutations of {1,2,3}:\n";
    do {
        for (int x : vec) std::cout << x << " ";
        std::cout << std::endl;
    } while (std::next_permutation(vec.begin(), vec.end()));
    
    // Heap algorithms
    std::cout << "\n--- Heap Operations ---\n";
    vec = {3, 1, 4, 1, 5, 9, 2, 6};
    std::make_heap(vec.begin(), vec.end());
    std::cout << "After make_heap: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    std::push_heap(vec.begin(), vec.end());
    std::cout << "Is heap: " << std::is_heap(vec.begin(), vec.end()) << std::endl;
    
    std::pop_heap(vec.begin(), vec.end());
    vec.pop_back();
    std::cout << "After pop_heap: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    std::sort_heap(vec.begin(), vec.end());
    std::cout << "After sort_heap: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
}

void demonstrateRangeBasedOperations() {
    std::cout << "\n=== RANGE-BASED OPERATIONS ===\n";
    
    std::vector<int> vec{1, 2, 3, 4, 5};
    
    // Range-based for loop
    std::cout << "\n--- Range-based for loop ---\n";
    std::cout << "Elements: ";
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    // Modify with range-based for
    std::cout << "Doubling elements:\n";
    for (auto& element : vec) {
        element *= 2;
    }
    
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    // std::for_each
    std::cout << "\n--- std::for_each ---\n";
    std::for_each(vec.begin(), vec.end(), [](int& x) { x += 1; });
    std::cout << "After for_each (+1): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    std::for_each(vec.begin(), vec.end(), [](const int& x) { 
        std::cout << "Processing: " << x << std::endl; 
    });
}

void demonstrateStringOperations() {
    std::cout << "\n=== STRING OPERATIONS ===\n";
    
    std::string str = "Hello, World!";
    
    // Basic string operations (string is also a container)
    std::cout << "String: " << str << std::endl;
    std::cout << "Size: " << str.size() << std::endl;
    std::cout << "Length: " << str.length() << std::endl;
    std::cout << "Capacity: " << str.capacity() << std::endl;
    std::cout << "Empty: " << str.empty() << std::endl;
    
    // Element access
    std::cout << "str[0]: " << str[0] << std::endl;
    std::cout << "str.at(1): " << str.at(1) << std::endl;
    std::cout << "str.front(): " << str.front() << std::endl;
    std::cout << "str.back(): " << str.back() << std::endl;
    
    // Modifiers
    str.push_back('?');
    str.pop_back();
    str += " How are you?";
    
    str.insert(5, " there");
    str.erase(5, 6); // Remove " there"
    
    str.replace(7, 5, "Universe");
    
    std::cout << "Modified string: " << str << std::endl;
    
    // String-specific operations
    std::cout << "Substring (0, 5): " << str.substr(0, 5) << std::endl;
    std::cout << "Find 'Universe': " << str.find("Universe") << std::endl;
    
    // String can use all container algorithms
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    std::cout << "Uppercase: " << str << std::endl;
}

void demonstrateComparisons() {
    std::cout << "\n=== CONTAINER COMPARISONS ===\n";
    
    std::vector<int> vec1{1, 2, 3};
    std::vector<int> vec2{1, 2, 3};
    std::vector<int> vec3{1, 2, 4};
    
    std::cout << "vec1 == vec2: " << (vec1 == vec2) << std::endl;
    std::cout << "vec1 != vec3: " << (vec1 != vec3) << std::endl;
    std::cout << "vec1 < vec3: " << (vec1 < vec3) << std::endl;
    std::cout << "vec1 <= vec2: " << (vec1 <= vec2) << std::endl;
    std::cout << "vec3 > vec1: " << (vec3 > vec1) << std::endl;
    std::cout << "vec2 >= vec1: " << (vec2 >= vec1) << std::endl;
    
    // Lexicographical comparison
    std::string str1 = "apple";
    std::string str2 = "banana";
    std::cout << "Lexicographical compare 'apple' vs 'banana': " 
              << std::lexicographical_compare(str1.begin(), str1.end(),
                                            str2.begin(), str2.end()) << std::endl;
}

int main() {
    std::cout << "=== COMPREHENSIVE C++ CONTAINER OPERATIONS DEMO ===\n";
    
    demonstrateSequentialContainers();
    demonstrateAssociativeContainers();
    demonstrateUnorderedContainers();
    demonstrateContainerAdaptors();
    demonstrateIterators();
    demonstrateAlgorithms();
    demonstrateRangeBasedOperations();
    demonstrateStringOperations();
    demonstrateComparisons();
    
    std::cout << "\n=== DEMO COMPLETE ===\n";
    
    return 0;
}
