const longestPrefix = (s: string): string => {
    let l = 0, r = 0, p = 1, mod = 1e9 + 7;
    let k = 0, n = s.length;
    for (let i = 0; i < n - 1; i++) {
        l = (l * 128 + s.charCodeAt(i)) % mod;
        r = (r + p * s.charCodeAt(n - i - 1)) % mod;
        if (l === r) k = i + 1;
        p = p * 128 % mod;
    }
    return s.substring(0, k);
};
