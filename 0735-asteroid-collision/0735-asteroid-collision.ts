function asteroidCollision(A: number[]): number[] {
    let st: number[] = [];
    for (let a of A) {
        let flag: number = 1;
        while (st.length > 0 && (st[st.length - 1] > 0 && a < 0)) {
            if (Math.abs(a) > Math.abs(st[st.length - 1])) {
                st.pop();
                continue;
            }
            if (Math.abs(a) === Math.abs(st[st.length - 1])) {
                st.pop();
            }
            flag = 0;
            break;
        }
        if (flag === 1) {
            st.push(a);
        }
    }
    let ans: number[] = new Array(st.length);
    for (let i: number = st.length - 1; i >= 0; --i) {
        ans[i] = st[st.length - 1];
        st.pop();
    }
    return ans;
};