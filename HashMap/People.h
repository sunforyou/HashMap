//
//  People.h
//  HashMap
//
//  Created by 宋旭 on 16/4/9.
//  Copyright © 2016年 sky. All rights reserved.
//

#ifndef People_h
#define People_h

#include <stdio.h>
typedef struct People{
    int retainCount_;
    char *name_;
    int age_;
} People;

/// Person Created
People *PeopleNew(char *name, int age);

/// Person GotName
char *PeopleGetName(People *people);

/// Person GotAge
int PeopleGetAge(People *people);

/// Person Destoried
void PeopleDestory(People *person);

#endif /* People_h */
