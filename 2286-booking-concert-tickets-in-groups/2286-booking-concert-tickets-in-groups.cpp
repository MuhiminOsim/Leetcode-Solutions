
class BIT{
public:
///1-indexed
    int sz; ///max size of array+1
    vector<long long> t;
    void init(int n){
        sz = n + 2;
        t.assign(sz,0);
    }
    long long query(int idx){
        long long ans = 0;
        for(; idx >= 1; idx -= (idx & -idx)) ans += t[idx];
        return ans;
    }
    void update(int idx, long long val){
        if(idx <= 0) return;
        for(; idx <sz; idx += (idx & -idx)) t[idx] += val;
    }
    long long query(int l, int r) { return query(r) - query(l - 1); }
};

class SegmentTree{
public:
    int sz;
    vector<long long> tree;

    void init(int _sz) {
        sz = _sz;
        tree.resize(4*sz+5,0);
    }

    void update(int pos, int l, int r, int idx, long long value){
        if(l==r && l==idx){
            tree[pos]+=value;
            return;
        }
        int mid=(l+r)>>1;
        if(idx>=l && idx<=mid) update(pos*2,l,mid,idx,value);
        if(idx>=(mid+1) && idx<=r) update(pos*2+1,mid+1,r,idx,value);
        tree[pos]=min(tree[pos*2], tree[pos*2+1]);
    }

    long long query(int pos, int l, int r, int L, int R){
        if(l>=L && r<=R) return tree[pos];
        if(r<L || l>R) return 1e10;
        int mid=(l+r)>>1;
        long long q1=query(pos*2,l,mid,L,R);
        long long q2=query(pos*2+1,mid+1,r,L,R);
        return min(q1, q2);
    }
};

class BookMyShow {
public:
    int n, m;
    BIT bit;
    SegmentTree seg;
    vector<int> cnt;
    int idx;
    
    BookMyShow(int _n, int _m) {
        n = _n, m = _m;
        bit.init(n);
        seg.init(n);
        cnt = vector<int> (n, 0);
        idx = 0;
    }
    
    vector<int> gather(int k, int maxRow) {
        int lo = 0, hi = maxRow;
        int index = -1;
        int booked = 0;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            int curCnt = seg.query(1, 1, n, 1, mid + 1);
            //cout << mid << " " << curCnt << endl;
            if((m - curCnt) >= k) {
                index = mid;
                booked = curCnt;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        //cout << index << " " << booked << endl;
        if(index == -1) return {};
        seg.update(1, 1, n, index + 1, k);
        bit.update(index + 1, k);
        cnt[index] += k;
        return {index, booked};
    }
    
    bool scatter(int k, int maxRow) {
        long long rem = ((long long)m * (maxRow + 1)) - bit.query(maxRow + 1);
        //cout << k << " " << maxRow << " " << rem << endl;
        if(rem < k) return false;
        
        while(idx <= maxRow && k) {
            //cout << idx << " " << cnt[idx] << " " << k << endl;
            if(cnt[idx] == m) {
                idx++;
                continue;
            }
            
            int mn = min(k, m - cnt[idx]);
            cnt[idx] += mn;
            k -= mn;
            seg.update(1, 1, n, idx + 1, mn);
            bit.update(idx + 1, mn);
            //cout << k << endl;
            if(!k) break;
            idx++;
        }
        
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */