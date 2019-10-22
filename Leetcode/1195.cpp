class FizzBuzz {
private:
    int n;
    int counter;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        counter = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(1)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){ return (counter > n
                || (counter % 3==0) && (counter % 5 != 0));});
            if (counter <= n)
            {
                printFizz();
                counter ++;
            }
            else
                break;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(1)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){ return (counter > n
                || (counter % 5 == 0) && (counter % 3 != 0));});
            if (counter <= n)
            {
                printBuzz();
                counter ++;
            }
            else
                break;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(1)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){ return (counter > n
                || (counter % 5 == 0) && (counter % 3 == 0));});
            if (counter <= n)
            {
                printFizzBuzz();
                counter ++;
            }
            else
                break;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(1)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){ return (counter > n
                || (counter % 5 != 0) && (counter % 3 != 0));});
            if (counter <= n)
            {
                printNumber(counter);
                counter ++;
            }
            else
                break;
            cv.notify_all();
        }
    }
};