class DynamicArray {
public:

    DynamicArray(int capacity)
    : capacity_{capacity}
    , size_{0}
    {
        arr_ = new int[capacity];
    }

    int get(int i) {
        return arr_[i];
    }

    void set(int i, int n) {
        arr_[i] = n;
    }

    void pushback(int n) {
        if (size_ == capacity_) {
            resize();
        }
        arr_[size_] = n;
        ++size_;
    }

    int popback() {
        if (size_ > 0) {
            --size_;
        }
        return arr_[size_];
    }

    void resize() {
        capacity_ = capacity_ * 2;
        int *newArray = new int[capacity_];
        for (auto i = 0; i < size_; ++i) {
            newArray[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = newArray;
    }

    int getSize() {
        return size_;
    }

    int getCapacity() {
        return capacity_;
    }

    private:
        int *arr_;
        int size_;
        int capacity_;

};
