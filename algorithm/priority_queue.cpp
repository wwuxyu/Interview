auto cmp = [](const T& a, const T& b) {
    // 自定义的比较规则
};

priority_queue<T, Container, decltype(cmp)> pq(cmp);


// Examples:
//https://blog.csdn.net/AAMahone/article/details/82787184

// 小根堆
auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
};
priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(cmp)> pq(cmp);
