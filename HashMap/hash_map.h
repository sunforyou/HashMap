//
//  hash_map.h
//  HashMap
//
//  Created by 宋旭 on 16/4/9.
//  Copyright © 2016年 sky. All rights reserved.
//

#ifndef hash_map_h
#define hash_map_h

#include <stdio.h>
#include "Object.h"
#include "People.h"

typedef People *AnyPointer;

typedef struct hashMap{
    int length_; //定义数组的长度
    int capacity_; //定义占用的空间大小
    char *keys_[10];  //存放主键key
    AnyPointer *values_;
    
} hashMap;
///创建数组
hashMap *mapCreate();

///获取数组长度
int MapGetLength(hashMap *map);

///往hashmap中添加元素
void hash_map_put(hashMap *map, char *key, AnyPointer value);

///根据key取出相应的元素
AnyPointer hash_map_get(hashMap *map, char *key);

///根据key移除相应的元素
void hash_map_remove(hashMap *map, char *key);

///销毁hashmap
void hash_map_destroy(hashMap *map);

#endif /* hash_map_h */

