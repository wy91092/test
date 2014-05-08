/*************************************************************************
	> File Name: workthread.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Wed 23 Apr 2014 11:14:07 AM CST
 ************************************************************************/

#ifndef _WORKTHREAD_H_
#define _WORKTHREAD_H
#include<pthread.h>
#include"thread.h"
class ThreadPool;

class WorkThread: public Thread
{
	public:
		void run();
		void compute_task(int num);//实际的工作函数，由run来调用
		void register_thread_pool(ThreadPool *p_thread_pool);//注册线程池
	private:
		ThreadPool *_p_thread_pool;//线程池的指针，用来指定线程去哪里获取任务
};

#endif
