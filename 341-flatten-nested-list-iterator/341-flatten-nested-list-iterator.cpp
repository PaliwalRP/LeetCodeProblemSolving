class NestedIterator {
public:
    using IT = vector<NestedInteger>::const_iterator;
    NestedIterator(vector<NestedInteger> &nestedList) {
        depth_.emplace(nestedList.cbegin(), nestedList.cend());
    }

    int next() {
        return (depth_.top().first++)->getInteger();
    }
    
    bool hasNext() {
        while (!depth_.empty()) {
            auto& cur = depth_.top();
            if (cur.first == cur.second) {
                depth_.pop();
            } else if (cur.first->isInteger()) {
                return true;
            } else {
                auto& nestedList = cur.first->getList();
                ++cur.first;
                depth_.emplace(nestedList.cbegin(), nestedList.cend());
            }
        }
        return false;
    }
    
private:
    stack<pair<IT, IT>> depth_;
};