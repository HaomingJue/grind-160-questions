class Solution {
    public int[] sortedSquares(int[] nums) {
        int pivot = findFirstPositive(nums);
        int[] ans = new int[nums.length];
        int i = pivot, j = pivot - 1, k = 0;
        while (i < nums.length && j >= 0) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                ans[k++] = b;
                j--;
            }            
            else {
                ans[k++] = a;
                i++;
            }           
        }
        while (j >= 0) {
            ans[k++] = nums[j] * nums[j];
            j--;
        }
        while (i < nums.length) {
            ans[k++] = nums[i] * nums[i];
            i++;
        }
        return ans;
    }

    private int findFirstPositive(int[] nums) {
        if (nums[0] >= 0) return 0;
        if (nums[nums.length - 1] <= 0) return nums.length;
        int l = 0, h = nums.length - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (nums[m] <= 0 && nums[m + 1] > 0) {
                return m + 1;
            }
            else if (nums[m] > 0) {
                h = m;
            } 
            else {
                l = m + 1;
            }
        }
        return nums.length;
    }
}