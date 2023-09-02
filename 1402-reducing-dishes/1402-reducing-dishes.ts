function maxSatisfaction(satisfaction: number[]): number {
    satisfaction.sort((a: number, b: number) => a - b);
    console.log(satisfaction);
    let n: number = satisfaction.length;
    let res: number = 0, tmp: number = 0;

    for(let i: number = n - 1; i >= 0; --i) {
        if(satisfaction[i] + tmp <=  0) break;
        tmp += satisfaction[i];
        res += tmp;
    }
    return res;
};