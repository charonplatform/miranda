// @Author Lin Ya
// @Email xxbbb@vip.qq.com
#pragma once
#include "base/noncopyable.h"
#include "EventLoopThread.h"
#include <memory>
#include <vector>
#include <assert.h>

class EventLoopThreadPool : noncopyable
{
public:
    EventLoopThreadPool(EventLoop* baseLoop, int numThreads);

    ~EventLoopThreadPool()
    {
        std::cout << "~EventLoopThreadPool()";
    }
    void start();

    EventLoop *getNextLoop();

private:
    EventLoop* baseLoop_;
    bool started_;
    int numThreads_;
    int next_;
    std::vector<std::shared_ptr<EventLoopThread>> threads_;
    std::vector<EventLoop*> loops_;
};
