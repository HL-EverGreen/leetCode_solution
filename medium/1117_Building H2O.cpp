// concurrency
// 292ms, beats 84.3%

// Main idea:
// Use two mutex, and class is initialized with o_mutex locked.
// Use count to monitor current number of Hydrogen.
// Lock h_mutex in each H calls, if odd H, release h_mutex, if even H, release o_mutex
// In O calls, lock o_mutex and unlock h_mutex

class H2O {
public:
    H2O() {
        cnt = 0;
        o_mutex.lock();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        h_mutex.lock();
        ++cnt;
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        
        if(cnt % 2 == 1) h_mutex.unlock();
        else o_mutex.unlock();
    }

    void oxygen(function<void()> releaseOxygen) {
        o_mutex.lock();
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        
        h_mutex.unlock();
    }
private:
    mutex h_mutex, o_mutex;
    int cnt;
};

// unique_lock and condition variable
/*
class H2O {
    mutex m;
    condition_variable cv;
    int c=1;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lk(m);
        cv.wait(lk,[this]{return (c%3 != 0);});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++c;
        if(!(c%3)) {
            lk.unlock();
            cv.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lk(m);
        cv.wait(lk,[this]{return (c%3 == 0);});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++c;
        lk.unlock();
        cv.notify_one();
    }
};
*/