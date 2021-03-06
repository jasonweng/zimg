/*   
 *   zimg - high performance image storage and processing system.
 *       http://zimg.buaa.us 
 *   
 *   Copyright (c) 2013, Peter Zhao <zp@buaa.us>.
 *   All rights reserved.
 *   
 *   Use and distribution licensed under the BSD license.
 *   See the LICENSE file for full text.
 * 
 */

/**
 * @file zspinlock.h
 * @brief Spinlock header.
 * @author 招牌疯子 zp@buaa.us
 * @version 1.0
 * @date 2013-07-19
 */


#ifndef ZSPINLOCK_H
#define ZSPINLOCK_H

#include "zcommon.h"

/* 用户空间的自旋锁实现 */
typedef struct {
    volatile long spin_;
    volatile long flag_;
}spin_lock_t;
 
void spin_init(spin_lock_t* lock, long* flag);          /* 初始化自旋锁（flag可为NULL） */
void spin_lock(spin_lock_t* lock);              /* 加锁 */
void spin_unlock(spin_lock_t* lock);                /* 解锁 */
int  spin_trylock(spin_lock_t* lock);               /* 尝试加锁，成功返回1，否则返回0 */
int  spin_is_lock(spin_lock_t* lock);               /* 如果已加锁，则返回1，否则返回0 */

#endif
