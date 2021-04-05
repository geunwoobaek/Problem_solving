public class twentyFourGames {
    public boolean judgePoint24(int[] nums) {
        double[] data = new double[nums.length];
        for (int i = 0; i < nums.length; i++)
            data[i] = (double) nums[i];
        return helper(data);
    }

    private boolean helper(double[] nums) {
        if (nums.length == 1)
            return Math.abs(nums[0] - 24.0) < 0.0001;

        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                double[] next = new double[n - 1];
                for (int k = 0, index = 0; k < n; k++) {
                    if (k != i && k != j)
                        next[index++] = nums[k];
                }
                double d1=nums[i],d2=nums[j];
                double[] dirs = new double[]{d1 + d2, d1 - d2, d2 - d1, d2 * d1};
                for (double dir: dirs) {
                    next[n-2] = dir;
                    if (helper(next)) return true;
                }
                
                if (d1 > 0.0001) {
                    next[n-2] = d2 / d1;
                    if (helper(next)) return true;
                }
                
                if (d2 > 0.0001) {
                    next[n-2] = d1 / d2;
                    if (helper(next)) return true;
                }
            }
        }
    }
}
