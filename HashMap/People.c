//
//  People.c
//  HashMap
//
//  Created by 宋旭 on 16/4/9.
//  Copyright © 2016年 sky. All rights reserved.
//

#include "People.h"
#include <stdlib.h>
#include "Object.h"

People *PeopleNew(char *name,int age){
    People *p1 = malloc(sizeof(People));
    
    OBJECT_RETAIN(p1);
    
    p1->name_ = name;
    p1->age_ = age;
    
    return p1;
}

char *PeopleGetName(People *people){
    return people->name_;
}

int PeopleGetAge(People *people){
    return people->age_;
}

void PeoleDestory(People *person) {
    OBJECT_RELEASE(person);
}