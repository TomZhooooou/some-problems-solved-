//
// Created by Tom on 12/05/2020.
//

#include "findPairs.h"
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> map ;
        int count = 0;
        if(k< 0) return count;
        for(int num : nums)
        {
            map[num]++;
        }
        if(k ==0){
            for(auto &s : map)
            {
                if(s.second > 1){
                    count++;}
            }
            return count;
        }
        for(auto &s : map)
        {
            //if(map.count(s.first+k) == 1) 两种方法判断是否 存在key
            if (map.find(s.first+k)!= map.end())
            {
                //cout <<"the key:"<<  s.first<<endl;
                count++;
            }
        }
        return count;
    }
};