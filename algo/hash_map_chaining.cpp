//
// Created by Administrator on 2023/11/21.
//
#include "./utils/common.hpp"


struct Pair {
public:
    int key;
    string val;
    Pair(int key, string val) {
        this->key = key;
        this->val = val;
    }
};
class HashMapChaining{
private:
    int size;
    int capacity;
    double loadThres;
    int extendRatio;
    vector<vector<Pair *>> buckets;
public:
    /*
     * 构造方法
     */
    HashMapChaining():size(0),capacity(4),loadThres(2.0/3),extendRatio(2){
        buckets.resize(capacity);
    }
    ~HashMapChaining(){
        for (auto &bucket:buckets){
            for (Pair *pair:bucket){
                delete pair;
            }
        }
    }
    /*
     * 哈希函数
     */
    int hashFunc(int key){
        int index = key %capacity;
        return index;
    }
    /*
     * 负载因子
     */
    double loadFactor() {
        return (double )size / (double )capacity;
    }
    /*
     * 查询操作
     */
    string get(int key){
        int index = hashFunc(key);
        for (Pair *pair:buckets[index]){
            if (pair->key == key){
                return pair->val;
            }
        }
        return "";
    }
    /*
     * 添加操作
     */
    void put(int key,string val) {
        if (loadFactor() > loadThres){
            extend();
        }
    }

    /*
     * 扩容哈希表
     */
    void extend(){
        //暂存原哈希表
        vector<vector<Pair *>> bucketsTmp = buckets;
        //初始化扩容后的新哈希表
        capacity *= extendRatio;
        buckets.clear();
        buckets.resize(capacity);
        size = 0;
        //将键值对从原哈希表搬运至新哈希表
        for (auto &bucket:bucketsTmp){
            for (Pair *pair:bucket) {
                put(pair->key,pair->val);
                delete pair;
            }
        }
    }

};