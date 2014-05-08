/*************************************************************************
  > File Name: workthread.cpp
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Wed 23 Apr 2014 11:32:02 AM CST
 ************************************************************************/
#include"threadpool.h"
#include<iostream>
using namespace std;

void WorkThread::run()
{
	while(true)
	{   std::cout<<pthread_self()<<std::endl;
		Task task;
		/*
		 *如果获取任务时，返回值为false,那么说明线程池已经关闭，
		 *所以此时线程需要退出死循环
		 */
		bool ret=_p_thread_pool->get_task_queue(task);
		if(ret==false)
		{
			return;
		}
		compute_task(task._num);
        sleep(5);
	}
}


void WorkThread::compute_task(int num)
{
	cout<<2*num <<"-----------"<<endl;
}
void WorkThread::register_thread_pool(ThreadPool *p_thread_pool)
{
  _p_thread_pool=p_thread_pool;
}
