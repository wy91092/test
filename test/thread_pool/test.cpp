/*************************************************************************
	> File Name: test.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Wed 23 Apr 2014 12:17:05 PM CST
 ************************************************************************/

#include"threadpool.h"
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

int main()
{
   ThreadPool pool(10);
   pool.start_thread_pool();
   srand(1024);

   while(true)
   {
     Task tmp;
	 tmp._num=rand()%100;
	 pool.add_task_queue(tmp);
	 sleep(1);
   }

  return 0;

}
