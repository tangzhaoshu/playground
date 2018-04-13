#include "reactor.h"

using namespace std;

EventLoop* EventLoop::instance_ = NULL;

EventLoop::EventLoop() {

}

EventLoop::EventLoop(int size) {
    timeEvents_ = NULL;
    event_size_ = size;
    max_fd_ = size;
    epoll_ = new EventEpoll(size);
    seteventsize(size);
}

EventLoop::~EventLoop() {

}

void EventLoop::release() {
    while (timeEvents_) {
        delete timeEvents_;
    }
    if (fileEvents_) {
        free(fileEvents_);
    }
    if (processEvent_) {
        free(fileEvents_);
    }
    if (epoll_) {
        delete epoll_;
    }
}

int EventLoop::CreateFileEvent(int fd, fileProcessFunc* rproc, fileProcessFunc* wproc, int mask) {
    if (fd > max_fd_) return -1;
    FileEvent* fe = &fileEvents_[fd];
    epoll_->AddEvent(fd, mask, fe->state_);
    if (mask & EEREAD) fe->read_func_ = rproc;
    if (mask & EEWRITE) fe->write_func_ = wproc;
    fe->state_ |= mask;
    return 0;
}

int EventLoop::DeleteFileEvent(int fd, int mask) {
    if (fd > max_fd_) return -1;
    FileEvent* fe = &fileEvents_[fd];
    epoll_->DelEvent(fd, mask, fe->state_);
    fe->state_ &= (~mask);
}