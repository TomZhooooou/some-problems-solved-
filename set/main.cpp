#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

class settest{
    multiset<int> containerLargestK;
    int K;
public:
    settest(int k, vector<int>& nums) {
        for (auto num :nums) {
            containerLargestK.insert(num);
            if (containerLargestK.size() > k)
                containerLargestK.erase(containerLargestK.begin());
        }
        K = k;
    }
    int add(int val) {
        containerLargestK.insert(val);
        if(containerLargestK.size() > K)
            containerLargestK.erase(containerLargestK.begin());
        return *containerLargestK.begin();
    }

};
class Multiset{
    priority_queue<int, vector<int>,greater<int>> pq;
    int K;
public:
    Multiset(int k, vector<int>& nums) {
        for (auto num :nums) {
            pq.push(num);
            if(pq.size() > k)
                pq.pop();
        }
        K = k;
    }
    int add(int val) {
        pq.push(val);
        if(pq.size()> K)
            pq.pop();
        return pq.top();
    }
};
int main() {
    vector<int> nums = {4,5,8,2};
    Multiset s(3,nums);
    std::cout << s.add(3)<<endl;
    std::cout << s.add(5)<<endl;
    std::cout << s.add(10)<<endl;
    std::cout << s.add(9)<<endl;
    std::cout << s.add(4)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
