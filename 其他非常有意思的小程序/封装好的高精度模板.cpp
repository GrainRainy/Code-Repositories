struct BigNum : vector<int> {
    BigNum(int n = 0) { push_back(n); Carry(); }
    BigNum(int SIZE, int _val) { assign(SIZE, _val); }
    BigNum &Carry() { // ��λ
        while (!empty() && !back()) pop_back();
        if (empty()) return *this;
        for (int i = 1; i < size(); i ++ )
            (*this)[i] += (*this)[i - 1] / 10,
            (*this)[i - 1] %= 10;
        while (back() >= 10)
			emplace_back(back() / 10), (*this)[size() - 2] %= 10;
        return *this;
    }
};
istream &operator >> (istream &s, BigNum &n) { 
// ���� BigNum
    string S; s >> S; n.clear();
    for (auto i : S) n.emplace_back(i ^ 48);
    reverse(n.begin(), n.end()); return s;
}
ostream &operator << (ostream &s, const BigNum &n) {
// ��� BigNum 
    if (n.empty()) s << 0;
    for (int i = n.size() - 1; i >= 0; i -- ) s << n[i];
    return s;
}
BigNum operator * (const BigNum &a, const BigNum &b) {
    BigNum ans(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i ++ )
        for (int j = 0; j < b.size(); j ++ )
            ans[i + j] += a[i] * b[j];
    return ans.Carry();
}
BigNum operator + (const BigNum &a, const BigNum &b) {
    BigNum ans(max(a.size(), b.size()) + 1, 0);
    for (int i = 0; i < a.size(); i ++ ) ans[i] += a[i];
    for (int i = 0; i < b.size(); i ++ ) ans[i] += b[i];
    return ans.Carry();
}

/*  ʹ��ʱ�� 
 *  ֱ������ BigNum ���� 
 *  BigNum a, b;
 *
 *  �����ѷ�װ��  
 *  cin >> a >> b;
 *  cout << a * b;
 */
