//
//  hash_map.c
//  HashMap
//
//  Created by 宋旭 on 16/4/9.
//  Copyright © 2016年 sky. All rights reserved.
//

#include "hash_map.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

static AnyPointer * allocMemoryForValuesByCapacity(hashMap *map) {
    return malloc(sizeof(AnyPointer) * map->capacity_);
}

static char * allocMemoryForKeysByCapacity(hashMap *map) {
    return malloc(sizeof(char*) *map -> capacity_);
}

hashMap* mapCreate(){
    hashMap *map  = malloc(sizeof(hashMap));
    map->length_ = 0;
    map->capacity_ = 32;//默认申请内存32位
    map->values_ = allocMemoryForValuesByCapacity(map);//申请存放values所存放的内存空间
    map->keys_[0] = allocMemoryForKeysByCapacity(map);//申请存放keys所存放的内存空间
    return map;
}

int MapGetLength(hashMap *map){
    return map->length_;
}

static int getIndexByKey(hashMap *map,char *key){
    int index = -1;
    for (int i = 0; i < map->length_; i++) {
        //        printf("根据key获取元素下标: %s,取地址后的值%s \n",key, map->keys_[i]);
        if(key == map->keys_[i]) {
            index = i;
            break;
        }
    }
    return index;
}

void hash_map_put(hashMap *map, char *key, AnyPointer value){
    //先检查要插入的key在map中是否已经存在，如果存在，则不可以插入
    if(getIndexByKey(map, key) != -1){
        printf("\n当前map中，已经存在key值对应的对象，请更换key值\n");
    }else{
        //判断内存是否溢出
        if (map->length_ >= map->capacity_) {
            
            map->capacity_ *= 2;
            
            AnyPointer *oldValues = map->values_;
            map->values_ = allocMemoryForValuesByCapacity(map);
            memcpy(map->values_, oldValues, map->capacity_ * sizeof(AnyPointer));
            
            free(oldValues);
            
            char *oldKeys = map->keys_[0];
            map->keys_[0] = allocMemoryForKeysByCapacity(map);
            memcpy(map->keys_, oldKeys, map->capacity_ * sizeof(char *));
            free(oldKeys);
        }
        
        map->values_[map->length_] = value;
        
        map->keys_[map->length_] = key;
        
        map->length_++;
        OBJECT_RETAIN(value);
    }
}

AnyPointer hash_map_get(hashMap *map,char *key){
    int index = getIndexByKey(map, key);
    if(index == -1){
        printf("没有key为％s的对象,无法删除\n");
    }
    return map->values_[index];
}

void hash_map_remove(hashMap *map,char *key){
    int index = getIndexByKey(map, key);
    if (index != -1) {
        assert(index>=0 && index < map->length_);
        OBJECT_RELEASE(map->values_);
        
        map->length_--;
        for (int i=index; i<map->length_; i++) {
            map->keys_[index] = map->keys_[i+1];
            map->values_[i] = map->values_[i+1];
        }
        printf("移除成功\n");
    }else{
        printf("没有指定key对应的对象");
    }
}

void hash_map_destroy(hashMap *map){
    
    for (int j = 0; j<map->length_; j++) {
        OBJECT_RELEASE(map->keys_);
        OBJECT_RELEASE(map->values_[j]);
    }
    
    free(map->values_);
    free(map);
}
