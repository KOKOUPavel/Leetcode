<?php
class Solution {

    /**
     * @param Integer[]
     * @return Integer
     */
    function numberOfArithmeticSlices($nums) {
        $n = count($nums);
        if ($n < 3) return 0;

        $count = 0;
        $curr = 0;

        for ($i = 2; $i < $n; $i++) {
            if ($nums[$i] - $nums[$i - 1] == $nums[$i - 1] - $nums[$i - 2]) {
                $curr += 1;
                $count += $curr;
            } else {
                $curr = 0;
            }
        }

        return $count;
    }
}
?>
