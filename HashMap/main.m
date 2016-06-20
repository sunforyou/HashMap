//
//  main.m
//  HashMap
//
//  Created by 宋旭 on 16/4/9.
//  Copyright © 2016年 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "hash_map.h"
#include "People.h"
#include "stdlib.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        hashMap *map = mapCreate();

        //往hashMap里添加一个元素
        People *ex1 = PeopleNew("hello1", 1);
        hash_map_put(map,"me1",ex1);
        People *ex2 = PeopleNew("hello2", 2);
        hash_map_put(map,"me2",ex2);
        People *ex3 = PeopleNew("hello3", 3);
        hash_map_put(map,"me3",ex3);
        People *ex4 = PeopleNew("hello4", 4);
        hash_map_put(map,"me4",ex4);
        People *ex5 = PeopleNew("hello5", 5);
        hash_map_put(map,"me5",ex5);
        
        People *jike = PeopleNew("jikexueyuan", 24);
        hash_map_put(map, "me", jike);
        People *find = hash_map_get(map, "me");
        
        printf("find me! name:%s,age:%d\n",find->name_,find->age_);
        
        hash_map_remove(map, "me");
        
        hash_map_get(map, "me");
        
        
        hash_map_destroy(map);

    }
    return 0;
}
