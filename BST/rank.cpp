//
// Created by Tom on 11/05/2020.
//

#include "rank.h"
#include <vector>
#include <utility>
#include <string>
#include <queue>

using namespace std;


class SolutionRank {
public:
    struct cmp{
    bool operator()(pair<int,int> a , pair<int,int> b){
            return a.second < b.second;
    }};
    // 大顶堆
    vector<string> findRelativeRanks(vector<int>& nums) {

        priority_queue<pair<int,int>,vector<pair<int, int>>,cmp> q;//为什么这里必须是 vector<pair<int,int>>
        int len = nums.size();
        vector<string> res(len);
        int i;
        pair<int, int> pa;
        for(int i =0; i< len; i++)
        {
            pa.first = i;
            pa.second = nums[i];
            q.push(pa);
        }
        for(int i = 0; i< len;i++)
        {
            if(i > 2 )
            {
                res[q.top().first] = to_string(i+1);
                q.pop();
            }
            else if(i == 2)
            {
                res[q.top().first] = "Bronze Medal";
                q.pop();
            }
            else if(i == 1)
            {
                res[q.top().first] = "Silver Medal";
                q.pop();
            }
            else{
                res[q.top().first] = "Gold Medal";
                q.pop();
            }
        }
        return res;
    }
    //布隆过滤器
    vector<string> findRelativeRanks2(vector<int>& nums) {
        int maxnum = 0, ord = 1;
        for(int i =0; i < nums.size(); i++)
        {
            if(maxnum < nums[i])
                maxnum = nums[i];
        }
        vector<string>res(nums.size());
        vector<int> order(maxnum+1, -1);
        for(int i =0; i< nums.size(); i++)
        {
            order[nums[i]] = i;
        }
        for(int i = order.size()-1; i >=0; i--)
        {
            if(ord > 3 && order[i]>=0 )
            {res[order[i]]=to_string(ord);ord++;}
            else if(order[i]>=0 && ord ==1)
            {
                res[order[i]]="Gold Medal";ord++;
            }
            else if(order[i]>=0 && ord ==2)
            {
                res[order[i]]="Silver Medal";ord++;
            }
            else if(order[i]>=0 && ord ==3)
            {
                res[order[i]]="Bronze Medal";ord++;
            }


        }
        return res;
    }

};