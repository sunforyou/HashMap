//
//  Object.c
//  HashMap
//
//  Created by 宋旭 on 16/4/9.
//  Copyright © 2016年 sky. All rights reserved.
//

#include "Object.h"
#include <stdlib.h>

void ObjectRetain(Object *obj){
    obj->retainCount_++;
}
void ObjectRelease(Object *obj){
    obj->retainCount_--;
    
    if(obj->retainCount_<=0){
        free(obj);
    }
}
int ObjectRetainCount(Object *obj){
    return obj->retainCount_;
}

