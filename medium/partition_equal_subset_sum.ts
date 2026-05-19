function canPartition(nums:number[]):boolean {
    const totalSum = nums.reduce((acc, num) => acc + num, 0);

    if(totalSum % 2 !== 0) return false;

    const objet = totalSum / 2;

    const dp: boolean[] = new Array(objet + 1).fill(false);
    dp[0] = true;

    for(const num of nums) {

        for(let j = objet; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp [objet];
}
